import copy
import random
import sys

if len(sys.argv) != 4:
    print("Usage: python generateur_carte.py <rows> <cols> <output_file>")
    sys.exit(1)

rows = int(sys.argv[1])
cols = int(sys.argv[2])

output_filename = sys.argv[3]

def print_matrix(matrix, cell_width=4):
    def justify(number, width):
        return str(number) + ' ' * (width - len(str(number)))
    for r in matrix:
        for c in r:
            print(justify(c, cell_width), end='')
        print()        

print('Generating matrix of size', rows, 'x', cols)

matrix = []
for i in range(rows):
    row = []
    for j in range(cols):
        row.append(random.randint(0, rows + cols))
    matrix.append(row)

highlighted_matrix = copy.deepcopy(matrix)
visited_positions = []

NORTH = (0, -1)
NORTHEAST = (1, -1)
EAST = (1, 0)
SOUTHEAST = (1, 1)
SOUTH = (0, 1)
SOUTHWEST = (-1, 1)
WEST = (-1, 0)
NORTHWEST = (-1, -1)

directions = [NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST]

def pick_new_position(matrix, current_pos):
    def can_use_position(pos):
        return (
            pos[0] >= 0
            and pos[0] < len(matrix)
            and pos[1] >= 0
            and pos[1] < len(matrix[0])
            and pos not in visited_positions
        )
    direction = random.choice(directions)
    new_pos = (current_pos[0] + direction[0], current_pos[1] + direction[1])
    tries = 1
    while (
        tries < len(directions)
        and not can_use_position(new_pos)
    ):
        direction = directions[(directions.index(direction) + 1) % len(direction)]
        new_pos = (current_pos[0] + direction[0], current_pos[1] + direction[1])
        tries += 1
    if can_use_position(new_pos):
        return new_pos
    else:
        return None

def create_path(matrix, start_pos, path_length, continue_path=False):
    max_val = 0
    pos = start_pos
    if continue_path:
        previous_val = matrix[pos[0]][pos[1]]
    else:
        previous_val = matrix[pos[0]][pos[1]] = 0
        highlighted_matrix[pos[0]][pos[1]] = '(0)'
        visited_positions.append(pos)
    for i in range(path_length):
        pos = pick_new_position(matrix, pos)
        if pos is None:
            break
        matrix[pos[0]][pos[1]] = previous_val + 1
        highlighted_matrix[pos[0]][pos[1]] = '(' + str(previous_val + 1) + ')'
        previous_val += 1
        visited_positions.append(pos)
        if previous_val > max_val:
            max_val = previous_val
    return max_val

max_val = 0

num_base_paths = min((rows + cols) // 10 + 1, 10)
for i in range(num_base_paths):
    start_pos = (random.randint(0, rows - 1), random.randint(0, cols - 1))
    while start_pos in visited_positions:
        start_pos = (random.randint(0, rows - 1), random.randint(0, cols - 1))
    local_max = create_path(matrix, start_pos, random.randint(num_base_paths, num_base_paths * 2))
    if local_max > max_val:
        max_val = local_max

for i in range(num_base_paths * 2):
    start_pos = random.choice(visited_positions)
    local_max = create_path(matrix, start_pos, random.randint(i, i * 2), continue_path=True)
    if local_max > max_val:
        max_val = local_max

print_matrix(highlighted_matrix, cell_width=6)
with open(output_filename, 'w') as f:
    for row in matrix:
        f.write(' '.join(str(cell) for cell in row) + '\n')
print('MAX VALUE:', max_val)
