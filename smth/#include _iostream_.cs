#include <iostream>
using namespace std;
double func(double x)  
{
	return 2,5*x/4+3/2;
}
void input()
{
	cout << "Input a , b, epsilon " << endl;
}
//int main()
//{
// input();
//	double a, b; cin >> a >> b;  double epsilon; double x;
//	cin >> epsilon;
//	double c;
//	c = (a + b) / 2;
//	do
//	{
//		if (func(a) * func(c) < 0)
//			b = c;
//		c = (a + b) / 2;
//		if (func(c) * func(b) < 0)
//			a = c;
//
//	} while (fabs(b - a) / 2 > epsilon);
//	x = (a + b) / 2;
//	if (fabs(func(x)) <= epsilon)
//	{
//		cout << " " << x << endl;
//		cout << func(x) << endl;
//	}
//	else cout << "No";
//}
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
	} while (fabs(c1 - c0) >= epsilon);
		cout << c1;

}
