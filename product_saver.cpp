#include<iostream>
using namespace std;
//variable declared globally 
int optionsc1;
int optionsc2;
int optionsc3;
int optionsc4;
int DD1[10];
int DD2[10];
int DD3[10];
int MM1[10];
int MM2[10];
int MM3[10];
int YY1[10];
int YY2[10];
int YY3[10];
string produ[1000];
int count;
int count2;//there is problem in code answer will write when you add item 1 time if you add multiple time  there is error to remove this error we should take this
//select option on screen 1
void opsc1()
{
   cin>>optionsc1;
}
//print display one(main menu display)
void display1()
{
  system("cls");//it will clear screen before printing next thing just like clrscr in turbo c
    cout<<"\n\t\t\t|||||||||||||||||||Product Saver|||||||||||||||||||";
    cout<<"\n\n\n\n\t\t\t1)Product's You Have"<<"\t\t __________________";
    cout<<"\n\t\t\t2)Add New Product"<<"\t        | ATTENTION NEEDED ";
    cout<<"\n\t\t\t3)Saver"<<"\t\t\t        |                  ";
    cout<<"\n\t\t\t0)Exit"<<"\t\t\t        |                  ";
    cout<<"\t\t\t\t\t\t\t\t\t";
    cout<<"\n\t\t\t\tChoose Option:"; 
}
//display 2 (Products you have)
void display2()//return type of display should be void because it doesnt return any value
{   system("cls");
    cout<<"Products Name"<<"\t\t\tM.F.D(DD:MM:YYYY)"<<"\t\t\tE.X.P.(DD:MM:YYYY)";
    for(int i=0;i<=count;i++)
   {
    cout<<"\n"<<i+1<<")"<<produ[i]<<"\t\t\t"<<DD1[i]<<":"<<MM1[i]<<":"<<YY1[i]<<"\t\t\t"<<DD2[i]<<":"<<MM2[i]<<":"<<YY2[i];
   }; 
    cout<<"\nPress 0:If you wanted to go back to the main menu";
    cout<<"\n\nChoose Option:";
}
//select option on screen 2
void opsc2()
{
 cin>>optionsc2;
}
//display 3(add new products)
void display3()
{ system("cls");
  int n;
  cout<<"How many products do you wanted to add right now:";
  cin>>n;
  count=count+n;
  system("cls");
  for(int i=0;i<=n-1;i++)
  {
  cout<<"\n("<<i+1<<")";  
  cout<<"\nProduct Name:";
  cin>>produ[i];
  cout<<"\nM.F.D.(DD):";
  cin>>DD1[i];cout<<"M.F.D.(MM):";cin>>MM1[i];cout<<"M.F.D.(YYYY):";cin>>YY1[i];
  cout<<"\nE.X.P.(DD):";
  cin>>DD2[i];cout<<"E.X.P.(MM):";cin>>MM2[i];cout<<"E.X.P.(YYYY):";cin>>YY2[i];
  }
  cout<<"\nPress 0:For going back to home page";
  cout<<"\nChoose Option:";
}
//select option on screen 3
void opsc3()
{
 cin>>optionsc3;
}
void display4()
{
 system("cls");
  cout<<"Product's Name"<<"How Much Time Is  Left";
   for(int i=0;i<=count;i++)
   {
     //caluclation of difference from here on now
    //here a is for 1(mf);b for 2(ex);c for 3(left) 
    //and 1 for date;2 for month ;3 for year
    //overal if a1 is for date of fist(mfd)
    //if c3 third year(yy of days left)
    //for date--------------------
     int a1,b1,c1;
     a1=DD1[i];
     b1=DD2[i];
     if(b1>a1)
     {
       c1=b1-a1;
     }else{c1=a1-b1;}
     DD3[i]=c1;
       //for month--------------------
     int a2,b2,c2;
     a2=MM1[i];
     b2=MM2[i];
     if(b2>a2)
     {
       c2=b2-a2;
     }else{c2=a2-b2;}
     MM3[i]=c2;   
     //for year--------------------
     int a3,b3,c3;
     a3=YY1[i];
     b3=YY2[i];
     if(b3>a3)
     {
       c3=b3-a3;
     }else{c3=a3-b3;}
     YY3[i]=c3;
     //--------------------------
    cout<<"\n"<<i+1<<")"<<produ[i]<<"\t\t\t"<<DD3[i]<<":"<<MM3[i]<<":"<<YY3[i];
   };

  cout<<"\nPress 0:For going back to home page";
  cout<<"\n\nChoose Option:";
}
//select option on screen 4
void opsc4()
{
 cin>>optionsc4;
}
//from where compiler start reading program and finish it till return o;
int main()
{ 
   count=-1;
    do
    { 
      display1();
      opsc1();
      switch (optionsc1)
      {
        case 1://products you have
               display2();
               opsc2();
               break;
        case 2://add new product
              display3();
              opsc3();
              break;
        case 3://saver(shows days left for product to get expired)
              display4();
              opsc4();
              break;
        default:
              cout<<"Invalid Input!!!!\n";
              break;      
      } 
        
    } while (optionsc1!=0);
    system("cls");      
    cout<<"\n\n\n\n\n\t\t\t\tTHANK YOU!!!"; 
    return 0;
}