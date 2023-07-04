#include<iostream>
using namespace std;
//defining a template for creating arrays of variable size
template<typename T,int N>
class Array
{
   T m_array[N];
   public:
    int get_size()
    {
        return N;
    }
        
};  
template<class t>
void print(t val)
{
    cout<<"Val="<<val<<endl;
}
int main()
{
    print<int>(1);
    print<float>(2.1f);
    print<double>(3.4);
    print<char>('e');
    Array<int,10>arr1;
    cout<<"Int array size="<<arr1.get_size()<<endl;
    Array<string,20>arr2;
    cout<<"String array size="<<arr2.get_size()<<endl;
}