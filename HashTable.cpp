#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size, int (*getHash) (const string&)) {
	this->size = size;
	this->getHash = getHash;

	table = new Node*[size];

	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

void HashTable::Print() const {
	for (int i = 0; i < size; i++) {
		if (!table[i]) 
			continue;
		
		cout << "[" << i << "]:";
		Node* tmp = table[i];

		while (tmp) {
			cout << " " << tmp->value;
			tmp = tmp->next;
		}

		cout << endl;
	}
}

// вставка элемента
void HashTable::Insert(const string& key, int value) {
	int index = getHash(key); // находим индекс для вствки

	// создаём указатель на элемнет
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;

	// если ещё нет элементов в списке, то вставляем его и выходим
	if (!table[index]) {
		table[index] = node; 
		return;
	}

	Node* tmp = table[index]; // элемент для поиска конца списка 

	// ищем конец списка
	while (tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = node; // добавляем элемент в конец
}

void HashTable::Remove(const string& key) {
	int index = getHash(key); // находим индекс для удаления

	while (table[index]) {
		Node* tmp = table[index];
		table[index] = table[index]->next;
		delete tmp;
	}
}

void HashTable::Search(const string& key) const {
	int index = getHash(key); // находим индекс 

	Node* tmp = table[index];

	if (!tmp) {
		cout << "No values for key '" << key << "'" << endl;
		return;
	}

	while (tmp) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
}

void HashTable::SaveInfo(const string& path) const {
	ofstream f(path.c_str());

	if (!f) 
		throw string("HashTable::SaveInfo: error open file.");

	for (int i = 0; i < size; i++) {
		int count = 0;
		Node* tmp = table[i];

		while (tmp) {
			count++;
			tmp = tmp->next;
		}

		f << count << endl; 
	}

	f.close();
}

HashTable::~HashTable() {
	for (int i = 0; i < size; i++) {
		while (table[i]) {
			Node* tmp = table[i];
			table[i] = table[i]->next;
			delete tmp;
		}
	}

	delete[] table;
}