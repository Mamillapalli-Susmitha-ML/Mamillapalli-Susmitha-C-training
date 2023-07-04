#include<iostream>
using namespace std;
struct vector1{
    int a,b;
    void print()
    {
        cout<<"a="<<a<<" b="<<b<<endl;
    }
};
int main()
{
    vector1 v1={1,2};
    vector1 v2=v1;  //copy values from v1 object to v2 object
    v1.print();
    v2.print();
    vector1 *v3=new vector1;
    v3->print();
    vector1 *v4=v3;//Initializing v4 using pointer v3
    v4->print();
    v4->a=20;   //this line modifies the value of a in both v4 and v3 instances
    v3->print();
    v4->print();
}