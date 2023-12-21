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
int height(node* root){
    if(root == NULL)
    return 0;

    int leftheight = height(root -> left);
    int rightheight = height(root -> right);

    int ans = max(leftheight, rightheight);

    return ans + 1;
}
int diameter(node* root){
    if(root == NULL)
    return 0;

    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left) + height(root -> right);

    int ans = max(op1, op2);
    int finalans = max(ans , op3);
    return finalans;
}
int main(){
    node* root = NULL;

    root = buildTree();

    int a = diameter(root);

    cout<<a;
}