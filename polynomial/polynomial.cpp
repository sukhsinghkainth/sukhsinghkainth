#include<iostream>
#include<math.h>
using namespace std; 
/* declare structure for polynomial */ 
struct poly 
{ 
   int coeff; 
   int expo; 
}p1[40],p2[40],p3[40];

int readPoly(struct poly []); 
int addPoly(struct poly [],struct poly [],int,int, struct poly []);
int subtractPoly(struct poly [],struct poly [],int,int, struct poly []);
int eval(int n1,struct poly []);
void displayPoly(struct poly [],int terms);
int main() 
{
  int n1,n2,n3,ch,val; 
  char c;
do{
  cout<<"\n\t=> Do you want to:\n";
  cout<<"\n\t 1. addition \n";
  cout<<"\n\t 2. subtraction\n";
  cout<<"\n\t 3. evaluation\n";
  cout<<"\n\t enter your choice:";
cin>>ch;
switch(ch)
{
case 1:
{
        n1=readPoly(p1); 
        n2=readPoly(p2);      
        cout<<"\n The first polynomial is: ";
        displayPoly(p1,n1); 
        cout<<"\n The second polynomial is: ";
        displayPoly(p2,n2);
        // add two polynomial and display result
        n3=addPoly(p1,p2,n1,n2,p3);
        cout<<"\n resultant polynomial after addition:"<<endl;
        displayPoly(p3,n3);
        break;
}
case 2:
{
        n1=readPoly(p1); 
        n2=readPoly(p2);      
        cout<<"\n The first polynomial is: ";
        displayPoly(p1,n1); 
        cout<<"\n The second polynomial is: ";
        displayPoly(p2,n2);
        // add two polynomial and display result
        n3=subtractPoly(p1,p2,n1,n2,p3);
        cout<<"\n resultant polynomial after subtraction:"<<endl;
        displayPoly(p3,n3);
        break;
}
case 3:
{
        cout<<"\n Enter the polynomial details:"; 
        n1=readPoly(p1); 
        cout<<"\n The polynomial is: "; 
        displayPoly(p1,n1); 
        val=eval(n1,p1);
        cout<<"\n The Resultant value of the polynomial is:"<<val<<endl; 
        break;
}
default:
{
    break;
}   
}
   cout<<"\n do you want to continue?(y/n):";
   cin>>c;
}while(c=='y'||c=='y');
return 0;
}
    int readPoly(struct poly p[10])                  
    { 
    int t1,i;
     cout<<"\n Enter the total number of terms in the polynomial: "; 
     cin>>t1;
     cout<<"\n Enter the COEFFICIENT and EXPONENT "<<endl; 
     for(i=0;i<t1;i++)
     { 
               cout<<" Enter the Coefficient("<<i+1<<"):";
               cin>>p[i].coeff; 
               cout<<" Enter the Exponent("<<i+1<<"):"; 
               cin>>p[i].expo; 
    }
    return(t1); 
    } 
   
    void displayPoly(struct poly p[20],int term)
     { 
    int k; 
    for(k=0;k<term-1;k++)                
    cout<<p[k].coeff<<"(x^"<<p[k].expo<<")+";
    cout<<p[term-1].coeff<<"(x^"<<p[term-1].expo<<")+";
    } 
    int addPoly(struct poly p1[10],struct poly p2[10],int n1,int n2,struct poly p3[10])
    {
        int i=0,j=0,k=0;
        while(i< n1 && j< n2)
        {
            if(p1[i].expo==p2[j].expo)
            {
                p3[k].coeff=p1[i].coeff+p2[j].coeff;
                p3[k].expo=p1[i].expo;
                i++, j++, k++;
            }
            else if(p2[i].expo>p2[j].expo)
            {
                p3[k].coeff=p1[i].coeff;
                p3[k].expo=p1[i].expo;
                i++, k++;
            }
            else
            {
                p3[k].coeff=p2[j].coeff;
                p3[k].expo=p2[j].expo;
                j++, k++;
            }
         }
        // for rest over terms for polynomial 1
        while(i<n1)
        {
              p3[k].coeff=p1[i].coeff;
              p3[k].expo=p1[i].expo;
              i++, k++;
        }
        // for rest over terms for polynomial 2
        while(i<n2)
        {
              p3[k].coeff=p2[j].coeff;
              p3[k].expo=p2[j].expo;
              j++, k++;
        }
        return k;

 }
 int subtractPoly(struct poly p1[20],struct poly p2[20],int n1,int n2,struct poly p3[20])
    {
        int i=0,j=0,k=0;
        while(i< n1 && j< n2)
        {
            if(p1[i].expo==p2[j].expo)
            {
                p3[k].coeff=p1[i].coeff-p2[j].coeff;
                p3[k].expo=p1[i].expo;
                i++, j++, k++;
            }
            else if(p2[i].expo>p2[j].expo)
            {
                p3[k].coeff=p1[i].coeff;
                p3[k].expo=p1[i].expo;
                i++, k++;
            }
            else
            {
                p3[k].coeff=p2[j].coeff;
                p3[k].expo=p2[j].expo;
                j++, k++;
            }
         }
        // for rest over terms for polynomial 1
        while(i<n1)
        {
              p3[k].coeff=p1[i].coeff;
              p3[k].expo=p1[i].expo;
              i++, k++;
        }
        // for rest over terms for polynomial 2
        while(i<n2)
        {
              p3[k].coeff=p2[j].coeff;
              p3[k].expo=p2[j].expo;
              j++, k++;
        }
        return k;

 }
int eval(int n1,struct poly p1[])
 { 
     int i,sum,x; 
     cout<<"\n\n Enter the value of x for evaluation: "; 
    cin>>x; sum=0; for(i=0;i<n1;i++) 
    sum=sum + p1[i].coeff*pow(x,p1[i].expo); 
    return(sum);
 }
