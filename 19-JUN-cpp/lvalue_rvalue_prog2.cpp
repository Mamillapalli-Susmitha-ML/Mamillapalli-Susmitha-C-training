#include<iostream>
using namespace std;
void printname(const string&);  //It works with const 
void printname(string&&); //Instead of const& we can use && to bind rvalue to a ref lvalue.
int main()
{
  string fname="maple";
  string lname="labs";
  string fullname=fname+lname;
  printname(fullname);
  printname(fname+lname);
  printname("Hello world");
  printname(fullname); //string&& name=fullname wont work.&& is only to bind rvalue to a ref lvalue.
  printname(fname+lname); //works with && and also with const&
  printname("hello world"); //works with && and also with const&
}
void printname(const string &name)
{
  cout<<"name="<<name<<endl;
}
void printname(string &&name)
{
  cout<<"name="<<name<<endl;
}

