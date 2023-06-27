#include<iostream>
using namespace std;
class Entity
{
    public:
        Entity(){}
        string name;
        virtual void getname()=0;   //pure virtual function
};
class player:public Entity
{
    public:
        player(){}
        void getname()  //Implementing pure virtual function of base class inside derived class
        {
            cout<<"In player class"<<endl;
        }
};
int main()
{
    //Entity e; cannot instantiate Entity class
    player *p=new player();
}