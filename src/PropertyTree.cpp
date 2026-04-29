#include "PropertyTree.hpp"

PropertyTree::PropertyTree() : root(nullptr) {}

PropertyTree::~PropertyTree() {
    destroyTree(root);
}

void PropertyTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void PropertyTree::insert(Property p) {
    insertNode(root, p);
}

void PropertyTree::insertNode(TreeNode*& node, Property p) {
    if (node == nullptr) {
        node = new TreeNode(p);
    } else if (p.getId() < node->property.getId()) {
        insertNode(node->left, p);
    } else if (p.getId() > node->property.getId()) {
        insertNode(node->right, p);
    }
}

Property* PropertyTree::search(int id) {
    TreeNode* result = searchNode(root, id);
    if (result) {
        return &(result->property);
    }
    return nullptr;
}

TreeNode* PropertyTree::searchNode(TreeNode* node, int id) {
    if (node == nullptr || node->property.getId() == id) {
        return node;
    }
    
    if (node->property.getId() > id) {
        return searchNode(node->left, id);
    }
    return searchNode(node->right, id);
}

void PropertyTree::displayAll() {
    inorderPrint(root);
}

void PropertyTree::inorderPrint(TreeNode* node) {
    if (node != nullptr) {
        inorderPrint(node->left);
        node->property.displayInfo();
        inorderPrint(node->right);
    }
}
