#pragma once

struct Stock
{
	char company[50];
	long shares;
	double share_val;
	double total_val;
};

void set_total(Stock* pst);
void acquire(Stock* pst, const char* co, long num, double price);
void buy(Stock* pst, long num, double price);
void sell(Stock* pst, long num, double price);
void update(Stock* pst, double price);
void show(Stock* pst);

