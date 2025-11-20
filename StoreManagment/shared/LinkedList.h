
#pragma once
#define NOMINMAX
#include<iostream>
#include<sstream>
#include<fstream>
#include <iomanip>
#include <cctype>
#include <Windows.h>
#include <cstdlib>
#include "Product.h"
using namespace std;

HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

int validateInput();
int validateInput();
double validateInputDouble();
int ID();

class LinkedList {

private:
	Node* head;


public:


	LinkedList() {
		head = nullptr;
	}

	void AddProduct() {
		Node* New_product = new Node;
		int a = 0;
		//New_product->id = ID();



		do {
			New_product->id = ID();
			if (cheak2(New_product->id) || New_product->id == 0) {
				a = 1;
			}

			else {
				a = 0;
			}
		} while (a);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do {

			cout << "Enter product name: ";
			getline(cin, New_product->name);
			// هنا مشكلة الحل حق الفراغ و بداية الاسم رقم 
			if (New_product->name.empty() || cheak(New_product->name) || isdigit(New_product->name[0])) {
				SetConsoleTextAttribute(h_console, 12);						//color red
				cout << "\nyou type wrong names or you reuse a name \n";
				SetConsoleTextAttribute(h_console, 7);						//color white

				a = 1;
			}

			else {
				a = 0;
			}
		} while (a);
		// الحل حق مشكلة انه الارقام اقل من صفر
		do {
			cout << "Enter product price: ";
			New_product->price = validateInputDouble();

			if (New_product->price <= 0) {
				SetConsoleTextAttribute(h_console, 12); //color red
				cout << "you type wrong numbers \n";
				SetConsoleTextAttribute(h_console, 7); //color white

				a = 1;
			}

			else {
				a = 0;
			}
		} while (a);
		// نفس المنغلة الي فوق
		do {
			cout << "\nEnter product quantity: ";
			New_product->Quantity = validateInput();

			if (New_product->Quantity <= 0) {
				SetConsoleTextAttribute(h_console, 12);
				cout << "you type wrong numbers \n";
				SetConsoleTextAttribute(h_console, 7);

				a = 1;
			}

			else {
				a = 0;
			}
		} while (a);

		if (head == nullptr) {

			New_product->next = nullptr;
			head = New_product;

		}
		else {

			Node* tail = head;
			while (tail->next != NULL) {
				tail = tail->next; // انتقل إلى العقدة الأخيرة
			}
			tail->next = New_product;
			tail = New_product;

			New_product->next = nullptr;
		}

	}
	void DeleteProduct() {


		if (head == nullptr)
		{
			SetConsoleTextAttribute(h_console, 12);
			cout << "there are no products.";
			SetConsoleTextAttribute(h_console, 7);
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
				SetConsoleTextAttribute(h_console, 64);
				cout << "product not found.";
				SetConsoleTextAttribute(h_console, 7);
				return;
			}

			if (current == head) {
				head = current->next;
				delete current;
				current = nullptr;
				return;
			}

			rev->next = current->next;
			delete current;
			current = nullptr;

		}
	}
	void displayTable() {
		if (head == nullptr) {
			SetConsoleTextAttribute(h_console, 64);
			cout << "\nNo products available.\n";
			SetConsoleTextAttribute(h_console, 7);
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
			SetConsoleTextAttribute(h_console, 64);
			cout << "\nproduct not found.";
			SetConsoleTextAttribute(h_console, 7);
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
			SetConsoleTextAttribute(h_console, 64);
			cout << "\nProduct not found.\n";
			SetConsoleTextAttribute(h_console, 7);
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
		int a = 0;
		cout << "Enter id: ";
		ID = validateInput();

		Node* current = head;
		while (current != nullptr && current->id != ID) {
			current = current->next;
		}

		if (current == nullptr) {
			SetConsoleTextAttribute(h_console, 64);
			cout << "\nproduct not found.";
			SetConsoleTextAttribute(h_console, 7);
			return;
		}


		do {
			cout << "\nNew price ~> ";
			double newPrice = validateInputDouble();

			if (newPrice <= 0) {
				SetConsoleTextAttribute(h_console, 12); //color red
				cout << "you type wrong numbers \n";
				SetConsoleTextAttribute(h_console, 7); //color white

				a = 1;
			}

			else {
				a = 0;
				current->price = newPrice;
			}
		} while (a);

		do {
			cout << "\nNew quantity ~> ";
			int newQuantity = validateInput();

			if (newQuantity <= 0) {
				SetConsoleTextAttribute(h_console, 12); //color red
				cout << "you type wrong numbers \n";
				SetConsoleTextAttribute(h_console, 7); //color white

				a = 1;
			}

			else {
				a = 0;
				current->Quantity = newQuantity;
			}
		} while (a);
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

		}
		else {
			Node* tail = head;
			while (tail->next != NULL) {
				tail = tail->next; // انتقل إلى العقدة الأخيرة
			}
			tail->next = New_product;
			tail = New_product;

			New_product->next = nullptr;
		}

	}
	// حل مشكلة انه الاسم متكرر
	bool cheak(string a) {
		Node* current = head;
		while (current != nullptr && current->name != a) {
			current = current->next;
		}

		if (current == nullptr) {
			return 0;
		}
		else {
			return 1;
		}
	}
	bool cheak2(int a) {
		Node* current = head;
		while (current != nullptr && current->id != a) {
			current = current->next;
		}

		if (current == nullptr) {
			return 0;
		}
		else {
			return 1;
		}
	}
};

double validateInputDouble() {
	double choice = 0;
	while (true) {
		if (!(cin >> choice)) {
			SetConsoleTextAttribute(h_console, 64);
			cout << "* Invalid input! Please enter a number ~> ";
			SetConsoleTextAttribute(h_console, 7);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return choice;
	}
}
int validateInput() {
	int choice = 0;
	while (true) {
		if (!(cin >> choice)) {
			SetConsoleTextAttribute(h_console, 64);
			cout << "* Invalid input!\n\n";
			SetConsoleTextAttribute(h_console, 7);
			cout << "Please enter a number ~> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
			continue;
		}
		return choice;
	}
}

int ID() {
	return rand() % 10001;
}