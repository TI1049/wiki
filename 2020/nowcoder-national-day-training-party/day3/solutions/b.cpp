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
constexpr db INF = 0x3f3f3f3f;
int n, m, S, T;
db a;

const db eps = 1e-4;
int sgn(db x) {
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

struct E {
    int v, x, y;
    E() {}
    E(int v, int x, int y) : v(v), x(x), y(y) {}
};

vector<vector<E>> G;

struct Dijkstra {
    struct node {
        int u;
        db w;
        node(int u = 0, db w = 0) : u(u), w(w) {}
        bool operator<(const node &other) const {
            return sgn(w - other.w) > 0;
        }
    };
    db dis[N];
    bool used[N];
    db gao(int s) {
        for (int i = 1; i <= n; ++i) {
            dis[i] = INF;
            used[i] = 0;
        }
        priority_queue<node> pq;
        dis[s] = 0;
        pq.push(node(s, dis[s]));
        while (!pq.empty()) {
            int u = pq.top().u;
            pq.pop();
            if (used[u])
                continue;
            if (u == T)
                return dis[T];
            used[u] = 1;
            for (auto &it : G[u]) {
                int v = it.v, x = it.x, y = it.y;
                db w = x + a * y;
                if (sgn(dis[v] - dis[u] - w) > 0) {
                    dis[v] = dis[u] + w;
                    pq.push(node(v, dis[v]));
                }
            }
        }
    }
} dij;

void run() {
    rd(n, m, S, T);
    G.clear();
    G.resize(n + 1);
    for (int i = 1, u, v, x, y; i <= m; ++i) {
        rd(u, v, x, y);
        G[u].push_back(E(v, x, y));
        G[v].push_back(E(u, x, y));
    }
    db res = 0;
    for (int i = 1; i <= 10000; ++i) {
        a = i * 0.0001;
        res += dij.gao(S) * 0.0001;
    }
    pt(res);
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
