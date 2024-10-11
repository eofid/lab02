#include "AdressBook.h"
#include <iostream>
#include <fstream>

// Äîáàâëåíèå íîâîãî êîíòàêòà
void AddressBook::addContact() {
    std::string name;
    std:: string phone;
    std:: string email;
    std::cout << "Ââåäèòå èìÿ: ";
    std::cin >> name;
    std::cout << "Ââåäèòå òåëåôîí: ";
    std::cin >> phone;
    std::cout << "Ââåäèòå email: ";
    std::cin >> email;

    contacts.emplace_back(name, phone, email);
    std::cout << "Êîíòàêò äîáàâëåí!\n";
}

// Ðåäàêòèðîâàíèå êîíòàêòà ïî èìåíè
void AddressBook::editContact() {
    std::string name;
    std::cout << "Ââåäèòå èìÿ êîíòàêòà äëÿ ðåäàêòèðîâàíèÿ: ";
    std::cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Ðåäàêòèðîâàíèå êîíòàêòà " << contact.name << std::endl;
            std::cout << "Ââåäèòå íîâîå èìÿ: ";
            std::cin >> contact.name;
            std::cout << "Ââåäèòå íîâûé òåëåôîí: ";
            std::cin >> contact.phone;
            std::cout << "Ââåäèòå íîâûé email: ";
            std::cin >> contact.email;
            std::cout << "Êîíòàêò îáíîâëåí!\n";
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Óäàëåíèå êîíòàêòà ïî èìåíè
void AddressBook::deleteContact() {
    std::string name;
    std::cout << "Ââåäèòå èìÿ êîíòàêòà äëÿ óäàëåíèÿ: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "Êîíòàêò óäàëåí!\n";
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Ïîèñê êîíòàêòà ïî èìåíè
void AddressBook::searchContact() const {
    std::string name;
    std::cout << "Ââåäèòå èìÿ äëÿ ïîèñêà: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Èìÿ: " << contact.name << std::endl;
            std::cout << "Òåëåôîí: " << contact.phone << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Âûâîä âñåõ êîíòàêòîâ
void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "Àäðåñíàÿ êíèãà ïóñòà.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "Èìÿ: " << contact.name << std::endl;
        std::cout << "Òåëåôîí: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "-------------------\n";
    }
}

// Ñîõðàíåíèå êîíòàêòîâ â ôàéë
void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Íå óäàëîñü îòêðûòü ôàéë äëÿ çàïèñè.\n";
        return;
    }

    for (const auto& contact : contacts) {
        file << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    }

    std::cout << "Êîíòàêòû óñïåøíî ñîõðàíåíû â ôàéë: " << filename << "\n";
}

// Çàãðóçêà êîíòàêòîâ èç ôàéëà
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Íå óäàëîñü îòêðûòü ôàéë äëÿ ÷òåíèÿ.\n";
        return;
    }

    contacts.clear();  // Î÷èùàåì òåêóùèå êîíòàêòû

    std::string name, phone, email;
    while (std::getline(file, name)) {  // ×òåíèå èìåíè
        if (std::getline(file, phone) && std::getline(file, email)) {  // ×òåíèå òåëåôîíà è email
            contacts.emplace_back(name, phone, email);  // Äîáàâëÿåì êîíòàêò â ñïèñîê
        }
    }

    file.close();
    std::cout << "Êîíòàêòû çàãðóæåíû èç ôàéëà.\n";
}
