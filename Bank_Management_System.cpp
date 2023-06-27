#include<iostream>
using namespace std;
#define no_customers 20
class Bank
{   
    string name;
    float balance;
    long int account_no;
    public:
        Bank(){}
        void openAccount(Bank *b)
        {
            static int count=0;
            string n;
            float bal;
            long int ac_no=152376900;
            cout<<"Enter you name:"<<endl;
            cin>>n;
            ac_no+=count;
            count++;
            cout<<"Pls note your account number......."<<ac_no<<endl;
            do{
                cout<<"Enter your opening balance(Must be alteast 1000)"<<endl;
                cin>>bal;
                if(bal<1000)
                    cout<<"Opening balance must be atleast 1000"<<endl;
            }while(bal<1000);
            b->name=n;
            b->account_no=ac_no;
            b->balance=bal;
        }
        string getname(){return name;}
        float getAmount(){return balance;}
        long int getAccountNumber(){return account_no;}
        void showDetails(Bank b[],int index)
        {
            for(int i=0;i<index;i++)
            {
                cout<<endl<<"--------------------------------------------------"<<endl;
                cout<<"NAME:"<<b[i].name<<endl;
                cout<<"ACCOUNT NUMBER:"<<b[i].account_no<<endl;
                cout<<"BALANCE:"<<b[i].balance<<endl;
                cout<<endl<<"--------------------------------------------------"<<endl;
            }
        }
        void addBalance(Bank *b)
        {
            float amount;
            cout<<"Enter the amount to be deposited:"<<endl;
            cin>>amount;
            b->balance+=amount;
        }
        void withdraw(Bank *b)
        {
            int amount;
            cout<<"Enter the amount to be withdrawn:"<<endl;
            cin>>amount;
            if(b->balance>=amount+1000)
            {
                b->balance-=amount;
                cout<<"Withdrawl successful:)"<<endl;
            }
            else
                cout<<"Withdrawl failed:(  Insufficient balance"<<endl;
        }
        Bank* search(Bank b[],long int ac)
        {
            for(int i=0;i<no_customers;i++)
            {
                if(b[i].account_no==ac)
                   return &b[i];
            }
            return NULL;
        }
        //~Bank(){cout<<"Inside destructor"<<endl;}
};
int main()
{
    Bank b1;
    Bank *b=new Bank[no_customers]();;
    int op,index=0;
    long int ac;
    do
    {
        cout<<"\n1.Open Account\n2.Add Balance\n3.Withdraw Amount\n4.Search a Record\n5.Show Details\n6.Exit\n";
        cin>>op;
        switch(op)
        {
            case 1:
            {
                b1.openAccount(&b[index]);
                index++;
                break;
            }
            case 2:
            {
                cout<<"Enter your account number:"<<endl;
                cin>>ac;
                Bank *temp=b1.search(b,ac);
                if(temp!=NULL)
                {
                    b1.addBalance(temp);
                }
                else    
                    cout<<"Not found in the records!!!!"<<endl;
                break;
            }
            case 3:
            {
                cout<<"Enter your account number:"<<endl;
                cin>>ac;
                Bank *temp=b1.search(b,ac);
                if(temp!=NULL)
                {
                    b1.withdraw(temp);
                }
                else    
                    cout<<"Not found in the records!!!!"<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter your account number:"<<endl;
                cin>>ac;
                Bank *temp=b1.search(b,ac);
                if(temp!=NULL)
                {
                    cout<<endl<<"--------------------------------------------------"<<endl;
                    cout<<"NAME:"<<temp->getname()<<endl;
                    cout<<"ACCOUNT NUMBER:"<<temp->getAccountNumber()<<endl;
                    cout<<"BALANCE:"<<temp->getAmount()<<endl;
                    cout<<endl<<"--------------------------------------------------"<<endl;
                }
                else
                    cout<<"Not found in the records!!!!"<<endl;
                break;
            }
            case 5:
            {
                b1.showDetails(b,index);
                break;
            }
        }
    } while(op!=6);    
    delete[] b;
}