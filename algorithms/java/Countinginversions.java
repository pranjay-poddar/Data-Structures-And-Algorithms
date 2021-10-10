public class CountingInversion {
	public static void main(String... args) {
		int [] a = {6, 3, 4, 5, 2, 1};
		Solution s = mergeSortCount(a, 0, a.length);
		for (int x: s.a) {
			System.out.print(x + " ");
		}
		System.out.println("\nCount (Divide and Conquer): " + s.count);
		System.out.println("Count (Bruteforce): " + countingInversions(a));
	}
	
	public static int countingInversions(int [] a) {
		int count = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[i] > a[j]) count ++;
			}
		}
		return count;
	}
	
	public static Solution mergeSortCount(int [] a, int left, int right) {
		if (right - left == 1) {
			Solution s = new Solution(1);
			s.a[0] = a[left];
			return s;
		}
		int mid = (left + right) / 2;
		Solution l = mergeSortCount(a, left, mid);
		Solution r = mergeSortCount(a, mid, right);
		Solution m = mergeCount(l, r);
		m.count += l.count + r.count;
		return m;
	}
	
	public static Solution mergeCount(Solution l, Solution r) {
		int i = 0, j = 0, k = 0;
		Solution s = new Solution(l.a.length + r.a.length);
		while (k < l.a.length + r.a.length) {
			if (j == r.a.length || (i < l.a.length && l.a[i] <= r.a[j])) {
				s.a[k] = l.a[i]; 
				k++;
				i++;
 			} else { // if (i == l.a.length || l.a[i] > r.a[j])
				s.a[k] = r.a[j];
				k++;
				j++;
				s.count = s.count + (l.a.length - i);
			}
		}
		return s;
	}		
}

class Solution {
	public int [] a = null;
	public int count = 0;
	public Solution(int size) {
		this.a = new int[size];
		this.count = 0;
	}
}
