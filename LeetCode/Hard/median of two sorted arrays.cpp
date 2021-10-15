#define min(x, y) (x < y ? x : y)

int odd(int n) { return n & 0x1; }

void swap(int *x, int *y) {
    int tmp = *x; *x = *y; *y = tmp;
}

/* median of an array */
double medianof(int A[], int n) {
    return odd(n) ? (double) A[n / 2] : (double)(A[ n / 2] + A[n / 2 - 1]) / 2.0;
}

int find(int A[], int m, int B[], int n) {
    int l = 0, u = m;
    int i, j, half = (m + n + 1) / 2;
    if (!A || m == 0)
        return medianof(B, n);
    if (!B || n == 0)
        return medianof(A, m);
    while (l < u) {
        i = (l + u) / 2;
        j = half - i - 2;
        if (j < 0 || j >= n) {
            if (j == -1 && A[i] <= B[0])
                return i; /* found */
            if (j >= n )
                l = i + 1; /* too small */
            else
                u = i; /* too big */
        } else {
            if (B[j]<= A[i] && (j == n - 1 || A[i] <= B[j+1]))
                return i; /* found */
            else if (A[i] < B[j])
                l = i + 1; /* too small */
            else
                u = i; /* too big */
        }
    }
    return -1;
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int i, j, k, *C;
    if (!A || m == 0)
        return medianof(B, n);
    if (!B || n == 0)
        return medianof(A, m);
    if ((i = find(A, m, B, n)) == -1) {
        i = find(B, n, A, m);
        C = A; A = B; B = C;
        swap(&m, &n);
    }
    if (odd(m + n))
        return (double)A[i];
    j = (m + n) / 2 - i - 2;
    if (i == m - 1)
        k = B[j+1];
    else if (j == n - 1)
        k = A[i+1];
    else
        k = min(A[i+1], B[j+1]);
    return (double)(A[i] + k) / 2.0;
}