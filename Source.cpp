#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum vectorStatus 
{
	TEXT,
	ENCRYPTED_TEXT
};

void CaesarShipherCoding(int& shift, vector<string>& text_and_encrypted_text)
{
	string message;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter your message: ";
	getline(cin, message);
	text_and_encrypted_text.push_back(message);
	text_and_encrypted_text.push_back(message);
	for (int i = 0; i < text_and_encrypted_text[TEXT].size(); i++)
	{
		text_and_encrypted_text[ENCRYPTED_TEXT][i] += shift;
	}
	cout << "Original message: " << endl;
	cout << text_and_encrypted_text[TEXT] << endl;
	cout << "Recieved encrypted message: " << endl;
	cout << text_and_encrypted_text[ENCRYPTED_TEXT] << endl;

	if (text_and_encrypted_text.size() != 0)
	{
		text_and_encrypted_text.clear();
	}
}

void CaesarShipherDecoding(int& shift, vector<string>& text_and_encrypted_text)
{
	string message;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Enter your Crypted message: ";
	getline(cin, message);
	text_and_encrypted_text.push_back(message);
	text_and_encrypted_text.push_back(message);
	for (int i = 0; i < text_and_encrypted_text[ENCRYPTED_TEXT].size(); i++)
	{
		text_and_encrypted_text[TEXT][i] -= shift;
	}
	cout << "Encrypted message: " << endl;
	cout << text_and_encrypted_text[ENCRYPTED_TEXT] << endl;
	cout << "Recieved original message: " << endl;
	cout << text_and_encrypted_text[TEXT] << endl;

	if (text_and_encrypted_text.size() != 0)
	{
		text_and_encrypted_text.clear();
	}
}

int main()
{
	vector<string> text_and_encrypted_text;

	int shift;
	int choice;
	
		cout << "--------------------" << endl;
		cout << "What needs to be done?" << endl;
		cout << "[1] Code message:" << endl;
		cout << "[2] Decode message:" << endl;
		cout << "to exit the program, enter 0" << endl;
		cout << "--------------------" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter your shift: ";
			cin >> shift;
			CaesarShipherCoding(shift, text_and_encrypted_text);
			break;
		case 2:
			cout << "Enter your shift: ";
			cin >> shift;
			CaesarShipherDecoding(shift, text_and_encrypted_text);
			break;
		default:
			cout << "Something went wrong, try again..." << endl;
			break;
		}

	return 0;	
}