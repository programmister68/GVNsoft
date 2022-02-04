import sys
import sqlite3
from sqlite3 import connect

class DSU():

    def __init__(self, n):
        self.rank = [1] * n
        self.parent = [i for i in range(n)]

    def find(self, x):
        if (self.parent[x] != x):
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xset = self.find(x)
        yset = self.find(y)

        if xset == yset:
            return
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset

        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset

        else:
            self.parent[yset] = xset
            self.rank[xset] = self.rank[xset] + 1

if __name__ == '__main__':
    set = DSU(10)
    set.union(0, 2)
    set.union(1, 2)
    set.union(5, 4)
    set.union(7, 3)
    if set.find(1) == set.find(0):
        print('Тест 1. Значения', set.find(1),'и', set.find(0), 'совпадают, множество уже объединено')
    else:
        print('Тест 1. Значения', set.find(1),'и', set.find(0), 'не совпадают, объединяем')

    if set.find(2) == set.find(5):
        print('Тест 2. Значения', set.find(2),'и', set.find(5), 'совпадают, множество уже объединено')
    else:
        print('Тест 2. Значения', set.find(2),'и', set.find(5), 'не совпадают, объединяем')

    if set.find(7) == set.find(5):
        print('Тест 3. Значения', set.find(7),'и', set.find(5), 'совпадают, множество уже объединено')
    else:
        print('Тест 3. Значения', set.find(7),'и', set.find(5), 'не совпадают, объединяем')
