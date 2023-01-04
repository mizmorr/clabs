#include <bits/stdc++.h>
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
bool tESTER(vector <vector <int>> a)
{
 if (size(a)>1) return true;
 else if (size(a)==0) return false;
 else 
    if(any_of(a[0].begin(),a[0].end(),[](int i ){return i!=1;})) return true;
    return false;
}
void printvec(vector <int> a, string s)
{	cout<<endl<<s<<" - ";
    for(int i=0;i<size(a);i++)
        cout<<a[i]<<" ";
        cout<<endl;
}
void CollectAllR(vector <vector <int>> &LS,int set[], vector<int> prefix,
									int n, int k)
{
	if (k == 0)
	{
        LS.push_back(prefix);
        return;
	}
	for (int i = 0; i < n; i++)
	{
		vector <int> newPrefix;
		newPrefix = prefix;
        newPrefix.push_back(set[i]);
		CollectAllR(LS, set, newPrefix, n, k-1);
	}

}

void Collect(vector <vector <int>> &LS,int set[], int k)
{
	CollectAllR(LS, set, {}, 3, k);
}

void Chooser(vector <vector <int>> &LO,int set[], vector<int> prefix, int k,vector <vector <int>>Collection,vector <vector<char>> A,vector <vector <int>> &LS)
{
	// if(!tESTER(LO))
	// {
		if (k == 0){
		{	for (int p=0;p<size(Collection);p++){
			vector <int> ls = Collection[p];
			bool flag=true;
		    for(int i=0;i<size(ls);i++){
				if(flag==false) break;
			    vector<char> a = A[i];
        		for(int j=0;j<size(prefix);j++)
        		if(!((ls[i]<=prefix[j]&&a[j]=='w')||(ls[i]>=prefix[j]&&a[j]=='r'))) //не превышает. не ниже
        		{ flag=false; break; }
			}
			if(flag){
				LO.push_back(prefix);
				LS.push_back(ls);
				}
		}
		}
		return;
		}
		for (int i = 0; i < 3; i++)
		{
			vector <int> newPrefix;
			newPrefix = prefix;
			newPrefix.push_back(set[i]);
			Chooser(LO, set, newPrefix, k-1,Collection,A,LS);
		}
	// }
	// else return;
}
int main()
{
int set1[] = {1, 2,3};
int n,m;
cin>>n>>m;
vector <vector <int>> LO;
vector <vector <int>> LS;
vector<vector <char>> A;
vector <vector <int>> Collection;
Collect(Collection,set1,n);
for (int i=0;i<n;i++){
	vector <char> preA;
   	for (int j=0;j<m;j++)
		preA.push_back(randomer());
	A.push_back(preA);
}

for(int i=0;i<n;i++){   
    cout<<endl;
    for(int j=0;j<m;j++)
   	cout<<A[i][j]<<" ";
}	
cout<<endl<<endl;
Chooser(LO,set1,{},m,Collection,A,LS);
for(int i=0;i<size(LO);i++)
	{cout<<"pair "<<i;printvec(LS[i],"LS"); printvec(LO[i],"LO"); cout<<endl;}
}

