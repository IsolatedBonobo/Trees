#include<iostream>
#include<queue>

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
void inordertraversal(node* root){
    // base case 
    if(root == NULL)
    return ;

    // follws up the order LNR
    inordertraversal(root -> left);
    cout<<root -> data<<" ";
    inordertraversal(root -> right);
}
void preorder(node* root ){
    // base case 
    if(root == NULL){
        cout<<endl;
        return;
    }

    // follws up the order NLR
    cout<<root -> data<<" ";
    inordertraversal(root -> left);
    inordertraversal(root -> right);
}
void postorder(node* root){
    // base case 
    if(root == NULL){
        cout<<endl;
        return;
    }
    

    // follws up the order LRN
    inordertraversal(root -> left);
    inordertraversal(root -> right);
    cout<<root -> data<<" ";
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
int main(){
    node* root = NULL;

    root = buildTree();
    levelorder(root);
    cout<<"postorder traversal "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"pre order traversal"<<endl;
    preorder(root);

    
    
}