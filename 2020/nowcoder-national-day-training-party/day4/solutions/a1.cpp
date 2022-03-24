#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 1010;
vector<long long> v[N];

int main() {
    int n;
    cin >> n;
    string s;
    for (int k = 0; k <= n; k++) {
        cin >> s;
        long long x = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                x = x * 10 + (s[i] ^ 0x30);
            } else {
                if (x)
                    v[k].push_back(x), x = 0;
                v[k].push_back(s[i] ^ (1ll << 32));
            }
        }
        if (x)
            v[k].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        cout << (v[i] < v[0] ? '-' : '+') << endl;
    }
    return 0;
}