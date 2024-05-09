def factorial(n:int)->int:
    if n==1:
        return 1
    if n==0:
        return 1
    else:
        x:int=factorial(n-1)
        y:int= n
        return x*y

# def sum(a:int,b:int)->int:
#     sm:int=a+b
#     return sm

def main():
    b:int = 4
    print(b)
    a:int = factorial(b)
    print(a)
    c:int = 7
    print(c)
    d:int = factorial(c)
    print(d)
    print("done")
    

if __name__ == "__main__":
    main()