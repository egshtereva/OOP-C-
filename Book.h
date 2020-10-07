#pragma once
#include "Product.h"
#include <string.h>
class Book : public Product
{
	string title;
	string author_name;
	string publisher_name;
	unsigned int pages;
public:
	Book();
	Book(double price, const string& name, const string& title, const string& author_name, const string& publisher_name, unsigned int pages);
	Book* clone() const override;

	void setTitle(const string& title);
	void setAuthor_name(const string& author_name);
	void setPublisher_name(const string& publisher_name);
	void setPages(unsigned int pages);
	
	const string getTitle() const;
	const string getAuthor_name() const;
	const string getPublisher_name ()const;
	const unsigned int getPages() const;

	void print() const override;
	friend ostream& operator<<(ostream& o, const Book& B);
	void read() override;
	friend istream& operator>>(istream& i, Book& B);
};