#include<stdio.h>
#include<stdlib.h>
// reversing a singly linked list
typedef struct node
{
  int data;
  struct node *next;
}node;

node * createSLL();
node * reverseSLL(node *);

void displayList(node *);

void main()
{
  node* HEAD;
  HEAD=createSLL();
  displayList(HEAD);
  HEAD = reverseSLL(HEAD);
  displayList(HEAD);
}

node * reverseSLL(node * head)
{
  node *temp, *prev, *next;
  prev = 0;
  temp = next = head;
  while(temp != 0)
  {
    next = next->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  head = prev;
  return head;
}

node * createSLL()
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
  printf("%d\n", temp->data);
}