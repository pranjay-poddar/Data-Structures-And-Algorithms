package Matrix;

import java.util.Scanner;

public class SearchInMatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = s.nextInt();
			}
		}
		int target = s.nextInt();
		System.out.println(searchMatrix(arr, target));
		s.close();
	}

	private static boolean searchMatrix(int[][] arr, int target) {
		int n = arr.length;
		int m = arr[0].length;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < m; j++) {
				if (arr[i][j] == target) {
					return true;
				}
			}
		}
		return false;
	}

}
