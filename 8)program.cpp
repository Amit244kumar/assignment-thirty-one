#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Customer
{
   private:
      char C_name[10];
      long int phone_no;
   protected:
    void setCustDetails(long int ph,char *n)
    {
        phone_no=ph;
        strcpy(C_name,n);
    }
     void displayCust()
    {
        cout<<"----------------------------------"<<endl;
        cout<<"customer name         : "<<C_name<<endl;
        cout<<"customer phone no     : "<<phone_no<<endl;
    }
};
class Depository:protected Customer
{
    private:
      int account_no;
      int balance;
    protected:
        void setDeptrDetails(int accNo,int bln)
        {
            account_no=accNo;
            balance=bln;
        }
        void displayDptr()
        {
            cout<<"Customer A/C No     : "<<account_no<<endl;
            cout<<"Balance             : "<<balance<<endl;
        }
};


class Borrower:protected Depository
{
    private:
       int loan_no;
       int amount;
    public:
        void displayBrw()
        {
            displayCust();
            displayDptr();
            cout<<"--------------------------"<<endl;
            cout<<"Loan No           : "<<loan_no<<endl;
            cout<<"Loan amount       : "<<amount<<endl;
        }
        void setBAnkDetails()
        {
            long int ph,acc,bl;
            char n[10];
            fflush(stdin);
            cout<<"Enter customer name      : ";
            cin.getline(n,10);
            cout<<"Enter customer phone no  : ";
            cin>>ph;
            cout<<"Enter customer A/C no    : ";
            cin>>acc;
            cout<<"Enter Balance            : ";
            cin>>bl;
            cout<<"Enter Loan no            : ";
            cin>>loan_no;
            cout<<"Enter amount             : ";
            cin>>amount;

            setDeptrDetails(acc,bl);
            setCustDetails(ph,n);
        }
};

int main()
{
    Borrower b1,b2;
    cout<<"Enter first customer Details"<<endl;
    b1.setBAnkDetails();
    cout<<"Enter second customer Details"<<endl;
    b2.setBAnkDetails();
    b1.displayBrw();
    b2.displayBrw();
    getch();
    return 0;
}


