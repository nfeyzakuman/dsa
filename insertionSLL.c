#include <stdio.h>
#include <stdlib.h>

//insertion in singly linked list

typedef struct node
{
  int data;
  struct node *next;
} node;

node *createSLL(int);
void displayList(node *);
node *insertBeg(node *);
node *insertEnd(node *);
node *insertByPos(node *);
int countList(node *);

void main()
{
  node *HEAD;
  int n, choice = 1;
  printf("How many values are you going to store: ");
  scanf("%d", &n);
  HEAD = createSLL(n);
  displayList(HEAD);
  while (choice == 1)
  {
    HEAD = insertByPos(HEAD);
    printf("would you like to continue inserting? 1 or 0: ");
    scanf("%d", &choice);
  }
  printf("Thats it! Here is your linked list: \n");
  displayList(HEAD);
}

node *createSLL(int n)
{
  node *head, *temp, *newNode;
  int m;
  for (int i = 0; i < n; i++)
  {
    printf("enter the value: ");
    scanf("%d", &m);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = m;
    newNode->next = 0;
    if (i == 0)
      head = temp = newNode;
    else
      temp->next = newNode;
    temp = newNode;
  }
  return head;
}

void displayList(node *head)
{
  int count = 0;
  node *temp = head;
  while (temp->next != 0)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
    count++;
  }
  printf("%d", temp->data);
  count++;
  printf("\nThere are %d values in your list \n", count);
}

int countList(node *head)
{
  int count = 0;
  node *temp;
  temp = head;
  while (temp != 0)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

node *insertBeg(node *head)
{
  int m;
  node *newNode;
  printf("enter the value that you want to insert to the beginning: ");
  scanf("%d", &m);
  newNode = (node *)malloc(sizeof(node));
  newNode->data = m;
  newNode->next = head;
  head = newNode;
  displayList(head);
  return head;
}

node *insertEnd(node *head)
{
  int m;
  node *newNode, *temp = head;
  printf("enter the value that you want to insert to the end: ");
  scanf("%d", &m);
  newNode = (node *)malloc(sizeof(node));
  newNode->data = m;
  newNode->next = 0;
  while (temp->next != 0)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  displayList(head);
  return head;
}

node *insertByPos(node *head)
{
  int n = countList(head);
  int m, pos;
  node *newNode, *temp = head;
  printf("Which position would you like to insert: ");
  scanf("%d", &pos);
  if (pos == 1)
  {
    head = insertBeg(head);
  }
  else if (pos == n + 1)
  {
    head = insertEnd(head);
  }
  else if (pos > 1 && pos <= n)
  {
    int i;
    printf("enter the value that you want to insert: ");
    scanf("%d", &m);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = m;
    newNode->next = 0;
    for (i = 2; i < pos; i++)
      temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    displayList(head);
  }
  else
  {
    printf("please enter valid value! \n");
    head = insertByPos(head);
  }
  return head;
}