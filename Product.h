#pragma once
#include <string>
using namespace std;
class Product
{
public:
	enum class type
	{
		Books, Notebooks, Pencils, Others
	};
private:
	double price;
	string name;
	type t;	
public:
	Product();
	Product(double price, const string& name, Product::type t);
	virtual ~Product();
	virtual Product* clone() const = 0;

	void setPrice(double price);
	void setName(const string& name);
	void setType(const type& t);
	
	double getPrice() const;
	const string getName() const;
	type getType() const;
	
	void typeCout() const;
	
	virtual void  print() const;
	friend ostream& operator<<(ostream& o, const Product& P);
	virtual void read();
	friend istream& operator>>(istream& i, Product& S);
};
