import java.util.Scanner;

public class APlusB2 {
  private static final int MOD = 1000000007;

  public int solve(String a, String b, String c) {
    int n = a.length();
    boolean[] createCarry = new boolean[n];
    boolean[] needCarry = new boolean[n];
    for (int i = 0; i < n; ++i) {
      int x = a.charAt(i) - '0';
      int y = b.charAt(i) - '0';
      int z = c.charAt(i) - '0';
      needCarry[i] = (x + y) % 10 != z;
      createCarry[i] = x + y + (needCarry[i] ? 1 : 0) >= 10;
      if (x + y + (needCarry[i] ? 1 : 0) - (createCarry[i] ? 10 : 0) != z) {
        return 0;
      }
    }

    int[][] d = new int[n][1 << n];

    for (int mask = 1; mask < 1 << n; ++mask)
      for (int v = 0; v < n; ++v)
        if ((mask & (1 << v)) != 0) {
          int pmask = mask ^ (1 << v);
          if (pmask == 0)
            d[v][mask] = a.charAt(v) != '0' && b.charAt(v) != '0' && c.charAt(v) != '0' && !createCarry[v] ? 1 : 0;
          else
            for (int pv = 0; pv < n; ++pv)
              if ((pmask & (1 << pv)) != 0)
                if (createCarry[v] == needCarry[pv])
                  d[v][mask] = (d[v][mask] + d[pv][pmask]) % MOD;
        }

    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (!needCarry[i])
        ans = (ans + d[i][(1 << n) - 1]) % MOD;
    return ans;
  }

  public static void main(String[] arg) {
    Scanner scanner = new Scanner(System.in);
    String a = scanner.next();
    String b = scanner.next();
    String c = scanner.next();
    System.out.println(new APlusB2().solve(a, b, c));
  }
}
