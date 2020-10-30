#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "book.h"
#include "student.h"

void loadBooks();
void loadStudents();
void printAllStudents();
void login();
void userInterface();
void borrowBook();
void returnBook();
vector <book> books;
vector <student> students;
int studentIndex;

int main() {
	
	cout << "Loading files from databases..." << endl << endl;
	loadBooks();
	loadStudents();
	studentIndex = -1;
	userInterface();


	cout << endl << "ALL DONE AND GOOD" << endl;
}


void borrowBook() {



}

void returnBook() {
	int input;
	cout << "What is the ID of the book you want to return?" << endl;
	cin >> input;

		







}

void userInterface() {
	char input;
	bool logout = false;
	login();    //Calls the login() function which is user authentication
	cout << "Welcome back, " << students[studentIndex].getUsername() << endl << endl;
	while(!logout){
		cout << "Please choose: " << endl;
		cout << "        1 -- Borrow Books" << endl;
		cout << "        2 -- Return Books" << endl;	
		cout << "        0 -- Log Out" << endl;
		cin >> input;
	
		switch (input) {
		case '1':
			borrowBook();
			break;
		case '2':
			returnBook();
			break;
		case '0':
			logout = true;
			break;
		default:
			cout << "Not a correct input, please try again:";
			break;
		}
	}
}

void login() {
	while (1) {
		string user = "", pass = "";
		bool found = false;
		cout << "Username:" << endl;
		cin >> user;
		cout << "Password:" << endl;
		cin >> pass;

		for (int i = 0; i <= students.size()-1 || found; i++) {
			if (students[i].getUsername() == user && students[i].getPassword() == pass) {
				found = true;
				studentIndex = i;
				break;
			}
		}
		if (!found) {
			cout << "No user with this password found" << endl << endl;
		}
		else {
			break;
		}
	}
}

void loadBooks() {    //Reads the data from book.txt
	int ISBN, ID;
	string title, author, category;

	ifstream data_in;
	data_in.open("book.txt");
	if (data_in.fail()) {
		cerr << "Error: Failed to open 'book.txt'." ;
	}
	cout << "Book Data found." << endl;

	while (!data_in.eof()) {
		data_in >> ISBN >> title >> author >> category >> ID;
		books.push_back(book(ISBN, title, author, category, ID));
	}
	cout << "Successfully loaded book data" << endl << endl;
}

void loadStudents() { //reads the data from students.txt
	string username, password, title;
	int maxAllowed, maxTime, listSize;

	ifstream data_in;
	data_in.open("student.txt");
	if (data_in.fail()) {
		cerr << "Error: Failed to open 'student.txt'.";
	}
	cout << "Student Data found." << endl;


	while (!data_in.eof()) {
		vector <string> borrowed;
		data_in >> username >> password >> maxAllowed >> maxTime >> listSize;
		for (listSize; listSize > 0; listSize--) {
			data_in >> title;
			borrowed.push_back(title);
		}
		students.push_back(student(username, password, maxAllowed, maxTime, borrowed));
	}
	cout << "Successfully loaded student data" << endl << endl;
}

void printAllStudents() {
	for (int i = 0; i < students.size(); i++) {
		cout << "Student " << i << ":" << endl;
		students[i].printStudent();
		cout << endl;
	}
}