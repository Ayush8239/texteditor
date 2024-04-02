#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createNewDocument() {
    string fileName;
    cout << "Enter the name of the new document: ";
    cin >> fileName;
    
    ofstream file(fileName.c_str());
    if (file.is_open()) {
        cout << "New document '" << fileName << "' created successfully.\n";
        file.close();
    } else {
        cout << "Unable to create document.\n";
    }
}

void openDocument() {
    string fileName, line;
    cout << "Enter the name of the document to open: ";
    cin >> fileName;
    
    ifstream file(fileName.c_str());
    if (file.is_open()) {
        cout << "Contents of '" << fileName << "':\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open document.\n";
    }
}

void editDocument() {
    string fileName, line;
    cout << "Enter the name of the document to edit: ";
    cin >> fileName;
    
    ofstream file(fileName.c_str(), ios::app);
    if (file.is_open()) {
        cout << "Enter text to append to the document (press Ctrl+Z and Enter to finish):\n";
        while (getline(cin, line)) {
            if (line == "^Z" && cin.peek() == EOF) // Check for Ctrl+Z and end of input
                break;
            file << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open document for editing.\n";
    }
}


int main() {
    int choice;
    while (true) {
        cout << "\n===== Text Editor Menu =====\n";
        cout << "1. Create New Document\n";
        cout << "2. Open Document\n";
        cout << "3. Edit Document\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                createNewDocument();
                break;
            case 2:
                openDocument();
                break;
            case 3:
                editDocument();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
