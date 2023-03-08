#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int key;
    //key = 3;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key value: ";
    cin >> key;

    // Encryption
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')//uppercase
        {       
            text[i] = 'A' + ((text[i] - 'A' + key) % 26);//formula
        }
        
        
        else if (text[i] >= 'a' && text[i] <= 'z')//lowercase
        {   
            text[i] = 'a' + ((text[i] - 'a' + key) % 26);//formula
        }
    }

    cout << "Encrypted text: " << text << endl;


    // Decryption
    for (int i = 0; i < text.length(); i++)
    {       
        if (text[i] >= 'A' && text[i] <= 'Z')
        {            
            text[i] = 'A' + ((text[i] - 'A' - key + 26) % 26);//converting back to plaintext
        }
        
        else if (text[i] >= 'a' && text[i] <= 'z')
        {            
            text[i] = 'a' + ((text[i] - 'a' - key + 26) % 26);
        }
    }

    cout << "Decrypted text: " << text << endl;


    return 0;
}
