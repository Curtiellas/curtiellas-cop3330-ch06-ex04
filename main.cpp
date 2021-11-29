/* ch06 ex04
ch04 ex19 Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22. For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding positions,
so that if names[7]=="Joe" then scores[7]==17). Terminate input
with NoName 0. Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.

ch06 ex04 Define a class Name_value that holds a string and a value. Rework exercise
19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
*/

#include <iostream>
#include <limits>
#include <string.h>
#include <vector>

#include "Name_value.h"
#include "Name_value.cpp"

using namespace std;

int main()
{
    vector<Name_value> v;

    // temp values
    char name[20];
    int score;

    do
    {
        cout << "Enter a name followed by an integer (\"NoName 0\" to end): ";

        try
        {
            cin >> name;
            if (cin.fail())
                throw "Invalid name. Try again.";

            cin >> score;
            if (cin.fail())
                throw "Invalid score. Try again.";

            if (strcmp(name, "NoName") == 0 && score == 0)
                throw "\nIteration ended properly.\n";

            else
            {
                // check if the name is repeated
                for (int a = 0; a < v.size(); a++)
                    if (strcmp(v[a].getName(), name) == 0 && !strcmp("NoName", name))
                        throw "Name already entered. Try Again.";

                Name_value temp(name, score);
                v.push_back(temp);
            }
        }
        catch (const char *e)
        {
            // print error type
            cerr << e << endl;
            // clear the error state of the buffer
            cin.clear();
            // ignore the rest of the line after the first instance of error that has occurred
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }

    } while (strcmp(name, "NoName") != 0 || score != 0);

    // traverse the vector list
    for (int a = 0; a < v.size(); a++)
    {
        cout << v[a].getName() << " " << v[a].getScore() << endl;
    }

    // empty the vector
    v.clear();
}