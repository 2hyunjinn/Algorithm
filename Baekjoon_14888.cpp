#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int max_= -1000000001;
int min_ = 1000000001;
int A[11] = { 0 };
int op[4] = { 0 };

void operate(int a, int idx)
{
    if (idx == n)
    {
        if (a > max_)
            max_ = a;
        if (a < min_)
            min_ = a;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            if (i == 0)
                operate(a + A[idx], idx + 1);
            else if (i == 1)
                operate(a - A[idx], idx + 1);
            else if (i == 2)
                operate(a * A[idx], idx + 1);
            else
                operate(a / A[idx], idx + 1);
            op[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
    return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	operate(A[0], 1);
	cout << max_ << endl << min_; 
	
	return 0;
}
