"""
This Problem was asked in Geeksforgeeks Interview Series - Paypal interview
Problem -   N frogs are positioned at one end of the pond. All frogs want to reach the other end of the pond as soon as possible.
            The pond has some leaves arranged in a straight line. Each frog has the strength to jump exactly K leaves.
            For eg, a frog having strength 2 will visit the leaves 2,4,6,8,... while crossing the pond.

            Given the strength of each frog and the number of leaves, your task is to find the number of leaves that not be visited by any of
            the frogs when all frogs have reached the other end of the pond.

Idea -
sort the array
prime sieve is used to remove touched leaves by each frog 
link to prime sieve algo - https://www.geeksforgeeks.org/sieve-of-eratosthenes/

Test Cases - 
1.  I/P - n=3, k=4, arr=[3,2,4]
    O/P - 1
2.  I/P - n=3, k=6, arr=[1,3,5]
    O/P - 0

TC - O(nlogn)
"""


def unvisitedLeaves(n, k, arr):
    arr = sorted(arr)
    vis = [1]*(k+1)
    for j in range(n):
        e = arr[j]
        if vis[e]:
            for i in range(e,k+1,e):
                vis[i] = 0
    
    c = 0
    for i in range(1,k+1):
        if vis[i]:
            c += 1
    return c


n = int(input())
k = int(input())
arr = list(map(int, input().split()))
print(unvisitedLeaves(n,k,arr))

