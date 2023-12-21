#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left ;
    node* right;

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
void zig_zag_order(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int count = 1 ;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        // s3
        if(temp == NULL){
            cout<<endl;
            count ++;
            if(!q.empty())
                q.push(NULL);
        }
        else if(count % 2 == 0){
            cout<<temp -> data<<" ";
            if(temp -> left )
            q.push(temp -> left);
            if(temp -> right)
            q.push(temp -> right);
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> right)
            q.push(temp -> right);
            if(temp -> left )
            q.push(temp -> left);
        }
    }
}
void zigzag(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    int levelcount = 1;
    // we notice ki odd levels pr LTR jaa rha hai, while even levels pr RTL jaa hai control of printing ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop();

        if(temp == NULL){
            cout<<endl;
            levelcount ++;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(levelcount % 2 != 0){
                // control for even levels 
                cout<<temp -> data <<" ";
                if(temp -> right)
                q.push(temp -> right);
                if(temp -> left)
                q.push(temp -> left);
            }
            else{
                cout<<temp -> data<<" ";
                
                if(temp -> left)
                q.push(temp -> left);
                if(temp -> right)
                q.push(temp -> right);
            }
        }
    }
}
int main(){
    node* root ;
    root = buildtree();
    levelorder(root);
    cout<<endl;
    zigzag(root);
}