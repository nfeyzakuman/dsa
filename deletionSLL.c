#include <stdio.h>
#include <stdlib.h>

// deletion in singly linked list

typedef struct node
{
  int data;
  struct node *next;
} node;

node *createSLL(int);
void displayList(node *);
int countList(node *);
void *deletionSLL(node **,int);

int main()
{
  node *HEAD; 
  node **HEADP;
  int n,pos,choice=1;
  printf("How many values are you going to store: ");
  scanf("%d", &n);
  HEAD = createSLL(n);
  displayList(HEAD);
  HEADP = &HEAD;
  while(HEAD != NULL && choice==1)
  {
    printf("enter position for delete: ");
    scanf("%d", &pos);
    deletionSLL(HEADP,pos);
    displayList(HEAD);
    if(HEAD != NULL)
    {
    printf("would you like to continue deleting? 1 or 0: ");
    scanf("%d", &choice);
    }
    else{
      printf("You can't delete any more.\n");
      choice = 0;}
  }

  printf("Program ended.\n");
  return 0;
}

void *deletionSLL(node **headp,int pos)
{
    node *curr = *headp;

    if(*headp==NULL)
      printf("LIST IS EMPTY!\n");
    else if(pos==1)
    {
      *headp = curr->next;
      free(curr);
      curr = NULL;
    }  
    else
    {
      node *prev = *headp;
      while(pos != 1)
      {
        prev = curr;
        curr = curr->next;
        pos--;
      }
      prev->next = curr->next;
      free(curr);
      curr = NULL;
    }
    //also you can make deletion function like this
    //node *deletionSLL(node *,int pos) 
    //it returns head 
    //if you do it void it will enter loop
    //bc head address is always changing
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
  //int count = 0;
  node *temp = head;
  if (head == NULL)
  {
    printf("Your list is empty!\n");
  }
  else
  {
    printf("Your list is: ");
    while (temp->next != 0)
    {
      printf("%d -> ", temp->data);
      temp = temp->next;
      //count++;
    }
    printf("%d\n", temp->data);
    //count++;
  }
  // printf("\nThere are %d values in your list \n", count);
}

int countList(node *head)
{
  int count = 0;
  if (head == NULL)
  {
    printf("Your list is EMPTY!\n");
  }
  else
  {
    node *temp;
    temp = head;
    while (temp != 0)
    {
      temp = temp->next;
      count++;
    }
  }
  return count;
}
