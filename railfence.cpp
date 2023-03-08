#include <iostream>
#include <string>

using namespace std;

int main() {
    // Ask user for plaintext input
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    
    // Ask user for key input
    int key;
    cout << "Enter the key: ";
    cin >> key;
    
    // Initialize the rail array with null characters
    char rail[key][plaintext.length()];
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < plaintext.length(); j++) {
            rail[i][j] = '\0';
        }
    }
    
    // Traverse the rail array in a zigzag pattern and fill it with plaintext characters
    int row = 0, col = 0, dir = -1;
    for (int i = 0; i < plaintext.length(); i++) {
        rail[row][col] = plaintext[i];
        if (row == 0 || row == key-1) {
            dir = -dir;
        }
        row += dir;
        col++;
    }
    
    // Generate the ciphertext by concatenating non-null characters from the rail array
    string ciphertext = "";
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < plaintext.length(); j++) {
            if (rail[i][j] != '\0') {
                ciphertext += rail[i][j];
            }
        }
    }
    
    // Print the ciphertext to the console
    cout << "Ciphertext: " << ciphertext << endl;
    

    // Decrypt the ciphertext using the same rail array pattern
    string decrypted = "";
    row = 0, col = 0, dir = -1;
    for (int i = 0; i < ciphertext.length(); i++) {
        decrypted += rail[row][col];
        if (row == 0 || row == key-1) {
            dir = -dir;
        }
        row += dir;
        col++;
    }
    
    // Print the decrypted plaintext to the console
    cout << "Decrypted plaintext: " << decrypted << endl;
    
    return 0;
}
