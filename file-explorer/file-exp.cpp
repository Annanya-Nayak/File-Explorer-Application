#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int choice;
    string src, dest, perm;

    while (true) {
        cout << "\n=== FILE EXPLORER ===\n";
        cout << "1. List directory\n";
        cout << "2. Open another directory\n";
        cout << "3. Create file\n";
        cout << "4. Create folder\n";
        cout << "5. Copy file\n";
        cout << "6. Move file\n";
        cout << "7. Delete file/folder\n";
        cout << "8. Search for file\n";
        cout << "9. Manage file permissions\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            system("ls -l");
            break;

        case 2:
            cout << "Enter directory name: ";
            getline(cin, src);
            system(("ls -l " + src).c_str());
            break;

        case 3:
            cout << "Enter file name: ";
            getline(cin, src);
            system(("touch " + src).c_str());
            cout << "File created: " << src << endl;
            break;

        case 4:
            cout << "Enter folder name: ";
            getline(cin, src);
            system(("mkdir " + src).c_str());
            cout << "Folder created: " << src << endl;
            break;

        case 5:
            cout << "Source file: ";
            getline(cin, src);
            cout << "Destination path: ";
            getline(cin, dest);
            system(("cp " + src + " " + dest).c_str());
            cout << "File copied!\n";
            break;

        case 6:
            cout << "Enter file to move: ";
            getline(cin, src);
            cout << "Enter destination path: ";
            getline(cin, dest);
            system(("mv " + src + " " + dest).c_str());
            cout << "File moved successfully!\n";
            break;

        case 7:
            cout << "File/folder to delete: ";
            getline(cin, src);
            system(("rm -r " + src).c_str());
            cout << "Deleted: " << src << endl;
            break;

        case 8:
            cout << "Enter filename to search: ";
            getline(cin, src);
            system(("find . -type f -name \"" + src + "\"").c_str());
            break;

        case 9:
            cout << "\n--- FILE PERMISSION MANAGEMENT ---\n";
            cout << "1. View permissions\n";
            cout << "2. Add permissions\n";
            cout << "3. Remove permissions\n";
            cout << "Enter option: ";
            int pchoice;
            cin >> pchoice;
            cin.ignore();

            if (pchoice == 1) {
                cout << "Enter filename: ";
                getline(cin, src);
                system(("ls -l " + src).c_str());
            } else if (pchoice == 2) {
                cout << "Enter filename: ";
                getline(cin, src);
                cout << "Enter permission to add (+r, +w, +x): ";
                getline(cin, perm);
                system(("chmod " + perm + " " + src).c_str());
                cout << "Permission added!\n";
            } else if (pchoice == 3) {
                cout << "Enter filename: ";
                getline(cin, src);
                cout << "Enter permission to remove (-r, -w, -x): ";
                getline(cin, perm);
                system(("chmod " + perm + " " + src).c_str());
                cout << "Permission removed!\n";
            } else {
                cout << "Invalid option!\n";
            }
            break;

        case 0:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
