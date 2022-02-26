#include <iostream>
#include <queue>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
string s;
vector<int> a;
vector<char> c;
 
void findmin() {
    int minlen = s.size() + 1;
    int pos = a.size() - 1;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        int len = s.size();
 
        j += a[i];
        if (a[i] == 0)j++;
 
        if (a[i] > 1) {
            len -= (ceil(log10(a[i] - 1 + 1)) - ceil(log10(a[i] + 1)));
        }
        else {
            len--;
            if (i - 1 >= 0 && i + 1 < s.size()) {
                if (c[i - 1] == c[i + 1]) {
                    len -= (ceil(log10(a[i - 1] + 1)) + ceil(log10(a[i + 1] + 1))) - ceil(log10(a[i - 1] + a[i + 1] + 1));
                }
            }
        }
        if (len < minlen) {
            minlen = len;
            pos = j;
        }
    }
    cout << 2 << " " << pos << endl;
}
 
void findmax() {
    int maxlen = 0;
    int pos = 0;
    char ch = 'A';
    int lr = 0;
    char sym[4] = { 'A','C','G','T' };
    for (int i = 0; i < a.size(); i++) {
        lr += a[i];
        if (a[i] == 0)lr++;
 
        for (int j = 0; j < 4; j++) {
            if (c[i] == sym[j])continue;
            int len = s.size();
            if (a[i] == 0) {
                if (i+1 <c.size() && c[i + 1] == sym[j])continue;
                len++;
                if (len > maxlen) {
                    maxlen = len;
                    pos = lr;
                    ch = sym[j];
                }
            }
            else {
                len = len - (ceil(log10(a[i]))) + ceil(log10(a[i] / 2 + 1)) + ceil(log10(a[i] - a[i] / 2 + 1)) + 1;
                if (len > maxlen) {
                    maxlen = len;
                    pos = lr - a[i] / 2;
                    ch = sym[j];
                }
            }
             
        }
    }
    cout << 1 << " " << pos << " " << ch << endl;
}
 
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            c.push_back(s[i]);
            a.push_back(0);
            continue;
        }
        string cnt = "";
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            cnt += s[i];
            i++;
        }
        a.push_back(stoi(cnt));
        c.push_back(s[i]);
    }
    findmin();
    findmax();
}