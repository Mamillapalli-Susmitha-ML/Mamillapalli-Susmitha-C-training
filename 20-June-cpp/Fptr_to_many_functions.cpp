#include<iostream>
#include<typeinfo>
int add(int ,int );
int sub(int,int);
int mul(int,int);
int divide(int,int);
typedef int(*ptr)(int,int);
int main(){
    ptr ap=add;
    std::cout<<"sum="<<ap(10,20)<<std::endl;

    ptr sp=sub;
    std::cout<<"diff="<<sp(10,20)<<std::endl;

    ptr mp=mul;
    std::cout<<"multipication="<<mp(10,20)<<std::endl;

    ptr dp=divide;
    std::cout<<"Division="<<dp(10,20)<<std::endl;

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