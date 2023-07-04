#include<iostream>
using namespace std;
class Company
{   
    protected:
        int empid;
        string name;
        string department;
    public:
        Company()
        {
            cout<<"Inside Company constructor....."<<endl;
        }
        Company(int e,string n,string d):empid(e),name(n),department(d){}
        void set_emp_data(int e,string n,string d)
        {
            empid=e;
            name=n;
            department=d;
        }
        void get_emp_data()
        {
            cout<<"Employee Name:"<<name<<endl;
            cout<<"Employee Id:"<<empid<<endl;
            cout<<"Employee Department:"<<department<<endl;
        }
        // virtual function in base class which is overriden in child classes.
        virtual string get_emp_department()
        {
            return department;
        }
        //For proper child class object destruction in case of run time polymorphism, we use virtual destructors in base class.
        virtual ~Company()
        {
            cout<<"Inside destructor of Company...."<<endl;
        }

};
class HR:public Company
{
    public:
        HR(int e,string n,string d){
            cout<<"Inside HR constructor......"<<endl;
            empid=e;
            name=n;
            department=d;
        }
        string get_emp_department(){
            return "Department:"+department;
        }
        void onboarding_info()
        {
            cout<<"onboarding started....."<<endl;
        }
        void recruitment_info()
        {
            cout<<"Recruitment in progress...."<<endl;
        }
        ~HR()
        {
            cout<<"Inside destructor of HR...."<<endl;
        }
};

class Finance:public Company
{
    public:
        Finance(int e,string n,string d){
            cout<<"Inside Finance constructor......."<<endl;
            empid=e;
            name=n;
            department=d;
        }
        string get_emp_department(){
            return "Department:"+department;
        }
        ~Finance()
        {
            cout<<"Inside destructor of Finance...."<<endl;
        }
};

class Support:public Company
{
    public:
        Support(int e,string n,string d){
            cout<<"Inside Support constructor....."<<endl;
            empid=e;
            name=n;
            department=d;
        }
        string get_emp_department(){
            return "Department:"+department;
        }
        ~Support()
        {
            cout<<"Inside destructor of Support....."<<endl;
        }
};
int main()
{   //base class constructor will be called and then          corresponding child class constructors are called.
    Company *cp1=new HR(1091,"swetha","HR");
    Company *cp2=new Finance(1432,"Megha","Finance");
    Company *cp3=new Support(1654,"Shona","Support");
    cout<<cp1->get_emp_department()<<endl;
    cout<<cp2->get_emp_department()<<endl;
    cout<<cp3->get_emp_department()<<endl;
    //child class destructors will be called and then base class destructor.
    delete cp1;
    delete cp2;
    delete cp3;
}