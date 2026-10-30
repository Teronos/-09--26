from functools import reduce


def task_1():
    num = input()
    return reduce(lambda x, y: int(x) * int(y), num)

def task_2():
    num = input()
    return str(sum([int(num[i]) for i in range(0, len(num), 2)])) + str(sum([int(num[i]) for i in range(1, len(num), 2)]))

def task_3():
    n = int(input())
    nums = [int(input()) for i in range(n)]
    nums3 = [i for i in nums if not i % 3]

    if not len(nums3):
        return -1

    return sum(nums3) / len(nums3)

def task_4():
    num = int(input())

    if not ((5 * num**2 + 4)**0.5).is_integer() and not ((5 * num**2 - 4)**0.5).is_integer():
        return -1

    counter = 1

    a, b = 0, 1
    while True:
        a, b = b, a + b
        if a == num:
            return counter + 1
        
        counter += 1

def task_5():
    num = bin(int(input()))[2:]
    result = ''
    for i, _ in enumerate(num[::-1]):
            result += str(2**i) + " "
            
    return result.rstrip()

def task_6():
    n = int(input())
    
    return len(list(filter(lambda x: x > 0, [int(input()) for i in range(n)])))

def task_7():
    seq = []

    n = None

    while n != 0:
        n = int(input())
        seq.append(n)

    return seq.count(max(seq))

def task_8():
    class Laptop:
        def __init__(self, brand: str, model: str, price: int) -> None:
            self.brand = brand
            self.model = model
            self.price = price
            self.laptop_name = f"{self.brand} {self.model}"

def task_9():
    class Promise:
        def __init__(self, id: int, salary: float):
            self.id = id
            self.salary = salary
            self._is_fulfilled = False
        
        def is_fulfilled(self) -> bool:
            return self._is_fulfilled
        
        def set_fulfilled(self, fill: bool) -> None:
            self._is_fulfilled = fill
        
        def get_salary(self) -> float:
            return self.salary


    class Person:
        def __init__(
            self,
            first_name: str,
            second_name: str,
            id: int,
            salary: float
        ):
            self.first_name = first_name
            self.second_name = second_name
            self.id = id
            self.salary = salary
            self.promise = Promise(id, salary)
        
        def is_fulfilled(self) -> bool:
            return self.promise.is_fulfilled()
        
        def set_fulfilled(self, fill: bool) -> None:
            self.promise.set_fulfilled(fill)
        
        def get_salary(self) -> float:
            return self.promise.get_salary()


    class Director(Person):
        def __init__(
            self,
            first_name: str,
            second_name: str,
            id: int,
            salary: float
        ):
            super().__init__(first_name, second_name, id, salary)
            self._company = None
        
        def check_promises(self) -> bool:
            if not self._company:
                return False
            return self._company.check_all_promises()

        def set_company(self, company: 'Company') -> None:
            self._company = company


    class Employee(Person):
        def __init__(
            self,
            first_name: str,
            second_name: str,
            id: int,
            salary: float
        ):
            super().__init__(first_name, second_name, id, salary)


    class Company:
        def __init__(self, balance: float):
            self.balance = balance
            self._director = None
            self._employees = []

        def create_director(self, first_name: str, second_name: str, id: int, salary: float) -> None:
            if self._director is not None:
                return
            
            self._director = Director(first_name, second_name, id, salary)
            self._director.set_company(self)
        
        def create_employee(self, first_name: str, second_name: str, id: int, salary: float) -> None:
            emp = Employee(first_name, second_name, id, salary)
            self._employees.append(emp)
        
        def set_profit(self, profit: float) -> None:
            self.balance += profit
            
            if self._director:
                self._director.set_fulfilled(False)
            
            for emp in self._employees:
                emp.set_fulfilled(False)

        def fulfill_promise(self) -> bool:
            unpaid = []
            
            if self._director and not self._director.is_fulfilled():
                unpaid.append(self._director)
            
            for emp in self._employees:
                if not emp.is_fulfilled():
                    unpaid.append(emp)
            
            if not unpaid:
                return True
            
            total_needed = sum(p.get_salary() for p in unpaid)
            
            if self.balance >= total_needed:
                self.balance -= total_needed
                for p in unpaid:
                    p.set_fulfilled(True)
                return True

            return False
        
        def director(self) -> Director:
            return self._director
        
        def check_all_promises(self) -> bool:
            if self._director and not self._director.is_fulfilled():
                return False
            for emp in self._employees:
                if not emp.is_fulfilled():
                    return False
            return True


    vk = Company(balance=50)

    vk.create_director(
        first_name="Владимир",
        second_name="Кириенко",
        id=1,
        salary=15
    )

    vk.create_employee(
        first_name="Елена",
        second_name="Иванова",
        id=2,
        salary=8
    )

    vk.create_employee(
        first_name="Виктор",
        second_name="Кузнецов",
        id=3,
        salary=6
    )

    vk.set_profit(145.12)
    print(f"Первая выплата: {vk.fulfill_promise()}")

    director = vk.director()
    print(f"Проверка обещаний: {director.check_promises()}")

    vk.set_profit(-200)
    print(f"Вторая выплата: {vk.fulfill_promise()}")

    print(f"Проверка обещаний: {director.check_promises()}")

if __name__ == "__main__":
    problem = int(input())

    if problem in (1, 9):    

        match problem:
            case 1:
                print(task_1())
            case 2:
                print(task_2())
            case 3:
                print(task_3())
            case 4:
                print(task_4())
            case 5:
                print(task_5())
            case 6:
                print(task_6())
            case 7:
                print(task_7())        
            case 8:
                task_8()
            case 9:
                task_9()
