#include "Product.h"
#include<cstring>
#include<iostream>
using namespace std;

Product::Product() :price(0), t(type::Others)
{
	setName("");
}

Product::Product(double price, const string& name, type t) : price(price), name(name),t(t)
{
}

Product::~Product(){}


void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setName(const string& name)
{
	this->name = name;
}

void Product::setType(const type & t)
{
	this->t = t;
}

void Product::typeCout() const
{
	if (t == Product::type::Pencils)cout << "Pencils";
	else if (t == Product::type::Notebooks) cout << "Notebooks";
	else if (t == Product::type::Books) cout << "Books";
	else cout << "Other";
}

void Product::print() const
{
	cout << (*this) << endl;
}

void Product::read()
{
	cin >> (*this);
}

double Product::getPrice() const
{
	return price;
}

const string Product::getName() const
{
	return name;
}


Product :: type Product::getType() const
{
	return t;
}

ostream & operator<<(ostream & o, const Product & P)
{
	o << "Price: " << P.price << endl <<"Name: " << P.name << endl << "Type: " ;
	P.typeCout();
	return o << endl;
}

istream & operator>>(istream & i, Product & S)
{
	cout << "---Product---"<< endl << "Enter price: ";
	i >> S.price;
	cout << "Enter name: ";
	i >> S.name;
	return i;
}
