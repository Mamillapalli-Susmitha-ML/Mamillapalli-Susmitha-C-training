#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> st;
    st.insert(1);//insert element to the stack
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl<<"Size of set is: "<<st.size()<<endl;
    cout<<"Is i present in set?? "<<st.count(1)<<endl;//return 1 if element is present else 0
    st.erase(1);//remove element from the set
    cout<<"After deleting 1 from set "<<endl;
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl<<"size of set is: "<<st.size()<<endl;//return the size of set
}