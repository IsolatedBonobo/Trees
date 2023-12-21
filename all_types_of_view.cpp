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
void top_view(node* root){
    if(root == NULL)
        return;
    
    // creating map to store horizontal distance and uske corresponding node* ka data;
    map<int, int> topnode;

    // creating a queue which stores two types of data node* and horizontal distance
    queue<pair<node*, int>> q ;

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node* , int > temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        if(topnode.find(hd) == topnode.end()){
            topnode[hd] = frontnode -> data;
        }
        if(frontnode -> left )
            q.push(make_pair(frontnode -> left, hd - 1 ));
            
        if(frontnode -> right )
            q.push(make_pair(frontnode -> right, hd + 1 ));
    }
    // printing ans ;
    for(auto i : topnode){
        cout<<i.first<<"->"<<i.second<<endl;
    }

}
void bottom_view(node* root){
    if(root == NULL)
        return;
    
    // creating map to store horizontal distance and uske corresponding node* ka data;
    map<int, int> topnode;

    // creating a queue which stores two types of data node* and horizontal distance
    queue<pair<node*, int>> q ;

    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node* , int > temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;
        topnode[hd] = frontnode -> data;
        if(frontnode -> left )
            q.push(make_pair(frontnode -> left, hd - 1 ));
            
        if(frontnode -> right )
            q.push(make_pair(frontnode -> right, hd + 1 ));
    }
    // printing ans ;
    for(auto i : topnode){
        cout<<i.first<<"->"<<i.second<<endl;
    }

}
void left_view(node* root, vector<int> &ans ,int level ){
    if(root == NULL)
        return;
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    // left call pehle 
    left_view(root -> left, ans, level++);
    left_view(root -> right, ans, level++);
}
void right_view(node* root, vector<int> &ans int level ){
    if(root == NULL)
        return;
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    // right call pehle 
    right_view(root -> right, ans, level++);
    right_view(root -> left, ans, level++);
}
int main(){
    node* root = buildtree();

    levelorder(root);
}