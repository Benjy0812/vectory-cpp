#include <iostream>
#include <string>
#include <vector>
#include <limits>

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
