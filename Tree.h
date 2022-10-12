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
class Tree {
private:
    struct Node {
        T item;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root = nullptr;
public:
    Tree() : root(nullptr) {

    }

    void delTree(Node *ptr) { // Удаление дерева
        if (ptr != NULL) {
            delTree(ptr->left);
            delTree(ptr->right);
            delete ptr;
            ptr = NULL;
        }

    }

    void LNR(Node *ptr, Sequence<T> *Arr) { //центрированный обход
        if (ptr == NULL) {
            return;
        }
        LNR(ptr->left, Arr);
        Arr->Append(ptr->item);
        LNR(ptr->right, Arr);
    }

    void RNL(Node *ptr, Sequence<T> *Arr) { //оппозитный центрированный обход
        if (ptr == NULL) {
            return;
        }
        RNL(ptr->right, Arr);
        Arr->Append(ptr->item);
        RNL(ptr->left, Arr);
    }

    void NLR(Node *ptr, Sequence<T> *Arr) { //прямой обход
        if (ptr == NULL) {
            return;
        }
        Arr->Append(ptr->item);
        NLR(ptr->left, Arr);
        NLR(ptr->right, Arr);
    }

    void NRL(Node *ptr, Sequence<T> *Arr) { //оппозитный прямой обход
        if (ptr == NULL) {
            return;
        }
        Arr->Append(ptr->item);
        NRL(ptr->right, Arr);
        NRL(ptr->left, Arr);
    }

    void LRN(Node *ptr, Sequence<T> *Arr) { //обратный обход
        if (ptr == NULL) {
            return;
        }
        LRN(ptr->left, Arr);
        LRN(ptr->right, Arr);
        Arr->Append(ptr->item);
    }

    void RLN(Node *ptr, Sequence<T> *Arr) { //обратный обход
        if (ptr == NULL) {
            return;
        }
        RLN(ptr->left, Arr);
        RLN(ptr->right, Arr);
        Arr->Append(ptr->item);
    }

    Node *Get1PtrRoot() {  // возвращаем указатель на корень
        Node *ptr = this->root;
        return ptr;
    }

    Node **Get2PtrRoot() {  // возвращаем указатель на корень
        Node **ptr = &(this->root);
        return ptr;
    }

    void RecursiveGo(Node **ptr, const T &value, bool &flag) {
        if ((*ptr != nullptr) and ((*ptr)->item == value)) {
            flag = true;
        }
        if (*ptr == nullptr) {
            return;
        }
        RecursiveGo(&((*ptr)->left), value, flag);
        RecursiveGo(&((*ptr)->right), value, flag);
    }

    void RecursiveGoPtr(Node **ptr, T value, Node **CurPtr) {
        if ((*ptr != nullptr) and ((*ptr)->item == value)) {
            *CurPtr = *ptr;
            return;
        }
        if (*ptr == nullptr) {
            return;
        }
        RecursiveGoPtr(&((*ptr)->left), value, CurPtr);
        RecursiveGoPtr(&((*ptr)->right), value, CurPtr);
    }

    bool Find(const T &value) { //поиск в дереве, возвращает true или false
        bool flag = false;
        Node **ptr = &(this->root);
        RecursiveGo(ptr, value, flag);
        return flag;
    }

    void FindWithPointer(T value, Node **CurPtr) {
        Node **ptr = &(this->root);
        RecursiveGoPtr(ptr, value, CurPtr);
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
    }

    void FillWithValues(int size) {
        for (int i = 0; i < size; i++) {
            T data;
            cin >> data;
            Add(data);
        }
    }

    T FindAbsolutePass(const T *pass, int count) { //поиск узла по заданному пути
        Node **ptr = Get2PtrRoot();
        FindWithPointer(pass[0], ptr);
        if (((*ptr)->item) != pass[0]) throw WRONG_PASS_MESSAGE;
        for (int i = 1; i < count; i++) {
            Node** ptrl = &((*ptr)->left);
            Node** ptrr = &((*ptr)->right);
            if (*ptrl != nullptr) {
                if ((*ptrl)->item == pass[i]) {
                    ptr = &((*ptr)->left);
                }
            } else if (*ptrr != nullptr) {
                if ((*ptrr)->item == pass[i]) {
                    ptr = &((*ptr)->right);
                }
            } else {
                throw WRONG_PASS_MESSAGE;
            }
        }
        Node** ptrl = &((*ptr)->left);
        Node** ptrr = &((*ptr)->right);
        if (*ptrl != nullptr) {
            ptr = &((*ptr)->left);
            return (*ptrl)->item;
        } else if (*ptrr != nullptr) {
            ptr = &((*ptr)->right);
            return (*ptrr)->item;
        } else {
            throw WRONG_PASS_MESSAGE;
        }
    }

    T FindRelativePass(string pass, int count, T StartData) { //поиск узла по относительному пути
        Node **ptr = Get2PtrRoot();
        FindWithPointer(StartData, ptr);
        for (int i = 0; i < count; i++) {
            if (ptr == nullptr) throw WRONG_PASS_MESSAGE;
            if (pass[i] == 'R') {
                ptr = &((*ptr)->right);
            } else {
                ptr = &((*ptr)->left);
            }
        }
        if (ptr == nullptr) {
            throw WRONG_PASS_MESSAGE;
        }
        return (*ptr)->item;
    }

    void NLRMerge(Node **ptr1, Node **ptr2) { //прямой обход
        if (*ptr2 == NULL) {
            return;
        }
        if (*ptr1 != nullptr) {
            (*ptr1)->item = (*ptr1)->item + (*ptr2)->item;
        } else {
            *ptr1 = new Node;
            (*ptr1)->item = (*ptr2)->item;
        }
        NLRMerge(&((*ptr1)->left), &((*ptr2)->left));
        NLRMerge(&((*ptr1)->right), &((*ptr2)->right));
    }

    void Merge(Tree<T> t1, Tree<T> t2) {
        Node **ptr1 = t1.Get2PtrRoot();
        Node **ptr2 = t2.Get2PtrRoot();
        NLRMerge(ptr1, ptr2);
    }

};
