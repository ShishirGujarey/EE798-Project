def main():
    p:bool = 6>2
    print(p)
    q:bool = 7<5
    print(q)
    r:bool = p and q
    print(r)
    s:bool = p or q
    print(s)
    a:int = 6 & 10         #0110 & 1010 = 0010 = 2
    print(a)
    a = 6 | 10             #0110 | 1010 = 1110 = 14
    print(a)
    a = 6 ^ 10             #0110 ^ 1010 = 1100 = 12
    print(a)
    a = 6<<1               #0110 << 1 = 1100 = 12
    print(a)
    a = 6>>1               #0110 >> 1 = 0011 = 3
    print(a)

if __name__ == "__main__":
    main()