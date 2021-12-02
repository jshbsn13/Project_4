#include <iostream>
#include "DelimiterStack.h"
using namespace std;







int main() {

    DelimiterStack myDStack;

    int lineNumber = 0;
    string currentLine = "";

    do {
        //get a line of text from the user

        cout << "Enter a line of text or type DONE: " << endl;

        getline(cin, currentLine);



        //parse input ignore non delimiters
        for (int i = 0; i < currentLine.size(); ++i)
        {

            //if opening delimiter push to stack
            if (currentLine.at(i) == '{' || currentLine.at(i) == '(' || currentLine.at(i) == '[')
            {
                myDStack.push(currentLine.at(i), lineNumber, i);
            }

            //if a closing delimiter pop top of stack
            if (currentLine.at(i) == '}' || currentLine.at(i) == ')' || currentLine.at(i) == ']')
            {
                if (myDStack.isEmpty())
                {
                    cout << "Right delimiter " << currentLine.at(i) << " had no left delimiter at line "<< lineNumber<< ", char "<<i<<endl;
                }
                else
                {
                    char delimiterChar = '\0';
                    int lineNum = 0;
                    int charIndex = 0;

                    myDStack.popDelimiter(delimiterChar, lineNum, charIndex);

                    //check for mismatches and display error message
                    if (currentLine.at(i) == '}' && delimiterChar != '{')
                    {
                        cout << "Mismatched delimiter "<< delimiterChar<< " found at line "<<lineNum<<", char "<<charIndex;
                        cout << " does not match "<<currentLine.at(i)<< " found at line "<<lineNumber<<", char "<<i<<endl;
                    }

                    if (currentLine.at(i) == ')' && delimiterChar != '(')
                    {
                        cout << "Mismatched delimiter "<< delimiterChar<< " found at line "<<lineNum<<", char "<<charIndex;
                        cout << " does not match "<<currentLine.at(i)<< " found at line "<<lineNumber<<", char "<<i<<endl;
                    }

                    if (currentLine.at(i) == ']' && delimiterChar != '[')
                    {
                        cout << "Mismatched delimiter "<< delimiterChar<< " found at line "<<lineNum<<", char "<<charIndex;
                        cout << " does not match "<<currentLine.at(i)<< " found at line "<<lineNumber<<", char "<<i<<endl;
                    }
                }
            }
        }

        //check if error needs to be thrown
        if (!myDStack.isEmpty())
        {
            while (!myDStack.isEmpty())
            {
                char delimChar = '\0';
                int lineNum = 0;
                int charIndex = 0;

                myDStack.popDelimiter(delimChar, lineNum, charIndex);

                cout << "Left delimiter "<<delimChar<<" at line "<<lineNum<<", char "<<charIndex<<" had no right delimiter."<<endl;
            }
        }



    } while (currentLine != "DONE");

    return 0;
}
