#ifndef __XLL_STL__
#define __XLL_STL__
//#pragma once

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>

namespace xl_stl_01 {
	void test_container();

	// sequence containers
	void test_array();
	void test_vector();
	void test_deque();
	void test_list();
	void test_forward_list();
	
	// container adaptor.
	void test_stack();
	void test_queue();
	void test_priority_queue();

	// associative containers.
	void test_set();
	void test_multiset();
	void test_map();
	void test_multimap();

	// unordered associative containers
	void test_unordered_set();
	void test_unordered_multiset();
	void test_unordered_map();
	void test_unordered_multimap();

}

namespace iterator_test {
	void iteratorTest();
}

#endif

