#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class myComplex
{
public:
	myComplex(const double r, const double i)
		: re(r), im(i) 
	{}

	myComplex& operator += (const myComplex&);

	double real() const { return re; }
	double imag() const { return im; }

	friend myComplex& __doapl(myComplex*, const myComplex&);

private:
	double re;
	double im;
};

myComplex& __doapl(myComplex* ths, const myComplex& r)
{
	ths->re += r.re;
	ths->im += r.im;

	return *ths;
}


myComplex& myComplex::operator += (const myComplex& r)
{
	return __doapl(this, r);
}

inline double imag(const myComplex& x)
{
	return x.imag();
}

inline double real(const myComplex& x)
{
	return x.real();
}

inline myComplex operator + (const complex& x, const complex& y)
{
	return myComplex(real(x) + real(y), imag(x) + imag(y));
}

inline myComplex operator + (const myComplex& x, double y)
{
	return myComplex(real(x) + y, imag(x));
}

inline myComplex operator + (double x, const myComplex& y)
{
	return myComplex(x + real(y), image(y));
}

inline myComplex operator + (const myComplex& x)
{
	return x;
}

inline myComplex operator - (const myComplex& x)
{
	return myComplex(-real(x), -imag(x));
}

inline bool operator == (const myComplex& x, const myComplex& y)
{
	return real(x) == real(y) && imag(x) == imag(y);
}

inline bool operator != (const myComplex& x, const myComplex& y)
{
	return real(x) != real(y) || imag(x) != imag(y);
}

ostream operator << (ostream& os, const myComplex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}


#endif


