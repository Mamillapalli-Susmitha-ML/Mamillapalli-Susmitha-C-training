#include<iostream>
using namespace std;
int main()
{
  int k=50;
  //compilation time---------const expression
  const int* iptr=new int{80};//point to another address but cannot change the value in the address.Pointer to a constant
  //*iptr=85; it won't work
  iptr=&k;//it works
  cout<<"*iptr="<<*iptr<<endl;
  int* const ptr=&k;//Address can't change but values can change.Constant pointer
  //const *int pttr=&k;  syntax error
  
  
  
  auto i=10;
  //cout<<"type of i="<<typeof(i)<<endl;
  auto p=10.4;
  cout<<"i="<<i<<" p="<<p<<endl;
}
//Use auto variables with iterators of vectors.
