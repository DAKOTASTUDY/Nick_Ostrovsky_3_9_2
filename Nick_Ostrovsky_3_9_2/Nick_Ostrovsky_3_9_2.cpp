#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	int get_numerator_() { return numerator_; };
	int get_denominator_() { return denominator_; };
	 Fraction  common(Fraction t) {
		for (int i = t.denominator_; i > 0; i--)
		{
			if (((t.denominator_ % i == 0) && (t.numerator_ % i == 0)))
			{
				t.denominator_ = t.denominator_ / i;
				t.numerator_ = t.numerator_ / i;
			}
			
		}
		return t;
	 }
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator > (Fraction f)
	{
		return ((numerator_ * f.denominator_) > (f.numerator_ * denominator_));

	};
	bool operator < (Fraction f)
	{
		return ((numerator_ * f.denominator_) < (f.numerator_ * denominator_));

	};
	/*bool operator > (Fraction f)
	{
		return ((numerator_ * f.denominator_) > (f.numerator_ * denominator_));


	};*/
	bool operator >= (Fraction f)
	{
		return ((numerator_ * f.denominator_) >= (f.numerator_ * denominator_));

	};
	bool operator <= (Fraction f)
	{
		return ((numerator_ * f.denominator_) <= (f.numerator_ * denominator_));

	};
	bool operator == (Fraction f)
	{
		return ((numerator_ * f.denominator_) == (f.numerator_ * denominator_));

	};
	bool operator != (Fraction f)
	{
		return ((numerator_ * f.denominator_) != (f.numerator_ * denominator_));

	};
	Fraction operator + (Fraction f)
	{
		Fraction t(0,0);

		t.numerator_ = (numerator_ * f.denominator_) + (f.numerator_ * denominator_);
		t.denominator_ = f.denominator_ * denominator_ ;
		t = common(t);

		return t;

	};
	Fraction operator - (Fraction f)
	{
		Fraction t(0, 0);

		t.numerator_ = (numerator_ * f.denominator_) - (f.numerator_ * denominator_);
		t.denominator_ = f.denominator_ * denominator_;
		t = common(t);

		return t;

	};
	Fraction operator * (Fraction f)
	{
		Fraction t(0, 0);

		t.numerator_ = (f.denominator_ * denominator_);
		t.denominator_ = (numerator_ * f.numerator_);
		t = common(t);

		return t;

	};
	Fraction operator / (Fraction f)
	{
		Fraction t(0, 0);

		t.numerator_ = (f.denominator_ * numerator_); 
		t.denominator_ = denominator_ * f.numerator_;
		t = common(t);

		return t;

	};
	Fraction& operator ++ (int)
	{
		Fraction t1(0, 0);
		Fraction temp(numerator_, denominator_);

		t1.numerator_ = (temp.numerator_ + temp.denominator_);
		t1.denominator_ = temp.denominator_;
		
		common(t1);
		*this = t1;
		return temp;

	};
	Fraction& operator ++ ()
	{
		numerator_ = (numerator_ + denominator_);
		denominator_ = denominator_;


		Fraction temp = *this;
		common(temp);
		return temp;

	};
	Fraction& operator -- (int)
	{
		 Fraction t1(0,0);
		Fraction temp(numerator_, denominator_);
		
		//std::cout << "  " << temp.numerator_ << "   " << temp.denominator_ << std::endl;
		t1.numerator_ = (temp.numerator_ - temp.denominator_);
		t1.denominator_ = temp.denominator_;
		//std::cout << "  " << temp.numerator_ << "   " << temp.denominator_ << std::endl;
		//t1 = temp;
		//std::cout << "  " << t1.numerator_ << "   " << t1.denominator_ << std::endl;
		//--temp;
		common(t1);
		*this = t1;
		return temp;

	};
	Fraction& operator -- ()
	{
		

	numerator_ = (numerator_ - denominator_);
		denominator_ = denominator_;
		

		Fraction temp = *this;
		common(temp);
		return temp;

	};
	Fraction& operator - ()
	{
		

		numerator_ = (-numerator_ );
		denominator_ = denominator_;
		Fraction temp = *this;
		common(temp);
		return temp;

	};
};



int main()
{
	int a, b, c, d;

	
	std::cout << "\n\t Please enter numerator 1: \t " << std::endl;
	std::cin >> a;
	std::cout << "\n\t Please enter denominator 1: \t " << std::endl;
	std::cin >> b;
	std::cout << "\n\t Please enter numerator 2: \t " << std::endl;
	std::cin >> c;
	std::cout << "\n\t Please enter denominator 2: \t " << std::endl;
	std::cin >> d;

	Fraction f1(a, b);
	Fraction f2(c, d);
	std::cout << "\t f1 \t" << (f1.get_numerator_()) << " / " << (f1.get_denominator_()) << std::endl;
	std::cout << "\t f2 \t" << (f2.get_numerator_()) << " / " << (f2.get_denominator_()) << std::endl;
	std::cout << std::boolalpha;
	std::cout << "\t f1 > f2\t" << (f1 > f2) << std::endl;
	std::cout << "\t f1 < f2\t" << (f1 < f2) << std::endl;
	std::cout << "\t f1 >= f2\t" << (f1 >= f2) << std::endl;
	std::cout << "\t f1 <= f2\t" << (f1 <= f2) << std::endl;
	std::cout << "\t f1 == f2\t" << (f1 == f2) << std::endl;
	std::cout << "\t f1 != f2\t" << (f1 != f2) << std::endl;
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	Fraction f3(0, 0);
	f3 = f1 + f2;

	std::cout << "\t f1 + f2\t" << (f3.get_numerator_()) <<" / " << (f3.get_denominator_()) << std::endl;
	f3 = f1 - f2;
	std::cout << "\t f1 - f2\t" << (f3.get_numerator_()) << " / " << (f3.get_denominator_()) << std::endl;
	f3 = f1 * f2;
	std::cout << "\t f1 * f2\t" << (f3.get_numerator_()) << " / " << (f3.get_denominator_()) << std::endl;
	f3 = f1 / f2;
	std::cout << "\t f1 / f2\t" << (f3.get_numerator_()) << " / " << (f3.get_denominator_()) << std::endl;
	f3 = f1++;
	//f1++;
	std::cout << "\t f1++ \t" << (f1.get_numerator_()) << " / " << (f1.get_denominator_()) << std::endl;
	std::cout << "\t f3 \t" << (f3.get_numerator_()) << " / " << (f3.get_denominator_()) << std::endl;
	++f2;
	//f1++;
	std::cout << "\t ++f2 \t" << (f2.get_numerator_()) << " / " << (f2.get_denominator_()) << std::endl;
	--f1;
	//f1--;
	std::cout << "\t --f1 \t" << (f1.get_numerator_()) << " / " << (f1.get_denominator_()) << std::endl;
	f3 = f2--;
	//f1++;
	std::cout << "\t f2-- \t" << (f2.get_numerator_()) << " / " << (f2.get_denominator_()) << std::endl;
	std::cout << "\t f3 \t" << (f3.get_numerator_()) << " / " << (f3.get_denominator_()) << std::endl;
	-f1;
	std::cout << "\t -f1 \t" << (f1.get_numerator_()) << " / " << (f1.get_denominator_()) << std::endl;
	return 0;
}


