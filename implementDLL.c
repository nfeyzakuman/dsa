#include<stdio.h>
#include<stdlib.h>
//implementation of Doubly Linked List

typedef struct node{
  int data;
  struct node* prev;
  struct node* next;
}node;

node * implementDLL();
void displayList(node *);

void main(){
  node *HEAD;
  HEAD = implementDLL();
  displayList(HEAD);
}

node * implementDLL(){
  node *head;
  
  return head;
}

void displayList(node *head){
  node *temp = head;
  while(temp->next != 0){
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}
