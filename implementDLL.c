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
  node *head = 0, *newNode, *temp;
  int data, choice = 1;
  while(choice){
    printf("enter data: ");
    scanf("%d", &data);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = 0;      
    newNode->prev = 0;
    if(head == 0){
      head = temp = newNode;
      }
    else{
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }  
    printf("enter choice 1 or 0: ");
    scanf("%d", &choice);
  }

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
