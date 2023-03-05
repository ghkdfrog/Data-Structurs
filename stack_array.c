#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX 10
int top = -1;
int stackArr[MAX];
int stack_full()
{
	int is_stack_full = 0;
	if (top == MAX - 1)
	{
		is_stack_full = 1;
	}
	return is_stack_full;
}
int stack_empty()
{
	int is_stack_empty = 0;
	if (top == -1)
	{
		is_stack_empty = 1;
	}
	return is_stack_empty;
}
void push(int item)
{
	top++;
	stackArr[top] = item;
	return;
}
int pop()
{
	int pop_num;
	pop_num = stackArr[top];
	top--;
	return pop_num;
}
int stack_array()
{
	int pop_num;
	if (stack_empty())
	{
		printf("stack empty!\n");
	}
	else
	{
		pop_num = pop();
		printf("pop num: %d\n", pop_num);
	}

	for (int i = 1; i <= 12; i++)
	{
		if (stack_full())
		{
			printf("stack full!\n");
			continue;
		}
		push(i);
	}
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stackArr[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		if (stack_empty())
		{
			printf("stack empty!\n");
		}
		else
		{
			pop_num = pop();
			printf("pop num: %d\n", pop_num);
		}
	}
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stackArr[i]);
	}
	printf("\n");
	int get_num;
	if (stack_full())
	{
		printf("stack full!\n");
	}
	else
	{
		printf("Enter a number to push: ");
		if (scanf_s("%d", &get_num) != 1) // scanf 대신 scanf_s 사용
		{
			printf("Invalid input!\n");
			return 1;
		}
		push(get_num);
	}

	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stackArr[i]);
	}
	printf("\n");
	return 0;
}