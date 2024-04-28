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
    int numOffset = 1;

    cout << "Testing Time!\nPlease enter a letter and then an offset number. \nEXAMPLE: "
         << "character('a', 1) returns: " << character('a', 1) << endl

         << "\nNow Please enter the letter you wish to test: "; cin >> userChar;
    cout << "\nNow enter the offset number (Can be a negative number): "; cin >> numOffset;

    try 
    {
        if (numOffset < 0)
        {
            cout << "The letter before " << userChar << " is: " << character(userChar, numOffset); cout << endl;
        }

        else 
        {
            cout << "The letter after " << userChar << " is: " << character(userChar, numOffset); cout << endl;
        }
       
    }

    catch (invalidCharacterException) 
    {
        cout << "\ninvalidCharacterException! " << userChar << " is not valid. We only accept letters, a b c etc." << endl;
    }

    catch (invalidRangeException) 
    {
        cout << "\ninvalidRangeException! " << userChar << " and " << numOffset << " do not mix.\nThis combination goes outside of the alphabet!";
    }

    return 0;
}