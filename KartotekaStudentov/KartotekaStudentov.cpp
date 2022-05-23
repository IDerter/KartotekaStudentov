#include "Kartoteka.h"
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
std::ostream& operator<<(std::ostream& os, const Student& student) //возвращает ссылку на объект типа ostream
{
    os << student.age << '/' << student.nummarks << '/' << student.name <<  '/' <<  student.surname;
    return os;
}
std::istream& operator>> (std::istream& in, Student& student) //возвращает ссылку на объект типа ostream
{
    in >> student.age;
    in >> student.nummarks;
    in >> student.name;
    in >> student.surname;
    return in;
}
std::ostream& operator<<(std::ostream& stream, const std::vector<Student>& vec)
{
    for (const auto& b : vec)
        stream << b;
    return stream;
}
bool operator==(const Student& left, const Student& right) {
    return left.nummarks == right.nummarks;
}
int Random(int min, int max) {
    return min + rand() % (max - min);
}
void PrintVector(std::vector <Student>& stud)
{
    for (int i = 0; i < size(stud); i++)
    {
        cout <<stud[i].GetNumber()<<") "<< stud[i] << " " << "Оценки: ";
        stud[i].GetMarks();
        cout << " Средняя оценка студента : " << stud[i].GetArifMarks() << endl;
    }
}
void MaxArifmmarks(std::vector <Student>& stud)
{
    float max = 0;
    int index = 0;
    for (int i = 0; i < stud.size(); i++)
    {
        if (stud[i].GetArifMarks() > max)
        {
            max = stud[i].GetArifMarks();
            index = i;
        }
    }
    cout << stud[index].GetNumber() << ") "<< stud[index] << " Имеет максимальный балл в группе: " << max <<endl;
}
void SortGroup(std::vector <Student>& stud)
{
   

    for (int i = 0; i < stud.size(); i++)
    {
        for (int j = 0; j < stud.size()-1-i; j++)
        {
            if (stud[j].GetArifMarks() < stud[j + 1].GetArifMarks())
            {
                swap(stud[j], stud[j + 1]);
                swap(stud[j].marks, stud[j + 1].marks);
                float srarifm = stud[j].GetArifMarks();
                stud[j].SetArifMarks(stud[j+1].GetArifMarks());
                stud[j + 1].SetArifMarks(srarifm);
                float number = stud[j].GetNumber();
                stud[j].SetNumber(stud[j + 1].GetNumber());
                stud[j + 1].SetNumber(number);
                
            }
        }
    }
    for (int i = 0; i < stud.size(); i++)
    {
        cout << stud[i].GetNumber() << ") " << stud[i] << " " << "Оценки: ";
        stud[i].GetMarks();
        cout << " Средняя оценка студента : " << stud[i].GetArifMarks() << endl;
    }
   
}
Student AddStudent(Student &stud,std::vector <std::string>& name, std::vector <std::string>& surname)
{
    stud.SetAge(18 + rand() % 5);
    stud.SetName(name[rand() % 10]);
    stud.SetName(surname[rand() % 10]);
    stud.SetNummarks(1 + rand() % 5);
    return stud;
}
void SearchStudent(vector <Student>& stud,string* surname)
{
    for (int i = 0; i < stud.size(); i++)
    {
        string surnamejname;
        surnamejname = stud[i].GetName() +  stud[i].GetSurname();
        if (*surname == surnamejname)
        {
            cout << stud[i].GetNumber() << ") " << stud[i] << " " << "Оценки: ";
            stud[i].GetMarks();
            cout << " Средняя оценка студента : " << stud[i].GetArifMarks() << endl;
        }
    }
}
int Student::counter = 0;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    static int countobj = 0;
    vector <string> surname = { "Пупкин","Петров","Батурин","Сидоров","Иванов","Смирнов","Кузнецов","Попов","Васильев","Михайлов"};
    vector <string> name = { "Василий","Петя","Иван","Кирилл","Никита","Максим","Даниил","Владимир","Родион","Денис" };
    int a; //кол-во студентов
    do {
        cout << "Введите количество студентов: ";
        cin >> a;
    } while (a <= 0);
    vector <Student> stud;
    int random = Random(0, a-1);
    cout << "Номер старосты: " << random+1<<endl;
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i < a; i++)
        {
            if (random == i)
            {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, 4); //красный
            }
            stud.push_back(Student(18 + rand() % 5, 1 + rand() % 5, 0, name[rand() % 10], surname[rand() % 10]));
            vector <int> masmarks;
            cout<< stud[i] << " " << "Оценки: ";
            stud[i].GetMarks();
            cout << " Средняя оценка студента : " << stud[i].ArifmMarks(stud[i].marks, stud[i].GetNummarks()) << endl;
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, 7); //белый
        }
        vector <Student> studnew;
        studnew = stud;
        vector <int> del;
        int choose = 0;
        int countdel = 0;
        while (choose != 7)
        {
            cout << "Если хотите добавить студента нажмите - 1"<< endl <<"Удалить - 2"<< endl <<"Найти макс балл - 3"<< endl
                <<"Сортировка студентов по ср баллу - 4"<< endl <<"Поиск студента - 5"<< endl <<"Выйти 7" << endl;
            cin >> choose;
            if (choose == 1)
            {
                stud.push_back(Student(18 + rand() % 5, 1 + rand() % 5, 0,name[rand() % 10], surname[rand() % 10]));
                vector <int> masmarks;
                cout << stud[stud.size() - 1] << " " << "Оценки: ";
                studnew.push_back(stud[stud.size() - 1]);
                stud[stud.size() - 1].GetMarks();
                cout << " Средняя оценка студента : " << stud[stud.size() - 1].ArifmMarks(stud[stud.size() - 1].marks, stud[stud.size() - 1].GetNummarks()) << endl;
            }
            else if (choose == 2)
            {
                int indexdel = 0;
                cout << "Введите номер удаляемого объекта" << endl;
                do {
                    cin >> indexdel;
                } while (indexdel > size(stud)  || indexdel <= 0);

                stud.erase(stud.begin() + indexdel-1);
                for (int i = 0; i < studnew.size(); i++)
                {
                    for (int j = 0; j < stud.size(); j++)
                    {
                        if (studnew[i].GetName() == stud[j].GetName() && studnew[i].GetSurname()== stud[j].GetSurname()&& studnew[i].GetAge() == stud[j].GetAge())
                        {
                            stud[j].marks = studnew[i].marks;
                            int a = studnew[i].GetNummarks();
                            stud[j].SetNummarks(a);
                            stud[j].ArifmMarks(stud[j].marks, stud[j].GetNummarks());
                        }
                    }
                }
                del.push_back(indexdel);
                system("cls"); 
                PrintVector(stud);
            }
            else if (choose == 3)
            {
                MaxArifmmarks(stud);
            }
            else if (choose == 4)
            {
                SortGroup(stud);
            }
            else if (choose == 5)
            {
                string surname;
                string name;
                char A[100];
                cout << "Введите имя:";
                cin >> name;
                cout << "Введите фамилию:";
                cin >> surname;
                string fullname = name + surname;
                SearchStudent(stud, &fullname);
            }
            else if (choose == 7)
            {
                flag = false;
            }   
        }
    }
}
