#include<stdio.h>
#include<string.h>
int main(){
    char sentence[100];
    int count=0;
    char vowels[]="aeiouAEIUO";
    printf("Enter any sentence:\n");
    fgets(sentence,100,stdin);
    for(int i=0;i<strlen(sentence);i++)
    {
        if(strchr(vowels,sentence[i])){
            count++;
        }
    }
    printf("There are %d vowels present in given sentence\n",count);
}