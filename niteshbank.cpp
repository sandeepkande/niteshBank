#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<direct.h>
#include<string.h>
#include<time.h>
using namespace std;

FILE *p;
char path[30]="G://simple//",fname[]="//scret.txt";
char pathl[30]="G://simple//",aname[]="//account.txt";
char paths[30]="G://simple//",stat[]="//statement.txt";
char patht[30]="G://",tfile[30]="totalamount.txt";
int amount,dep,with,che,tamount;
char sid[20];
time_t t;
class account
{
 public:
 void signup();
 void login();
 void checkstat();
 void delete_account();
 void totalamount();
 void total_amount();
};

class loan
{
 public:
 void signup();
 void login();
 void checkstat();
 void delete_account();
};


void account::signup()
{
 char spw[9];
 int temp;
 cout<<"\n create your user name=";
 fflush(stdin);
 gets(sid);
 strcat(path,sid);
 temp=mkdir(path);
 strcat(path,fname);
 p=fopen(path,"w");
 cout<<"\n create your password=";
 gets(spw);
 fputs(spw,p);
 fclose(p);
 strcat(patht,tfile);
 p=fopen(patht,"r");
 tamount=getw(p);
 fclose(p);
 if(temp==0)
 {
  cout<<"\n account created";
  strcat(pathl,sid);
  strcat(pathl,aname);
  p=fopen(pathl,"w");
  cout<<"\n enter your opening amount";
  cin>>amount;
  int a;
  a=amount;
  tamount=tamount+amount;
  putw(amount,p);
  fclose(p);
  strcat(paths,sid);
  strcat(paths,stat);
  p=fopen(paths,"a");
  char b[]="opening amount=",c[]="\n",d[]="\ton=";
  t=time(NULL);
  fputs(b,p);
  fprintf(p,"%d",a);
  fputs(d,p);
  fputs(ctime(&t),p);
  fputs(c,p);
  fclose(p);

  strcat(patht,tfile);
  p=fopen(patht,"w");
  putw(tamount,p);
  fclose(p);
 /* p=fopen(patht,"r");
  tamount=getw(p);
  fclose(p);*/
 }
}


void account::login()
{
 char lpw[9],spw[9], path[30]="G://simple//";
 int temp;
 cout<<"\n enter your user name=";
 cin>>sid;
 cout<<"\n enter your password=";
 strcat(path,sid);
 strcat(path,fname);
 p=fopen(path,"r");
 fread(lpw,8,1,p);
 fclose(p);
 for(temp=0;temp<5;temp++)
 {
  spw[temp]=getch();
  if(spw[temp]==13)
  {
   break;
  }
 /* if(spw[temp]==8)
  {
   putch('\b');
   putch(NULL);
   putch('\b');
   continue;
  }*/
  cout<<"*";
  if(temp==4)
  {
   spw[temp+1]='\0';
  }
 }
 if(!strcmp(spw,lpw))
 {
  cout<<"\n welcome to your account";
  int do1,z=1;
  strcat(pathl,sid);
  strcat(pathl,aname);
  do
  {
   cout<<"\nwhat do you want to perform\n1:deposit\n2:withdraw\n3:check=";
   int n;
   cin>>n;
   strcat(patht,tfile);
   p=fopen(patht,"r");
   tamount=getw(p);
   fclose(p);
   if(n==1)
   {
    int a,b;
    cout<<"\n enter amount you want to deposit=";
    cin>>dep;
    b=dep;
    tamount=tamount+dep;
    p=fopen(pathl,"r");
    amount=getw(p);
    a=amount;
    fclose(p);
    amount=amount+dep;
    p=fopen(pathl,"w");
    putw(amount,p);
    fclose(p);
    if(z==1)
    {
     strcat(paths,sid);
     strcat(paths,stat);
     z++;
    }
    p=fopen(paths,"a");
    char e[]="deposite amount=",f[]="amount=",g[]="\n",h[]="\n",i[]="\ton=";
    t=time(NULL);
    fputs(f,p);
    fprintf(p,"%d",a);
    fputs(g,p);
    fputs(e,p);
    fprintf(p,"%d",b);
    fputs(i,p);
    fputs(ctime(&t),p);
    fputs(h,p);
    fclose(p);
    cout<<"\n amount deposited";
   }
   else
   if(n==2)
   {
    int a,b;
    p=fopen(pathl,"r");
    amount=getw(p);
    a=amount;
    fclose(p);
    cout<<"\n enter amount you want to withdraw=";
    cin>>with;
    b=with;
    tamount=tamount-with;
    if(with<amount)
    {
     amount=amount-with;
     p=fopen(pathl,"w");
     putw(amount,p);
     fclose(p);
     cout<<"\namount withdraw";
     if(z==1)
     {
      strcat(paths,sid);
      strcat(paths,stat);
      z++;
     }
     p=fopen(paths,"a");
     char c[]="withdrawl amount=",d[]="amount=",e[]="\n",f[]="\n",i[]="\ton=";
     t=time(NULL);
     fputs(d,p);
     fprintf(p,"%d",a);
     fputs(e,p);
     fputs(c,p);
     fprintf(p,"%d",b);
     fputs(i,p);
     fputs(ctime(&t),p);
     fputs(f,p);
     fclose(p);
    }
    else
    {
     cout<<"\n not sufficient amount";
    }
   }
   else
   if(n==3)
   {
    p=fopen(pathl,"r");
    amount=getw(p);
    cout<<"\nyour amount is="<<amount;
    fclose(p);
   }
   strcat(patht,tfile);
   p=fopen(patht,"w");
   putw(tamount,p);
   fclose(p);
  /* p=fopen(patht,"r");
   tamount=getw(p);
   fclose(p);*/
   cout<<"\ndo you want to continue\n1-yes\n2-no=";
   cin>>do1;
   fflush(p);
  }
  while(do1==1);
 }
 else
 {
  cout<<"\nwrong password";
 }
}

void account::checkstat()
{
 char lpw[9],spw[9], path[30]="C://turboc3//ok//simple//";
 int temp;
 cout<<"\n enter your user name=";
 cin>>sid;
 cout<<"\n enter your password=";
 strcat(path,sid);
 strcat(path,fname);
 p=fopen(path,"r");
 fread(lpw,8,1,p);
 fclose(p);
 for(temp=0;temp<5;temp++)
 {
  spw[temp]=getch();
  cout<<"*";
  if(temp==4)
  {
   spw[temp+1]='\0';
  }
 }
 if(!strcmp(spw,lpw))
 {
  cout<<"\n welcome to your account";
  cout<<"\n";
  strcat(paths,sid);
  strcat(paths,stat);
  p=fopen(paths,"r");
  fseek(p, SEEK_SET, 0);
  char buf[500];
  fread(buf,500,1,p);
  cout<<buf;
  fclose(p);
 }
}

void account::delete_account()
{
 char lpw[9],spw[9];
 int temp;
 cout<<"\n enter your user name=";
 cin>>sid;
 cout<<"\n enter your password=";
 strcat(path,sid);
 strcat(path,fname);
 p=fopen(path,"r");
 fread(lpw,8,1,p);
 fclose(p);
 for(temp=0;temp<5;temp++)
 {
  spw[temp]=getch();
  cout<<"*";
  if(temp==4)
  {
   spw[temp+1]='\0';
  }
 }
 if(!strcmp(spw,lpw))
 {
  fclose(p);
  if (remove(strcat(path,sid)) == 0)
  {
  // remove(strcat(path,aname));
  // remove(strcat(path,stat));
   printf("\nRemoved %s.\n",sid);
  }
  else
  {
   perror("remove");
  }
 }
 else
 {
  cout<<"\nyour password is wrong \nunauthorised access\ncannot delete account";
 }
}



void account::total_amount()
{
 strcat(patht,tfile);
 p=fopen(patht,"r");
 tamount=getw(p);
 fclose(p);
 cout<<"\ntotal amount="<<tamount;
}


int main()
{
 account a1;
 int temp,do2;
 system("cls");
 fflush(p);
 do
 {
  cout<<"1-for signup\n2-for login\n3-for statement list\n4-for deleting account=";
  cin>>temp;
  switch(temp)
  {
   case 1: a1.signup();break;
   case 2: a1.login();break;
   case 3: a1.checkstat();break;
   case 4: a1.delete_account();break;
   case 9: a1.total_amount();break;
  }
  cout<<"\ndo you want to continue\n1 for yes\n2 for no=";
  cin>>do2;
 }
 while(do2==1);
 cout<<"\nTHANKYOU";
 getch();
 return 0;
}

