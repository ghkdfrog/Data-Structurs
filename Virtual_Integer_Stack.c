#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 4

typedef struct 
{
	int front;
	int rear;
	int data[MAX];
}Queue;
void queueInit(Queue* q) 
{	q->front = -1;
	q->rear = -1;
}
int queue_empty(Queue* q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	return 0;
}
int queue_full(Queue* q)
{
	if (q->rear == MAX - 1)
	{
		return 1;
	}
	return 0;
}
void enqueue(Queue* q, int data)
{
	q->rear++;
	q->data[q->rear] = data;
}
int dequeue(Queue* q)
{
	q->front++;
	return q->data[q->front];
}
void printQueue(Queue* q)
{
	for (int i = q->front + 1; i <= q->rear; i++)
	{
		printf("[ %d ] ", q->data[i]);
	}
	printf("\n");
}
typedef struct
{
	Queue mainQueue;
	Queue subQueue;
}Stack;
void stackInit(Stack* s)
{
	queueInit(&(s->mainQueue));
	queueInit(&(s->subQueue));
}
int stack_full(Stack* s)
{
	if (queue_full(&(s->mainQueue)))
	{
		printf("stack full\n");
		return 1;
	}
	return 0;
}
void push(Stack* s, int data)
{
	if (stack_full(s))
	{
		return;
	}
	enqueue(&(s->mainQueue), data);
}
int stack_empty(Stack* s)
{
	if (queue_empty(&(s->mainQueue)))
	{
		printf("stack empty\n");
		return 1;
	}
	return 0;
}
int pop(Stack* s)
{
	if (stack_empty(s))
	{
		return -1;
	}
	int result;
	while ((s->mainQueue).front + 1 < (s->mainQueue).rear)
	{
		enqueue(&(s->subQueue), dequeue(&(s->mainQueue)));
	}
	result = dequeue(&(s->mainQueue));
	queueInit(&(s->mainQueue));
	int res2;
	while (!queue_empty(&(s->subQueue)))
	{	
		enqueue(&(s->mainQueue), dequeue(&(s->subQueue)));
	}
	queueInit(&(s->subQueue));
	return result;
}
void printStack(Stack* s)
{
	printQueue(&(s->mainQueue));
}
int main()
{
	Stack s;
	stackInit(&s);
	pop(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	push(&s, 50);
	printStack(&s);
	printf("pop: %d\n", pop(&s));
	printStack(&s);
	printf("pop: %d\n", pop(&s));
	printStack(&s);
	push(&s, 50);
	printStack(&s);
	printf("pop: %d\n", pop(&s));
	printStack(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	return 0;
}