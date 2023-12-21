#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left ;
    node* right ;
    node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;

    }
};
node* buildtree(){
    int data;
    cout<<"enter the data for root node"<<endl;
    cin>>data;

    if(data == -1)
    return NULL;
    // step 1
    node* root = new node(data);
    // step 2 
    cout<<"enter the data for left node"<<endl;
    root -> left = buildtree();
    // step 3
    cout<<"enter the data for right node"<<endl;
    root -> right = buildtree();

    return root ;
}
// printing level order traversal level wise 
void levelorder(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        // s3
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp -> data<<" ";
        if(temp -> left )
        q.push(temp -> left);       
        if(temp -> right)
        q.push(temp -> right);
        }
    }
}

int main(){
    node* root ;
    root = buildtree();
    levelorder(root);
    
}