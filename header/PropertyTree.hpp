#ifndef _PROPERTY_TREE_H_
#define _PROPERTY_TREE_H_

#include "Property.hpp"
#include <iostream>

struct TreeNode {
    Property property;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(Property p) : property(p), left(nullptr), right(nullptr) {}
};

class PropertyTree {
private:
    TreeNode* root;

    void insertNode(TreeNode*& node, Property p);
    TreeNode* searchNode(TreeNode* node, int id);
    void inorderPrint(TreeNode* node);
    void destroyTree(TreeNode* node);

public:
    PropertyTree();
    ~PropertyTree();

    void insert(Property p);
    Property* search(int id);
    void displayAll();
};

#endif
