#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "stock00.h"


void set_total(Stock* pst)
{
	pst->total_val = pst->shares * pst->share_val;
}
	
void acquire(Stock* pst, const char *co, long num, double price)
{
	strcpy(pst->company, co);
	if (num < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< pst->company << " shares set to 0.\n";
		pst->shares = 0;
	}
	else
		pst->shares = num;
	pst->share_val = price;
	set_total(pst);
}

void buy(Stock* pst, long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
	}
	else
	{
		pst->shares += num;
		pst->share_val = price;
		set_total(pst);
	}
}

void sell(Stock* pst, long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares sold can't be negative. Transaction is aborted.\n";
	}
	else if (num > pst->shares)
	{
		std::cout << "You can't sell more than you have! Transaction is aborted.\n";
	}
	else
	{
		pst->shares -= num;
		pst->share_val = price;
		set_total(pst);
	}
}

void update(Stock* pst, double price)
{
	pst->share_val = price;
	set_total(pst);
}

void show(Stock* pst)
{
	std::cout << "Company: " << pst->company
		<< " Shares: " << pst->shares << "\n Share Price: $" << pst->share_val
		<< " Total Worth: $" << pst->total_val << "\n";
}


