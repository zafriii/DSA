// BST
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return;
    }
    
    if(val<root->data){
        insert(root->left,val);
    }
    else{
         insert(root->right,val);
    }
}

void inOrder(Node* root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
     inOrder(root->right);
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
    
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    return 1+ max(left,right);
}

Node* LCA(Node* root, int a, int b){
    if(root==NULL|| a==root->data|| b==root->data){
        return root;
    }
    
    Node* left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);
    
    if(root->left==NULL){
        return right;
    }
    if(root->right==NULL){
        return left;
    }
    
    return root;
}

bool isBST(Node* root, int minVal, int maxVal){
    if(root==NULL){
        return true;
    }
    
    if(root->data<minVal||root->data>maxVal){
        return false;
    }
 
    return isBST(root->left, minVal, root->data)&&
           isBST(root->right,root->data , maxVal);
}   

int main() {
    
    Node* root =NULL;
    
    int n;
    cin>>n;
    
    while(n--){
        int temp;
        cin>>temp;
        insert(root,temp);
    }
    
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    
    cout<<"Height :"<<height(root)<<endl;
    cout<<"LCA :"<<(LCA(root,7,12))->data<<endl;
    cout<<"BST or Not?"<<isBST(root,INT_MIN, INT_MAX);
   
    return 0;
}
