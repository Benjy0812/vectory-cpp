#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::isspace;

static void show_list(const vector<string>& list) {
    if (list.empty()) {
        cout << "List is empty";
    }
    else {
        cout << "List:" << "\n";
        for (int i = 0; i < static_cast<int>(list.size()); i++) {
            cout << i + 1 << ". " << list[i] << "\n";
        }
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
    for (int i = 0; i < static_cast<int>(list.size()); i++) {
        cout << i + 1 << ". " << list[i] << "\n";
    }

    int position = 0;
    cin >> position;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input please enter a number!\n";
    }
    else if (position < 1 || position > static_cast<int>(list.size())) {
        cerr << "Please enter a number between 1 and " << list.size() << "\n";
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        --position;
        list.erase(list.begin() + position);
    }
}

static void purge_list(vector<string>& list) {
    while (true) {
        if (list.empty()) {
            cout << "List empty!\n";
            break;
        }

        cout << "\nPurge list:\n";
        for (int i = 0; i < static_cast<int>(list.size()); i++) {
            cout << i + 1 << ". " << list[i] << "\n";
        }

        cout << "Are you sure you want to purge the list (y/n): ";
        string confirmation;
        if (!getline(cin, confirmation)) {
            cout << "\ninput error or EOF purge canceled\n";
            break;
        }

        // Remove white space
        while (!confirmation.empty() && isspace(static_cast<unsigned char>(confirmation.back()))) {
            confirmation.pop_back();
        }

        // Convert to lower case
        for (char &c: confirmation) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }

        if (confirmation == "y") {
            list.clear();
            list.shrink_to_fit();
            cout << "List Purged!\n";
            break;
        }
        if (confirmation == "n") {
            cout << "Purge canceled";
            break;
        }
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

        int choice;
        if (!(cin >> choice)) {
            cout << "\ninput error or EOF purge canceled\n";
            break;
        }

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input please enter a valid number.";
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
