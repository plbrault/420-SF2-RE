import random
import csv

def generate_values(num_values):
    values = []
    for _ in range(num_values):
        if len(values) >= 3 and random.random() < 0.1:  # 10% chance to create a sequence
            if random.random() < 0.5:  # 50% chance to increase
                values.append(round(values[-1] * 1.12, 4))
            else:  # 50% chance to decrease
                values.append(round(values[-1] * 0.88, 4))
        else:
            values.append(round(random.uniform(0, 1000), 4))
    return values

def write_to_csv(values, filename):
    with open(filename, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for value in values:
            writer.writerow([value])

values = generate_values(100000)
write_to_csv(values, '/home/andrew/420-SF2-RE/laboratoires/lab07-listes/solution/data_to_add.csv')