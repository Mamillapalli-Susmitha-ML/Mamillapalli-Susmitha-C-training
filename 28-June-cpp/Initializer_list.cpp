#include<iostream>
using namespace std;
class Example
{
    public:
        Example()
        {
            cout<<"Inside example"<<endl;
        }
        Example(int a)
        {
            cout<<"Inside Example created a="<<a<<endl;
        }
};
class Entity
{
    public:
    float x,y;
    string name;
    Example e1; //One object will get created and non-parameterized constructor invokes.
    
    //Here initializer list is not used.
    Entity(){
        x=1.2f;
        y=2.3f;
        name="susmitha";
        e1=Example(10); //parameterized constructor invokes.
    }

    //With initializer list
    Entity(float p,float q,string n):
        x{p},y{q},name(n),e1{10}    //only parameterized constructor will be invoked
        {
            
        }
};
int main()
{
    Entity e1;
    cout<<"-----------------------------"<<endl;
    Entity e3(1.2f,13.3f,"susmitha");
}