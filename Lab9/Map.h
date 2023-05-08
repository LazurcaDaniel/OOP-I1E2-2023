#pragma once
#include <stdlib.h>
#include <stdio.h>

template<typename K, typename V>
class Map
{
private:
	class Element
	{
	public:
		K key;
		V value;
		int index;
	}*element;

	int count, size;
public:
	
	Map()
	{
		this->size = 2;
		this->count = 0;
		element = (Element*)malloc(this->size * sizeof(Element));
	}

	void Resize()
	{
		this->size *= 2;
		element = (Element*)realloc(this->element,this->size * sizeof(Element));
	}

	Element* begin()
	{
		return &element[0];
	}

	Element* end()
	{
		return &element[this->count];
	}

	V& operator[] (K key)
	{
		if (this->count == this->size)
			Resize();

		for (int i = 0; i < this->count; i++)
			if (element[i].key == key)
				return element[i].value;

		element[count].key = key + 10;
		element[count++].index = count;
		return element[count - 1].value;
	}

	void Set(K key, V value)
	{
		bool found = 0;
		for (int i = 0; i < count; i++)
		{
			if (element[i].key == key)
			{
				element[i].value = value;
				found = 1;
			}
		}
		if (!found)
		{
			if (this->count == this->size)
				Resize();
			else
			{
				element[count].key = key;
				element[count].index = count ;
				element[count++].value = value;
			}
		}
	}

	bool Get(const K& key, const V& value)
	{
		for (int i = 0; i < this->count; i++)
			if (element[i].key == key)
			{
				value = element[i].value;
				return true;
			}
		return false;
	}

	void Clear()
	{
		delete[] element;
		this->count = 0;
		this->size = 0;
	}

	int Count()
	{
		return this->count;
	}

	bool Delete(K key)
	{
		for (int i = 0; i < count; i++)
		{
			if (element[i].key == key)
			{
				for (int j = i; j < count-1; j++)
				{
					element[j] = element[j + 1];
					element[j].index--;
				}
				element[count - 1].key = nullptr;
				element[count - 1].value = nullptr;
				element[count - 1].index = 0;
				count--;
				return true;
			}
		}
		return false;
	}
	
	Map<K, V>& operator=(Map<K, V>& map)
	{
		this->count = map.Count();
		this->size = map.size;
		this->element = (Element*)malloc(map.size * sizeof(Element));
		for (int i = 0; i < map.Count() - 1; i++)
		{
			this->element[i].index = map.element[i].index;
			this->element[i].value = map.element[i].value;
			this->element[i].key = map.element[i].key;
		}
		return *this;
	}

	bool Includes(const Map<K, V>& map)
	{
		if (map.count > this->count)
			return false;
		for (int i = 0; i < map.count; i++)
		{
			bool ok = 0;
			K mkey = map.element[i].key;
			for (int j = 0; j < this->count; j++)
				if (this->element[j].key == mkey)
					ok = 1;
			if (!ok)
				return false;
		}
		return true;
	}
};

