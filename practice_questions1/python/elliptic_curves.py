class Point:
    def __init__(self, x, y, a, b):
        self.a = a
        self.b = b
        self.x = x
        self.y = y
        if self.y**2 != self.x**3 + a * x + b:
            raise ValueError('({}, {}) is not on the curve'.format(x, y))
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y \
            and self.a == other.a and self.b == other.b
    
    def __ne__(self, other):
        return self.x != other.x or self.y != other.y \
            or self.a != other.a or self.b != other.b
    
if __name__ == "__main__":
    def on_curve(x, y):
        return y ** 2 == x ** 3 + 5 * x + 7

    print(on_curve(2,4))
    print(on_curve(-1,1))
    print(on_curve(18,77))
    print(on_curve(5,7))