// Generator created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "testlib.h"
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;


int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = opt<int>("n");
	int maxs = 1000000000;
	if (__testlib_opts.count("maxs")) {
		maxs = opt<int>("maxs");
	}

	vector<pii> arr(n);
	arr[0] = {rnd.next(0, maxs), 0};
	int q = rnd.next(0, maxs);
	arr[n - 1] = {q, q};

	shuffle(arr.begin(), arr.end());

	cout << n << "\n";

	for (int i = 0; i < n; ++i) {
		cout << "1 " << arr[i].ff << "\n";
		cout << arr[i].ss << "\n";
	}

	return 0;
}