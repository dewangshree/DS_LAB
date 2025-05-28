#include<stdio.h>
#include<stdlib.h>
struct bnode{
    int data;
    struct bnode* left;
    struct bnode* right;
};
struct bnode* create(int data){
    struct bnode* newnode=(struct bnode*)malloc(sizeof(struct bnode));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
struct bnode* insert(struct bnode * root,int data){
    if(root==NULL){
        return create(data);
    }
    struct bnode* newnode=create(data);
    struct bnode* curr,*prev;
    prev=NULL;
    curr=root;
    while(curr!=NULL){
        prev=curr;
        if(curr->data>data){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    if(prev->data>data){
        prev->left=newnode;
    }
    else{
        prev->right=newnode;
    }
    return root;
}
void inorder(struct bnode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void serarch(struct bnode* root, int key){
    struct bnode* temp=root;
    while(temp!=NULL && temp->data!=key){
        if(temp->data>key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    if(temp==NULL){
        printf("\n%d is not present in this BST\n",key);
    }
    else{
        printf("\n%d is present in bst \n",key);
    }
}
int maxmarks(struct bnode* root){
    struct bnode* temp=root;
    while(temp->right!=NULL)
    temp=temp->right;
    return temp->data;
}
int minimarks(struct bnode* root){
    struct bnode* temp=root;
    while(temp->left!=NULL)
    temp=temp->left;
    return temp->data;
}
void main(){
    struct bnode* root=NULL;
    int max,min,data,choice;
    while(choice!=6){
        printf("\nenter 1 for insert \n 2 for print in sorted order \n 3 for search element \n 4 for find the minimum marks \n 5 for find maximum marks\n 6 for exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter data to insert\n");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2:inorder(root);
                   break;
            case 3:printf("enter the element to serach \n");
                  scanf("%d",&data);
                  serarch(root,data);
                  break;
            case 4:min=minimarks(root);
                   printf("the minimum marks is %d\n",min);
                   break;
            case 5:max=maxmarks(root);
                  printf("the max marks are %d \n",max);
                  break;
                  case 6: printf("exiting the program \n");
                  break;                            
        }
    }
}
