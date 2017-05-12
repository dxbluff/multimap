#include "RBT.h" // ќперации над бинарным деревом
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "mlmap.h"


using namespace std;

void genTree(multimap<int, int> &tree, unsigned int quant)
{
	srand(time(NULL));
	for (unsigned int i = 0; i ^ quant; ++i)
	{
		int tmp = rand() % 100;
		cout << "GENERATED " << tmp << endl;
		tree.insert(tmp, tmp);
	}
}

void display(int &a)
{
	cout << "&a == " << &a << endl;
}




int main()
{ 
	setlocale(LC_ALL, "Russian");


	multimap<string, int> m;
	m.insert(pair<string, int>("Booooob", 10));

	m.insert("Alikhan", 2);
	m.insert("Alikhan", 1000);
	m.insert("Dima", 3);
	m.insert("Misha", 4);
	m.insert("Vova", 3);
	m.insert("Anya", 3);
	m.insert("Anton", 3);
	m.insert("Ildar", 3);
	m.delete_item("Alikhan");
	m.print();
	m.delete_item("Anya");
	std::cout << m.find("Misha") << endl;
	m.insert("Ildar", 4);
	m.print();

	cout << endl;

}