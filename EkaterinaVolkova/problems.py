import sys


def problem1():
    n = int(input())
    if n > 0:
        res = 1
    else:
        res = 0
    while n > 0:
        res *= (n % 10)
        n = n // 10
    return res


def problem2():
    n = input()
    sum_odd = 0
    sum_even = 0

    for i in range(len(n)):
        digit = int(n[i])
        if (i + 1) % 2 != 0:
            sum_odd += digit
        else:
            sum_even += digit

    res = int(str(sum_odd) + str(sum_even))
    return res


def problem3():
    n = int(input())
    total = 0
    count = 0
    for _ in range(n):
        x = int(input())
        if x % 3 == 0:
            total += x
            count += 1
    if count == 0:
        return -1
    return total / n


def problem4():
    a = int(input())
    if a == 1:
        return 1
    f1, f2 = 1, 1
    idx = 2
    while f2 < a:
        f1, f2 = f2, f1 + f2
        idx += 1
    return idx if f2 == a else -1


def problem5():
    n = int(input())
    res = []
    power = 1
    while power <= n:
        res.append(str(power))
        power *= 2
    return " ".join(res)


def problem6():
    n = int(input())
    count = 0
    for _ in range(n):
        x = int(input())
        if x > 0:
            count += 1
    return count


def problem7():
    max_val = None
    count = 0
    while True:
        x = int(input())
        if x == 0:
            break
        if max_val is None or x > max_val:
            max_val = x
            count = 1
        elif x == max_val:
            count += 1
    return count


class Laptop:
    def __init__(self, brand, model, price):
        self.brand = brand
        self.model = model
        self.price = price
        self.laptop_name = f"{brand} {model}"

    def get_laptop_name(self):
        return self.laptop_name


class Promise:
    def __init__(self, Id, salary):
        self.Id = Id
        self.salary = salary
        self.fulfilled = False


class Worker:
    def __init__(self, first_name, second_name, Id, salary):
        self.first_name = first_name
        self.second_name = second_name
        self.Id = Id
        self.promise = Promise(Id, salary)

    def check_promises(self):
        return self.promise.fulfilled


class Director(Worker):
    pass


class Employee(Worker):
    pass


class Company:
    def __init__(self, balance=0):
        self.balance = balance
        self._director = None
        self._employees = []

    def create_director(self, first_name, second_name, Id, salary):
        self._director = Director(first_name, second_name, Id, salary)

    def create_employee(self, first_name, second_name, Id, salary):
        self._employees.append(Employee(first_name, second_name, Id, salary))

    def director(self):
        return self._director

    def set_profit(self, amount):
        self.balance += amount

    def fulfill_promise(self):
        workers = [self._director] + self._employees
        total_salary = sum(w.promise.salary for w in workers)
        if self.balance >= total_salary:
            for w in workers:
                w.promise.fulfilled = True
            self.balance -= total_salary
            return True
        for w in workers:
            w.promise.fulfilled = False
        return False


def main():
    if len(sys.argv) < 2:
        print("Использование: python hw.py <номер_задачи>")
        print("Доступные задачи: 1-9")
        return

    task = sys.argv[1]

    if task == "1":
        print(problem1())
    elif task == "2":
        print(problem2())
    elif task == "3":
        print(problem3())
    elif task == "4":
        print(problem4())
    elif task == "5":
        print(problem5())
    elif task == "6":
        print(problem6())
    elif task == "7":
        print(problem7())
    elif task == "8":
        lp = Laptop("Apple", "MacBook Pro", 250000)
        print(lp.brand)
        print(lp.model)
        print(lp.price)
        print(lp.laptop_name)
        print(lp.get_laptop_name())
    elif task == "9":
        vk = Company(balance=50)
        vk.create_director(
            first_name="Владимир",
            second_name="Кириенко",
            Id=1,
            salary=15
        )
        vk.create_employee(
            first_name="Елена",
            second_name="Иванова",
            Id=2,
            salary=8
        )
        vk.create_employee(
            first_name="Виктор",
            second_name="Кузнецов",
            Id=3,
            salary=6
        )
        vk.set_profit(145.12)
        vk.fulfill_promise()
        director = vk.director()
        print(director.check_promises())
        vk.set_profit(-200)
        vk.fulfill_promise()
        print(director.check_promises())
    else:
        print(f"Задача {task} не найдена")


if __name__ == "__main__":
    main()