#pragma once

#include <iostream>

using namespace std;


namespace PlusPlusTest
{
	void testPlusPlus();

	void testPlusPlus()
	{
		int i = 1;
		do {
			cout << i++ << " ";  // 1 2 3 4 5 6 7 8 9
		} while (i < 10);
		cout << endl;

		i = 1;
		while (i++ < 10) {
			cout << i << " ";  // 2 3 4 5 6 7 8 9 10
		}
		cout << endl;
		
		{
			cout << " 5 & 2 = " << (5 & 2) << endl;
		}

		{
			int a = 200;
			unsigned char b = 117;

			if (a > b) {
				cout << " A > B" << endl;
			}
			else {
				cout << "A > B" << endl;
			}
		}

		{
			const int a = 5;

			//a++;
			cout << "a = " << a << endl;
		}

		{
			class Base {
			public:
				void f() {
					cout << "Base\n";
				}
			};
			class Derived :public Base {
			public:
				void f() {
					cout << "Derived\n";
				};
			};
			
			Derived obj;
			obj.Base::f();   // display: Base
			
		}

		{
			union abc {
				int x;
				char ch;
			} var;

			var.ch = 'A';
			cout <<"abc = " << var.x<<endl;  // -858993599 (Garbage value)  why ????
		}

		{
			typedef enum Color { black, brown, beige, blackandwhite, nocolor };
		
			cout << "\n next black = " << Color::brown << endl;

		}


	}

	typedef struct _S {
		int x;
		int y;
	}S;

	struct _C {
		int x;
		int y;
	};

	typedef struct _C C;

}

namespace xl02
{
	void HelpMe(int* p, int* num, int* q);
	void WhereAmI(int* p, int* q, int a);

	void HelpMe(int* p, int* num, int* q) {
		int a;

		a = 2;
		q = &a;
		*p = *q + *num;
		num = p;
	}


	void WhereAmI(int* p, int* q, int a) {
		a = 6;
		*p = a + *p;
		*q = a + 3;
		HelpMe(q, &a, p);
	}

	void test()
	{
		int* p;
		int q;
		int* num;
		int a;

		a = 3;
		q = 5;
		p = &a;
		num = &q;

		cout << "\n*p = " << *p << ", q= " << q << ", a = " << a << ", *num = " << *num << endl;

		HelpMe(&a, p, num);
		cout << "*p = " << *p << ", q= " << q << ", a = " << a << ", *num = " << *num << endl;

		WhereAmI(&q, p, *num);
		cout << "*p = " << *p << ", q= " << q << ", a = " << a << ", *num = " << *num << endl;

	}
}


