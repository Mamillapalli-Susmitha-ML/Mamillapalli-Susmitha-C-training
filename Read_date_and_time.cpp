#include<iostream>
// To use date and time in c++, <ctime> header file is added in the program.
#include<ctime>
int main()
{
     //Executes the date command using the system() function. The system() function runs the "date" command in the system's shell.
    int result=system("sudo date");

    //If system() fails it will return -1
    if(result==-1)
    {
        std::cout<<"Failed to read date and time"<<std::endl;
    }
    else{
        std::cout<<"date and time successfully read"<<std::endl;
    }
}