#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int pages[3];
    bool miss = false;
    int oldest_element_index = 0;
    int to_add[12] = {
        2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (to_add[i] == pages[i])
            {
                cout << "Hit" << endl;
                miss = false;
            }
            else
            {
                cout << "Miss" << endl;
                miss = true;
            }
        }
        if (miss)
        {
            pages[oldest_element_index] = to_add[i];
            oldest_element_index =
        }
    }

    return 0;
}