#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

//NOT FINISHED NEED TO ADD OPTION OTHER THEN JUST CARE CARD NUMBER
void add(List * atpatients){
  string theCareCardNum = "";
  cout << "Please, enter patients 10 digit care card number to add: ";
  // Remove all leading whitespace -> ws  

  getline(cin >> ws, theCareCardNum);

  Patient p = Patient(theCareCardNum);


  if(atpatients->insert(p)){
    cout << "Patient added successfully" << endl;
  }
  else
    cout << "Patient failed to add" << endl;

}

//NOT FINISHED
void removepatient(List * atpatients){
  //once constructor for all information is added change it to enable
  string toRemove = "";
  cout << "Please, enter patients 10 digit care card number to remove: ";
  getline(cin >> ws, toRemove);

  Patient p2 = Patient(toRemove);

  if(atpatients->remove(p2)){
    cout << "Patient removed successfully" << endl;
  }
  else
    cout << "Patient failed to remove" << endl;



}

//NOT FINISHED
void search(List * atpatients){
  string toSearch = "";
  cout << "Please, enter patients 10 digit care card number to find: ";
  getline(cin >> ws, toSearch);
  Patient p3a = Patient(toSearch);
  Patient* p3b = atpatients->search(p3a);

  if (p3b != NULL)
    cout << "Patient search result: \n" <<p3a <<  endl;
  if (p3b == NULL)
    cout << "Patient not found" << endl;
  	
}

//NOT FINISHED
void modify(List * atpatients){
  string toModify= "";
  cout << "Please, enter patients 10 digit care card number to modify: ";

  getline(cin >> ws, toModify);

  Patient p4 = Patient(toModify);


  if(atpatients->modify(p4)){
    cout << "Patient added successfully" << endl;
  }
  else
    cout << "Patient failed to modify" << endl;  

    

	
}


int main(){
	bool finished = false;
	List* patients = new List();
	char input = 0;
/*
The walk-in clinic patient system must allow the receptionist to

enter a new patient into the system
remove a patient from the system
search for an existing patient
modify a patient's record (for example, adding the patient's information or making a change of address, etc...).
print all its patients by descending order of care card numbers.
*/
	//while case loop is adapted off of inclass FriendsBook.cpp
	while (not finished) {
    cout << "\nWalk-in clinic patient system\n" << endl;
    cout << "To add a new patient enter: a" << endl;
    cout << "To remove an existing patient enter: r" << endl;
    cout << "To search for an existing patient enter: s" << endl;
    cout << "To modify a patient's record enter: m" << endl;
    cout << "To list all patient records enter: l" << endl;
    cout << "To exit enter: x\n" << endl;

    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'a': add(patients); break;
      case 'r': removepatient(patients); break;
      case 's': search(patients); break;
      case 'm': modify(patients); break;
      case 'l': patients->printList(); break;
      case 'x': cout << "\nExiting patient system\n" << endl; finished = true; break;
      default: cout << "Input is not a valid choice, please try again." << endl;
    }

  }//While
  
  patients->removeAll();
	return 0;
}// main()