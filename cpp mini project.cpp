#include<iostream>
#include<fstream>
using namespace std;
class bill
{
      public:
             bill();
             void get();
             void display();
             void search();
             void modify();
      private:
              int billno;
              int qty;
              float itemrate;
              string itemname;
};
bill::bill()
{
            billno=30;
            itemname="Food";
            qty=1;
            itemrate=400.4;
}
void bill::get()
{
     fstream file;
     cout<<"Enter billno,qty,itemrate,itemname:"<<endl;
     cin>>billno>>qty>>itemrate>>itemname;
     file.open("billdetails.bin",ios::app | ios::out);
     file<<" "<<billno<<" "<<qty<<" "<<itemrate<<" "<<itemname<<"\n";
     file.close();
}
void bill::display()
{
     fstream file;
     file.open("billdetails.bin",ios::in);
     if(!file)
     {
              cout<<"no data is present";
              file.close();
     }
     else
     {
              file>>billno>>qty>>itemrate>>itemname;
              while(!file.eof())
              {
                                cout<<"billno:"<<billno<<endl;
                                cout<<"qty:"<<qty<<endl;
                                cout<<"itemrate:"<<itemrate<<endl;
                                cout<<"itemname:"<<itemname<<endl;
                                file>>billno>>qty>>itemrate>>itemname;
              }
     }
     file.close();
}
void bill::modify()
{
     fstream file,file1;
     int bill_no;
     int found=0;
     file.open("billdetails.bin",ios::in);
     if(!file)
     {
              cout<<"no data is present";
              file.close();
     }
     else
     {
         cout<<"\n Enter the billno that you want to modify:";
         cin>>bill_no;
         file1.open("billno",ios::app | ios::out);
         file>>billno>>qty>>itemrate>>itemname;
         while(!file.eof())
         {
                           if(bill_no!=billno)
                           {
                                              file1<<" "<<billno<<" "<<qty<<" "<<itemrate<<" "<<itemname<<"\n";
                           }
                           else
                           {
                               cout<<"Enter billno,qty,itemrate,itemname:";
                               cin>>billno>>qty>>itemrate>>itemname;
                               file1<<" "<<billno<<" "<<qty<<" "<<itemrate<<" "<<itemname<<"\n";
                               found++;
                           }
         file>>billno>>qty>>itemrate>>itemname;
         if(found==0)
         {
                     cout<<"not found";
         }
         }
         file1.close();
         file.close();
         remove("billdetails.bin");
         rename("bill.bin","billdetails.bin");
     }
}
void bill::search()
{
     fstream file;
     int found=0;
     file.open("billdetails.bin",ios::in);
     if(!file)
     {
              cout<<"\n No data is present";
     }
     else
     {
         int bill_no;
         cout<<"Enter billno that you want to serach:";
         cin>>bill_no;
         file>>billno>>qty>>itemrate>>itemname;
         while(!file.eof())
         {
                            if(bill_no==billno)
                            {
                                               cout<<"billno:"<<billno<<endl;
                                               cout<<"qty:"<<qty<<endl;
                                               cout<<"itemrate:"<<itemrate<<endl;
                                               cout<<"itemname:"<<itemname<<endl;
                                               found++;
                            }
                            file>>billno>>qty>>itemrate>>itemname;
         }
         if(found==0)
         {  
                 cout<<"\nbillno not found";
         }
         file.close();
     }
}
main()
{
      char x;
      int ch;
      do
      {
          cout<<"\n1.Enter Details\n2.display details\n3.modify detais\n4.search details\n5.Exit";
          cout<<"\nEnter your choice:";
          cin>>ch;
          switch(ch)
          {
          case1:
          {
                do
                {
                    bill b;
                    b.get();
                    cout<<"Add another billno(Y,N)";
                    cin>>x;
                }while(x=='y' || x=='Y');
                break;
          }
          case2:
          {
                bill b1;
                b1.display();
                break;
          }
          case3:
          {
                bill b2;
                b2.modify();
                break;
          }
          case4:
          {
                bill b3;
                b3.search();
                break;
          }
          case5:
          {
                cout<<"Exit";
                break;
          }
          }
      }while(ch!=5);
      return 0;
} 
                                               
             
                               
     
              
     
    
                           
