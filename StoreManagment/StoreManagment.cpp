#include"Product.h"
#include"Storage.h"
#include <iostream>
#include <sstream>
using namespace std;


#include "LinkedList.h"
void ask();
int main() {

	bool flag = true;
	Storage product;
	LinkedList obj;
	int choise;
	
	while (flag){
		cout << R"(
 ____  _                                                                            _                      _                 
/ ___|| |_ ___  _ __ ___      _ __ ___   __ _ _ __   __ _  ___ _ __ ___   ___ _ __ | |_      ___ _   _ ___| |_ ___ _ __ ___  
\___ \| __/ _ \| '__/ _ \    | '_ ` _ \ / _` | '_ \ / _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|    / __| | | / __| __/ _ \ '_ ` _ \ 
 ___) | || (_) | | |  __/    | | | | | | (_| | | | | (_| |  __/ | | | | |  __/ | | | |_     \__ \ |_| \__ \ ||  __/ | | | | |
|____/ \__\___/|_|  \___|    |_| |_| |_|\__,_|_| |_|\__, |\___|_| |_| |_|\___|_| |_|\__|    |___/\__, |___/\__\___|_| |_| |_|
                                                    |___/                                        |___/   
=============================================================================================================================                                                                                                                                      
)";

		obj.displayTable();
		cout << "\nChoose from 1 - 6\n\n";
		cout << "1) Add             2) Search by name        3) Search by ID\n\n";
		cout << "4) Delete          5) Update                6) close program\n\n";
		cout << "Enter: ";
	    choise = validateInput();
		
		switch (choise){
			case  1:
				product.loadfromfile();
				obj.AddProduct();
				product.saveTofile();
				ask();
			    break;
					
		    case 2:
				obj.searchbyName();
				ask();
				break;

			case 3:
				obj.searchbyID();
				ask();
				break;

			case 4:
				obj.DeleteProduct();
				product.saveTofile();
				ask();
				break;

			case 5:
				obj.UpdateProduct();
				ask();
				break;

			case 6:
				product.saveTofile();
				cout << "\nprogramm closed.";
				flag = false;
				break;

			default:	
				cout << "\nwrong input.\n\n";
				ask();
				break;	
		}
	
	}

}

void ask() {
	
	int x =0;
	
	while(x != 1 || x != 2){
		cout << "\n\nPress [1]~>continue\n";
	cout << "Press [2]~>close app\n";
	x = validateInput();
	if (x == 1) {
		system("cls");
		return;
	}
	else if (x == 2) {
		exit(0);
	}
	else {
		system("cls");
		cout << "\n wrong number \n";

	}
	}
}