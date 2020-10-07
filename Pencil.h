#pragma once
#include "Product.h"
class Pencil : public Product
{
	string color;
	string producer_name;
public:
	Pencil();
	Pencil(double price, const string& name, const string& color, const string& producer_name);
	Pencil* clone() const override;

	void setColor(const string& color);
	void setProducer_name(const string& producer_name);

	const string getColor()const;
	const string getProducer_name() const;

	void print() const override;
	friend ostream& operator<<(ostream& o, const Pencil& P);
	void read() override;
	friend istream& operator>>(istream& i, Pencil& P);
};