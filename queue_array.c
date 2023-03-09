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

void queue_init() //queue initialize
{
	queue.front = -1;
	queue.rear = -1;
}

int queue_full() //check queue full
{
	//if rear == MAX -1, return 1, else return 0.
	return (queue.rear == MAX - 1); 
}

int queue_empty() //check queue empty
{
	//if front == rear, return 1, else return 0.
	return (queue.front == queue.rear); 
}

void enqueue(int item)
{
	// ++rear and insert the item in queue[rear].
	queue.data[++queue.rear] = item; 
}

int dequeue()
{
	// ++front and return the item in queue[front].
	return queue.data[++queue.front]; 
}

void print_queue()
{
	printf(" queue : ");
	for (int i = queue.front + 1; i <= queue.rear; i++) 
	{
		printf("[%d] ", queue.data[i]);
	}
	printf("\n");
}

int main()
{
	queue_init();
	// print menu.
	printf("enqueue : 1\n");
	printf("dequeue : 2\n");
	printf("print queue : p\n");
	printf("quit program : q\n");

	// bool : stop loop.
	bool bol = true;
	// key : select menu.
	char key;
	// item :insert in queue.
	int item;
	while (bol) {
		printf("put key : ");
		scanf(" %c", &key);

		switch (key) {
		case '1':
			if (queue_full()) // check queue full.
			{
				printf("	queue full\n");
				break;
			}
			while (1)
			{
				while (getchar() != '\n');
				printf("	item to enqueue : ");
				scanf(" %d", &item);
				if (item < 0) // check item is bigger than 0 and not number.
				{
					printf("	item is negetive or not number\n");
					continue;
				}
				enqueue(item);
				break;
			}
			break;
		case '2':
			if (queue_empty()) // check queue empty
			{
				printf("	queue empty\n");
				break;
			}
			printf("	dequeue data: %d\n", dequeue());
			break;
		case 'q':
			// stop loop
			bol = false;
			break;
		case 'p':
			if (queue_empty()) // check queue empty.
			{
				printf("	queue empty\n");
				break;
			}
			print_queue();
			break;
		default:
			// check key is suitable.
			printf("	wrong key\n");
			break;
		}
	}
	return 0;
}