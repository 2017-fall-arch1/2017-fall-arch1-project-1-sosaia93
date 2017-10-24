//Computer Achitecture 1 - CS 3432
//Project 1 - Personnel Management System
//By Sosa, Isaias
//Professor Eric Freudenthal
//Header file

#ifndef BSTree_H
#define BSTree_H

/* node */

struct node;

void insert();
void delete();
void deleteT(struct node *t);
void create();
void search(struct node *t);
void searchD(struct node *t, char s[]);
void inorder(struct node *t);
char* smallest(struct node *t);
char* largest(struct node *t);

#endif
