#include<conio.h>
#include<iostream>

using namespace std;

class Worker
{
    private:
       int salary,code;
       char name[10];
    protected:
        void setWorkerInfo()
        {

            cout<<endl<<"-------------------------"<<endl;
            cout<<"Enter code    : ";
            cin>>code;
            cout<<"Enter name    : ";
            fflush(stdin);
            cin.getline(name,10);
            cout<<"Enter salary  : ";
            cin>>salary;
        }
        void DisplayWorkerInfo()
        {
            cout<<endl<<"---------------------------"<<endl;
            cout<<"Manager information"<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"code             : "<<code<<endl;
            cout<<"Name             : "<<name<<endl;
            cout<<"salary           : "<<salary<<endl;
        }
        int getSalary(){return salary;}

};

class Officer
{
   private:
     int DA,HRA;
   protected:
    void setOfficerInfo()
    {
        cout<<"Enter DA        : ";
        cin>>DA;
        cout<<"Enter HRA       : ";
        cin>>HRA;
    }
    void displayOfficerInfo()
    {
        cout<<"DA               : "<<DA<<endl;
        cout<<"HRA              : "<<HRA<<endl;
    }
    int getDA(){return DA;}
    int getHRA(){return HRA;}

};

class Manager:protected Worker,protected Officer
{
    private:
       int TA,gross_salary;
    public:
        void setManager()
        {
            setWorkerInfo();
            setOfficerInfo();
            TA=(getSalary()*10)/100;
            gross_salary=getSalary()+getDA()+getHRA()+TA;
        }
        void displayManager()
        {
            DisplayWorkerInfo();
            displayOfficerInfo();
            cout<<"TA               : "<<TA<<endl;
            cout<<"Gross Salary     : "<<gross_salary<<endl;
        }
};

int main()
{
    int n;
    cout<<"Enter manager count : ";
    cin>>n;
    Manager m1[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter worker infomation for "<<i+1;
        m1[i].setManager();
    }
    for(int i=0;i<n;i++)
    {
        m1[i].displayManager();
    }

    getch();
    return 0;
}
