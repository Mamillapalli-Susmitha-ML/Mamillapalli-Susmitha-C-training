#include<iostream>
using namespace std;
class base
{
    public:
        base(){}
        virtual void display()  //Virtual function which is overriden in derived class
        {
            cout<<"base class"<<endl;
        }
        virtual void display1() //virtual function which is not overriden in derived class
        {
            cout<<"base class again"<<endl;
        }
};
class derived:public base{
    public:
        derived(){}
        void display()  //overriden function
        override{
            cout<<"derived class"<<endl;
        }
};
void printName(base *b)
{
    b->display();
}
int main()
{
    // base b;
    // b.seta(10);
    // b.display();
    // derived d;
    // d.setb(20);
    // d.display();
    // base *b=new base();
    // printName(b);
    // derived *d=new derived();
    // printName(d);
    base *b1=new derived(); //using base class pointer to hold derived class instance
    printName(b1);
    b1->display1();
}