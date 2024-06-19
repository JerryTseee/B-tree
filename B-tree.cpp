#include<iostream>
using namespace std;

/*
Properties of B-tree:
-All leaves are at the same level
-every node except the root must contain at least t-1 keys.(root contain minimum of 1 key)
-number of children of node = (t-1) + 1
-like binary search tree, time complexity to search, insert, and delete is O(logn)
*/

const int MAX_KEYS = 10;
const int MAX_CHILDREN = MAX_KEYS + 1;

//build the node
struct Node
{
    int n;
    int key[MAX_KEYS];
    Node* child[MAX_CHILDREN];
    bool leaf;
};

Node* BtreeSearch(Node* x, int k){
    int i = 0;
    while (i < x->n && k > x->key[i])
    {//find the smallest index i such that k <= x.key[i], or set i = x.n + 1
        i++;
    }
    if (i < x->n && k == x->key[i])
    {//found the required key
        return x;
    }
    else if (x->leaf == true)
    {//iterate to the leaf, it is end
        return nullptr;//not found
    }
    return BtreeSearch(x->child[i], k);
}



//
int main() {
    // Create a sample B-tree
    Node* root = new Node();
    root->n = 2;//this is the root node(which has two keys with values 10 and 20)
    root->key[0] = 10;
    root->key[1] = 20;

    root->child[0] = new Node();//a new child node
    root->child[0]->n = 1;//only one key
    root->child[0]->key[0] = 5;
    root->child[0]->leaf = true;//it is a leaf node

    root->child[1] = new Node();//a new child node
    root->child[1]->n = 1;//only one key
    root->child[1]->key[0] = 15;
    root->child[1]->leaf = true;//it is a leaf node
    
    root->leaf = false;//root node is not a leaf!

/*
    (10 20)
    /     \
  (5)     (15)
*/


    // Search for a key in the B-tree
    int searchKey = 5;
    Node* result = BtreeSearch(root, searchKey);

    if (result != nullptr) {
        cout << "Key " << searchKey << " found in the B-tree." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the B-tree." << endl;
    }

    // Cleanup
    delete root->child[0];
    delete root->child[1];
    delete root;

    return 0;
}