import constant

if True:
    print("hello world!!")
else:
    print("WTF!!")
for i in range(0, 10):
    print(i)
num = 0

#if num == 0
#    raise ZeroDivisionError('cannot devide')
a, b, c = 10,3.2, "who ?"
print(a)
print(b)
print(c)



print(constant.PI)
print(constant.GRAVITY)

a = 0b1010
b = 100
c = 0o310
d = 0x12c


float_1 = 10.5
float_2 = 1.5e2

x = 3.14j

print(a, b, c, d)
print(float_1, float_2)
print(x, x.imag, x.real)


strings = "This is Python"
char = "C"
multiline_str = """This is a multiline string with more than one line code."""
unicode = u"\u00dcnic\u00f6de"
raw_str = r"raw \n string"

print(strings)
print(char)
print(multiline_str)
print(unicode)
print(raw_str)


x = (1 == True)
y = (1 == False)
a = True + 4
b = False + 10

print("x is", x)
print("y is", y)
print("a:", a)
print("b:", b)

drink = "Available"
food = None


def menu(x):
    if x == drink:
        print(drink)
    else:
        print(food)


menu(drink)
menu(food)

# list
fruits = ["apple", "mango", "orange"]

# tuple
numbers = (1, 2, 3)

# dictionary
alphabets = {'a': 'apple', 'b': 'ball', 'c': 'cat'}

# set
vowels = {'a', 'e', 'i', 'o', 'u'}

print(fruits)
print(numbers)
print(alphabets)
print(vowels)


a = 5
print(a, "is of type", type(a))

a = 2.0
print(a, "is of type", type(a))

a = 1+2j
print(a, "is complex number?", isinstance(1+2j,complex), type(a))

b = 2+3j

print(a*b)

a = [5,10,15,20,25,30,35,40]

print(a)

# a[2] = 15
print("a[2] = ", a[2])

# a[0:3] = [5, 10, 15]
print("a[0:3] = ", a[0:3])

# a[5:] = [30, 35, 40]
print("a[5:] = ", a[5:])

t = (5,'program', 1+3j)

# t[1] = 'program'
print("t[1] = ", t[1])

# t[0:3] = (5, 'program', (1+3j))
print("t[0:3] = ", t[0:3])

# Generates error
# Tuples are immutable
#t[0] = 10

a = {5,2,3,1,4}

# printing set variable
print("a = ", a)

# data type of variable a
print(type(a))

d = {1:'value','key':2}
print(type(d))

print("d[1] = ", d[1]);

print("d['key'] = ", d['key']);

# Generates error
#print("d[2] = ", d[2]);
print("d[2] = ", d.get(2));

num_int = 123
num_str = "456"

print("Data type of num_int:",type(num_int))
print("Data type of num_str before Type Casting:",type(num_str))

num_str = int(num_str)
print("Data type of num_str after Type Casting:",type(num_str))

num_sum = num_int + num_str

print("Sum of num_int and num_str:",num_sum)
print("Data type of the sum:",type(num_sum))

print(1,2,3,4)
# Output: 1 2 3 4

print(1,2,3,4,sep='*',flush=True)
# Output: 1*2*3*4

print(1,2,3,4,sep='#',end='&')
# Output: 1#2#3#4&
print()

a = 2
# Output: id(2)= 10919424
print('id(2) =', id(2))

# Output: id(a) = 10919424
print('id(a) =', id(a))

print("==================")
a = 2

# Output: id(a) = 10919424
print('id(a) =', id(a))

a = a+1

# Output: id(a) = 10919456
print('id(a) =', id(a))

# Output: id(3) = 10919456
print('id(3) =', id(3))

b = 2

# Output: id(2)= 10919424
print('id(2) =', id(2))

print('id(b)=', id(b))

def printHello():
    print("Hello")
a = printHello()

# Output: Hello
a
