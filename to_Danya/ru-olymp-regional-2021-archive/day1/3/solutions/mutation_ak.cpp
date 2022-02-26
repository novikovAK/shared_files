/// Created by Arsenii Kirillov
 
#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#ifndef LOCAL
#  define cerr __get_ce
#endif
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
 
/*
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
//*/
 
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }
 
 
void solve() {
	string s;
	cin >> s;
	vector<pair<int, char>> mas;
	int sum = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int x = 0;
			while ('0' <= s[i] && s[i] <= '9') {
				x = 10 * x + s[i] - '0';
				i++;
			}
			mas.push_back({x, s[i]});
		} else {
			mas.push_back({1, s[i]});
		}
		sum += mas.back().first;
	}
	int opt = 1, delta = 0;
	set<int> mem;
	mem.insert(2);
	mem.insert(1);
	int x = 1;
	while (10ll * x <= sum) {
		x *= 10;
		mem.insert(x);
	}
	auto cnt = [&](int x) {
		if (x == 1)
			return 0;
		int ans = 0;
		while (x) {
			ans++;
			x /= 10;
		}
		return ans;
	};
	sum = 0;
	for (int i = 0; i < (int)mas.size(); i++) {
		auto p = mas[i];
		if (mem.count(p.first) && delta == 0) {
			opt = sum + 1;
			delta = 1;
		}
		if (i > 0 && i + 1 < (int)mas.size() && p.first == 1 && mas[i - 1].second == mas[i + 1].second) {
			int nw_delta = (cnt(mas[i - 1].first) + cnt(mas[i + 1].first) + 3) - (cnt(mas[i - 1].first + mas[i + 1].first) + 1);
			if (nw_delta > delta) {
				opt = sum + 1;
				delta = nw_delta;
			}
		}
		sum += p.first;
	}
	//1 - add
	//2 - delete
	//3 - change
	cout << "2 " << opt << "\n";
	opt = 0, delta = 1;
	sum = 0;
	char c = s[0];
	for (int i = 0; i < (int)mas.size(); i++) {
		auto p = mas[i];
		//cout << sum << " " << p.first << " " << p.second << "  " << opt << " " << delta << endl;
		if (p.first < 10) {
			if (p.first >= 4) {
				if (delta < 3) {
					opt = sum + 2;
					delta = 3;
					c = p.second;
				}
			} else if (p.first == 3) {
				if (delta < 2) {
					opt = sum + 2;
					delta = 2;
					c = p.second;
				}
			}
		} else if (p.first == 11) {
			if (delta < 3) {
				opt = sum + 2;
				delta = 3;
				c = p.second;
			}
		} else {
			auto q = mem.upper_bound(p.first);
			q--;
			int x = (*q);
			if (p.first >= 2 * x) {
				int nw_delta = cnt(x) + 2;
				if (delta < nw_delta) {
					opt = sum + x;
					delta = nw_delta;
					c = p.second;
				}
			} else if (p.first >= x + (x / 10)) {
				int nw_delta = cnt(x / 10) + 2;
				if (delta < nw_delta) {
					opt = sum + x;
					delta = nw_delta;
					c = p.second;
				}
			} else {
				int nw_delta = cnt(x / 10 * 2) + 1;
				if (delta < nw_delta) {
					opt = sum + 8 * (x / 10);
					delta = nw_delta;
					c = p.second;
				}
			}
		}
		sum += p.first;
	}
	if (c == 'A' || c == 'G' || c == 'T')
		c = 'C';
	else
		c = 'A';
	cout << "1 " << opt << " " << c << endl;
}
 
 
int main() {
#ifdef LOCAL
	clock_t start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int test_count = 1;
	//cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
 
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}