#include <iostream>

using namespace std;

// ENCRYPT A LETTER
string encryptLetter(char letter);
// ENCRYPT A TEXT
string encrypt(string msg);

// DECRYPT A LETTER
char decryptLetter(string letter);
// DECRYPT A TEXT
string decrypt(string code);

// MORSE CODE PROGRAM
void morseCode()
{
    int choice;

    cout << "Welcome to morse code program!\n"
            "============================================================\n"
            "NOTE: this program supports aplphanumeric [a-z 0-9] and some punctuation [. - , ! ? ' \"] letters only.\n"
            "any other letter will be discarded.\n"
            "capital letters will be encoded like small ones.\n"
            "there is one space between every letter and three spaces between words.\n"
            "============================================================\n"
            "1- Encrypt a message\n"
            "2- Decrypt a message\n"
            "3- Exit\n"
            "Enter your choice: ";

    cin >> choice;

    while (choice > 3 || choice < 1)
    {
        // reset error flag to make cin continue working
        cin.clear();
        // discard all the characters in the buffer
        cin.ignore(INT_MAX, '\n');
        cout << "This is invalid choice, please enter 1, 2 or 3: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        string msg;
        cout << "\nEnter the message: ";

        // ignore the remaining newline character to make getline work properly
        cin.ignore(1);

        getline(cin, msg);
        cout << "\n" + encrypt(msg) << endl;
    }
    else if (choice == 2)
    {
        string code;
        cout << "\nNOTE: Enter one space between letters and three spaces between words to get what you want\n"
                "Enter the encrypted code: ";

        // ignore the remaining newline character to make getline work properly
        cin.ignore(1);

        getline(cin, code);
        cout << "\n" + decrypt(code) << endl;
    }
    else if (choice == 3)
    {
        cout << "\nGood bye!" << endl;
    }
}

string encrypt(string msg)
{
    string code;
    string letter;

    for (int i = 0; i < msg.length(); i++)
    {
        letter = encryptLetter(msg[i]);
        if (letter == "")
        {
            continue;
        }
        code = code + letter + " ";
    }
    return code;
}
string decrypt(string code)
{
    string msg = "";
    string letter = "";

    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == ' ')
        {
            msg += decryptLetter(letter);
            if (code[i + 1] == ' ' && code[i + 2] == ' ')
            {
                msg += ' ';
                i = i + 2;
            }
            letter = "";
        }
        else
        {
            letter += code[i];
        }
    }
    // last letter may don't have space after it so we proccess it manually
    msg += decryptLetter(letter);

    return msg;
}
string encryptLetter(char letter)
{
    string encryptedLetter;
    switch (letter)
    {
    case 'a':
    case 'A':
        encryptedLetter = ".-";
        break;
    case 'b':
    case 'B':
        encryptedLetter = "-...";
        break;
    case 'c':
    case 'C':
        encryptedLetter = "-.-.";
        break;
    case 'd':
    case 'D':
        encryptedLetter = "-..";
        break;
    case 'e':
    case 'E':
        encryptedLetter = ".";
        break;
    case 'f':
    case 'F':
        encryptedLetter = "..-.";
        break;
    case 'g':
    case 'G':
        encryptedLetter = "--.";
        break;
    case 'h':
    case 'H':
        encryptedLetter = "....";
        break;
    case 'i':
    case 'I':
        encryptedLetter = "..";
        break;
    case 'j':
    case 'J':
        encryptedLetter = ".---";
        break;
    case 'k':
    case 'K':
        encryptedLetter = "-.-";
        break;
    case 'l':
    case 'L':
        encryptedLetter = ".-..";
        break;
    case 'm':
    case 'M':
        encryptedLetter = "--";
        break;
    case 'n':
    case 'N':
        encryptedLetter = "-.";
        break;
    case 'o':
    case 'O':
        encryptedLetter = "---";
        break;
    case 'p':
    case 'P':
        encryptedLetter = ".--.";
        break;
    case 'q':
    case 'Q':
        encryptedLetter = "--.-";
        break;
    case 'r':
    case 'R':
        encryptedLetter = ".-.";
        break;
    case 's':
    case 'S':
        encryptedLetter = "...";
        break;
    case 't':
    case 'T':
        encryptedLetter = "-";
        break;
    case 'u':
    case 'U':
        encryptedLetter = "..-";
        break;
    case 'v':
    case 'V':
        encryptedLetter = "...-";
        break;
    case 'w':
    case 'W':
        encryptedLetter = ".--";
        break;
    case 'x':
    case 'X':
        encryptedLetter = "-..-";
        break;
    case 'y':
    case 'Y':
        encryptedLetter = "-.--";
        break;
    case 'z':
    case 'Z':
        encryptedLetter = "--..";
        break;
    case '0':
        encryptedLetter = "-----";
        break;
    case '1':
        encryptedLetter = ".----";
        break;
    case '2':
        encryptedLetter = "..---";
        break;
    case '3':
        encryptedLetter = "...--";
        break;
    case '4':
        encryptedLetter = "....-";
        break;
    case '5':
        encryptedLetter = ".....";
        break;
    case '6':
        encryptedLetter = "-....";
        break;
    case '7':
        encryptedLetter = "--...";
        break;
    case '8':
        encryptedLetter = "---..";
        break;
    case '9':
        encryptedLetter = "----.";
        break;
    case ' ':
        encryptedLetter = " ";
        break;
    case '.':
        encryptedLetter = ".-.-.-";
        break;
    case '-':
        encryptedLetter = "-....-";
        break;
    case ',':
        encryptedLetter = "--..--";
        break;
    case '!':
        encryptedLetter = "-.-.--";
        break;
    case '?':
        encryptedLetter = "..--..";
        break;
    case '\'':
        encryptedLetter = ".----.";
        break;
    case '\"':
        encryptedLetter = ".-..-.";
        break;
    default:
        encryptedLetter = "";
        break;
    }
    return encryptedLetter;
}

char decryptLetter(string letter)
{
    char decryptedLetter;

    if (letter == ".-")
        decryptedLetter = 'a';
    else if (letter == "-...")
        decryptedLetter = 'b';
    else if (letter == "-.-.")
        decryptedLetter = 'c';
    else if (letter == "-..")
        decryptedLetter = 'd';
    else if (letter == ".")
        decryptedLetter = 'e';
    else if (letter == "..-.")
        decryptedLetter = 'f';
    else if (letter == "--.")
        decryptedLetter = 'g';
    else if (letter == "....")
        decryptedLetter = 'h';
    else if (letter == "..")
        decryptedLetter = 'i';
    else if (letter == ".---")
        decryptedLetter = 'j';
    else if (letter == "-.-")
        decryptedLetter = 'k';
    else if (letter == ".-..")
        decryptedLetter = 'l';
    else if (letter == "--")
        decryptedLetter = 'm';
    else if (letter == "-.")
        decryptedLetter = 'n';
    else if (letter == "---")
        decryptedLetter = 'o';
    else if (letter == ".--.")
        decryptedLetter = 'p';
    else if (letter == "--.-")
        decryptedLetter = 'q';
    else if (letter == ".-.")
        decryptedLetter = 'r';
    else if (letter == "...")
        decryptedLetter = 's';
    else if (letter == "-")
        decryptedLetter = 't';
    else if (letter == "..-")
        decryptedLetter = 'u';
    else if (letter == "...-")
        decryptedLetter = 'v';
    else if (letter == ".--")
        decryptedLetter = 'w';
    else if (letter == "-..-")
        decryptedLetter = 'x';
    else if (letter == "-.--")
        decryptedLetter = 'y';
    else if (letter == "--..")
        decryptedLetter = 'z';
    else if (letter == "-----")
        decryptedLetter = '0';
    else if (letter == ".----")
        decryptedLetter = '1';
    else if (letter == "..---")
        decryptedLetter = '2';
    else if (letter == "...--")
        decryptedLetter = '3';
    else if (letter == "....-")
        decryptedLetter = '4';
    else if (letter == ".....")
        decryptedLetter = '5';
    else if (letter == "-....")
        decryptedLetter = '6';
    else if (letter == "--...")
        decryptedLetter = '7';
    else if (letter == "---..")
        decryptedLetter = '8';
    else if (letter == "----.")
        decryptedLetter = '9';
    else if (letter == ".-.-.-")
        decryptedLetter = '.';
    else if (letter == "-....-")
        decryptedLetter = '-';
    else if (letter == "--..--")
        decryptedLetter = ',';
    else if (letter == "-.-.--")
        decryptedLetter = '!';
    else if (letter == "..--..")
        decryptedLetter = '?';
    else if (letter == ".----.")
        decryptedLetter = '\'';
    else if (letter == ".-..-.")
        decryptedLetter = '\"';
    else
        decryptedLetter = 0;

    return decryptedLetter;
}