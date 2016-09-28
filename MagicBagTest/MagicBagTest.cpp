// MagicBagTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "MagicBag.h"

using namespace std;

void memoryLeakTest();

int main() {

	MagicBag<int> mb1;
	mb1.insert(1);
	mb1.insert(2);
	mb1.insert(3);

	cout << "Printing out Magic Bag 1" << endl;
	mb1.print(cout);

	//set copy of mb1 as mb2
	MagicBag<int> mb2(mb1);

	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of threes in the bag is " << mb1.peek(3) << endl;
	cout << endl;

	int itemDrawn = mb1.draw();
	cout << "A " << itemDrawn << " was drawn from the bag." << endl << endl;

	cout << "The number of ones in the bag is " << mb1.peek(1) << endl;
	cout << "The number of twos in the bag is " << mb1.peek(2) << endl;
	cout << "The number of three in the bag is " << mb1.peek(3) << endl;
	cout << endl;

	cout << "Printing out Magic Bag 1" << endl;
	mb1.print(cout);
	cout << "\n Printing out Magic Bag 2" << endl;
	mb2.print(cout);
	
	//cout << mb1 << endl;
	//cout << mb2 << endl << endl;

	for (int i = 0; i < 1000000; i++) {
		memoryLeakTest();
	}

	// Testing the ability to add an "unlimited" number of items
	MagicBag<int> mb3;
	for (int i = 0; i < 50; i++) {
		mb3.insert(i + 1);
	}
	cout << "\nPrinting Magic Bag 2" << endl;
	mb2.print(cout);

	mb3 = mb2 = mb1;
	cout << "Printing out Magic Bag 2 after = overloads" << endl;
	mb2.print(cout);


	system("pause");
	return 0;
}


void memoryLeakTest() {
	MagicBag<int> mb;
}