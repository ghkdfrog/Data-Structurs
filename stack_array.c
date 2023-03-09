#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
	int top;
	int data[MAX];
}Stack;

Stack stack;

void stack_init() //stack initialize
{
	stack.top = -1;
}

int stack_empty() //check stack empty
{
	//if top == -1, return 1, else return 0.
	return (stack.top == -1);
}

int stack_full() //check stack full
{
	//if tio == MAX-1, return 1, else return 0.
	return (stack.top == MAX - 1);
}

void push(int item)
{
	//++top and insert the item in stack[top].
	stack.data[++stack.top] = item;
}

int pop()
{
	// return stack[top] and top--.
	return stack.data[stack.top--];
}

void stack_print()
{
	printf(" stack : ");
	for (int i = 0; i <= stack.top; i++)
	{
		printf("[%d] ", stack.data[i]);
	}
	printf("\n");
}

int main()
{
	stack_init();
	//print menu.
	printf("push : 1\n");
	printf("pop : 2\n");
	printf("print stack : p\n");
	printf("quit program : q\n");
	
	// bool : stop loop
	bool bol = true;
	// key : select menu
	char key;
	// item : insert in stack
	int item;
	while (bol) {
		printf("put key : ");
		scanf(" %c", &key);
		switch (key) {
		case '1':
			if (stack_full()) // check stack full
			{
				printf("stack full\n");
				break;
			}
			while (1)
			{
				while (getchar() != '\n');
				printf("	item to push : ");
				scanf(" %d", &item);
				if (item < 0) // check item is bigger than 0 and not number.
				{
					printf("	item is negetive or not number\n");
					continue;
				}
				push(item);
				break;
			}
			break;
		case '2':
			if (stack_empty()) //check stack empty
			{
				printf("	stack empty\n");
				break;
			}
			printf("	pop data: %d\n", pop());
			break;
		case 'q':
			// stop loop
			bol = false;
			break;
		case 'p':
			if (stack_empty()) // check stack empty
			{
				printf("	stack empty\n");
				break;
			}
			stack_print();
			break;
		default:
			// check key is suitable
			printf("	wrong key\n");
			break;
		}
	}
	return 0;
}