#include<iostream>
using namespace std;
int KthAncestor(node* root, int k, node* p){
    if(root == NULL)
    return 0;

    if(root -> data == p -> data){
        return 
    }

    node* leftans = KthAncestor(root -> left, k, p);
    node* rightans = KthAncestor(root -> right, k, p);

}
int main(){

}