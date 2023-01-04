#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
const int n=4;
//easy+243 
//9 9 3 1
//3 3 9 3
int fact_tailed(int n , int res)
{
    if(n==1) return res;
    else return fact_tailed(n-1,res*n);
}
int fact(int n)
{
    return fact_tailed(n,1);
}
bool IsEasyTrd(int n)
{
    for(int i=2;i<sqrt(n);i++)
        if (n%i==0) return 0;
    return 1;
}
void swap(int *a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}
bool IsEasySnd(int p)
{
    return (fact(p-1)+1)%p==0;
}
int mastoint(int *);
bool IsEasy(int p)
{
    if (p==1) return true;
    else
    {   int a = rand();
        while(a%p==0) a=rand();
        return a%p==0;
        // int ppow=pow(a,p-1)-1;
        // bool flg;
        // ppow%p==0? flg = true: flg= false;
        // return flg;
    }
}
// void generate (int *a, int t){
//     if (t==n-1){ 
//         if (IsEasy(mastoint(a))==true){
//             for (int i=0;i<n;++i)
//                 cout<<a[i]<< " ";
//             cout<<"- might be key"<<endl;
//         }
//         else
      
//         for (int i=0;i<n;++i)
//                 cout<<a[i]<< " ";
//             cout<<endl; 
//         }
//     else{
//     for (int j=t;j<n;++j){
//         swap(a,t,j); 
//         t++;
//         generate(a,t);
//         t--;
//         swap(a,t,j);
//         }
//     }
// }
int mastoint(int *mas)
{
    string s="";
    for(int i=0;i<4;i++)
    s+=to_string(mas[i]);    
    return stoi(s);
}
// int main()
// {
// int *a {new int[n]{9,9,3,1}};
// int *b {new int[n]{3,3,9,3}};
// // generate(a,0);
// generate(b,0);

// }
bool NextSet(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; 
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  swap(a, j, k);
  int l = j + 1, r = n - 1; 
  while (l<r)
    swap(a, l++, r--);
  return true;
}
string writeTXT(int *a, int n)  
{ string s="";
  if(IsEasyTrd(mastoint(a))==true)
    {
        for (int i = 0; i < n; i++)
        s+= to_string(a[i])+ " ";
        s+="- might be a key\n";
    }
    else
    {
    for (int i = 0; i < n; i++)
        s+=to_string(a[i])+" ";
        s+='\n';
    }
    return s;
}
int main() 
{
  ofstream out;
  out.open("out2.txt");
  int *a;
  a = new int[n];
  int *aw {new int[n]{1,3,9,9}};
  for (int i = 0; i < n; i++)
    a[i] = aw[i];
  out<<writeTXT(a,n);
  while (NextSet(a, n))
    out<<writeTXT(a, n);
  int *a2 {new int[n]{3,3,3,9}};
  for (int i = 0; i < n; i++)
    a[i] = a2[i];
  out<<writeTXT(a, n);
  while (NextSet(a, n))
    out<<writeTXT(a, n);
  out.close();
}
