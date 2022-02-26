#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

vector<pair<int, char>> mas;
int sum, len;

int cnt(int x) {
	if (x == 1)
		return 0;
	int ans = 0;
	while (x) {
		x /= 10;
		ans++;
	}
	return ans;
}

//1 - add
//2 - delete
//3 - change

inline int readOperation(InStream& in) {
	int op = in.readInt(1, 3);
	int s = 0;
	
	if (op == 1) {
		int x = in.readInt(0, len);
		char c = in.readToken("[ACGT]")[0];
		for (int i = 0; i < (int)mas.size(); i++) {
			if (x == s) {
				if (mas[i].second == c) {
					return sum - cnt(mas[i].first) + cnt(mas[i].first + 1);
				} else if (i > 0 && mas[i - 1].second == c) {
					return sum - cnt(mas[i - 1].first) + cnt(mas[i - 1].first + 1);
				} else
					return sum + 1;
			} else if (x < s + mas[i].first) {
				if (c == mas[i].second)
					return sum - cnt(mas[i].first) + cnt(mas[i].first + 1);
				else
					return sum - cnt(mas[i].first) + cnt(x - s) + cnt(mas[i].first - x + s) + 2;
			}
			s += mas[i].first;
		}
		if (mas.back().second == c)
			return sum - cnt(mas.back().first) + cnt(mas.back().first + 1);
		else
			return sum + 1;
	} else if (op == 2) {
		int x = in.readInt(1, len);
		for (int i = 0; i < (int)mas.size(); i++) {
			if (x <= s + mas[i].first) {
				if (mas[i].first == 1 && i > 0 && i + 1 < (int)mas.size() && mas[i - 1].second == mas[i + 1].second)
					return sum - cnt(mas[i - 1].first) - cnt(mas[i + 1].first) + cnt(mas[i - 1].first + mas[i + 1].first) - 2;
				else if (mas[i].first == 1)
					return sum - 1;
				else
					return sum - cnt(mas[i].first) + cnt(mas[i].first - 1);
			}
			s += mas[i].first;
		}
	} else if (op == 3) {
		int x = in.readInt(1, len);
		char c = in.readToken("[ACGT]")[0];
		for (int i = 0; i < (int)mas.size(); i++) {
			if (x <= s + mas[i].first) {
				if (mas[i].second == c) {
					in.quitf(_wa, "not a mutation");
				}
				if (mas[i].first == 1) {
					int delta = -1;
					int ll = 1;
					if (i > 0 && mas[i - 1].second == c) {
						delta -= cnt(mas[i - 1].first) + 1;
						ll += mas[i - 1].first;
					}
					if (i + 1 < (int)mas.size() && mas[i + 1].second == c) {
						delta -= cnt(mas[i + 1].first) + 1;
						ll += mas[i + 1].first;
					}
					return sum + delta + cnt(ll) + 1;
				} else {
					if (x == s + 1) {
						if (i > 0 && mas[i - 1].second == c)
							return sum - cnt(mas[i].first) + cnt(mas[i].first - 1) - cnt(mas[i - 1].first) + cnt(mas[i - 1].first + 1);
						else
							return sum - cnt(mas[i].first) + cnt(mas[i].first - 1) + 1;
					} else if (x == s + mas[i].first) {
						if (i + 1 < (int)mas.size() && mas[i + 1].second == c)
							return sum - cnt(mas[i].first) + cnt(mas[i].first - 1) - cnt(mas[i + 1].first) + cnt(mas[i + 1].first + 1);
						else
							return sum - cnt(mas[i].first) + cnt(mas[i].first - 1) + 1;
					} else {
						return sum - cnt(mas[i].first) + cnt(x - s - 1) + cnt(mas[i].first + s - x) + 2;
					}
				}
			}
			s += mas[i].first;
		}
	}
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    string s = inf.readToken();
	sum = 0;
	len = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int x = 0;
			while ('0' <= s[i] && s[i] <= '9') {
				x = 10 * x + s[i] - '0';
				i++;
			}
			mas.push_back({x, s[i]});
			sum += cnt(x) + 1;
		} else {
			mas.push_back({1, s[i]});
			sum++;
		}
		len += mas.back().first;
	}
	pair<int, int> ja = {readOperation(ans), readOperation(ans)};
	pair<int, int> pa = {readOperation(ouf), readOperation(ouf)};
	if (pa.first < ja.first) {
		quitf(_fail, "minimum length, pans = %d, jans = %d", pa.first, ja.first);
	} else if (pa.second > ja.second) {
		quitf(_fail, "maximum length, pans = %d, jans = %d", pa.second, ja.second);
	}
	else if (pa.first > ja.first) {
		quitf(_wa, "minimum length, pans = %d, jans = %d", pa.first, ja.first);
	} else if (pa.second < ja.second) {
		quitf(_wa, "maximum length, pans = %d, jans = %d", pa.second, ja.second);
	} else {
		quitf(_ok, "good, mimimum length = %d, maximum length = %d", pa.first, pa.second);
	}
}