try: 
    a = int(input())
    b = int(input())
    c = a/b
    d = []
    d[3] = int(input())

except ZeroDivisionError as err: 
    print("You cant divide by 0 man")
    
except IndexError as err2:
    print("Index is out of bounds")