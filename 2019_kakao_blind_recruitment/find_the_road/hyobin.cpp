#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2);

struct node{
    int x,y,value;
    node* left;
    node* right;
};

bool compare(node& n1, node& n2){
    if(n1.y == n2.y){
        return n1.x < n2.x;
    }
    else{
        return n1.y > n2.y;
    }
}

void insert(node* parent, node* child) {
    if(child->x < parent->x) { 
        if(parent->left == NULL)
            parent->left = child;
        else
            insert(parent->left, child);
    } 
    else {
        if(parent->right == NULL)
            parent->right = child;
        else
            insert(parent->right, child);
    }
}

void preorder(node* n1) {
    if(n1 == NULL) return;
    answer[0].push_back(n1->value);
    preorder(n1->left);
    preorder(n1->right);
}

void postorder(node* n1) {
    if(n1 == NULL) return;
    
    postorder(n1->left);
    postorder(n1->right);
    answer[1].push_back(n1->value);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    int len = nodeinfo.size();
    vector<node> map(len);
    
    for(int i=0;i<len;i++){
        node tmp;
        tmp.value=i+1;
        tmp.x=nodeinfo[i][0];
        tmp.y=nodeinfo[i][1];
        map[i]=tmp;
    }
    sort(map.begin(),map.end(),compare);
    
    node* root=&map[0];
    for(int i=1;i<len;i++){
        insert(root,&map[i]);
    }
    preorder(root);
    postorder(root);

    return answer;
}
