#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    int size=st.size();
    cout<<"The size of stack is: "<<st.size()<<endl;
    int top_element=st.top();
    cout<<"Top most element in stack is: "<<st.top()<<endl;
    st.pop();
    cout<<"Top most element in stack after pop operation is: "<<st.top()<<endl;
    bool is_empty=st.empty();
    cout<<"Is stack empty?? "<<is_empty<<endl;
    cout<<"stack elements: "<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}