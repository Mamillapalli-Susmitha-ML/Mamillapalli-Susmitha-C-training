#include<iostream>
using namespace std;
class myclass
{
    public:
        int arr[5]={1,2,3,4,5};
        void operator [](int x)//overloading subscript operator
        {
            cout<<"Array element arr[]="<<arr[x]<<endl;
        }
};
int main()
{
    myclass m;
    m[1];

}