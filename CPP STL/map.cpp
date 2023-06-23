#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int>mp;
    mp[1]=2;//insert {key,value} to map
    mp[2]=3;
    mp[3]=4;
    mp[5]=6;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;//it->first for printing key and it->second for printing value
    }
    int size=mp.size();//return size of map
    cout<<"Size of map is: "<<mp.size()<<endl;
    map<int,int>::iterator it=mp.find(1);//find return the address of the specified element if present else return end address
    cout<<it->first<<" "<<it->second<<endl;
    bool is_empty=mp.empty();//check if map is empty
    cout<<"Is map empty?? "<<is_empty<<endl;
}