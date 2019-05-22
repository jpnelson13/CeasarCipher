#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

// Base class
class Key {
public:
	int keyNum = 0;
	void userKey() {
		cout << "Enter a key number 1-26 for encryption or decryption: " << endl;
		cin >> keyNum;
	}
};

// Derived class 
class Encryption : public Key {
public:
	char message[100];
	string input;
	size_t i = 0;
	int cipherValue;
	char cipher;
	void encryptMessage() {
		userKey();
		cin.ignore(100, '\n');
		cout << "Enter a message of alphabetical characters you would like to encrypt: " << endl;
		getline(cin, input);
		strcpy_s(message, input.c_str());
	}
	void encryptionRecursion() {
		if (message[i] != '\0' && message[i] != ' ' && strlen(message) - 1 >= i) {
			cipherValue = ((int)message[i] - 97 + keyNum) % 26 + 97;
			cipher = (char)(cipherValue);
			printf("%c", cipher);
			i++;
			encryptionRecursion();
		}
		else if (message[i] == ' ') {
			cout << (" ");
			i++;
			encryptionRecursion();
		}
		else {
			cout << endl;
			system("pause");
		}
	}
};

// Derived class 
class Decryption : public Key {
public:
	char message[100];
	string input;
	size_t i = 0;
	int cipherValue;
	char cipher;
	void decryptMessage() {
		userKey();
		cin.ignore(100, '\n');
		cout << "Enter a message of alphabetical characters you would like to decrypt: " << endl;
		getline(cin, input);
		strcpy_s(message, input.c_str());
	}
	void decryptionRecursion() {
		if (message[i] != '\0' && message[i] != ' ' && strlen(message) - 1 >= i) {
			cipherValue = ((int)message[i] - 97 - keyNum) % 26 + 97;
			cipher = (char)(cipherValue);
			printf("%c", cipher);
			i++;
			decryptionRecursion();
		}
		else if (message[i] == ' ') {
			cout << (" ");
			i++;
			decryptionRecursion();
		}
		else {
			cout << endl;
			system("pause");
		}
	}
};

// Derived class 
// The correct Key Number is 3 for testing
class StoredMessages : public Key {
public:
	char message[100];
	string input = "Encryption or decryption successful. This system is ready for further testing of messages.";
	size_t i = 0;
	int cipherValue;
	char cipher;
	int starter = 0;
	void keyNumber() {
		cout << "Enter the correct key number 1-26 to access the stored message: " << endl;
		cin >> keyNum;
		cin.ignore(100, '\n');
		strcpy_s(message, input.c_str());
	}
	void storedRecursion() {
		if (keyNum == 3) {
			if (starter == 0) {
				cout << "The Encrypted message is ";
				starter++;
			}
			if (message[i] != '\0' && message[i] != ' ' && strlen(message) - 1 >= i) {
				cipherValue = ((int)message[i] - 97 + 3) % 26 + 97;
				cipher = (char)(cipherValue);
				printf("%c", cipher);
				i++;
				storedRecursion();
			}
			else if (message[i] == ' ') {
				cout << (" ");
				i++;
				storedRecursion();
			}
			else {
				cout << endl;
				cout << "The Decrypted message is " << input << endl;
				system("CLS");
				system("pause");
			}
		}
		else {
			cout << "Invalid key number, please try again!" << endl;
			system("pause");
			system("CLS");
		}
	}
};
int main()
{
	//declaring objects
	Encryption encrypt;
	Decryption decrypt;
	StoredMessages stored;

	//Menu Creation
	int choice = 1;

	while (choice > 0) {
		cout << "Welcome to my Caesar Cipher!" << endl;
		cout << "Would you like to Encrypt a message, Decrypt a message, or view a stored message?" << endl;
		cout << "Press 1 to Encrypt, 2 to Decrypt, and 3 to view the stored message: " << endl;
		cin >> choice;
		system("CLS");

		if (choice == 1) {
			encrypt.encryptMessage();
			encrypt.encryptionRecursion();
			system("CLS");
			cout << "Do you want to go back to the menu or exit?" << endl;
			cout << "Press 1 to go back to the menu and 0 to exit: " << endl;
			cin >> choice;
			system("CLS");
		}
		else if (choice == 2) {
			decrypt.decryptMessage();
			decrypt.decryptionRecursion();
			system("CLS");
			cout << "Do you want to go back to the menu or exit?" << endl;
			cout << "Press 1 to go back to the menu and 0 to exit: " << endl;
			cin >> choice;
			system("CLS");
		}
		else if (choice == 3) {
			stored.keyNumber();
			stored.storedRecursion();
			cout << "Do you want to go back to the menu or exit?" << endl;
			cout << "Press 1 to go back to the menu and 0 to exit: " << endl;
			cin >> choice;
			system("CLS");
		}
		else {
			cout << "Invalid command, please try again!" << endl;
			system("CLS");
		}
	}

	system("pause");
	return 0;
}
