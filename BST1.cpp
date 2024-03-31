#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


node*insertInfoBST(node*root,int d){
    //base case
    if(root==NULL){
        root=new node(d);
        return root;
    }

    if(d>root->data){
        // right part me insert karna h
        root->right=insertInfoBST(root->right,d);
    }
    else{
        // left part me insert karna h
        root->left=insertInfoBST(root->left,d);
    }
    return root;
}



void takeinput(node*&root){
    int data;
    cout<<"Enter the data: \n";
    cin>>data;

    while(data!=-1){
        root=insertInfoBST(root,data);
        cout<<"Enter the data: \n";
        cin>>data;
    }
}


void levelorderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse ho choka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


int main(){
    node*root=NULL;
    takeinput(root);
    levelorderTraversal(root);

}  
   
   
    
    
   
     