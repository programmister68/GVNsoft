a = int (input ("Введите значение а: " ))
b = int (input ("Введите значение b: " ))
c = int (input ("Введите любое число: ")) 
if a%2 ==0 and b%2 == 0:
    print (a, "+", b, "=", a+b)
else:
    print (a, "-", b, "=", a-b)

while True:
    c-=10
    print (c)
    if c <= 0:
        break
    
