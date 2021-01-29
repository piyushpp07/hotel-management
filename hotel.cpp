//source code
#include <iostream>
#include<stdio.h>
#include <fstream>
#define single_room 1000
#define Dormatiory 800
#define Double_Bed 1500
#define Luxary 2000


using namespace std;
class Hotel
{
    public:

    virtual void Room()=0;
    virtual void calculatePrice()=0;
    virtual void Save()=0;
    virtual void Print()=0;
};
class Bill :public Hotel
{ string Name;
int days,total_price=0,count_dor=0,count_sin=0,count_dou=0,count_lux=0,flagdor=0,flagsin=0,flagdou=0,flaglux=0;

public:
      Bill(int day_no,string n)
    {
        days=day_no;
        Name =n;
    }
    void Room();
    void Save();
    void Print();
    void calculatePrice();
};

void Bill ::Room()
{    int no;
    cout<<"How many kind rooms\t:";
    cin>>no;
    int *roomtype =new int[no];
    cout<<"\n Dormatiory press 1\t single_room press 2\t double bed press 3 \t Luxary press 4\n";
    for (int i=0 ;i<no ;i++)
    {
        cin>>roomtype[i];
    }
    for (int i=0 ;i<no ;i++)
    {
        if(roomtype[i]==1)
        { flagdor++;
          count_dor+=Dormatiory;
        }
        else if(roomtype[i]==2)
        { flagsin++;
            count_sin+=single_room;
        }

        else if(roomtype[i]==3){
            flagdou++;
            count_dou+=Double_Bed;
        }
        else if(roomtype[i]==4)
        {    flaglux++;
            count_lux+=Luxary;
        }
      }
}
  void Bill ::calculatePrice(){
  total_price =days*(count_dor+count_sin+count_dou+count_lux);
  }
void Bill ::Save()
  {
      ofstream of("bill.txt");
      of<<"\t\t\tBILL\n\n";
      of<<"\tCostumer Name :"<<Name<<endl;
      of<<"\tType      "<<"\tQuantity"<<"\tPrice"<<endl;
      of<<"\tDormatiory"<<"\t"<<flagdor<<"\t"<<count_dor<<endl;
      of<<"\tSingle_Room"<<"\t"<<flagsin<<"\t"<<count_sin<<endl;
      of<<"\tDouble_Room"<<"\t"<<flagdou<<"\t"<<count_dou<<endl;
      of<<"\tLuxary_Room"<<"\t"<<flaglux<<"\t"<<count_lux<<endl;
      of<<"\t\t"<<"Total:"<<total_price;
      }
void Bill :: Print()
      {

      cout<<"\t\t\tBILL\n\n";
      cout<<"\tCostumer Name :"<<Name<<endl;
      cout<<"\tType      "<<"\tQuantity"<<"\tPrice"<<endl;
      cout<<"\tDormatiory"<<"\t"<<flagdor<<"\t\t"<<count_dor<<endl;
      cout<<"\tSingle_Room"<<"\t"<<flagsin<<"\t\t"<<count_sin<<endl;
      cout<<"\tDouble_Room"<<"\t"<<flagdou<<"\t\t"<<count_dou<<endl;
      cout<<"\tLuxary_Room"<<"\t"<<flaglux<<"\t\t"<<count_lux<<endl;
      cout<<"\t\t"<<"Total:"<<total_price;
      }

int main()
{   int days;
    string Name;

    cout<<"Hotel Management System:\t";
    cout<<"\nHow many days you want to stay:\t";

    cin>>days;
    cout<<"Enter the name of costumer:\t";
    cin>>Name;
    system("cls");
    Bill h1(days,Name);
    h1.Room();
    h1.calculatePrice();
    system("cls");
    h1.Save();
    h1.Print();
     int key;
    cout<<"\npress e and  then enter to exit your bill is saved as bill.txt\n";
    cin>>key;
    return 0;
}
