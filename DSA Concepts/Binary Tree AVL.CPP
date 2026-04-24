#include <iostream>
using namespace std;

struct Node{
    int data; 
    int hight;
    Node *left , *right;
    
    Node(int value){
        data = value;
        hight = 1;
        left = right = NULL;
    }
};
 // get Hight code 
 int getHight(Node *root){
     if(root == NULL){
         return 0;
     }
     
     return root->hight;
 }
 
  // getBalance 
  
  int getBalance(Node *root){
      return getHight(root->left) - getHight(root->right);
  }
  
  // right Rotation
  Node* rightRotation(Node *root){
      Node* child = root->left;
      Node* temp = child->right;
      
      child->right = root;
      root->left = temp;
      
      // update hight
      root->hight = 1+max(getHight(root->left), getHight(root->right));
      child->hight = 1+max(getHight(child->left), getHight(child->right));
      
      return child;
      
  }
  
  // left Rotation
  Node* leftRotation(Node *root){
      Node* child = root->right;
      Node* temp = child->left;
      
      child->left = root;
      root->right = temp;
      
      // update hight
      root->hight = 1+max(getHight(root->left), getHight(root->right));
      child->hight = 1+max(getHight(child->left), getHight(child->right));
      
      return child;
      
  }

  
  





Node* InsertAVL(Node* root, int value){
    // if node doesnt exist
    if(root == NULL){
        return new Node(value);
    }
    // if exist 
    if(value < root->data){
        root->left = InsertAVL(root->left, value);
    }
    else if(value > root->data){
        root->right = InsertAVL(root->right, value);
    }
    else{
        return root ; // duplicate element are not allowed 
    }
    
    return root;
    
  //     update hight
  
  root->hight = 1+max(getHight(root->left), getHight(root->right));
  
  // check balance factor 
  
  int balance = getBalance(root);
  
  // case 1: L-L 
  if(balance >1 && value < root->left->data){
      return rightRotation(root);
  }
  // case 2: R-R
  else if(balance < -1 && value > root->right->data){
      return leftRotation(root);
  }
  // case 3: L-R
 else if(balance >1 && value > root->left->data){
     root->left = leftRotation(root->left);
     return rightRotation(root);
      
  }
  // case 4: R-L
  else if(balance < -1 && value < root->right->data){
      root->right = rightRotation(root->right);
      return leftRotation(root);
      
  }
    
    
}

void Inorder(Node *root){
    if(root == NULL){
        return ;
    }
    else {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}


int main(){
    Node *root = NULL;
    root = InsertAVL(root, 3);
    root = InsertAVL(root, 4);
    root = InsertAVL(root, 3);
    root = InsertAVL(root, 1);
    root = InsertAVL(root, 2);
    
    Inorder(root);
    
    return 0;
}