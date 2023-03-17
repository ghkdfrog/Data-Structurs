#include<stdio.h>

#define MAX 6 // valid MAX will be 5, to distinguish full and empty state. one index must not fill.

int queue[MAX];
int rear = -1;
int front = -1;

int queue_full()
{
	if (front % MAX == (rear + 2) % MAX) // consider the full condition with remainder operator
		return 1;
	return 0; // return 0 if the above condition false.
}

int queue_empty()
{
	if (front == -1||(rear < front)) // front will greater than rear when queue empty.
		return 1;
	return 0; // return 0 if the above condition false.
}

void enqueue(int item)
{
	if (front == -1)
		front++;
	rear++;
	queue[rear % MAX] = item; // input data with remainder of rear.
	printf("front : %d rear : %d\n", front, rear);
}

int dequeue()
{
	printf("front : %d rear : %d\n", front, rear);
	int temp;
	temp = queue[front % MAX]; // return data with remainder of front.
	front++;
	return temp;
}

// helper function : print current queue.
void print_queue()
{
	if (queue_empty())
	{
		printf("queue underflow\n");
		return;
	}
	printf("queue : ");
	for (int i = front; i <= rear; i++) //repeat printf with the number between front and rear.
	{
		printf("[%d] ", queue[i%MAX]);
	}
	printf("\n");
}

// helper function : run a series of enqueue.
// int item[] : an array fron wich input values are taken
// int count : total numbers of elements to enqueue.
void run_enqueue(int item[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (queue_full())
		{
			printf("queue overflow\n");
			return;
		}
		enqueue(item[i]);
	}
}

// helper function: run a series of dequeue.
// input argument: int count <- total number of elements to dequeue.
void run_dequeue(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (queue_empty())
		{
			printf("queue underflow\n");
			return;
		}
		printf(" -> %d\n", dequeue());
	}
}

int main()
{
	int item[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	print_queue();
	run_enqueue(item, 6);
	print_queue();
	run_dequeue(2);
	print_queue();
	run_dequeue(4);
	run_enqueue(item, 2);
	print_queue();
	run_dequeue(3);
	return 0;
}