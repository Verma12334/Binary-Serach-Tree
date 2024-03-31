#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
    node*InsertBST(node*root,int d){
        if(root==NULL){
            root=new node(d);
            return root;
        }
        if(d>root->data){

            root->right=InsertBST(root->right,d);
        }
        else{

            root->left=InsertBST(root->left,d);
        }
        return root;
    }
    
void BST(node*&root){
    int data;
    cout<<"Enter the data:\n";
    cin>>data;
    while(data!=-1){
        root=InsertBST(root,data);
    cout<<"Enter the data:\n";
        cin>>data;
    }
}

int Minimum_Value_of_BST(node*root){

    node*temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int main(){
    node*root=NULL;
    BST(root);
   cout<<"Minimum value of BST "<<Minimum_Value_of_BST(root)<<endl;
}