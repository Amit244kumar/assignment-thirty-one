#include<conio.h>
#include<iostream>

using namespace std;

class Add
{
   private:
     int n1,n2;
   protected:
      int getn1(){return n1;}
      int getn2(){return n2;}
   public:
    void setData(int a,int b)
    {
        n1=a;
        n2=b;
    }
};

class Sum:public Add
{
    public:
      void display()
      {
          cout<<this->getn1()+this->getn2();
      }

};


int main()
{
    Sum s1;
    s1.setData(3,4);
    s1.display();
    getch();
    return 0;

}
