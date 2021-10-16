class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def Left_index(points):
   
    minn = 0
    for i in range(1, len(points)):
        if points[i].x < points[minn].x:
            minn = i
        elif points[i].x == points[minn].x:
            if points[i].y > points[minn].y:
                minn = i
    return minn


def orient(p, q, r):

  
    val = (q.y - p.y) * (r.x - q.x) - \
          (q.x - p.x) * (r.y - q.y)

    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def convexHull(points, n):
    # There must be at least 3 points
    if n < 3:
        return

    # Find the leftmost point
    l = Left_index(points)

    hull = []

 
    p = l
    q = 0
    while (True):

        # Add current point to result
        hull.append(p)
        q = (p + 1) % n

        for i in range(n):

            if (orient(points[p],
                            points[i], points[q]) == 2):
                q = i

      
        p = q

  
        if (p == l):
            break

    # Print Result
    yy=[]
    for each in hull:
        xx=[]
        pin1,pin2 =(points[each].x, points[each].y)
        xx.append(pin1)
        xx.append(pin2)
        yy.append(xx)
    print(yy,"before")
    list_final=sorted(yy, key=lambda k: [k[0], k[1]])
    print(list_final,":after")
    for i in range(len(list_final)):
        print("({},{})".format(list_final[i][0], list_final[i][1]))

points = []
n = int(input())
for _ in range(n):
    string=input()
    x = ''
    y = ''
    i = 1
    cond = True
    while cond:
        if string[i] == (","):
            cond = False
            i += 1
        else:
            x += string[i]
            i += 1

    cond = True
    while cond:
        if string[i] == (")"):
            cond = False
        else:
            y += string[i]
            i += 1
            # print(y)
    X=int(x)
    Y=int(y)
    points.append(Point(X, Y))

convexHull(points, len(points))
