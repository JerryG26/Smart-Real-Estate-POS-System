#ifndef _NODE_H_
#define _NODE_H_
#include "Property.hpp"
struct Node{
    Property data;
    Node *next;
    Node(Property data, Node *next = nullptr);

};
#endif 