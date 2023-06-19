#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 50
int main(){
    FILE *fptr=fopen("data.txt","w");   //A file pointer to write data to the file
    char buffer[size];  //Buffer to store the user input
    if(fptr==NULL)
    {
        printf("File open Unsuccessful\n");
        exit(0);
    }
    //Getting user input,storing it to buffer and writing to the file
    else{
       while((strcmp(buffer,"bye"))!=0){
        printf("Enter data:\n");
        fgets(buffer,size,stdin);
        buffer[strlen(buffer)-1]=0;
        if(strcmp(buffer,"bye")!=0)
             fputs(strcat(buffer,"\n"),fptr);
       }
    }
    fclose(fptr);   //Closing the file 
    printf("---------FILE CONTENT---------\n");
    //Printing the content of the file
    FILE *rptr=fopen("data.txt","r");
    while((fgets(buffer,size,rptr)!=NULL))
            printf("%s",buffer);
}