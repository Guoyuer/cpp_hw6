#include <iostream>
#include "my_tree.h"

int main() {
    auto tree = new btree();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    auto tree1 = tree;
}