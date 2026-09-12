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

static int show_list(const vector<string>& list) {
    if (list.empty()) {
        cout << "List is empty" << endl;
    }
    if (!list.empty()) {
        for (const string& item : list)
            cout << item << endl;
    }
    return 0;
}

static void add_list(vector<string>& list) {
    cout << "\nAdd to list";
    string item_name;
    getline(cin, item_name);

    list.push_back(item_name);
}

static int remove_list() {
    cout << "\nRemove from list";
    return 0;
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
            cout << "Can't purge a empty list!";
        }
    }
    else if (confirmation == "no" || confirmation == "n") {
        cout << "Purge canceled";
    }
    else {
        cout << "Invalid choice";
    }
}

static int exit_cli() {
    cout << "\nExit";
    return 0;
}

int main() {
    vector<string> list;
    bool is_running = true;

    while (is_running) {
        cout << "Welcome!";
        cout << "\n1. Show list";
        cout << "\n2. Add to list";
        cout << "\n3. Remove from list";
        cout << "\n4. purge list";
        cout << "\n5. Exit";
        cout << "\nEnter here:";
        cout << endl;

        int choice;
        cin >> choice;

        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a valid number." << endl;
        }

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
                is_running = false;
                break;
            default: cout << "\nInvalid choice!\n";
                break;
        }
    }
    return 0;
}
