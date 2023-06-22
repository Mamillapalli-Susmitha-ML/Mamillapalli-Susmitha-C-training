#include<iostream>
using namespace std;
class Entity{
    int x,y;    //class variables are private by default
    void move(int a,int b)
    {
        x=a;
        y=b;
    }
};
int main()
{
    Entity e;
    e.move(1,2);//function not accessible here
    cout<<"x="<<e.x<<" "<<"y="<<e.y<<endl;//variables not accessible here
}