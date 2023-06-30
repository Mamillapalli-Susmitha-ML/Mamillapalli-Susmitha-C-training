#include<iostream>
using namespace std;
class TimeConversion
{
    int seconds;
    public:
        TimeConversion(int s):seconds(s){}
        void set_seconds(int s){seconds=s;}
        void conversion()
        {
            int hours=seconds/3600;
            int min=(seconds-(hours*3600))/60;
            int sec=seconds-(hours*3600)-(min*60);
            cout<<"HH:MM:SS="<<hours<<":"<<min<<":"<<sec<<endl;
        }
};
int main()
{
    int time;
    cout<<"Enter time in seconds:";
    cin>>time;
    TimeConversion t(time);
    t.conversion();
}