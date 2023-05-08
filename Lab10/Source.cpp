#include <iostream>
using namespace std;

class exceptie1 : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Index-ul specificat nu exista!";
	}
}index_out_of_bounds;

class exceptie2 : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Lista este plina!";
	}
}list_full;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class MyCompare : Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		T* i1 = static_cast<T*>(e1);
		T* i2 = static_cast<T*>(e2);
		if (*i1 > *i2)
			return 1;
		if (*i1 == *i2)
			return 0;
		return -1;
	}
};

template <class T>
int compare(const T& d1, const T& d2)
{
	if (d1 > d2)
		return 1;
	if (d1 == d2)
		return 0;
	else
		return -1;
}


template<class T>
class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array(); // Lista nu e alocata, Capacity si Size = 0

	~Array(); // destructor

	Array(int capacity); // Lista e alocata cu 'capacity' elemente

	Array(const Array<T>& otherArray); // constructor de copiere



	T& operator[] (int index); // arunca exceptie daca index este out of range



	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie



	bool operator=(const Array<T>& otherArray);



	void Sort(); // sorteaza folosind comparatia intre elementele din T

	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator



	int Find(const T& elem); // cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator



	int GetSize() { return this->Size; };

	int GetCapacity() { return this->Capacity; };

	void DebugPrint();



};

template<class T>
Array<T>::Array() : Capacity(0), Size(0)
{
	this->List = nullptr;
}

template<class T>
Array<T>::Array(int capacity)
{
	this->Capacity = capacity;
	this->Size = 0;
	this->List = new T * [capacity];
}

template<class T>
Array<T>::~Array()
{
	this->Capacity = 0;
	this->Size = 0;
	for (int i = 0; i < this->Capacity; ++i)
		delete[] this->List[i];
	delete[] this->List;
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
	this->Capacity = otherArray.Capacity;
	this->Size = otherArray.Size;

	this->List = new T * [this->Capacity];
	for (int i = 0; i < this->Size; i++)
	{
		this->List[i] = new T*[sizeof(T)];
		this->List[i] = otherArray.List[i];
	}
}

template<class T>
T& Array<T>::operator [](int index)
{
	try
	{
		if (index > this->Size || index < 0)
			throw index_out_of_bounds;
		else
			return *this->List[index];
	}
	catch (exception& e)
	{
		cout << "Exceptie la operatorul []" << e.what() << '\n';
	}
	return *this->List[index];
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	try
	{
		if (index > this->Size || index < 0)
			throw index_out_of_bounds;
		else if (this->Size == this->Capacity)
			throw list_full;
		else if (index == this->Size)
		{
			this->List[index] = new T [sizeof(T)];
			*this->List[index] = newElem;
			this->Size++;
		}
		else
		{
			this->Size++;
			this->List[this->Size] = new T [sizeof(T)];
			for (int i = this->Size-1; i > index; i--)
				this->List[i] = this->List[i - 1];
			*this->List[index] = newElem;
			return *this;
		}
	}
	catch (exception& e)
	{
		cout << "Exceptie la INSERT: " << e.what() << '\n';
	}
	return *this;
}

template <class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	try
	{
		if (index > this->Size || index < 0)
			throw index_out_of_bounds;
		else if (this->Size + otherArray.Size == this->Capacity)
			throw list_full;
		else
		{
			for (int i = this->Size + 1; i <= this->Size + otherArray.Size; i++)
				this->List[i] = new T*[sizeof(T)];
			this->Size += otherArray.Size;
			for (int i = this->Size; i > index; i--)
				this->List[i] = this->List[i - 1];
			int temp_i = 0;
			while (temp_i <= otherArray.Size)
			{
				if(*otherArray.List[temp_i]!=nullptr)
				this->List[index] = otherArray.List[temp_i++];
			}
			return *this;
		}
	}
	catch (exception& e)
	{
		cout << "Exceptie la INSERT: " << e.what() << '\n';
	}
	return *this;

}

template <class T>
const Array<T>& Array <T> ::operator+=(const T& newElem)
{
	try
	{
		if (this->Size == this->Capacity)
		{
			throw list_full;
		}
		else
		{
			this->Insert(this->Size, newElem);
			return *this;
		}
	}
	catch (exception& e)
	{
		cout << "Eroare la operatorul+=: " << e.what() << '\n';
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	try 
	{
		if (index > this->Size || index < 0)
			throw index_out_of_bounds;
		else
		{
			for (int i = index; i < this->Size-1; i++)
				this->List[i] = this->List[i + 1];
			delete[] this->List[this->Size-1];
			this->Size--;
		}
	}
	catch (exception& e)
	{
		cout << "Eroare la DELETE: " << e.what() << '\n';
	}
	return *this;

}

template<class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{

	delete[] this->List;
	this->Capacity = otherArray.Capacity;
	this->Size = otherArray.Size;

	this->List = new T * [this->Capacity];

	for (int i = 0; i < this->Size; ++i)
	{
		this->List[i] = new T[sizeof(T)];
		this->List[i] = otherArray.List[i];
	}
	return true;
}

template<class T>
void Array<T> ::Sort()
{
	bool ok = 0;
	do
	{
		ok = 0;
		for (int i = 0; i < this->Size - 1; i++)
		{
			if (List[i] < List[i + 1])
			{
				swap(List[i], List[i + 1]);
				ok = 1;
			}
		}
	} while (ok == 1);
}

template<class T>
void Array<T> :: Sort(int(*compare)(const T&, const T&))
{
	bool ok = 0;
	do
	{
		ok = 0;
		for (int i = 0; i < this->Size - 1; i++)
		{
			if (compare(*List[i],*List[i+1])>0)
			{
				swap(List[i], List[i + 1]);
				ok = 1;
			}
		}
	} while (ok == 1);
}

template<class T>
void Array<T>::Sort(Compare* comparator)
{
	bool ok = 0;
	do
	{
		ok = 0;
		for (int i = 0; i < this->Size - 1; i++)
		{
			if (comparator->CompareElements(List[i],List[i+1]) > 0)
			{
				swap(List[i], List[i + 1]);
				ok = 1;
			}
		}
	} while (ok == 1);
}

template<class T>
int Array<T>::BinarySearch(const T& elem)
{
	this->Sort();
	int m = this->Size / 2;
	int stg = 0, dr = this->Size-1;
	while (stg != dr)
	{
		cout << "M-u " << ":"<< m << '\n';
		if (*this->List[m] == elem)
			return m;
		else
		{
			if (*this->List[m] > elem)
				dr = m - 1;
			else
				stg = m + 1;
			m = (stg + dr) / 2;
		}
	}
	if (m == 0)
		return -1;
}
template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	this->Sort();
	int m = this->Size / 2;
	int stg = 0, dr = this->Size;
	while (stg != dr)
	{
		if (compare(*this->List[m],elem) == 0)
			return m;
		else
		{
			if (compare(*this->List[m], elem) == -1)
				dr = m - 1;
			else
				stg = m + 1;
			m = (stg + dr) / 2;
		}
	}
	return -1;
}
template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	this->Sort();
	int m = this->Size / 2;
	int stg = 0, dr = this->Size;
	while (stg != dr)
	{
		if (comparator->CompareElements(this->List[m],elem)==0)
			return m;
		else
		{
			if (comparator->CompareElements(this->List[m], elem) == -1)
				dr = m - 1;
			else
				stg = m + 1;
			m = (stg + dr) / 2;
		}
	}
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < this->Size; i++)
		if (*this->List[i] == elem)
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < this->Size; i++)
		if (compare(*this->List[i], elem))
			return i;
	return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i = 0; i < this->Size; i++)
		if (comparator->CompareElements(this->List[i], elem) == 0)
			return i;
	return -1;
}

template<class T>
void Array<T>::DebugPrint()
{
	for (int i = 0; i < this->Size; i++)
		cout << *this->List[i] << " ";
	cout << '\n';
}

int main()
{
	Array<int> d(3);

	printf("d: ");

	d += 1;
	d += 3;
	d += 6;
	d.Delete(0);

	d.DebugPrint();

	Array<int> x(50);

	x += 3;
	x += 12;
	x += 11;
	x += 9;
	x += 7;

	printf("x inainte de insert: ");
	x.DebugPrint();

	x.Insert(2, 13);

	printf("x dupa insert: ");
	x.DebugPrint();

	x.Sort(compare);

	printf("x dupa sort: ");
	x.DebugPrint();


	printf("\n-------TEST CAUTARE BINARA--------\n\nSe afla 3 in x?\nRaspunsul este: ");

	if (x.BinarySearch(3) == -1)
		printf("nu\n");
	else
		printf("da, la indexul %d\n", x.BinarySearch(3, compare));

	printf("\n----------------------------------\n");


	printf("\n-------TEST CAUTARE LINIARA-------\n\nSe afla 12 in x?\nRaspunsul este: ");

	if (x.Find(12) == -1)
		printf("nu\n");
	else
		printf("da, la indexul %d\n", x.Find(12, compare));

	printf("\n----------------------------------\n");

	printf("\n");
	system("pause");

	return 0;
}