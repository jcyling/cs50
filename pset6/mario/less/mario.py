from cs50 import get_int

n = get_int('Height: ')

# Check input
while n < 1 or n > 8:
    print('Height should be 1 - 8 inclusive.')
    n = get_int('Height: ')

# Loop for half-pyramid
for i in range(1, n + 1):
    for j in range(n - i):
        print(' ', end='')
    for k in range(1, i + 1):
        print('#', end='')
        if k == i:
            print('')
