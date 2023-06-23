#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> v;
    v.push_back(1);//insert element to the end of vector
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int> v1(5,20);//create a vector of 5 instances with element 20
    cout<<"Before copy of vectors:"<<endl;
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    for(vector <int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl<<"After copy of vectors:"<<endl;
    vector <int> v2(v1);//copy vector v1 to v2
     for(vector <int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*(it)<<" ";
    }
    for(vector <int>::iterator it=v2.begin();it!=v2.end();it++)
    {
        cout<<*(it)<<" ";
    }
    v.erase(v.begin(),v.end());//delete entire elements from vector,end address is excluded
    cout<<endl<<"After deleting from vector v:"<<endl;
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }

    v.insert(v.begin(),2);//Insert element at start of the vector
    v.insert(v.begin(),2,10);//insert two instances of element 10 after the start address of vector
    v.insert(v.begin()+1,2,20);
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl<<"After copying entire vector to v:"<<endl;
    vector<int> copy(2,50);
    v.insert(v.begin(),copy.begin(),copy.end());
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl<<"Before swap of v and v1:"<<endl;
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(vector <int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*(it)<<" ";
    }
    v1.swap(v);//swap two vectors
    cout<<endl<<"After swap of v1 and v:"<<endl;
    for(vector <int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(vector <int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*(it)<<" ";
    }
    v.clear();//clear the entire vector
    if(v.empty()==true)//return true if vector is empty else false
        cout<<endl<<"The vector is empty"<<endl;
    else    
        cout<<"Not empty"<<endl;
}