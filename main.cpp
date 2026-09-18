#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::getline;
using std::cerr;

static void show_list(const vector<string>& list) {
    if (list.empty()) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "List:" << "\n" << endl;
        for (const string& item : list)
            cout << item << "\n" << endl;
        cout << "Press enter to continue";
        cin.get();
    }
}

static void add_list(vector<string>& list) {
    cout << "Add to list: ";
    string item_name;
    getline(cin, item_name);
    if (item_name.empty()) {
        cerr << "Can't enter nothing\n";
    }
    else {
        list.push_back(item_name);
    }
}

static void remove_list(vector<string>& list) {
    cout << "\nRemove from list\n";
    int position = 0;
    for (const string& item : list)
        cout << item << "\n";
    cin >> position;

    if (cin.fail()) {
        cerr << "Invalid input please enter a number!\n";
    }
    else if (position < 1 || position > list.size()) {
        cerr << "Please enter a number between 1 and 999\n";
    }
    else {
        --position;
        list.erase(list.begin() + position);
    }
}

static void purge_list(vector<string>& list) {
    cout << "\nPurge list\n";
    cout << "Are you sure you want to purge the list";
    string confirmation;
    cin >> confirmation;
    if (!confirmation.empty()) {
        for (char &c: confirmation) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
    }
    if (confirmation == "yes" || confirmation == "y") {
        if (!list.empty()) {
            list.clear();
            list.shrink_to_fit();
        }
        else {
            cerr << "Can't purge a empty list!";
        }
    }
    else if (confirmation == "no" || confirmation == "n") {
        cout << "Purge canceled";
    }
    else {
        cout << "Invalid choice";
    }
}

int main() {
    vector<string> list;
    bool is_running = true;

    cout << "Welcome!";
    while (is_running) {
        cout << "\n1. Show list";
        cout << "\n2. Add to list";
        cout << "\n3. Remove from list";
        cout << "\n4. purge list";
        cout << "\n5. Exit";
        cout << "\nEnter here:";
        cout << endl;

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input, please enter a valid number.";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: show_list(list);
                break;
            case 2: add_list(list);
                break;
            case 3: remove_list(list);
                break;
            case 4: purge_list(list);
                break;
            case 5:
                is_running = false;
                break;
            default: cerr << "\nInvalid choice!\n";
                break;
        }
    }
    return 0;
}
