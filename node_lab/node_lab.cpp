// node_lab.cpp: определяет точку входа для приложения.
//

#include "node_lab.h"

using namespace std;

int main()
{
	SingleLinkedList<int> l1;
	SingleLinkedList<int> l2 = l1;
	l1.push_tail(3);
	l1.push_tail(4);
	l1.push_tail(-3);

	cout << l1.get_size() << endl;
	cout << l2.get_size() << endl;
	l1.print();
	return 0;
}
