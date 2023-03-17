#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct _Node {
    int data;          
    struct _Node* next;   
}Node;

Node* front = NULL;
Node* rear = NULL;

int queue_full()
{
    if (queue_empty())
        return 0;
    Node* ptr = front;
    int i = 0;
    while (ptr != rear)
    {
        i++;
        ptr = ptr->next;
    }
    if (i >= MAX-1)
        return 1;
    return 0;
}

int queue_empty()
{
    if (front == NULL)
        return 1;
    return 0;
}

void enqueue(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL)
    {
        rear = newNode;
        front = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue()
{
    Node* del;
    int temp = front->data;
    del = front;
    front = front->next;
    free(del);
    return temp;
}

//helper function: print the current queue
void print_queue()
{
    if (queue_empty())
    {
        printf("queue empty\n");
        return;
    }
    printf("queue : ");
    for (Node* ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

//helper function : run a series of enqueues
//int item[] : an array from wich input values are taken
//int count : total number of elemets to enqueue
void run_enqueue(int item[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (queue_full())
        {
            printf("queue full\n");
            return;
        }
        enqueue(item[i]);
    }
}

//helper function : run a series of dequeues
//int count : total number of elements to dequeue.
void run_dequeue(int count)
{
    for (int i = 0; i < count; i++)
    {
        if (queue_empty())
        {
            printf("queue empty\n");
            return;
        }
        printf(" -> %d\n", dequeue());
    }
}

int main()
{
    int items[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };
    print_queue();
    run_enqueue(items, 5);
    run_dequeue(3);
    run_enqueue(items, 10);
    run_dequeue(11);
    run_enqueue(items, 3);

    return 0;
}