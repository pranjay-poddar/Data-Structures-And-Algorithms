public class MatrixChain {
	public static void main(String... args) {
		int [] p = new int[]{30, 35, 15, 5, 10, 20, 25};
		int n = p.length - 1;
		int [][][] ms = matrixChainOrder(p);
		printOptimalParenthesis(ms[1], 1, n);
		System.out.println("\nNumber of Scalar Multiplications: " + ms[0][1][n]);
		System.out.println("Number of Scalar Multiplications: " + recursiveMatrixChain(p, 1, n));
		System.out.println("Number of Scalar Multiplications: " + memoizedMatrixChain(p));
	}
	
	public static void printOptimalParenthesis(int [][] s, int i, int j) {
		if (i == j) {
			System.out.print("A" + i);
			return;
		}
		System.out.print("(");
		printOptimalParenthesis(s, i, s[i][j]);
		printOptimalParenthesis(s, s[i][j] + 1, j);
		System.out.print(")");
	}
	
	public static int [][][] matrixChainOrder(int [] p) { // Question 5
		final int n = p.length - 1;
		int [][] m = new int[n + 1][n + 1];
		int [][] s = new int[n][n + 1];
		//for (int i = 1; i <= n; i++) 
			//m[i][i] = 0;
		for (int l = 2; l <= n; l++) {
			for (int i = 1; i <= n - l + 1; i++) {
				int j = i + l - 1;
				m[i][j] = Integer.MAX_VALUE;
				for (int k = i; k <= j - 1; k++) {
					int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
					if (q < m[i][j]) {
						m[i][j] = q;
						s[i][j] = k;
					}
				}
			}
		}
		int [][][] ms = new int[][][]{m, s};
		return ms;
	}
	
	public static int recursiveMatrixChain(int [] p, int i, int j) {
		if (i == j) return 0;
		int [][] m = new int[j][j + 1];
		m[i][j] = Integer.MAX_VALUE;
		for (int k = i; k <= j - 1; k++) {
			int q = recursiveMatrixChain(p, i, k)
				+ recursiveMatrixChain(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];
			if (q < m[i][j])
				m[i][j] = q;
		}
		return m[i][j];
	}
	
	public static int memoizedMatrixChain(int [] p) { // Question 8 (part 1)
		int n = p.length - 1;
		int m[][] = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				m[i][j] = Integer.MAX_VALUE;
			}
		}
		return lookupChain(m, p, 1, n);
	}
	
	public static int lookupChain(int [][] m, int [] p, int i, int j) { // Question 8 (part 2)
		if (m[i][j] < Integer.MAX_VALUE) return m[i][j];
		if (i == j) m[i][j] = 0;
		else {
			for (int k = i; k <= j - 1; k++) {
				int q = lookupChain(m, p, i, k)
					+ lookupChain(m, p, k + 1, j)
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				m[i][j] = q;
			}
		}
		return m[i][j];
	}
}
