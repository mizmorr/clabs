#include <iostream>
using namespace std;
#include <vector>
bool gorner(int del, vector <int> a)
{
	int s = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (i == 1)
		{
			s = s * del + a[1];
		}
		else s = s * del + a[i];
	}
	if (s == 0) return 1;
	else return 0;
}
void input_vector(vector <int>& k, int n)
{
	int w;
	for (int i = 0; i<=n; i++) { cin >> w; k.push_back(w); }
}
void print_vector(vector <int> k)
{
	int j = k.size();
	for (vector <int> :: iterator it = k.begin(); it != k.end(); ++it)
	{
		j--;
		if (j > 1)
		{
			if (j == k.size()-1)
			{
				cout.width(1);
				if(*it==1) cout<< "x^" << j;
				else
				cout << *it << "x^" << j;
			}
			else {
				if (*it != 1)
				{	
					if (*it == 0) break;
					else {
						cout.width(1);
						if (*it < 0) cout << *it << "x^" << j;
						else cout << "+" << *it << "x^" << j;
					}
				}
				else {
					cout.width(1); if (*it < 0) cout<< "x^" << j;
					else cout << "+"<< "x^" << j;
				}
			}
		}
		else {
			switch (j)
			{
			case 1:
			{if (*it != 1) {
				if (*it == 0) break;
				else {
					cout.width(1);
					if(k.size()-1==1||*it<0) cout << *it << "x";
					else
					cout << "+" << *it << "x";
				}
			}
			else { cout.width(1); if(k.size()-1==1) cout << "x"; else
			{if (*it > 0)
			cout << "+" << "x";
			else
			cout << "x";}
			}
			break;
			case 0: {
				cout.width(1);
				if (*it == 0) break;
				else {
					if (*it < 0) cout << *it;
					else cout << "+" << *it;
				}
			}
				  break;
			}
			}
		}
	}
}

void polynomial(vector <int>& j, vector <int> k, int root)
{
	j.push_back(0);
	int s = k[0];
	int i = 1;
	j.push_back(s);
	int pred = k[0];
	while (i < k.size())
	{
		s = root * pred + k[i];
		j.push_back(s); i++;
		pred = s;
	}
	j.erase(j.begin()); 
	j.pop_back();

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, root;
	cout << '\n' << "Введите степень полинома: ";
	cin >> n;
	cout << '\n';
	vector <int> null;
	vector <int> a; // вектор коэффициентов вводимого полинома
	cout << "Введите коэффициенты переменных полинома: ";
	cout << '\n';
	input_vector(a, n);
	cout << '\n';
	cout << "Введите корень двучлена: ";
	cin >> root;
	cout << '\n';
	if (gorner(root, a) == 1)
		polynomial(null, a, root);
	else {
		cout << '\n';
		cout << "данное значение не является корнем"; cout << '\n'; return 0;

	}
	print_vector(null);
	cout << " - результирующий полином" << endl;
	cout << "............................................................." << endl;
	return 0;
}

