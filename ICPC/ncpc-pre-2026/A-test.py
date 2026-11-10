from random import randint as ri

n = ri(1, 20)

print(1)
print(' '.join([f'{n}', f'{ri(1, n)}'] + [str(ri(1, 10 ** 7)) for _ in range(n)]))