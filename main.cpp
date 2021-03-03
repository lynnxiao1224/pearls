

#include <iostream>
#include <vector>
#include <array>

#include "Header.h"
#include "classFraction.h"
#include "myString.h"
#include "myTemplate.h"
#include "mySTL.h"
#include "plusplusTest.h"

#include "mergeLinks.h"
#include "operatorTest.h"

#include "ifelseTest.h"

//using std::cout;//using declarations
//using std::cin;
//using std::endl;

//class Solution5;

using namespace std;

int main()
{

	//knight();


	//Goldbach(100);

	//testInsert();

	//testReverse();

	//testMatrix();

	//testMatrix_1();
	//list_test();

	//testReverseString();

	//testEnhentance();

	//std::vector<int> nums = { 2,3,4,5,1 };
	//Solution5QuickSelect b;
	//cout << "\n  2th = " << b.kthLargestElement(4, nums) << endl;;

	//test_Integer();

	//test_class();

	//test findArrayQuadruplet()
	{
		/*Test Case:
		Input:[2, 7, 4, 0, 9, 5, 1, 3] , 20
		Expected :[0, 4, 7, 9]
		Actual :[]
		*/
		vector<int> arr1 = { 2,7,4,0,9,5,1,3 };
		vector<int> rsn1 = findArrayQuadruplet(arr1, 20);

		cout << "rsn1 = ";
		for (auto e : rsn1) {
			cout << " " << e;
		}
		cout << endl;
		/*Input:[1,2,3,4,5,9,19,12,12,19], 40
		  Expected:[4,5,12,19]
		  Actual:[ ]
		*/

		vector<int> arr2 = { 1,2,3,4,5,9,19,12,12,19 };
		vector<int> rsn2 = findArrayQuadruplet(arr2, 40);

		cout << "rsn2 = ";
		for (auto e : rsn2) {
			cout << " " << e;
		}
		cout << endl;

	}

	{
		cout << "\nc1:"<<endl;
		myString c1 = myString("hello");  // constructor

		cout << "\nc2:" << endl;
		myString c2(c1);      // copy constructor

		cout << "\nc3:" << endl;
		myString c3 = c1;     // copy constructor

		cout << "\nc4:" << endl;
		myString c4;    // constructor
		c4 = c1;      // copy assignment.
		c4 = c4;

	}

	{
		test_static();
		test_mystone();
	}

	{
		array<array<bool, 2>, 3> dp{ true };

	}

	//test_myTemplate();

	//xl_stl_01::test_container();

	//PlusPlusTest::testPlusPlus();
	//xl02::test();

	//iterator_test::iteratorTest();
	{
		//xl_210215::testMergeTwoList();
		//operator_overload::testOperator();
	}

	{

		xl_210303::ifelseTest tst;
		tst.test();
	}

	return 0;
}

