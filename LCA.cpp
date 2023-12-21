#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data ;
    node* left;
    node* right ;
    node(int data){
        this -> data = data ;
        left = NULL;
        right = NULL;
    }
};
node* buildTree(){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
// anjane me hi base case reach ho gya 
    if(data == -1 ){
        return NULL;
    }
    // step 1 creating root node
    node* root = new node(data);
    // step 2 left node ko sambhalna 
    root-> left = buildTree();
    // step 3 right node ko sambhalna 
    root -> right = buildTree();
    return root;
}
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
node* search(node* root, node* p, node* q){
    if(root == NULL)
        return NULL;
    if(root -> data == p -> data)
    return p;
    if(root -> data == q -> data)
    return q;

    node* leftans = search(root -> left, p, q);
    node* rightans = search(root -> right, p, q);
    
    if(leftans == NULL && rightans == NULL)
    return NULL;
    else if(leftans != NULL && rightans == NULL)
    return leftans;
    else if(leftans == NULL && rightans != NULL)
    return rightans;
    else
    return root;
}

int main(){
    node* root ; 
    root = buildTree();
    levelorder(root);
    node* p ;
    p -> data = 50;
    vector<int>arr;
    search_and_store(root, arr, p );
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}