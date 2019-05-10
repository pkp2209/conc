#include "cnc.h"
#include <cstring>
#include <iomanip>

int dataCmp(const void * x1, const void * x2)
{
	Event* k = (Event *)x1;
	Event* m = (Event *)x2;
	return (strcmp(k->data_time, m->data_time));
}

int nameCmp(const void * x1, const void * x2)
{
	Event* k = (Event *)x1;
	Event* m = (Event *)x2;
	return (strcmp(k->name, m->name));
}

std::ostream& operator<< (std::ostream &out, const Concert &obj)
{
	for (int i = 0; i < obj.n; i++)
	{
		out << i + 1 << ") " << std::setw(20) << std::left << obj.array[i].name << " " << std::setw(7) << std::right << obj.array[i].residue << "/" << std::setw(7) << std::left << obj.array[i].capacity << " " << obj.array[i].data_time << std::endl;
	}

	out << std::endl;

	return out;
}

std::ifstream& operator>> (std::ifstream & in, Concert &obj)
{
	if (obj.getN() == obj.getSize())
	{
		obj.addMem();
	}

	char buffer[64] = { NULL };
	in.getline(obj.array[obj.n].name, 64, ';');
	in.getline(buffer, 64, ';');
	obj.array[obj.n].capacity = atoi(buffer);
	strcpy_s(buffer, "");
	in.getline(buffer, 64, ';');
	obj.array[obj.n].residue = atoi(buffer);
	strcpy_s(buffer, "");
	in.getline(obj.array[obj.n].data_time, 64, '\n');
	(obj.n)++;

	return in;
}