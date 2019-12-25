using namespace std;

/* Only for day count use */
struct b_day
{
    int d, m, y;
};

// To store number of days in all months from January to Dec. 
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                        31, 31, 30, 31, 30, 31}; 

/* Convert the integer to string */
string toString(int i){
    stringstream ss;
    ss << i; // converting integer to string object

    return ss.str(); // returning the integer in str format
}

// This function counts number of leap years before the 
// given date 
int countLeapYears(b_day d) 
{ 
    int years = d.y; 

    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.m <= 2) 
        years--; 

    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} 

/* GET THE DAY DIFFERECE BETWEEN 2 DATES*/
int getDifference(b_day dt1, b_day dt2) 
{ 
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 

    // initialize count using years and day 
    long int n1 = dt1.y*365 + dt1.d; 

    // Add days for months in given date 
    for (int i=0; i<dt1.m - 1; i++) 
        n1 += monthDays[i]; 

    // Since every leap year is of 366 days, 
    // Add a day for every leap year 
    n1 += countLeapYears(dt1); 

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 

    long int n2 = dt2.y*365 + dt2.d; 
    for (int i=0; i<dt2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2); 

    // return difference between two counts 
    return (n2 - n1); 
} 

/* FOR EACH SUBJECT NEW NODE*/
typedef struct Node {
    char name[20];
    string section;
    int rollNumber;
    struct b_day bday;
    string blood_group;
    string status;
    struct Node* next;
} node;

/*  DEFAULT DATE FOR TODAY REFERENCE */

b_day dt2 = {27,12,2019}; // For now need to set it manually

/* ---------------------------------------------- */

node* head = NULL;

node* getNode() {
    cin.clear();
    cin.sync();
    node* newNode;
    newNode = new Node();   // dynamically allocating memory for each data on the head section of the memory 
    char ch;
    cout << "Enter Student Name: ";
    cin.getline(newNode->name,20); // also spaces are allowed
    cin.clear();
    cin.sync();
    bool sec = false, checkString = false;
    do {
        cout << "Enter Section ('A' or 'B') ->  ";
        cin >> ch;
        cin.clear();
        if(ch == 'A' || ch == 'a' || ch == 'B' || ch == 'b') {
                if(ch == 65 || ch == 97)
                    newNode->section = "A";
                else
                    newNode->section = "B";
            sec = true;
        }
        else {
            cout << "\nThere are only 'A' & 'B' section available." << endl;
        }
    }while(!sec);
    /* Need to find out a way for Validation if the user gives garbage input*/
    cout << "Enter the student Roll Number: ";
    string m_some;
    do {
        cin >> m_some;
        for(int i = 0; i < m_some.length(); i++){
            if(isdigit(m_some[i]) == true){
                newNode->rollNumber = stoi(m_some);
                checkString = true;
            }
            else{
                cout << "Invalid input. Roll should be Numbers only:";
                break;
            }

        }
    }while(!checkString); // while checkString in not true
    cin.clear();
    cin.sync();
    cout << "Choose blood group: \n";
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
                newNode->blood_group = "A+";
                chek = true;
                break;
            case '2':
                newNode->blood_group = "A-";
                chek = true;
                break;
            case '3':
                newNode->blood_group = "B+";
                chek = true;
                break;
            case '4':
                newNode->blood_group = "B-";
                chek = true;
                break;
            case '5':
                newNode->blood_group = "O+";
                chek = true;
                break;
            case '6':
                newNode->blood_group = "O-";
                chek = true;
                break;
            case '7':
                newNode->blood_group = "AB+";
                chek = true;
                break;
            case '8':
                newNode->blood_group = "AB-";
                chek = true;
                break;
            default:
                cout << "invalid selection. Try again." << endl;
        }
    } while (!chek);
    cin.clear();
    cin.sync();
    /* hoping to do a data validation here , if the user provided garbage input*/
    cout << "Enter the last date of blood donation (dd mm yy) : ";
    scanf("%d %d %d", &newNode->bday.d, &newNode->bday.m, &newNode->bday.y);

    int x = getDifference(newNode->bday, dt2); // getting the number of days from two dates into x 
    if(x > 60) {
        newNode->status = "Available";
    }
    else {
        int rem = 60-x;
        string s = "Donated! " + toString(rem) + " days remaining.";
        newNode->status = s ;
    }
    newNode->next = NULL;
    return newNode;
}
