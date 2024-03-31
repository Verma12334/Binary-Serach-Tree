#include<iostream>
#include<limits.h>
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

void buildFromLevelOrder(node*&root){
    queue<node*>q;
    cout<<"Enter data for root\n";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

bool vaildateBST(node*root,int min,int max){
    if(root==NULL){
        return true;
    }

    if(root->data<=max && root->data>=min){
        bool left=vaildateBST(root->left,min,root->data);
        bool right=vaildateBST(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }
}//T.C.=O(n)   ...S.C.=O(H)

void inorder(node*root){
    //base case
    if(root==NULL){
        return;
    }


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);


}

int main(){
    node*root=NULL;
    buildFromLevelOrder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    if(vaildateBST(root,INT_MIN,INT_MAX)){
        cout<<"It is vaildate BST\n";
    }
    else{
        cout<<"It is not a vvaildate BST\n";

    }
}