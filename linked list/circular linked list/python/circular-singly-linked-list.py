class Node:  
    
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
   
    def __init__(self):
      self.first = self.last = self.current = self.follow = self.ahead = self.new = None

    def insert(self,data):
       new = Node(data)
       if not self.first:
         self.first = self.last = new
         new.next = new
       else:
         self.last.next = new
         new.next = self.first
         self.last = new
    
    def insertBefore(self):
      if self.first == None:
        print("Linked List is Empty")
      else:
        flagloop, flagelem = True, False
        data = int(input("Enter element to be insert:"))
        elem = int(input("Enter number before which insertion should be done:"))
        new = Node(data)
        self.current = self.first
        self.follow = None
        while(self.current != self.first or flagloop):
          if(self.current.data != elem):
            pass
          else:
            flagelem = True
            break
          self.follow = self.current
          self.current = self.current.next 
          flagloop = False  
        if not flagelem:
          print("Element Not Found")
        else:
          if self.first.data == elem:
            new.next = self.current
            self.first = new
            self.last.next = new
          else:
            self.follow.next = new
            new.next = self.current
    
    def insertAfter(self):
      if self.first == None:
        print("Linked List is Empty")
      else:
        flagloop, flagelem = True, False
        data = int(input("Enter element to be insert:"))
        elem = int(input("Enter number after which insertion should be done:"))
        new = Node(data)
        self.current = self.first
        while(self.current != self.first or flagloop):
          if(self.current.data != elem):
            pass
          else:
            flagelem = True
            break
          self.current = self.current.next 
          flagloop = False  
        if not flagelem:
          print("Element Not Found")
        else:
          self.ahead = self.current.next
          if self.current == self.last:
            self.last.next = new
            new.next = self.first
            self.last = new
          else:
            self.current.next = new
            new.next = self.ahead
    
    def delete(self):
       if self.first == None:
         print("Linked List is Empty")
       else:
         flagloop, flagelem = True, False
         elem = int(input("Enter element to be delete:"))
         self.current = self.first
         self.follow = None
         while(self.current != self.first or flagloop):
          if(self.current.data != elem):
            pass
          else:
            flagelem = True
            break
          self.follow = self.current
          self.current = self.current.next 
          flagloop = False  
       if not flagelem:
          print("Element Not Found")
       else:
           self.ahead = self.current.next
           if self.current == self.first and self.current == self.last:
             self.first = None
           elif(self.current == self.first):
             self.first = self.first.next
             self.last.next = self.first
           elif(self.current == self.last):
             self.last = self.follow
             self.last.next = self.first
           else:
             self.follow.next = self.ahead
   
    def show(self):
        if self.first == None:
          print("Linked List is Empty")
        else:
          print("Linked list Contains:")
          flag = True
          self.current = self.first
          while(self.current != self.first or flag):
            print(self.current.data,end=" ")
            self.current = self.current.next
            flag = False
          print()
          
    def search(self):
      if self.first == None:
          print("Linked List is Empty")
      else:
        self.current = self.first
        elem = int(input("Enter element to be search:"))
        flagloop, flagelem = True, False
        while(self.current != self.first or flagloop):
          if(self.current.data != elem):
            pass
          else:
            flagelem = True
          self.current = self.current.next
          flagloop = False
        if flagelem:
          print("Element Found")
        else:
          print("Element not Found")
          
#Initialise Linked list        
linklist = LinkedList()
while(True):
  print("""1. Insert
2. InsertBefore
3. InsertAfter
4. Delete
5. Show
6. Search
7. Exit""")
  choice=input()
  if(choice=='1'):
    linklist.insert(int(input("Enter element to be insert:")))
  elif(choice=='2'):
    linklist.insertBefore()
  elif(choice=='3'):
    linklist.insertAfter()
  elif(choice=='4'):
    linklist.delete()
  elif(choice=='5'):
    linklist.show()
  elif(choice=='6'):
    linklist.search()
  elif(choice=='7'):
    break
  else:
    print("Invalid Input")

         
        
