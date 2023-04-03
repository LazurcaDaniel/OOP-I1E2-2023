#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree<int>* x = new Tree<int>(15);
	x->add_node(x, 20);
	x->add_node(x, 28);
	x->add_node(x, 1);
	x->sort(nullptr,nullptr);
	
	for (int i = 0; i < x->get_nr_children(nullptr); i++) 
		cout << x->get_value(&x->get_child(nullptr,i)) << " "; //28 20 1
	cout << '\n';
	
	Tree<int>* y = new Tree<int>;
	y = &x->get_child(nullptr, 1); // second child, value 28
	x->add_node(y, 4); //child 0
	x->add_node(y, 6); //child 1
	x->insert_node(y, 1, 8); /// children becom 4 8 6
	
	for (int i = 0; i < y->get_nr_children(nullptr); i++)
		cout << y->get_value(&y->get_child(nullptr, i)) << " ";
	
	y->delete_node(&y->get_child(nullptr, 0));
	cout <<'\n'<< y->get_nr_children(nullptr) << '\n';
	
	for (int i = 0; i < y->get_nr_children(nullptr); i++)
		cout << y->get_value(&y->get_child(nullptr, i)) << " ";
	
	cout << '\n' << x->count(nullptr) << '\n';
	
}