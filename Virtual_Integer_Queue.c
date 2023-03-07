#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX 4

typedef struct {
	int top;
	int data[MAX];
}stack;
typedef struct {
	stack inBox;
	stack outBox;
}queue;

void stackInit(stack* s)
{
	s->top = -1;
}

void queueInit(queue* q)
{
	stackInit(&(q->inBox));
	stackInit(&(q->outBox));
}

int stack_full(stack* s)
{
	if (s->top == MAX)
	{
		return 1;
	}
	return 0;
}

int stack_empty(stack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(stack* s, int data)
{
	s->top++;
	s->data[s->top] = data;
}

int pop(stack* s)
{
	int pop_num;
	pop_num = s->data[s->top];
	s->top--;
	return pop_num;
}

int main()
{
	return 0;
}