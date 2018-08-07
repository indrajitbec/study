def smart_divide(func):
   def inner(a,b):
      print("I am going to divide",a,"and",b)
      if b == 0:
         print("Whoops! cannot divide")
         return

      return func(a,b)
   return inner

@smart_divide
def divide(a,b):
    return a/b

def simple_div(a,b):
    return a/b

#print(simple_div(2,0))
print(divide(2,0))
print("=====")
print(divide(6,2))
print("====")
