#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
constexpr int mod = 998244353;
template <class T1, class T2>
inline void chadd(T1 &x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1 &x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1 &x, T2 y) {
    if (x > y)
        x = y;
}
inline int nextInt() {
    int x;
    cin >> x;
    return x;
}
void rd() {}
template <class T, class... Ts>
void rd(T &arg, Ts &...args) {
    cin >> arg;
    rd(args...);
}
#define dbg(x...)                             \
    do {                                      \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
    for (auto &v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T &arg, const Ts &...args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T &arg, const Ts &...args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t> &arg, const A &...args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}
inline ll qpow(ll base, ll n) {
    assert(n >= 0);
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
// head
constexpr int N = 5e5 + 10;
constexpr int M = 1300;
int n, f[M], g[N];

void gao() {
    f[1] = 1, f[2] = 2, f[3] = 5, f[4] = 7;
    for (int i = 5; i < M; ++i) f[i] = 3 + 2 * f[i - 2] - f[i - 4];
    g[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll sum[4] = {0}, now = 0;
        int j = 1;
        for (; f[j + 3] <= i; j += 4) {
            sum[0] += g[i - f[j]];
            sum[1] += g[i - f[j + 1]];
            sum[2] -= g[i - f[j + 2]];
            sum[3] -= g[i - f[j + 3]];
        }
        now = (sum[0] + sum[1] + sum[2] + sum[3]) % mod;
        for (; f[j] <= i; ++j) {
            if ((j + 1) >> 1 & 1) {
                now += g[i - f[j]];
            } else {
                now -= g[i - f[j]];
            }
        }
        now = (now + mod) % mod;
        g[i] = now;
    }
}

void run() {
    rd(n);
    gao();
    pt(g[n - 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int _T = 1;
    while (_T--) run();
    //    for (int kase = 1; kase <= _T; ++kase) {
    //        cout << "Case #" << kase << ": ";
    //        run();
    //    }
    //	while (cin >> n) run();
    //	run();
    return 0;
}