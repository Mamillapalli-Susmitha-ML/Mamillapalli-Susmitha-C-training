#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<condition_variable>
#define range 5
std::mutex m;
std::condition_variable cv;
int num=0,turn=1;
std::vector<int>v;
//function to get integer input from user
void reader(int r)
{
  std::unique_lock<std::mutex>ul(m);
  for(int i=1;i<=r;i++)
  {
    cv.wait(ul,[]{return (turn==1)?true:false;}); //wait till turn becomes 1
    std::cout<<"Enter any integer:"<<std::endl;
    std::cin>>num;
    turn=2;
    cv.notify_one();  //notify the waiting thread on condition turn=2
  }
}
//function to write the squares of the input to vector
void writer(int r)
{
  std::unique_lock<std::mutex>ul(m);
  for(int i=1;i<=r;i++)
  {
    cv.wait(ul,[]{return (turn==2)?true:false;}); //wait till turn becomes 2
    v.push_back(num*num); //inserting element to vector
    turn=1;
    cv.notify_one();  //notify the waiting thread on condition turn=1
  }
}

//overloading << operator for printing vector contents
std::ostream& operator<<(std::ostream& os,std::vector<int>&v)
{
  for(std::vector<int>::iterator it=v.begin();it!=v.end();it++)
  {
    std::cout<<*it<<" ";
  }
  return os;
}
int main()
{
  std::thread t1(reader,range);
  std::thread t2(writer,range);
  t1.join();
  t2.join();
  std::cout<<"Squares of entered numbers:"<<std::endl;
  std::cout<<v<<std::endl;
}
