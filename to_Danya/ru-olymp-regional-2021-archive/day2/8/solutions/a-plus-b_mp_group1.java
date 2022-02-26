import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Consumer;

public class APlusB1 {
  private void genPermutations(int n, ArrayList<Integer> l, boolean[] used, Consumer<List<Integer>> f) {
    if (used == null) used = new boolean[n];
    if (l == null) l = new ArrayList<>();
    if (l.size() == n) {
      f.accept(l);
    } else {
      for (int i = 0; i < n; ++i) {
        if (!used[i]) {
          used[i] = true;
          l.add(i);
          genPermutations(n, l, used, f);
          l.remove(l.size() - 1);
          used[i] = false;
        }
      }
    }
  }

  int ans = 0;

  public int solve(String a, String b, String c) {
    int n = a.length();
    genPermutations(n, null, null, (p) -> {
      StringBuilder pa = new StringBuilder();
      StringBuilder pb = new StringBuilder();
      StringBuilder pc = new StringBuilder();
      boolean fail = false;
      boolean first = true;
      for (int i : p) {
        if (first && (a.charAt(i) == '0' || b.charAt(i) == '0' || c.charAt(i) == '0')) {
          fail = true;
          break;
        }
        pa.append(a.charAt(i));
        pb.append(b.charAt(i));
        pc.append(c.charAt(i));
        first = false;
      }
      if (!fail && Integer.parseInt(pa.toString()) + Integer.parseInt(pb.toString()) == Integer.parseInt(pc.toString())) {
        ++ans;
      }
    });
    return ans;
  }

  public static void main(String[] arg) {
    Scanner scanner = new Scanner(System.in);
    String a = scanner.next();
    String b = scanner.next();
    String c = scanner.next();
    System.out.println(new APlusB1().solve(a, b, c));
  }
}
