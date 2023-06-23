#include<iostream>
using namespace std;
class Entity
{
    public:
        float a,b;
        //default constructor don't initialize anything if we have primitive variables.But strings get initialized
        Entity()
        {
            a=b=0;
        }
        Entity(int x,int y)
        {
            a=b=0;
            cout<<"a="<<a+x<<" b="<<b+y<<endl;
        }
        ~Entity()
        {
            //need to use when we use new operator for creating object
            cout<<"Inside destructor"<<endl;
        }
        void print_val()
        {
            cout<<"a="<<a<<" b="<<b<<endl;
        }
};
int main()
{
    Entity e;
    Entity e1(1,2);
    e1.print_val();
}