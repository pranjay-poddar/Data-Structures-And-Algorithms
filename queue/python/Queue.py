class Queue:

    def __init__(self):

        self.queue = []

    def insert(self, elem):

        self.queue.append(elem)

    def remove(self):

        if len(self.queue) == 0:

            print("Queue is Empty")

        else:

            self.queue.pop(0)

    def show(self):

        if len(self.queue) == 0:

            print("Queue is Empty")

        else:

            print("Queue Contains:",self.queue)

queue=Queue()

while(True):

  print("""1. Insert

2. Remove

3. Show

4. Exit""")

  choice=input()

  if(choice=='1'):

    queue.insert(int(input("Enter element to be insert:")))

  elif(choice=='2'):

    queue.remove()

  elif(choice=='3'):

    queue.show()

  elif(choice=='4'):

    break

  else:

    print("Invalid Input")

  

