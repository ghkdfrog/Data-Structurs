#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
int front = -1;
int rear = -1;
int queueArr[MAX];

void enqueue(int item)
{
	if (queue_full())
	{
		printf("queue full!\n");
		return;
	}
	rear++;
	queueArr[rear] = item;
	return;
}
int dequeue()
{
	if (queue_empty())
	{
		printf("queue empty!\n");
		return;
	}
	int dequeue_item;
	front++;
	dequeue_item = queueArr[front];
	return dequeue_item;
}
int queue_full()
{
	int is_queue_full = 0;
	if (rear == MAX-1)
	{
		is_queue_full = 1;
	}
	return is_queue_full;
}
int queue_empty()
{
	int is_queue_empty = 0;
	if (front == rear)
	{
		is_queue_empty = 1;
	}
	
	return is_queue_empty;
}
int queue_array()
{
	dequeue();

	enqueue(1);
	for (int i = front + 1; i <= rear; i++)
	{
		printf("%d ", queueArr[i]);
	}
	printf("\n");
	dequeue();
	dequeue();
	for (int i = 2; i <= 11 ; i++)
	{
		enqueue(i);
	}
	for (int i = front + 1; i <= rear; i++)
	{
		printf("%d ", queueArr[i]);
	}
	printf("\n");
	dequeue();
	for (int i = front + 1; i <= rear; i++)
	{
		printf("%d ", queueArr[i]);
	}
	printf("\n");

	return 0;
}