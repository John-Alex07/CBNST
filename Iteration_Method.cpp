#include<bits/stdc++.h>
#include <iostream>

using namespace std;
float ansi(float x)
{
    float expo= (x*x*x)-(2*x*x)-4;
    return expo;
}
 float fun(float x)
 {
     float ans=cbrt(2*(x*x)+4);
     return ans;
 }
 
 float df(float x)
 {
     float ans=(2*x*x +4);
     float m= 3*(pow(ans,2/3));
      
      float n=(4*x)/m;
      return n;
 }
 
 
void interval(float &a, float &b, int n)
{
   int na;
   int nb;
   int temp=0;
   while(b<n)
   {
       if(ansi(a)*ansi(b)<0)
       {
           temp=1;
           break;
       }
       a++;
       b++;
   }
   
   if(temp==1)
   {
       na=0;
       nb=-1;
   }
   else
   {
    na=a;
    nb=a-1;
   }
   int flag=0;
   while(nb>-n)
   {
       if(ansi(na)*ansi(nb)<0)
       {
           flag=1;
           break;
       }
       nb--;
       na--;
       
   }
   if(flag==1)
   {
      if(abs(a-b)>=abs(nb-na))
    {    a=na;
        b=nb;
    }
   }

}


int main()
{
   int n;
   cout<<"Enter the value of range:";
   cin>>n;
   
   float a;
   float b;
   a=0;
   b=1;
   
   interval(a,b,n);
 
 float x;
 float x1;
 cout<<"a: "<<a<<" b:"<<b<<endl;
 x=(a+b)/2;
   while(1)
   {   
       a=x;
       x1= fun(a);
       x=x1;
       cout<<"x1:"<<x1<<endl;
       if(abs(x1-a)<=0.0001)
        break;
   }
   cout<<"x1:"<<x1;
    return 0;
}