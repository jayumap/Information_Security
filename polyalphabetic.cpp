#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string msg, key, k, ct, pt;
    int lenm, lenk, i, j=0;
    cout << "Enter Message : ";
    getline(cin, msg);
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    cout << "Enter Key : ";
    getline(cin, key);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    lenm = msg.length();
    lenk = key.length();

    //loop for iterating the key to length of the message
    for (i=0; i<lenm; i++,j++) {
        if (j == lenk) {
            j = 0;
        }
        k += key[j];
    }
    

    //loop for generating the cipher text by calculating ct of 1 character and appending it to ct
    for (i=0; i<lenm; i++) { 
        ct += ((msg[i]+k[i])%26)+'A';
    }

    //loop to generate plaintext
    for (i=0; i<lenm; i++) {
        pt += (((ct[i]-k[i])+26)%26)+'A';
    }
    
    //transform(ct.begin(), ct.end(), ct.begin(), ::tolower);
    //transform(pt.begin(), pt.end(), pt.begin(), ::tolower);
    cout << "\nEncrypted Message : " << ct;
    cout << "\nDecrypted Message : " << pt;
    return 0;
}
