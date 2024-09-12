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

int check(int next, map<int, int>&mp, int k) {
	return mp[next] + 1 < k;
}
long long crazySubarrays(int n, int k, vector <int> &a) {
	long long ans = 0;
	int head = -1, tail = 0;
	map<int, int>mp;

	while (tail < n) {
		while (head + 1 < n && check(a[head + 1], mp, k)) {
			head++;
			mp[a[head]]++;
		}
		ans += (n - 1 - head);
		if (tail > head) {
			tail++;
			head = tail - 1;
		} else {
			mp[a[tail]]--;
			if (!(mp[a[tail]]))mp.erase(mp.find(a[tail]));
			tail++;
		}
	}
	return ans;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	read(a);
	cout << crazySubarrays(n, k, a) << endl;
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