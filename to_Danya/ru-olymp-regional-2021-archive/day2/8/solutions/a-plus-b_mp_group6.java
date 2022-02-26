import java.util.Scanner;

public class APlusB6 {
  private static final int MOD = 1000000007;

  private int solve(int na, int nb, int nc, int nd, int naz, int nbz) {
    if (nb != nc) return 0;
    class State {
      int ac = 0, bd = 0;

      void addAC(int x) {
        ac += x;
        if (ac >= MOD) ac -= MOD;
      }
      void addBD(int x) {
        bd += x;
        if (bd >= MOD) bd -= MOD;
      }
    }
    State[][][][] dp = new State[2][nc+1][2][nd+1];
    for (State[][][] dp1 : dp)
      for (State[][] dp2 : dp1)
        for (State[] dp3 : dp2)
          for (int i = 0; i < dp3.length; ++i)
            dp3[i] = new State();
    if (na > 0) dp[1][0][0][0].ac = (int)((long)(na - naz) * (nb > 0 ? nb : 1) % MOD);
    if (nb > 0) dp[0][0][1][0].bd = (int)((long)(nb - nbz) * (na > 0 ? na : 1) % MOD);

    for (int a = 0; a <= na; ++a)
      for (int c = 0; c <= nc; ++c)
        for (int cb = 0; cb <= 1 && c + cb <= nb; ++cb)
          for (int d = 0; d <= nd; ++d) {
            int b = c + cb;
            State cd = dp[a&1][c][cb][d];
            if (b != nb && cb == 0) {
              dp[a&1][c][1][d].addBD(cd.ac);
            }
            if (c != nc && cb == 1) {
              dp[a&1][c+1][0][d].addAC(cd.bd);
            }
            if (d != nd) {
              dp[a&1][c][cb][d+1].addBD(cd.bd);
            }
            if (a != na) {
              dp[(a&1)^1][c][cb][d].addAC(cd.ac);
              cd.ac = cd.bd = 0;
            }
          }

    int ans = dp[na&1][nc][0][nd].ac;
    for (int i = 1; i < na; ++i) ans = (int)((long)ans * i % MOD);
    for (int i = 1; i < nb; ++i) ans = (int)((long)ans * i % MOD);
    for (int i = 1; i <= nc; ++i) ans = (int)((long)ans * i % MOD);
    for (int i = 1; i <= nd; ++i) ans = (int)((long)ans * i % MOD);
    return ans;
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
    System.out.println(new APlusB6().solve(a, b, c));
  }
}
