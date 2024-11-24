#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX = 100;
    string names[MAX];
    int studentCount = 0;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Students\n";
        cout << "2. Display Names\n";
        cout << "3. Sequential Search\n";
        cout << "4. Binary Search (requires sorting)\n";
        cout << "5. Simple Sort\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Selection Sort\n";
        cout << "8. Insertion Sort\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "How many students to add? ";
            int num;
            cin >> num;
            cin.ignore();
            for (int i = 0; i < num && studentCount < MAX; ++i) {
                cout << "Enter name of student " << studentCount + 1 << ": ";
                getline(cin, names[studentCount++]);
            }
        } else if (choice == 2) {
            cout << "Student Names:\n";
            for (int i = 0; i < studentCount; ++i) {
                cout << i + 1 << ". " << names[i] << "\n";
            }
        } else if (choice == 3) {
            cout << "Enter name to search (Sequential): ";
            string target;
            cin.ignore();
            getline(cin, target);
            bool found = false;
            for (int i = 0; i < studentCount; ++i) {
                if (names[i] == target) {
                    cout << "Name found at position " << i + 1 << ".\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Name not found.\n";
        } else if (choice == 4) {
            cout << "Enter name to search (Binary, requires sorted list): ";
            string target;
            cin.ignore();
            getline(cin, target);
            int left = 0, right = studentCount - 1, mid;
            bool found = false;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (names[mid] == target) {
                    cout << "Name found at position " << mid + 1 << ".\n";
                    found = true;
                    break;
                } else if (names[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (!found) cout << "Name not found.\n";
        } else if (choice == 5) {
            cout << "Sorting names using Simple Sort...\n";
            for (int i = 0; i < studentCount - 1; ++i) {
                for (int j = i + 1; j < studentCount; ++j) {
                    if (names[i] > names[j]) {
                        string temp = names[i];
                        names[i] = names[j];
                        names[j] = temp;
                    }
                }
            }
            cout << "Names sorted.\n";
        } else if (choice == 6) {
            cout << "Sorting names using Bubble Sort...\n";
            for (int i = 0; i < studentCount - 1; ++i) {
                for (int j = 0; j < studentCount - i - 1; ++j) {
                    if (names[j] > names[j + 1]) {
                        string temp = names[j];
                        names[j] = names[j + 1];
                        names[j + 1] = temp;
                    }
                }
            }
            cout << "Names sorted.\n";
        } else if (choice == 7) {
            cout << "Sorting names using Selection Sort...\n";
            for (int i = 0; i < studentCount - 1; ++i) {
                int minIdx = i;
                for (int j = i + 1; j < studentCount; ++j) {
                    if (names[j] < names[minIdx]) {
                        minIdx = j;
                    }
                }
                if (minIdx != i) {
                    string temp = names[i];
                    names[i] = names[minIdx];
                    names[minIdx] = temp;
                }
            }
            cout << "Names sorted.\n";
        } else if (choice == 8) {
            cout << "Sorting names using Insertion Sort...\n";
            for (int i = 1; i < studentCount; ++i) {
                string key = names[i];
                int j = i - 1;
                while (j >= 0 && names[j] > key) {
                    names[j + 1] = names[j];
                    j--;
                }
                names[j + 1] = key;
            }
            cout << "Names sorted.\n";
        } else if (choice == 9) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
