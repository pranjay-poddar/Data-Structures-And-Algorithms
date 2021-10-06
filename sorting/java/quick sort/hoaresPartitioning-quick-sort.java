import java.util.*;
public class QuickSort
{
	public static int partition(int[] arr, int low, int high){
		int pivot = arr[low];
		int i = low-1, j = high+1;
		while(true){
		    do{
		       i++;
		    }while(arr[i] < pivot);
		    do{
		       j--;
		    }while(arr[j] > pivot);
		    if(i >= j){
		       return j;
		    }
		    else{
		       int temp = arr[i];
		       arr[i] = arr[j];
		       arr[j] = temp;
		    }
		}
	}
	public static void quickSort(int[] arr, int low, int high){
		if(low < high){
		    int q = partition(arr, low, high);
		    quickSort(arr, low, q);
	            quickSort(arr, q+1, high);	
		}
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		//input from user
		for(int i = 0; i < n; i++){
		    arr[i] = scanner.nextInt();
		}
		//quick sort
		quickSort(arr, 0, arr.length-1);
		//output
		for(int i = 0; i < n; i++){
		    System.out.print(arr[i]+" ");
		}
	}
}