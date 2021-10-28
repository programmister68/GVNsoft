import sys # Импортирование модуля (подключение библиотеки) sys

from PyQt5.QtCore import pyqtSlot # Импортирование модуля (подключение библиотеки) pyqtSlot
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QLineEdit, QButtonGroup, QLabel # Импортирование модуля (подключение библиотеки) pyqtSlot


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__() # Возвращает объект родительского класса, который делегирует вызовы методов родительскому или одноуровневому класс типа
        self.btn_group = QButtonGroup() # Класс предоставляющий контейнер для организации кнопок виджетов
        self.btn_list = [] # Список кнопок
        self.label = QLabel(self) # Отбражение текста или изображения
        self.label.move(100, 20) # Позиционирование текста (или изображения) в окне
        for i in range(9): # Цикл, создающий девять кнопок 
            self.btn_list.append(QPushButton(self)) # Передача аргументов с сигналами
            self.btn_group.addButton(self.btn_list[-1], i) # Добавление кнопки
            self.btn_list[-1].move((i % 3 * 100) + 100, (i // 3 * 100) + 100)
        self.counter = 0
        self.restart_button = QPushButton("Restart", self) # Добавление кнопки "Новая игра"
        self.restart_button.move(200, 500) # Позиционирование кнопки "Новая игра" в окне

	# Привязка сигнала (действия) к кнопке
        self.restart_button.clicked.connect(self.restart_game) 
        self.btn_group.buttonClicked[int].connect(self.btn_clicked)

    @pyqtSlot(int) # Декоратор слотов (нужны для того, чтобы принимать сигналы). При этом декоратор снижает потребление памяти и ускоряет работу слотов. Не связывает, а производит обработку нажатия.
    def btn_clicked(self, value): # Блокировка повторного нажатия кнопки
        if self.btn_list[value].text() != '': # Проверка пустого ввода
            return
        self.btn_list[value].setText('x' if self.counter % 2 == 0 else 'o') # Определяет, кто сейчас ходит крестик или нолик
        self.counter += 1

        if self.is_winner():  # Условие завершения игры
            self.label.setText(f"Победил {self.is_winner()} !")
            for button in self.btn_list:
                button.setDisabled(True) # Блокировка кнопок


    def is_winner(self): # Условия победы в игре
        self.values = [i.text() for i in self.btn_list]  # Генератор, проходящийся по всем кнопкам. Считывает данные с кнопок и сохраняет их в массив данных 
        for i in range(0, 9, 3):
            if self.values[i] == self.values[i + 1] == self.values[i + 2]: // Сравнение значений, записанных в кнопках (по горизонтали)
                return self.values[i]
        for i in range(3):
            if self.values[i] == self.values[i + 3] == self.values[i + 6]: // Сравнение значений, записанных в кнопках (по вертикали)
                return self.values[i]
        if self.values[0] == self.values[4] == self.values[8]: // Сравнение значений, записанных в кнопках (по главной диагонали)
            return self.values[4]
        if self.values[2] == self.values[4] == self.values[6]: // Сравнение значений, записанных в кнопках (по побочной диагонали)
            return self.values[4]
        return False

    def restart_game(self): # Запуск новой игры
        for btn in self.btn_list:
            btn.setEnabled(True) # Разблокировка кнопок
            btn.setText('') # Сброс значений в кнопках
        self.counter = 0 # Обнуление счётчика
        self.label.setText('') # Сброс надписи "Победил {self.is_winner()} !"

if __name__ == '__main__':
    qapp = QApplication(sys.argv) # Класс, управляющий потоком управления и основными настройками приложения с графическим интерфейсом.
    window = MainWindow() # Создание главное окно приложения 
    window.setWindowTitle("Tic Tac Toe") # Заголовок окна
    window.resize(600, 600) # Установка размера отображаемого окна
    window.show() # Вывести окно на экран
    sys.exit(qapp.exec()) # Закрытие программы
