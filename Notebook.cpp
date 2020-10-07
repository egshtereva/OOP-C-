#include "Notebook.h"
#include<iostream>
Notebook::Notebook():Product(0, "", Product::type::Notebooks), color(""), pages(0)
{
}

Notebook::Notebook(double price, const string& name, const string& color, unsigned int pages): Product(price, name, Product::type::Notebooks), color(color), pages(pages)
{
}

Notebook * Notebook::clone() const
{
	return new Notebook(*this);
}

void Notebook::setColor(const string & color)
{
	this->color = color;
}

void Notebook::setPages(unsigned int pages)
{
	this->pages = pages;
}

const string Notebook::getColor() const
{
	return color;
}

const unsigned int Notebook::getPages() const
{
	return pages;
}

void Notebook::print() const
{
	cout << (*this) << endl;
}

void Notebook::read()
{
	cin >> (*this);
}

ostream & operator<<(ostream & o, const Notebook & N)
{
	cout << "---Notebook---" << endl;
	cout << (Product&)N;
	cout << "Color: " << N.getColor() << endl << "Pages: " << N.getPages() << endl;
	return o;
}

istream & operator>>(istream & i, Notebook & N)
{
	i >> (Product&)N;
	N.setType(Product::type::Notebooks);
	cout << "Enter color: ";
	i >> N.color;
	cout << "Enter pages: ";
	i >> N.pages;
	return i;
}
