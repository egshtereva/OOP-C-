#pragma once
#include "Product.h"
#include "User.h"
#include <vector>
class Store {
private:
	vector<Product*> products;
	vector<User> users;
public:
	Store ();
	Store(const Store& S);
	Store& operator=(const Store& S);
	~Store();

	void addProduct(const Product& P);
	void deleteProduct(unsigned int index);
	const Product& getProduct(unsigned int index) const;
	unsigned int getProductsSize() const;
	void addUser(const User& U);
	void deleteUser(unsigned int index);
	void seeProducts() const;
	
	void filterByType(const Product::type &T) const;
	void filterByPrice(double start, double end) const;

	friend ostream& operator<<(ostream& o, const Store& s);
};