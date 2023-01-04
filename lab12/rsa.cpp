#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include "numeric/bigint.h"

using namespace std;

char letters[]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','#','1','2','3','4','5','6','7','8','9'};

bool isPrime(int x){
    for( auto i=2;i<=sqrt(x);i++)
        if (x%i==0) return false;
    return true;
}

int GCD(int a, int b) {

    do
    {
        if (a>b) a %=b;
        else b%=a;
    } while (a!=0&&b!=0);
    return a+b;
}
long CalcD(int p, int q){
    long d =(p-1)*(q-1)-1;
    while (d>0&&GCD(d,((p-1)*(q-1)))!=1)
        d--;
    return d;
}
long CalcE(long d, long m){
    long e =10;
    while(true){
        if (GCD(e*d,m)==1)
            break;
        else e++;
    }
    return e;
}
int getIndex(char k){
    int n = sizeof(letters)/sizeof(letters[0]);
    auto itr = find(letters,letters+n,k);
    return (distance(letters,itr)+1);
}
vector <int> RSA_Encrypt(string s, long e, long n){
    vector <int> res;
    double bi;
    for (auto j:s){
        int ind = getIndex(j);
        
        bi = pow(ind,e);
        // cout<<ind<<" "<<bi<<endl;
        res.push_back((int)fmod(bi,n));
    }
    return res;
}

string RSA_Decrypt(vector <bigint> s, long d, long n)
{
    string res = "";
    bigint bi;
    for (auto i : s)
    {   
        bi = i.bigpow(d);
        // cout<<bi<<endl;
        bi%=n;
        // res+=to_string(char(letters[bi.to_int()-1]));
        res+=char(letters[bi.to_int()-1]);
    }
    return res;
}

void Iron_setup(int p, int q){
    string s = "Iron Man";
    long m = (p-1)*(q-1);
    long n = p*q;
    long e = CalcE(CalcD(p,q),m);
    for (auto & c: s) c = toupper(c);
    vector <int> res = RSA_Encrypt(s,e,n);

    vector <bigint> bigres;
    for (auto r:res) bigres.push_back(bigint(r));
    string res2 =RSA_Decrypt(bigres,CalcD(p,q),n); 
    cout<<res2<<endl;
}

void another_setup(int p,int q,string s){
    long m = (p-1)*(q-1);
    long n = p*q;
    long e = CalcE(CalcD(p,q),m);
    for (auto & c: s) c = toupper(c);
    vector <int> res = RSA_Encrypt(s,e,n);

    vector <bigint> bigres;
    for (auto r:res) bigres.push_back(bigint(r));
    string res2 =RSA_Decrypt(bigres,CalcD(p,q),n); 
    cout<<res2<<endl;
}

int main()
{
int p,q;
cout<<"Input p,q"<<endl;
cin>>p>>q;

while(true){
    if (!isPrime(p)||!isPrime(q)||GCD(p,q)!=1)
        {cout<<"bad parameters, try else"<<endl; cin>>p>>q;}
    else break;
}

// Iron_setup(p,q); //5 7
                //7 13

cout<<"choose setup"<<endl<<"1 - Iron Man"<<endl<<"2- What is going on"<<endl<<"3 - different string"<<endl;
int ind;
cin>>ind;
switch(ind){
    case 1:
    Iron_setup(p,q);
    break;
    case 2:
    another_setup(p,q,"What is going on");
    break;
    case 3:
    cout<<"input string"<<endl; string s; cin>>s; another_setup(p,q,s);
}

// // cout<<e<<" "<<CalcD(p,q)<<endl;

// // cout<<fmod(pow(15,23),35)<<endl;

// // // long long bi = pow(14,23);
// // // cout<<bi;

// for (auto i=0;i<sizeof(letters)/sizeof(letters[0]);i++)
// cout<<letters[i]<<"  "<<i+1<<endl;
}

