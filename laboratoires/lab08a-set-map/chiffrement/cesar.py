import sys

if len(sys.argv) < 2:
    print('Usage:')
    print('python cesar.py <shift> "<text>"')
    print('OR python cesar.py <shift> -f <filename>')
    sys.exit(1)

shift = int(sys.argv[1])
if sys.argv[2] == '-f':
    filename = sys.argv[3]
    with open(filename, 'r') as file:
        text = file.read()
else:
    text = sys.argv[2]

lowercase_letters = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'
]
uppercase_letters = [letter.upper() for letter in lowercase_letters]

def cipher(shift, text):
    result = ""
    for char in text:
        if char in lowercase_letters:
            index = lowercase_letters.index(char)
            new_index = (index + shift) % len(lowercase_letters)
            result += lowercase_letters[new_index]
        elif char in uppercase_letters:
            index = uppercase_letters.index(char)
            new_index = (index + shift) % len(uppercase_letters)
            result += uppercase_letters[new_index]
        else:
            result += char
    return result

print(cipher(shift, text))
