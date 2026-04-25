#ifndef _NODE_H_
#define _NODE_H_
#include "Property.hpp"
struct Node{
    Node *prev;
    Property data;
    Node *next;
    Node(Property dataNode,Node *prev = nullptr, Node *next = nullptr);

};
#endif 