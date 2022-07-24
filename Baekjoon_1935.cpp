#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int alpha[26] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> alpha[i];
    }

    stack<double> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            st.push(alpha[s[i] - 'A']);
        }
        else {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            switch (s[i]) {
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}
