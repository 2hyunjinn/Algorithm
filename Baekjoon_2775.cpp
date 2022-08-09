#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    
    int floor[15][14] = { 0, };
    for (int i = 0; i < 14; i++)
        floor[0][i] = i + 1;
    for (int i = 0; i < 14; i++)
    {
        int sum = 0;
        for (int j = 0; j < 14; j++)
        {
            sum += floor[i][j];
            floor[i + 1][j] = sum;
        }
    }

    int k, n;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        cin >> n;

        cout << floor[k][n - 1] << '\n';
    }
    return 0;
}
