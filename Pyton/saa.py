import sqlite3

def num():
    while 1:
        try:
            k = float(input())
            return k

        except ValueError:
            print("Используйте цифры от 0 до 9 и '.'")


def update(table, row, data, code):
    while 1:
        try:
            print('Введите новые данные: ')
            sql.execute(f'UPDATE {table} SET {row}="{input()}" WHERE "{code}"=="{data}"')
            db.commit()
            return
        except IndexError:
            print("Введено некорректное значение! Введите повторно")


def existing():
    cout = 0
    for value in sql.execute(f"""SELECT * FROM '{table}'"""):
        print(value)

    while 1:
        try:
            return int(input("Выберите из выше перечисленных нужный вариант (перый столбец): "))
            #return [value for value in sql.execute(f"SELECT '{code}' FROM '{table}' LIMIT 1 OFFSET '{choice - 1}'")][0][0]

        except ValueError:
            print("Введено некорректное значение! Введите повторно")


db = sqlite3.connect('refill3.db')
sql = db.cursor()

#создаем таблицы:

#4:
sql.execute("""CREATE TABLE IF NOT EXISTS Fuel ( 
    Product_code integer primary key, 
    Product_Name TEXT,
    Unit TEXT,
    Cost_of_goods FLOAT,
    Note_Item TEXT
)""")

#8:
sql.execute("""CREATE TABLE IF NOT EXISTS Name_Station (
    Refueling_code integer primary key,
    Name_of_Gas_Station TEXT,
    Note TEXT
)""")

db.commit()


while 1:
    choice = input('Что вы хотите сделать? \n1) Добавить новые данные\n2) Отредактировать существующие данные\n3) Просмотреть данные\n4) Выйти\n')

    #вводим в таблицу данные
    if choice=='1':
        choice = input('1) Добавить новое топливо\n2) Выбрать существующее\n')

        # новые данные в таблице 4
        if choice=='1':
            Product_Name = input('название топлива: ')
            Unit = input('Единица измерения топлива: ')
            print('Стоимость топлива за единицу: ')
            Cost_of_goods = num()
            Note_Item = input('Примечание к топливу: ')

            sql.execute("INSERT INTO Fuel VALUES (NULL,?,?,?,?)", (Product_Name, Unit, Cost_of_goods, Note_Item))
            # NULL тк первичный ключ - primary key (он сам нумеруется)
            db.commit()     #обязательно прописать после добавления, иначе не сохранится

            # нам нужен Product_code тк он используется в 1, 2 и 7 таблицах, мы его выбираем из только что введенной строки
            Product_code=[value for value in sql.execute(f"SELECT Product_code FROM Fuel WHERE Product_Name=='{Product_Name}' and Unit=='{Unit}' and Cost_of_goods=='{Cost_of_goods}' and Note_Item=='{Note_Item}'")][0][0]

            # if sql.fetchone() is None:
            #     print("good")


        #при выборе существующей. Нам нужен только код (выбор существующего нужен в таблицах  3, 4, 5, 6, 8 то есть там где есть primary key)
        elif choice=='2':

            table = 'Fuel' # название таблицы
            code = 'Product_code'  # только первичный ключ
            sql.execute(f"SELECT '{code}' FROM '{table}'")

            if sql.fetchone() is not None:
                Product_code = existing()

            else:
                print('тут ничего нет')
                # print('code', Product_code)

        else:
            print("Введено некорректное значение")


        choice = input('1) Добавить новую заправку\n2) Выбрать существующую\n')
        # новые данные в таблице 8
        if choice=='1':
            Name_of_Gas_Station = input('название заправки: ')
            Note = input('примечание: ')

            sql.execute("INSERT INTO Name_Station VALUES (NULL,?, ?)", (Name_of_Gas_Station, Note))
            db.commit()  # обязательно прописать после добавления, иначе не сохранится

            # нам нужен Refueling_code тк он используется в 1, 2 и 7 таблицах, мы его выбираем из только что введенной строки
            Refueling_code = [value for value in sql.execute(f"SELECT Refueling_code FROM Name_Station WHERE Name_of_Gas_Station=='{Name_of_Gas_Station}' and Note=='{Note}'")][0][0]

        elif choice=='2':

            table = 'Name_Station'  # название таблицы
            code = 'Refueling_code'  # только первичный ключ
            sql.execute(f"SELECT '{code}' FROM '{table}'")

            if sql.fetchone() is not None:
                Refueling_code = existing()

            else:
                print('тут ничего нет')


        else:
            print("Введено некорректное значение")




    #изменить данные
    elif choice=='2':
        choice=input('Какую таблицу хотите отредактировать?\n1) Приход топлива\n2) Поставщик\n3) Топливо\n4) Потребитель\n5) Сотрудник\n6) Расход топлива\n7) Название заправки\n')
        if choice=='1':
            pass
        elif choice=='2':
            pass
        elif choice=='3':
            f=True
            code = 'Product_code' # первичный ключ
            table = 'Fuel'
            for value in sql.execute(f"SELECT * FROM '{table}'"):
                print(value)

            choice = input('Какой столбец хотите отредактировать?\n1) Название топлива\n2) Единица измерения\n3) Стоимость топлива\n4) Примечание топлива\n')
            data = input('Введите код строки (первый столбик): ')
            if choice == '4':
                row='Note_Item'
            elif choice == '1':
                row='Product_Name'
            elif choice == '2':
                row='Unit'
            elif choice == '3':
                row='Cost_of_goods'
            else:
                print("Введено некорректное значение! Введите повторно")
                f=False

            if f:
                update(table, row, data, code)



        elif choice == '4':
            pass
        elif choice == '5':
            pass
        elif choice == '6':
            pass
        elif choice == '7':
            f=True
            table = 'Name_Station'
            code = 'Refueling_code'
            for value in sql.execute(f"SELECT * FROM '{table}'"):
                print(value)

            choice = input('Какой столбец хотите отредактировать?\n1) Название заправки\n2) Примечание\n')
            data = input('Введите код строки (первый столбик): ')
            if choice == '1':
                row = 'Name_of_Gas_Station'
            elif choice == '2':
                row = 'Note'
            else:
                print("Введено некорректное значение! Введите повторно")
                f = False

            if f:
                update(table, row, data, code)


        else:
            print("Введено некорректное значение! Введите повторно")




    #выведем
    elif choice=='3':
        # должны выводиться данные за определенный день, тут пишет Свят - 1 табл.
        # то есть данные должны каждый раз рассчитываться, записываться в бд и выводится (хотя в теории можно да же не записывать в бд, но наверное лучше записать)

        #пример вывода:
        print('пример специально для вас (как вывести данные):')
        for value in sql.execute("SELECT * FROM Fuel"): # * значит, что выбираем все данные из табицы Fuel
            print(value)                                # выводим выбранные данные

        #или так (запихиваем данные из таблицы в переменную)
        a = [value for value in sql.execute(f"SELECT Name_of_Gas_Station FROM Name_Station WHERE Refueling_code=={1}")]   # выбираем столбик Name_of_Gas_Station из таблицы Name_of_Gas_Station, но только те, где Refueling_code равен одному
        print(a)  # выводим выбранные данные




    #выход
    elif choice=='4':
        exit()

    else:
        print("Введено некорректное значение")
