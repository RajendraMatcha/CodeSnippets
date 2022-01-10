// created by rmatcha
// To Do:
// Compute time of execution , compare with existing one.
// Generalize w.r.t the existing implementation.
//
//
//
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

#define PRINT_FLOW
#define ABS_AFLOAT_MAX 4.294967232E+9
#define ABS_AFLOAT_MIN 2.3283065059276353E-10

typedef struct
{
	long long unsigned int unused_mantissa : 27;
	long long unsigned int useful_mantissa : 25;
	long long unsigned int exp_field: 11;
	bool sign_field : 1;
}Double;
typedef struct
{
	unsigned int mantissa_field: 25;
	unsigned int exp_field: 6;
	bool sign_field : 1;
}Afloat;
typedef union
{
	double dp;
	Double D;
} MapDouble;
typedef union
{
	unsigned int ui;
	Afloat af;
}MapAfloat;

unsigned int doubleToAfloat(double);
double AfloatToDouble(unsigned int);

int main( int argc, char ** argv )
{
	double x = -71.1225E6;	// give the value here
	unsigned int af;
//	cout<<"Enter the double value"<<endl;cin>>x;
//	clock_t begin, end;	begin = clock();end = clock();cout<<"Time spent = "<<(double(end-begin)/CLOCKS_PER_SEC)<<endl;
	cout<<"Value of input(double) is "<<x<<endl;
	af = doubleToAfloat(x);
	cout<<"Bit pattern in Afloat is "<<hex<<af<<"H"<<endl;
	x = AfloatToDouble(af);
	cout<<"Value after conversion from double to Afloat to double is "<<x<<endl;

	return 0;
}

unsigned int doubleToAfloat(double x)
{
#ifdef PRINT_FLOW
	cout<<endl<<"Entering function doubleToAfloat()"<<endl;
#endif

	if (x > ABS_AFLOAT_MAX)
	{
		x = ABS_AFLOAT_MAX;
		cout<<"Overflow !! Saturating to AFLOAT_MAX"<<endl;
	}
	if (x < -ABS_AFLOAT_MAX)
	{
		x = -ABS_AFLOAT_MAX;
		cout<<"Overflow !!Saturating to -AFLOAT_MAX"<<endl;
	}
	if ((x>0) && (x < ABS_AFLOAT_MIN))
	{
		x = ABS_AFLOAT_MIN;
		cout<<"Underflow !!Saturating to AFLOAT_MIN"<<endl;
	}
	if ((x<0) && (x > -ABS_AFLOAT_MIN))
	{
		x = -ABS_AFLOAT_MIN;
		cout<<"Underflow !!Saturating to -AFLOAT_MIN"<<endl;
	}

	MapDouble F;
	F.dp = x;
	MapAfloat L;
	L.af.sign_field = F.D.sign_field;
	L.af.exp_field = F.D.exp_field - 0x3DF;
	L.af.mantissa_field = F.D.useful_mantissa;

#ifdef PRINT_FLOW
	cout<<"Exiting function doubleToAfloat()"<<endl<<endl;
#endif
	return L.ui;
}

double AfloatToDouble(unsigned int af)
{
#ifdef PRINT_FLOW
	cout<<endl<<"Entering function AfloatToDouble()"<<endl;
#endif

	MapAfloat F;
	F.ui = af;
	MapDouble L;
	L.D.sign_field = F.af.sign_field;
	L.D.exp_field = F.af.exp_field + 0x3DF;
	L.D.useful_mantissa = F.af.mantissa_field;

#ifdef PRINT_FLOW
	cout<<"Exiting function AfloatToDouble()"<<endl<<endl;
#endif
	return L.dp;
}
