def outer_function():
    a = 20
    def inner_function():
        a = 30
        print('a =',a)

    inner_function()
    print('a =',a)

a = 10
outer_function()
print('a =',a)

# Program to iterate through a list using indexing

genre = ['pop', 'rock', 'jazz']

# iterate over the list using index
for i in range(len(genre)):
	print("I like", genre[i])

digits = [0, 1, 5]

for i in digits:
    print(i)
else:
    print("No items left.")
