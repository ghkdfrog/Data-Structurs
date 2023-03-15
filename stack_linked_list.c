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

Node* head = NULL;

int stack_full()
{
	if (top == MAX - 1)
	{
		return 1;
	}
	return 0; // return 0 if the above condition is false
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
	return 0; //return 0only if the above condition is false
}

int pop()
{
	top--;
	Node* prev, * cur;
	cur = prev = head;
	int pop_data;
	if (cur->next == NULL)
	{
		head = NULL;
		pop_data = cur->data;
	}
	else
	{
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		pop_data = cur->data;
	}
	return pop_data;
}


// helper function: run a series of pushes

// input arguments: int item[] <- an array from which input values are taken

// input arguments: int count <- total number of elements to push
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

// helper function: run a series of pops

// input argument: int count <- total number of elements to pop
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

// helper function : print the current stack
void printStack() {
	Node* ptr;
	ptr = head;
	if (stack_empty())
	{
		printf("stack empty\n");
		return;
	}
	printf("stack : ");
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	int items[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };
	run_push(items, 5);
	run_pop(3);
	run_push(items, 10);
	run_pop(11);
	
	return 0;
}