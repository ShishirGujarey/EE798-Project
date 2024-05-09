class A:

  def __init__(self):
    self.x: int = 1
    self.y: int = 4
  
  def sum(self)->int:
    p:int = self.x
    q:int = self.y
    r:int = p+q
    print(p)
    print(q)
    return r

class B(A):

  def __init__(self):
    self.x = 3
    self.y = 5
    self.z: int = 87

def main():
  a: A = A()
  b: B = B()
  print("Parent")
  d:int= a.sum()
  print("Sum")
  print(d)
  print("Child")
  c:int = b.sum()
  print("Sum")
  print(c)
if __name__ == "__main__":
  main()