#include<iostream>
using namespace std;
struct vector
{
    float x,y;
    vector(){}
    vector(float a,float b):x{a},y{b}
    {}
    //A function to add members of two classes(Without operator overloading)
    vector sum(vector& v1)
    {
        vector v2;
        v2.x=x+v1.x;
        v2.y=v1.y+y;
        return v2;

    }
};
int main()
{
    vector position(1.2f,1.3f);
    vector speed(2.0f,3.0f);
    vector res=position.sum(speed);
    cout<<res.x<<" "<<res.y<<endl;
    //vector result=position+speed; results in an error without operator overloading
}