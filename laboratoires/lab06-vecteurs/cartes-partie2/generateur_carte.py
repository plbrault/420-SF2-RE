import copy
import random

def print_matrix(matrix, cell_width=4):
    def justify(number, width):
        return str(number) + ' ' * (width - len(str(number)))
    for r in matrix:
        for c in r:
            print(justify(c, cell_width), end='')
        print()        

ROWS = 200
COLS = 30

print('Generating matrix of size', ROWS, 'x', COLS)

matrix = []
for i in range(ROWS):
    row = []
    for j in range(COLS):
        row.append(random.randint(0, 200))
    matrix.append(row)

highlighted_matrix = copy.deepcopy(matrix)

NORTH = (0, -1)
EAST = (1, 0)
SOUTH = (0, 1)
WEST = (-1, 0)

def create_path(matrix, path_length):
    directions = [NORTH, EAST, SOUTH, WEST]
    pos = (random.randint(0, ROWS - 1), random.randint(0, COLS - 1))
    matrix[pos[0]][pos[1]] = 0
    highlighted_matrix[pos[0]][pos[1]] = '(0)'
    previous_val = 0
    for i in range(path_length):
        direction = random.choice(directions)
        pos = (pos[0] + direction[0], pos[1] + direction[1])
        if pos[0] < 0 or pos[0] >= ROWS or pos[1] < 0 or pos[1] >= COLS:
            continue
        matrix[pos[0]][pos[1]] = previous_val + 1
        highlighted_matrix[pos[0]][pos[1]] = '(' + str(previous_val + 1) + ')'
        previous_val += 1

for i in range(10, ROWS + COLS, 10):
    create_path(matrix, i + random.randint(0, 50))

print_matrix(highlighted_matrix, cell_width=6)
