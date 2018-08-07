pow2 = [2 ** x for x in range(13)]

# Output: [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
print(pow2)

i = 0
for v in pow2:
    print("2 ^ {0} = {1}".format(i,v))
    i+=1
