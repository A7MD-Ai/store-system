#pragma once
#include <String>
#include<iostream>


using namespace std;
struct Node{
	string name;
	int id;
	int Quantity;
	double price;
	Node* next;
};