package Matrix;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class spiralTraverse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int R = s.nextInt();
		int C = s.nextInt();
		int[][] arr = new int[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] = s.nextInt();
			}
		}
		System.out.println(TraverseSpiral(arr));
		s.close();
	}

	private static ArrayList<Integer> TraverseSpiral(int[][] arr) {
		// TODO Auto-generated method stub
		ArrayList<Integer> stack = new ArrayList<>();
		if (arr.length == 0) {
			return stack;
		}
		int R = arr.length;
		int C = arr[0].length;
		boolean[][] chk = new boolean[R][C];
		int[] dr = { 0, 1, 0, -1 };
		int[] dc = { 1, 0, -1, 0 };
		int r = 0, c = 0, di = 0;
		for (int i = 0; i < R * C; i++) {
            stack.add(arr[r][c]);
            chk[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];

            if (0 <= cr && cr < R && 0 <= cc && cc < C && !chk[cr][cc]) {
                r = cr;
                c = cc;
            }
            else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }

		return stack;
	}

}
