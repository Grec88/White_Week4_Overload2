//============================================================================
// Name        : Week4_Overload2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator > 0 && denominator > 0) {
			p = numerator / gcd(numerator, denominator);
			q = denominator / gcd(numerator, denominator);
		}
		if (numerator == 0) {
			p = 0;
			q = 1;
		}
		if (numerator < 0 && denominator < 0) {
			p = abs(numerator) / gcd(abs(numerator), abs(denominator));
			q = abs(denominator) / gcd(abs(numerator), abs(denominator));
		}
		if ((denominator > 0 && numerator < 0)
				|| (denominator < 0 && numerator > 0)) {
			p = -(abs(numerator) / gcd(abs(numerator), abs(denominator)));
			q = abs(denominator) / gcd(abs(numerator), abs(denominator));
		}
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p, q;
};

bool operator==(const Rational &r1, const Rational &r2) {
	if ((r1.Numerator() == r2.Numerator())
			&& (r1.Denominator() == r2.Denominator())) {
		return true;
	} else {
		return false;
	}
}

Rational operator+(const Rational &r1, const Rational &r2) {
	return Rational(
			(r1.Numerator() * r2.Denominator()
					+ r2.Numerator() * r1.Denominator()),
			(r1.Denominator() * r2.Denominator()));
}

Rational operator-(const Rational &r1, const Rational &r2){
	return Rational(
				(r1.Numerator() * r2.Denominator()
						- r2.Numerator() * r1.Denominator()),
				(r1.Denominator() * r2.Denominator()));
}

int main() {
	    {
	 Rational r1(4, 6);
	 Rational r2(2, 3);
	 bool equal = r1 == r2;
	 if (!equal) {
	 cout << "4/6 != 2/3" << endl;
	 return 1;
	 }
	 }

	 {
	 Rational a(2, 3);
	 Rational b(4, 3);
	 Rational c = a + b;
	 bool equal = c == Rational(2, 1);
	 if (!equal) {
	 cout << "2/3 + 4/3 != 2" << endl;
	 return 2;
	 }
	 }

	 {
	 Rational a(5, 7);
	 Rational b(2, 9);
	 Rational c = a - b;
	 bool equal = c == Rational(31, 63);
	 if (!equal) {
	 cout << "5/7 - 2/9 != 31/63" << endl;
	 return 3;
	 }
	 }

	 cout << "OK" << endl;
	return 0;
}

