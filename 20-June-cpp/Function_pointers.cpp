#include<iostream>
using namespace std;
int add(int ,int );
int sub(int,int);
int mul(int,int);
int divide(int,int);
typedef int(*fptr)(int,int);
int main()
{
    int res=0;
    fptr fp[]={add,sub,mul,divide};
    int size=sizeof(fp)/sizeof(fptr);
    for(int i=0;i<size;i++)
    {
        res=fp[i](10,20);
        cout<<"Result="<<res<<endl;
    }
}
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int mul(int a,int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return a/b;
}