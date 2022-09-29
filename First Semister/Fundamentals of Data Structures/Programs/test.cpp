#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    int x;
    int k;
    string n1, n2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n1;
        
        for (int j = n1.length(); j >= 0; j--)
        {
            n2[j - 1] = n1[n1.length() - j];
        }

        if (n1 == n2)
        {
            cout << "wins" << endl;
        }
        else
        {
            cout << "loses" << endl;
        }
    }
    return 0;
}