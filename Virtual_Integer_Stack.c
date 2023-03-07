#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10

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
int queue_full(Queue* q)
{
	if (q->rear == MAX - 1)
	{
		printf("queue full\n");
		return 1;
	}
	return 0;
}
void enqueu(Queue* q, int data)
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
	printf("front: %d, rear: %d\n", q->front, q->rear);
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

}
int main()
{
	Stack s;
	stackInit(&s);
	return 0;
}