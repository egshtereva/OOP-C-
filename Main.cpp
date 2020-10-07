#include<iostream>
#include<string>
#include"User.h"
#include"Store.h"
#include "Book.h"
#include "Notebook.h"
#include "Pencil.h"
#include<fstream>
using namespace std;
int main()
{	
	Store S;
	User U("me","pass");
	S.addUser(U);
	U.login("me", "pass");

	Book B1(20, "novel", "Hamlet", "William Shakespeare", "Helikon", 234);
	Book B2;
	B2 = B1;
	B2.setTitle("Romeo and Juliet");
	B2.setPages(300);
	Book B3(17, "novel", "Under the Yoke", "Ivan Vazov", "Ciela", 350);
	Notebook N1(12.3, "Desert", "yellow", 60);
	Notebook N2(N1);
	N2.setName("Nature");
	N2.setColor("green");
	Pencil P1(1.5, "Happy Thoughts", "pink", "Orange");
	Pencil P2(78, "Beautiful moments", "blue", "Caran d'Ache");

	S.addProduct(B1);
	S.addProduct(B2);
	S.addProduct(B3);
	S.addProduct(N1);
	S.addProduct(N2);
	S.addProduct(P1);
	S.addProduct(P2);
	/*U.getCart().addToCart(P1);
	U.getCart().addToCart(B3);
	U.getCart().addToCart(N2);
	U.getCart().deleteFromCart(0);
	U.getCart().seeProducts();
	S.addProduct(B1);
	cout << S;
	S.filterByPrice(9, 17);
	S.filterByType(Product::type::Notebooks);*/
	/*string u;
	ifstream i("1.txt");
	if (!i) { cout << "a"; return 1; }
	i >> u >> u >> u;
	i.close();
	ofstream i2("1.txt",ios::app);
	if (!i2) { cout << "a"; return 1; }
	i2 << u << u <<endl;*/
	while (cin)
	{
		User U1;
		menu:
		cout << "Select Options: "<< endl << "R-Registration   L-Log In   Q-Quit" << endl;
		char op;
		cin >> op;
		switch(op) {
			case 'R': case 'r': {
				cin >> U1;
				S.addUser(U1);
				cout << "Sucess registration"<<endl;
			sel:
				cout << "Select Options " << endl << "R-Return back to menu   L-Log in   Q-quit"<<endl;
				cin >> op;
				switch (op)
				{
					case 'R': case 'r' :goto menu;
					case 'L': case 'l': goto log; 
					case 'Q': case 'q': goto quit;
					default: goto sel;
				}
			}
			case 'L': case 'l': {
			log:
				string name, pass;
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter pass: ";
				cin >> pass;
				if (U1.login(name, pass))
				{
					cout << "Success log in" << endl;
				}
			func:
				if (U1.login(name, pass))
				{							
					cout << "Select function: " << endl << "1-See products in store" << endl << "2-Filter products by type" << endl << "3-Filter products by price" << endl;
					cout << "4-Add to cart" << endl << "5-Delete from cart" << endl << "6-Cart total price" << endl <<"7-See products in cart" << endl;
					cout<<"8-See number of products in cart" << endl <<"9-Buy products in cart" << endl <<"10-Log out"<< endl << "11-Quit" << endl;
					unsigned int a;
					cin >> a;
					if (!cin) { cout << "Wrong input" << endl; cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); goto func; }
					switch(a)
					{
						case 1: {S.seeProducts(); goto func; break; }
						case 2: {
						ftype:
							cout << "Select type: B-Book  N-Notebook   P-Pencil  Q-Quit"<<endl;
							cin >> op;
							switch (op)
							{
								case 'B': case 'b': S.filterByType(Product::type::Books); goto func;
								case 'N': case 'n': S.filterByType(Product::type::Notebooks); goto func;
								case 'P': case 'p': S.filterByType(Product::type::Pencils); goto func;
								case 'Q': case 'q': goto quit;
								default: {
									cout << "Wrong input! Select options:  " << endl;
									cout << "T-Try again input a type   R-Return back to user functions   Q-quit";
									cin >> op;
									switch (op)
									{
										case 'T':case 't': goto ftype;
										case 'R': case 'r': goto func;
										case 'Q': case 'q': goto quit;
										default: cout << "Wrong input. Try again!" << endl; goto ftype;
									}
								}

							}
						}
						case 3: {
							double l, r;
							cout << "Input left border: ";
							cin >> l;
							if (!cin) { cout << "Wrong input" << endl; cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); goto func; }
							cout << "Input right border: ";
							cin >> r;
							if (!cin) { cout << "Wrong input" << endl; cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); goto func; }
							S.filterByPrice(l, r);
							goto func;
						}
						case 4: {
							cout << "Number of products in store: " << S.getProductsSize() << endl;
							cout << "Insert index of  the product: ";
							cin >> a;
							if (!cin) { cout << "Wrong input" << endl;  cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); goto func; }
							U.getCart().addToCart(S.getProduct(a));
						add: 
							cout << "Select options:   B-Buy products in cart   S-See products in cart    R-Return back to user functions   Q-Quit"<<endl;
							cin >> op;
							switch (op)
							{
								case 'B': case 'b': goto c9;
								case 'S': case 's': goto c7;
								case 'R': case 'r': goto func;
								case 'Q': case 'q': goto quit;
								default: {cout << "Wrong input!Try again!" << endl; goto add; }
							}
						}
						case 5: {
							cout << "Number of products in cart: " << U.getCart().NumberProducts() << endl;
							cout << "Insert index of  the product: ";
							cin >> a;
							if (!cin) { cout << "Wrong input" << endl;  cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); goto func; }
							U.getCart().deleteFromCart(a);
						del:
							cout << "Select options:   B-Buy products in cart   S-See products in cart   R-Return back to menu   Q-Quit" << endl;
							cin >> op;
							switch (op)
							{
								case 'B': case 'b': goto c9;
								case 'S': case 's': goto c7;
								case 'R': case 'r': goto func;
								case 'Q': case 'q': goto quit;
								default: { cout << "Wrong input!Try again!" << endl; goto del; }
							}
						}
						case 6: {
							cout << "Total price: " << U.getCart().totalPrice() << endl;
						pr:
							cout << "Select options:   B-Buy products in cart   S-See products in cart    R-Return back to user functions   Q-Quit" << endl;
							cin >> op;
							switch (op)
							{
								case 'B': case 'b': goto c9;
								case 'S': case 's': goto c7;
								case 'R': case 'r': goto func;
								case 'Q': case 'q': goto quit;
								default: { cout << "Wrong input!Try again!" << endl; goto pr; }
							}
						}
					c7: case 7:{
							U.getCart().seeProducts();
						see:
							cout << "Select options:   B-Buy products in cart   R-Return back to user functions   Q-Quit" << endl;
							cin >> op;
							switch (op)
							{
								case 'B': case 'b': goto c9;
								case 'R': case 'r': goto func;
								case 'Q': case 'q': goto quit;
								default: { cout << "Wrong input!Try again!" << endl; goto see; }
							}
						}
						case 8: {
							cout << "Number of products: " << U.getCart().NumberProducts() << endl;
							goto func;
						}
					c9: case 9: {
							U.getCart().BuyProducts();
							cout << "Success buying! " << endl;
							goto func;
					}
						case 10: {
							U.logout();
							cout << "Log out" << endl;
							goto menu;
						}
						case 11: goto quit;
						default: cout << "Invalid parameters. Try again: "<<endl; goto func;
					}
				}
				else
				{
					cout << "Invalid data. Select options: " << endl;
					cout << "T-Try again log in   R-Return back to menu   Q-quit"<<endl;
					cin >> op;
					switch(op)
					{
						case 'R': case 'r':goto menu;
						case 'T': case 't': goto log;
						case 'Q': case 'q': goto quit;
						default: {cout << "Wrong input!" << endl; goto sel; }
					}
				}
				break; }
			case 'Q': case 'q': {
				quit:
				return 0; }
			default:  cout << "Invalid input. Try again ";  goto menu;
		}
	}
	system("pause");
}