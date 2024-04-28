/*\
Name: Branden Kozel
Date: 4/25/24
Class: 1202 201
\*/

#include <iostream>

using namespace std;

class invalidCharacterException {};
class invalidRangeException {};

char character(char start, int offset) 
{
    if (!isalpha(start)) 
    {
        throw invalidCharacterException();
    }

    if (!isalpha(start + offset) || (isupper(start) && islower(start + offset)) || (islower(start) && isupper(start + offset))) 
    {
        throw invalidRangeException();
    }

    return start + offset;
}

int main() 
{
    char userChar;


    try {
        cin >> userChar; cout << "  " << character(userChar, 1); cout << endl;
    }
    catch (invalidCharacterException) {
        cout << "invalidCharacterException." << endl;
    }
    catch (invalidRangeException) {
        cout << "invalidRangeException." << endl;
    }


    return 0;
}