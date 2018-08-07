def greet(name, msg = "Good morning!"):
   """
   This function greets to
   the person with the
   provided message.

   If message is not provided,
   it defaults to "Good
   morning!"
   """

   print("Hello",name + ', ' + msg)

greet("Kate")
greet("Bruce","How do you do?")

greet(name = "Bruce",msg = "How do you do?")
greet(msg = "How do you do?",name = "Bruce")
greet("Bruce",msg = "How do you do?")
#greet(name="Bruce","How do you do?")

def greetAll(*names):
   """This function greets all
   the person in the names tuple."""

   # names is a tuple with arguments
   for name in names:
       print("Hello",name)

greetAll("Monica","Luke","Steve","John")

def calc_factorial(x):
    """This is a recursive function
    to find the factorial of an integer"""

    if x == 1:
        return 1
    else:
        return (x * calc_factorial(x-1))

#num = int(input("Enter an integer: "))
num = 4
print("The factorial of", num, "is", calc_factorial(num))
