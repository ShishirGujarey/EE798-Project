def Add(a:int, b:int)->int:
    c:int = a+b
    return c

def Subtract(a:int, b:int)->int:
    c:int = a-b
    return c

def Multiply(a:int, b:int)->int:
    c:int = a*b
    return c

def Power(a:int, b:int)->int:
    c:int = 1
    for i in range (0,b):
        c = c*a
    return c
    
def Divide(a:int, b:int)->int:
    c:int = a/b
    return c

def main():
    x:int = 6
    y:int = 3
    z:int = Add(x, y)
    print(z)
    z=Subtract(x, y)
    print(z)
    z=Multiply(x, y)
    print(z)
    z=Divide(x, y)
    print(z)
    z=Power(x, y)
    print(z)

if __name__ == "__main__":
    main()