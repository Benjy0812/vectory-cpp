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
    cout << "\nAdd to list: ";
    string item_name;
    getline(cin, item_name);
    if (item_name.empty()) {
        cout << "Can't enter nothing\n";
    }
    else {
        list.push_back(item_name);
    }
}

//TODO make sure it only takes numbers
static void remove_list(vector<string>& list) {
    cout << "\nRemove from list";
    int position = 0;
    for (const string& item : list)
        cout << item << "\n" << endl;
    cin >> position;
    position -= 1;

    list.erase(list.begin() + position);
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
            cout << "Invalid input, please enter a valid number." << endl;
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
            default: cout << "\nInvalid choice!\n";
                break;
        }
    }
    return 0;
}
