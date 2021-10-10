import java.util.*;

public class ActivitySelection {
	public static void main(String... args) {
		int[] s = new int[]{0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; // Activity 0 is dummy
		int[] f = new int[]{0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}; // Activity 0 is dummy
		Set<Integer> set1 = recursiveActivitySelector(s, f, 0, s.length - 1);
		System.out.println("Recursive: ");
		for (Integer i: set1) System.out.print(i + " ");
		Set<Integer> set2 = greedyActivitySelector(s, f);
		System.out.println();
		System.out.println("Iterative: ");
		for (Integer i: set2) System.out.print(i + " ");
		System.out.println();
	}
	
	public static Set<Integer> recursiveActivitySelector(int[] s, int[] f, int k, int n) {
		int m = k + 1;
		while (m <= n && s[m] < f[k])
			m = m + 1;
		if (m <= n) {
			Set<Integer> set = recursiveActivitySelector(s, f, m, n);
			set.add(m);
			return set;
		}
		return new java.util.HashSet<Integer>();
	}
	
	public static Set<Integer> greedyActivitySelector(int[] s, int[] f) {
		int n = s.length - 1;
		Set<Integer> set = new HashSet<>();
		set.add(1);
		int k = 1;
		for (int m = 2; m <= n; m++) {
			if (s[m] >= f[k]) {
				set.add(m);
				k = m;
			}
		}
		return set;
	}
}
