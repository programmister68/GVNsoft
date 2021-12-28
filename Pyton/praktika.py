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

#2:
sql.execute("""CREATE TABLE IF NOT EXISTS Fuel_arrival ( 
    Refueling_Code integer primary key, 
    Fuel_Code INT,
    Supplier_Code INT,
    Fuel_Arrival_Date TEXT,
    Fuel_Arrival_Time TEXT,
    Fuel_Quantity FLOAT,
    Total_Cost_of_Goods FLOAT,
    Driver_Supplier TEXT,
    Invoice_number TEXT
)""")

#6:
sql.execute("""CREATE TABLE IF NOT EXISTS Employee (
    Gas_Station_Employee_Code integer primary key,
    Surname TEXT,
    Name TEXT,
    Patronymic TEXT,
    Phone_number TEXT,
    Employment_date TEXT,
    Hiring_Hours TEXT
)""")


db.commit()


while 1:
    choice = input('Что вы хотите сделать? \n1) Добавить новые данные\n2) Отредактировать существующие данные\n3) Просмотреть данные\n4) Выйти\n')

    #вводим в таблицу данные
    if choice=='1':
        choice = input('1) Указать новый приход топлива\n2) Выбрать сущестующий\n')

        # новые данные в таблице 4
        if choice=='1':
            Fuel_Arrival_Date = input('Дата прихода топлива: ')
            Fuel_Arrival_Time = input('Время прихода топлива: ')
            print('Количество топлива: ')
            Fuel_Quantity = num()
            print('Общая стоимость товара: ')
            Total_Cost_of_Goods = num()
            Driver_Supplier = input('Водитель-поставщик: ')
            Invoice_number = input('Номер накладной: ')

            sql.execute("INSERT INTO Fuel_arrival VALUES (NULL,NULL,NULL,?,?,?,?,?,?)", (Fuel_Arrival_Date, Fuel_Arrival_Time, Fuel_Quantity, Total_Cost_of_Goods, Driver_Supplier, Invoice_number))
            # NULL тк первичный ключ - primary key (он сам нумеруется)
            db.commit()     #обязательно прописать после добавления, иначе не сохранится

            # нам нужен Product_code тк он используется в 1, 2 и 7 таблицах, мы его выбираем из только что введенной строки
            Refueling_Code = [value for value in sql.execute(f"SELECT Refueling_Code FROM Fuel_arrival WHERE Fuel_Arrival_Date=='{Fuel_Arrival_Date}' and Fuel_Arrival_Time=='{Fuel_Arrival_Time}' and Fuel_Quantity=='{Fuel_Quantity}' and Total_Cost_of_Goods=='{Total_Cost_of_Goods}' and Driver_Supplier=='{Driver_Supplier}' and Invoice_number=='{Invoice_number}'")][0][0]

            # if sql.fetchone() is None:
            #     print("good")


        #при выборе существующей. Нам нужен только код (выбор существующего нужен в таблицах  3, 4, 5, 6, 8 то есть там где есть primary key)
        elif choice=='2':

            table = 'Fuel_arrival' # название таблицы
            code = 'Refueling_Code'  # только первичный ключ
            sql.execute(f"SELECT '{code}' FROM '{table}'")

            if sql.fetchone() is not None:
                Refueling_Code = existing()

            else:
                print('тут ничего нет')

        else:
            print("Введено некорректное значение")

###
        choice = input('1) Добавить нового сотрудника\n2) Выбрать существующего\n')
        # новые данные в таблице 8
        if choice=='1':
            Surname = input('Фамилия сотрудника: ')
            Name = input('Имя сотрудника: ')
            Patronymic = input('Очество сотркдника: ')
            Phone_number = input('Номер телефона: ')
            Employment_date = input ('Дата приёма на работу: ')
            Hiring_Hours = input('Время приёма на работу: ')

            sql.execute("INSERT INTO Employee VALUES (NULL,?,?,?,?,?,?)", (Surname, Name, Patronymic, Phone_number, Employment_date, Hiring_Hours))
            db.commit()  # обязательно прописать после добавления, иначе не сохранится

            # нам нужен Refueling_code тк он используется в 1, 2 и 7 таблицах, мы его выбираем из только что введенной строки
            Gas_Station_Employee_Code = [value for value in sql.execute(f"SELECT Gas_Station_Employee_Code FROM Employee WHERE Surname=='{Surname}' and Name=='{Name}' and Patronymic =='{Patronymic}' and Phone_number == '{Phone_number}' and Employment_date == '{Employment_date}' and Hiring_Hours == '{Hiring_Hours}'")][0][0]

        elif choice=='2':

            table = 'Employee'  # название таблицы
            code = 'Gas_Station_Employee_Code'  # только первичный ключ
            sql.execute(f"SELECT '{code}' FROM '{table}'")

            if sql.fetchone() is not None:
                Gas_Station_Employee_Code = existing()

            else:
                print('тут ничего нет')


        else:
            print("Введено некорректное значение")




    #изменить данные
    elif choice=='2':
        choice=input('Какую таблицу хотите отредактировать?\n1) Приход топлива\n2) Поставщик\n3) Топливо\n4) Потребитель\n5) Сотрудник\n6) Расход топлива\n7) Название заправки\n')
        if choice=='1': #FUEL_ARRIVAL
            f = True
            table = 'Fuel_arrival'
            code = 'Refueling_Code'  # первичный ключ
            for value in sql.execute(f"SELECT * FROM '{table}'"):
                print(value)

            choice = input(
                'Какой столбец хотите отредактировать?\n1) Дата прихода топлива\n2) Время прихода топлива\n3) Кол-во топлива\n4) Общая стоимость товара\n5) Водитель-поставщик\n6) Номер накладной')
            data = input('Введите код строки (первый столбик): ')
            if choice == '1':
                row = 'Fuel_Arrival_Date'
            elif choice == '2':
                row = 'Fuel_Arrival_Time'
            elif choice == '3':
                row = 'Fuel_Quantity'
            elif choice == '4':
                row = 'Total_Cost_of_Goods'
            elif choice == '5':
                row = 'Driver_Supplier'
            elif choice == '6':
                row = 'Invoice_number'
            else:
                print("Введено некорректное значение! Введите повторно")
                f = False

            if f:
                update(table, row, data, code)

        elif choice=='2':
            pass
        elif choice=='3':
            f=True
            table = 'Fuel_arrival'
            code = 'Refueling_Code' # первичный ключ
            for value in sql.execute(f"SELECT * FROM '{table}'"):
                print(value)

            choice = input('Какой столбец хотите отредактировать?\n1) Название топлива\n2) Единица измерения\n3) Стоимость топлива\n4) Примечание топлива\n')
            data = input('Введите код строки (первый столбик): ')
            if choice == '1':
                row='Product_Name'
            elif choice == '2':
                row='Unit'
            elif choice == '3':
                row='Cost_of_goods'
            elif choice == '4':
                row = 'Note_Item'
            else:
                print("Введено некорректное значение! Введите повторно")
                f=False

            if f:
                update(table, row, data, code)

        elif choice == '4':
            pass
        elif choice == '5':#EMPLOYEE
            f = True
            table = 'Employee'
            code = 'Gas_Station_Employee_Code'
            for value in sql.execute(f"SELECT * FROM '{table}'"):
                print(value)

            choice = input('Какой столбец хотите отредактировать?\n1) Имя сотрудника\n2) Фамилия сотрудника\n3) Отчество сотрудника\n4) Номер телефона\n5) Дата приёма на работу\n6) Время приёма на работу')
            data = input('Введите код строки (первый столбик): ')
            if choice == '1':
                row = 'Surname'
            elif choice == '2':
                row = 'Name'
            elif choice == '3':
                row = 'Patronymic'
            elif choice == '4':
                row = 'Phone_number'
            elif choice == '5':
                row = 'Employment_date'
            elif choice == '6':
                row = 'Hiring_Hours'
            else:
                print("Введено некорректное значение! Введите повторно")
                f = False

            if f:
                update(table, row, data, code)


        elif choice == '6':
            pass
        elif choice == '7':
            f = True
            table = 'Employee'
            code = 'Gas_Station_Employee_Code'
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
    elif choice == '3':
        # должны выводиться данные за определенный день, тут пишет Свят - 1 табл.
        # то есть данные должны каждый раз рассчитываться, записываться в бд и выводится (хотя в теории можно да же не записывать в бд, но наверное лучше записать)

        #пример вывода:
        for value in sql.execute("SELECT * FROM Fuel_arrival"): # * значит, что выбираем все данные из табицы Fuel
            print(value)                                # выводим выбранные данные

        #или так (запихиваем данные из таблицы в переменную)
        for value in sql.execute("SELECT * FROM Employee"):   # выбираем столбик Name_of_Gas_Station из таблицы Name_of_Gas_Station, но только те, где Refueling_code равен одному
            print(value)  # выводим выбранные данные




    #выход
    elif choice == '4':
        exit()

    else:
        print("Введено некорректное значение")
