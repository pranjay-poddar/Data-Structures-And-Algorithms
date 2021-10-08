import java.lang.*;

public class InsertionSort {

    public static void main(String[] args) {
        
        int[] arr={10,-6,-9,110,68,-101,10,1};

        for(int firstUnsortedIndex=1;firstUnsortedIndex<arr.length;firstUnsortedIndex++){

            int newElement=arr[firstUnsortedIndex];
            int i;

            for(i=firstUnsortedIndex;i>0&&arr[i-1]>newElement;i--){

                arr[i]=arr[i-1];
            }

            arr[i]=newElement;

        }

        for (int j : arr)
            System.out.println(j);
    }

}