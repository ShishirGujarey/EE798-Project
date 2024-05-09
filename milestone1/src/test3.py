def fib(a:int) -> int :
    if a==1:
        return 1
    x:int=a*fib(a-1)
    return x

if __name__ == "__main__":
    print(fib(6))