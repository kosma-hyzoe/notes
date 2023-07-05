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
            and MAZE[p.y][p.x] != WALL


def walk_maze(maze: list[str], p: Point, end: Point):
    if p == end:
        return True
    elif is_walkable(p) and p not in visited:
        path.append(p)
        drs = [Point(p.x - 1, p.y), Point(p.x + 1, p.y),
               Point(p.x, p.y - 1), Point(p.x, p.y + 1)]
        for dr in drs:
            if walk_maze(maze, dr, end):
                return True
            else:
                visited.append(dr)
        path.pop()
    return False

def solve_maze(maze: list[str], start: Point, end: Point):
    if not walk_maze(maze, start, end):
        exit(1)





if __name__ == "__main__":
    sys.setrecursionlimit(1500)
    start = Point(10, 0)
    end = Point(1, N_ROWS)

    solve_maze(MAZE, start, end)
    print(path)


