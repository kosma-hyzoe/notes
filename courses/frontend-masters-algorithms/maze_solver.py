from collections import namedtuple
import sys

Point = namedtuple('Point', ['x', 'y'])

WALL = "x"
ROW_LENGHT = 12
N_ROWS = 6
MAZE = ["xxxxxxxxxxSx",
        "x        x x",
        "x        x x",
        "x xxxxxxxx x",
        "x          x",
        "xExxxxxxxxxx"]

path: [Point] = []
visited: [Point] = []

"""off map, is wall, been there, the end"""

def print_way():
    pass

def is_walkable(p: Point):
    return p.x in range(0, ROW_LENGHT) and p.y in range(0, N_ROWS) \
            and MAZE[p.y][p.x] != "#"


def walk_maze(maze: list[str], p: Point, end: Point):
    while p != end:
        drs = [Point(p.x - 1, p.y), Point(p.x + 1, p.y),
               Point(p.x, p.y - 1), Point(p.x, p.y + 1)]
        for dr in drs:
            if is_walkable(dr) and dr not in visited:
                p = dr
                if walk_maze(maze, dr, end):
                    path.append(dr)
                    return True
                else:
                    visited.append(dr)
        return False
    return True

def solve_maze(maze: list[str], start: Point, end: Point):
    if not walk_maze(maze, start, end):
        exit(1)





if __name__ == "__main__":
    sys.setrecursionlimit(1500)
    start = Point(10, 0)
    end = Point(1, N_ROWS)

    solve_maze(MAZE, start, end)
    print(path)


