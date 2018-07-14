#quick sort
def main():
    list0 = get_list()
    list0 = quicksort(list0)
    print(list0)

def get_list():
    while True:
        msg = input('Input the number(split with ","):')
        if msg:
            try:
                list0 = [int(n) for n in msg.split(',')]
                return list0
            except:
                print('Error')
        else:
            exit()

def quicksort(list0):
    if len(list0) < 2:
        return list0
    else:
        list1 = []
        list2 = []
        pivot = list0[0]
        for i in list0[1:]:
            if i < pivot:
                list1.append(i)
            else:
                list2.append(i)
        list0 = quicksort(list1) + [pivot] + quicksort(list2)
        return list0

main()
