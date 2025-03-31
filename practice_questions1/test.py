prime = 19

for k in (1, 3, 7, 13, 18):
    print([k*i % prime for i in range(prime)])        