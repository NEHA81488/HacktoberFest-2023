#include <iostream>
#include <string>

using namespace std;

void decode() {
    string in_str;
    cout << "Enter the string to decode: ";
    cin.ignore(); // Ignore any newline left in the input buffer
    getline(cin, in_str); // Allow spaces in input

    bool isKey = false;
    char check;
    cout << "Do you have a key? (Y/n): ";
    cin >> check;
    
    if (check == 'y' || check == 'Y') {
        isKey = true;
    }

    if (isKey) {
        long long key;
        cout << "Enter key for decryption: ";
        cin >> key;

        if (key < 0) {
            cout << "Key has to be positive!" << endl;
            return;
        }

        for (char &c : in_str) { // Iterate using a reference to modify the original string
            if (isupper(c)) {
                c = (c - key < 'A') ? 'Z' - ('A' - (c - key - 1)) % 26 : c - key;
            } else if (islower(c)) {
                c = (c - key < 'a') ? 'z' - ('a' - (c - key - 1)) % 26 : c - key;
            }
        }
        cout << "Decoded string is --> " << in_str << endl;

    } else {
        cout << "Bruteforcing all 26 combinations..." << endl;
        for (long long key = 0; key < 26; key++) {
            string str = in_str; // Make a copy for each key
            for (char &c : str) {
                if (isupper(c)) {
                    c = (c - key < 'A') ? 'Z' - ('A' - (c - key - 1)) % 26 : c - key;
                } else if (islower(c)) {
                    c = (c - key < 'a') ? 'z' - ('a' - (c - key - 1)) % 26 : c - key;
                }
            }
            cout << "Key " << key << " --> " << str << endl;
        }
    }
}

void encode() {
    string str;
    cout << "Enter the string to encode: ";
    cin.ignore(); // Ignore any newline left in the input buffer
    getline(cin, str); // Allow spaces in input

    long long key;
    cout << "Enter key for encryption: ";
    cin >> key;

    if (key < 0) {
        cout << "Key has to be positive!" << endl;
        return;
    }

    for (char &c : str) {
        if (isupper(c)) {
            c = (c + key > 'Z') ? 'A' + (c + key - 'Z' - 1) % 26 : c + key;
        } else if (islower(c)) {
            c = (c + key > 'z') ? 'a' + (c + key - 'z' - 1) % 26 : c + key;
        }
    }

    cout << "Encoded string is --> " << str << endl;
}

int main() {
    cout << "Caesar Cipher Encoder and Decoder" << endl;
    long long option;
    do {
        cout << "Modes:\n1.Decode\n2.Encode\n3.Exit\nChosen Mode: ";
        cin >> option;

        switch (option) {
            case 1: decode(); break;
            case 2: encode(); break;
            case 3: cout << "Thanks for using! Exiting now." << endl; break;
            default: cout << "Invalid option! Please choose again." << endl; break;
        }
    } while (option != 3);

    return 0;
}
