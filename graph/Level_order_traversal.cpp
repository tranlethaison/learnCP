#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left, * right;
};

void levelOrder(Node* node){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  queue<Node*> Q;

  Q.push(node);

  while(!Q.empty()){
    Node* first = Q.front();
    cout << first->data << ' ';
    Q.pop();

    if(first->left != NULL)
      Q.push(first->left);

    if(first->right != NULL)
      Q.push(first->right);
  }
}