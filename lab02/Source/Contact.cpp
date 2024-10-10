#include "Contact.h"

// ���������� ������������ Contact
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

// ���������� ���������� ��������� "=="
bool operator==(const Contact& lhs, const Contact& rhs) {
    return (lhs.name == rhs.name) && (lhs.phone == rhs.phone) && (lhs.email == rhs.email);
}

// ���������� ��������� ������ (��� ������ � ����)
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    return os;  // ���������� �����
}
