#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left ;
    Node* right;
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};
void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
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
Node* buildTreeViaPostandInorder(int inorder[], int postorder[], int size, int &postindex, int inorderStart, int inorderEnd){
    // base case 
    if(postindex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    // step 1 creating root node from preorder ka first index
    int element = postorder[postindex--];
    Node* root = new Node(element);
    int pos ;

    for(int i =0;i<size;i++){
        if(inorder[i] == element ){
            pos = i;
            break;
        }
    }
    // step 2 calling for left and right one to solve 
    root -> right = buildTreeViaPostandInorder(inorder, postorder, size, postindex, pos + 1, inorderEnd);
    root -> left = buildTreeViaPostandInorder(inorder, postorder, size, postindex, inorderStart, pos - 1);

    return root ;
}
int main(){
    int inorder[] = {40, 20 ,10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = 6;
    int postindex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size -1;
    Node* root = buildTreeViaPostandInorder(inorder, postorder, size, postindex, inorderStart, inorderEnd);
    levelorder(root);
}