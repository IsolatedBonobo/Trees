#include<bits/stdc++.h>

using namespace std;
    // building tree 
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
void balance(node* root, bool &finalans){
        if(root == NULL)
        return ;

        int leftheight = height(root -> left);
        int rightheight = height(root -> right);
        
        if(abs(leftheight - rightheight) > 1){
            finalans = 0;
            return ;
        }
        balance(root -> left, finalans);
        balance(root -> right, finalans);


    }
bool isBalanced(node* root) {
        bool ans = 1;
        balance(root, ans);
        return ans ;
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
nt main(){
    node* root = NULL;
    root = buildTree();

    levelorder(root);
    
}