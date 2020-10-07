#include "Pencil.h"
#include<iostream>
Pencil::Pencil():Product(0, "", Product::type::Pencils), color(""),producer_name("")
{
}

Pencil::Pencil(double price, const string& name, const string& color, const string& producer_name) : Product(price, name, Product::type::Pencils), color(color), producer_name(producer_name)
{
}


Pencil * Pencil::clone() const
{
	return new Pencil(*this);
}

void Pencil::setColor(const string & color)
{
	this->color = color;
}

void Pencil::setProducer_name(const string& producer_name)
{
	this->producer_name = producer_name;
}

const string Pencil::getColor() const
{
	return color;
}

const string Pencil::getProducer_name() const
{
	return producer_name;
}

void Pencil::print() const
{
	cout << (*this) << endl;
}

void Pencil::read()
{
	cin >> (*this);
}

ostream & operator<<(ostream & o, const Pencil & P)
{
	cout << "---Pencil---" << endl;
	cout << (Product&)P;
	cout << "Color: " << P.getColor() << endl << "Producer name: " << P.getProducer_name() << endl;
	return o;
}

istream & operator>>(istream & i, Pencil & P)
{
	i >> (Product&)P;
	P.setType(Product::type::Pencils);
	cout << "Enter color: ";
	i >> P.color;
	cout << "Enter producer_name: ";
	i >> P.producer_name;
	return i;
}
