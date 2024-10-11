#include "Contact.h"

// Реализация конструктора
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

// Реализация скрытого друга — оператора <<
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    return os;
}
