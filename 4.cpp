#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
long double PI = acos(-1.0);
#define fastio()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define pb push_back
#define NL cout<<endl;
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define ff(i, l, r) for(int i=l;i<r;i++)
#define fr first
#define sc second
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define YES \
	yes();          \
	return
#define NO\
	no();          \
	return
const int MOD = (1e9 + 7);
/*
https://visualgo.net/en/
pythontutor.com- for codestack visualisation(Recursive stack)
1sec -10^7-10^8 OPS APPROX
INT_MAX=2^31-1 && INT_MIN=-2^31
int- (2*(-10^-9) to 2*(10^9))RANGE
long (2*(-10^12) to 2*(10^12))RANGE
long long(-10^18 to 10^18)RANGE
(a+b)%M=((a%M)+(b%M))%M
(a*b)%M=((a%M)*(b%M))%M
(a-b)%M=((a%M)-(b%M)+M)%M
(a/b)%M=((a%M)*(b^-1)%M)%M
lower_bound:-LOGN
interator
--FIRST ELEMENT IN AR >=x
--NO OF ELEMENTS<x
upper_bound:-
iterator
--FIRST ELEMENT IN AR>x
--NO OF ELEMENTS<=x
*/
#ifdef ANURAG
#define debug(x)        \
	cerr << #x << ": "; \
	_print(x);          \
	cerr << endl;
#else
#define debug(x) ;
#endif

void _print(int t) {
	cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
	cerr << "{";
	_print(p.ff);
	cerr << ",";
	_print(p.ss);
	cerr << "}";
}
template <class T>
void _print(vector<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
	cerr << "[ ";
	for (auto i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void read(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
}

void read2dn(vii &a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cin >> a[i][j];
		}
	}
}
void read2dcustom(vii &a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}

void print(vector<int> a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int binpow(int a, int b, int m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
int binpow1(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b % 2) {
		return a * binpow1(a, b - 1) % MOD;
	}
	int ans = binpow1(a, b / 2);
	return (ans * ans) % MOD;
}
int fact[100004];
void precompute() {
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}
}
int ncrpc(int n, int r) {
	if (r < 0 || r > n) {
		return 0;
	}
	int d = (fact[r] * fact[n - r]) % MOD;
	return fact[n] * binpow1(d, MOD - 2) % MOD;
}
int NCR(int n, int r) {
	if (r < 0 || r > n) {
		return 0;
	}
	n %= MOD;
	r %= MOD;
	int ans = 1;
	for (int i = 0; i < r; i++) {
		ans = (ans % MOD * (((n % MOD) - (i % MOD)) % MOD) % MOD) % MOD;
		int m = binpow(i  + 1, MOD - 2, MOD);
		ans = (ans * m) % MOD;
	}
	return (ans % MOD + MOD) % MOD;
}
void pfsi(vector<int>&v) {
	int n = v.size();
	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
	}
}
struct node {
	long long T, maxe, mine, len;
	node() {
		T = maxe = mine = len = 0;
	}
};
node t[4 * 100100];
vector<int>a;
int n, k;
node merge(node a, node b) {
	node ans;
	ans.T = a.T + b.T;
	ans.len = a.len + b.len;
	ans.maxe = max(a.maxe, b.maxe);
	ans.mine = min(a.mine, b.mine);
	if (abs(ans.maxe - ans.mine) <= k) {
		int j = ans.len;
		ans.T = j * (j + 1) / 2;
	}
	return ans;
}

void build(int id, int l, int r) {
	if (l == r) {
		t[id].len = t[id].T = 1;
		t[id].maxe = t[id].mine = a[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	t[id] = merge(t[id * 2], t[id * 2 + 1]);
}
node query(int id, int l, int r, int lq, int rq) {
	if (lq > r || rq < l)return node();
	if (lq <= l && r <= rq)return t[id];
	int mid = l + (r - l) / 2;
	return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
vector <long long> kTwistSubarrays(int n1, int k1, int q, vector <int> &a1, vector <vector<int>> &que) {
	a = a1, n = n1, k = k1;
	build(1, 0, n - 1);
	vector<long long>ans;
	for (int i = 0; i < q; i++) {
		int lq = que[i][0], rq = que[i][1];
		ans.push_back(query(1, 0, n - 1, lq, rq).T);
	}
	return ans;
}
void solve() {

}


signed main() {
	fastio();

#ifdef Anurag5623
	freopen("Error.txt", "w", stderr);
#endif
	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}
}