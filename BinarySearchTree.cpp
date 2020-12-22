#include <iostream>
#include <cstdlib> //not sure if needed yet (shown in tutorial)

struct node {
  int value;
  node* left;
  node* right;
  node (int newValue) {
    value = newValue;
    left = NULL;
    right = NULL;
  }
};


void add(node* &root, int value);
void print(node* &root);
void printTree(node* &root, int space);
node* search(node* &root, int value);

using namespace std;
int input;

int main() {
  node* root = NULL;
  cout << "Type 16 numbers " << endl;
  
  cin >> input; //1
  add(root, input);
  cin >> input; //2
  add(root, input);
  cin >> input; //3
  add(root, input);
  cin >> input; //4
  add(root, input);
  cin >> input; //5
  add(root, input);
  cin >> input; //6
  add(root, input);
  cin >> input; //7
  add(root, input);
  cin >> input; //8
  add(root, input);
  cin >> input; //9
  add(root, input);
  cin >> input; //10
  add(root, input);
  cin >> input; //11
  add(root, input);
  cin >> input; //12
  add(root, input);
  cin >> input; //13
  add(root, input);
  cin >> input; //14
  add(root, input);
  cin >> input; //15
  add(root, input);
  cin >> input; //16
  add(root, input);
  
  print(root);
  search(root, 200);
  printTree(root, 0);
  return 0;
}

void add(node* &root, int value) {
  if (root == NULL) {
    root = new node(value);
    
    cout << "if " << root->value << endl;
  }
  else if (value < root->value) {
    add(root->left, value);
    cout << "ekse if" << endl;
  }
  else if (value > root->value) {
    add(root->right, value);
  }
}

//prints from min to max
void print(node* &root) {
  node* currentPtr = root; 
  if (root == NULL) {
    cout << "The tree is empty" << endl;
  }
  else {
    if (currentPtr->left != NULL) {
      print(currentPtr->left);
    }
    cout << currentPtr->value << " ";
    if (currentPtr->right != NULL) {
      print(currentPtr->right);
    }
  }
}

//prints tree
//code from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void printTree(node* &root, int space) {
  if(root == NULL){
    return;
  }
  space += 10;

  printTree(root->right, space);
  cout << endl;
  
  for(int i = 10; i < space; i++){
    cout << " ";
  }
  cout << root->value << "\n";
  printTree(root->left, space);
}

//search
node* search(node* &root, int value) {
  if (root != NULL) {
    if (root->value == value) {
      cout << "Search value " << value << " found" << endl;
      return root;
    }
    else {
      if (value < root->value) {
	return search(root->left, value); //search left
      }
      else {
	return search(root->right, value); //search right
      }
    }
  }
  else {
    cout << "Search value " << value << " not found" << endl;
    return NULL;
  }
  
}

