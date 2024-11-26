#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    node* right;
    node* left;

    node(int val)  {
        data = val;
        right = NULL;
        left = NULL;
    }
} node;

node* root = NULL;

void bst_insert(int val) {
    node* newNode = new node(val);
    if (root != NULL) {
        node* curr = root;
        node* prev = root;
        while (curr != NULL) {
            prev = curr;
            if (val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        if (val < prev->data) 
            prev->left = newNode;
        else prev->right = newNode;
    }
    else 
        root = newNode;
}

void bst_delete(int val) {
    node* curr = root;
    node* prev = root;

    // locate the node 
    while (curr != NULL) {
        if (curr->data == val) break;   // node found
        if (curr->data > val) {
            prev = curr;
            curr = curr->left;
        }
        else {
            prev = curr;
            curr = curr->right;
        } 
    }
    if (curr == NULL) return;   // not found!

    // case 1 : no subtree
    if (curr->left == NULL and curr->right == NULL) {
        if (curr == prev->left) prev->left = NULL;
        else prev->right = NULL;
    }

    // case 2 : one subtree
    else if (curr->left == NULL or curr->right == NULL)  {
        if (curr->left == NULL) {  // only right subtree present
            if (prev->right == curr) {
                if (curr->left == NULL) // curr er right subtree thakle right ta uthbe
                    prev->right = curr->right;
                else prev->right = curr->left;
            }
            else {
                if (curr->left == NULL) // curr er left subtree thakle left ta uthbe
                    prev->left = curr->right;
                else prev->left = curr->left;
            }
        }
        else {  // only left subtree present
            if (prev->right == curr) prev->right = curr->left;
            else prev->left = curr->left;
        }
    }
    // case 3 : both subtree
    else if (curr->left != NULL and curr->right != NULL) {
        node* temp = curr;
        prev = curr;
        // if we go to the left, we'll need the maximum
            // if we go to the right, we'll need the minimum
                // we're going to the right... so we need the minimum value which would be on the leftest;
        while (curr->left != NULL) {
            prev = curr;
            curr = curr->left;
        }

        temp->data = curr->data;

        if (prev->left == curr) prev->left = curr->right;
        else prev->right = curr->right;
    }
}

/*
            100
           /   \
          50   200 <---------------------temp (eita delete kora lagbe)
               /  \
                  300 <------------------prev
                 /   \
      (leftest)250 <--[...]--------------curr
                \
                270
              (or null)

*/

void inOrder(node* root) 
{
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " " ;
        inOrder(root->right);
    }
}



int main (void)
{
    system("cls");
    int x;
    for (int i=1; i<=11; i++) {
        cin >> x;
        bst_insert(x);
    }

    inOrder(root);
    bst_delete(18);
    cout << endl;
    inOrder(root);
}
/*
    // input : 12 6 9 18 4 10 5 16 49 31 43
                    12
                  /    \
                6        18
               / \       / \
              4   9     16  49
              \    \        /
               5    10     31
                            \
                             43

*/
