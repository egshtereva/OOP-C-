#include "Book.h"
#include<iostream>
Book::Book(): Product(0,"", Product::type::Books), title(""), author_name(""), publisher_name(""), pages(0)
{
}

Book::Book(double price, const string& name, const string& title, const string& author_name, const string& publisher_name, unsigned int pages) : Product(price, name, Product::type::Books), title(title), author_name(author_name), publisher_name(publisher_name), pages(pages)
{
}

Book * Book::clone() const
{
	return new Book(*this);
}

void Book::setTitle(const string & title)
{
	this->title = title;
}

void Book::setAuthor_name(const string & author_name)
{
	this->author_name = author_name;
}

void Book::setPublisher_name(const string & publisher_name)
{
	this->publisher_name = publisher_name;
}

void Book::setPages(unsigned int pages)
{
	this->pages = pages;
}

const string Book::getTitle() const
{
	return title;
}

const string Book::getAuthor_name() const
{
	return author_name;
}

const string Book::getPublisher_name() const
{
	return publisher_name;
}

const unsigned int Book::getPages() const
{
	return pages;
}

void Book::print() const
{
	cout << (*this) << endl;
}

void Book::read()
{
	cin >> (*this);
}

ostream & operator<<(ostream & o, const Book & B)
{
	cout << "---Book---"<<endl;
	cout << (Product&)B;
	cout << "Title: " << B.getTitle() << endl << "Author name: " << B.getAuthor_name() << endl << "Publisher name: " << B.getPublisher_name() << endl << "Pages: " << B.getPages()<< endl;
	return o;
}

istream & operator>>(istream & i, Book & B)
{
	i >> (Product&)B;
	B.setType(Product::type::Books);
	cout << "Enter title: ";
	i >> B.title; 
	cout << "Enter author name: ";
	i >> B.author_name;
	cout << "Enter publisher name: ";
	i >> B.publisher_name;
	cout << "Enter pages: ";
	i >> B.pages;
	return i;
}


