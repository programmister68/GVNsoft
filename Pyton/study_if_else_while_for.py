i = 1000
while i >= 20:
    print (i, end = '; ' )
    i /=2
    
print (end = '\n')

for i in 'hello world':
    if i == ' ':
        print (i*1, end = '')
    else:
        print (i*3, end = ' ')

print (end = '\n')

for j in 'hello world':
    if j == 'w': 
        continue #Пропуск итерации
    print (j * 3, end = ' ')

print (end = '\n')

for j in 'hello world':
    if j == 'w': 
        break #Выход из цикла
    print (j * 3, end = ' ')
    print (end = '\n')

for j in 'hello world':
    if j == 'k': 
        break 
    print (j * 4, end = ' ')
else:
    print (end = '\n')
    print ("Буквы k нет в строке")
    
print (end = '\n')

################################

counter = 0
bukva = input()
for j in 'hello world':
    if j == bukva: 
        counter +=1
print (counter)

