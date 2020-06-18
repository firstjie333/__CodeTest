#include <iostream>
using namespace std;

/**
 * @brief 小赛旅游
 * 
 * @return int 
 */
int main()
{
    int n, num, count = 0, i, j = 0;
    cin >> n >> num;
    while (num >= 0)
    {
        cin >> i;
        if (i > n)
        {
            count = 0;
            break;
        }
        if (i + j > n)
        {
            count++;
            j = i;
        }
        else
        {
            j += i;
        }
        num--;
    }
    cout << count << endl;
    return 0;
}