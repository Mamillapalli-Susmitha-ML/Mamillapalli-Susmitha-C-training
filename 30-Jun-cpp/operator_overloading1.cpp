#include<iostream>
using namespace std;
struct vector
{
    float x,y;
    public:
    vector(){}
    vector(float a,float b):x(a),y(b){}

    //Without operator overloading
    vector Add(const vector& v)const
    {
        return vector(x+v.x,y+v.y);
    }
    vector Multiply(const vector& v)const
    {
        return vector(x*v.x,y*v.y);
    }

    //with operator overloading
    vector operator +(const vector& v)const//overloading + operator
    {
        return vector(x+v.x,y+v.y);
    }
    vector operator *(const vector& v)const//overloading * operator 
    {
        return vector(x*v.x,y*v.y);
    }
    //without insertion operator overloading 
    void display()
    {
        cout<<"x="<<x<<" y="<<y<<endl;
    }
};

// overloading insertion operator.
// Left side operand which is cout is not accessible from our class.So overload this function outside the class and pass two arguments.
ostream& operator <<(ostream& os,vector res)
{
    os<<res.x<<" "<<res.y<<endl;
    return os;//If we won't return ostream object, we cannot nest the cout
}

/* void operator <<(ostream& os,vector res)
 {
     os<<res.x<<" "<<res.y<<endl;
 }
    cout<<res<<endl;   won't work in this case because we aren't returning ostream object
    we won't be able to nest cout.So always return ostream object.
 */

int main()
{
    vector position(2.0f,2.0f);
    vector speed(8.0f,9.0f);
    vector increase(2.0f,5.0f);
    vector res=position+speed*increase;
    cout<<res<<endl;
    
    //res.display();
    // vector1 res=position.Add(speed.Multiply(increase));
    // res.display();
}