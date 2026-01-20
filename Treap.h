#ifndef TREAP_H
#define TREAP_H

#include "Post.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct TreapNode {
    Post post;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(Post p) : post(p), priority(p.score), left(nullptr), right(nullptr) {}
};

class Treap {
private:
    TreapNode* root;
    int size;
    int rotationCount;

    TreapNode* rotateRight(TreapNode* node);
    TreapNode* rotateLeft(TreapNode* node);
    TreapNode* insertHelper(TreapNode* node, Post post);
    TreapNode* searchHelper(TreapNode* node, string postId);
    TreapNode* deleteHelper(TreapNode* node, string postId);
    int heightHelper(TreapNode* node);
    void inorderHelper(TreapNode* node);
    int getBalanceFactorHelper(TreapNode* node);

    // Validation helpers
    bool validateBSTProperty(TreapNode* node, string* minId, string* maxId);
    bool validateHeapProperty(TreapNode* node);

public:
    Treap();

    
    void addPost(string id, int timestamp, int score);
    void deletePost(string postId);
    Post* searchPost(string postId);
    void likePost(string postId);
    Post* getMostPopular();
    vector<Post> getMostRecent(int k);

    // Metrics
    int getHeight();
    int getSize();
    int getRotationCount();
    int getBalanceFactor();
    void printInorder();

    // Structural Validation 
    bool validateStructure();
    bool isBSTValid();
    bool isHeapValid();
    void printValidationReport();
};

#endif