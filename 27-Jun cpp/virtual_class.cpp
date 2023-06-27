#include<iostream>
using namespace std;
class printable
{
    public:
        virtual string getClassName()=0;    //pure virtual function

};
class Entity:public printable{
    public:
        string getClassName()
        override{
            return "Entity class";
        }
};
class player:public Entity{
    public:
        string getClassName()
        override{
            return "Player class";
        }
};
class A:public printable
{
    public:
        string getClassName()
        override{
            return "A";
        }
};
void print(printable *p)
{
   cout<< p->getClassName()<<endl;
}
int main()
{
    Entity *e=new Entity();
    print(e);
    player *p=new player();
    print(p);
    A *a=new A();
    print(a);
}