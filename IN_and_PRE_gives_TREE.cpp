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
Node* buildTreeViaPreandInorder(int inorder[], int preorder[], int size, int &preindex, int inorderStart, int inorderEnd){
    // base case 
    if(preindex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    // step 1 creating root node from preorder ka first index
    int element = preorder[preindex++];
    Node* root = new Node(element);
    int pos ;

    for(int i =0;i<size;i++){
        if(inorder[i] == element ){
            pos = i;
            break;
        }
    }
    // step 2 calling for left and right one to solve 
    root -> left = buildTreeViaPreandInorder(inorder, preorder, size, preindex, inorderStart, pos - 1);
    root -> right = buildTreeViaPreandInorder(inorder, preorder, size, preindex, pos + 1, inorderEnd);

    return root ;
}
int main(){
    int inorder[] = {3, 1, 4, 5, 2};
    int preorder[] = {5, 1, 3, 4, 2};
    int size = 5;
    int preindex = 0;
    int inorderStart = 0;
    int inorderEnd = size -1;
    Node* root = buildTreeViaPreandInorder(inorder, preorder, size, preindex, inorderStart, inorderEnd);
    levelorder(root);
}