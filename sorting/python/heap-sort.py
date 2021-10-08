"""
Heap Sort
Algorithm:
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. 
Finally, heapify the root of the tree. 
3. Repeat step 2 while the size of the heap is greater than 1.

Example Testcase - I/P - [12, 11, 13, 5, 6, 7]
                    O/P - 5 6 7 11 12 13

Time Complexity - O(n*Logn)
"""


def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    # check if left child of root exists and is greater than root
    if l < n and arr[largest] < arr[l]:
        largest = l

    # check if right child of root exists and is greater than root
    if r < n and arr[largest] < arr[r]:
        largest = r
    
    # swap values in needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        # heapify the root
        heapify(arr, n, largest)


def heapSort(arr):
    n = len(arr)

    # building a max heap
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)

    # extract elements one by one
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


# Driver code
arr = list(map(int, input().split()))
heapSort(arr)
n = len(arr)
print("Sorted array is")
print(*arr)
