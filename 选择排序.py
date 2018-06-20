#选择排序

def main():
    list0 = get_list()
    newlist = []
    for i in range(len(list0)):
        small = smallest(list0)
        newlist.append(list0.pop(small))
    return newlist

def get_list():
    while True:
        msg = input("Input the list(use ',' to split):")
        if msg:
            try:
                msg = [int(n) for n in msg.split(',')]
                return msg
            except:
                print('Error')
        else:
            exit()

def smallest(a):
    smallest = a[0]
    index = 0
    for i in range(1, len(a)):
        if a[i] < smallest:
            smallest = a[i]
            index = i
    return index

new = main()
print(new)
