#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>

static int n=-3; //n is the product no. counter declared globally to access and modify from any function

class product             //class for products........
{char name[30];
 char code[6];
 float price;
 int quantity;
 char category[20];

 public:
   char cname[30];
   char ccode[6];
   char ccategory[20];
   int total;

 void getval()
     {int s;
      cout<<"\n Enter the name of the product(max:30 letters):";
      do{
         gets(name);
         s=strlen(name);
         if((s<1)||(s>31))
          {cout<<"\n Enter a valid name(within 30 letters):";}
        }while((s<1)||(s>31));
      cout<<"\n Enter the code of the product(6 characters):";
      do{
         gets(code);
         s=strlen(code);
         if(s!=6)
          {cout<<"\n Enter a valid code(6 characters):";}
        }while(s!=6);
      cout<<"\n Enter price:Rs.";
      cin>>price;
      cout<<"\n Enter the quantity of product in stock:";
      cin>>quantity;
      cout<<"\n Enter the category of the product(max:20 letters)";
      do{
         gets(category);
         s=strlen(category);
         if((s<1)||(s>21))
          {cout<<"\n Enter a valid category(within 20 letters):";}
        }while((s<1)||(s>21));
     }

 void putval()
     {
      cout<<"\n\n Name of the product: "<<name;
      cout<<"\n Code of the product: "<<code;
      cout<<"\n Price of the product:Rs. "<<price;
      cout<<"\n quantity left in stock: "<<quantity;
      cout<<"\n category of the product: "<<category;
     }
 void rname()
     {strcpy(cname,name);}
 void rcode()
     {strcpy(ccode,code);}
 void rcategory()
     {strcpy(ccategory,category);}
 void nname(char nname[30])
     { strcpy(name,nname);}
 void ncode(char ncode[30])
     { strcpy(code,ncode);}
 void ncatag(char cat[30])
     { strcpy(category,cat);}
 void nprice(float nprice)
     { price=nprice;}
 void nquant(float nquantity)
     { quantity=nquantity;}
 int rprice()
     {return price;}
 int rquantity()
     {return quantity;}
 int net()
     {total=price*quantity;}

 void disp_2()
     {int sz,c,i;
      sz=strlen(name);
      c=30-sz;
      cout<<"\n  "<<name;
      for(i=0;i<c;i++)
      {cout<<" ";}
      sz=strlen(code);
      c=6-sz;
      cout<<"\t\t"<<code;
      for(i=0;i<c;i++)
      {cout<<" ";}
      cout<<"\t\t   ";
      if(quantity<1)
      {cout<<"OUT OF STOCK";}
      else
      {cout<<quantity;}
      }
int putval2()
    {int sz,c,i;
      sz=strlen(name);
      c=30-sz;
      cout<<"  "<<name;
      for(i=0;i<c;i++)
      {cout<<" ";}
      cout<<price;
      if(price<10)
      {cout<<" ";}
      cout<<"  ";
      if(quantity<1)
      {cout<<"OUT OF STOCK";
      return 0;}
      else
      {return 1;}
    }
int putval3(int x)
    {int pr=0;
     cout<<"  ";
     if(x<=quantity)
     {quantity=quantity-x;
      cout<<"             "<<x*price;
      return (x*price);}
     if(x>quantity)
     {x=quantity;
      cout<<"("<<x<<")            "<<x*price;
      quantity=0;
      return (x*price);}
     }

 }s[1000];


class acc         //class for account..........
 {char name[20];
  int password[10];
  int sz;

  public:

  void putname()
       {cout<<name;}

  void getacc()
      {int x,s;
       char pw[10];
       cout<<"\n Enter the name of administrator :";
       do{
          gets(name);
          s=strlen(name);
          if((s<1)||(s>21))
           {cout<<"\n Enter a valid name(within 20 letters):";}
         }while((s<1)||(s>21));
       cout<<"\n Enter the password[not recoverable] :";
       do{
         gets(pw);
         sz=strlen(pw);
         if((sz<1)||(sz>11))
          {cout<<"\n Enter a valid password(within 10 letters):";}
        }while((sz<1)||(sz>11));
        for(x=0;x<sz;x++)
        {password[x]=pw[x];}
        clrscr();
     }

    //------------------------------------------------------------

  int pw_check()                     //function to check the password......
    {char pw[10];
     int f=4;
     int r,i,z,k,x;
     char pg[10],ch;
     ch='z';
      do{
         cout<<"\nEnter the password____";
         int lp;
         for(lp=0;lp<sz;lp++)
          {pg[lp]=getch();
           if(pg[lp]=='\b')
              {if(lp!=0)
               {cout<<"\b \b";
                lp--;}
              else
               {cout<<"";}
               lp--;}
           else
            {cout<<"*";}
           }
           pg[lp]='\0';
        for(x=0;x<sz;x++)
        {pw[x]=password[x];}
        pw[x]='\0';
        r=strcmp(pg,pw);
       if(r==0)
       {cout<<"   congo.. right password";
        for(k=0;k<=1000;k++);
        return 1;
       }
       else
       {cout<<"\n\n\t\tpassward invalid!!!!\n";
      f--;
       if(f==0)
        {cout<<"\n sorry...\n  we can't give you any more chance...\n\n\t!!PRESS ANY KEY TO CONTINUE AS GUEST!!\n\n\n";
         getch();
         return 0;}
         cout<<"\n\twant to try again("<<f<<" attempts left)??___";
         for(z=0;z<1000;z++)
           {ch=getche();
            if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
             {z=1000;}
            else
             {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
          }}
        if(ch=='n'||ch=='N')
         {return 0;}
    }while(ch=='y'||ch=='Y');
   }
  }p;

  //------------------------------------------------------------------------------

class info                //class for info of the shop..................
{char name[20];
 char add[50];
 char ph[10];

 public:

  void getvalue()
       {int s;
       clrscr();
      cout<<"\n Enter the name of the shop(max:20 letters):";
      do{
         gets(name);
         s=strlen(name);
         if((s<1)||(s>21))
          {cout<<"\n Enter a valid name(within 20 letters):";}
        }while((s<1)||(s>21));
      cout<<"\n Enter the address of the shop(max:50 characters):";
      do{
         gets(add);
         s=strlen(add);
         if((s<1)||(s>50))
          {cout<<"\n Enter a valid address(within 50 characters):";}
        }while((s<1)||(s>50));
      cout<<"\n Enter the phone number of the shop:";
      int f=1;
      do{ f=1;
         gets(ph);
         s=strlen(ph);
         if((s==8)||(s==10))
          {if((ph[0]=='1')||(ph[0]=='2')||(ph[0]=='3')||(ph[0]=='7')||(ph[0]=='8')||(ph[0]=='9'))
           {for(int i=1;i<s;i++)
            {if((ph[i]<48)||(ph[i]>57))
              {f=0;}
            }
           }
           else
           {f=0;}
          }
         else
          {f=0;}
      if(f==0)
      {cout<<"\n Enter a valid phone number :";}
        } while(f==0);
      }
  void putvalue()
     {cout<<"\n\t\t\t"<<name;
      cout<<"\n\t\t"<<add;
      cout<<"\n\t\t\t\t Call us at :"<<ph<<"\n";
      for(int x=0;x<160;x++)
      {cout<<"_";}
      cout<<"\n";
     }
  }shop;


  //--------------------------------------------------------------------------

 void dispw()                                                                      //function for welcome screen...
{int i;
 char ch=219,ch1=240;
 clrscr();
 cout<<"\n\n\n";
 cout<<"\n\t\t "<<ch<<"   "<<ch<<" "<<ch<<ch<<ch<<ch<<" "<<ch<<"    "<<ch<<ch<<ch<<" "<<ch<<ch<<ch<<ch<<" "<<ch<<ch<<" "<<ch<<ch<<" "<<ch<<ch<<ch<<ch<<" ";
 cout<<"\n\t\t "<<ch<<"   "<<ch<<" "<<ch<<"    "<<ch<<"    "<<ch<<"   "<<ch<<"  "<<ch<<" "<<ch<<" "<<ch<<" "<<ch<<" "<<ch;
 cout<<"\n\t\t "<<ch<<"   "<<ch<<" "<<ch<<ch<<ch<<"  "<<ch<<"    "<<ch<<"   "<<ch<<"  "<<ch<<" "<<ch<<"   "<<ch<<" "<<ch<<ch<<ch;
 cout<<"\n\t\t "<<ch<<" "<<ch<<" "<<ch<<" "<<ch<<"    "<<ch<<"    "<<ch<<"   "<<ch<<"  "<<ch<<" "<<ch<<"   "<<ch<<" "<<ch;
 cout<<"\n\t\t "<<ch<<ch<<" "<<ch<<ch<<" "<<ch<<ch<<ch<<ch<<" "<<ch<<ch<<ch<<ch<<" "<<ch<<ch<<ch<<" "<<ch<<ch<<ch<<ch<<" "<<ch<<"   "<<ch<<" "<<ch<<ch<<ch<<ch<<" ";
 cout<<"\n\n\n\t\t Program starting up";
 for(i=0;i<=150000000;i++)
  {if(i%10000000==0)
    cout<<"_";}
 cout<<"\n Press any key to continue...";
 getch();
}
//--------------------------------------------------------------------------------------
 int choose()                                                             //funtion to choose account type...
 {int ac,r;
  do{clrscr();
     cout<<"\n\n\t Choose your account type___\n";
     cout<<"\t1) ";
     p.putname();
     cout<<"[password protected]\n\t2) Guest";
     cout<<"\n Enter the type of account to continue_";
     cin>>ac;
     }while((ac<0)||(ac>2));
   if(ac==1)
   {r=p.pw_check();
    if(r==1)
    {return 1;}
   }
   else
   {return 0;}
  }

  //-----------------------------------------------------------------------------

  void counter()
  {int i;                                                            //function to take input from user...........

   do{clrscr();
      cout<<"enter the no. of product you want to register?:[up to 1000]___";
      cin>>n;}while((n<0)||(n>1000));
   for(i=0;i<n;i++)
   {cout<<"\n\nEnter the info of "<<(i+1)<<"th product";
    s[i].getval();}
   }
 //------------------------------------------------------------------------------
void load()                                                         //function to load values
  {
   ifstream acc;
   acc.open("acc.scb", ios::in|ios::binary);
   if(acc.bad())
    {p.getacc();}
   if(acc.good())
    {acc.read((char*)&p,sizeof(p));}
   acc.close();

   ifstream sp;
   sp.open("shop.scb", ios::in|ios::binary);
   if(sp.bad())
    {shop.getvalue();}
   if(sp.good())
    {sp.read((char*)&shop,sizeof(shop));}
   sp.close();
  ifstream nfin;
    nfin.open("info.scb", ios::in);
     nfin>>n;
    nfin.close();

   if(n>=0)
    {ifstream fin1;
    fin1.open("data.scb", ios::in|ios::binary);
    if(fin1.good())
     {for(int i=0;i<n;i++)
      {fin1.read((char*)&s[i],sizeof(s[i]));}
     }
    else
     {counter();}
     fin1.close();
    }
   else
    {counter();}

   }

 //--------------------------------------------------------------------------

 void save()                                                //function to save vales.........
 {ofstream acc;
   acc.open("acc.scb", ios::out|ios::binary);
    {acc.write((char*)&p,sizeof(p));}
   acc.close();

   ofstream sp;
   sp.open("shop.scb", ios::out|ios::binary);
    {sp.write((char*)&shop,sizeof(shop));}
   sp.close();

   ofstream nfin;
    nfin.open("info.scb", ios::out);
     nfin<<n;
    nfin.close();

    ofstream fin1;
    fin1.open("data.scb", ios::out|ios::binary);
     {for(int i=0;i<n;i++)
      {fin1.write((char*)&s[i],sizeof(s[i]));}
     }
     fin1.close();
    }


 //--------------------------------------------------------------------------
void search()
    {char src[100],ch;
     int chs,q=-1;
     int ab,cd,rst;
	  int pp=0;
	  int f=3;
 	  int sz=0,sz1=0;
		clrscr();
 		cout<<"\nWithin which part do you want to search?\n";
 		cout<<"\t1)Name\n\t2)Code\n\t3)Category";
      cout<<"\nEnter the option number:";
      do{
         cin>>chs;
         if((chs<1)||(chs>3))
         {cout<<"\nEnetr a valid option";}
        }while((chs<1)||(chs>3));
	int k,l;
		cout<<"\n Enter the portion to be searched___";
		gets(src);
		q=0;                                                                //main searching codes starts here!!.......
      cout<<"searching.....";
   if(chs==1)
       {for(k=0;k<n;k++)
         { s[k].rname();
          sz=strlen(s[k].cname);
			 sz1=strlen(src);
 			 rst=-1;
			 for(l=0;l<=sz;l++)
			 {if(src[0]==s[k].cname[l])
           { ab=l;
            cd=ab+sz1;
            sz1=0;
            f=0;
            for(ab=l,pp=0;ab<cd;ab++,pp++)
             {if(src[pp]!=s[k].cname[ab])
              { f=1;}
             }
             if(f==0)
            {rst++;}}
           }
       if(rst>=0)
       {cout<<"\n product no."<<(k+1)<<"___"<<s[k].cname;
      q=1;
      f=1;}
         }}
   if(chs==2)
       {for(k=0;k<n;k++)
         {s[k].rcode();
          sz=strlen(s[k].ccode);
			 sz1=strlen(src);
 			 rst=-1;
			 for(l=0;l<=sz;l++)
			 {if(src[0]==s[k].ccode[l])
           { ab=l;
            cd=ab+sz1;
            sz1=0;
            f=0;
            for(ab=l,pp=0;ab<cd;ab++,pp++)
             {if(src[pp]!=s[k].ccode[ab])
              { f=1;}
             }
             if(f==0)
            {rst++;}}
           }
        if(rst>=0)
        {cout<<"\n product no."<<(k+1)<<"___"<<s[k].ccode;
         q=1;
         f=1;}
        } }
   if(chs==3)
       {for(k=0;k<n;k++)
         {s[k].rcategory();
          sz=strlen(s[k].ccategory);
			 sz1=strlen(src);
 			 rst=-1;
			 for(l=0;l<=sz;l++)
			 {if(src[0]==s[k].ccategory[l])
           { ab=l;
            cd=ab+sz1;
            sz1=0;
            f=0;
            for(ab=l,pp=0;ab<cd;ab++,pp++)
             {if(src[pp]!=s[k].ccategory[ab])
              { f=1;}
             }
              if(f==0)
            {rst++;}}
           }
        if(rst>=0)
       {cout<<"\n product no."<<(k+1)<<"___"<<s[k].ccategory;
      q=1;
      f=1;}
         }}

  if(q==0)
  {cout<<"\nTry again...no record found";}
   }

   //----------------------------------------------------------------------------
                                                                                //case 2.....................
void case_2()
   {      char src[6];
          int  q=0;
	       int f=3,m;
          int w;
           {cout<<"\nEnter the code to delete: ";
            gets(src);
            int rst=1;
            if(strlen(src)==6)
            {
             {for(int k=0;k<n;k++)
              {rst=1;
               s[k].rcode();
               for(m=0;m<6;m++)
                {if(src[m]!=s[k].ccode[m])
                 {rst=0;}}
           if(rst==1)
            {q=1;
             f=1;
             w=k;
             k=n;}
           } }
           if(rst==1)
            {cout<<"\nDetails of product no."<<(w+1)<<" which is to be deleted___";
             s[w].putval();
             for(;w<n;w++)
             {s[w+1].rname();
              s[w+1].rcode();
              s[w+1].rcategory();
              s[w].nname(s[w+1].cname);
              s[w].ncode(s[w+1].ccode);
              float lprice;
              lprice=s[w+1].rprice();
              s[w].nprice(lprice);
              int lquant;
              lquant=s[w+1].rquantity();
              s[w].nquant(lquant);
              s[w].ncatag(s[w+1].ccategory);}
              cout<<"\n\t\tIS NOW DELETED !\n\n";
              q=1;
              f=1;
              n--;}
           } }
          if(q==0)
            {cout<<"\ncode no."<<src<<" is invalid.";}
            }
//-------------------------------------------------------------------------------
void case_3()                                                                    //case 3..........................
   {int chs;
    char ch;
   do{
    clrscr();
    cout<<"\n which portion to edit :";
    cout<<"\n 1) Name";
    cout<<"\n 2) Code";
    cout<<"\n 3) Price";
    cout<<"\n 4) Quantity";
    cout<<"\n 5) Category";
    cout<<"\n Enter the option number:";
    cin>>chs;}while((chs<0)||(chs>5));

        {char src[6];
          int  q=0;
	       int f=3,m;
          int w;
           {cout<<"\nEnter the code to display: ";
            gets(src);
            int rst=1;
            if(strlen(src)==6)
            {
             {for(int k=0;k<n;k++)
              {rst=1;
               s[k].rcode();
               for(m=0;m<6;m++)
                {if(src[m]!=s[k].ccode[m])
                 {rst=0;}}
           if(rst==1)
            {q=1;
             f=1;
             w=k;
             k=n;}
           } }
           if(rst==1)
            {cout<<"\n Product no."<<(w+1)<<"___";
             s[w].putval();
             cout<<"\n\n\n";
            if(chs==1)
             {cout<<"Enter the new name:";
              char lname[30];
              gets(lname);
              s[w].nname(lname);}
           if(chs==2)
             {cout<<"Enter the new code:";
              char lcode[6];
              gets(lcode);
              s[w].ncode(lcode);}
          if(chs==3)
             {cout<<"Enter the new price:";
              float lprice;
              cin>>lprice;
              s[w].nprice(lprice);}
          if(chs==4)
             {cout<<"Enter the new quantity:";
              int lquant;
              cin>>lquant;
              s[w].nquant(lquant);}
          if(chs==5)
             {cout<<"Enter the new category";
              char lcata[30];
              gets(lcata);
              s[w].ncatag(lcata);}
          cout<<"\n\n\nFinal product details___";
             s[w].putval();

           q=1;
           f=1;}
           } }
          if(q==0)
            {cout<<"\nCode no."<<src<<" is invalid.";}
            }
          }

   //----------------------------------------------------------------------------
void option_2()                                                   //function to check stock..............
   {int i;
    clrscr();
    cout<<"\n\n\t\tName\t\t\t\tCode\t\tQuantity left\n";
    for(i=0;i<n;i++)
     {s[i].disp_2();}
    }
   //----------------------------------------------------------------------------
void option_3()                                                   //function to generate bill..............
{clrscr();
 shop.putvalue();
 cout<<"\n\n CODE\tNAME\t\t             PRICE(Rs)\tQUANTITY\tNET PRICE(Rs)\n";
        char ch;
        int xx=0;
        int p;
        long pric=0;
        do
        {char src[6];
          int  q=0;
	       int f=3,m;
          int w,giv;
          int x,qnt[1],qntq;
            for(x=0;x<6;x++)
            {src[x]=getche();
             if(src[x]=='\b')
              {if(x!=0)
               {cout<<src[x-1];}
               x--;}
              }
            src[x]='\0';
            int rst=1;
            if(strlen(src)==6)
             {for(int k=0;k<n;k++)
              {rst=1;
               s[k].rcode();
               for(m=0;m<6;m++)
                {if(src[m]!=s[k].ccode[m])
                 {rst=0;}}
           if(rst==1)
            {q=1;
             f=1;
             w=k;
             k=n;}
           } }
           if(rst==1)
            {giv=s[w].putval2();
           q=1;
           f=1;}
           int fi=1;
           if(giv==1)
           {cout<<"          ";
            for(int r=0;r<=1;r++)
            {qnt[r]=getche();
             if(qnt[r]=='\b')
              {if(r!=0)
               {cout<<qnt[r-1];}
              else
               {cout<<" ";}
               r--;}
             else
             {if((qnt[r]<48)||(qnt[r]>57))
              {if(qnt[r]==45)
               {fi=-1;}
               qnt[r]=0;}
              else
              {qnt[r]=(qnt[r]-48);}
             }
            }
            qntq=((qnt[0]*10)+qnt[1])*fi;
            fi=1;
            p=0;
            p=s[w].putval3(qntq);
            pric=pric+p;
            p=0;
            ch='y';
            giv=0;}
          if(q==0)
          {if(strcmp(src,"theend")==0)
             {ch='n';
             xx=0;
             cout<<"\r";
            cout<<"                                                 \r";}
           else
             {ch='y';
            cout<<" code no."<<src<<" is invalid.";
            getch();
            cout<<"\r";
            cout<<"                                                 \r";
            xx=1;    } }
            if(xx==0)
            {cout<<"\n";}
            xx=0;
           }while(ch=='y');
           for(int x=0;x<80;x++)
           {cout<<"_";}
           cout<<"\n\t\t\t\t\t\t\tNet price :Rs"<<pric;
           cout<<"\n\t\t\t\t\t\t\tTotal tax :Rs"<<(pric*5)/100<<"(5%)\n";
           for(int x=0;x<80;x++)
           {cout<<"_";}
           cout<<"\n\t\t\t\t\t\tNet payable price :Rs"<<(pric+((pric*5)/100))<<"\n\n\n";
           cout<<"\n\t\t* This is a computer generated bill. No sign is required.\n\n";
           save();
 }
   //----------------------------------------------------------------------------
                                                                 //function to print all values...............
 void printall()
  {int i,total=0;
   for(i=0;i<n;i++)
   {cout<<"\n\nThe info of "<<(i+1)<<"th product";
    s[i].putval();
    total=total+s[i].net();}
    cout<<"\n\n\tTotal evaluation of all product in store:Rs"<<total<<"\n";

  }

//-------------------------------------------------------------------------------
void list2()
  {clrscr();
   int chs,z,i,j;
   char ch;
   do{
     do{
 menu2: clrscr();
        save();
        cout<<"\n\n\n\tMENU __2\n";
        cout<<"\n\t1)Add a product";
        cout<<"\n\t2)Delete a product";
        cout<<"\n\t3)Edit product details";
        cout<<"\n\t4)View details of all product";
        cout<<"\n\t5)view detail of any particular product";
        cout<<"\n\t6)search for products";
        cout<<"\n\t7)Go back";
        cout<<"\n\tEnter the option number:";
        cin>>chs;}while((chs<0)||(chs>7));
      switch(chs)
  {                                                                              //case 1.......................
   case 1:{clrscr();
            do
            {s[n].getval();
             n=n++;
             cout<<"\n Do you want to enter any other records(y/n)";
             for(z=0;z<1000;z++)
              {ch=getche();
               if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
                {z=1000;}
               else
               {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
              }
             }while(ch=='y'||ch=='Y');
             goto menu2;
           break;}
   case 2:{clrscr();
          do                                                                    //case 2...................................
          {case_2();
           cout<<"\nDo you want to update any more??(y/n)";
           for(z=0;z<1000;z++)
           {ch=getche();
               if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
                {z=1000;}
               else
               {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
              }
           }while(ch=='y'||ch=='Y');
           goto menu2;
           break;}
  case 3:{clrscr();
           do                                                                   //case 3................................
          {case_3();
           cout<<"\nDo you want to update any more??(y/n)";
           for(z=0;z<1000;z++)
           {ch=getche();
               if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
                {z=1000;}
               else
               {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
              }
           }while(ch=='y'||ch=='Y');
           goto menu2;
           break;}
  case 4:{clrscr();
            cout<<"\nDisplaying all records....";                                //case 4........................
             if(n<0)
             {cout<<"Sorry no record found!!";}
            else
             {printall();}
             getch();
             goto menu2;
              break;}
  case 5:{clrscr();
          char src[6];
          int  q=0;
	       int f=3,m;
           do                                                                   //case 5..........................
           {cout<<"\nEnter the code to display: ";
            gets(src);
            if(strlen(src)==6)
             {for(int k=0;k<n;k++)
              {int rst=1;
               s[k].rcode();
               for(m=0;m<6;m++)
                {if(src[m]!=s[k].ccode[m])
                 {rst=0;}}
           if(rst==1)
            {cout<<"\n Product no."<<(k+1)<<"___";
             s[k].putval();
           q=1;
           f=1;}
           } }
          if(q==0)
            {cout<<"\nCode no."<<src<<" is invalid.";}
            cout<<"\n \nDo want any more product?? (y/n)";
            for(z=0;z<1000;z++)
            {ch=getche();
               if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
                {z=1000;}
               else
               {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
              }
           }while(ch=='y'||ch=='Y');
           goto menu2;
           break;}
 case 6:{do                                                                     //case 6............................
          {search();                                                              //search function called
           cout<<"\nDo you want to search anymore??(y/n)";
           for(z=0;z<1000;z++)
           {ch=getche();
               if(ch=='y'||ch=='n'||ch=='N'||ch=='Y')
                {z=1000;}
               else
               {cout<<"\nEnter 'y'(yes) or 'n'(no)___ ";}
              }
           }while(ch=='y'||ch=='Y');
           goto menu2;
           break;}
 case 7:{ ch='n';
           break;}
 default:{ cout<<"Invalid choice";                                              //case 7....................................
           break;}
    }
    }while(ch=='y'||ch=='Y');
    }

    //---------------------------------------------------------------------------

  int list1(int c)
    {clrscr();
     int chs,z;
     char ch;
    do{save();
      do{clrscr();
  menu1: cout<<"\n\n\n\tMENU __ 1";
        cout<<"\n\n\n\t1)Edit product list";
        cout<<"\n\t2)Check condition of stock";
        cout<<"\n\t3)Start billing";
        cout<<"\n\t4)Exit";
        cout<<"\n\tEnter the option number:";
        cin>>chs;}while((chs<0)||(chs>4));
     if(chs==1)
     {if(c==1)
      {list2();}
      else
      {cout<<"Not available for GUEST";
      c=p.pw_check();}
      ch='y';
      clrscr();
      goto menu1;
     }
     if(chs==2)
     {option_2();
      ch='y';
      getch();
      clrscr();
      goto menu1;}
     if(chs==3)
     {option_3();
      ch='y';
      getch();
      clrscr();
      goto menu1;}
     if(chs==4)
     {ch='n';}
     if(ch=='y')
     {cout<<"\n\n\n\tPress any key to get back...";}
    }while(ch=='y'||ch=='Y');
    }

     //--------------------------------------------------------------------------

 void main()
 {clrscr();
  int i,c;
  load();
  dispw();
  c=choose();
  list1(c);
  cout<<"\t\t\tCoded By__ $oh@g  B@r@l"<<"\n\t\t\tThankyou for using";
  getch();
  }

