#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef struct _bstree{
   	int data;
    int idx;
    _bstree * left;
   	_bstree * right; 
} BSTree;

typedef pair<pair<int, int>, int> Node;

BSTree* makeBST(Node nodeinfo){
   	BSTree * root = (BSTree*) malloc(sizeof(BSTree));
    root->data = nodeinfo.first.second;
    root->idx = nodeinfo.second;
    root->left = NULL;
    root->right = NULL;
    return root;
}

BSTree* makeNewNode(Node nodeinfo){
    BSTree* newNode = (BSTree*)malloc(sizeof(BSTree));
    newNode->data = nodeinfo.first.second;
    newNode->idx = nodeinfo.second;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void InsertBST(Node nodeinfo, BSTree * ptree){
   	BSTree * newNode = makeNewNode(nodeinfo);
    BSTree * cur = ptree;
    BSTree * parent;
    while(cur != NULL){
        parent = cur;
       	if(cur->data > newNode->data) cur = cur->left; 
        else if(cur->data < newNode->data) cur = cur->right;
    }
    if(parent->data > newNode->data) parent->left = newNode;
    else parent->right = newNode;
}

void preorderTranverse(vector<int>& track, BSTree * ptree){
    if(ptree == NULL) return;
    track.push_back(ptree->idx);
   	preorderTranverse(track, ptree->left);
    preorderTranverse(track, ptree->right);
}

void postorderTranverse(vector<int>& track, BSTree * ptree){
    if(ptree == NULL) return;
   	postorderTranverse(track, ptree->left); 
   	postorderTranverse(track, ptree->right); 
    track.push_back(ptree->idx);
}

void freeAll(BSTree * node){
   	if(node == NULL) return;
    freeAll(node->left);
    freeAll(node->right);
    free(node);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
   	vector<Node> nodes;	
    int tmpidx = 1;
    
    for(auto elem : nodeinfo){
       	nodes.push_back({{elem[1], elem[0]}, tmpidx++});
    }
    
    sort(nodes.begin(), nodes.end(), greater<Node>());
	BSTree * tree = makeBST(nodes[0]);
    
    for(int i = 1; i < nodes.size(); i++){
        InsertBST(nodes[i], tree);
    }
    
    vector<int> preTran, postTran;
    
   	preorderTranverse(preTran, tree);
    postorderTranverse(postTran, tree);
    
    answer.push_back(preTran);
    answer.push_back(postTran);
    
    freeAll(tree);
    return answer;
}