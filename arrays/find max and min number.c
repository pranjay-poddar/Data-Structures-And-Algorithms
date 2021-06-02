#include <stdio.h>
struct p{
    int max;
    int min;
};
struct p compare(int a[],int n){
    struct p comp;
    if(n == 1){
        comp.max=a[0];
        comp.min=a[0];
        return comp;
    }
    if(n > 1){
        if(a[1]>a[0]){
            comp.max=a[1];
            comp.min=a[0];
        }
        else{
            comp.max=a[0];
            comp.min=a[1];
        }
        for(int i = 2;i < n;i++){
            if(a[i]>comp.max){
                comp.max=a[i];
            }
            if(a[i]<comp.min){
                comp.min=a[i];
            }
        }
    }
    return comp;
}
int main() {
	int i,j,n;
	struct p c;
	scanf("%d",&n);
	int a[n];
	for(i = 0;i < n;i++){
	    scanf("%d",&a[i]);
	}
	c = compare(a,n);
	printf("Maximum Number:%d\n",c.max);
	printf("Minimum Number:%d\n",c.min);
	
	return 0;
}