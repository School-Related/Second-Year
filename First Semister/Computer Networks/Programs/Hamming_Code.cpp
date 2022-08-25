// You will be given a string as input and you have to find the resulting hamming code to be sent.
// Also check which bit if flipped after flipping it.

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int m, r[20][20];
int r_val = 0;

void display_r()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
}

// Returns the length of the resulting hamming code
int calc_length(string input)
{
    //  2^r > m + r + 1
    m = input.length();
    int r = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pow(2, i) >= m + i + 1)
        {
            r = i;
            break;
        }
    }
    r_val = r;
    return m + r;
}

// Fills the values of r in the 2d array
void fill_r_values(int hamming_len)
{
    int count = 0;
    bool should_add = false;
    for (int k = 0; k < hamming_len; k++)
    {
        count = 0;
        should_add = false;
        for (int i = 0, j = 0; i <= hamming_len; i++)
        {
            if (count == pow(2, k))
            {
                count = 0;
                should_add = should_add ? false : true; // flips it
            }

            if (should_add == true)
            {
                r[k][j] = i;
                j++;
            }
            count++;
        }
    }
}

// Fills the first column of the r table, to 1 or 0 for maintaining even parity. 
void fill_r_parity(int hamming_len, bool hamming[])
{
    int count = 0;
    bool parity = false;
    for (int i = 0; i < hamming_len; i++)
    {
        // check parity
        count = 0;
        for (int j = 1; j <= hamming_len / 2; j++)
        {
            hamming[r[i][j] - 1] ? count++ :count;
        }
        parity = count % 2 == 0 ? false : true; // if number of 1's is even
        r[i][0] = parity;                       // assign parity bit
    }
}

// Fills the hamming array by looking at the parity r bits from the r array.
void fill_hamming(int hamming_len, bool hamming[])
{
    int k = 0;
    for (int j = 0; j < hamming_len; j++)
    {
        if (j == pow(2, k) - 1)
        {
            hamming[j] = r[k][0];
            k++;
        }
    }
}

void display_hamming(int hamming_len, bool hamming[])
{
    cout << "The Hamming code to be sent by the sender is: " << endl;
    for (int i = hamming_len - 1; i >= 0; i--)
    {
        cout << hamming[i];
    }
    cout << endl;
}

int main()
{
    string input;
    int hamming_len;
    // Input the value as a string, as we dont know how long it can be.
    cout << "Enter the Input : " << endl;
    cin >> input;

    // Edge Case
    if (input.length() == 0)
        return 0;
    else
        m = input.length();

    // Find the value of r and the length of the hamming code
    hamming_len = calc_length(input);

    // Declare an array to store the hamming code
    bool hamming[hamming_len] = {false};

    // Store the bits
    for (int i = 0, j = 0, k = m; i < hamming_len; i++)
    {
        if (i != (pow(2, j) - 1))
        {
            hamming[i] = (input[k - 1] == '1');
            k--;
        }
        else
        {
            j++;
        }
    }

    // fill the values of r till hamming_len
    fill_r_values(hamming_len);

    // Fill r with even parity
    fill_r_parity(hamming_len, hamming);

    // Fill the hamming code
    fill_hamming(hamming_len, hamming);

    display_r();

    display_hamming(hamming_len, hamming);

    return 0;
}
