#二分法查找

def main():
    string = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    letter = get_msg()
    num = search(letter, string)
    if num:
        num = num + 1
        print(num)

def get_msg():
    s = input('Input a letter (Captial):')
    while True:
        if s:
            return s
        else:
            break

def search(a, s):
    start = 0
    end = len(s) - 1
    while start <= end:
        mid = (start + end)// 2
        if s[mid] == a:
            return mid
        elif s[mid] < a:
            start = mid + 1
        else:
            end = mid - 1
    else:
        print('Not Found')

main()
    
