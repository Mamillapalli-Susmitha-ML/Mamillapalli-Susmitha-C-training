#include<iostream>
#include<string.h>
using namespace std;
class String
{
    int m_size;
    char *m_buffer;
    public:
        String(const char* buf)
        {
            m_size=strlen(buf);
            m_buffer=new char[m_size+1];
            memcpy(m_buffer,buf,m_size+1);
            m_buffer[m_size]=0;
        }
        String()
        {
            cout<<"In constructor..."<<endl;
        }
        friend ostream& operator <<(ostream& os,String str)
        {
            cout<<str.m_buffer<<endl;
            return os;
        }
        char& operator[](int index)
        {
            return m_buffer[index];
        }

        // String(const String& other):m_size(other.m_size),
        // m_buffer(other.m_buffer){}
        //String(const String& other)=delete; will give error

        String(const String& other):m_size(other.m_size){
            m_buffer=new char[m_size+1];
            memcpy(m_buffer,other.m_buffer,m_size+1);
            m_buffer[m_size]=0;
            cout<<"Inside cpy cnstr......"<<endl;
        }
        ~String()
        {
           
            delete m_buffer;
        }
};
void print(String& s)   
{
    cout<<s;
}
// void print(String s)
// {
//     cout<<s;
// }
int main()
{
    String s1="Maple";
    String s2=s1;
    s1[0]='T';
    // cout<<s1;
    // cout<<s2;
    print(s1);
    print(s2);
}