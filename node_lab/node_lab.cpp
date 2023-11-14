// node_lab.cpp: определяет точку входа для приложения.
//

#include "node_lab.h"

using namespace std;

int main()
{
	cout << "push_head" << endl;
	SingleLinkedList<int> l3(10, 10, 100);
	l3.print();
	SingleLinkedList<float> l2(10, 10.0f, 100.0f);
	l2.print();
	SingleLinkedList<double> l1(10, 0.0, 100.0);
	l1.print();

	return 0;
}
