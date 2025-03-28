class FieldElement:
    def __init__(self, num, prime):
        if num >= prime or num < 0:
            error = f"Num {num} not in field range 0 to {prime - 1}"
            raise ValueError(error)
        self.num = num
        self.prime = prime

    def __repr__(self):
        return f"FieldElement_{self.prime}({self.num})"

    def __ne__(self, other):
        return (self != other)

    
    def __eq__(self, other):
        if other is None:
            return False
        return self.num == other.num and self.prime == other.prime
    
    def __add__(self, other):
        if self.prime != other.prime:
            return TypeError('Cannot add two numbers in different Fields')
        num = (self.num + other.num) % self.prime
        return self.__class__(num, self.prime)
    
    def __sub__(self, other):
        if self.prime != other.prime:
            return TypeError('Cannot add two numbers in different Fields')
        num = (self.num - other.num) % self.prime
        return self.__class__(num, self.prime)


if __name__ == "__main__":
    a = FieldElement(7, 13)
    b = FieldElement(12, 13)
    c = FieldElement(6, 13)
    print(a+b==c)