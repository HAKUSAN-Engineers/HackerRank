n = int(input())
names_and_numbers = [input().split() for _ in range(n)]
phone_book = {k: v for k, v in names_and_numbers}

while True:
    try:
        name = input()
        if name in phone_book:
            print(name + '=' + phone_book[name])
        else:
            print('Not found')
    except:
        break

