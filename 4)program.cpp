#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Person
{
    private:
      char  name[10],address[10];
      long int phone_no;
    protected:
        void perDetails(char *n,char *a,long int no)
        {
            strcpy(name,n);
            strcpy(address,a);
            phone_no=no;
        }
        void perDisplay()
        {
            cout<<"Employee name : "<<name<<endl;
            cout<<"Employee address : "<<address<<endl;
            cout<<"Employee phone_no : "<<phone_no<<endl;
        }
        char* getName(){return name;}
};
class employee:protected Person
{
    private:
      int eno;
    protected:
        void setEno(int n)
        {
            eno=n;

        }
        void displayEno()
        {
            cout<<"Employee no : "<<eno<<endl;
        }
};

class manager:protected employee
{
    private:
       char designation[15],department_name[15];
       float B_salary;
    protected:
        void managerDetails(char *d,char *dn,float s)
        {
            strcpy(designation,d);
            strcpy(department_name,dn);
            B_salary=s;
        }
    public:
      void setDetails();
      void displayManager()
      {
          this->perDisplay();
          this->displayEno();
          cout<<"employee designation : "<<designation<<endl;
          cout<<"employee department : "<<department_name<<endl;
          cout<<"employee basic salary : "<<B_salary<<endl;
      }
      void compareManager(manager m1)
      {
          if(B_salary>m1.B_salary)
          {
              cout<<"Manager with higher salary is : "<<B_salary<<endl;
              cout<<"And, manage name is : "<<getName();
          }
          else
          {
              cout<<"Manager with higher salary is : "<<m1.B_salary<<endl;
              cout<<"And, manage name is : "<<m1.getName()<<endl;
          }
      }
};
void manager::setDetails()
{
    char nam[10],ad[10],design[15],de_name[15];
    int n;
    float sa;
    long int no;
    cout<<endl<<"Enter Details of manager"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Enter Employee No. : ";
    cin>>n;
    cout<<"Enter name : ";
    cin>>nam;
    cout<<"Enter Address : ";
    cin>>ad;
    cout<<"Enter phone no : ";
    cin>>no;
    cout<<"Enter designation : ";
    fflush(stdin);
    cin.getline(design,15);
    cout<<"Enter department name : ";
    fflush(stdin);
    cin.getline(de_name,15);
    cout<<"Enter Basic salary : ";
    cin>>sa;
    fflush(stdin);
    this->managerDetails(design,de_name,sa);
    this->setEno(n);
    this->perDetails(nam,ad,no);
}

int main()
{
    int n;
    cout<<"How many manager you want to enter? :";
    cin>>n;
    manager m[n];

    for(int i=0;i<n;i++)
    {
        m[i].setDetails();
    }
    cout<<endl<<"first manager details"<<endl;
    m[0].displayManager();
    cout<<endl<<"second manager details"<<endl;
    m[1].displayManager();
    cout<<endl<<endl<<endl;
    m[0].compareManager(m[1]);
    getch();
    return 0;

}
