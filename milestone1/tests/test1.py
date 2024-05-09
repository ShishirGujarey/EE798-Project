class Rectangle:
    def __init__(self, width, height):
        self.width: int = width
        self.height: int = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)

    def diagonal_length(self):
        return (self.width ** 2 + self.height ** 2) ** 0.5

class Square(Rectangle):
    def __init__(self, side_length):
        super().__init__(side_length, side_length)

class Circle:
    def __init__(self, radius):
        self.radius:float = radius

    def area(self):
        return 3.14 * self.radius ** 2

    def circumference(self):
        return 2 * 3.14 * self.radius

class Cylinder:
    def __init__(self, radius, height):
        self.radius: float = radius
        self.height:float = height

    def surface_area(self):
        return 2 * 3.14 * self.radius * (self.radius + self.height)

    def volume(self):
        return 3.14 * self.radius ** 2 * self.height

def main():
    rectangle: Rectangle = Rectangle(5, 4)
    print("Rectangle Area:", rectangle.area())
    print("Rectangle Perimeter:", rectangle.perimeter())
    print("Rectangle Diagonal Length:", rectangle.diagonal_length())

    square :Square= Square(5)
    print("Square Area:", square.area())
    print("Square Perimeter:", square.perimeter())
    print("Square Diagonal Length:", square.diagonal_length())

    circle : Circle = Circle(3)
    print("Circle Area:", circle.area())
    print("Circle Circumference:", circle.circumference())

    cylinder: Cylinder = Cylinder(3, 5)
    print("Cylinder Surface Area:", cylinder.surface_area())
    print("Cylinder Volume:", cylinder.volume())

if __name__ == "__main__":
    main()