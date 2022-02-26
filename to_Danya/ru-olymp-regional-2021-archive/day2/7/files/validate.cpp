#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(2, 10, "n");
  inf.readSpace();
  int m = inf.readInt(2, 10, "m");
  inf.readSpace();
  int c = inf.readInt(2, 3, "c");
	inf.readEoln();
	inf.readEof();

	return 0;
}
