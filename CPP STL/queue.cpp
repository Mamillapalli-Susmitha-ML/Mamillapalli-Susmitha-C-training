#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int size=q.size();
    cout<<"Size of queue: "<<size<<endl;;
    cout<<"Queue elements: "<<endl;
    queue<int> copy(q);//creating a copy of queue
    while(!q.empty())//check if queue is empty
    {
        cout<<q.front()<<" ";//returns front element from queue
        q.pop();
    }
   cout<<endl<<"Recent most added element is: "<<copy.back()<<endl;//return rear element from queue
}