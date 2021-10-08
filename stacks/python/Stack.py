def create_stack():

  stack=[]

  return stack

def isEmpty(stack):

  return len(stack) == 0

  

def push_op(stack,elem):

  stack.append(elem)

  

def pop_op(stack):

  if(isEmpty(stack)):

    print("Stack is Empty")

  else:

    stack.pop()

def show(stack):

  if(isEmpty(stack)):

    print("Stack is Empty")

  else:

    print("Stack Contains:",stack)

stack=create_stack()

while(True):

  print("""1. Push

2. Pop

3. Show

4. Exit""")

  choice=input()

  if(choice=='1'):

    push_op(stack,int(input("Enter element to be push:")))

  elif(choice=='2'):

    pop_op(stack)

  elif(choice=='3'):

    show(stack)

  elif(choice=='4'):

    break

  else:

    print("Invalid Input")

  

