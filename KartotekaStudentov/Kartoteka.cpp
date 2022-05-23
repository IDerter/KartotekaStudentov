#include "Kartoteka.h"
void Student::SetAge(int valueage)
{
	age = valueage;
}
int Student::GetAge ()
{
	return age;
}
int Student::GetNumber()
{
	return number;
}
void Student::SetNumber(int number)
{
	this->number = number;
}
int Student::GetNummarks()
{
	return nummarks;
}
void Student::SetNummarks(int valueage)
{
	nummarks = valueage;
}
std::string Student::GetName()
{
	return name;
}
void Student::SetSurname(std::string valuesurname)
{
	surname = valuesurname;
}
std::string Student::GetSurname()
{
	return surname;
}
void Student::SetName(std::string valuename)
{
	name = valuename;
}
void Student::SetMarks(std::vector <int>& mas, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		int a = 2 + rand() % 4;
		mas.push_back(a);
		marks.push_back(a);
		std::cout << mas[i] << " ";
	}
	
}
void Student::GetMarks()
{
	for (int i = 0; i < marks.size(); i++)
	{
		std::cout << marks[i] << " ";
	}
}
float Student::ArifmMarks(std::vector <int>& mas, int size)
{

	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += mas[i];
	}
	arifmmarks = (sum / GetNummarks());
	return arifmmarks;
}
float Student::GetArifMarks()
{
	return arifmmarks;
}

void Student::SetArifMarks(float arifmmarks)
{
	this->arifmmarks = arifmmarks;
}
