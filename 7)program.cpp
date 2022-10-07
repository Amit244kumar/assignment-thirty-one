#include<conio.h>
#include<iostream>

using namespace std;

class employee
{
    private:
       int emp_no;
       char *ptr;
    protected:
        void setEmpDetails(int code,char *a)
        {
            int l;
            l=strlen(a);
            ptr=new char[l];
            strcpy(ptr,a);
            emp_no=code;

        }
        void displayE()
        {
            cout<<"----------------------"<<endl;
            cout<<"Employee number    :  "<<emp_no<<endl;
            cout<<"Employee name      :  "<<ptr<<endl;
        }

};

class Working:protected employee
{
   private:
      int salary;
      char status[10];
   public:
        void setFullTimeDetails(int c,char *name,int sa,char st)
        {
            setEmpDetails(c,name);
            salary=sa;
            if(st=='f'||st=='F')
                strcpy(status,"full time");
            else
                strcpy(status,"part Time");
        }
        void displayF()
        {
            displayE();
            cout<<"salary           :  "<<salary<<endl;
            cout<<"status           :  "<<status<<endl;
            cout<<"--------------------"<<endl;
        }
};


int main()
{

}
