#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(1);//Insert elements to the end of the list
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    for(list<int>:: iterator it=l.begin();it!=l.end();it++){
        cout<<*(it)<<" ";
    }
    l.clear();//clear all list elements
    cout<<endl<<"After clearing all list elements:"<<endl;
    for(list<int>:: iterator it=l.begin();it!=l.end();it++){
        cout<<*(it)<<" ";
    }
    bool isempty=l.empty();
    cout<<"Is list empty?? "<<isempty<<endl;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);//insert element to the beginging of list
    int size=l.size();
    cout<<"List size is: "<<size<<endl;
}