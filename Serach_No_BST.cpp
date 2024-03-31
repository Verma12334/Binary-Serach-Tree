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
    

void BST(node*root){
    int data;
    cout<<"Enter the data  :\n";
    cin>>data;
    while(data!=-1){
        root=InsertBST(root,data);
    cout<<"Enter the data  :";
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


bool CkeckBST_Number(node*root,int value){
    // base case
    if(root==NULL){
        return false;
    }
    if(root->data==value){
        return true;
    }

    if(root->data>value){
        return CkeckBST_Number(root->left,value);
    }
    else{
        return CkeckBST_Number(root->right,value);
    }

    
}

bool Two_nd_way_check_number_BST(node*root,int value){
    node*temp=root;
    while(temp!=NULL){
        if(root->data==value){
            return true;
        }
        if(root->data>value){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}


int main(){
    node*root=NULL;
    BST(root);
    levelorderTraversal(root);

    cout<<"Enter the value for checking present or not in BST:\n";
    int value;
    cin>>value;
    if(CkeckBST_Number(root,value)){
        cout<<"Present\n";
    }
    else{
        cout<<"NOT Present\n";
    }
}