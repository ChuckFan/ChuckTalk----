#include<stdio.h>
#include<string.h>
typedef struct Node
{
	int value;
	struct Node*next;
}Node;

void SListInit(Node *head)
{
	head = NULL;
}