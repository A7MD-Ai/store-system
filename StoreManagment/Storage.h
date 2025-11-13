#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include"LinkedList.h"
#include"Product.h"
using namespace std;

class Storage {
	LinkedList list;

public:


	void saveTofile(LinkedList& list){
		ofstream file("StorageDB.csv");

		if (!file.is_open()) {
			cout << "Error opening file\n";
			return;
		}

		file << "ID,Name,Quantity,Price\n";


		Node* current = list.gethead();
		while (current != nullptr) {
			file << current->id << ","
				<< current->name << ","
				<< current->Quantity << ","
				<< current->price << "\n";
			current = current->next;
		}
		file.close();
	}

	void loadfromfile(LinkedList& list) {
		ifstream file("StorageDB.csv");

		if (!file.is_open()) {
			cout << "Error opening file\n";
			return;
		}

		string line1;
		getline(file, line1);

		string line;
		while (getline(file, line)) {

			stringstream ss(line);
			string idStr, name, priceStr, quantityStr;

			getline(ss, idStr, ',');
			getline(ss, name, ',');
			getline(ss, quantityStr, ',');
			getline(ss, priceStr, ',');
			 
			Node load;

			 load.id = stoi(idStr);
			 load.name = name;
			 load.Quantity = stoi(quantityStr);
			 load.price = stod(priceStr);

			 list.addProductfromfile(&load);
		}

		file.close();
	}
};