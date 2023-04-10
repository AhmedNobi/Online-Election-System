#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Function prototypes
void displayMenu();
void addCandidate();
void listCandidates();
void vote();
void viewResults();
void quit();

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                listCandidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                viewResults();
                break;
            case 5:
                quit();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

// Display the menu
void displayMenu() {
    cout << "Online Election System\n";
    cout << "======================\n";
    cout << "1. Add Candidate\n";
    cout << "2. List Candidates\n";
    cout << "3. Vote\n";
    cout << "4. View Results\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
}

// Add a candidate to the list
void addCandidate() {
    ofstream fout("candidates.txt", ios::app);

    if (!fout) {
        cout << "Error opening file candidates.txt.\n";
        return;
    }

    string name;

    cout << "Enter the candidate's name: ";
    cin.ignore();
    getline(cin, name);

    fout << name << endl;

    fout.close();

    cout << "Candidate added.\n";
}

// List all the candidates
void listCandidates() {
    ifstream fin("candidates.txt");

    if (!fin) {
        cout << "Error opening file candidates.txt.\n";
        return;
    }

    string name;
    int count = 0;

    cout << "List of Candidates\n";
    cout << "==================\n";

    while (getline(fin, name)) {
        cout << ++count << ". " << name << endl;
    }

    fin.close();
}

// Vote for a candidate
void vote() {
    ifstream fin("candidates.txt");

    if (!fin) {
        cout << "Error opening file candidates.txt.\n";
        return;
    }

    string name;
    int count = 0;
    int choice;

    cout << "List of Candidates\n";
    cout << "==================\n";

    while (getline(fin, name)) {
        cout << ++count << ". " << name << endl;
    }

    fin.close();

    cout << "Enter your choice: ";
    cin >> choice;

    fin.open("candidates.txt");

    if (!fin) {
        cout << "Error opening file candidates.txt.\n";
        return;
    }

    count = 0;

    while (getline(fin, name)) {
        if (++count == choice) {
            ofstream fout("votes.txt", ios::app);

            if (!fout) {
                cout << "Error opening file votes.txt.\n";
                return;
            }

            fout << name << endl;

            fout.close();

            cout << "Vote recorded.\n";
            return;
        }
    }

    fin.close();

    cout << "Invalid choice. Please try again.\n";
}
// View the results
void viewResults(){
    ifstream fin("votes.txt");
    if (!fin){
        cout << "Error opening file votes.txt.\n";
        return;
    }
    string name;
    int count = 0;
    int totalVotes = 0;

    cout << "Results\n";
    cout << "=======\n";

    while (getline(fin, name)){
        cout << name << endl;
        ++count;
        ++totalVotes;
    }

    fin.close();

    if (count == 0){
        cout << "No votes recorded yet.\n";
        return;
    }

    cout << "Total number of votes: " << totalVotes << endl;
}

// Quit the program
void quit(){
	cout << "Goodbye!\n";
}
