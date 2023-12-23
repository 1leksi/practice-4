#include <iostream>
#include <limits>
#include <string.h>

using namespace std;
int const maxWords = 10, inWords = 50;
char firstLetters[] = { 'A', 'B', 'C', 'D', 'E',
                       'F', 'G', 'H', 'I', 'J' };

char arrOfSymbols[] = { ',', '?', '!',
                      ' ', ':', ';',
                      '-' };

void Menu() {

    cout << "1. enter the line" << '\n';
    cout << "2. edit the line" << '\n';
    cout << "3. first task (no. 3)" << '\n';
    cout << "4. second task (no. 4)" << '\n';
    cout << "5. find dlc-strings" << '\n' << '\n';

}



void strWithoutDigs(char string[]) {
    char digs[] = { '0', '1', '2', '3',
                   '4', '5', '6', '7',
                   '8', '9' };
    for (int i = 0; i < strlen(string); i++) {
        for (int j = 0; j < 10; j++) {
            if (string[i] == digs[j]) {
                string[i] = ' ';
            }
        }
    }
}


void deleteSymbols(char string[], char symbol) {
    for (int i = 0; i < strlen(string) - 1; i++) {
        if (string[i] == symbol && string[i + 1] == symbol) {
            for (int j = i + 1; j < strlen(string); j++) {
                string[j - 1] = string[j];
            }
            string[strlen(string) - 1] = '\0'; // конец строки
            i--;
        }
    }
}

void registerChange(char string[]) {
    for (int i = 1; i < strlen(string); i++) {
        string[i] = tolower(string[i]); // вниз
    }
    string[0] = toupper(string[0]); // вверх
}

void clearTheBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int find(char string[], char symbol, int start = 0) {
    for (int index = start; index < strlen(string); index++) {
        if (string[index] == symbol) {
            return index;
        }
    }
    return -1;
}



int main() {

    int taskNumber, words;
    const int sizeOfString = 500;
    char string[sizeOfString], string2[sizeOfString];
    char crackingString[inWords][maxWords] = {};
    bool repeaters;

    Menu();

    for (int repeatTask = 0; repeatTask < 100; repeatTask++) {
        cout << "\n enter the task number: ";
        cin >> taskNumber;
        cout << '\n';
        clearTheBuffer();

        switch (taskNumber) {

        case 1:

            cout << " enter your line: ";
            cin.getline(string, sizeOfString);
            cout << '\n';
            break;

        case 2:

            for (int i = 0; i < strlen(arrOfSymbols); i++) {
                deleteSymbols(string, arrOfSymbols[i]);
            }
            registerChange(string);
            cout << " new string: " << string;
            cout << '\n' << '\n';
            break;

        case 3:
            cout << " sequences without numbers: ";
            strWithoutDigs(string);
            deleteSymbols(string, ' ');
            cout << string;
            break;
            cout << '\n' << '\n';
            break;

        case 4:

            for (int i = 0; i < strlen(string); i++) {
                if (string[i] >= '0' && string[i] <= '9') {
                    string[i] = firstLetters[string[i] - '0'];
                }
            }
            cout << "new string: " << string << '\n' << '\n';
            break;

            return 0;
        }
    }
}