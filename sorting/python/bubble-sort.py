def sort(arr):

  for i in range(len(arr)-1):

    for j in range(len(arr)-1-i):

     if( arr[j] > arr[j+1] ):

       arr[j],arr[j+1] = arr[j+1],arr[j]

  return arr

arr = list(map(int,input("Enter Numbers: ").split()))

print(sort(arr))
