#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

class ratio
{
private:
	int cntr;
	int dvdr;
public:
	void reduce(ratio& op);
	ratio(int _cntr = 0, int _dvdr = 1);
	//ratio(double dec);
	ratio& operator=(ratio op2);
	ratio operator+(ratio op2);
	ratio operator-(ratio op2);
	ratio operator*(ratio op2);
	ratio operator/(ratio op2);
	friend ostream& operator<<(ostream& os, const ratio& r);
	friend istream& operator>>(istream& is, ratio& r);
	//bool operator!=(ratio right);
};