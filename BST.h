#ifndef BST_H
#define BST_H

#include "Post.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BSTNode {
    Post post;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Post p) : post(p), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    int size;

    BSTNode* searchHelper(BSTNode* node, string postId);
    BSTNode* deleteHelper(BSTNode* node, string postId);
    BSTNode* findMin(BSTNode* node);
    int heightHelper(BSTNode* node);
    Post* findMaxScoreHelper(BSTNode* node, Post* currentMax);
    int getBalanceFactorHelper(BSTNode* node);

public:
    BST();

    
    void addPost(string id, int timestamp, int score);
    void deletePost(string postId);
    Post* searchPost(string postId);
    void likePost(string postId);
    Post* getMostPopular();
    vector<Post> getMostRecent(int k);

    // Metrics
    int getHeight();
    int getSize();
    int getBalanceFactor();
};

#endif