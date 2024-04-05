#include <stdio.h>
#include <stdlib.h>

// implementation of singly linked list

typedef struct node
{
  int data;
  struct node *next;
}node;

node * createSinglyLinkedList();

void displayList(node *);

void main()
{
  node* HEAD=0;
  HEAD=createSinglyLinkedList();
  displayList(HEAD);
}

node * createSinglyLinkedList()
{
  node *head, *newNode, *temp;
  head=0;
  int c, choice = 1;
  while (choice == 1)
  {
    newNode = (node *)malloc(sizeof(node));
    printf("enter the value of node:  ");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (head == 0)
      head = temp = newNode;
    else
    {
      temp->next = newNode;
      temp = newNode;
    }

    printf("enter 1 for continue, 0 for end (1,0):  ");
    scanf("%d", &c);
    if (c == 1 || c == 0)
      choice = c;
    else
    {
      choice = 1;
    }
  }
  return head;
}

void displayList(node *head)
{
  int count = 0;
  node *temp = head;
  while (temp->next != 0)
  {
    printf("%d  ->  ", temp->data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}