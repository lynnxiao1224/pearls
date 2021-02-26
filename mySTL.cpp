
using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "mySTL.h"

constexpr long gASIZE = 500L;
//const long gASIZE = 5000L;

long get_a_target_long()
{
	long target = 0;

	cout << "target (~" << RAND_MAX << "):";
	cin >> target;

	return target;
}

string get_a_target_string()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;

	return to_string(target);
}

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b) {
		return 1;
	}
	else if (*(string*)a < *(string*)b) {
		return -1;
	}
	else {
		return 0;
	}
 }


namespace xl_stl_01 {
	void test_array()
	{
		cout << "\ntest_array()....." << endl;

		std::array<long, gASIZE> c;
		clock_t timeStart = clock();

		for (long i = 0; i < gASIZE; ++i) {
			c[i] = rand();
		}

		cout << "milli-second : " << (clock() - timeStart) << endl;
		cout << "array.size() = " << c.size() << endl;
		cout << "array.front() = " << c.front() << endl;
		cout << "array.back() = " << c.back() << endl;
		cout << "array.data() = " << c.data() << endl;

		long target = get_a_target_long();

		timeStart = clock();
		qsort(c.data(), gASIZE, sizeof(long), compareLongs);

		long* pItem = (long*)bsearch(&target, (c.data()), gASIZE, sizeof(long), compareLongs);

		cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != nullptr) {
			cout << "Found, " << *pItem << endl;
		}
		else {
			cout << "not found!" << endl;
		}
	}

	void test_vector()
	{
		cout << "\ntest_vector()....." << endl;

		vector<string> s;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				s.push_back(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-second : " << (clock() - timeStart) << endl;
		cout << "vector.size() = " << s.size() << endl;
		cout << "vector.front() = " << s.front() << endl;
		cout << "vector.back() = " << s.back() << endl;
		cout << "vector.data() = " << s.data() << endl;
		cout << "vector.capacity() = " << s.capacity() << endl;

		string target = get_a_target_string();

		timeStart = clock();
		auto pItem = ::find(s.begin(), s.end(), target);
		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != s.end()) {
			cout << "Found, " << *pItem << endl;
		}
		else {
			cout << "Not found:" << target << endl;
		}

		timeStart = clock();
		::sort(s.begin(), s.end());
		string* p = (string*)bsearch(&target, (s.data()), s.size(), sizeof(string), compareStrings);
		cout << "sort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl;

		if (p != nullptr) {
			cout << "Found, " << *p << endl;
		}
		else {
			cout << "Not find, " << target << endl;
		}
	}

	void test_deque()
	{
		cout << "\ntest_deque()......" << endl;

		deque<string> c;
		clock_t timeStart = clock();

		for (long i = 0; i < 10000; i++) {
			try {
				if (i % 2) {
					c.push_back(to_string(rand()));
				}
				else {
					c.push_front(to_string(rand()));
				}
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
	
		cout << "milli-seconds : " << (clock() - timeStart);
		cout << "deque.size() = " << c.size() << endl;
		cout << "deque.front() = " << c.front() << endl;
		cout << "deque.back() = " << c.back() << endl;
		cout << "deque.max_size() = " << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end()) {
			cout << "Found " << *pItem << endl;
		}
		else {
			cout << "Not found." << endl;
		}
		
		timeStart = clock();
		::sort(c.begin(), c.end());
		cout << "::sort(), milli-seconds : " << (clock() - timeStart) << endl;

	}

	void test_list()
	{
		cout << "\ntest_list()...." << endl;

		list<string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.push_back(to_string(rand()));
			}
			catch(exception& p){
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "list.size() = " << c.size() << endl;
		cout << "list.max_size() = " << c.max_size() << endl;
		cout << "list.front() = " << c.front() << endl;
		cout << "list.back() = " << c.back() << endl;

		string target = get_a_target_string();

		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end()) {
			cout << "Found, " << *pItem << endl;
		}
		else {
			cout << "Not found!" << endl;
		}

		timeStart = clock();
		c.sort();
		cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;
	}

	void test_forward_list()
	{
		cout << "\ntest_forward_list()....." << endl;

		forward_list<string> c;
		clock_t timeStart = clock();

		for (int i = 0; i < 1000000; i++) {
			try {
				c.push_front(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << ", " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "forward_lis.max_size() = " << c.max_size() << endl;
		cout << "forward_list.front() = " << c.front() << endl;
		//!c.back() // no such member function
		//!c.size() // no such member function

		string target = get_a_target_string();

		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end()) {
			cout << "Found, " << *pItem << endl;
		}
		else {
			cout << "Not found" << endl;
		}

		timeStart = clock();
		c.sort();
		cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;
	}

	void test_stack()
	{
		cout << "\ntest_stack()....." << endl;

		stack<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.push(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "stack.size() = " << c.size() << endl;
		cout << "stack.top() = " << c.top() << endl;
		c.pop();
		cout << "stack.size() = " << c.size() << endl;
		cout << "stack.top() = " << c.top() << endl;
	}

	void test_queue()
	{
		cout << "\ntest_queue()....." << endl;
		queue<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.push(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "queue.size() = " << c.size() << endl;
		cout << "queue.front() = " << c.front() << endl;
		cout << "queue.back() = " << c.back() << endl;
		c.pop();
		cout << "queue.size() = " << c.size() << endl;
		cout << "queue.front() = " << c.front() << endl;
	}

	void test_priority_queue()
	{
		cout << "\ntest_priority_queue()....." << endl;

		priority_queue<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.push(to_string(rand()));
//				cout << "c.top() = " << c.top() << endl;
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "priority_queue.size() = " << c.size() << endl;
		cout << "priority_queue.top() = " << c.top() << endl;
		c.pop();
		cout << "priority_queue.size() = " << c.size() << endl;
		cout << "priority_queue.top() = " << c.top() << endl;
	}

	void test_set()
	{
		cout << "\ntest_set()....." << endl;

		set<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "set.size() = " << c.size() << endl;  // != 1000000
		cout << "set.max_size() = " << c.max_size() << endl;

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found, " << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem2 = c.find(target);  //faster...
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem2 != c.end()) {
				cout << "Found, " << *pItem2 << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
	}

	void test_multiset()
	{
		cout << "\ntest_multiset()....." << endl;

		multiset<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "multiset.size() = " << c.size() << endl;  // 
		cout << "multiset.max_size() = " << c.max_size() << endl;

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found, " << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem2 = c.find(target);  // find the first one, and faster...
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem2 != c.end()) {
				cout << "Found, " << *pItem2 << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		{
			timeStart = clock();
			auto num = c.count(target);
			cout << "multiset.count(), milli-seconds : " << (clock() - timeStart) << endl;
			cout << target << " num = " << num << endl;
		}
	}

	void test_map()
	{
		cout << "\ntest_map()....." << endl;

		map<long, string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c[i] = to_string(rand());
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "set.size() = " << c.size() << endl;  // != 1000000
		cout << "set.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		auto pItem2 = c.find(target);  //faster...
		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem2 != c.end()) {
			cout << "Found, (" << (*pItem2).first <<", " << (*pItem2).second << ")" << endl;
		}
		else {
			cout << "Not found." << endl;
		}
	}

	void test_multimap()
	{
		cout << "\ntest_multimap()....." << endl;

		multimap<long, string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert({ rand(), to_string(rand()) });
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "set.size() = " << c.size() << endl;  // != 1000000
		cout << "set.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		auto pItem2 = c.find(target);  //find the first one, faster...
		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem2 != c.end()) {
			cout << "Found, (" << (*pItem2).first << ", " << (*pItem2).second << ")" << endl;
		}
		else {
			cout << "Not found." << endl;
		}

		{
			timeStart = clock();
			auto num = c.count(target);
			cout << "multimap.count(), milli-seconds : " << (clock() - timeStart) << endl;
			cout << target << " num = " << num << endl;
		}
	}

	void test_unordered_set()
	{
		cout << "\ntest_unordered_set()....." << endl;
		
		unordered_set<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_set.size() = " << c.size() << endl;
		cout << "unordered_set.max_size() = " << c.max_size() << endl;
		cout << "unordered_set.bucket_count() = " << c.bucket_count() << endl;
		cout << "unordered_set.local_factor() = " << c.load_factor() << endl;
		cout << "unordered_set.max_local_factor() = " << c.max_load_factor() << endl;
		cout << "unordered_set.max_bucket_cout() = " << c.max_bucket_count() << endl;

		for (unsigned i = 0; i < 20; i++) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements" << endl;
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found," << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);  // faster
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found," << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}

		cout << target << "in unordered_set.count() = " << c.count(target) << endl;
	}

	void test_unordered_multiset()
	{
		cout << "\ntest_unordered_multiset()....." << endl;

		unordered_multiset<string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_multiset.size() = " << c.size() << endl;
		cout << "unordered_multiset.max_size() = " << c.max_size() << endl;
		cout << "unordered_multiset.bucket_count() = " << c.bucket_count() << endl;
		cout << "unordered_multiset.local_factor() = " << c.load_factor() << endl;
		cout << "unordered_multiset.max_local_factor() = " << c.max_load_factor() << endl;
		cout << "unordered_multiset.max_bucket_cout() = " << c.max_bucket_count() << endl;

		for (unsigned i = 0; i < 20; i++) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements" << endl;
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found," << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);  // faster
			cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end()) {
				cout << "Found," << *pItem << endl;
			}
			else {
				cout << "Not found." << endl;
			}
		}
		cout << target << "in unordered_multiset.count() = " << c.count(target) << endl;
	}

	void test_unordered_map()
	{
		cout << "\ntest_unordered_map()....." << endl;

		unordered_map<long, string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c[i]= to_string(rand());
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_map.size() = " << c.size() << endl;
		cout << "unordered_map.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		//auto pItem = ::find(c.bengin(), c.end(), target); //No support!!!!
		auto pItem = c.find(target);
		cout << "unordered_map.find(), milli-seconds = " << (clock() - timeStart) << endl;
		if (pItem != c.end()) {
			cout << "Found,(" << (*pItem).first << "," << (*pItem).second << ")" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}

	void test_unordered_multimap()
	{
		cout << "\ntest_unordered_multimap()....." << endl;

		unordered_multimap<long, string> c;

		clock_t timeStart = clock();
		for (long i = 0; i < 1000000; i++) {
			try {
				c.insert({ rand(), to_string(rand()) });
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_multimap.size() = " << c.size() << endl;
		cout << "unordered_multimap.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		//auto pItem = ::find(c.bengin(), c.end(), target); //No support!!!!
		auto pItem = c.find(target);
		cout << "unordered_multimap.find(), milli-seconds = " << (clock() - timeStart) << endl;
		if (pItem != c.end()) {
			cout << "Found,(" << (*pItem).first << "," << (*pItem).second << ")" << endl;
		}
		else {
			cout << "Not found" << endl;
		}

		cout << target << "in unordered_multimap.count() = " << c.count(target) << endl;
	}

	void test_container()
	{
		//srand(time(NULL));
		
		//test_array();
		//test_vector();
		//test_deque();
		//test_list();
		//test_forward_list();
		
		//test_stack();
		//test_queue();
		//test_priority_queue();

		//test_set();
		//test_multiset();
		//test_map();
		//test_multimap();

		test_unordered_set();
		test_unordered_multiset();
		test_unordered_map();
		test_unordered_multimap();
	}
}

namespace iterator_test {

	void _display_category(random_access_iterator_tag) 
	{
		cout << "random_access_iterator" << endl;
	}

	void _display_category(bidirectional_iterator_tag) 
	{
		cout << "bidirectional_iterator" << endl;
	}

	void _display_category(forward_iterator_tag) 
	{
		cout << "forward_iterator" << endl;
	}

	void _display_category(input_iterator_tag)
	{
		cout << "input_interator" << endl;
	}

	void _display_category(output_iterator_tag)
	{
		cout << "output_interator" << endl;
	}


	template<typename I>
	void display_category(I itr)
	{
		typename iterator_traits<I>::iterator_category cagy;
		_display_category(cagy);
	}

	void iteratorTest()
	{
		cout << "\ntest_iterator_cagetory().......\n";

		display_category(array<int, 10>::iterator());  //random_access_iterator

		display_category(vector<int>::iterator());      //random_access_iterator

		display_category(deque<int>::iterator());       //random_access_iterator

		display_category(list<int>::iterator());        //bidirectional_iterator

		display_category(forward_list<int>::iterator());  //forward_iterator

		display_category(set<int>::iterator());       //bidirectional_iterator
		display_category(multiset<int>::iterator());   //bidirectional_iterator

		display_category(map<int, int>::iterator());    //bidirectional_iterator
		display_category(multimap<int, int>::iterator()); //bidirectional_iterator

		display_category(unordered_set<int>::iterator()); //bidirectional_iterator
		display_category(unordered_multiset<int>::iterator()); //bidirectional_iterator

		display_category(unordered_map<int, int>::iterator()); //bidirectional_iterator
		display_category(unordered_multimap<int, int>::iterator()); //bidirectional_iterator

		display_category(istream_iterator<int>());         //input_iterator
		display_category(ostream_iterator<int>(cout, ""));    //output_iterator
	}
}


