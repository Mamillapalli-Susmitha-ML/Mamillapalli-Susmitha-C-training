#include<iostream>
#include<memory>
using namespace std;
class sharedpointer
{   
    int num;
    public:
        sharedpointer(int a):num(a){}
        ~sharedpointer()
        {
            cout<<"Inside destructor"<<endl;
        }
        void getNum()
        {
            cout<<"NUM="<<num<<endl;
        }
};
void test_shared_pointer(shared_ptr<sharedpointer>sptr)
{
    cout<<"Inside function....use count of sptr:  "<<sptr.use_count()<<endl;
}
int main()
{
    shared_ptr<sharedpointer> sptr1(new sharedpointer(10)); //creating a shared pointer
    sptr1->getNum();
    //use_count give the number of shared pointers refering to the same managed object.Reference count=1 here
    cout<<"Use count of shared pointer1:    "<<sptr1.use_count()<<endl; 
    //creating shared pointer using sptr1   
    shared_ptr<sharedpointer>sptr2(sptr1);          
    sptr2->getNum();
    //reference count will increase as sptr1 and sptr2 are refering to same managed object. Reference count=2 here
    cout<<"Use count of shared pointer2:    "<<sptr2.use_count()<<endl;
    shared_ptr<sharedpointer>*sptr3=&sptr1;
     //reference count won't increase if we use reference or pointer of a shared pointer.Reference count is still 2.
    cout<<"Use count of shared pointer3:    "<<sptr3->use_count()<<endl;   
    shared_ptr<sharedpointer>&sptr4=sptr1;
    sptr4->getNum();
    //reference count won't increase if we use reference or pointer of a shared pointer.Reference count is still 2.
    cout<<"Use count of shared pointer4:    "<<sptr4.use_count()<<endl;
    /*reference count will increase to 3 because we are passing shared pointer as an argument to a function.
    Function will maintain a copy of this shared pointer*/
    test_shared_pointer(sptr1);  
    //reference count decreases to 2 after this function execution.
    cout<<"Use count of shared pointer4:    "<<sptr4.use_count()<<endl;                   
}
//Destructor will be called on the managed object as the shared pointers goes out of scope