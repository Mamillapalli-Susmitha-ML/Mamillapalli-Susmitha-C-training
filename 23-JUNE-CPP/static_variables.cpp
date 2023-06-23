#include<iostream>
using namespace std;
class Employee{
    public:
        static const char* org;
        int empid;
        static void print_org()
        {
            cout<<org<<endl;
        }
        void get_org()
        {
            org="MAPLELABS";//Modifying static variable
            cout<<org<<endl;
        }
};
const char* Employee::org;//If we comment this then we won't be able to use org inside main().will get undefined reference error
int main()
{
    Employee e;
    //e.org="MapleLabs";//not possible to use const members with objects
    Employee::org="MapleLabs";//calling static variable outside the class 
    e.get_org();
    Employee e1;
    e1.get_org();
    cout<<e1.org<<endl;
}