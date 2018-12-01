#include <iostream>
#include <cstdlib>
#include <string>

#include "HashTable.h"

using namespace std;

bool checkKey(const string& key) {
	if (key.length() != 6) 
		return false;

	if (key[0] < '0' || key[0] > '9')
		return false;

	if (key[1] < '0' || key[1] > '9')
		return false;

	if (key[2] < 'A' || key[2] > 'Z')
		return false;
	
	if (key[3] < 'A' || key[3] > 'Z')
		return false;

	if (key[4] < '0' || key[4] > '9')
		return false;
	
	if (key[5] < 'A' || key[5] > 'Z')
		return false;

	return true;
}

int gethash(const string& key) {
	int res = 0;

	for (int i = 0; i < key.length(); i++) 
		res += key[i] * key[i] * key[i] * key[i];
	
	return res % 1500;
}

string getRndKey() {
	string key = "";

	key += '0' + rand() % 10;
	key += '0' + rand() % 10;
	key += 'A' + rand() % 26;
	key += 'A' + rand() % 26;
	key += '0' + rand() % 10;
	key += 'A' + rand() % 26;

	return key;
}

void Print(HashTable& table) {
	table.Print();
}

void Insert(HashTable& table) {
	string key;
	int value;

	cout << "Enter key, value: ";
	cin >> key >> value;

	while (!checkKey(key)) {
		cout << "Enter key again: ";
		cin >> key;
	}

	table.Insert(key, value);
}

void Remove(HashTable& table) {
	string key;

	cout << "Enter key: ";
	cin >> key;

	while (!checkKey(key)) {
		cout << "Enter key again: ";
		cin >> key;
	}

	table.Remove(key);
}

void Search(HashTable& table) {
	string key;

	cout << "Enter key: ";
	cin >> key;

	while (!checkKey(key)) {
		cout << "Enter key again: ";
		cin >> key;
	}

	table.Search(key);
}

void Save(HashTable& table) {
	string path;

	cout << "Enter path to file: ";
	cin >> path;

	table.SaveInfo(path);
}

void FillRandom(HashTable& table) {
	int n;

	cout << "Enter count of elements: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		table.Insert(getRndKey(), i);
	}
}

int main() {
	HashTable table(1500, gethash);
    int item; // выбираемый пункт меню

    do {
        system("cls"); // очищаем экран
        // выводим меню
        cout << "What do you want to do?" << endl;
        cout << "1. Print" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Search" << endl;
        cout << "5. Save" << endl;
        cout << "6. Fill random" << endl;
        cout << "7. Quit" << endl;
        cout << ">";
        cin >> item; // считываем пункт меню

        // обрабатываем некорректный ввод
        while(item < 1 || item > 7) {
            cout << "Incorrect titem. Try again: ";
            cin >> item; // считываем пункт меню заново
        }

        switch (item) {
            case 1:
                Print(table);
                break;

            case 2:
                Insert(table);
                break;

            case 3:
                Remove(table);
                break;

            case 4:
                Search(table);
                break;

            case 5:
                Save(table);
                break;

            case 6:
            	FillRandom(table);
            	break;
        }

        if (item != 7) {
            system("pause"); // задерживаем экран
        }
    } while (item != 7); // повторяем, пока не решим выйти

    return 0;
}