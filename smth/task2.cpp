#include <iostream>
using namespace std;
#include "math.h";
double func(double x)
{
    return 3*x*x*x + 2*x - 4;
}
double right_rectangle(double a, double b, int n)
{
    double integ = 0;
    double h = (b-a)/ n;
    for (int i = 1; i < n; i++)
        integ += h * func(a + i * h);
    return integ;
}

double simpson(double a, double b, int n)
{
	double integ=0;
	double h=(b-a)/n;
	for(int i=0;i<n;i+=2)
		integ+=h/3*(func(a+i*h)+4*func(a+(i+1)*h)+func(a+(i+2)*h));
	return integ;
}
double integralRectangle(double a, double b, int n, double Epsilon, int &step)
{
	double s0,s1;
	s1=right_rectangle(a,b,n);
	do
	{
		s0=s1;
		n*=2;
		s1=right_rectangle(a,b,n);
		step++;
		
	} while (abs(s1-s0)>Epsilon);
	return s1;
}
double integralSimpson(double a, double b, int n, double Epsilon, int &step)
{
	double s0,s1;
	s1=simpson(a,b,n);
	do
	{
		s0=s1;
		n*=2;
		s1=simpson(a,b,n);
		step++;

	} while (abs(s1-s0)>Epsilon);
	return s1;
}
int main()

{	
	double a, b; int n0=1,n1=1; double epsilon; 
	cout<<"Input left limit: "<<endl; cin>>a; 
	cout<<"Input right limit: "<<endl; cin>>b;
	cout<<"Input epsilon: "<<endl; cin>>epsilon;
	int step1=0,step2=0;
	double s1 = integralRectangle(a,b,n0,epsilon,step1);
	double s2 = integralSimpson(a,b,n1,epsilon,step2);
	cout<<s1<<" - right_rectangle_inte1gral"<<'\t'<<step1<<" - step"<<endl;
	cout<<s2<<" - simpson_integral"<<'\t'<<step2<<" - step"<<endl;
	cout<<'\n';
}