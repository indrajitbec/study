# A simple generator function
def my_gen():
    n = 1
    #print('This is printed first')
    # Generator function contains yield statements
    yield (n,"Hi")

    n += 1
    #print('This is printed second')
    yield (n, "Haha")

    n += 1
    #print('This is printed at last')
    yield n

# Using for loop
for item in my_gen():
    print(item)

    # Initialize the list
my_list = [1, 3, 6, 10]

# square each term using list comprehension
# Output: [1, 9, 36, 100]
print([x**2 for x in my_list])

# same thing can be done using generator expression
# Output: <generator object <genexpr> at 0x0000000002EBDAF8>
gen = (x**2 for x in my_list if x % 2 == 0)
print("##################")
for i in gen:
    print(i)
print("##################")

def rev_str(my_str):
    length = len(my_str)
    for i in range(length - 1,-1,-1):
        yield my_str[i]

# For loop to reverse the string
# Output:
# o
# l
# l
# e
# h
for char in rev_str("hello"):
     print(char)
