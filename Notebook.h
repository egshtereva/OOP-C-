#pragma once
#include "Product.h"
class Notebook : public Product
{
	string color;
	unsigned int pages;
public:
	Notebook();
	Notebook(double price, const string& name, const string& color, unsigned int pages);
	Notebook* clone() const override;

	void setColor(const string& color);
	void setPages(unsigned int pages);

	const string getColor()const;
	const unsigned int getPages() const;

	void print() const override;
	friend ostream& operator<<(ostream& o, const Notebook& N);
	void read() override;
	friend istream& operator>>(istream& i, Notebook& N);
};
