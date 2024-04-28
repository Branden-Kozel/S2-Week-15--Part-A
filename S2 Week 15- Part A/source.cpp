/*\
Name: Branden Kozel
Date: 4/27/24
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
    int secretNum;

    cout << "Testing Time!\nPlease enter a letter and then an offset number. \nEXAMPLE: "
         << "character('a', 1) returns: " << character('a', 1) << endl

         << "\nNow Please enter the letter you wish to test: "; cin >> userChar;
    cout << "\nNow enter the offset number (Can be a negative number): "; cin >> numOffset;

    if (numOffset == 427)
    {
        cout << "\nHooray! Happy Stanley Day!\nDo you Know the super secret pin number (hint it is four digits)??? "; cin >> secretNum;
        if (secretNum == 2845)
        {
            cout << "\nEPIC. You know the code! Here take this Stanlurine for your troubles."
                << "\nNow where were we... Oh yeah!\nI can tell you right now that you are going to get a invalidRangeException so we are just going to end the program here." << endl;
            return 0;
        }

        else
        {
            cout << "\nAwww. You got it wrong, how tragic. Well that's the end of that.\n"
                 << "Um what were we doing... Oh yeah! This number you inputted breaks this program so I am just going to end it here." << endl;
            return 0;
        }

    }

    try 
    {
        if (numOffset < 0)
        {
            if (numOffset < -1)
            {
                cout << "The letter " << (numOffset - numOffset - numOffset) << " places before " << userChar << " is: " << character(userChar, numOffset); cout << endl;
                return 0;
            }

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
        cout << "\ninvalidRangeException! " << userChar << " and " << numOffset << " do not mix.\nThis combination goes outside of the alphabet!" << endl;
    }

    return 0;
}