#include<iostream>
using namespace std;
class Entity
{
    public:
        int a;
        Entity(){
            cout<<"Inside non-parameterized constructor"<<endl;
            a=1;
        }
        Entity(int x)
        {
            a=x;
        }
        ~Entity()
        {
            static int count=1;
            cout<<"Destructor called "<<count++<<endl;
        }
};
int main()
{
    Entity *e=new Entity();
    Entity *e1=new Entity[10]();
    delete e;
    delete[] e1;
}