#include <iostream>
#include <string>

using namespace std;

class Abonent
{
public:
    string name;
    string phone;

    Abonent(string n = "", string p = "")
        : name(n), phone(p) {
    }
};

class PhoneBook
{
private:
    Abonent* abonents;
    int countAbonent;

public:
    PhoneBook()
    {
        abonents = nullptr;
        countAbonent = 0;
    }

    ~PhoneBook()
    {
        delete[] abonents;
    }

    void Add(const Abonent& a)
    {
        Abonent* temp = new Abonent[countAbonent + 1];

        for (int i = 0; i < countAbonent; i++)
            temp[i] = abonents[i];

        temp[countAbonent] = a;

        delete[] abonents;
        abonents = temp;
        countAbonent++;
    }

    void Delete(const string& phone)
    {
        int index = -1;

        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].phone == phone)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Абонента не знайдено\n";
            return;
        }

        Abonent* temp = new Abonent[countAbonent - 1];

        for (int i = 0, j = 0; i < countAbonent; i++)
        {
            if (i != index)
                temp[j++] = abonents[i];
        }

        delete[] abonents;
        abonents = temp;
        countAbonent--;

        cout << "Абонента видалено\n";
    }

    void SearchByName(const string& name) const
    {
        bool found = false;

        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].name == name)
            {
                cout << abonents[i].name << " | "
                    << abonents[i].phone << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Абонента не знайдено\n";
    }

    void SearchByPhone(const string& phone) const
    {
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].phone == phone)
            {
                cout << abonents[i].name << " | "
                    << abonents[i].phone << endl;
                return;
            }
        }
        cout << "Абонента не знайдено\n";
    }

    void ShowAll() const
    {
        if (countAbonent == 0)
        {
            cout << "Телефонна книга порожня\n";
            return;
        }

        for (int i = 0; i < countAbonent; i++)
        {
            cout << abonents[i].name << " | "
                << abonents[i].phone << endl;
        }
    }
};

int main()
{
    PhoneBook pb;

    pb.Add(Abonent("Іваненко Іван Іванович", "111111"));
    pb.Add(Abonent("Петренко Петро Петрович", "222222"));

    pb.ShowAll();

    cout << "\nПошук за ПІБ:\n";
    pb.SearchByName("Іваненко Іван Іванович");

    cout << "\nВидалення:\n";
    pb.Delete("111111");

    cout << "\nВсі абоненти:\n";
    pb.ShowAll();

    return 0;
}