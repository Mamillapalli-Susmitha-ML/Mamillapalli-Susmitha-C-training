#include<iostream>
using namespace std;
class Entity
{
    private:
    int x=0,y=0;
    Entity()
    {
        cout<<"x="<<x<<" y="<<y<<endl;
    }
    public:
    void move(int a,int b)
    {
        x+=a;
        y+=b;
    }
};
class player:Entity{//Derived class 
    void print()
    {
        cout<<"x="<<x<<" y="<<y<<endl;  //x and y not accessible here
    }
};
int main()
{
    Entity e;//Cannot create beacuse constructor is private
    e.move(1,2);//can be invoked because it's public
    e.x=5;//cannot access private variables outside the class
    player p;
    p.print();//Derived class cannot access the private variables of parent class
}