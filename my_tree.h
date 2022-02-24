//
// Created by Tmp on 2/24/2022.
//

#ifndef CPP_HW6_MY_TREE_H
#define CPP_HW6_MY_TREE_H
// From http://www.cprogramming.com/tutorial/lesson18.html

#include<memory>

using namespace std;
struct node {
    int key_value;
    unique_ptr<node> left;
    unique_ptr<node> right;
};

class btree {
public:
    btree() {
        root = nullptr;
    }

    void insert(int key) {
        if (root != nullptr)
            insert(key, root);
        else {
            root = new node;
            root->key_value = key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    node *search(int key) {
        return search(key, root);
    }


private:

    void insert(int key, node *leaf) {
        if (key < leaf->key_value) {
            if (leaf->left != nullptr)
                insert(key, leaf->left.get());
            else {
                leaf->left = make_unique<node>();
                leaf->left->key_value = key;
                leaf->left->left = nullptr;    //Sets the left child of the child node to nullptr
                leaf->left->right = nullptr;   //Sets the right child of the child node to nullptr
            }
        } else if (key >= leaf->key_value) {
            if (leaf->right != nullptr)
                insert(key, leaf->right.get());
            else {
                leaf->right = make_unique<node>();
                leaf->right->key_value = key;
                leaf->right->left = nullptr;  //Sets the left child of the child node to nullptr
                leaf->right->right = nullptr; //Sets the right child of the child node to nullptr
            }
        }
    }

    node *search(int key, node *leaf) {
        if (leaf != nullptr) {
            if (key == leaf->key_value)
                return leaf;
            if (key < leaf->key_value)
                return search(key, leaf->left.get());
            else
                return search(key, leaf->right.get());
        } else return nullptr;
    }

    node *root;
};


#endif //CPP_HW6_MY_TREE_H
