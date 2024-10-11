#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;

public:
    // Конструктор
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    // Операторы как скрытые друзья
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
    friend std::istream& operator>>(std::istream& is, Contact& contact);
    friend bool operator==(const Contact& lhs, const Contact& rhs);
};

#endif // CONTACT_H
