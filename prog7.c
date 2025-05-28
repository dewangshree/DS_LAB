#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 3
struct queue {
    int arr[max];
    int front,rear;
};
int isfull(struct queue *q){
    return( q->rear == max-1) ;
}
int isempty(struct queue *q){
    return (q->front == -1);
}
void enqueue(struct queue *q,int data){
    if(isfull(q)){
        printf("Queue is full");
    }else{

        if(isempty(q)){
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=data;
    }
}
void dequeue(struct queue *q){
    if(isempty(q)){
        printf("queue is empty");

    }
    else{
        int data=q->arr[q->front];
        if(q->front==q->rear){
            q->front=-1;
            q->rear=-1;
        }
        else{
            q->front++;
        }
        printf("%d element is dequed ",data);
    }
}
void display(struct queue *q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}
void main(){
    struct queue q;
    q.front=-1;
    q.rear =-1;
    int choice, data;
    while(choice!=4){
        printf("enter 1 for insert \n 2 for deque \n 3 for display \n 4 for exit ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the element to insert");
                    scanf("%d",&data);
                    enqueue(&q,data);
                    break;
            case 2: dequeue(&q);
            break;
            case 3: display(&q);
            break;
            case 4: printf("exiting ....");        
        }
    }
}
