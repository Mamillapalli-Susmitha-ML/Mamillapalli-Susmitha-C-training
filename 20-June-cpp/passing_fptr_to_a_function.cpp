#include<iostream>
#include <iterator>
#include<vector>
using namespace std;
void printvalue(int);
typedef void(*fptr)(int);
int main(){
    
    vector <int> values={1,2,3,4,5};
    fptr fp1= printvalue;
    for(vector<int>::iterator it=values.begin();it<values.end();it++)
    {
       // cout << "Value " << *it << endl;
        fp1(*it);
    }
    

}
void printvalue(int a)
{
    std::cout<<"value="<<a<<std::endl;
}
void foreach(fptr fp,int a)
{
    fp(a);
}
