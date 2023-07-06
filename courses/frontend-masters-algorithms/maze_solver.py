from collections import namedtuple
import sys

Point = namedtuple('Point', ['x', 'y'])

WALL = "x"
ROW_LENGHT = 12
N_ROWS = 6
MAZE = ["xxxxxxxxxx x",
        "x        x x",
        "x        x x",
        "x xxxxxxxx x",
        "x          x",
        "x xxxxxxxxxx"]

path: [Point] = []
visited: [Point] = []


def print_way():
    pass

def is_walkable(maze, p: Point):
    return p.x in range(0, ROW_LENGHT) and p.y in range(0, N_ROWS) \
            and maze[p.y][p.x] != WALL


def walk_maze(maze: list[str], p: Point, end: Point):
    if not is_walkable(maze, p) or p in visited:
        return False
    elif p == end:
        path.append(p)
        return True
    visited.append(p)

    path.append(p)
    drs = [Point(p.x - 1, p.y), Point(p.x + 1, p.y),
           Point(p.x, p.y - 1), Point(p.x, p.y + 1)]

    for dr in drs:
        if walk_maze(maze, dr, end):
            return True
    path.pop()

def solve_maze(maze: list[str], start: Point, end: Point):
    if not walk_maze(maze, start, end):
        print(path)
        exit(1)


if __name__ == "__main__":
    start = Point(10, 0)
    end = Point(1, N_ROWS - 1)

    solve_maze(MAZE, start, end)
    print(path)


