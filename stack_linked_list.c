#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

struct Node* top = NULL;

int stack_empty()
{
	if (top == NULL)
		return 1;
	return 0; // return 0 only if the above condition is false
}

int stack_full()
{
	int i = 0;
	struct Node* ptr = top;
	if (ptr == NULL)
		return 0; // if top == NULL, stack always empty
	while (ptr->next != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	if (i >= MAX-1)
		return 1;
	return 0; // return 0 if the above condition is false
}

void push(int data)
{
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = top;
	top = newNode; // top is the node that pushed last.
}

int pop()
{
	int temp = top->data;
	Node* del = top;
	top = top->next;
	free(del);
	return temp; // remove the first node and change top.
}

// helper function : print the current stack
void print_stack()
{
	if (stack_empty())
	{
		printf("stack empty\n");
		return;
	}
	struct Node* ptr = top;
	while (ptr->next != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}

// helper function: run a series of pushes
// input arguments: int datas[] <- an array from which input values are taken
// input arguments: int count <- total number of elements to push
void run_push(int datas[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (stack_full())
		{
			printf("stack full\n");
			return;
		}
		push(datas[i]);
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
		printf("pop-> %d\n", pop());
	}
}

int main()
{
	int items[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	print_stack();
	run_push(items, 5);
	run_pop(3);
	run_push(items, 10);
	run_pop(11);;
	return 0;
}