#pragma once
#include <iostream>
template <class T>
class Tree
{
	T value;
	int nr_children;
	int max_children = 100;
	Tree<T>* father;
	Tree<T>** children;

public:
	Tree(T value)
	{
		this->nr_children = 0;
		this->father = nullptr;
		this->children = new Tree * [max_children];
		for (int i = 0; i < max_children; i++)
			children[i] = nullptr;
		this->value = value;
	}
	Tree()
	{
		this->nr_children = 0;
		this->father = nullptr;
		this->children = new Tree * [max_children];
		for (int i = 0; i < max_children; i++)
			children[i] = nullptr;
	}

	Tree& get_node(Tree* parent)
	{
		if (parent == nullptr)
			return *this;
		return *parent;
	}
	Tree& get_child(Tree* parent, int index)
	{
		if (parent == nullptr)
			return *this->children[index];
		return *parent->children[index];
	}
	Tree& get_father(Tree* parent)
	{
		return *parent->father;
	}
	int get_nr_children(Tree* parent)
	{
		if (parent == nullptr)
			return this->nr_children;
		return parent->nr_children;
	}
	T get_value(Tree* parent)
	{
		if (parent == nullptr)
			return this->value;
		return parent->value;
	}

	void add_node(Tree* parent, T value)
	{
		Tree<T>* x = new Tree<T>(value);
		if (parent == nullptr)
		{
			this->children[this->nr_children] = new Tree<T>;
			this->children[this->nr_children] = x;
			this->children[this->nr_children]->father = this;
			this->nr_children++;
		}
		else
		{

			parent->children[parent->nr_children] = new Tree<T>;
			parent->children[parent->nr_children] = x;
			parent->children[parent->nr_children]->father = parent;
			parent->nr_children++;
		}
	}
	void insert_node(Tree* parent, int index, T value)
	{
		Tree<T>* x = new Tree<T>(value);

		if (parent == nullptr)
		{
			x->father = this;
			this->children[this->nr_children] = new Tree<T>;
			for (int i = this->nr_children; i > index; i--)
				this->children[i] = this->children[i - 1];
			this->nr_children++;
			this->children[index] = x;
		}
		else
		{
			x->father = parent;
			parent->children[parent->nr_children] = new Tree<T>;
			for (int i = parent->nr_children; i > index; i--)
				parent->children[i] = parent->children[i - 1];
			parent->nr_children++;
			parent->children[index] = x;
		}
	}
	void delete_node(Tree* parent)
	{

		if (parent == nullptr)
		{
			for (int i = 0; i < this->nr_children; i++)
				delete_node(this->children[i]);
			delete this;
		}
		else
		{
			int index = 0;
			Tree<T>* t = new Tree<T>;
			t = parent->father;
			while (t->children[index]!= parent && index < t->nr_children)
			{
				index++; t = t->children[index];
			}
			
			for (int i = index; i <parent->father->nr_children; i++)
				parent->father->children[i] = parent->father->children[i + 1];
			parent->father->nr_children--;
			for (int i = 0; i < parent->nr_children; i++)
				delete_node(parent->children[i]);
			delete parent;
		}

	}
	Tree find_node(T value, Tree** queue, Tree<T>* parent)
	{
		if (parent == nullptr)
			queue == this;
		if (parent->value == value)
			return parent;
		queue->delete_node(queue->children[0]);
		if (parent != nullptr)
		{
			for (int i = 0; i < parent->nr_children; i++)
				queue->add_node(parent->children[i], parent->children[i]->value);
		}
		else
		{
			for (int i = 0; i < this->nr_children; i++)
				queue->add_node(this->children[i], this->children[i]->value);
		}
		for (int i = 0; i < queue->nr_children; i++)
			find_node(value, queue, queue->children[i]);
		return -1;
	}

	bool compar(T x, T y)
	{
		return x < y;
	}
	void sort(Tree* parent, bool (*compar)(T, T))
	{
		if (parent != nullptr)
			if (compar == nullptr)
			{
				bool ok;
				do
				{
					ok = 0;
					for (int i = 0; i < parent->nr_children - 1; i++)
						if (get_value(parent->children[i]) < get_value(parent->children[i + 1]))
						{
							std::swap(parent->children[i], parent->children[i + 1]);
							ok = 1;
						}
				} while (ok);
			}
			else
			{
				bool ok;
				do
				{
					ok = 0;

					for (int i = 0; i < parent->nr_children - 1; i++)
						if (compar(get_value(parent->children[i]), get_value(parent->children[i + 1])))
						{
							std::swap(parent->children[i], parent->children[i + 1]);
							ok = 1;
						}
				} while (ok);
			}
		else
			if (compar == nullptr)
			{
				bool ok;
				do
				{
					ok = 0;
					for (int i = 0; i < this->nr_children - 1; i++)
						if (get_value(this->children[i]) < get_value(this->children[i + 1]))
						{
							std::swap(this->children[i], this->children[i + 1]);
							ok = 1;
						}
				} while (ok);
			}
			else
			{
				bool ok;
				do
				{
					ok = 0;

					for (int i = 0; i < this->nr_children - 1; i++)
						if (compar(get_value(this->children[i]), get_value(this->children[i + 1])))
						{
							std::swap(this->children[i], this->children[i + 1]);
							ok = 1;
						}
				} while (ok);
			}
	}
	int count(Tree* parent)
	{

		if (parent == nullptr)
		{
			if (this->nr_children == 0)
				return 1;
			int counter = 1;
			for (int i = 0; i < this->nr_children; i++)
				counter +=  count(this->children[i]);
			return counter;
		}
		else 
		{
			
			if (parent->nr_children == 0)
				return 1;
			int counter = 1;
			for (int i = 0; i < parent->nr_children; i++)
				counter +=  count(parent->children[i]);
			return counter;
		}
	}


	
};

