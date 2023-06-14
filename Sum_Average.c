#include<stdio.h>
//Function declaration
void sum(int [],int);
void Average(int [],int);
int main(){
    int nums[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(nums)/sizeof(nums[0]);
    sum(nums,size);
    Average(nums,size);
}
//Function to calculate sum of given numbers
void sum(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    printf("The sum of given numbers is %d\n",sum);
}
//Function to calculate Average of given numbers
void Average(int arr[],int size){
    float avg=0,sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    avg=sum/size;
    printf("The Average of given numbers is %f\n",avg);
}
