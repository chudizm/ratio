#include "ratio.h"

ratio::ratio(int _cntr, int _dvdr)
{
	cntr = _cntr;
	dvdr = _dvdr;
}
ratio::ratio(double dec)
{
	int whdec,frdec;
	whdec = (int)dec;
	frdec = (int)( ( dec - floor(dec) ) * 1000000 );
	int powDec = 1;
	double resDiv;
	do
	{
		powDec*=10;
		resDiv = frdec/powDec;
	}
	while(resDiv > 0);
	dvdr = powDec;
	cntr = whdec * powDec + frdec;
}
void ratio::reduce(ratio& op)
{
	if (op.cntr > op.dvdr)						
		for (int i = abs(op.dvdr); i > 1; i--)
		{
			if ((op.cntr % i == 0)&&(op.dvdr % i == 0))
			{
				op.cntr /= i;
				op.dvdr /= i;
				break;
			}
		}
	else
		for (int i = abs(op.cntr); i > 1; i--)
		{
			if ((op.cntr % i == 0)&&(op.dvdr % i == 0))
			{
				op.cntr /= i;
				op.dvdr /= i;
				break;
			}
		}
	if (op.dvdr < 0)
	{
		op.dvdr *= -1;
		op.cntr *= -1;
	}

}
ratio& ratio::operator=(ratio op2)
{
	cntr = op2.cntr;
	dvdr = op2.dvdr;
	return *this;
}
ratio ratio::operator+(ratio op2)
{
	ratio res;
	res.dvdr = dvdr * op2.dvdr;
	res.cntr = (cntr * (res.dvdr / dvdr)) + (op2.cntr * (res.dvdr / op2.dvdr));
	reduce(res);
	return res;
}
ratio ratio::operator-(ratio op2)
{
	ratio res;
	res.dvdr = dvdr * op2.dvdr;
	res.cntr = (cntr * (res.dvdr / dvdr)) - (op2.cntr * (res.dvdr / op2.dvdr));
	reduce(res);
	return res;
}
ratio ratio::operator*(ratio op2)
{
	ratio res;
	res.dvdr = dvdr * op2.dvdr;
	res.cntr = cntr * op2.cntr;
	if (res.dvdr == 0)
		return (-1,-1); // - pri delenii na nol'
	else
	{
		reduce(res);
		return res;
	}
}
ratio ratio::operator/(ratio op2)
{
	ratio res;
	res.dvdr = dvdr * op2.cntr;
	res.cntr = cntr * op2.dvdr;
	if (res.dvdr == 0)
		return (1,-1); // - pri delenii na nol'
	else
	{
		reduce(res);
		return res;
	}
}
ostream& operator<< (ostream& os, const ratio& r)
{
	if (r.cntr % r.dvdr == 0)
		os << r.cntr;
	else
		os << "( " << r.cntr << "/" << r.dvdr << " )";
	return os;
}
istream& operator>> (istream& is, ratio& r)
{
	do
	{
		is >> r.cntr >> r.dvdr;
		if (r.dvdr == 0)
			cout << "\ndivided by zero, try again: " << endl;
	}
	while(r.dvdr == 0);
	return is;
}
bool ratio::operator!=(ratio right)
{
	bool res = false;
	//return ((cntr != right.cntr)+(dvdr != right.dvdr));
	if ((cntr!=right.cntr)||(dvdr!=right.dvdr))
		res = true;
	return res;
}
/*int ratio::strsym(const char* str, int c)
{
    int i = 0;
	for (i < strlen(str); str[i] != c; i++);
	return ++i;
}
int ratio::decGetCounter(double X)
{
	char Xstring[12];
	char cntr[12] = "";
	sprintf(Xstring,"%f",X);
	strcat(Xstring,"\0");
	strncpy(cntr,Xstring,strsym(Xstring,','));
	return atoi(cntr);
}
int ratio::decGetDivider(double X)
{
	char Xstring[12];
	char dvdr[12] = "";
	sprintf(Xstring,"%f",X);
	cout << "Xstring == " << Xstring << endl;
	for (int i = strsym(Xstring,','); i < strlen(Xstring); i++)
		strncat(dvdr,Xstring);
	cout << dvdr << endl;
	return atoi(dvdr);

}*/