#include<iostream>
using namespace std;
struct queue
{
    
    int capacity;
    int front;
    int rear;
    int *arr;
};

struct  queue* create_queue(int capacity)
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->arr =(int *)malloc(sizeof(int)*capacity);
    return q;
}

// push or enqueue operation
void push(struct queue* q,int data)
{
    if((q->front == 0 && q->rear == q->capacity -1) || (q->rear +1 == q->front))
    {
        cout<<"no space availabe";
    }
    else if(q->front == -1)
    {
        q->front =0;
        q->rear  =0;
        q->arr[q->rear] = data;
    }
    else if((q->rear == q->capacity -1) && (q->front != 0))
    {
        q->rear =0;
        q->arr[q->rear] = data;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}


//pop or dequeue operation
void pop(struct queue *q)
{
    //if there is no element
    if(q->front == -1 || q->rear == -1)
    {
        cout<<"can not from pop queue";
    }
    else if(q->front == 0 && q->rear == 0) // if there is only single element in the queue
    {
        q->front = -1;
        q->rear  = -1;
    }
    else if(q->front  == q->capacity -1)//if front reaches at the end
    {
            q->front = 0;
    }
    else//normal condition
    {
        q->front++;
    }
}

int main()
{
    struct queue *q;
    q = create_queue(10);
    // push(q,10);
    pop(q);
}