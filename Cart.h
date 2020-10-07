#pragma once
#include "Product.h"
#include <vector>
using namespace std;
class Cart
{
	vector<Product*> products;
public:
	Cart();
	Cart(const Cart& C);
	Cart& operator=(const Cart& C);
	~Cart();
	
	void addToCart(const Product& P);
	void deleteFromCart(unsigned int index);
	double totalPrice()const;
	void BuyProducts();
	int NumberProducts() const;
	void seeProducts() const;
};