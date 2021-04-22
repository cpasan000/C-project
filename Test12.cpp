

#include <iostream>
#include <iomanip> //for formatting output
#include "Employee.h" //include Employee class
#include <fstream> //filestream
#include <unordered_set>
using namespace std;
struct node {
	Employee emp;
	node* next;
};

void displayList(node* head);
void viewEmployee(node* head, string ID);
void addNewEmployee(node** head, Employee newEmp);
void removeEmployee(node** head, string ID);
void displayEmployee(Employee* aEmp);
void printHeader();



class List {
private:
	int size;
	node* head;
	node* tail;
public:
	List() {
		head = NULL; //The constructer will make them NULL to avoid any garbage value.
		tail = NULL;
		size = 0;
	}

	void insert_start(Employee* newEmp) {
		node* temp = new node();
		temp->emp = *newEmp;
		temp->next = head;
		if (head == NULL) {
			tail = temp;
		}
		head = temp;

		size++;
	}

	void insert_end(Employee* newEmp) {
		node* temp = new node;
		temp->emp = *newEmp;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		size++;

	}


	void displayList() {

		node* temp = new node;
		temp = head;
		cout << left << setw(12) << setfill(' ') << "Employee ID";
		cout << left << setw(12) << setfill(' ') << "Name";
		cout << left << setw(12) << setfill(' ') << "Lastname";
		cout << left << setw(35) << setfill(' ') << "Position";
		cout << left << setw(0) << setfill(' ') << "Department";
		cout << endl;
		cout << left << setw(12) << setfill('-') << "-";
		cout << left << setw(12) << setfill('-') << "-";
		cout << left << setw(12) << setfill('-') << "-";
		cout << left << setw(35) << setfill('-') << "-";
		cout << left << setw(20) << setfill('-') << "-";
		cout << endl;
		while (temp != NULL) {
			cout << left << setw(12) << setfill(' ') << temp->emp.getEmpID();
			cout << left << setw(12) << setfill(' ') << temp->emp.getName();
			cout << left << setw(12) << setfill(' ') << temp->emp.getLastName();
			cout << left << setw(35) << setfill(' ') << temp->emp.getPosition();
			cout << left << setw(0) << setfill(' ') << temp->emp.getDepartment();
			cout << endl;
			temp = temp->next;
		}

	}
	int getsize() {
		return size;
	}

	void removeEmployee(string stringID) {
		node* cur = head;
		node* pre = new node;
		if (cur != NULL) {
			cur->emp.getEmpID();
			cur = cur->next;
		}
		while (cur != NULL) {
			if (cur->emp.getEmpID() == stringID) {
				pre->next = cur->next;
				delete(cur);
			}
			else {
				cur->emp.getEmpID();
				pre = cur;
			}
			cur = pre->next;
		}

	}


	bool isEmpty() {
		return size == 0;
	}

	void removeDuplicates() {
		node* cur;
		node* prev;
		cur = head;
		prev = head;
		unordered_set<string> tempSet;
		if (cur != NULL) {
			tempSet.insert(cur->emp.getEmpID());
			cur = cur->next;
		}
		while (cur != NULL){
			if (tempSet.find(cur->emp.getEmpID()) != tempSet.end()) {
				prev->next = cur->next;
				delete(cur);
			}
			else {
				tempSet.insert(cur->emp.getEmpID());
				prev = cur;
			}
			cur = prev->next;
		}
	}



	Employee* find(string stringID) {
		

		node* temp = head;
		
		while (temp != NULL) {
			if (temp->emp.getEmpID() == stringID) {
				cout << "\nID: " << temp->emp.getEmpID();
				cout << "\nFirstName: " << temp->emp.getName();
				cout << "\nLastname: " << temp->emp.getLastName();
				cout << "\nPosition: " << temp->emp.getPosition();
				cout << "\nDepartmet: " << temp->emp.getDepartment();
				cout << '\n';
				return NULL;
			}
			temp = temp->next;

		}

		if (temp == NULL) {
			cout << "\nEmplyoee doesnt exist\n" << endl;
		}
		return NULL;


	}

	void sort() {
		mergeSort(&head);
	}

	void mergeSort(node** tempHead) {
		node* temp = *tempHead;
		node* a = NULL;
		node* b = NULL;

		//base case
		if (temp == NULL || temp->next == NULL) {
			return;
		}
		findMid(temp, &a, &b);
		mergeSort(&a);
		mergeSort(&b);
		*tempHead = merge(a, b);

	}
	node* merge(node* a, node* b)
	{
		//merge two sorted linked lists
		node* result = NULL;
		if (a == NULL)
			return(b);
		else if (b == NULL)
			return(a);
		if (a->emp.getEmpID() <= b->emp.getEmpID()) {
			result = a;
			result->next = merge(a->next, b);
		}
		else {
			result = b;
			result->next = merge(a, b->next);
		}
		return result;

	}

	void findMid(node* headRef, node** front, node** back)
	{
		//'Runner Technique' - slow/fast pointers
		node* fast;
		node* slow;
		
		if (headRef == NULL || headRef->next == NULL) {
			*front = headRef;
			*back = NULL;
		}
		else {
			//insert your code here
			slow = headRef;
			fast = headRef->next;
			while (fast != NULL) {
				fast = fast->next;
				if (fast != NULL) {
					slow = slow->next;
					fast = fast->next;
				}
			}
			*front = headRef;
			*back = slow->next;
			slow->next = NULL;
		}
		
	}
};


int main(int argc, const char* argv[]) {

	List empList; //Employee List Object
	fstream dataFile;
	string line;
	string delimiter = ",";
	string newEmpID, newName, newLastName, newPosition, newDepartment = "";

	dataFile.open("EmployeeData2.csv", ios::in);
	cout << "Importing data " << endl;
	if (dataFile.is_open()) {
		printHeader();
		while (getline(dataFile, line))
		{
			
			getline(dataFile, newEmpID, ',' );
			
			getline(dataFile, newName, ',');
			getline(dataFile, newLastName, ',');
			getline(dataFile, newPosition, ',');
			//getline(dataFile, newDepartment);
			newDepartment = line;

			
			//newEmpID,newName,newLastName,newPosition,newDepartment
			Employee* newEmp = new Employee(newEmpID, newName, newLastName, newPosition, newDepartment);
			empList.insert_end(newEmp);

			displayEmployee(newEmp); //display each employee's detail
			delete(newEmp);

		}
		cout << "Import done!" << endl;

	}

	dataFile.close();
	int choice;
	//call the function to remove any duplicate records
	empList.removeDuplicates();

	do
	{
		cout << endl
			<< "***** My Employee Program (CS351) *****" << endl
			<< " 1 - Display List of Employee" << endl
			<< " 2 - View Employee" << endl
			<< " 3 - Add New Employee" << endl
			<< " 4 - Remove an Employee" << endl
			<< " 5 - Sort List" << endl
			<< " 6 - Exit" << endl
			<< " Enter your choice and press return: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (!empList.isEmpty()) {
				empList.displayList();
			}
			else {
				cout << endl
					<< "The list is empty!" << endl;
			}
			break;
		case 2:
		{
			cout << endl
				<< "Enter the ID of the employee that you would like to view!" << endl;         cin.ignore();
			getline(cin, newEmpID);
			//display the employee based on ID match
			displayEmployee(empList.find(newEmpID));
			break;
		}
		case 3:
		{
			cout << endl
				<< "Enter information for the new employee!" << endl;
			cout << "Employee ID : ";
			cin.ignore();
			getline(cin, newEmpID);
	
			cout << "Name : ";
			getline(cin, newName);

			cout << "Lastname : ";
			getline(cin, newLastName);

			cout << "Position : ";
			getline(cin, newPosition);

			cout << "Department : ";
			getline(cin, newDepartment);
			//add the new employee, create an object of Employee class
			//the new employee should be added at the END of the list
			Employee newEmp(newEmpID, newName, newLastName, newPosition, newDepartment);

			empList.insert_end(&newEmp);


			cout << "New Employee is added!!!" << endl;
			break;
		}

		case 4:
			if (!empList.isEmpty()) {
				cout << endl
					<< "Enter the ID of the employee that you would like to remove from the list!" << endl;
				cin.ignore();
				getline(cin, newEmpID);
				empList.removeEmployee(newEmpID);
			}
			else {
				cout << endl
					<< "The list is empty!" << endl;
			}
			break;
		case 5:
			if (!empList.isEmpty()) {
				empList.sort();
			}
			else {
				cout << endl
					<< "The list is empty!" << endl;
			}
			break;


		case 6:
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}

	} while (choice != 6); //the loop exists when user chooses 5 from the main menu
	return 0;
}

void printHeader() {
	cout << left << setw(12) << setfill(' ') << "Employee ID";
	cout << left << setw(12) << setfill(' ') << "Name";
	cout << left << setw(12) << setfill(' ') << "Lastname";
	cout << left << setw(20) << setfill(' ') << "Position";
	cout << left << setw(20) << setfill(' ') << "Department";
	cout << endl;
	cout << left << setw(12) << setfill('-') << "-";
	cout << left << setw(12) << setfill('-') << "-";
	cout << left << setw(12) << setfill('-') << "-";
	cout << left << setw(20) << setfill('-') << "-";
	cout << left << setw(20) << setfill('-') << "-";
	cout << endl;
}

void displayEmployee(Employee* aEmp) {
	if (aEmp != nullptr) {
		cout << left << setw(12) << setfill(' ') << aEmp->getEmpID();
		cout << left << setw(12) << setfill(' ') << aEmp->getName();
		cout << left << setw(12) << setfill(' ') << aEmp->getLastName();
		cout << left << setw(20) << setfill(' ') << aEmp->getPosition();
		cout << left << setw(20) << setfill(' ') << aEmp->getDepartment();
		cout << endl;

	}

}
