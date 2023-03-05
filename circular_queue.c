#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
int queue[MAX];
int front = 0;
int rear = 0;

void insert(int item)
{
	if ((rear + 1) % MAX == front)
	{
		printf("queue full\n");
		return ;
	}
	rear++;
	queue[rear % MAX] = item;

	return;
}

int delete()
{
	if (front == rear)
	{
		printf("queue empty\n");
		return 0;
	}
	front++;
	return queue[front % MAX];
}

int main()
{
	int delete_num;
	delete();
	insert(1);
	printf("delete: %d\n", delete());
	for (int i = 1; i < 6; i++)
	{
		insert(i);
	}
	for (int i = 0; i < 5; i++)
	{
		delete();
	}
	return 0;
}