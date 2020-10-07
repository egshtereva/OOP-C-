#pragma once
#include<string>
#include <vector>
#include"Product.h"
#include"Cart.h"
using namespace std;
class User
{
	string name;
	string password;
	void setName(const string& name);
	void setPassword(const string& password);
	Cart cart;
	bool log = false;
public:
	User();
	User(const string& name, const string& password);

	Cart& getCart();
	const Cart& getCart() const;
	const string getName() const;

	bool login(const string& name, const string& password);
	void logout();

	friend ostream& operator<<(ostream& o, const User& U);
	friend istream& operator>>(istream& i, User& U);
};
