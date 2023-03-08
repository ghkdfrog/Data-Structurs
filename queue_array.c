#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
	int front;
	int rear;
	int data[MAX];
}Queue;

Queue queue;

void queue_init()
{
	queue.front = -1;
	queue.rear = -1;
}

int queue_full()
{
	return (queue.rear == MAX - 1);
}

int queue_empty()
{
	return (queue.front == queue.rear);
}

void enqueue(int item)
{
	if (queue_full())
	{
		printf("	queue full\n");
		return;
	}
	queue.data[++queue.rear] = item;
}

int dequeue()
{
	if (queue_empty())
	{
		printf("	queue empty\n");
		return -1;
	}
	return queue.data[++queue.front];
}

void queue_print()
{
	if (queue_empty())
	{
		printf("	queue empty\n");
		return;
	}
	for (int i = queue.front + 1; i <= queue.rear; i++)
	{
		printf("[%d] ", queue.data[i]);
	}
	printf("\n");
}

int main()
{
	queue_init();
	printf("enqueue : 1\n");
	printf("dequeue : 2\n");
	printf("print queue : p\n");
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
				printf("	item to enqueue : ");
				scanf(" %d", &item);
				if (item < 0)
				{
					printf("	item is bigger than 0\n");
					continue;
				}
				enqueue(item);
				break;
			}
			break;
		case '2':
			printf("	dequeue data: %d\n", dequeue());
			break;
		case 'q':
			bol = false;
			break;
		case 'p':
			queue_print();
			break;
		default:
			printf("	wrong key\n");
			break;
		}
	}
	return 0;
}