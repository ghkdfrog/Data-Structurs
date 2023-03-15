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
		while (ptr->next)
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
	top--;
	Node* prev, * cur;
	cur = prev = head;
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

void run_push(int item[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (stack_full())
		{
			printf("stack full\n");
			return;
		}
		push(item[i]);
	}
}

void run_pop(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (stack_empty())
		{
			printf("stack empty\n");
			return;
		}
		printf("-> %d\n", pop());
	}
}

void printStack() {
	Node* ptr;
	if (stack_empty())
	{
		printf("stack empty\n");
		return;
	}
	for (ptr = head; ptr->next; ptr = ptr->next)
	{
		printf("%d ", ptr->data);
	}
	printf("%d\n", ptr->data);
}

int main()
{
	int items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	init();
	run_push(items, 5);
	printStack();
	run_pop(3);
	run_push(items, 11);
	printStack();
	run_pop(11);

	return 0;
}