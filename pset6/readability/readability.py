from cs50 import get_string


def main():

    # Get string from user
    text = get_string('Text: ')

    # Find letters and sentences
    L = 0
    S = 0
    W = 1

    for c in text:
        if (c.isalpha()):
            L += 1
        elif (c.isspace()):
            W += 1
        elif (c == '!' or c == '.' or c == '?'):
            S += 1

    # Calculate grade using formulae
    averageLets = 100.00 * L / W
    averageStns = 100.00 * S / W
    index = 0.0588 * averageLets - 0.296 * averageStns - 15.8

    grade = round(index)

    # Print grade level
    if (grade < 1):
        print('Before Grade 1')
    elif (grade > 16):
        print('Grade 16+')
    else:
        print(f'Grade {grade}')


main()