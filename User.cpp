#include "User.h"
#include <stdexcept>
#include<iostream>
User::User(): cart()
{
	setName("");
	setPassword("");
}

User::User(const string& name, const string& password): cart()
{
	setName(name);
	setPassword(password);
}

void User::setName(const string& name)
{
	this->name = name;
}

Cart & User::getCart()
{
	if (!log) throw runtime_error("Not logged in"); 
	return cart;
}

const Cart& User::getCart() const
{
	if (!log) throw runtime_error("Not logged in");
	return cart;
}

void User::setPassword(const string& password)
{
	this->password = password;
}

const string User::getName() const
{
	return name;
}

bool User::login(const string & n, const string & p)
{
	if (name == n && password == p)
		log = true;
	return log;
}

void User::logout()
{
	if (!log) { cout << "Not logged in" << endl; return; }
	log=false;
}

ostream & operator<<(ostream & o, const User & U)
{
	if (!U.log)return o<<"Not logged in"<<endl;
	o << "Name: " << U.name << " ";
	U.cart.seeProducts();
	cout<< endl;
	return o;
}

istream & operator>>(istream & i, User & U)
{
	cout << "---User---"<< endl <<"Enter name: ";
	i >> U.name;
	cout << "Enter password: ";
	i >> U.password;
	return i;
}
