/*
Write a menu driven program in C or C++ to perform the following operations on Binary Search
Tree.

(a) insert a node. d
(b) inorder traversal. d
(c) preorder traversal. d
(d) search an given key. d
(e) Find the smallest element. d
(c) postorder traversal. d
(d) Find the largest element. d
(e) Count the total number of nodes.
(c) Count the total number of external nodes.
(d) Count the total number of internal nodes.
(e) Determine the height of the tree.
(c) Delete items from the tree. d

*/
#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int val){
            value = val;
            left = NULL;
            right = NULL;
        }
};

class BinarySearchTree{
    public:
        Node* root;
        BinarySearchTree(){
            root = NULL;
        }
        void insert(int val){
            if (root == NULL){
                root = new Node(val);
            }
            else{
                Node* curr = root;
                Node* newNode = new Node(val);
                while (true)
                {
                    if (curr->value == val)
                    {
                        cout << "\nEntered value already in the tree. No changes made.\n";
                        return;
                    }
                    else if (curr->value > val && curr->left!=NULL)
                    {
                        curr = curr->left;
                        continue;
                    }
                    else if (curr->value < val && curr->right!=NULL)
                    {
                        curr = curr->right;
                        continue;
                    }
                    else{
                        if (curr->value > val){
                            curr->left = newNode;
                        }
                        else{
                            curr->right = newNode;
                        }
                        cout << "\nInserted.\n";
                        return;
                    }
                    
                }

            }
        }
        void inorder(Node* curr){
            if (root == NULL){
                cout << "\nNo value inserted yet. Nothing to traverse.\n";
            }
            else{
                if (curr == NULL){
                    return;
                }
                inorder(curr->left);
                cout << curr->value << "  ";
                inorder(curr->right);
            }
        }
        void preorder(Node* curr){
            if (root == NULL){
                cout << "\nNo value inserted yet. Nothing to traverse.\n";
            }
            else{
                if (curr == NULL){
                    return;
                }
                cout << curr->value << "  ";
                inorder(curr->left);
                inorder(curr->right);
            }
        }
        void postorder(Node* curr){
            if (root == NULL){
                cout << "\nNo value inserted yet. Nothing to traverse.\n";
            }
            else{
                if (curr == NULL){
                    return;
                }
                inorder(curr->left);
                inorder(curr->right);
                cout << curr->value << "  ";
            }
        }
};

int main(){
    BinarySearchTree bst = BinarySearchTree();
    int item,ch;

    cout << "\nOperations on BST:\n\t  - 0. Exit\n\t  - 1. Insert a value\n\t  - 2. Delete by key\n\t  - 3. Inorder traversal\n\t  - 4. Preorder traversal\n\t  - 5. Postorder traversal\n\t  - 6. Search by key\n\t  - 7. Find Largest Key\n\t  - 8. Find smallest key\n\nPlease enter your choice of operation: ";

    cin >> ch;

    while (ch)
    {
        switch (ch)
        {
        case 0:
            break;
        
        case 1:
            cout << "\nPlease enter the value to be inserted: ";
            cin >> item;
            bst.insert(item);
            break;
        
        case 2:
            break;

        case 3:
            bst.inorder(bst.root);
            break;

        case 4:
            bst.preorder(bst.root);
            break;
        
        case 5:
            bst.postorder(bst.root);
            break;

        default:
            cout << "\nPlease enter only one of the given operation codes 0-8.\n";
            break;
        }

        cout << "\nPlease enter your next operation: ";
        cin >> ch;
    }

    cout << "\nThank you.\n";
    return 0;
}