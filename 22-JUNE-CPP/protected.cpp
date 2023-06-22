#include<iostream>
using namespace std;
class Entity
{
    protected:
        int x,y;
        void move(int a,int b)
        {
            x=a;
            y=b;
        }
    public:
        Entity()
        {
            x=0;
            y=0;
        }
};
class player:public Entity{
    private:
        string name;
    public:
        player()
        {
            x=3;
            y=4;
            cout<<"x="<<x<<" y="<<y<<endl;//protected variables are accessible inside derived class
        }
};
int main()
{
    Entity e;
    e.x=8;//private not accessible outside the class
    player p;
    p.x=5;//derived class cannot access protected variables of parent outside the derived class
}