from collections import namedtuple

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

way = [[" " for _ in range(ROW_LENGHT)] for _ in range(N_ROWS)]
visited: [Point] = []

"""off map, is wall, been there, the end"""

def print_way():
    pass

def walk_maze(maze: list[str], pos: Point):
        for dr in [(x - 1, y), (x + 1, y), (x, y - 1),(x, y + 1)]:
            if dr.x not in range(0, ROW_LENGHT) or dr.y not in range(0, N_ROWS):
                solve_maze(
            elif dr in visited:
                return False
            elif MAZE[dr.y][dr.x] == "#":
                visited.append(dr)
                return False

            print_way()
            if MAZE[dr.y][dr.x] == "E":
                sys.exit(0)
            else:
                return False

def solve_maze(maze: list[str], start: Point):
    pos = start
    for y in range(0, N_ROWS):
        for x in range(0, ROW_LENGHT):
            if (x, y) == pos:
                if not walk_maze(maze, pos):




if __name__ == "__main__":
    start = Point(MAZE[0].index("S"), 0)
    end = Point(MAZE[N_ROWS].index("E"))

    print(solve_maze(MAZE, start, end))


