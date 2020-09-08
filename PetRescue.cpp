/* Program Name: PetRescue.cpp
 * Author: Nicholas A. Shaw
 * Date Last Updated: 9/7/2020
 * Purpose: This file-based program will let the user create new pet records and view all past pet records.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Display menuOptions
	string menuOption1 = "1:  Create A New Pet Record";
	string menuOption2 = "2:  View All Current Records";
	string menuOption3 = "3:  Exit";
	string menuResponse = "0";
	cout << menuOption1 << endl;
	cout << menuOption2 << endl;
	cout << "\nENTER 1 OR 2:  ";
	cin >> menuResponse;

	do {
		/* WRITE NEW DATA INTO THE RECORDS FILE */
		if (menuResponse == "1") {
			// ofstream is used for writing files.
			ofstream writeFile;
			writeFile.open("PetRecords.txt", fstream::app);  // https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it

			// If the file does not exist, print an error message and exit.
			if (!writeFile) { cerr << "RECORDS FILE DOES NOT EXIST -OR- COULD NOT BE OPENED." << endl; system("pause"); return 1; }

			string animalName;
			cout << "Enter the pet's name:  ";
			cin >> animalName;

			string animalSpecies;
			cout << "Enter " << animalName << "'s species:  ";
			cin >> animalSpecies;

			string animalBreed;
			cout << "Enter " << animalName << "'s breed:  ";
			cin >> animalBreed;

			string animalColor;
			cout << "Enter " << animalName << "'s color:  ";
			cin >> animalColor;

			int animalAgeYears;
			cout << "Approximately how many years old is " << animalName << "?  " << endl;
			cout << "If less than (or equal to) 1 year old, enter 1.  If unknown, enter 0.  Response:  ";
			cin >> animalAgeYears;

			int animalAgeMonths = 0;
			if (animalAgeYears == 1) {
				cout << "Approximately how many months old is " << animalName << "?  ";
				cin >> animalAgeMonths;
			}

			// Write this data with this format into the records file.
			writeFile << "Name:  " << animalName << endl;
			writeFile << "Species:  " << animalSpecies << endl;
			writeFile << "Breed:  " << animalBreed << endl;
			writeFile << "Color:  " << animalColor << endl;
			if (animalAgeYears == 1) { writeFile << "Months Old:  " << animalAgeMonths << endl; writeFile << endl; }
			else if (animalAgeYears > 1) { writeFile << "Years Old:  " << animalAgeYears << endl; writeFile << endl; }
			else { writeFile << "Age:  Unknown" << endl; writeFile << endl; }  // if (animalAgeYears == 0)

			// Close the file.
			writeFile.close();
		}

		/* GET ALL LINES FROM THE RECORDS FILE */
		else if (menuResponse == "2") {
			// ifstream is used for reading files.
			ifstream readFile;
			readFile.open("PetRecords.txt");

			// If the file does not exist, print an error message and exit.
			if (!readFile) { cerr << "RECORDS FILE DOES NOT EXIST." << endl; system("pause"); return 1; }

			// Read every line.
			string allRecords;
			while (getline(readFile, allRecords)) {
				cout << allRecords << '\n';
			}

			// Close the file.
			readFile.close();
		}

		else { break; }

		cout << endl;
		cout << menuOption1 << endl;
		cout << menuOption2 << endl;
		cout << menuOption3 << endl;
		cout << "\nENTER 1, 2, OR 3:  ";
		cin >> menuResponse;
	} while (menuResponse != "3");

	system("pause");
	return 0;
}