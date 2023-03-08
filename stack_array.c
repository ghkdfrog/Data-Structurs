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

void stack_init()
{
	stack.top = -1;
}

int stack_empty()
{
	if (stack.top == -1)
	{
		return 1;
	}
	return 0;
}

int stack_full()
{
	if (stack.top == MAX - 1)
	{
		return 1;
	}
	return 0;
}

void push(int item)
{
	if (stack_full())
	{
		printf("	stack full\n");
		return;
	}
	stack.top++;
	stack.data[stack.top] = item;
}

int pop()
{
	if (stack_empty())
	{
		printf("	stack empty\n");
		return -1;
	}
	int pop_item;
	pop_item = stack.data[stack.top];
	stack.top--;
	return pop_item;
}

void stack_print()
{
	if (stack_empty())
	{
		printf("	stack empty\n");
		return;
	}
	for (int i = 0; i <= stack.top; i++)
	{
		printf("[%d] ", stack.data[i]);
	}
	printf("\n");
}

int main()
{
	stack_init();
	printf("push : 1\n");
	printf("pop : 2\n");
	printf("print stack : p\n");
	printf("quit program : q\n");
	
	bool bol = true;

	char key;
	int item;
	while (bol) {
		printf("put key : ");
		scanf(" %c", &key);

		switch (key) {
		case '1':
			while (1)
			{
				printf("	item to push : ");
				scanf(" %d", &item);
				if (item < 0)
				{
					printf("	item is bigger than 0\n");
					continue;
				}
				push(item);
				break;
			}
			break;
		case '2':
			printf("	pop data: %d\n", pop());
			break;
		case 'q':
			bol = false;
			break;
		case 'p':
			stack_print();
			break;
		default:
			printf("	wrong key\n");
			break;
		}
	}
	return 0;
}