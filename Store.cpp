#include "Store.h"
#include<iostream>
Store::Store()
{
}

Store::Store(const Store & S): users(users)
{
	for (auto i : S.products)
		products.push_back(i->clone());
}

Store & Store::operator=(const Store & S)
{
	if (this == &S) return *this;
	users = S.users;
	for (auto i : products)
		delete i;
	products.clear();
	for (auto i : S.products)
		products.push_back(i->clone());
	return *this;
}

Store::~Store()
{
	for (auto i : products)
		delete i;
}

void Store::addProduct(const Product& P)
{
	products.push_back(P.clone());
}

void Store::deleteProduct(unsigned int index)
{
	unsigned int size = products.size();
	if (index >= size)throw runtime_error("Out of array");
	delete products[index];
	products.erase(products.begin() + index);
}

const Product& Store::getProduct(unsigned int index) const
{
	if (index >= products.size())throw runtime_error("Out of array");
	return *products[index];
}

unsigned int Store::getProductsSize() const
{
	return products.size();
}

void Store::addUser(const User & U)
{
	users.push_back(U);
}

void Store::deleteUser(unsigned int index)
{
	unsigned int size = users.size();
	if (index >= size)throw runtime_error("Out of array");
	users.erase(users.begin() + index);
}

void Store::seeProducts() const
{
	cout << "---IN STORE---" << endl;
	for (unsigned i = 0; i < products.size(); i++)
		products[i]->print();
}

void Store::filterByType(const Product::type & T) const
{
	cout << "Result after filter: " << endl;
	int p = 0;
	for (unsigned int i = 0; i < products.size(); i++)
	{
		if (products[i]->getType() == T) {
			cout << "~Product N" << ++p << endl;
			products[i]->print();
			cout << endl;
		}
	}
}

void Store::filterByPrice(double start, double end) const
{
	if ((start <= 0 && end <= 0) || start>end) return;
	cout << "Result after filter: " << endl;
	int p = 0;
	for (auto i : products)
	{
		if (i->getPrice() >= start && i->getPrice() <= end)
		{
			cout << "~Product N" << ++p << endl;
			i->print();
			cout << endl;
		}
	}
}


ostream & operator<<(ostream & o, const Store & s)
{
	cout << "---IN STORE---" << endl;
	int p = 0, u = 0;
	for (auto i : s.products)
	{
		o << "~Product N" << ++p << endl;
		i->print();
		cout<< endl;
	}
	for (unsigned int i = 0; i < s.users.size(); i++)
	{
		o << "~User N"<< ++u << endl << "Name: " << s.users[i].getName()<<endl;
	}
	return o;
}
