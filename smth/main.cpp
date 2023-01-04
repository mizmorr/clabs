#include <iostream>
using namespace std;
double func(double x)  //example y=2,5x/4+1,5
{
	return 2,5*x/4+3/2;
}
void input()
{
	cout << "Input a , b, epsilon " << endl;
}
int main()
{
	input();
	double a, b; cin >> a >> b; double epsilon; cin >> epsilon;
	double c1, c0;
	c1 = 0;
	do
	{
		c0 = c1;
		c1 = a - func(a) * (a - b) / (func(a) - func(b));
		a = b; b = c1;
	} while (abs(c1 - c0) >= epsilon);
		cout << c1<<endl;

}
