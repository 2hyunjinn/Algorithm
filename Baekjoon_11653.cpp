#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n; //고리의 수 입력
    
    int i = 2;
    while(n>1) {
        if (n % i) {
            i++;
        }
        else {
            cout << i << endl;
            n /= i;
        }
    }
    return 0;
}
