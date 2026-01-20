#include "Treap.h"

using namespace std;

Treap::Treap() {
    root = nullptr;
    size = 0;
    rotationCount = 0;
}

// ROTATIONS 
TreapNode* Treap::rotateRight(TreapNode* y) {
    TreapNode* x = y->left;
    TreapNode* B = x->right;

    x->right = y;
    y->left = B;

    rotationCount++;
    return x;
}

TreapNode* Treap::rotateLeft(TreapNode* x) {
    TreapNode* y = x->right;
    TreapNode* B = y->left;

    y->left = x;
    x->right = B;

    rotationCount++;
    return y;
}

// ADD POST 
void Treap::addPost(string id, int timestamp, int score) {
    Post post(id, timestamp, score);
    root = insertHelper(root, post);
    size++;
}

TreapNode* Treap::insertHelper(TreapNode* node, Post post) {
    if (node == nullptr) {
        return new TreapNode(post);
    }

    if (post.postId < node->post.postId) {
        node->left = insertHelper(node->left, post);

        if (node->left->priority > node->priority) {
            node = rotateRight(node);
        }
    }
    else {
        node->right = insertHelper(node->right, post);

        if (node->right->priority > node->priority) {
            node = rotateLeft(node);
        }
    }

    return node;
}

// SEARCH POST 
Post* Treap::searchPost(string postId) {
    TreapNode* result = searchHelper(root, postId);
    if (result != nullptr) {
        return &(result->post);
    }
    return nullptr;
}

TreapNode* Treap::searchHelper(TreapNode* node, string postId) {
    if (node == nullptr) {
        return nullptr;
    }

    if (postId == node->post.postId) {
        return node;
    }
    else if (postId < node->post.postId) {
        return searchHelper(node->left, postId);
    }
    else {
        return searchHelper(node->right, postId);
    }
}

// DELETE POST 
void Treap::deletePost(string postId) {
    root = deleteHelper(root, postId);
    size--;
}

TreapNode* Treap::deleteHelper(TreapNode* node, string postId) {
    if (node == nullptr) {
        return nullptr;
    }

    if (postId < node->post.postId) {
        node->left = deleteHelper(node->left, postId);
    }
    else if (postId > node->post.postId) {
        node->right = deleteHelper(node->right, postId);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            node = rotateLeft(node);
            node->left = deleteHelper(node->left, postId);
        }
        else if (node->right == nullptr) {
            node = rotateRight(node);
            node->right = deleteHelper(node->right, postId);
        }
        else {
            if (node->left->priority > node->right->priority) {
                node = rotateRight(node);
                node->right = deleteHelper(node->right, postId);
            }
            else {
                node = rotateLeft(node);
                node->left = deleteHelper(node->left, postId);
            }
        }
    }

    return node;
}

// LIKE POST
void Treap::likePost(string postId) {
    Post* post = searchPost(postId);
    if (post != nullptr) {
        Post updatedPost = *post;
        updatedPost.score++;

        deletePost(postId);
        size++;

        addPost(updatedPost.postId, updatedPost.timestamp, updatedPost.score);
        size--;
    }
}

// GET MOST POPULAR 
Post* Treap::getMostPopular() {
    if (root == nullptr) {
        return nullptr;
    }
    return &(root->post);
}

// HEIGHT 
int Treap::getHeight() {
    return heightHelper(root);
}

int Treap::heightHelper(TreapNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);

    return 1 + max(leftHeight, rightHeight);
}

// GET SIZE 
int Treap::getSize() {
    return size;
}

// GET ROTATION COUNT 
int Treap::getRotationCount() {
    return rotationCount;
}

// PRINT INORDER 
void Treap::printInorder() {
    inorderHelper(root);
    cout << endl;
}

void Treap::inorderHelper(TreapNode* node) {
    if (node == nullptr) return;

    inorderHelper(node->left);
    cout << "(" << node->post.postId << ", score:" << node->post.score
        << ", pri:" << node->priority << ") ";
    inorderHelper(node->right);
}

// GET BALANCE FACTOR 
int Treap::getBalanceFactor() {
    if (root == nullptr) {
        return 0;
    }
    return getBalanceFactorHelper(root);
}

int Treap::getBalanceFactorHelper(TreapNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;

    vector<TreapNode*> currentLevel;
    vector<TreapNode*> nextLevel;

    if (node->left != nullptr) {
        currentLevel.push_back(node->left);
        while (!currentLevel.empty()) {
            leftHeight++;
            nextLevel.clear();
            for (TreapNode* n : currentLevel) {
                if (n->left != nullptr) nextLevel.push_back(n->left);
                if (n->right != nullptr) nextLevel.push_back(n->right);
            }
            currentLevel = nextLevel;
        }
    }

    currentLevel.clear();
    if (node->right != nullptr) {
        currentLevel.push_back(node->right);
        while (!currentLevel.empty()) {
            rightHeight++;
            nextLevel.clear();
            for (TreapNode* n : currentLevel) {
                if (n->left != nullptr) nextLevel.push_back(n->left);
                if (n->right != nullptr) nextLevel.push_back(n->right);
            }
            currentLevel = nextLevel;
        }
    }

    return leftHeight - rightHeight;
}

//  GET MOST RECENT 
vector<Post> Treap::getMostRecent(int k) {
    vector<Post> result;

    if (root == nullptr || k <= 0) {
        return result;
    }

    vector<TreapNode*> stack;
    TreapNode* current = root;

    while ((!stack.empty() || current != nullptr) && result.size() < k) {
        while (current != nullptr) {
            stack.push_back(current);
            current = current->right;
        }

        current = stack.back();
        stack.pop_back();
        result.push_back(current->post);

        current = current->left;
    }

    return result;
}


// STRUCTURAL VALIDATION FUNCTIONS


// Validate BST Property: left < parent < right (by postId)
bool Treap::validateBSTProperty(TreapNode* node, string* minId, string* maxId) {
    if (node == nullptr) {
        return true;
    }

    // Check if current node violates BST property
    if (minId != nullptr && node->post.postId <= *minId) {
        return false;
    }
    if (maxId != nullptr && node->post.postId >= *maxId) {
        return false;
    }

    // Recursively check left and right subtrees
    return validateBSTProperty(node->left, minId, &(node->post.postId)) &&
        validateBSTProperty(node->right, &(node->post.postId), maxId);
}

// Validate Heap Property: parent priority >= children priority
bool Treap::validateHeapProperty(TreapNode* node) {
    if (node == nullptr) {
        return true;
    }

    // Check left child
    if (node->left != nullptr) {
        if (node->left->priority > node->priority) {
            cout << "  Heap violation: " << node->left->post.postId
                << " (priority: " << node->left->priority << ") > parent "
                << node->post.postId << " (priority: " << node->priority << ")" << endl;
            return false;
        }
    }

    // Check right child
    if (node->right != nullptr) {
        if (node->right->priority > node->priority) {
            cout << "  Heap violation: " << node->right->post.postId
                << " (priority: " << node->right->priority << ") > parent "
                << node->post.postId << " (priority: " << node->priority << ")" << endl;
            return false;
        }
    }

    // Recursively check children
    return validateHeapProperty(node->left) && validateHeapProperty(node->right);
}

// Public function to check BST property
bool Treap::isBSTValid() {
    return validateBSTProperty(root, nullptr, nullptr);
}

// Public function to check Heap property
bool Treap::isHeapValid() {
    return validateHeapProperty(root);
}

// Validate entire Treap structure
bool Treap::validateStructure() {
    bool bstValid = isBSTValid();
    bool heapValid = isHeapValid();
    return bstValid && heapValid;
}

// Print detailed validation report
void Treap::printValidationReport() {
    cout << endl;
    cout << "=====================================================" << endl;
    cout << "         TREAP STRUCTURAL VALIDATION REPORT          " << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    cout << "Tree Statistics:" << endl;
    cout << "  - Size: " << size << " nodes" << endl;
    cout << "  - Height: " << getHeight() << endl;
    cout << "  - Balance Factor: " << getBalanceFactor() << endl;
    cout << "  - Total Rotations: " << rotationCount << endl;
    cout << endl;

    if (root != nullptr) {
        cout << "Root Node:" << endl;
        cout << "  - Post ID: " << root->post.postId << endl;
        cout << "  - Priority (Score): " << root->priority << endl;
        cout << "  - Timestamp: " << root->post.timestamp << endl;
        cout << endl;
    }

    cout << "Validation Results:" << endl;

    // Check BST Property
    bool bstValid = isBSTValid();
    cout << "  - BST Property (left < parent < right by postId): ";
    if (bstValid) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "FAILED" << endl;
    }

    // Check Heap Property
    bool heapValid = isHeapValid();
    cout << "  - Heap Property (parent priority >= children): ";
    if (heapValid) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "FAILED" << endl;
    }

    cout << endl;
    cout << "=====================================================" << endl;
    if (bstValid && heapValid) {
        cout << "  TREAP STRUCTURE IS VALID!" << endl;
    }
    else {
        cout << "  TREAP STRUCTURE IS INVALID!" << endl;
    }
    cout << "=====================================================" << endl;
    cout << endl;
}