#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

typedef struct
{
	int front;
	int rear;
	int data[MAX];
}Queue;

Queue queue;

void queue_init()
{
	queue.front = 0;
	queue.rear = 0;
}

void enqueue(int item)
{
	queue.data[(queue.rear++)%MAX] = item;
}

int dequeue()
{
	return queue.data[(queue.front++) & MAX];
}

int queue_full()
{
	return (queue.rear + 1) % MAX == queue.front;
}

int queue_empty()
{
	return queue.rear == queue.front;
}

void print_queue()
{
	printf(" queue : ");
	for (int i = queue.front; i < queue.rear; i++)
	{
		printf("[%d] ", queue.data[i%MAX]);
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
			if (queue_full())
			{
				printf("	queue full\n");
				break;
			}
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
			if (queue_empty())
			{
				printf("	queue empty\n");
				break;
			}
			printf("	dequeue data: %d\n", dequeue());
			break;
		case 'q':
			bol = false;
			break;
		case 'p':
			if (queue_empty())
			{
				printf("	queue empty\n");
				break;
			}
			print_queue();
			break;
		default:
			printf("	wrong key\n");
			break;
		}
	}
	return 0;
}