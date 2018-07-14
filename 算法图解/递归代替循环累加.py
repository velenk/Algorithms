#递归代替循环累加

def sum1(a):
    if a == []:
        s = 0
    else:
        s = a[0] + sum1(a[1:])
    return s

def input_num():
    while True:
        msg = input('The number list(use "," to split):')
        if msg:
            try:
                list1 = [int(n) for n in msg.split(',')]
                return list1
            except:
                print('Error')
        else:
            exit()

a = input_num()
s = sum1(a)
print(str(s))
