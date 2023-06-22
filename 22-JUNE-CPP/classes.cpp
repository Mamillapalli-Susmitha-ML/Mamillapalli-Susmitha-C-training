#include<iostream>
using namespace std;
class Entity{
    public: //by default class variables are private but struct variables are public by default
       int x,y;
       void moveinside(int x,int y);

};
void move(Entity &e,int a,int b);

void move(Entity &e,int a,int b)
{
    e.x=a;
    e.y=b;
}
void Entity::moveinside(int a,int b)//function definition outside the class
{
    x=x+a;
    y=y+b;
}
int main()
{
    Entity e;
    move(e,1,2);
    cout<<"x="<<e.x<<" "<<"y="<<e.y<<" size="<<sizeof(e)<<endl;
    e.moveinside(12,13);
    cout<<"x="<<e.x<<" "<<"y="<<e.y<<" size="<<sizeof(e)<<endl;
}
