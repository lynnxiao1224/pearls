#pragma once

#include <list>
#include <iostream>

using namespace std;

namespace xl_210215 {
	list<int> merge2List(const list<int>& list1, const list<int>& list2, int meetVal)
	{
		list<int> newList = list2;

		if (list1.empty()) {
			return newList;
		}

		auto ptr = find(list1.begin(), list1.end(), meetVal);
		while (ptr != list1.end()) {
			newList.push_back(*ptr);
			ptr++;
		}

		return newList;
	}

	void testMergeTwoList()
	{
		list<int> l1 = { 2,3,4,5,6,7,8,9 };
		list<int> l2 = { 1,11,22,33 };

		list<int> newList = merge2List(l1, l2, 6);

		cout << "new list = ";
		for (auto item : newList)
		{
			cout << " " << item;
		}
		cout << endl;
	}
}

