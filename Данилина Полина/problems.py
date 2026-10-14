def problem1():
    chisla = int(input())
    posled = 1
    while chisla > 0:
        last = chisla % 10
        posled *= last
        chisla = chisla // 10
    print(posled)


def problem2():
    chis = str(input())
    sn = 0
    sch = 0
    for el in range(0, len(chis), 2):
        sch += int(chis[el])
    for el1 in range(1, len(chis), 2):
        sn += int(chis[el1])
    print(str(sch) + str(sn))


def problem3():
    N = int(input())
    Nch = 0
    sred = 0
    col = 0
    while Nch != N:
        num = int(input())
        Nch += 1
        if num % 3 == 0:
            sred += num
            col += 1
    if col == 0:
        print(-1)
    else:
        sred = sred / col
        print(sred)


def problem4():
    A = int(input())
    ac = 1
    f1 = 0
    f2 = 1
    f = 0
    while f < A:
        f = f1 + f2
        f1 = f2
        f2 = f
        ac += 1
    if f == A:
        print(ac)
    else:
        print(-1)


def problem5():
    N = int(input())
    stepen = 1
    num = 2
    print(1)
    while num <= N:
        num = 2 ** stepen
        stepen += 1
        if num <= N:
            print(num)


def problem6():
    N = int(input())
    n = 0
    col = 0
    while n != N:
        el = int(input())
        n += 1
        if el >= 0:
            col += 1
    print(col)


def problem7():
    n = 10000000000
    coli = 0
    max_ = -100000
    while n != 0:
        elem = int(input())
        n = elem
        if elem > max_:
            coli = 0
            max_ = elem
        if elem == max_:
            coli += 1
    print(coli)


class Laptop:
    def __init__(self, brand, model, price):
        self.brand = brand
        self.model = model
        self.price = price
        self.laptop_name = brand + " " + model


class Promise:
    def __init__(self, snils, zp):
        self.snils = snils
        self.zp = zp
        self.zp_paid = False


class Director:
    def __init__(self, name, surname, snils, promise):
        self.name = name
        self.surname = surname
        self.snils = snils
        self.promise = promise


class Employee:
    def __init__(self, name, surname, snils, promise):
        self.name = name
        self.surname = surname
        self.snils = snils
        self.promise = promise


class Company:
    def __init__(self):
        self.profit = 0.0
        self.director = None
        self.employees = []

    def set_profit(self, amount):
        self.profit = amount

    def full_promise(self):
        total_needed = 0.0
        if self.director is not None:
            total_needed += self.director.promise.zp
        for el in self.employees:
            total_needed += el.promise.zp
        if self.profit >= total_needed:
            if self.director is not None:
                self.director.promise.zp_paid = True
            for el in self.employees:
                el.promise.zp_paid = True
            self.profit -= total_needed
            return True
        else:
            return False
