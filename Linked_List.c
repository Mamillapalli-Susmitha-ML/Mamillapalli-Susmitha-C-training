#include<stdio.h>
#include<stdlib.h>

// Function Declaration
struct LinkedList* Insert_At_Begining();
struct LinkedList* Insert_At_End();
struct LinkedList* search(int);
struct LinkedList* Delete(struct LinkedList*);
void print_List();

//Structure to represent a node
struct LinkedList{
   struct LinkedList *next;
   int data;
};

struct LinkedList *head,*node,*temp,*found;
int op,element;

int main(){
    do{
         printf("Choose one:\n1.Insert at begining\n2.Insert at end\n3.Delete element\n4.Print List\nPress 0 to exit......\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:{
                Insert_At_Begining();
                break;
            }
            case 2:{
                Insert_At_End();
                break;
            }
            case 3:{
                printf("Enter an element to delete:\n");
                scanf("%d",&element);
                found=search(element);
                if(found)
                    Delete(found);
                else    
                    printf("Element not found!!\n");
                break;
            }
            case 4:{
                print_List();
                break;
            }
        }
    }while(op!=0);
}

//Function to insert element at the begining of the linked list
struct LinkedList* Insert_At_Begining(){
    printf("Enter the element:\n");
    scanf("%d",&element);
    node=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->data=element;
    if(head==NULL){
        head=node;
    }
    else{
        node->next=head;
        head=node;
    }
    return head;
}

//Function to insert node at the end of the list
struct LinkedList* Insert_At_End(){
    printf("Enter the element:\n");
    scanf("%d",&element);
    node=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->data=element;
    node->next=NULL;
    if(head==NULL){
        head=node;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
    }
    return head;
}

//Function to search in the linked list based on the item to be deleted
struct LinkedList* search(int item){
    temp=head;
    while(temp!=NULL){
        if(temp->data==item){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

//Function to delete nodes from the linked list
struct LinkedList* Delete(struct LinkedList* del){
    if(head==del){
        head=head->next;
        free(del);
    }
    else{
        temp=head;
        node=NULL;
        while(temp->next!=del){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(del);
    }
    return head;
}
 
//Function to print the linked list
void print_List(){
    temp=head;
    printf("List Elements:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}