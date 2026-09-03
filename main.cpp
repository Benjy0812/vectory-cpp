#include  <iostream>
using std::cout;
using std::cin;
using std::endl;

static int show_list() {
    cout << "\nList";
    return 0;
}

static int add_list() {
    cout << "\nAdd to list";
    return 0;
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
    cout << "Welcome!";
    cout << "\n1. Show list";
    cout << "\n2. Add to list";
    cout << "\n3. Remove from list";
    cout << "\n4. purge list";
    cout << "\n5. Exit";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: show_list();
            break;
        case 2: add_list();
            break;
        case 3: remove_list();
            break;
        case 4: purge_list();
            break;
        case 5: exit_cli();
            break;
        default: cout << "\nInvalid choice!";
    }
    return 0;
}
