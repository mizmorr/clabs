#include <iostream>
using namespace std;
char randomer()
{
    int a = rand()%2;
    switch (a)
    {
    case 1:
        return 'r';
        break;
    
    case 0:
        return 'w';
        break;
    }
    return 'w';
}
void print(string s,int n, int a [])
{   
    cout<<endl<<"print "+s+":"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
int m,n;
cin>>n>>m;
char A [n][m];
int LS[n], LO[m];
for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    A[i][j]=randomer();
for(int i=0;i<n;i++)
    {   cout<<endl;
        for(int j=0;j<m;j++)
        cout<<A[i][j]<<" ";
    }
cout<<endl;
for(int i=0;i<n;i++)
    LS[i]=rand()%3+1;
for(int j=0;j<m;j++)
    LO[j]=rand()%3+1;
print("LS",n,LS);
print("LO",m,LO);
bool flag=true;
int k,g;
    for(int i=0;i<n;i++)
        {if(flag==false) break;
        for(int j=0;j<m;j++)
        if(!((LS[i]>=LO[j]&&A[i][j]=='w')||(LS[i]<=LO[j]&&A[i][j]=='r'))) //не превышает. не ниже
        {
            flag=false; k=i; g=j;
            break;
        }
    }
        
cout<<endl<<"flag - "<<to_string(flag)<<endl;
cout<<k<<" "<<g<<endl;
cout<<A[0][4];
}
