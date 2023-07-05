#include<iostream>
#include<map>
using namespace std;
//class template to print map contents.
template<typename K,typename V>
class Map
{
    public:
        void print(map<K,V>mp)
        {
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
};
int main()
{
    map<string,int>roll_no;
    roll_no["Harry"]=1;
    roll_no["Potter"]=2;
    roll_no["Ron"]=3;
    roll_no["Hermoine"]=4;
    Map<string,int>mp1;
    mp1.print(roll_no);
    cout<<"--------------------------------"<<endl;
    map<int,int>kv;
    kv[1]=100;
    kv[2]=200;
    kv[3]=300;
    Map<int,int>mp2;
    mp2.print(kv);
}