#include <clocale>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Abiturient{
private:
    char *firstName;
    char *lastName;
    char *familyName;
    char *adress;
    int mark1;
    int mark2;

public: 

    Abiturient(char fName=NULL, char lName=NULL, char famName=NULL, char adr=NULL, int mark1=NULL, int mark2=NULL); //конструктор по умолчанию
    Abiturient(char *fName, char *lName, char *famName, char *adr, int mark1, int mark2); // Конструктор
    Abiturient(const Abiturient&); //конструктор копирования

    void set_id(int tmp);
    const int get_id();

    void set_firstName(char *tmp); //метод
    const char *get_firstName() const; //метод

    void set_lastName(char *tmp);
    const char *get_lastName() const;

    void set_familyName(char *tmp);
    const char *get_familyName() const;

    void set_adress(char *tmp);
    const char *get_adress()const;

    void set_mark1(int tmp);
    const int get_mark1();

    void set_mark2(int tmp);
    const int get_mark2();

    const void show();
    ~Abiturient(); // деструктор

};

Abiturient::Abiturient(char *fName, char *lName, char *famName, char *adr, int mark1, int mark2)
{
    set_firstName(fName);
    set_lastName(lName);
    set_familyName(famName);
    set_adress(adr);
    set_mark1(mark1);
    set_mark2(mark2);

}

Abiturient::~Abiturient()
{
    delete(firstName);
    delete(lastName);
    delete(familyName);
    delete(adress);
}

void Abiturient::set_firstName(char *tmp)
{
    firstName= new char[strlen(tmp)];
    strcpy(firstName, tmp);
}

void Abiturient::set_lastName(char *tmp)
{
    lastName=new char[strlen(tmp)];
    strcpy(lastName, tmp);
}

void Abiturient::set_familyName(char *tmp)
{
    familyName=new char[strlen(tmp)];
    strcpy(familyName, tmp);
}

void Abiturient::set_adress(char *tmp)
{
    adress=new char[strlen(tmp)];
    strcpy(adress, tmp);
}

void Abiturient::set_mark1(int tmp)
{
    mark1 = tmp;
}

void Abiturient::set_mark2(int tmp)
{
    mark2 = tmp;
}

const char *Abiturient::get_firstName()const 
{                                         
    return firstName;                    
}

const char *Abiturient::get_lastName()const
{
    return lastName;
}

const char *Abiturient::get_familyName()const
{
    return familyName;
}

const char *Abiturient::get_adress() const
{
    return adress;
}

const int Abiturient::get_mark1()
{
    return mark1;
}

const int Abiturient::get_mark2()
{
    return mark2;
}

int N = 5;

void Abiturients_not_passed(Abiturient **data) //список абитуриентов, имеющих неудовл оценки
{
    for(int i=0; i<N; i++)
    {
        if (data[i]->get_mark1()<3 || data[i]->get_mark2()<3)
        {
            data[i]->show();
            cout<<"\n";
        }
    }
}

void Abiturients_sum_marks_more_than(Abiturient **data, int limitSumMarks) //список абитуриентов, имеющих неудовл оценки
{
    for(int i=0; i<N; i++)
    {   
        int sumMarks;
        sumMarks = data[i]->get_mark1() + data[i]->get_mark2();
        if (sumMarks>=limitSumMarks)
        {
            data[i]->show();
            cout<<"\n";
        }
    }
}

void Abiturients_N(Abiturient **data, int number) //список N абитуриентов
{
    for(int i=0; i<number; i++)
    {   
        data[i]->show();
        cout<<"\n";
    }
}

const void Abiturient::show()
{
    printf("Name: %s %s %s\nAdress: %s \nMark1: %d \nMark2: %d \n",
        get_firstName(), get_lastName(), get_familyName(), get_adress(), get_mark1(), get_mark2());
}




int main()
{
    setlocale(LC_ALL, "Rus");

    Abiturient **data;
    data = new Abiturient*[N]; // массив объектов
    data[0] = new Abiturient("Pavel", "Snejok", "Volya", "Moscow", 2, 3);
    data[1] = new Abiturient("Andreev", "Konstantin", "Igorevich", "Moscow", 5, 5);
    data[2] = new Abiturient("Semenov", "Mihail", "Nikolaevich", "Moscow", 5, 4);
    data[3] = new Abiturient("Medvedev", "Andrey", "Aleksandrovich", "Moscow", 3, 2);
    data[4] = new Abiturient("Kanareykin", "Igor", "Dmitrievich", "Moscow", 4, 5);

    cout<<"Список студентов: \n";
    for(int i=0; i<N; i++)
    {
        data[i]->show();
        cout<<"\n";
    }
    cout<<"******************************************";
    cout<<"\n";

    cout<<"task1: Студенты, имеющие неудовл оценки\n";
    Abiturients_not_passed(data);
    cout<<"===========================================\n";

    unsigned int limitSumMarks=6; //сумма оценок
    cout<<"task2: Студенты, имеющие сумму оценок не меньше заданной " <<limitSumMarks<<"\n";
    Abiturients_sum_marks_more_than(data, limitSumMarks);
    cout<<"===========================================\n";

    unsigned int N = 2; //N абитуриентов
    cout<<"task3: Выбрать N абитуриентов, имеющих самую высокую сумму баллов, и список абитуриентов, имеющих полупроходной балл.\n";
    Abiturients_N(data, N);


    for(int i=0; i<N; i++)
        delete data[i];
    delete []data;

    return 0;
}
