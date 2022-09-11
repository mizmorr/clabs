#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string switchab(string ab)
{
	char a = ab[0];
	char b = ab[1];
	string ba = "";
	ba += b; ba += a;
	return ba;
}
void lclear(string& a);
//string switchtriple(string ab)
//{
// string ad = ab.substr(0,3 );
// string add = switchab(ad);
// char ac = switchab(ad.substr(1, 2))[1];
// return ac+add ;
//}
//string decode(string word)
//{
// int leng = word.length();
// char * wordmas;
// for (int i = 0; i < leng; i++)
// wordmas = new char[i];
// for (int i = 0; i < leng - 3; i++)
// wordmas += word[i];
//
//}
//
//string decode2(string a)
//{
// string fst = a.substr(0, a.length() - 3);
// string presecond = a.substr(a.length() - 3, 3);
// string second = switchtriple(presecond);
// return second+fst ;
//}
string decode3(string a)
{
	string fst = a.substr(0, a.length() - 3);
	string second = a.substr(a.length() - 3, 3);
	return second + fst;
}
string decode4(string a)
{
	int mas[50];
	string str[20], restr;
	int  j = 1; mas[0] = 0;
	restr = "";
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ') {
			{mas[j] = i; j++; }
		}
	}
	for (int i = 0; i < j; i++)
	{
		string substr = a.substr(mas[i], mas[i + 1]);
		lclear(substr);
		str[i] = decode3(substr);
	}
	for (int i = 0; i < j; i++)
		restr += str[i]+' ';
	return restr;
}
void lclear(string&a)
{
	int i = 0;
	while (a[i] ==' ')
		a.erase(i,1);
}
void rclear(string& a)
{
	while (a[a.length() - 1] == ' ')
		a.pop_back();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string line;
	ifstream prewords("prewords.txt");
	ofstream reswords("reswords.txt",ios::app);
	if (prewords.is_open())
	{
		while (getline(prewords, line))
		{
			rclear(line);
			string resstr = decode4(line);
			cout << resstr << endl;
			reswords << resstr << endl;
		}
	}
	prewords.close();
	reswords.close();
}