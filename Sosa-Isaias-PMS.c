//Sosa, Isaias
//CS 3432 Computer Architecture 1
//Professor Eric Freudenthal
//Project 1 - Personnel-Management-System


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


// Node

struct node{

  char *ename;
  struct node *left, *right;
}*root;

//Find

void find(char *str, struct node **p, struct node **l){

  struct node *ptr, *ptrsave;

  if(root = NULL){
      *l = NULL;
      *p = NULL;
      return;
  }
  if(!(strcmp(str, root -> ename))){
    *l = root;
    *p = NULL;
    return;
  }
  
  if(strcmp(str, root -> ename)<0)
    ptr = root -> left;
  else
    ptr = root -> right;

  ptrsave = root;

  while(ptr != NULL){

    if(!(strcmp(str, ptr -> ename))){
      *l = ptr;
      *p =ptrsave;
      return;
    }

    ptrsave = ptr;
    
    if(strcmp(str, ptr -> ename)<0)
       ptr = ptr -> left;
    else
       ptr = ptr -> right;
  
  }

  *l = NULL;
  *p = ptrsave;

}



// Insert

void insert(char *str){

  struct node *parent, *location, *temp;

  find(str, &parent, &location);

  temp = malloc(sizeof(struct node));
  temp -> ename = strdup(str);
  temp -> left = NULL;
  temp -> right = NULL;

  if(parent == NULL){
    root = temp;
  }
  else if(strcmp(str, parent -> ename) < 0){
    parent -> left = temp;
  }
  else{
    parent -> right = temp;
  }

}

// Display

void display(struct node *ptr){

   if(root = NULL){
     printf("Tree is empty");
     return;
   }

   if(ptr != NULL){
     display(ptr -> left);
     printf("%s -> ", ptr -> ename);
     display(ptr -> right);
    }

}

// Main

int main(){

   root = NULL;
   char str[20];
   char a;

printf("Please enter a name: ");
scanf(str);
insert(str);
printf("Would you like to enter another name (y/n):  ");

 while((a = getchar()) == 'y'){

  fflush(stdin);
  printf("Please enter a name: ");
  scanf(str);
  insert(str);

  printf("Would you like to enter another name (y/n):  ");
  scanf("%c", &a);
  }

//Display tree

  display(root);

return 0;

}
