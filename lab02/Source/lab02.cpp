#include <iostream>
#include <string>
#include "AdressBook.h"

using namespace std;

// Функция для отображения меню
void showMenu() {
    cout << "1. Добавить контакт\n";
    cout << "2. Редактировать контакт\n";
    cout << "3. Удалить контакт\n";
    cout << "4. Поиск контакта\n";
    cout << "5. Вывести все контакты\n";
    cout << "6. Записать контакты в файл\n";
    cout << "7. Загрузить контакты из файла\n";
    cout << "8. Выход\n";
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "rus");
    AddressBook addressBook;
    int choice;
    string filename;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addressBook.addContact();
            break;
        case 2:
            addressBook.editContact();
            break;
        case 3:
            addressBook.deleteContact();
            break;
        case 4:
            addressBook.searchContact();
            break;
        case 5:
            addressBook.displayContacts();
            break;
        case 6:
            cout << "Введите имя файла для сохранения: ";
            cin >> filename;
            addressBook.saveToFile(filename);  // Записываем контакты в файл
            break;
        case 7:
            cout << "Введите имя файла для загрузки: ";
            cin >> filename;
            addressBook.loadFromFile(filename);  // Загружаем контакты из файла
            break;
        case 8:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 8);

    return 0;
}
