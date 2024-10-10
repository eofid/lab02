#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string email;

    // ����������� � �����������
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    // ������������� ������� ��� ���������� ��������� "=="
    friend bool operator==(const Contact& lhs, const Contact& rhs);

    // ����� ��� ������ �������� � �����
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

    // ����� ��� ������ �������� �� ������
    friend std::istream& operator>>(std::istream& is, Contact& contact);
};

#endif // CONTACT_H
