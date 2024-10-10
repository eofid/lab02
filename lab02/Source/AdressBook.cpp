#include "AdressBook.h"
#include <iostream>
#include <fstream>

// ���������� ������ ��������
void AddressBook::addContact() {
    std::string name, phone, email;
    std::cout << "������� ���: ";
    std::cin >> name;
    std::cout << "������� �������: ";
    std::cin >> phone;
    std::cout << "������� email: ";
    std::cin >> email;

    contacts.emplace_back(name, phone, email);
    std::cout << "������� ��������!\n";
}

// �������������� �������� �� �����
void AddressBook::editContact() {
    std::string name;
    std::cout << "������� ��� �������� ��� ��������������: ";
    std::cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "�������������� �������� " << contact.name << std::endl;
            std::cout << "������� ����� ���: ";
            std::cin >> contact.name;
            std::cout << "������� ����� �������: ";
            std::cin >> contact.phone;
            std::cout << "������� ����� email: ";
            std::cin >> contact.email;
            std::cout << "������� ��������!\n";
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// �������� �������� �� �����
void AddressBook::deleteContact() {
    std::string name;
    std::cout << "������� ��� �������� ��� ��������: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "������� ������!\n";
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// ����� �������� �� �����
void AddressBook::searchContact() const {
    std::string name;
    std::cout << "������� ��� ��� ������: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "���: " << contact.name << std::endl;
            std::cout << "�������: " << contact.phone << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// ����� ���� ���������
void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "�������� ����� �����.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "���: " << contact.name << std::endl;
        std::cout << "�������: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "-------------------\n";
    }
}

// ���������� ��������� � ����
void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������.\n";
        return;
    }

    for (const auto& contact : contacts) {
        file << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    }

    std::cout << "�������� ������� ��������� � ����: " << filename << "\n";
}

// �������� ��������� �� �����
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������.\n";
        return;
    }

    contacts.clear();  // ������� ������� ��������

    std::string name, phone, email;
    while (std::getline(file, name)) {  // ������ �����
        if (std::getline(file, phone) && std::getline(file, email)) {  // ������ �������� � email
            contacts.emplace_back(name, phone, email);  // ��������� ������� � ������
        }
    }

    file.close();
    std::cout << "�������� ��������� �� �����.\n";
}
