#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct _Node {
    int data;          
    struct _Node* next;   
}Node;

Node* head = NULL;
int front = -1;
int rear = -1;

int queue_full()
{
    if (rear >= MAX - 1)
    {
        return 1;
    }
    return 0; //return 0 only if the above condition is false
}
void enqueue(int data)
{
    rear++;
    if (front <= -1) // increase front only initially
        front++;
    Node* ptr = head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
int queue_empty()
{
    if (front == -1 || front>rear) // front can not be greater than rear
    {
        return 1;
    }
    return 0; // return 0 only if the above condition is false
}
int dequeue()
{
    front++;
    int dequeue_data;
    Node* cur = head;
    dequeue_data = cur->data;
    head = cur->next;
    free(cur);
    return dequeue_data;
}

//helper function: print the current queue
void printQueue()
{
    if (queue_empty())
    {
        printf("queue empty\n");
        return;
    }
    Node* ptr;
    ptr = head;
    printf("queue : ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
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
        printf("-> %d\n", dequeue());
    }
}

int main()
{
    int items[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };
    printQueue();
    run_enqueue(items, 5);
    run_dequeue(3);
    run_enqueue(items, 10);
    run_dequeue(11);
    run_enqueue(items, 3);

    return 0;
}