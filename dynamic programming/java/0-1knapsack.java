import java.util.*;
public class ClassicalKnapsack
{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] weight = new int[n];
		int[] value = new int[n];
		System.out.println("Enter the weight:-");
		for(int i = 0; i < n; i++){
		    weight[i] = scanner.nextInt();
		}
		System.out.println("Enter the value:-");
		for(int i = 0; i < n; i++){
		    value[i] = scanner.nextInt();
		}
		System.out.println("Enter the required capacity:-");
		int w = scanner.nextInt();
		int[][] dp = new int[n+1][w+1];
		for(int i = 0; i <= n; i++){
		    for(int j = 0; j <= w; j++){
		        if(i == 0 || j == 0){
		            dp[i][j] = 0;
		        }
		        else if(weight[i-1] <= j){
		            dp[i][j] = Math.max(value[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
		        }
		        else{
		            dp[i][j] = dp[i-1][j];
		        }
		    }
		}
		//print the output
		System.out.println(dp[n][w]);
	}
}
