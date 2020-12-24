#include <iostream>
#include <cstring>
#include <fstream>

/* A Binary Search Tree that can take use input (console) or from a file, then add value to tree,
 * search numbers, print (tree, min to max, and max to min), remove numbers, and quit program. 
 * Author: Ryan Le
 * Date: 12/23/2020
 */

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
void printMin(node* &root);
void printMax(node* &oroot);
void printTree(node* &root, int space);
node* search(node* &root, int value);
int findLargest(node* &root);
void remove(node* &root, int value);

using namespace std;
int input;

int main() {
  node* root = NULL;
  char action[80];
  bool exit = 0;

  cout << "Welcome to Binary Search Tree" << endl;
  while (exit == 0) {
    cout << "Executable Actions: FILE, ADD, SEARCH, PRINT, REMOVE, QUIT" << endl;
    cin >> action;

    //FILE ADD
    //from Heap assignment
    if (strcmp(action, "FILE") == 0) {
      ifstream indata;
      int num;
      indata.open("numberFile.txt");
      indata >> num;
      while ( !indata.eof()) {
	add(root, num);
	indata >> num;
      }
      indata.close();
      cout << "Read file" << endl;
    }

    //ADD
    else if (strcmp(action, "ADD") == 0) {
      cout << "How many numbers do you want to enter? ";
      int numAmount;
      cin >> numAmount;
      cout << "Enter numbers between 1-999." << endl;
      for (int i = 1; i < numAmount+1; i++) {
	cout << "[" << i << "] Enter number: ";
	cin >> input;
	add(root, input);
      }
    }

    //SEARCH
    else if (strcmp(action, "SEARCH") == 0) {
      cout << "Search number: ";
      cin >> input;
      search(root, input);
    }

    //PRINT
    else if (strcmp(action, "PRINT") == 0) {
      cout << "Print Min to Max (MIN), Max to Min (MAX), or tree (TREE) ?" << endl;
      cin >> action;
      //Prints from Min to Max
      if (strcmp(action, "MIN") == 0) {
	printMin(root);
	cout << endl;
      }
      //Prints from Max to Min
      else if (strcmp(action, "MAX") == 0) {
	printMax(root);
	cout << endl;
      }
      //Prints Tree
      else if (strcmp(action, "TREE") == 0) {
	printTree(root, 0);
      }
    }

    //DELETE
    else if (strcmp(action, "REMOVE") == 0) {
      cout << "Remove number: ";
      cin >> input;
      search(root, input); //tells user if the wanted delete number is in tree
      remove(root, input);
    }

    //QUIT
    else if (strcmp(action, "QUIT") == 0) {
      exit = 1;
    }

    //If typed something else, try again
    else {
      cout << "Please try again." << endl;
    }
  }
  
  //cout << "Largest number" << findLargest(root->left) << endl;
  return 0;
}

//ADD Function
void add(node* &root, int value) {
  if (root == NULL) {
    root = new node(value);
  }
  else if (value <= root->value) {  // add to the left of parent.
    add(root->left, value);
  }
  else if (value > root->value) {  // add to the right of parent.
    add(root->right, value);
  }
}

//prints from min to max by traverse to the most left node first.
void printMin(node* &root) {
  node* currentPtr = root; 
  if (root == NULL) {
    cout << "The tree is empty" << endl;
  }
  else {
    if (currentPtr->left != NULL) {
      printMin(currentPtr->left);
    }
    cout << currentPtr->value << " ";
    if (currentPtr->right != NULL) {
      printMin(currentPtr->right);
    }
  }
}

//prints from max to min order by traverse to the most right first.
void printMax(node* &root) {
  node* currentPtr = root;
  if (root == NULL) {
    cout << "The tree is empty" << endl;
  }
  else {
    if (currentPtr->right != NULL) {
      printMax(currentPtr->right);
    }
    cout << currentPtr->value << " ";
    if (currentPtr->left != NULL) {
      printMax(currentPtr->left);
    }
  }
}

//prints Binary tree horizontally.
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

//SEARCH function if number in the tree is existing.
node* search(node* &root, int value) {
  if (root != NULL) {
    if (root->value == value) {
      cout << "Value " << value << " found" << endl;
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
    cout << "Value " << value << " not found" << endl;
    return NULL;
  }
  
}

//finds largest number
int findLargest(node* &root) {
  node* currentPtr = root;
  while(currentPtr != NULL && currentPtr->right != NULL) {
    currentPtr = currentPtr->right;
  }
  return currentPtr->value;
}

//Remove function
void remove(node* &root, int value) {
  if (root->value == value) {
    
    //Case 0 - 0 children
    if (root->left == NULL && root->right == NULL) {
      root = NULL;
      //  cout << "meatballs" << endl;
    }
    //Case 1 - 1 child 
    else if (root->left != NULL && root->right == NULL) {
      root = root->left;
      //cout << "pasta" << endl;
    }
    else if (root->left == NULL && root->right != NULL) {
      root = root->right;
      //cout << "eggrolls" << endl;
    }
    //Case 2 - 2 children
    else {
      //cout << "crackers" << endl;
      int largestInLeftSubTree = findLargest(root->left);
      root->value = largestInLeftSubTree;
      remove(root->left, largestInLeftSubTree);
      //cout << "bread" << endl;
    }
  }
  else {
    if (value < root->value && root->left != NULL) {
      remove(root->left, value);
    }
    else if (value > root->value && root->right != NULL) {
      remove(root->right, value);
    }
  }  
}
