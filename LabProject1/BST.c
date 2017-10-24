//Computer Architecture 1 - CS 3432
//Sosa, Isaias
//Project 1 - Personnel Management System
//Eric Freudenthal


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

int flag = 1;


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

//To delete a node
void delete(){

  char str[50];   //Store element to be removed

  if(root == NULL){
    
    printf("No elements in the tree to be deleted");
    return;
  }

  printf("Enter the data to be deleted: ");
  scanf("%s", str);

  t1 = root;
  t2 = root;

  searchD(root, str);
  
}

//Search for the node to be deleted
void searchD(struct node *t, char s[]){

  if(strcmp(s, t->name) > 0){

    t1 = t;
    searchD(t->right, s);
  }

  else if(strcmp(s, t->name) < 0){

    t1 = t;
    searchD(t->right, s);
  }

  else if(strcmp(s, t->name) == 0){

    deleteT(t);
  }
}

// Delete the found node, and rearrange BST
void deleteT(struct node *t){

  char *k = (char *)malloc(sizeof(char) * 50);
  int i = 0;

  //Deleting leaf node
  if((t->left == NULL) && (t->right == NULL)){

    if(t1->left == t){

      t1->left = NULL;
    }
    else{
      t->right = NULL;
    }

    t = NULL;
    free(t);
    return;
    
  }

  //To delete a node that has a left child node
  else if(t->right == NULL){

    if(t1 == t){

      root = t->left;
      t1 = root;
      
    }
    else if(t1->left == t){

      t1->left = t->left;
      
    }
    else{

      t1->right = t->left;
    }

    t= NULL;
    free(t);
    return;

  }

  //To delete a node that has a right child node
  else if(t->left == NULL){

    if(t1 == t){

      root = t->right;
      t1 = root;
    }
    else if(t1->right == t){
      t1->right = t-> right;
    }
    else
      t1->left = t->right;

    t == NULL;
    free(t);
    return;
  }

  //To delete a node having two child nodes
  else if((t->left != NULL) && (t->right != NULL)){
  
    t2 =root;
    
    if(t->right != NULL){

      k = smallest(t->right);
      flag = 1;
      
    }
    else{

      k = largest(t->left);
      flag = 2;
    }

    searchD(root, k);

    //Copies the elements of one array to the other
    while((temp->name[i] != '\0') && (k[i] != '\0')){
      temp->name[i] = k[i];
      i++;
    }

   }
    
  }

//To find the smallest element in the right subtree
char*  smallest(struct node *t){

  t2 = t;

  if(t->left != NULL){

    t2 = t;
    return(smallest(t->left));
  }
  else{

    return (t->name);
  }
     
}

//To find the largest element
char* largest(struct node *t){

  if(t->right != NULL){

    t2 = t;
    return(largest(t->right));

  }

  else{

    return(t->name);

  }
  
}

