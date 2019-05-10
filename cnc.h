#pragma once
#include <iostream>
#include <fstream>

struct Event
{
	char name[64];
	int residue;
	int capacity;
	char data_time[32];
	int n_of_booking;
};

int dataCmp(const void * x1, const void * x2);
int nameCmp(const void * x1, const void * x2);

class Concert {
	int n;
	int size;
	Event * array;

public:
	Concert() {
		array = nullptr;
		size = n = 0;
	}

	Concert(const int l)
	{
		n = 0;
		if (l < 0)
		{
			size = 0;
			array = nullptr;
			std::cout << "Error! size < 0" << std::endl << "Default dimensions(0) are set" << std::endl;
		}
		else
		{
			size = l;
			array = new Event[size];
		}
	}

	virtual ~Concert()
	{
		delete[] this->array;
	}

	Concert(Concert const& source) {//конструктор копирования
		size = source.size;
		n = source.n;
		array = new Event[size];

		for (int i = 0; i < size; i++)
		{
			array[i] = source.array[i];
		}
	}

	Concert(Concert&& source) {//конструктор перемещения
		size = source.size;
		n = source.n;
		array = source.array;
		source.array = nullptr;
	}

	int getN() const
	{
		return n;
	}

	int getSize() const
	{
		return size;
	}

	Event& operator[] (const int l)
	{
		try
		{
			if (l < 0 || l >= this->getSize())
			{
				throw 1;
			}
			return this->array[l];
		}
		catch (...)
		{
			std::cout << "Error! Invalid index" << std::endl;
			system("pause");
			exit(1);
		}
	}

	void sortData()
	{
		qsort(this->array, this->getN(), sizeof(Event), dataCmp);
	}

	void sortName()
	{
		qsort(this->array, this->getN(), sizeof(Event), nameCmp);
	}

	void book(const int l)
	{
		if (l < 1 || l > this->getN())
		{
			std::cout << "Error! Incorrect number of concert";
		}
		else if (this->array[l - 1].residue == 0)
		{
			std::cout << "No tickets avilable";
		}
		else
		{
			this->array[l - 1].n_of_booking++;
			this->array[l - 1].residue--;
		}
	}

	friend std::ostream& operator<< (std::ostream &out, const Concert &obj);

	friend std::ifstream& operator>> (std::ifstream & in, Concert &obj);

	void addMem()
	{
		if (this->getSize() == 0)
		{
			this->array = new Event[30];
			this->size += 30;
		}
		else
		{
			Event* tempObj = new Event[this->getSize() + 10];
			this->size += 10;

			for (int i = 0; i < this->getSize(); i++)
			{
				tempObj[i] = this->array[i];
			}
			delete[] this->array;

			this->array = tempObj;
		}
	}
};