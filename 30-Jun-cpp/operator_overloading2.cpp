#include<iostream>
#include<list>
using namespace std;
struct Utubechannel
{
    string title;
    int totalsuscribers;
    Utubechannel(string s,int c):title(s),totalsuscribers(c){}

};
struct Mycollection
{
    list <Utubechannel> channels;
    //overloading += operator
    void operator +=(Utubechannel& t)
    {
        channels.push_back(t);
    }
};

//overloading insertion operator
ostream& operator <<(ostream& os,Mycollection& c)
{
    for(list<Utubechannel>::iterator it=c.channels.begin();it!=c.channels.end();it++)
    {
        cout<<it->title<<" "<<it->totalsuscribers<<endl;
    }
    return os;
}
int main()
{
    Utubechannel yt1{"Mygames",500};
    Utubechannel yt2{"MyMusic",600};
    Mycollection mc;
    mc+=yt1;
    mc+=yt2;
    cout<<mc<<endl;
}