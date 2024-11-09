#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Contact
{
    string Name;
    string PhoneNumber;
    string Email;

    void Display_Contact()const
    {
        cout << "Name: " << Name << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Email: " << Email << endl;
    }

};

class AddressBook
{
private:
    vector<Contact> contacts;

public:
    void AddContact(const Contact &con)
    {
        contacts.push_back(con);
    }

    void UpdateContact(const string &name)
    {
        auto it = find_if(contacts.begin(),contacts.end(),[&name](const Contact &con){return con.Name == name;});

        if(it != contacts.end())
        {
            cout << "Enter new details for " << name << '\n';
            cout << "New Phone Number: ";
            cin >> it->PhoneNumber;
            cout << "New Email: ";
            cin >> it->Email;
        }
        else
        {
            cout << "Contact can't be found.\n";
        }
    }

    void SearchContact(string &name)
    {
        auto it = find_if(contacts.begin(),contacts.end(),[&name](Contact &con){return con.Name == name;});

        if(it != contacts.end())
        {
            it->Display_Contact();
        }
        else
        {
            cout << "Contact can't be found.\n";
        }
    }
};




int main()
{
    AddressBook Book;
    int selected;
    string name;

    do
    {
        cout << "\nAddress Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Update Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> selected;

        switch(selected)
        {
            case 1:
            {
                Contact new_person;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin,new_person.Name);
                cout << "Enter phone number: ";
                cin >> new_person.PhoneNumber;
                cout << "Enter email: ";
                cin >> new_person.Email;
                Book.AddContact(new_person);
                break;
            }
            case 2:
            {
                cout << "Enter the name of the contact to Update: ";
                cin.ignore();
                getline(cin,name);
                Book.UpdateContact(name);
                break;
            }
            case 3:
            {
                cout << "Enter the name of the contact to Search: ";
                cin.ignore();
                getline(cin,name);
                Book.SearchContact(name);

                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }while(selected != 4);

    cout << "See you soon";
    return 0;
}
