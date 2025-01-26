def eu_mod(a, b):
    r = a % b
    if r < 0:
        r += abs(b)
    return r


def extended_euclidean(a, b):
    x0, x1 = 1, 0

    while b != 0:
        q = a // b
        a, b = b, eu_mod(a, b)
        x0, x1 = x1, x0 - q * x1
    return a, x0


a, b = 698917, -102089
# a, b = -417143, -455947
gcd, x = extended_euclidean(a, b)
y = (gcd - x * a) // b

print(f"{x} {y} {gcd}")
