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
    node* root = new node(data);
    root-> left = buildTree();
    root -> right = buildTree();
    return root;
}

int main(){
    int vum = 10;

    cout<<vum ++;
    cout<<++vum;
}