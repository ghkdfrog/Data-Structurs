#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct _Node {
    int data;            /* 저장할 데이터 */
    struct _Node* next;    /* 다음 노드를 가리킬 포인터*/
}Node;
Node* head;

int front = -1;
int rear = -1;

void init()
{
    head = NULL;
}
int queue_full()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int data)
{
    if (queue_full())
    {
        printf("queue full\n");
        return;
    }
    rear++;
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
    if (front == rear)
    {
        return 1;
    }
    return 0;
}
int dequeue()
{
    if (queue_empty())
    {
        printf("queue empty\n");
        return;
    }
    front++;
    int dequeue_data;
    Node* cur = head;
    dequeue_data = cur->data;
    head = cur->next;
    cur->next = NULL;
    free(cur);
    return dequeue_data;
}
void printList()
{
    Node* ptr;
    for (ptr = head; ptr->next; ptr = ptr->next)
    {
        printf("%d->", ptr->data);
    }
    printf("%d\n", ptr->data);
}
int main()
{
    init();
    enqueue(100);
    printList();
    printf("dequeue: %d\n", dequeue());
    dequeue();
    for (int i = 1; i < 12; i++)
    {
        enqueue(i * 10);
    }
    printList();
    return 0;
}