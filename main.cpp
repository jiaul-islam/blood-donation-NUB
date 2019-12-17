  
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include "getnode.hpp"
using namespace std;

/* Function Prototyping Section, all the function prototypes goes here*/
void mainMenu();                                            // Create main menu & functionality
void asciiArt();                                            // ACSII Art
void makeSpace();                                           // visual space
void deleteNode();                                          // Delete nodes
void endMyProgram();                                        // Just a simple note to end the program
void nodeAtBegining();                                      // Creating node at beginning
void createNode(int x);                                     // Create nth terms of node
void displayInformation();                                  // Display all the info
int countLeapYears(b_day d);                                // Calculate leap year function
int countnode(node *stList);                                // Counting node list
void writeListToFile(node *pToHead);                        // Export Data to file
int getDifference(b_day dt1, b_day dt2);                    // Gets the difference between two dates
void check_with_blood_group(node *pToHead);                 // filters the donors with blood group
void check_for_available_donors(node *pToHead);             // filters the available donors

/* Function Prototyping Block Ends */

// Driver codes are here
int main() {

    asciiArt();
    cout << endl;
    string name = "", pass = "";
    bool auth = false;
    int counter = 1;
    do {
        cout  << "Please enter  User Name   \t-> ";
        getline(cin, name);
        cout << endl;
        cout  << "Please enter the password \t-> ";
        getline(cin, pass);
        cout << endl;
        if(name == "admin" && pass == "admin" ) {
            makeSpace();
            cout << "Access Granted ";
            for (int i = 0; i <= 2; ++i) {
                //sleep(1);
                cout << "." << flush;
            }
            cout << endl;
            auth = true;
        } else {
            makeSpace();
            cout <<"Access Denied! username/password doesn't match !\n";
            counter++;
            if(counter >= 5) {
                cout << "Attempted 5 time's. Please restart the program !" << endl;
                return 1;
            }
        }
    } while(!auth);

    mainMenu(); // Calling all the cross connected functions

    endMyProgram();

    return 0;
}


/*Function definitions starts here*/

/* Create nodes with a range by user defined */
void createNode(int x) {
    node* makeNode;
    for(int i = 0; i < x; ++i) {
        makeNode = getNode();
        if(head == NULL) {
            head = makeNode;
        } else {
            node* tempNode = head;
            while(tempNode->next != NULL) {
                tempNode = tempNode->next;
            }
            tempNode->next = makeNode;
        }
    }
    system("cls");
    cout << endl;
}

/* Create node at beginning*/
void nodeAtBegining() {
    node* temp = getNode();
    temp->next = head;
    head = temp;
}

/* Display the data*/
void displayInformation() {
	system("cls");

    node* temp = head;
    int counter = 1;
    for (int i = 0; i < 159; ++i)
    {
        cout << "-";
    }
    cout << endl;
    cout << "|| SL || \t|| Student Name || \t || Student Roll || \t  || Student Section || \t || Blood Group ||  Last donation Date  ||  Donation Status  ||\n";
    for(int i = 0; i < 159; ++i) {
        cout << "-";
    }
    cout << endl;
    if (head == NULL) {
    	makeSpace();
    	cout << "Data table is empty. Please create data first." << endl;
    	for(int i=0; i < 159; i++) {
    		cout <<"-";
    	}
    	cout << endl;
    }
    while(temp != NULL) {
        cout<<"  " << counter<< " \t\t  " << temp->name << " \t\t " << temp->rollNumber << " \t\t\t " << temp->section << "\t\t\t\t  " << temp->blood_group <<"\t\t" << temp->bday.d << "-" << temp->bday.m << "-" << temp->bday.y << "  \t  " << temp->status << endl;
        for(int i = 0; i < 159; ++i) {
            cout << "-";
        }
        cout << endl;
        temp = temp->next;
        counter++;
    }
    cout << endl << endl;
}

/* Delete node at nth position */
void deleteNode() {
    node *current, *prev;
    int pos, nodectr, ctr = 1;
    if(head == NULL) {		// check if the list is empty then show error
        cout << "No data found. Please create data first" << endl;
        return;
    } else {
        cout << "Enter the position to delete data: ";
        cin >> pos;
        nodectr = countnode(head);
        if (pos > nodectr) {
            cout << "Invalid position. I have " << nodectr << " data only." << endl << endl;
            return;
        } else if (pos > 1 && pos <= nodectr) {
            current = prev = head;
            while(ctr < pos) {
                prev = current;
                current = current->next;
                ctr++;
            }
            prev->next = current->next;
            delete current;
            cout << "Successfully deleted." << endl << endl;
        } else {
            cout << "Deleting error ! Position value can't be zero/negative." << endl << endl;
            return;
        }
    }
}

/* Count the nodes */
int countnode(node *stList) {
    int count = 0;
    while(stList != NULL) {
        count++;
        stList= stList->next; // increment count till found null
    }
    return count;
}

/* Creating the menu here & controls*/
void mainMenu() {
    char ch;
    string m_input;
    int range;
    for (int i = 0; i <= 119; ++i) {
        //sleep(0.40);		// using just a simple slow animation for cli program.
        cout << "=" << flush;
    }
    cout << endl << endl;
    do {
        makeSpace();
        cout << "-> Press 1 to Create a data with range." <<endl;
        makeSpace();
        cout << "-> Press 2 to Insert data at first row." <<endl;
        makeSpace();
        cout << "-> Press 3 to view/display the data." <<endl;
        makeSpace();
        cout << "-> Press 4 to delete data from table." <<endl;
        makeSpace();
        cout << "-> Press 5 to export data to file." <<endl;
        makeSpace();
        cout << "-> Press 6 to show Available donors." <<endl;
        makeSpace();
        cout << "-> Press 7 to filter donors by blood group." <<endl;
        makeSpace();
        cout << "-> Press q to quit the application." << endl << endl;
        makeSpace();
        cout <<"-> Enter Your Choice ------>  ";
        cin >> ch;
        cout << endl;

        switch(ch) {
        case '1':
/*    Forcing to give integer value. Need sstream header for stringstream to use  */
            while (getline (cin, m_input)){
                stringstream chck(m_input);
                if(chck >> range){
                    if(chck.eof()){
                        // end of the line search finished. success
                        break;
                    }
                }
                cout << "Enter the range for the list: ";
            }
            createNode(range);
            break;
        case '2':
            cin.clear();
            cin.ignore(9999,'\n');
            nodeAtBegining();
            break;
        case '3':
            displayInformation();
            break;
        case '4':
            cin.clear();
            cin.ignore(9999,'\n');
            deleteNode();
            break;
        case '5':
            writeListToFile(head);
            break;
        case '6':
            check_for_available_donors(head);
            break;
        case '7':
            check_with_blood_group(head);
            break;
        case 'q':
            cout << "Exiting Program";
            for (int i = 0; i <= 2; ++i) {
                //sleep(1);
                cout << "." << flush;
            }
            system("cls");
            break;
        default:
            cout << "Invalid input. Try again !" << endl;
        }

    } while(ch != 'q');
}

/* This is just a simple function for creating a visual space*/
void makeSpace() {
    for (int i = 0; i < 22; i++) {
        cout << "  ";
    }
}


/* Export data to a CSV File */
void writeListToFile(node *pToHead) {
    if (pToHead == NULL) {
        cout << "No data found to export. Please create data first. !" <<endl<< endl;
    } else {
        ofstream myFile;
        myFile.open("Blood_Records.csv");
        node *temp = pToHead;
        int counter = 1;
        myFile <<"SL,Student Name,Student Roll,Section,Blood Group,Blood donation date,Status\n";
        while(temp != NULL) {
            myFile <<counter++ << "," << temp->name << "," <<temp->rollNumber << "," << temp->section << "," << temp->blood_group << "," 
            << temp->bday.d << "/"<< temp->bday.m  << "/"<< temp->bday.y << "," << temp->status << "\n";
            temp = temp->next;
        }
        myFile.close();
        cout << "File Successfully exported." << endl;
    }
}
/* Just a simple art */
void asciiArt() {

    cout << R"(
                                         _  _  _       _
                                        | || || |     | |
                                        | || || | ____| | ____ ___  ____   ____
                                        | ||_|| |/ _  ) |/ ___) _ \|    \ / _  )
                                        | |___| ( (/ /| ( (__| |_| | | | ( (/ /
                                         \______|\____)_|\____)___/|_|_|_|\____)

                                         		TO 
                                         NUBian Students Blood Foundation Program
                                ** This Program is developed by ECSE-2nd-Semester(DOS-I Programming) **
                            Participants>> 1: 190201123 2: 190201161 3: 180300995 4: 190201177 5: 190201190
    )" << endl;
    for (int i = 0; i < 120; i++)
    {
        cout <<"=";
    }

}

/* End Program Function */
void endMyProgram() {
    makeSpace();
    cout << endl << endl;
    makeSpace();
    cout << "Thanks for using this application. See you soon !" << endl <<endl;
}

/* Filter data with available donors only */
void check_for_available_donors(node *pToHead){
	node *temp = head;
	int perCounter = 0, findDonor = 0;
	while (temp != NULL){
		if(temp->status == "Available"){	// check if any available donors have in the list
			cout << ++perCounter << ": Donor Name- " << temp->name << " || Donor Blood Group- " << temp->blood_group << " || Donor Roll- " << temp->rollNumber << endl;
			findDonor++;
		}
		temp = temp->next;
	}
	cout << endl << "Total " << findDonor << " donor found available." << endl; // give the total number of available donor
}

/* Filter data with blood group*/
void check_with_blood_group(node *pToHead){
	node *temp = head; 
	string inpt;
	int findBlood = 0;
	cout << "Choose the blood group to filter: \n";
	char selectBlood; bool chek = false;
    do {
        for (int i = 0; i < 74; ++i)
        {
            cout << "-";
        }
        cout << endl;
        cout << "|| Press-1 for A+ ||" << " ";
        cout << "Press-2 for A- ||" << " ";
        cout << "Press-3 for B+ ||" << " ";
        cout << "Press-4 for B- ||" << "\n";
        for (int i = 0; i < 74; ++i)
        {
            cout << "-";
        }
        cout << endl;
        cout << "|| Press-5 for O+ ||" << " ";
        cout << "Press-6 for O- ||" << " ";
        cout << "Press-7 for AB+||" << " ";
        cout << "Press-8 for AB-||" << endl;
        for (int i = 0; i < 74; ++i)
        {
            cout << "-";
        }
        cout << endl;
        cout << "Press a key: ";
        cin >> selectBlood;
        cout << endl;

        switch(selectBlood)
        {
            case '1':
                inpt = "A+";
                chek = true;
                break;
            case '2':
                inpt = "A-";
                chek = true;
                break;
            case '3':
                inpt = "B+";
                chek = true;
                break;
            case '4':
                inpt = "B-";
                chek = true;
                break;
            case '5':
                inpt = "O+";
                chek = true;
                break;
            case '6':
                inpt = "O-";
                chek = true;
                break;
            case '7':
                inpt = "AB+";
                chek = true;
                break;
            case '8':
                inpt = "AB-";
                chek = true;
                break;
            default:
                cout << "invalid selection. Try again." << endl;
        }
    } while (!chek);

    // Display the donors with the matching blood group
    int perCounter = 0;
	while (temp != NULL) {
		if(temp->blood_group == inpt){
			cout<< ++perCounter << ": " << temp->name << "\t" << temp->blood_group << endl;
			findBlood++;
		}
		temp = temp->next;
	}
	if(!findBlood){
		cout << "No match found!" << endl; // while no match found for blood group display error
	}
	else{
		cout<< "Total " << findBlood << " match found !" << endl; // show the count of the total match found
	} 
}

