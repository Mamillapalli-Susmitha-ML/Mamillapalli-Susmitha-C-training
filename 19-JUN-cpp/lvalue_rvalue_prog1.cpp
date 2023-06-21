#include<iostream>
using namespace std;
void setvalue(const int&);
int main(){
  int i=10;
  int &ref=i;
  setvalue(ref);
  setvalue(20);
}
void setvalue(const int &a)
{
  cout<<"a="<<a<<endl;
}//const int &var=20 It works-------->const with & makes reference variable to accept an rvalue.
//int &var=20 won't work--------->trying to assign a rvalue to a ref variable.


