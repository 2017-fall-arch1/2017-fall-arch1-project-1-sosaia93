//Sosa, Isaias
//CS 3432 Computer Architecture 1
//Professor Eric Freudenthal
//Project 1 - Personnel-Management-System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"


/* node */

struct node{

  char name[50];
  struct node *left, *right;
}*root = NULL, *temp = NULL, *t2, *t1;

int flag = 1;

void main(){

  FILE *fptr;           //To open a file
  char filename[20];    //To store the name of the file
  char c;                //To store each number of the file
  int ch;               

  printf("\nOperations ---:");
  printf("\n1 - Insert an element into tree\n");
  printf("2 - Inorder traversal\n");
  printf("3 - Exit\n");
  printf("4 - Read from a file\n");

  while(1){
    
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch){

    case 1:
      insert();
      break;

    case 2:
      inorder(root);
      break;

    case 3:
      exit(0);
      break;

    case 4:
      printf("Enter the file name to be opened:\n");
      scanf("%s", filename);

      //Open the file for reading
      fptr = fopen(filename, "r");

      //If file does not exist, let the user know, and exit the program
      if(fptr == NULL){

	printf("Cannot open file\n");
	exit(0);
	
      }

      //Reading the file line by line and adding
      c = fgetc(fptr);
      while(c != EOF){

	printf("%c", c);
	c = fgetc(fptr);
      }

      fclose(fptr);
      break;

    default:
      printf("Wrong choice, Please enter correct choice: ");
      break;
    }
  }
}

/*To insert a node in a tree */
void insert(){

  create();
  if(root == NULL)
    root = temp;
  else
    search(root);
}

/*To create a node */
void create(){

  char str[50];
  int i = 0;

  printf("Enter data of node to be inserted:\n");
  scanf("%s", str);
  temp = malloc(sizeof(struct node));
  
  //Copy one string to another
   while((temp->name[i] = str[i]) != '\0'){
    i++;
  }
 
  temp -> left = temp -> right = NULL;
}

/*Insert from a file
void insert1(char number){
  
  temp = (struct node *)malloc(1*sizeof(struct node));
  temp -> value = number;
  temp -> left = temp -> right = NULL;

  if(root == NULL)
    root = temp;
  else
    search(root);
}*/


/* Function to search the appropiate position to insert the new node */
void search(struct node *t){

  if((strcmp(temp->name, t->name) > 0) && (t->right != NULL))  //value more than root
    search(t -> right);
  else if((strcmp(temp->name, t->name) > 0) && (t->right == NULL))
    t->right = temp;
  else if((strcmp(temp->name, t->name) < 0) && (t->left != NULL))
    search(t->left);
  else if((strcmp(temp->name, t->name) < 0) && (t->left == NULL))
    t->left =temp;
}

/* Recursive function to perform inorder traversal of tree */
void inorder(struct node *t){

  if(root == NULL){

    printf("No elements in a tree to display");
    return;
  }

  if(t->left != NULL)
    inorder(t->left);

  printf("%s -> ", t->name);

  if(t->right != NULL)
    inorder(t->right);
}

/* Store the input of the user to a node
void copy(char *n[], char *s[]){

  int i;

  i = 0;
  while((n[i] = s[i]) != '\0'){
    i++;
    } 
   
    } */



