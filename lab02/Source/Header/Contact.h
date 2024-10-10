#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string email;

    // Конструктор с параметрами
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    // Дружественная функция для перегрузки оператора "=="
    friend bool operator==(const Contact& lhs, const Contact& rhs);

    // Метод для записи контакта в поток
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

    // Метод для чтения контакта из потока
    friend std::istream& operator>>(std::istream& is, Contact& contact);
};

#endif // CONTACT_H
