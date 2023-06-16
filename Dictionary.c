#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Function declaration
struct dictionary* Add_Word();
struct dictionary* search(char *);
struct dictionary* Delete(struct dictionary*);
void print_Dictionary();
struct dictionary{
    char *word;
    char *meaning;
    struct dictionary *next;
};
struct dictionary *head=NULL,*node=NULL,*temp=NULL,*found=NULL;
int op;
char *temp_word;
int main(){
    do{
        printf("\n1.Insert a word\n2.Delete a word\n3.Print Dictionary\n");
        scanf("%d",&op);
        fgetc(stdin);
        switch(op)
        {
            case 1:
            {
                Add_Word();
                break;
            }
            case 2:
            {
                printf("Enter the string to be deleted:");
                temp_word=(char*)malloc(sizeof(char)*100);
                fgets(temp_word,100,stdin);
                temp_word[strlen(temp_word)-1]=0;   //Removing the last '\n' character from temp_word
                found=search(temp_word);
                free(temp_word);
                if(found)
                    Delete(found);
                else
                    printf("Entered string not found in dictionary\n");
                break;
            }
            case 3:
            {
                print_Dictionary();
                break;
            }
        }
    }while(op!=0);
}
//Function to add a word and meaning into the dictionary
struct dictionary* Add_Word(){
    node=(struct dictionary*)malloc(sizeof(struct dictionary));
    node->word=(char *)malloc(100*sizeof(char));
    node->meaning=(char *)malloc(100*sizeof(char));
    printf("Enter the word to insert:\n");
    fgets(node->word,100,stdin);
    printf("Enter the meaning of the word:\n");
    fgets(node->meaning,100,stdin);
    node->word[strlen(node->word)-1]=0;
    node->meaning[strlen(node->meaning)-1]=0;
    node->next=NULL;
    if(head==NULL)
        head=node;
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
    }
    return head;
}
//Function to search for a word in the dictionary
struct dictionary* search(char *str){
    temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->word,str)==0)
            return temp;
        temp=temp->next;
    }
    return NULL;
}
//Function to delete a word and meaning from the dictionary
struct dictionary* Delete(struct dictionary *del){
     if(head==del){
        head=head->next;
        free(del);
    }
    else{
        temp=head;
        while(temp->next!=del){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(del);
    }
    return head;
}
//Function to print the dictionary
void print_Dictionary(){
    temp=head;
    printf("\n----------------Dictionary Contents----------------\n");
    while(temp!=NULL)
    {
        printf("%s  :  %s\n",temp->word,temp->meaning);
        temp=temp->next;
    }
}
