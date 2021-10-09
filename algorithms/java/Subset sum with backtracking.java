public class SubsetSum {
	public static void main(String... args) {
		int T = 15;
		//Integer[] array = new Integer[] {11, 6, 5, 1, 7, 13, 12};
		Integer[] array = new Integer[] {8, 6, 7, 5, 3, 10, 9};
		java.util.TreeSet<Integer> X = new java.util.TreeSet<>();
		for (int x: array) {
			X.add(x);
		}
		System.out.println(subsetSum(X, T));
	}

	@SuppressWarnings("unchecked")
	public static boolean subsetSum(java.util.TreeSet<Integer> X, int T) {
		printProblem(X, T);
		if (T == 0) {
			System.out.println("Yes, there exists at least one subset!");
			return true;
		} else if (T < 0 || X.isEmpty()) {
			System.out.println("Backtracking...");
			return false;
		} else {
			Integer x = X.first();
			X.remove(x);
			return (
				subsetSum(((java.util.TreeSet<Integer>) X.clone()), T)
				||
				subsetSum(((java.util.TreeSet<Integer>) X.clone()), T - x)
			);
		}
	}
	
	public static void printProblem(java.util.TreeSet<Integer> X, int T) {
		for (Integer x: X) {
			System.out.print(x + " ");
		}
		System.out.println("-> " + T);
	}
}
