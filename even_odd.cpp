#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cv;  //condition variable is used for thread synchronization.
int turn=2;     //The turn variable is used to control the execution order of the even and odd threads. 
void even(int l)
{
    unique_lock<mutex>ul(m);
    for(int i=0;i<=l;i++)
    {
        cv.wait(ul,[]{return (turn==2)?true:false;});   //even thread waits until turn becomes 2
        if(i%2==0)
            cout<<i<<" ";
        turn=1;
        cv.notify_one();    //To wake up a waiting thread that is waiting on the condition turn == 1
    }
}
void odd(int l)
{
    unique_lock<mutex>ul(m);
    for(int i=0;i<=l;i++)
    {
        cv.wait(ul,[]{return (turn==1)?true:false;});   //odd thread waits until turn becomes 1
        if(i%2!=0)
            cout<<i<<" ";
        turn=2;
        cv.notify_one();    // To wake up a waiting thread that is waiting on the condition turn == 2.
    }
}
int main()
{
    thread t1(odd,10);
    thread t2(even,10);
    t1.join();
    t2.join();
}