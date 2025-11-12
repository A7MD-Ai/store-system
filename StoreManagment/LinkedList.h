#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include <iomanip>
#include "Product.h"

using namespace std;

/*inline*/ int validateInput();
/*inline*/ double validateInputDouble();
		  
class LinkedList{

 private:
 	Node* head;
	Node* tail;

public:
	

	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void AddProduct() {
		Node* New_product = new Node;

		cout << "Enter product name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, New_product->name);

		cout << "\nEnter product price: ";
		New_product->price = validateInputDouble();

		cout << "\nEnter product quantity: ";
		New_product->Quantity = validateInput();

		int id = 1;
		if (head == nullptr) {

			New_product->id = id;
			New_product->next = nullptr;
			head = New_product;
			tail = New_product;
		}
		else{

			Node* current = tail;
			New_product->id = current->id+1;
			current->next = New_product;
			tail = New_product;

			New_product->next = nullptr;
		}
		
	}
	void DeleteProduct() {


		if (head == nullptr)
		{
			cout << "there are no products.";
		}
		else {
			int ID;
			cout << "Enter id: ";
			ID = validateInput();

			Node* rev = nullptr;
			Node* current = head;

			while (current != nullptr && current->id != ID) {
				rev = current;
				current = current->next;
			}

			if (current == nullptr) {
				cout << "product not found.";
				return;
			}

			if (current == head) {
				head = current->next;
				delete current;
				current = nullptr;
				UpdateIds();
				return;
		    }
			
			rev->next = current->next;
			delete current;
			current = nullptr;
			UpdateIds();
		
		}
	}
	void UpdateIds() {
		int Ids = 1;
		if (head != nullptr) {
			Node* current = head;

			while (current != nullptr) {
				current->id = Ids;
				current = current->next;
				Ids += 1;
			}

		}
	}	
	void displayTable() {
		if (head == nullptr) {
			cout << "\nNo products available.\n";
			return;
		}

		int idWidth = 2;
		int nameWidth = 4;
		int qtyWidth = 8;
		int priceWidth = 6;

		Node* current = head;
		
		while (current != nullptr) {
			idWidth = max(idWidth, (int)to_string(current->id).length());
			nameWidth = max(nameWidth, (int)current->name.length());
			qtyWidth = max(qtyWidth, (int)to_string(current->Quantity).length());

			string priceStr = to_string(current->price);

			if (priceStr.find('.') != string::npos) {
				priceStr = priceStr.substr(0, priceStr.find('.') + 3);
			}
			priceWidth = max(priceWidth, (int)priceStr.length());
			current = current->next;
		}


		int totalWidth = idWidth + nameWidth + qtyWidth + priceWidth + 13;

		cout << "\n";
		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";
		cout << "| " << setw(idWidth) << "ID"
			<< " | " << setw(nameWidth) << "Name"
			<< " | " << setw(qtyWidth) << "Quantity"
			<< " | " << setw(priceWidth) << "Price"
			<< " |\n";
		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";

		current = head;
		while (current != nullptr) {
			cout << "| " << setw(idWidth) << current->id
				<< " | " << setw(nameWidth) << current->name
				<< " | " << setw(qtyWidth) << current->Quantity
				<< " | " << setw(priceWidth) << fixed << setprecision(2) << current->price
				<< " |\n";
			current = current->next;
		}

		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n\n";
		
	}
	void searchbyID() {
	int ID;
		cout << "Enter id: ";
		ID = validateInput();

		Node* current = head;
		while (current != nullptr && current->id != ID) {
			current = current->next;
		}
			if (current == nullptr) {
				cout << "\nproduct not found.";
			}

			int idWidth = 2;
			int nameWidth = 4;
			int qtyWidth = 8;
			int priceWidth = 6;

			Node* temp = head;
			while (temp != nullptr) {
				idWidth = max(idWidth, (int)to_string(temp->id).length());
				nameWidth = max(nameWidth, (int)temp->name.length());
				qtyWidth = max(qtyWidth, (int)to_string(temp->Quantity).length());

				string priceStr = to_string(temp->price);
				if (priceStr.find('.') != string::npos) {
					priceStr = priceStr.substr(0, priceStr.find('.') + 3);
				}
				priceWidth = max(priceWidth, (int)priceStr.length());
				temp = temp->next;
			}

			int totalWidth = idWidth + nameWidth + qtyWidth + priceWidth + 13;

			cout << "\n";
			cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";
			cout << "| " << setw(idWidth) << "ID"
				<< " | " << setw(nameWidth) << "Name"
				<< " | " << setw(qtyWidth) << "Quantity"
				<< " | " << setw(priceWidth) << "Price"
				<< " |\n";
			cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";

			cout << "| " << setw(idWidth) << current->id
				<< " | " << setw(nameWidth) << current->name
				<< " | " << setw(qtyWidth) << current->Quantity
				<< " | " << setw(priceWidth) << fixed << setprecision(2) << current->price
				<< " |\n";

			cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n\n";
			
	}
	void searchbyName() {
		string name;
		cout << "Product name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);

		Node* current = head;
		while (current != nullptr && current->name != name) {
			current = current->next;
		}

		if (current == nullptr) {
			cout << "\nProduct not found.\n";
			return;
		}

		int idWidth = 2;
		int nameWidth = 4;
		int qtyWidth = 8;
		int priceWidth = 6;

		Node* temp = head;
		while (temp != nullptr) {
			idWidth = max(idWidth, (int)to_string(temp->id).length());
			nameWidth = max(nameWidth, (int)temp->name.length());
			qtyWidth = max(qtyWidth, (int)to_string(temp->Quantity).length());

			string priceStr = to_string(temp->price);
			if (priceStr.find('.') != string::npos) {
				priceStr = priceStr.substr(0, priceStr.find('.') + 3);
			}
			priceWidth = max(priceWidth, (int)priceStr.length());
			temp = temp->next;
		}

		int totalWidth = idWidth + nameWidth + qtyWidth + priceWidth + 13;

		cout << "\n";
		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";
		cout << "| " << setw(idWidth) << "ID"
			<< " | " << setw(nameWidth) << "Name"
			<< " | " << setw(qtyWidth) << "Quantity"
			<< " | " << setw(priceWidth) << "Price"
			<< " |\n";
		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n";

		cout << "| " << setw(idWidth) << current->id
			<< " | " << setw(nameWidth) << current->name
			<< " | " << setw(qtyWidth) << current->Quantity
			<< " | " << setw(priceWidth) << fixed << setprecision(2) << current->price
			<< " |\n";

		cout << setfill('-') << setw(totalWidth) << "-" << setfill(' ') << "\n\n";
	}
	void UpdateProduct() {
		int ID;
		cout << "Enter id: ";
		ID = validateInput();

		Node* current = head;
		while (current != nullptr && current->id != ID) {
			current = current->next;
		}

		if (current == nullptr) {
			cout << "\nproduct not found.";
			return;
		}


		cout << "\nNew price ~> ";
		double newPrice = validateInputDouble();
		if (newPrice == NULL) {
			return;
		}
		else {
			current->price = newPrice;
		}

		cout << "\nNew quantity ~> ";
		int newQuantity = validateInput();
		if (newQuantity == NULL) {
			return;
		}
		else {
			current->Quantity = newQuantity;
		}
	}

	Node* gethead() {
		return head;
	}
	void addProductfromfile(Node* load) {
		Node* New_product = new Node;
		New_product->id = load->id;
		New_product->name = load->name;
		New_product->Quantity = load->Quantity;
		New_product->price = load->price;
		New_product->next = nullptr;

		if (head == nullptr) {
			head = New_product;
			tail = New_product;
		}
		else {
			tail->next = New_product;
			tail = New_product;
		}
		delete load;
		
	}

};

/*inline*/ double validateInputDouble() {
	double choice = 0;
	while (true) {
		if (!(cin >> choice)) {
			cout << "* Invalid input! Please enter a number ~> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return choice;
	}
}
/*inline*/ int validateInput() {
	int choice = 0;
	while (true) {
		if (!(cin >> choice)) {
			cout << "* Invalid input! Please enter a number ~> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return choice;
	}
}
