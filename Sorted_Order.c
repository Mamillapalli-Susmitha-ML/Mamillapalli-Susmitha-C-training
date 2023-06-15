#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Function declaration
void printArray(char*[]);
void SortArray(char *[]);
int size,i,j;
char *key;
int main(){
    printf("Enter the size of array:");
    scanf("%d",&size);
    char *names[size];
    printf("Enter the array elements:\n");
    for(int i=0;i<size;i++)
    {
        //Dynamically Allocating memory to each pointer
        names[i]=malloc(100*sizeof(char));
        scanf("%s",names[i]);
    }    
    SortArray(names);
    printArray(names);
}
//Function to sort the array of strings
void SortArray(char *names[])
{
    for(int i=1;i<size;i++)
    {
        j=i-1;
        key=names[i];
        while(j>=0&&strcmp(names[j],key)>0)
        {
            names[j+1]=names[j];
            j-=1;
        }
        names[j+1]=key;
    }
}
//Function to print array of strings
void printArray(char *names[]){
    printf("\nThe sorted array elements are:\n");
    for(int k =0;k<size;k++)
        printf("%s\n",names[k]);
}