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
	return (stack.top == -1);
}

int stack_full()
{
	return (stack.top == MAX - 1);
}

void push(int item)
{
	if (stack_full())
	{
		printf("	stack full\n");
		return;
	}
	stack.data[++stack.top] = item;
}

int pop()
{
	if (stack_empty())
	{
		printf("	stack empty\n");
		return -1;
	}
	return stack.data[stack.top--];
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
				while (getchar() != '\n');
				printf("	item to push : ");
				scanf(" %d", &item);
				if (item < 0)
				{
					printf("	item is negetive or not number\n");
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

	int test;
	scanf("%d", &test);
	if (!test)
	{
		printf("not num");
	}
	else
	{
		printf("%d", test);
	}

	return 0;
}