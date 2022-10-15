
"""search element in a list using linear search"""


def take_user_input():
    x = int(input('enter the number'))
    lst = [ ]
    for i in range(0,x):
        y = int(input('enter values for list'))
        lst.append(y)
        print(lst)
    z = int(input('enter num that u want to find in list '))
    return lst,z

def check_if_element_in_list(lst,z):
    found = False
    for i in lst:
        # 
        if z == i:
            found = True
            break
    return found


def print_result(found):
    if not found:
        print('the number is not present in list')

    if found:
        print('the number is present in list')


def main():
    lst,z = take_user_input()
    present =  check_if_element_in_list(lst,z)
    print_result(present)


main()