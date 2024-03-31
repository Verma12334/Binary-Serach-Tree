#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int Minimum_Value_of_BST(node* root) {
    node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

node* InsertBST(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }
    if (d > root->data) {
        root->right = InsertBST(root->right, d);
    }
    else {
        root->left = InsertBST(root->left, d);
    }
    return root;
}

void BST(node*& root) {
    int data;
    cout << "Enter the data:\n";
    cin >> data;
    while (data != -1) {
        root = InsertBST(root, data);
        cout << "Enter the data:\n";
        cin >> data;
    }
}

node* Deletion_Node_of_BST(node* root, int value) {
    // base case 
    if (root == NULL) {
        return root;
    }

    if (root->data == value) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // right child 
        if (root->right != NULL && root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = Minimum_Value_of_BST(root->right);
            root->data = mini;
            root->right = Deletion_Node_of_BST(root->right, mini);
            return root;
        }
    }
    else if (value < root->data) {
        root->left = Deletion_Node_of_BST(root->left, value);
    }
    else {
        root->right = Deletion_Node_of_BST(root->right, value);
    }

    return root;
}

void inorder(node*root){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main() {
    node* root = NULL;
    BST(root);
    inorder(root);
    int value;
    cout << "\nEnter the value of node for deletion:\n";
    cin >> value;
    root = Deletion_Node_of_BST(root, value);
    inorder(root);
    // Print the modified BST or perform other operations as needed
    return 0;
}

//T.C=O(H)AVERADE CASE//WORST CASE O(n).....n=no.of node..H=height