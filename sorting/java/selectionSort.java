import java.util.*;
public class SelectionSort
{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		//input from user
		for(int i = 0; i < n; i++){
		    arr[i] = scanner.nextInt();
		}
		//selection algorithm
		for(int i = 1; i < n; i++){
		    int j = i-1;
		    int temp = arr[i];
		    while(j >= 0 && arr[j] > temp){
		        arr[j+1] = arr[j];
		        j--;
		    }
		    arr[j+1] = temp;
		}
		//output
		for(int i = 0; i < n; i++){
		    System.out.print(arr[i]+" ");
		}
	}
}
