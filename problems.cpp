#include <iostream>
#include <string>
#include <vector>


//Задача 1
//Дано пятизначное число. Найдите произведение его цифр.
//Пример ввода:
//14962
//Пример вывода:
//432
unsigned problem1() {
    unsigned a;
    std::cout << "Введите пятизначное число" << std::endl;
    std::cin >> a;
    unsigned p = 1;
    for (int i = 0; i < 5; i++) {   // цикл 5 раз
      unsigned c = a % 10;     // остаток от деления
      p = p * c;
      a = a / 10;     // минус последнюю цифру
    }
    return p;
}

//Задача 2
//Дано шестизначное число. Найдите суммы его четных и нечетных элементов. Образуйте из них этих сумм одно число и выведите его на экран
//Пример ввода:
//531893
//Пример вывода:
//1514

unsigned problem2() {
    unsigned a;
    std::cout << "Введите шестизначное число" << std::endl;
    std::cin >> a;
    unsigned sumH = 0;  //четные
    unsigned sumN = 0;   // нечетных
    for (int i = 0; i < 6; i++) {
        unsigned c = a % 10;  // остаток
        if (i % 2 == 0) {
            sumH = sumH + c;
        } else {
            sumN = sumN + c;
        }
        a = a / 10;
    }
    unsigned shift = 100;
    if (sumH < 10) {
      shift = 10;
    }
    return sumN * shift + sumH;
}

//Задача 3
//Вводится натуральное число N, а затем N чисел. Найти среднее арифметическое всех чисел кратных 3. Если таких чисел нет, то вывести −1
//Пример ввода:
//6
//6
//3
//2
//42
//5
//12
//Пример вывода:
//10.5

double problem3() {
    int n;
    std::cout << "Введите количество чисел" << std::endl;
    std::cin >> n;
    int sum = 0;   // суммы чисел которые делятся на 3
    int count = 0;     // сколько чисел нашли
    for (int i = 0; i < n; i++) {
        int x;
        std::cout << "Введите чило " << i+1 << ":" << std::endl;
        std::cin >> x;    // читаем очередное число
        if (x % 3 == 0) {    // если остаток равен 0 то число кратно 3
            sum = sum + x;
            count = count + 1;
        }
    }
    if (count == 0) {   //  есликратных 3 не было
        return -1;
    }
    return (double)sum / count;      //  дабл для того чтобы деление было дробным а не целым
}

//Задача 4
//Дано натуральное число A>1. Определите, каким по счету числом Фибоначчи оно является, то есть выведите такое число n,что φn=A. Если Ане является числом Фибоначчи, выведите число −1.
//Пример ввода:
//8
//Пример вывода:
//6

int problem4() {
    int a;
    std::cout << "Ввендите натуральное число" << std::endl;
    std::cin >> a;
    int prev = 1;   // 1 число Фибоначчи
    int cur = 1;      // 2 чс
    int n = 2;     // номер числа ейчас
    while (cur < a) {    //    меньше а идем дальше
        int next = prev + cur;   // новое число сумма 2 предыдущих
        prev = cur;       // редыдушее становится на место нового
        cur = next;
        n = n + 1;
    }
    if (cur == a) {    //дошли до а нашли
        return n;
    }
    return -1;    // ушли за а значит его нет среди чисел фибоначи
}

// Задача 5
//По данному числу N распечатайте все целые значения степени двойки, не превосходящие N, в порядке возрастания.
//Пример ввода:
//50
//Пример вывода:
//1 2 4 8 16 32

void problem5() {
    int n;
    std::cout << "Ввендите натуральное число" << std::endl;
    std::cin >> n;
    int p = 1;         // первая степень двойки 0
    while (p <= n) {      // пока степень не больше н
        std::cout << p << " ";   // печатаем ее
        p = p * 2;     // следующая степень двойки
    }
}

//Задача 6
//Сначала на вход поступает длина последовательности N. Затем элементы последовательности – целые числа. Напишите программу, которая подсчитывает количество положительных чисел среди элементов последовательности.
//Пример ввода:
//5
//1
//2
//3
//-1
//-4
//Пример вывода:
//3

int problem6() {
    int n;
    std::cout << "Ввендите количество чисел" << std::endl;
    std::cin >> n;
    int count = 0;               // считаем положительные чисела
    for (int i = 0; i < n; i++) {
        int x;
        std::cout << "Введите чило " << i+1 << ":" << std::endl;
        std::cin >> x;
        if (x > 0) {   // положительное число
            count = count + 1;
        }
    }
    return count;
}

//Задача 7
// Последовательность состоит из натуральных чисел и завершается числом 0. Определите количество элементов этой последовательности, которые равны ее наибольшему элементу.
//Пример ввода:
//1
//3
//3
//1
//0
//Пример вывода:
//2
//
int problem7() {
    int x;
    std::cin >> x;    // первое число
    int max = 0;    // наибольшее число
    int count = 0;
    while (x != 0) {          // сколько раз встретилось наибольшее пока не пришел 0
        if (x > max) {     // новое наибольшее
            max = x;
            count = 1;
        } else if (x == max) {   // нашли такое же, как наибольшее
            count = count + 1;
        }
        std::cout << "Введите чила, введите 0 чтобы завершить ввод" << ":" << std::endl;
        std::cin >> x;   // след число
    }
    return count;
}

//Задача 8
//Создайте класс Laptop, у которого есть:
//Конструктор, принимающий 3 аргумента: бренд, модель и цену ноутбука. На основании этих аргументов нужно для экземпляра создать атрибуты brand, model, price и также атрибут laptop_name — строковое значение, следующего вида: «brand model»
//Метод laptop_name возвращающий аналогичное значение поля.

class Laptop {

public:
    std::string brand; // бренд
    std::string model; // модель
    double price;      // цена
    std::string name;

    // конструктор
    Laptop(std::string b, std::string m, double p) {
        brand = b;
        model = m;
        price = p;
        name = brand + " " + model;
    }

    std::string laptop_name() {// по этой строке возвращаем laptop_name
        return name;
    }
};


std::string problem8() {   // ф-я для проверки /читаем данные ноутбука и выводим его имя
    std::string brand, model;
    double price;
    std::cin >> brand >> model >> price;
    Laptop laptop(brand, model, price);   // создаем ноутбук
    return laptop.laptop_name();
}

// Задача 9.
//Нужно создать функционал для упрошенного описания экономических отношений между работодателем, работником и компанией.
//Нужно реализовать классы Director, Employee, Company, Promise.

// Promise - обещание зарплаты
class Promise {
    public:
        unsigned id;     // снилс
        double salary;    // размер зарплаты
        bool paid;       // начислили или нет

        Promise() {        // пустой конструктор
            id = 0;
            salary = 0;
            paid = false;
        }

        Promise(unsigned i, double s) {
            id = i;
            salary = s;
            paid = false;    // сначала зарплату еще не платили
        }
    };

// создаем Worker это общий класс для работника /наследуются директор и обычный работник

class Worker {
public:
    std::string first_name;    // имя
    std::string second_name;   // фамилия
    unsigned id;                // снилс
    Promise promise;      // контракт

    Worker() {
        id = 0;
    }

    Worker(std::string f, std::string s, unsigned i, double salary) {
        first_name = f;
        second_name = s;
        id = i;
        promise = Promise(i, salary);   // создаем контракт работника
    }


    bool check_promises() {  ///правда если зарплата начислена
        return promise.paid;
    }
};

class Director : public Worker {
public:
    Director() {}
    Director(std::string f, std::string s, unsigned i, double salary) : Worker(f, s, i, salary) {}
};

class Employee : public Worker {
public:
    Employee(std::string f, std::string s, unsigned i, double salary) : Worker(f, s, i, salary) {}
};

class Company {
    private:
        double balance;
        Director main_director;        // 1 директор
        bool has_director;         // есть ли уже директор
        std::vector<Employee> employees;   // работнички

public:
    Company(double start_balance) {
        balance = start_balance;
        has_director = false;
    }

    // наш директор
    void create_director(std::string f, std::string s, unsigned id, double salary) {
        main_director = Director(f, s, id, salary);
        has_director = true;
    }

    // добавляем работника в список
    void create_employee(std::string f, std::string s, unsigned id, double salary) {
        employees.push_back(Employee(f, s, id, salary));
    }

    // возвращаем директора
    Director& director() {      // по амперсанту передаем самого работника а не его копию
        return main_director;
    }

    // прибыль за количество времени / прибавляем ее к балансу / может быть в убытке
    void set_profit(double profit) {
        balance = balance + profit;


    // начался новый период / зарплаты  опять невыплаченны
    main_director.promise.paid = false;
    for (int i = 0; i < employees.size(); i++) {
        employees[i].promise.paid = false;
    }
}

    // пытаемся выплатить зарплату всем
    // денег хватает /платим и возвращаем правду
    // иначе никому не платим и возвращаем ложь
    bool fulfill_promise() {
        double total = 0;     //  всего заплатить
        if (has_director) {
            total = total + main_director.promise.salary;
        }
        for (int i = 0; i < employees.size(); i++) {
            total = total + employees[i].promise.salary;
        }

        if (balance < total) {         // если денег не хватает
            return false;
        }

        balance = balance - total;  // вычитаем зарплаты из баланса
        if (has_director) {
            main_director.promise.paid = true;  //  директору заплатили
        }

        for (int i = 0; i < employees.size(); i++) {
            employees[i].promise.paid = true;  // работнику заплатили
        }
        return true;
    }
};

// проверка
void problem() {
    auto vk = Company(50);
    vk.create_director("Vladimir", "Kirienko", 1, 15);
    vk.create_employee("Elena", "Ivanova", 2, 8);
    vk.create_employee("Viktor", "Kuznetsov", 3, 6);

    vk.set_profit(145.12);
    vk.fulfill_promise();

    auto& director = vk.director();
    std::cout << std::boolalpha << director.check_promises() << std::endl;   // правда

    vk.set_profit(-200);
    vk.fulfill_promise();

    std::cout << std::boolalpha << director.check_promises() << std::endl;   // ошибка
}
void problem9() {
    Company vk(50);
    vk.create_director("Vladimir", "Kirienko", 1, 15);
    vk.create_employee("Elena", "Ivanova", 2, 8);
    vk.create_employee("Viktor", "Kuznetsov", 3, 6);

    vk.set_profit(145.12);
    vk.fulfill_promise();

    auto& director = vk.director();
    std::cout << std::boolalpha << director.check_promises() << std::endl;   // true (правда)

    vk.set_profit(-200);
    vk.fulfill_promise();

    std::cout << std::boolalpha << director.check_promises() << std::endl;   // false (зарплата не начислена, т.к. денег нет)
}




int main() {
    unsigned id_problem;
    std::cin >> id_problem;

    switch (id_problem) {
    case 1:
        std::cout << problem1() << std::endl;
        break;

    case 2:
        std::cout << problem2() << std::endl;
        break;

    case 3:
        std::cout << problem3() << std::endl;
        break;

    case 4:
        std::cout << problem4() << std::endl;
        break;

    case 5:
        problem5();
        break;

    case 6:
        std::cout << problem6() << std::endl;
        break;

    case 7:
        std::cout << problem7() << std::endl;
        break;

    case 8:
        std::cout << problem8() << std::endl;
        break;

    case 9:
        problem9();
        break;

    default:
        std::cout << "Неверный номер задачи" << std::endl;
        break;
    }

    return 0;
}