#include "BST.h"

using namespace std;

BST::BST() {
    root = nullptr;
    size = 0;
}

// ADD POST (Ordered by TIMESTAMP) 
void BST::addPost(string id, int timestamp, int score) {
    Post post(id, timestamp, score);
    BSTNode* newNode = new BSTNode(post);

    if (root == nullptr) {
        root = newNode;
        size++;
        return;
    }

    BSTNode* current = root;
    BSTNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        // ORDER BY TIMESTAMP 
        if (post.timestamp < current->post.timestamp) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (post.timestamp < parent->post.timestamp) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    size++;
}

// SEARCH POST (by postId - must traverse entire tree) 
Post* BST::searchPost(string postId) {
    // Since BST is ordered by timestamp, we must search entire tree for postId
    if (root == nullptr) {
        return nullptr;
    }

    vector<BSTNode*> stack;
    stack.push_back(root);

    while (!stack.empty()) {
        BSTNode* node = stack.back();
        stack.pop_back();

        if (node->post.postId == postId) {
            return &(node->post);
        }

        if (node->left != nullptr) {
            stack.push_back(node->left);
        }
        if (node->right != nullptr) {
            stack.push_back(node->right);
        }
    }

    return nullptr;
}

BSTNode* BST::searchHelper(BSTNode* node, string postId) {
    return nullptr;
}

// DELETE POST (by postId - must find first, then delete) 
void BST::deletePost(string postId) {
    // Find the node and its parent
    BSTNode* current = root;
    BSTNode* parent = nullptr;
    bool isLeftChild = false;

    // Must traverse to find by postId 
    vector<BSTNode*> stack;
    vector<BSTNode*> parentStack;
    vector<bool> isLeftStack;

    stack.push_back(root);
    parentStack.push_back(nullptr);
    isLeftStack.push_back(false);

    while (!stack.empty()) {
        current = stack.back();
        parent = parentStack.back();
        isLeftChild = isLeftStack.back();
        stack.pop_back();
        parentStack.pop_back();
        isLeftStack.pop_back();

        if (current == nullptr) continue;

        if (current->post.postId == postId) {
            break;
        }

        if (current->left != nullptr) {
            stack.push_back(current->left);
            parentStack.push_back(current);
            isLeftStack.push_back(true);
        }
        if (current->right != nullptr) {
            stack.push_back(current->right);
            parentStack.push_back(current);
            isLeftStack.push_back(false);
        }

        if (stack.empty()) {
            return; 
        }
    }

    if (current == nullptr || current->post.postId != postId) {
        return; 
    }

    // Case 1: No children
    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            root = nullptr;
        }
        else if (isLeftChild) {
            parent->left = nullptr;
        }
        else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Case 2: One child (right)
    else if (current->left == nullptr) {
        if (current == root) {
            root = current->right;
        }
        else if (isLeftChild) {
            parent->left = current->right;
        }
        else {
            parent->right = current->right;
        }
        delete current;
    }
    // Case 3: One child (left)
    else if (current->right == nullptr) {
        if (current == root) {
            root = current->left;
        }
        else if (isLeftChild) {
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 4: Two children
    else {
        BSTNode* successorParent = current;
        BSTNode* successor = current->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        current->post = successor->post;

        if (successorParent == current) {
            successorParent->right = successor->right;
        }
        else {
            successorParent->left = successor->right;
        }
        delete successor;
    }

    size--;
}

BSTNode* BST::deleteHelper(BSTNode* node, string postId) {
    return nullptr;
}

BSTNode* BST::findMin(BSTNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

//LIKE POST 
void BST::likePost(string postId) {
    Post* post = searchPost(postId);
    if (post != nullptr) {
        post->score++;
    }
}

// HEIGHT (Iterative) 
int BST::getHeight() {
    if (root == nullptr) {
        return 0;
    }

    vector<BSTNode*> currentLevel;
    vector<BSTNode*> nextLevel;

    currentLevel.push_back(root);
    int height = 0;

    while (!currentLevel.empty()) {
        height++;
        nextLevel.clear();

        for (BSTNode* node : currentLevel) {
            if (node->left != nullptr) {
                nextLevel.push_back(node->left);
            }
            if (node->right != nullptr) {
                nextLevel.push_back(node->right);
            }
        }

        currentLevel = nextLevel;
    }

    return height;
}

int BST::heightHelper(BSTNode* node) {
    return 0;
}

// GET MOST POPULAR (Iterative - must traverse all) 
Post* BST::getMostPopular() {
    if (root == nullptr) {
        return nullptr;
    }

    Post* maxPost = &(root->post);

    vector<BSTNode*> stack;
    stack.push_back(root);

    while (!stack.empty()) {
        BSTNode* node = stack.back();
        stack.pop_back();

        if (node->post.score > maxPost->score) {
            maxPost = &(node->post);
        }

        if (node->left != nullptr) {
            stack.push_back(node->left);
        }
        if (node->right != nullptr) {
            stack.push_back(node->right);
        }
    }

    return maxPost;
}

Post* BST::findMaxScoreHelper(BSTNode* node, Post* currentMax) {
    return nullptr;
}

// GET SIZE 
int BST::getSize() {
    return size;
}

// GET BALANCE FACTOR 
int BST::getBalanceFactor() {
    if (root == nullptr) {
        return 0;
    }
    return getBalanceFactorHelper(root);
}

int BST::getBalanceFactorHelper(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;

    vector<BSTNode*> currentLevel;
    vector<BSTNode*> nextLevel;

    if (node->left != nullptr) {
        currentLevel.push_back(node->left);
        while (!currentLevel.empty()) {
            leftHeight++;
            nextLevel.clear();
            for (BSTNode* n : currentLevel) {
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
            for (BSTNode* n : currentLevel) {
                if (n->left != nullptr) nextLevel.push_back(n->left);
                if (n->right != nullptr) nextLevel.push_back(n->right);
            }
            currentLevel = nextLevel;
        }
    }

    return leftHeight - rightHeight;
}

// GET MOST RECENT (k posts) 
// Returns k posts with most recent timestamps (highest timestamps)
// Uses reverse in-order traversal (right -> node -> left)
vector<Post> BST::getMostRecent(int k) {
    vector<Post> result;

    if (root == nullptr || k <= 0) {
        return result;
    }

    
    vector<BSTNode*> stack;
    BSTNode* current = root;

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