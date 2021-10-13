package Matrix;

import java.util.Arrays;
import java.util.Scanner;

public class SortMatrixRowColWise {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int[][] arr = new int[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				arr[i][j] = s.nextInt();
			}
		}
		sortMatrix(arr,n,m);
	}

	private static void sortMatrix(int[][] arr, int n, int m) {
		// TODO Auto-generated method stub
		int[] arr1 = new int[n*m];
		int index = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				arr1[index++] = arr[i][j];
			}
		}
		Arrays.sort(arr1);
		int k=0;
		for(int r=0; r<n; r++) {
			for(int c=0; c<m; c++) {
				arr[r][c] = arr1[k];
				k++;
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println("");
		}
	}

}
