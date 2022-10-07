#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Item
{
    private:
       int item_no;
       float price;
       char name[10];
    protected:
        void setItem(int no,float p,char *n)
        {
            item_no=no;
            price=p;
            strcpy(name,n);
        }
        void displayItem()
        {
            cout<<"Item name : "<<name<<endl;
            cout<<"Item no : "<<item_no<<endl;
            cout<<"Item price : "<<price<<endl;
        }
        float getPrice(){return price;}

};

class Discounted_item:protected Item
{
   private:
      int discount;
      float Discounted_price,total_price;
   protected:
     void getDiscount(int d)
     {
        discount=d;
     }
   public:
    void setItemDetails();
    void display();
    float getTotalPrice()
    {
        return total_price;
    }
    float getDiscountedPrice()
    {
        return Discounted_price;
    }

};
void Discounted_item::setItemDetails()
{
    float p,dp,i;
    int i_no,d;
    char name[10];
    cout<<"Enter item name : ";
    fflush(stdin);
    cin.getline(name,10);
    cout<<"Enter item no : ";
    cin>>i_no;
    cout<<"Enter item price : ";
    cin>>p;
    cout<<"Enter Discount percent : ";
    cin>>discount;
    cout<<"--------------------------"<<endl;
    setItem(i_no,p,name);
    dp=getPrice();
    i=dp*discount/100.0;
    total_price=dp-i;
    Discounted_price=i;
}
void Discounted_item::display()
{

    cout<<endl<<endl;
    displayItem();
    cout<<"Discount percent : "<<discount<<endl;
    cout<<"Discounted price : "<<total_price<<endl<<endl;
    cout<<"--------------------"<<endl;
}
int main()
{
   int n;
   cout<<"Enter how many items  you want to enter? :";
   cin>>n;
   Discounted_item d[n];
   for(int i=0;i<n;i++)
   {
       d[i].setItemDetails();
   }
   cout<<"first item";
   d[0].display();
   cout<<"second item";
   d[1].display();
   cout<<endl;
   cout<<"Total price : "<<d[0].getTotalPrice()+d[0].getTotalPrice()<<endl;
   cout<<"Total discount : "<<d[1].getDiscountedPrice()+d[1].getDiscountedPrice()<<endl;
   getch();
   return 0;

}
