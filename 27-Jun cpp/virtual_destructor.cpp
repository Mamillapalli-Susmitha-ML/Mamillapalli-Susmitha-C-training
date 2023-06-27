#include<iostream>
using namespace std;
class base
{
    public:
        base()
        {
            cout<<"In base constructor"<<endl;
        }
        virtual ~base()                 //Virtual destructor
        {
            cout<<"In base destructor"<<endl;
        }
};
class derived:public base{
    public:
        derived()
        {
            cout<<"In derived constructor"<<endl;
        }
        ~derived()
        {
            cout<<"In derived destructor"<<endl;
        }
};
int main()
{
    base *b=new base();
    delete b;
    cout<<"________________________________________"<<endl;
    derived *d=new derived();
    delete d;
    cout<<"________________________________________"<<endl;
    base *b1=new derived(); //using base class pointer to hold derived class instance
    delete b1;
}