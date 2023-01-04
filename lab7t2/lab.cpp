#include <string>
#include <bits/stdc++.h>
using namespace std;

string gen()
{
    char R[2] = {'r','w'};
    int fst = rand()%3;
    int second = rand()%3;
    switch (fst)
    {
    case 0:
        return "_";
           
    case 1:
        switch (second)
        {
        case 2:
            return "rw";
                
        default:
            return "r";
        }
    case 2:
        switch (second)
        {
        case 1:
            return "rw";
                
        default:
            return "w";
        }
    }
    return "";
}
void print(string **mas,int n, int m)
{   cout<<"our matrix: "<<endl;
    for(int i =0;i<n;i++){
    if(i) cout<<endl;
    for (int j=0;j<m;j++)
        cout<<mas[i][j]<<" ";
}
}
void A(string ** R,int n,int m) 
{
	vector <int> answer = vector <int>();
	for (int j = 0; j <m; j++)
	{
		bool flag = true;
		for (int i = 0; i < n; i++)  
		{
			if (R[i][j] != "_")
				flag = false; 
		}
		if (flag)
			answer.push_back(j);
	}
    if (answer.size())
	{cout<<endl << "список объектов, не доступных для всех субъектов" << endl;
	for (auto iter = answer.begin(); iter!=answer.end(); ++iter)
		cout << *iter << " ";
    }
    else { cout<<endl<<"a) not found"<<endl;}

}
void B(string ** R,int n,int m) 
{
	vector <int> answer = vector <int>();
	for (int i = 0; i <n; i++)
	{
		bool flag = true;
		for (int j = 0; j < m; j++)  
		{
			if (R[i][j] != "_")
				flag = false; 
		}
		if (flag)
			answer.push_back(i);
	}
    if (answer.size())
	{cout<<endl << "список субъектов, не доступных для всех субъектов" << endl;
	for (auto iter = answer.begin(); iter!=answer.end(); ++iter)
		cout << *iter << " ";
    }
    else { cout<<endl<<"b) not found"<<endl;}

}
void C(string ** R,int n,int m) 
{
	vector <int> answer = vector <int>();
	for (int i = 0; i <n; i++)
	{
		bool flag = true;
		for (int j = 0; j < m; j++)  
		{
			if (R[i][j]!="rw")
				flag = false; 
		}
		if (flag)
			answer.push_back(i);
	}
    if (answer.size())
	{cout<<endl << "список субъектов, имеющих полный доступ ко всем объектам" << endl;
	for (auto iter = answer.begin(); iter!=answer.end(); ++iter)
		cout << *iter << " ";
    }
    else { cout<<endl<<"c) not found"<<endl;}
}
void D(string ** R,int n,int m) 
{
	vector <int> answer = vector <int>();
	for (int j = 0; j <m; j++)
	{
		bool flag = true;
		for (int i = 0; i < n; i++)  
		{
			if (R[i][j]!="rw"&&R[i][j]!="w")
				flag = false; 
		}
		if (flag)
			answer.push_back(j);
	}
    if (answer.size())
	{cout<<endl << "список субъектов C1...." << endl;
	for (auto iter = answer.begin(); iter!=answer.end(); ++iter)
		cout << *iter << " ";
    }
    else { cout<<endl<<"d) not found"<<endl;}
}void E(string ** R,int n,int m) 
{
	vector <int> answer = vector <int>();
	for (int i = 0; i <n; i++)
	{   int count=0;
		bool flag = true;
		for (int j = 0; j < m; j++)  
		{
			if (R[i][j] == "rw")
				count++;
            if (R[i][j]=="w")
                flag = false; 
		}
		if (flag==true&&count==1)
			answer.push_back(i);
	}
    if (answer.size())
	{cout<<endl << "список субъектов. полный доступ только к одному объекту и к остальным объектам _/r" << endl;
	for (auto iter = answer.begin(); iter!=answer.end(); ++iter)
		cout << *iter << " ";
    }
    else { cout<<endl<<"e) not found.."<<endl;}
}

void makeTXT(int n, int m)
{
    string Rstat[n][m];
    for(int i =0;i<n;i++)
        for (int j=0;j<m;j++)
            Rstat[i][j]=gen();
ofstream out("lab7t2/access.txt",ofstream::out);
if (out.is_open()) {
    for(int i =0;i<n;i++){
        if (i) out<<endl;
        for (int j=0;j<m;j++)
            out<<Rstat[i][j]<<" ";
    }
}
out.close();
}

string ** Rm(int n,int m)
{   int i=0;
    string **R = new string *[n];
        for (int i=0;i<n;i++)
            *(R+i) = new string[m];
    ifstream source("lab7t2/access.txt");string s;
    while(getline(source,s))
    {   int j=0;
        string item;
        istringstream ss(s);
        while (getline(ss, item,' ') )
        {
            R[i][j]=item;
            j++;
        } 
        i++;
    }
    return R;
}
int main()
{
int n,m;
cin>>n>>m;
makeTXT(n,m);
string **r = Rm(n,m);
print(r,n,m);
A(r,n,m);
B(r,n,m);
C(r,n,m);
D(r,n,m);
E(r,n,m);
}





