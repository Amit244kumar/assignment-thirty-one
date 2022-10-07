#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;
class Float;
class Integer
{
   private:
      char name[10];
   public:
    void setInteger(char *a)
    {
        strcpy(name,a);
    }
    void display()
    {
        cout<<"I am "<<name<<endl;
    }
    friend void exchange(Float&,Integer&);
};

class Float
{
    private:
       char name[10];
    public:
        void setFloat(char *n)
        {
            strcpy(name,n);
        }
        void display()
        {
            cout<<"I am "<<name<<endl;
        }
        friend void exchange(Float&,Integer &i);

};

void exchange(Float &r,Integer &i)
{
    char f[10];
    strcpy(f,i.name);
    strcpy(i.name,r.name);
    strcpy(r.name,f);
}

int main()
{
    Integer i1;
    Float f1;
    i1.setInteger("int");
    f1.setFloat("float");
    i1.display();
    f1.display();
    exchange(f1,i1);
    i1.display();
    f1.display();
    getch();
    return 0;

}
