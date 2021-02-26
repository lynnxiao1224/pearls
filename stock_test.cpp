#include <iostream>
#include <cstring>
#include "stock00.h"

#include "Header.h"

using namespace std;


struct Node	// 通常用Node表示链表的“节点”
{
	Stock record;	// 记录
	Node* next;		// 指向下一个节点的指针
};

struct LinkedList	// 另需一个结构体链表类型
{
	Node* head;		// 指向Node链条的第一个Node
	int num;		// 当前链条中的Node个数（可选）
};

void showLList(const LinkedList* llist)
{
	const Node* p = llist->head; // 为什么声明成const？
	while (p != nullptr)
	{
		cout << p
			 << "\t" << p->record.company
			<< "\t" << p->record.shares
			<< "\t" << p->record.share_val
			<< "\t" << p->record.total_val << endl;
		p = p->next; // 为什么？
	}
}

void appendLList(LinkedList* llist, const Stock* item)
{
	if (llist == nullptr) {
		cout << "appendLList: llist can't be nullptr" << endl;
		return;
	}

	Node* newNode = new Node;
	if (newNode == nullptr) {
		cout << "appendLList: new Node fail!!" << endl;
		return;
	}

	cout << "newNode address = " << newNode << " size = " << sizeof(Node) << endl;

	strcpy_s(newNode->record.company, item->company);
	newNode->record.shares = item->shares;
	newNode->record.share_val = item->share_val;
	newNode->record.total_val = item->total_val;
	newNode->next = nullptr;
	
	if (llist->num == 0) {
		llist->head = newNode;
		llist->num++;
		return;
	} 

	int k = llist->num;
	Node* curr = llist->head;
	while (k > 1) {
		curr = curr->next;
		k--;
	}

	curr->next = newNode;
	llist->num++;
}

void removeLList(LinkedList* llist, const char* company)
{
	if (llist == nullptr) {
		return;
	}

	if (strcmp(llist->head->record.company, company) == 0) {

		Node* tmp = llist->head;
		llist->head = llist->head->next;
		llist->num--;

		delete tmp;
		return;
	}

	Node* prev = llist->head;
	Node* curr = llist->head;
	int n = llist->num;
	while (n > 0) { // == while(n)

		if (strcmp(curr->record.company, company) == 0) {
			Node* tmp = curr;
			prev->next = curr->next;
			llist->num--;

			delete tmp;
			return;
		}

		prev = curr;
		curr = curr->next;
		n--;
	}
}



int list_test()
{
	LinkedList* plist = new LinkedList;

	cout << "plist address = " << plist << " size = " << sizeof(LinkedList) << endl;

	plist->head = nullptr;
	plist->num = 0;
	
	Stock item;
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "input No: " << i + 1 << " stock" << endl;
		cin >> item.company;
		cin >> item.shares;
		cin >> item.share_val;
		item.total_val = item.shares * item.share_val;
		appendLList(plist, &item);
	}
	showLList(plist);
	removeLList(plist,"aaa");
	cout << "remove aaa success\n";
	showLList(plist);
	removeLList(plist, "Unbound");
	cout << "remove Unbound\n";
	showLList(plist);
	return 0;
}
