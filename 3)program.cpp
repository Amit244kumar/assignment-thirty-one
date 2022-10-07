#include<conio.h>
#include<iostream>

using namespace std;

class subject
{
    private:
       int sub1,sub2,sub3;
    protected:
        int getSub1(){return sub1;}
        int getSub2(){return sub2;}
        int getSub3(){return sub3;}
    public:
        void setSub(int s1,int s2,int s3)
        {
            sub1=s1;
            sub2=s2;
            sub3=s3;
        }
};

class Mark:public subject
{
   public:
      int getTotalMark()
      {
          return this->getSub1()+this->getSub2()+this->getSub3();
      }
};
class percent:public Mark
{
public:
    float getPer()
    {
        return (this->getTotalMark()/300.0)*100.0;
    }
};

int main()
{
    percent p1;
    p1.setSub(23,45,65);
    cout<<"The percentages of three subject"<<endl<<p1.getPer();
    getch();
    return 0;

}
