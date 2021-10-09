#include <iostream>
using namespace std;

int main() {
	int t1, t2, t3;
	cin >> t1 >> t2 >> t3;
	int heights1[t1], heights2[t2], heights3[t3], sum_1 = 0, sum_2 = 0, sum_3 = 0;
	
	for (int a = 0; a < t1; a++) {
		cin >> heights1[a];
		sum_1 += heights1[a];
	}
	for (int a= 0; a < t2; a++) {
		cin >> heights2[a];
		sum_2 += heights2[a];
	}
	for (int a = 0; a < t3; a++) {
		cin >> heights3[a];
		sum_3 += heights3[a];
	}
	
	int a = 0, b = 0, c = 0;
	while (! (sum_1 == sum_2 and sum_2 == sum_3)) {
		if (sum_1 >= sum_2 and sum_1 >= sum_3) {
			sum_1 -= heights1[a];
			a++;
			continue;
		}
		if (sum_2 >= sum_3 and sum_2 >= sum_1) {
			sum_2 -= heights2[b];
			b++;
			continue;
		}
		if (sum_3 >= sum_1 and sum_3 >= sum_2) {
			sum_3 -= heights3[c];
			c++;
			continue;
		}
	}
	
	cout << sum_1;
} 

/*input:
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
*/