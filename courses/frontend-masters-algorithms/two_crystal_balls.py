import random
import math

HEIGHT = 100

def main():
    breakpoint = random.randint(0, HEIGHT - 1)
    breaks = []
    for i in range(0, HEIGHT):
        breaks.append(True) if i >= breakpoint else breaks.append(False)

    print(f"Breakpoint: {breakpoint}")
    print(two_crystal_balls(breaks))


def two_crystal_balls(breaks: list[bool]):
    i = jump = math.floor(math.sqrt(len(breaks)))
    while not breaks[i]:
        i += jump

    i -= jump
    while not breaks[i]:
        i += 1

    return i


if __name__ == "__main__":
    main()
