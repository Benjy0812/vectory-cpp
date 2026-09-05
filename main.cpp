#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

static int show_list(const vector<string>& list) {
    cout << "\nList";
    for (const string& item : list)
        cout << item << endl;
    return 0;
}

void add_list(vector<string>& list) {

    cout << "\nAdd to list";
    string itemName;
    cin >> itemName;

    list.push_back(itemName);
}

static int remove_list() {
    cout << "\nRemove from list";
    return 0;
}

static int purge_list() {
    cout << "\nPurge list";
    return 0;
}

static int exit_cli() {
    cout << "\nExit";
    return 0;
}

int main() {
    vector<string> list;
    bool state = false;

    while (state == false) {
        cout << "Welcome!";
        cout << "\n1. Show list";
        cout << "\n2. Add to list";
        cout << "\n3. Remove from list";
        cout << "\n4. purge list";
        cout << "\n5. Exit";
        cout << endl;
        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: show_list(list);
                break;
            case 2: add_list(list);
                break;
            case 3: remove_list();
                break;
            case 4: purge_list();
                break;
            case 5: exit_cli();
                state = true;
                break;
            default: cout << "\nInvalid choice!";
        }
    }
    return 0;
}
