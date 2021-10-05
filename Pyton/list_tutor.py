l = []
lis = [2, 1, 'fox', 34, 2.34, [1,2,3]]
print (lis)

a = [a+b for a in 'list' if a!= 's' for b in 'sop' if b!= 'u']
print (a)

lis.append (23)
lis.append ('fox')
print (lis)

lis.extend (a)
print (lis)

lis.insert(3, 68) #Это функция вставки, не замены!
print (lis)

lis.remove ('fox') #Функция удаления элмента. Удаляет указанный элемент только один раз.
print (lis)

lis.pop (6) #даление элемента по индексу, если не указать его, то удалит последний элемент списка
print (lis)

print ("Index 'fox': ", lis.index ('fox'))

print (lis.count ('fox'))
print (lis.clear())
