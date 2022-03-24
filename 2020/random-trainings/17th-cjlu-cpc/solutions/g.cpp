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
constexpr int mod = 1e9 + 7;
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
constexpr int N = 1e5 + 10;
constexpr int S = 450;
int n, m, q, a[N], f[N], id[N], fid[N], sze[N];
bool isBig[N];
vector<vector<int>> G, T, H;
bitset<N> b[2 * (N / S) + 10];

void run() {
    rd(n, m);
    memset(isBig, 0, sizeof isBig);
    G.clear();
    G.resize(n + 1);
    T.clear();
    T.resize(n + 1);
    for (int i = 1; i <= n; ++i) rd(a[i]);
    for (int i = 1, u, v; i <= m; ++i) {
        rd(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    *id = 0;
    H.clear();
    H.resize(1);
    for (int i = 1; i <= n; ++i) {
        if (SZ(G[i]) > S) {
            isBig[i] = 1;
            id[i] = ++*id;
            fid[*id] = i;
            sze[*id] = SZ(G[i]) + 5;
            b[*id].set();
            H.push_back(vector<int>(sze[*id], 0));
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (auto &v : G[u]) {
            if (isBig[v]) {
                int _v = id[v];
                T[u].push_back(_v);
                int x = a[u];
                if (x < sze[_v]) {
                    ++H[_v][x];
                    if (H[_v][x] == 1)
                        b[_v][x] = 0;
                }
            }
        }
    }
    rd(q);
    for (int i = 1, op, u, x; i <= q; ++i) {
        rd(op, u);
        if (op == 1) {
            rd(x);
        } else {
            if (isBig[u]) {
                x = b[id[u]]._Find_first();
            } else {
                int _sze = SZ(G[u]) + 5;
                for (int i = 0; i <= _sze; ++i) f[i] = 0;
                for (auto &v : G[u]) {
                    if (a[v] < _sze) {
                        f[a[v]] = 1;
                    }
                }
                for (int i = 0; i <= _sze; ++i)
                    if (!f[i]) {
                        x = i;
                        break;
                    }
            }
            pt(x);
        }
        int pre = a[u];
        a[u] = x;
        for (auto &it : T[u]) {
            if (pre < sze[it]) {
                --H[it][pre];
                if (H[it][pre] == 0)
                    b[it][pre] = 1;
            }
            if (x < sze[it]) {
                ++H[it][x];
                if (H[it][x] == 1)
                    b[it][x] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int _T = 1;
    // nextInt();
    while (_T--) run();
    //    for (int kase = 1; kase <= _T; ++kase) {
    //        cout << "Case #" << kase << ": ";
    //        run();
    //    }
    //	while (cin >> n) run();
    //	run();
    return 0;
}