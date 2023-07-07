#include<iostream>
#include<ctime>
// To use date and time in c++, <ctime> header file is added in the program.
using namespace std;
int main()
{
    //time() represents current time.
    time_t curr_time=time(nullptr);

    // localtime()cfunction returns the pointer to the tm structure representing local time
    struct tm *local=localtime(&curr_time);

    local->tm_sec=45;// seconds of minutes from 0 to 61 
    local->tm_min=6;// minutes of hour from 0 to 59
    local->tm_hour=13;// hours of day from 0 to 24
    local->tm_mday=23;// day of month from 1 to 31
    local->tm_mon=8; // month of year from 0 to 11
    local->tm_year=100;// year since 1900.Eg:1900+100=2000
    local->tm_wday=3;

    // This function converts mktime to time_t or calendar date and time.
    time_t modified_time=mktime(local);

    //The to_string() function is used to convert the modified_time value from a time_t type to a string representation.
    // the "@" symbol is used to specify that the value following it represents a Unix timestamp.
    string command = "sudo date --set=@" + to_string(modified_time);

    // command.c_str() will return a pointer to a null-terminated character array const char*
    // passing command.c_str() as the argument to the system(), to execute the command represented by the "command" string.
    int result = system(command.c_str());

    //If system() fails it will return -1
    if(result==-1)
    {
        cout<<"Failed to set date and time"<<endl;
    }
    else{
        cout<<"Successfully set date and time"<<endl;
    }
}
