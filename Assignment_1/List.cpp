/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Dixon Snider
 * Date: Feb 4, 2022
 */


#include <iostream>
#include <string>
#include "List.h"


//Constructor
List::List() : elementCount(0), capacity(List::MAX_ELEMENTS) {

   cout << "Constructing a List!" << endl;   // For testing purposes ... and curiosity--DELETE

} 

//Destructor
List::~List() {

	cout << "Destructing a List!" << endl;   // For testing purposes ... and curiosity--DELETE
	delete [] elements;
	elements = NULL; 
	elementCount = 0;

}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const {
   return elementCount;
} 

// Description: Remove all elements.
void List::removeAll() {

	delete [] elements;
	elements = NULL;
	elementCount = 0;
	return;
} 

//WIP
// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
//Need to add if staements for errors
 
      if(elementCount == 0){
      	elements = new Patient[MAX_ELEMENTS];
      	elements[0] = newElement;

      }
      else{
      	for (int pos = elementCount; pos >= 1; pos--)
         	elements[pos] = elements[pos - 1];
         
		   // Insert new Element
		   elements[0] = newElement;
		   
      }
      elementCount++;  // Increase count of elements
      
   //change to variable that you can make T or F, once if added
	return true;
}//Insert

// WIP
// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ) {
	bool trigger = false;
	for (int i = 0; i < elementCount; i++){
		if(elements[i] == toBeRemoved){
			trigger = true;
		}
		if(trigger == true){
			elements[i] = elements[i+1];
		}
	}	
         
   elementCount--;  // Decrease count of elements

   //change to variable that you can make T or F, once if added
	return true;

}//Remove

// Description: Modify an element. 
// Postcondition: finds toModify in elements then alters the data.	
bool List :: modify( const Patient& toModify ){
	bool trigger2 = false;
	string mName, mAddress, mPhone, mEmail ="";
	for (int i = 0; i < elementCount; i++){
		if(elements[i] == toModify){
			trigger2 = true;
			//MAKE THIS INTO A CASE SYSTEM
			cout << "Enter name: " << endl;
			getline(cin, mName);
			elements[i].setName(mName);
			cout << "Enter Address: " << endl;
			getline(cin, mAddress);
			elements[i].setAddress(mAddress);
			cout << "Enter Phone: " << endl;
			getline(cin, mPhone);
			elements[i].setPhone(mPhone);
			cout << "Enter Email: " << endl;
			getline(cin, mEmail);
			elements[i].setEmail(mEmail);
		}
	}
	if(trigger2 == false)return false;
	return true;
}//Modify

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
	for (int i = 0; i < elementCount; i++){

		if (elements[i] == target){

			return &elements[i];

		}

	}
	return NULL;
}//Search

// Description: Prints all elements stored in List by descending order of search key.
void List::printList(){
		for (int i = 0; i < elementCount; i++){
			cout <<  elements[i] << endl;
		}
}//printList

