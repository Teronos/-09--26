print("Выбери задачу:")
print("1 - Произведение цифр")
print("2 - Суммы четных и нечетных цифр")
print("3 - Среднее арифметическое чисел, кратных 3")
print("4 - Число Фибоначчи")
print("5 - Степени двойки")
print("6 - Количество положительных чисел")
print("7 - Количество максимальных элементов")
print("8 - Класс Laptop")

n = int(input("Номер задачи: "))

if n == 1:
    a = int(input("Введите пятизначное число: "))
    p = 1

    while a > 0:
        p = p * (a % 10)
        a = a // 10

    print(p)

elif n == 2:
    a = input("Введите шестизначное число: ")
    chet = 0
    nechet = 0

    for i in range(6):
        c = int(a[i])

        if (i + 1) % 2 == 0:
            chet = chet + c
        else:
            nechet = nechet + c

    print(str(nechet) + str(chet))

elif n == 3:
    N = int(input("Введите количество чисел: "))
    s = 0
    k = 0

    for i in range(N):
        a = int(input())

        if a % 3 == 0:
            s = s + a
            k = k + 1

    if k > 0:
        print(s / k)
    else:
        print(-1)

elif n == 4:
    A = int(input("Введите число: "))
    a = 1
    b = 1
    k = 2

    while b < A:
        c = a + b
        a = b
        b = c
        k = k + 1

    if b == A:
        print(k)
    else:
        print(-1)

elif n == 5:
    N = int(input("Введите N: "))
    a = 1

    while a <= N:
        print(a, end=" ")
        a = a * 2

    print()

elif n == 6:
    N = int(input("Введите количество чисел: "))
    k = 0

    for i in range(N):
        a = int(input())

        if a > 0:
            k = k + 1

    print(k)

elif n == 7:
    a = int(input())
    maximum = a
    k = 1

    while a != 0:
        a = int(input())

        if a > maximum:
            maximum = a
            k = 1
        elif a == maximum and a != 0:
            k = k + 1

    print(k)

elif n == 8:
    class Laptop:
        def __init__(self, brand, model, price):
            self.brand = brand
            self.model = model
            self.price = price
            self.laptop_name = brand + " " + model

        def get_laptop_name(self):
            return self.laptop_name

    laptop = Laptop("Acer", "Aspire", 50000)
    print(laptop.get_laptop_name())

else:
    print("Такой задачи нет")
