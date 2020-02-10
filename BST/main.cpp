// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for
// output.
//

#include "BST312.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
void print(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<int> bst;

    int s;
    inFile >> s;
    while (inFile) {

        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    // cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = 1;

    if (bst.isItemInTree(s)) {
        cout << "Is item " << s << " in tree? "
             << "TRUE" << endl;
    } else {

        cout << "Is item " << s << " in tree? "
             << "FALSE" << endl;
    }
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;
}
