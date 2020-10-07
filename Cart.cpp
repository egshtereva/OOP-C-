#include "Cart.h"
#include<iostream>
Cart::Cart()
{
}

Cart::Cart(const Cart & C)
{
	for (auto i : C.products)
		products.push_back(i->clone());
}

Cart & Cart::operator=(const Cart & C)
{
	if (this == &C)return *this;
	for (auto i : products)
		delete i;
	products.clear();
	for (auto i : C.products)
		products.push_back(i->clone());
	return *this;
}

Cart::~Cart()
{
	for (auto i : products)
		delete i;
}

void Cart::addToCart(const Product& P)
{
	products.push_back(P.clone());
	cout << "Added in cart" << endl;
}

void Cart::deleteFromCart(unsigned int index)
{
	unsigned int size = products.size();
	if (index >= size)throw runtime_error("Out of array");
	delete products[index];
	for (unsigned int i = index+1; i < size; i++)
	{
		products[i-1] = products[i];
	}
	products.pop_back();
	cout << "Deleted product" << endl;
}

double Cart::totalPrice() const
{
	double sum = 0;
	for (unsigned int i = 0; i < products.size(); i++)
		sum += products[i]->getPrice();
	return sum;
}

void Cart::BuyProducts()
{
		for (auto i : products)
			delete i;
		products.clear();
}

int Cart::NumberProducts() const
{
	return products.size();
}

void Cart::seeProducts() const
{
	cout << "---IN CART---" << endl;
	for (unsigned i = 0; i < products.size(); i++)
		products[i]->print();
}

