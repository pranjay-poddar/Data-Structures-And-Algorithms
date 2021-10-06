import java.util.*;
public class BubbleSort
{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		//input from user
		for(int i = 0; i < n; i++){
		    arr[i] = scanner.nextInt();
		}
		//bubble algorithm
		for(int i = 0; i < n; i++){
		    for(int j = 0; j < n-i-1; j++){
		        if(arr[j] > arr[j+1]){
		            int temp = arr[j];
		            arr[j] = arr[j+1];
		            arr[j+1] = temp;
		        }
		    }
		}
		//output
		for(int i = 0; i < n; i++){
		    System.out.print(arr[i]+" ");
		}
	}
}
