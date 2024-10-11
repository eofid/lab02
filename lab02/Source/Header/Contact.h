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

    // Сделаем оператор << скрытым другом класса Contact
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
};

#endif // CONTACT_H
