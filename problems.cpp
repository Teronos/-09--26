#include <iostream>
#include <string>

namespace problem {

    // Задача 1
    long long problem1() {
        long long n;
        std::cin >> n;
        if (n < 0) n = -n;

        long long product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        return product;
    }

    // Задача 2
    long long problem2() {
        long long n;
        std::cin >> n;

        int digits[6];
        for (int i = 5; i >= 0; i--) {
            digits[i] = n % 10;
            n /= 10;
        }

        int sum_odd_pos = 0;
        int sum_even_pos = 0;
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
                sum_odd_pos += digits[i];
            }
            else {
                sum_even_pos += digits[i];
            }
        }
        std::string glued = std::to_string(sum_odd_pos) + std::to_string(sum_even_pos);
        return std::stoll(glued);
    }

    // Задача 3
    double problem3() {
        int n;
        std::cin >> n;

        long long sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            if (x % 3 == 0) {
                sum += x;
                count++;
            }
        }

        if (count == 0) return -1;
        return (double)sum / count;
    }

    // Задача 4
    int problem4() {
        long long a;
        std::cin >> a;

        long long prev = 1;
        long long cur = 1;
        int index = 2;

        while (cur < a) {
            long long next = prev + cur;
            prev = cur;
            cur = next;
            index++;
        }

        if (cur == a) return index;
        return -1;
    }

    // Задача 5
    std::string problem5() {
        long long n;
        std::cin >> n;

        std::string result = "";
        for (long long p = 1; p <= n; p *= 2) {
            if (p != 1) result += " ";
            result += std::to_string(p);
        }
        return result;
    }

    // Задача 6
    int problem6() {
        int n;
        std::cin >> n;

        int count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (x > 0) count++;
        }
        return count;
    }

    // Задача 7
    int problem7() {
        int x;
        std::cin >> x;

        int max_value = 0;
        int count = 0;
        while (x != 0) {
            if (x > max_value) {
                max_value = x;
                count = 1;
            }
            else if (x == max_value) {
                count++;
            }
            std::cin >> x;
        }
        return count;
    }

    // Задача 8
    class Laptop {
    public:
        std::string brand;
        std::string model;
        double price;

        Laptop(std::string brand_, std::string model_, double price_) {
            brand = brand_;
            model = model_;
            price = price_;
            name_ = brand + " " + model;
        }

        std::string laptop_name() const {
            return name_;
        }

    private:
        std::string name_;
    };

    std::string problem8() {
        std::string brand, model;
        double price;
        std::cin >> brand >> model >> price;

        Laptop laptop(brand, model, price);
        return laptop.laptop_name();
    }

    // Задача 9

    class Promise {
    public:
        long long id;
        double salary;
        bool paid;

        Promise() {
            id = 0;
            salary = 0;
            paid = false;
        }

        Promise(long long id_, double salary_) {
            id = id_;
            salary = salary_;
            paid = false;
        }
    };

    class Employee {
    public:
        std::string first_name;
        std::string second_name;
        long long id;
        Promise promise;

        Employee() {
            id = 0;
        }

        Employee(std::string first, std::string second, long long id_, double salary) {
            first_name = first;
            second_name = second;
            id = id_;
            promise = Promise(id_, salary);
        }

        bool check_promises() const {
            return promise.paid;
        }
    };

    class Director : public Employee {
    public:
        Director() {}

        Director(std::string first, std::string second, long long id_, double salary)
            : Employee(first, second, id_, salary) {
        }
    };

    class Company {
    public:
        Company(double balance_) {
            balance = balance_;
            employee_count = 0;
        }

        void create_director(std::string first, std::string second, long long id, double salary) {
            director_ = Director(first, second, id, salary);
        }

        void create_employee(std::string first, std::string second, long long id, double salary) {
            if (employee_count < MAX_EMPLOYEES) {
                employees[employee_count] = Employee(first, second, id, salary);
                employee_count++;
            }
        }

        Director& director() {
            return director_;
        }

        void set_profit(double profit) {
            balance += profit;
        }

        bool fulfill_promise() {
            double total = director_.promise.salary;
            for (int i = 0; i < employee_count; i++) {
                total += employees[i].promise.salary;
            }

            if (balance >= total) {
                balance -= total;
                director_.promise.paid = true;
                for (int i = 0; i < employee_count; i++) {
                    employees[i].promise.paid = true;
                }
                return true;
            }

            director_.promise.paid = false;
            for (int i = 0; i < employee_count; i++) {
                employees[i].promise.paid = false;
            }
            return false;
        }

    private:
        static const int MAX_EMPLOYEES = 100;

        double balance;
        Director director_;
        Employee employees[MAX_EMPLOYEES];
        int employee_count;
    };

    std::string problem9() {
        auto vk = Company(50);
        vk.create_director("Владимир", "Кириенко", 1, 15);
        vk.create_employee("Елена", "Иванова", 2, 8);
        vk.create_employee("Виктор", "Кузнецов", 3, 6);

        vk.set_profit(145.12);
        vk.fulfill_promise();

        auto& director = vk.director();
        std::string result = director.check_promises() ? "true" : "false";

        vk.set_profit(-200);
        vk.fulfill_promise();

        result += "\n";
        result += director.check_promises() ? "true" : "false";
        return result;
    }
}

using namespace problem;

int main() {
    auto run_problem = [](this auto&& self) -> void
        {
            unsigned id_problem;
            std::cin >> id_problem;

            switch (id_problem) {
            case 1:
                std::cout << problem1();
                break;

            case 2:
                std::cout << problem2();
                break;

            case 3:
                std::cout << problem3();
                break;

            case 4:
                std::cout << problem4();
                break;

            case 5:
                std::cout << problem5();
                break;

            case 6:
                std::cout << problem6();
                break;

            case 7:
                std::cout << problem7();
                break;

            case 8:
                std::cout << problem8();
                break;

            case 9:
                std::cout << problem9();
                break;

            default:
                self();
            }
        };

    run_problem();
}
