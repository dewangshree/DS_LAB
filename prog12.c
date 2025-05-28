#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=newnode;
    return newnode;
}
struct node* inserthead(struct node* tail,int data){
if(tail==NULL){
    return create(data);
}
struct node* newnode=create(data);
newnode->next=tail->next;
tail->next=newnode;
return tail;
}

struct node* deleterear(struct node* tail) {
    if (tail == NULL) {
        printf("empty\n");
        return NULL;
    }

    if (tail->next == tail) {
        printf("Deleting the only node: %d\n", tail->data);
        free(tail);
        return NULL;
    }
    struct node* head = tail->next;
    struct node* temp = tail->next;
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = head;
    printf("%d is deleted \n", tail->data);
    free(tail);
    return temp;

}

void display(struct node* tail){
    struct node* temp=tail->next;
    while(temp!=tail){2

        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf(" %d\n",tail->data);
}
int main(){
struct node* head=NULL;
int data,choice;
while(choice!=4){
    printf("enter 1 for insert front  \n 2 for delete rear \n 3 for display \n 4 for exit \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter data to insert \n");
               scanf("%d",&data);
               head=inserthead(head,data);
               break;
        case 2:head=deleterear(head);
               break;
        case 3: display(head);
               break;
        case 4:printf("exiting \n");
               break;       
    }
}
return 0;
}
