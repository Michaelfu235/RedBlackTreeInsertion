#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Node {

public:
  
  int data;
  char color;

  Node* left;
  Node* right;
  Node* parent;

  
  Node(int newData){
    data = newData;
    color = 'R';
    left = NULL;
    right = NULL;
    parent = NULL;
  }

  Node(){
    color = 'R';
    left = NULL;
    right = NULL;
    parent = NULL;
  }
  
};

void printTree(Node* tree, int depth, int fromwhere);
void rotateLeft(Node* &root, Node* &node);
void rotateRight(Node* &root, Node* &node);
Node* add(Node* &root, int data, bool &LL, bool &RR, bool &LR, bool &RL);


int main(){
  Node* root = NULL;

  bool LL = false;
  bool RR = false;
  bool LR = false;
  bool RL = false;


  
  cout << "help" << endl;
}


void printTree(Node* tree, int depth, int fromwhere){
  if(tree->data == -1){
    cout << "tree is empty" << endl;
    return;
  }
  if(tree->right != NULL){
    printTree(tree->right, depth+1, 1);
  }

  for(int i = 0;i<depth-1;i++){
    cout << "\t";
  }
  if(fromwhere==2){
    cout << "\\____";
  } else if(fromwhere == 1){
    cout << "/▔▔▔▔▔";
    cout << tree->data << " color: " << tree->color << endl;
  }

  if(tree->left != NULL){
    printTree(tree->left, depth+1, 2);
  }
    
}


void rotateLeft(Node* &root, Node* &node){
  Node* y = node->right;
  node->right = y->left;
  if(node->right){
    node->right->parent = node;
  }
  y->parent = node->parent;

  if(!node->parent){
    root = y;
  } else if (node == node->parent->left){
    node->parent->left = y;
  } else {
    node->parent->right = y;
  }
  y->left = node;
  node->parent = y;
}

void rotateRight(Node* &root, Node* &node){
  Node* y = node->left;
  node->left = y->right;
  if(node->left){
    node->left->parent = node;
    
  }
  y->parent = node->parent;
  if(!node->parent){
    root = y;
  } else if (node == node->parent->right){
    node->parent->right = y;
  } else {
    node->parent->left = y;
  }
  y->right = node;
  node->parent = y;
}


Node* add(Node* &root, int data, bool &LL, bool &RR, bool &LR, bool &RL){
  if(root == NULL){
    Node* temp = new Node(data);
    root = temp;
    return root;
  } else {
    bool isRedRed = false;
    if(data < root->data && root->left != NULL){
      Node* temp = root->left;
      return add (temp, data, LL, RR, LR, RL);
    } else if (data < root->data && root->left == NULL){
      Node* newNode = new Node(data);
      root->left = newNode;
      newNode->parent = root;
      return newNode;
    }

    if(data > root->data && root->right != NULL){
      Node* temp = root->right;
      return add(temp, data, LL, RR, LR, RL);
    } else if (data > root->data && root->right == NULL){
      Node* newNode = new Node(data);
      root->right = newNode;
      newNode->parent = root;
      return newNode;
    }
    /*if (data < root->data && root->left == NULL){
    Node* newNode = new Node(data);
    root->left = newNode;
    newNode->parent = root;
    return newNode;*/
  }
  return NULL;
}
