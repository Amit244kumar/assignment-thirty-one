#include<conio.h>
#include<iostream>

using namespace std;

class Student
{
    private:
       int roll_no;
       char name[10];
    protected:
        void setStudentDetails();
        void displayStDetails()
        {
            cout<<"Roll no.              : "<<roll_no<<endl;
            cout<<"Student name          : "<<name<<endl<<endl;
        }

};
void Student::setStudentDetails()
{
    cout<<"Enter Roll no               : ";
    cin>>roll_no;
    cout<<"Enter Student name          : ";
    fflush(stdin);
    cin.getline(name,10);
    cout<<endl;
}

class StudentExam:protected Student
{
    private:
      int Subject[6];
    protected:
        void setSubjectMarks();
        void DisplayExamDetails();
        int getSubSum()
        {
            int s=0;
            for(int i=0;i<6;i++)
            {
                s+=Subject[i];
            }
            return s;
        }
};
void StudentExam::setSubjectMarks()
{
    for(int i=0;i<6;i++)
    {
        cout<<"Enter Mark for Subject "<<i+1<<"    : ";
        cin>>Subject[i];
    }
    cout<<endl<<endl;
}
void StudentExam::DisplayExamDetails()
{
    for(int i=0;i<6;i++)
    {
         cout<<"Mark of student "<<i+1<<" : "<<Subject[i]<<endl;
    }
}

class StudentResult:protected StudentExam
{
    private:
      int per,totalmark;
    public:
        void SetStudent()
        {
            setStudentDetails();
            setSubjectMarks();
            per=(getSubSum()*100)/600;
            totalmark=getSubSum();
        }
        void displayResult()
        {
            displayStDetails();
            DisplayExamDetails();
            cout<<endl;
            cout<<"Total Marks       : "<<totalmark<<endl;
            cout<<"Total percentage  : "<<per<<endl<<endl<<endl;
        }
};

int main()
{
    int n;
    cout<<"Enter no. of Student you want? : ";
    cin>>n;
    StudentResult  s1[n];
    for(int i=0;i<n;i++)
    {
        s1[i].SetStudent();
    }
    for(int i=0;i<n;i++)
    {
        s1[i].displayResult();
    }
    getch();
    return 0;
}
