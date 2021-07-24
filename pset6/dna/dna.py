# Imports
import sys
import csv
import re


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python, database, dna sequence")

    database = sys.argv[1]
    dna = sys.argv[2]
    str = []

    # Import csv as reader
    with open(database, 'r') as file:
        reader = csv.DictReader(file)
        columns = reader.fieldnames

        # Make a list of dictionaries using rows
        data = list(reader)

    # Import txt sequence for read
    with open(dna, 'r') as file:
        sequence = file.read()

    counted = {}
    # Use files to find the longest match
    for i in range(1, len(columns), 1):
        str = columns[i]

        str_re = re.compile('(?:' + str + ')+')
        count = max((len(seq) for seq in str_re.findall(sequence)), default=0) // len(str)
        counted[str] = count

    # Loop through people list
    for i in range(0, len(data), 1):
        currentlist = data[i]
        name = currentlist['name']
        currentlist.pop('name')

        # Counter for correct matches
        match = 0
        for key in currentlist:

            if int(currentlist[key]) == counted[key]:
                match += 1

            if match == len(counted):
                print(name)
                sys.exit()
    print('No match.')


main()

