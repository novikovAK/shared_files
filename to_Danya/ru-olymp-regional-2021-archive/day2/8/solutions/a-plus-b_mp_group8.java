import java.util.Scanner;

public class APlusB8 {
  private static final int MOD = 1000000007;

  private static long inv(long a) {
    long r = 1;
    for (int b = MOD - 2; b > 0; b >>= 1, a = (a * a % MOD)) {
      if ((b & 1) != 0) r = (r * a % MOD);
    }
    return r;
  }

  private int solve(int a, int b, int c, int d, int az, int bz) {
    int n = a + b + c + d;
    long[] fact = new long[n+3];
    fact[0] = 1;
    for (int i = 1; i <= n + 2; ++i)
      fact[i] = (i * fact[i - 1] % MOD);
    long[] ofact = new long[n+3];
    ofact[n + 2] = inv(fact[n + 2]);
    for (int i = n + 2; i >= 1; --i)
      ofact[i - 1] = (ofact[i] * i % MOD);

    if (b != c) return 0;
    if (b == 0) {
      if (d == 0) return (int)(fact[a - 1] * (a - az) % MOD);
      return 0;
    }

    long ansAB = 1;
    ansAB = ansAB * fact[c] % MOD;
    ansAB = ansAB * fact[a + b] % MOD;
    ansAB = ansAB * fact[d + b - 1] % MOD;
    ansAB = ansAB * ofact[b - 1] % MOD;

    long ansB = 1;
    ansB = ansB * fact[b] % MOD;
    ansB = ansB * fact[c] % MOD;
    ansB = ansB * fact[a + b - 1] % MOD;
    ansB = ansB * fact[d + b - 1] % MOD;
    ansB = ansB * ofact[b - 1] % MOD;
    ansB = ansB * ofact[b - 1] % MOD;

    long ansA = (ansAB - ansB + MOD) % MOD;

    if (a > 0) {
      ansA = ansA * inv(a) % MOD;
      ansA = ansA * (a - az) % MOD;
    }
    ansB = ansB * inv(b) % MOD;
    ansB = ansB * (b - bz) % MOD;

    return (int)((ansA + ansB) % MOD);
  }

  public int solve(String a, String b, String c) {
    int n = a.length();
    int na = 0, nb = 0, nc = 0, nd = 0, naz = 0, nbz = 0;
    for (int i = 0; i < n; ++i) {
      int x = a.charAt(i) - '0';
      int y = b.charAt(i) - '0';
      int z = c.charAt(i) - '0';
      boolean needCarry = (x + y) % 10 != z;
      boolean createCarry = x + y + (needCarry ? 1 : 0) >= 10;
      if (x + y + (needCarry ? 1 : 0) - (createCarry ? 10 : 0) != z) {
        return 0;
      }
      if (!needCarry && !createCarry) {
        ++na;
        if (x == 0 || y == 0 || z == 0) ++naz;
      } else if (needCarry && !createCarry) {
        ++nb;
        if (x == 0 || y == 0 || z == 0) ++nbz;
      } else if (!needCarry) {
        ++nc;
      } else {
        ++nd;
      }
    }

    return solve(na, nb, nc, nd, naz, nbz);
  }

  public static void main(String[] arg) {
    Scanner scanner = new Scanner(System.in);
    String a = scanner.next();
    String b = scanner.next();
    String c = scanner.next();
    System.out.println(new APlusB8().solve(a, b, c));
  }
}
