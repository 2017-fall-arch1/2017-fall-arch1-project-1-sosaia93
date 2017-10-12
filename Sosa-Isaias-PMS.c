//Sosa, Isaias
//CS 3432 Computer Architecture 1
//Professor Eric Freudenthal
//Project 1 - Personnel-Management-System

#include <stdio.h>
#include <stdlib.h>


int main(){

  printf("Hello");

  return 0;

}

/* node */

struct node{

  int value;
  struct node *left, *right;
};

/* newNode */

struct node* newNode(int number){

  struct node *temp = (struct node *) malloc(sizeof(struct node));
  temp -> value = number;
  temp -> left = temp-> right = NULL;
  return temp;
}

/* inorder */

void inorder(struct node *root){

  if(root != NULL){
    inorder(root->left);
    printf("%d\n", root->value);
    inorder(root->right);
  }
  
}
/* insert */

struct node* insert(struct node* node, int number){

  /*if the tree is empty return a new node */
  if(node = NULL) return newNode(number);

  /*otherwise traverse down the key */
  if(number < node->value)
    node->left = insert(node -> left, number);
  else if(number > node->value)
    node->right = insert(node->right, number);

  /*return the node pointer without any changes */
  return node;
}

  
int main(){

  /*Let us create the following BST
                 50
		/  \
	      30    70
	     /  \  /  \
	     20  40 60  80 */

  struct node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // print inorder traversal of the BST
  inorder(root);

  return 0;
	     

}
