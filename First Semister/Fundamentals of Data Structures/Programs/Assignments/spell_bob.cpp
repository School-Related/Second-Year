#include <iostream>
using namespace std;

int main()
{

    int t, count = 0;
    string top_face, bottom_face;
    cin >> t;
    while (t--)
    {
        int count_b = 0, count_o = 0;
        bool can_spell_bob = true;
        // Accepting Input
        cin >> top_face;
        cin >> bottom_face;

        for (int i = 0; i < 3; i++)
        {
            // Checking if the Card contains b on the bottom or the top
            if ((top_face[i] == 'b' || bottom_face[i] == 'b'))
            {
                count_b++;
            }

            // Checking if the Card contains o on the bottom or the top
            if ((top_face[i] == 'o' || bottom_face[i] == 'o'))
            {
                count_o++;
            }

            // Checking if the card doesnt contain any of 'b' or 'o', in which case you cant spell bob either way. So quit. 
            if (top_face[i] != 'b' && bottom_face[i] != 'b' && top_face[i] != 'o' && bottom_face[i] != 'o')
            {
                can_spell_bob = false;
                break;
            }
        }

        // Checking if the given conditions match
        if (count_b >= 2 && count_o >= 1 && can_spell_bob)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}