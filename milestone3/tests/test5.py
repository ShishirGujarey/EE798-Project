def listrev(a:list[int])->list[int]:
    b:list[int] = [3, 2, 1]
    return b

def main():
    c:list[int] = [1, 2, 3]
    d:list[int] = listrev(c)
    p:int = d[0]
    q:int = d[1]
    r:int = d[2]
    print(p)
    print(q)
    print(r)
