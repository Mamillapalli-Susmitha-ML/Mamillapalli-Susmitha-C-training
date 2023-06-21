#include<iostream>
#include<typeinfo>
void helloworld();
void printnumber(int i);
typedef void(*ptr)(int);//rename function pointer with ptr using typedef
typedef void(*ptr1)();//typedef for function pointer with no arguments
int main()
{
    //auto fp=helloworld;   not preffered to use auto.
    void (*fp)()=helloworld;//declaring a function pointer.
    fp();
    void (*fptr)(int)=printnumber;//passing arguments to a function pointer
    fptr(10);
    ptr fptr2=printnumber;//declaring function pointer using ptr;typedef of function pointer
    fptr2(20);
    std::cout<<typeid(fp).name()<<std::endl;
}
void helloworld()
{
    std::cout<<"helloworld"<<std::endl;
}
void printnumber(int i)
{
    std::cout<<"i="<<i<<std::endl;
}