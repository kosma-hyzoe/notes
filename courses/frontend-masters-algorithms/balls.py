import random
import math

HEIGHT = 100

def main():
    ball1 = random.randint(1, HEIGHT)
    ball2 = random.randint(1, HEIGHT)
    print(f"ball1: {ball1}  ball2: {ball2}")
    print(balls(ball1, ball2))


def balls(b1, b2):
    lo = 1
    hi = HEIGHT + 1

    while lo < hi:
        f = lo + math.floor(lo + (hi - lo) / 2);

        if f == b1 and f >= b2 or f == b2 and f >= b1:
            return f
        elif f < b1 or f < b2:
            lo = f + 1
        else:
            hi = f

if __name__ == "__main__":
    main()
