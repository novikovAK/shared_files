#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int GROUP_COUNT = 9;
const int MAX_N = 200000;

struct Group {
  int n;
  bool zeros;
};

const Group GROUPS[] = {
  { MAX_N, true },   // Samples
  { 6,     true },   // Group 1
  { 18,    true },   // Group 2
  { 200,   false },  // Group 3
  { 200,   true },   // Group 4
  { 750,   false },  // Group 5
  { 750,   true },   // Group 6
  { MAX_N, false },  // Group 7
  { MAX_N, true },   // Group 8
};

int group;

string readStr(string const& name) {
  string s = inf.readToken(GROUPS[group].zeros ? "[0-9]+" : "[1-9]+", name);
  inf.readEoln();
  return s;
}

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  group = stoi(validator.group());
  ensuref(group >= 0 && group < GROUP_COUNT, "Group id is incorrect");

  string a = readStr("a");
  string b = readStr("b");
  string c = readStr("c");

  ensuref(a.size() == b.size() && a.size() == c.size(), "a, b and c must be of equal length");
  ensuref(2 <= a.size() && (int)a.size() <= GROUPS[group].n, "length must be between 2 and %d", GROUPS[group].n);

  inf.readEof();
  return 0;
}
