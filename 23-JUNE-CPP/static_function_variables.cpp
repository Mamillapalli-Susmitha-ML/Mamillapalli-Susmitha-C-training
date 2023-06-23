#include<iostream>
using namespace std;
class Employee
{
    public:
        static string org;
        int empid=10427;
        //static function accessing local variable give error

        // static void print_emp(){
        //     cout<<"EMPLOYEE ID="<<empid<<endl;   
        // }

        //static function accessing static variable
        static void print_org(){
            cout<<"ORGANIZATION="<<org<<endl;
        }

        //Non-static function accessing static variable
        void print_org_again()
        {
            cout<<"ORGANIZATION="<<org<<endl;
        }
};
string Employee::org;
int main()
{
    Employee e;
    e.org="MAPLELABS";
   // e.print_emp();This will throw error because static function accessing local variable
    e.print_org();
    e.print_org_again();
}