#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
  	struct node *next;
}*head=NULL;


void display(struct node *p)
{
  	if(head==NULL)
  	{
    		printf("Empty List !!");
  	}
  	else
  	{
    		while(p!=NULL)
    		{
      			printf("%d ",p->data);
      			p=p->next;
    		}
  	}
}


void create(int n)
{
	int m=0;
  struct node *t;
  struct node *last;
  while(n>0)
  {
 
    if(head==NULL)
    {
      t = (struct node *)malloc(sizeof(struct node));
      printf("Enter node data : ");
      scanf("%d",&m);
      t->data=m;
      t->next=NULL;
      head=t;
      last=t;
    }
    else
    {
      t = (struct node *)malloc(sizeof(struct node));
      printf("Enter node data : ");
      scanf("%d",&m);
      t->data=m;
      t->next=NULL;
      last->next=t;
      last=t;
    }
    n--;
  }
}
int main(int argc , char* argv[])
{
  create(5);
  //printf("Hello");
  display(head);
  return 0;
}
