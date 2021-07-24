from cs50 import get_float


def main():

    # Get user input
    dollars = get_float('Change owed: ')

    # Check user input
    while dollars < 0:
        print('Invalid')
        dollars = get_float('Change owed: ')

    # Calculate
    change = round(dollars * 100)
    quarter = 0
    dime = 0
    nickel = 0
    penny = 0
    r = change

    while(r >= 25):
        quarter = r // 25
        r = r % 25

    while(r >= 10):
        dime = r // 10
        r = r % 10

    while(r >= 5):
        nickel = r // 5
        r = r % 5

    penny = r
    coins = penny + nickel + dime + quarter

    # Print coins used
    print(coins)


main()