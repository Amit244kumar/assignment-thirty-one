#include<conio.h>
#include<iostream>
#include<string.h>

using namespace std;

class Person
{
    private:
      int age;
      char name[20];
    public:
        void setAge(int a){age=a;}
        void setName(char *n){strcpy(name,n);}
        int getAge(){return age;}
        char* getName(){return name;}
};

class Employee:public Person
{
   private:
     int empid;
     float salary;
   public:
    void setEmpid(int i){empid=i;}
    void setSalary(float s){salary=s;}
    int getEmpid(){return empid;}
    float getSalary(){return salary;}
};

int main()
{
    Employee e1;
    e1.setAge(25);
    e1.setName("Rohit negi");
    e1.setEmpid(5);
    e1.setSalary(50000.3);
    cout<<"Employee details"<<endl;
    cout<<"Employee age    : "<<e1.getAge()<<endl;
    cout<<"Employee name   : "<<e1.getName()<<endl;
    cout<<"Employee id     : "<<e1.getEmpid()<<endl;
    cout<<"Employee salary : "<<e1.getSalary()<<endl;
    getch();
    return 0;
}
