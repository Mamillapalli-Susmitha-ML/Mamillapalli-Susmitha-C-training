#include<iostream>
using namespace std;
#define N 5
template<typename T>
class vectors
{
    T *arr=new T[N];
    int size;
    int v_capacity;
    public:
        vectors() : size(0), v_capacity(N) {}
        int Size()
        {
            return size;
        }
        bool isEmpty()
        {
            if(size==0) return true;
            return false;
        }
        void Push_back(T ele)
        {
            if(size>=v_capacity)
            {
                v_capacity*=2;
                T* newElements = new T[v_capacity];
                for (int i = 0; i < size; ++i)
                {
                    newElements[i] = arr[i];
                }
                delete[] arr;
                arr = newElements;
                arr[size++]=ele;
            }
            else{
                arr[size++]=ele;
            }
        }
        void print()
        {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        ~vectors()
        {
            delete[] arr;
        }
};
int main()
{
    vectors<char>v;
    v.Push_back('a');
    v.Push_back('b');
    v.Push_back('c');
    v.Push_back('d');
    v.Push_back('e');
    v.Push_back('f');
    cout<<"The vector elements are:"<<endl;
    v.print();
    cout<<endl<<"Vector Size:"<<v.Size()<<endl;
    cout<<"Is vector empty?"<<v.isEmpty()<<endl;
    cout<<"---------------------------------------------------"<<endl;
    vectors<int>v1;
    v1.Push_back(1);
    v1.Push_back(2);
    v1.Push_back(3);
    v1.Push_back(4);
    v1.Push_back(5);
    v1.Push_back(6);
    cout<<"The vector elements are:"<<endl;
    v1.print();
    cout<<endl<<"Vector Size:"<<v1.Size()<<endl;
    cout<<"Is vector empty?"<<v1.isEmpty()<<endl;
    cout<<"---------------------------------------------------"<<endl;
    vectors<string>v2;
    v2.Push_back("C");
    v2.Push_back("C++");
    v2.Push_back("Java");
    v2.Push_back("Perl");
    v2.Push_back("Ruby");
    v2.Push_back("Python");
    cout<<"The vector elements are:"<<endl;
    v2.print();
    cout<<endl<<"Vector Size:"<<v2.Size()<<endl;
    cout<<"Is vector empty?"<<v2.isEmpty()<<endl;
}