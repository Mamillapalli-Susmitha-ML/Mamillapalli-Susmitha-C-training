#include<iostream>
#include<vector>
using namespace std;
struct vertex
{
    int x,y,z;
    vertex(const vertex& v):
        x(v.x),y(v.y),z(v.z)
        {
            cout<<"In cpy cnstr....."<<endl;
        }
        vertex(int x,int y,int z):x(x),y(y),z(z)
        {   
        }
};

ostream& operator <<(ostream& os,const vertex& v)
{
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
    return os;
}
void function(const vector<vertex>&v)
{
    cout<<"in function......."<<endl;
}
int main()
{
    vector<vertex>v;
    /*we can use push_back with reserve for better performance or can use emplace_back
        v.reserve(3);           
        v.push_back(1,2,3);
        v.push_back(4,5,6);
        v.push_back(7,8,9);
    */
    v.emplace_back(1,2,3);
    v.emplace_back(4,5,6);
    v.emplace_back(7,8,9);
    for(const vertex& ver:v)
    {
        cout<<ver;
    }
    //function(v);      if we pass by value , copy constructor gets called every time.
    function(v);
}