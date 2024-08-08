#include <iostream>
using namespace std;
int table[1000001] = {0};
int main()
{
    int n;
    int tmp, sum, x, y;
    for (int i = 1; i < 1000001; i++)
    {
        tmp = i;
        sum = 0;
        while (tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        table[i] = i % sum == 1 ? table[i - 1] + 1 : table[i - 1];
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cout << table[y] - table[x - 1] << endl;
    }
    return 0;
}