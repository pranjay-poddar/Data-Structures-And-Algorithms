def search(arr,number):

  arr.sort()

  low,high=0,len(arr)-1

  while(low<=high):

    mid=low+high//2

    if(arr[mid]==number):

      return mid

    elif(arr[mid]>number):

      high=mid-1

    else:

      low=mid+1

  else:

    return -1

  

arr = list(map(int,input("Enter Numbers: ").split()))

elem = int(input("Enter Number to be searched: "))

index=search(arr,elem)

if(index == -1):

  print("Element not found")

else:

  print("Element found")

    
