import sys
import random

if len(sys.argv) < 2:
    print('Usage:')
    print('python substitution.py "<text>"')
    print('OR python substitution.py -f <input_filename> [<output_filename>]')
    sys.exit(1)

output_filename = None
if sys.argv[1] == '-f':
    filename = sys.argv[2]
    with open(filename, 'r') as file:
        text = file.read()
    if len(sys.argv) > 3:
        output_filename = sys.argv[3]

else:
    text = sys.argv[1]

letters = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'
]
shuffled_letters = letters[:]
random.shuffle(shuffled_letters)

substitutions = {}

for i in range(len(letters)):
    substitutions[letters[i]] = shuffled_letters[i]
    substitutions[letters[i].upper()] = shuffled_letters[i].upper()

print('Substitutions:', substitutions)
print('')
print('Ciphered text:')
print('')

def cipher(text, substitutions):
    result = ''
    for char in text:
        if char in substitutions:
            result += substitutions[char]
        else:
            result += char
    return result

ciphered_text = cipher(text, substitutions)

if output_filename:
    with open(output_filename, 'w') as file:
        file.write(ciphered_text)
        print('')
        print('Ciphered text written to', output_filename)
