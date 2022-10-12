#pragma once

#include <iostream>
#include "DynamicArray.h"
#include "Sequence.h"

using namespace std;

#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define STRING_NOT_CORRECT "string now correct"
#define WRONG_PASS_MESSAGE "there is no such pass"
#define EQUAL_ITEM_MESSAGE "tree already have this item"
#define WRONG_ITEM_MESSAGE "something wrong with your item"

template<class T>
class Map {
private:
    struct Node {
        T item;
        int count;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root = nullptr;
public:
    Map() : root(nullptr) {

    }

    void delMap(Node *ptr) { // Удаление дерева
        if (ptr != NULL) {
            delTree(ptr->left);
            delTree(ptr->right);
            delete ptr;
            ptr = NULL;
        }
    }

    void Add(const T &value) {
        Node **ptr = &(this->root);
        while (*ptr != nullptr) {
            if (value < (*ptr)->item) {
                ptr = &((*ptr)->left);
            } else if (value > (*ptr)->item) {
                ptr = &((*ptr)->right);
            } else {
                throw WRONG_ITEM_MESSAGE;
            }
        }
        *ptr = new Node;
        (*ptr)->item = value;
        (*ptr)->count = 0;
    }

    bool Find(const T &value) { //поиск в дереве, возвращает true или false
        bool flag = false;
        Node **ptr = &(this->root);
        RecursiveGo(ptr, value, flag);
        return flag;
    }

    void Increase(const T &value) { //поиск в дереве, возвращает true или false
        bool flag = false;
        Node **ptr = &(this->root);
        RecursiveGo(ptr, value, flag);
        if ((*ptr)->item == value) {
            (*ptr)->count++;
        }
    }

    void RecursiveGo(Node **ptr, const T &value, bool &flag) {
        if ((*ptr != nullptr) and ((*ptr)->item == value)) {
            flag = true;
            return;
        }
        if (*ptr == nullptr) {
            return;
        }
        RecursiveGo(&((*ptr)->left), value, flag);
        RecursiveGo(&((*ptr)->right), value, flag);
    }

};