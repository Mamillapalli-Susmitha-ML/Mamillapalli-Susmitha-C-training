#include<iostream>
using namespace std;


void printEntity(Entity *e);
class Entity;

class Entity
{   
        public:
        int x,y;
        /*Initializer list will work fine without this keyword
       Entity(int x,int y):x(x),y(y){} */
       Entity(int x,int y)
       {
        this->x=x;
        this->y=y;
        printEntity(this);
       }
        void print()
        {
            cout<<"x="<<x<<" y="<<y<<endl;
        }
        /* void getx() const
         {
             this->x=10; //this pointer cannot be used to modify values inside const function
         }*/

};
void printEntity(Entity *e)
{
    cout<<"Outside of the class......"<<e->x<<endl;
}
int main()
{
    Entity e(1,2);
    e.print();
}