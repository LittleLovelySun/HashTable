#pragma once

#include <iostream>
#include <string>
#include <fstream>

class HashTable {
	// элемент таблицы 
	struct Node {
		int value;
		Node* next; 
	};

	int size; // размер таблицы
	Node** table; // массив указателей на талицу 
	int (*getHash) (const std::string&); // указатель на хеш-функцию

public:
	HashTable(int size, int (*getHash) (const std::string&));

	void Print() const;
	void Insert(const std::string& key, int value);
	void Remove(const std::string& key);
	void Search(const std::string& key) const;
	void SaveInfo(const std::string& path) const;

	~HashTable();
};