#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
vector <int> a;

void gener(int num, int last,int numb,vector <int> & res,vector <int> mas )
{   
     if (num==numb)
        {   vector<int> pre;
            int sum=0;
            for (int i =0;i<numb;i++)
                {
                pre.push_back(a[i]);
                sum+=a[i];
                }
            if (sum%size(mas)==0)
            {
                for(int j=0;j<size(pre);j++)
                    res.push_back(pre[j]);
            }
            
        }
        for(int i=last+1;i<size(mas);i++)
        {
            a.push_back(mas[i]);
            gener(num+1,i,numb,res,mas);
            a.pop_back();
        }
}

string getsub(vector <int> a,int i)
{
    srand(time(NULL));
    int j = 0+rand()%(size(a)-i);
    string s=" ";
    while(i)
    {
        s+=to_string(a[j])+" ";
        i--;
        j++;
    }
    return s;
    
}

string res (vector <int> inp)
{
    vector <int> r;
    int i=1;
    int powbool=pow(2,size(inp));
    while(size(r)==0)
    {
        gener(0,0,i,r,inp);
        i++;
    }
    if (size(r)==0) return "NO";
    else
        return "yes+\n"+getsub(r,i)+"\n"+to_string(powbool);
}
vector <int> strtovec (string a)
{
    vector <int> numbs;
    stringstream str(a);
    string s;
    while(getline(str,s,' '))
        numbs.push_back(stoi(s));
    return numbs;

}
int main()
{
    // ifstream input("input.txt");
    // ofstream out("out.txt");
    vector <int> a;
    string s;
    // if (input.is_open())
    // {
    //     // getline(input,s);
    //     // a=strtovec(s);
    //     cout<<"sda";
    // }
    // out<<res(a)<<endl;
    // out.close();
    // input.close();
}