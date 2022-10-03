// he compressed string of "bbbbbbbbbbaa" is "b10a2", which is shorter.
// The compressed string of "c" is "c1", which is not shorter than "c".
// The compressed string of "aaaaaaaaaabcdefgh" is "a10b1c1d1e1f1g1h1", which is not shorter than "aaaaaaaaaabcdefgh" (both strings have length 1717).
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, n, max, temp, count = 0;
    cin >> t;
    string test;
    while (t--)
    {
        cin >> test;
        string output = "";
        count = 1;
        for (int i = 1; i < test.length(); i++)
        {
            // Check if the previous element and the current element are the same, in which case increment count.
            if (test[i] == test[i - 1])
            {
                count++;
            }

            // If they arent same, then that means we are done with that elements' count. So append it to the output string along with its count.
            else if ((test[i] != test[i - 1]))
            {
                output += test[i - 1] + to_string(count);
                // Reset the value of count for the next element.
                count = 1;
            }

            // If we are checking the last element, then it means the string is over and we have to add it to output.
            if (i == test.length() - 1)
            {
                output += test[i - 1] + to_string(count);
                count = 1;
            }
        }

        // Naturally if the output string is empty, the input string is empty and no point.
        if (output.length() == 0)
        {
            cout << "NO" << endl;
        }
        // If the length is strictly less thant he original length, then print yes. or else no.
        else if (output.length() < test.length())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
