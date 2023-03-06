#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int top = -1;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* head;

void init()
{
	head = NULL;
}

void printList() {
	Node* ptr;
	if (head == NULL)
	{
		printf("list empty\n");
		return;
	}
	for (ptr = head; ptr->next; ptr = ptr->next)
	{
		printf("%d->", ptr->data);
	}
	printf("%d\n", ptr->data);
}

int stack_full()
{
	if (top == MAX - 1)
	{
		return 1;
	}
	return 0;
}

void push(int data)
{
	if (stack_full())
	{
		printf("stack full\n");
		return;
	}
	top++;
	Node* ptr;
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		ptr = head;
		while(ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
}

int stack_empty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}

int pop()
{
	Node *prev, *cur;
	cur = prev = head;
	if (stack_empty())
	{
		printf("stack empty\n");
		return -1;
	}
	top--;
	if (cur->next == NULL)
	{
		head = NULL;
		return cur->data;
	}
	else 
	{
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		return cur->data;
	}
}

int main()
{
	init();
	pop();
	push(10);
	printList();
	printf("pop: %d\n", pop());
	printList();
	for (int i = 1; i < 12; i++)
	{
		push(i * 10);
	}
	printList();
	printf("pop: %d\n", pop());
	printList();

	return 0;
}