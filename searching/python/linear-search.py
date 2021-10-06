def search(arr,elem):
  for i in arr:
    if i==elem:
      print("Element found at index:",arr.index(elem))
  else:
    print("Element not found")


arr = list(map(int,input("Enter Numbers: ").split()))
elem = int(input("Enter Number to be searched: "))
search(arr,elem)
  
