#include<iostream>
#include<memory>
using namespace std;
class weakpointer
{
    int num;
    public:
        weakpointer(int n):num(n){}
        ~weakpointer()
        {
            cout<<"Inside destructor...."<<endl;
        }
        void getnum()
        {
            cout<<"Num="<<num<<endl;
        }
};
int main()
{
    //creating a shared pointer
    shared_ptr<weakpointer>sptr1(new weakpointer(10));
    //creating weak pointer using shared pointer
    weak_ptr<weakpointer>wptr1(sptr1);
    //weak pointer use count is 1
    cout<<"weak pointer count: "<<wptr1.use_count()<<endl;
    //shared pointer use count is 1
    cout<<"shared pointer count: "<<sptr1.use_count()<<endl;
    //Using lock() to obtain a shared_ptr
    if(shared_ptr<weakpointer>sptr2=wptr1.lock())
    {
        //using shared pointer to access member function
        sptr2->getnum();
        //reference count increases to 2
        cout<<"shared pointer count: "<<sptr2.use_count()<<endl;
    }
    //Using reset() to release the weak reference
    wptr1.reset();
    //lock() returns nullptr hence else block gets executed
    if(shared_ptr<weakpointer>sptr2=wptr1.lock())   
    {
        cout<<"shared pointer count: "<<sptr2.use_count()<<endl;
    }
    else{
        cout<<"Weak pointer expired..."<<endl;
    }
}