def problem1():
    n = int(input())
    result = 1
    while n > 0:
        digit = n % 10
        result = result * digit
        n = n // 10
    return result


def problem2():
    s = input()
    sum_odd_positions = 0
    sum_even_positions = 0
    for i in range(len(s)):
        digit = int(s[i])
        if i % 2 == 0:
            sum_odd_positions = sum_odd_positions + digit
        else:
            sum_even_positions = sum_even_positions + digit
    return str(sum_odd_positions) + str(sum_even_positions)


def problem3():
    n = int(input())
    total = 0
    count = 0
    for i in range(n):
        x = int(input())
        if x % 3 == 0:
            total = total + x
            count = count + 1
    if count == 0:
        return -1
    return total / count


def problem4():
    a = int(input())
    prev = 1      # φ1
    current = 1   # φ2
    index = 2
    while current < a:
        temp = current
        current = current + prev
        prev = temp
        index = index + 1
    if current == a:
        return index
    return -1


def problem5():
    n = int(input())
    power = 1
    result = ""
    while power <= n:
        result = result + str(power) + " "
        power = power * 2
    return result.strip()


def problem6():
    n = int(input())
    count = 0
    for i in range(n):
        x = int(input())
        if x > 0:
            count = count + 1
    return count


def problem7():
    maximum = 0
    count = 0
    x = int(input())
    while x != 0:
        if x > maximum:
            maximum = x
            count = 1
        elif x == maximum:
            count = count + 1
        x = int(input())
    return count


class Laptop:
    def __init__(self, brand, model, price):
        self.brand = brand
        self.model = model
        self.price = price
        self.laptop_name = brand + " " + model + " " + price

    def get_laptop_name(self):
        return self.laptop_name


class Promise:
    def __init__(self, id, salary):
        self.id = id
        self.salary = salary
        self.paid = False


class Employee:
    def __init__(self, first_name, second_name, id, salary):
        self.first_name = first_name
        self.second_name = second_name
        self.id = id
        self.promise = Promise(id, salary)

    def check_promises(self):
        return self.promise.paid


def problem8():
    laptop = Laptop("Lenovo", "ThinkPad", "52000")
    return laptop.get_laptop_name()


class Director(Employee):
    pass

class Company:
    def __init__(self, balance):
        self.balance = balance
        self.the_director = None
        self.employees = list()

    def create_director(self, first_name, second_name, Id, salary):
        self.the_director = Director(first_name, second_name, Id, salary)

    def create_employee(self, first_name, second_name, Id, salary):
        employee = Employee(first_name, second_name, Id, salary)
        self.employees.append(employee)

    def director(self):
        return self.the_director

    def set_profit(self, profit):
        self.balance = self.balance + profit

    def fulfill_promise(self):
        # собираем всех сотрудников вместе с директором
        everyone = list()
        if self.the_director is not None:
            everyone.append(self.the_director)
        for employee in self.employees:
            everyone.append(employee)

        # считаем, сколько нужно выплатить
        total_salary = 0
        for person in everyone:
            total_salary = total_salary + person.promise.salary

        # платим всем или никому
        if self.balance >= total_salary:
            self.balance = self.balance - total_salary
            for person in everyone:
                person.promise.paid = True
            return True

        for person in everyone:
            person.promise.paid = False
        return False

def problem9():
    vk = Company(50)
    vk.create_director("Владимир", "Кириенко", 1, 15)
    vk.create_employee("Елена", "Иванова", 2, 8)
    vk.create_employee("Виктор", "Кузнецов", 3, 6)

    vk.set_profit(145.12)
    vk.fulfill_promise()

    director = vk.director()
    print(director.check_promises())  # True

    vk.set_profit(-200)
    vk.fulfill_promise()

    return director.check_promises()  # False


def main():
    while True:
        print("Привет, введи номер задачи!")
        id_problem = int(input())

        if id_problem == 1:
            print("Введи пятизначное число и я найду произведение его цифр!")
            print(problem1())
        elif id_problem == 2:
            print("Введи шестизначное число и я найду суммы его четных и нечетных элементов и образую из этих сумм одно число!")
            print(problem2())
        elif id_problem == 3:
            print("Введи натуральное число, а затем ровно столько же чисел, я найду среднее арифметическое всех чисел, кратных 3, если таких не будет то выведу -1.")
            print(problem3())
        elif id_problem == 4:
            print("Введи натуральное число A больше 1 и я найду, каким по счету числом Фибоначчи оно является, если это не число Фибоначчи, то выведу -1.")
            print(problem4())
        elif id_problem == 5:
            print("Введи число N и я выведу все целые степени двойки, не превосходящие N, в порядке возрастания!")
            print(problem5())
        elif id_problem == 6:
            print("Введи длину последовательности N, а затем столько же целых чисел, и я подсчитаю, сколько среди них положительных!")
            print(problem6())
        elif id_problem == 7:
            print("Вводи натуральные числа по одному, закончи ввод нулем, и я найду, сколько элементов равны наибольшему!")
            print(problem7())
        elif id_problem == 8:
            print(problem8())
        elif id_problem == 9:
            print(problem9())
        else:
            continue  # неверный номер — спрашиваем снова

        break


main()
