#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int LeaderSum(int n, int* array) {
    int flag=0,sum =0;
   for(int i = 0;i < n;i++){
       flag = 0;
       for(int j =i +1;j<n;j++){
           if(array[i]<array[j]){
               flag = 1;
               break;
           }
       }
       if(flag == 0){
           sum+=array[i];
       }
   }
    return sum;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *array = malloc(sizeof(int) * n);
    for (int array_i = 0; array_i < n; array_i++) {
    	scanf("%i",&array[array_i]);
    }
    int result = LeaderSum(n, array);
    printf("%d\n", result);
    return 0;
}