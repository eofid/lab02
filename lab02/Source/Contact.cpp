#include "Contact.h"

// Реализация конструктора
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

// Реализация перегрузки оператора "=="
bool operator==(const Contact& lhs, const Contact& rhs) {
    return (lhs.name == rhs.name) && (lhs.phone == rhs.phone) && (lhs.email == rhs.email);
}

// Реализация оператора вывода (<<) для записи в поток
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    return os;
}

// Реализация оператора ввода (>>) для чтения из потока
std::istream& operator>>(std::istream& is, Contact& contact) {
    std::getline(is, contact.name);
    std::getline(is, contact.phone);
    std::getline(is, contact.email);
    return is;
}
