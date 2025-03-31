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
    
    def __mul__(self, other):
        if (self.prime != other.prime):
            return TypeError('Cannot add two numbers in different Fields')
        num = (self.num * other.num) % self.prime
        return self.__class__(num, self.prime)

    def __pow__(self, exponent):
        n = exponent % (self.prime - 1)
        num = pow(self.num, n, self.prime)
        return self.__class__(num, self.prime)
    
    def __truediv__(self, other):
        num = (self.num * pow(other.num, self.prime-2, self.prime) % self.prime)
        return self.__class__(num, self.prime)

if __name__ == "__main__":
    prime = 31
    print(3*pow(24, prime-2, prime) % prime)