#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

namespace math{
    unsigned sqr(int x){
        return x*x;
    }

    vector<unsigned> fibonacci(unsigned n){
        if (n == 0){
            return {};
        }
        vector<unsigned> fib(n, 0);

        fib[0] = 0;

        if (n > 1){
            fib[1] = 1;
        }

        for (unsigned i = 2; i < n; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        // Output

        // for (unsigned i = 0; i < n; i++){
        //     cout << fib[i] << " ";
        // }

        return fib;
    }

    int exp(int number, int exp){
        int result {1};
        for (unsigned i = 0; i < exp; i++){
            result *= number;
        }
        return result;
    }
}

namespace classes{
    class Laptop{
        string brand;
        string model;
        double price;
        string laptop_name;

    public:
        Laptop(const string& _brand, const string& _model, double _price) :
        brand(_brand), model(_model), price(_price){
            this -> laptop_name = brand + " - " + model;
        }

        string get_laptop_name() const {return laptop_name;}
        string get_brand() const { return brand; }
        string get_model() const { return model; }
        double get_price() const { return price; }
    }; 

    //============================================

    class Company{
        string title;
        double fund;


        void get_revenue(){

        }

    };
    class Employee{
        string name;
    };
    class Director{
        string name;
    };
    class Promise{

    };
}

namespace company_classes{//ДЕСТРУКТОР + ЧЕК ПРОМИСЕС

    class Company;
    class Promise{
        unsigned employee_id;
        bool salary_sent;
    public: 
        float salary;
        Promise(const unsigned _employee_id, const float _salary):
        employee_id(_employee_id), salary(_salary){
            cout << "Promise created:\nid: " << employee_id << ".\n";
        };
    };
    class Employee{
        string name;
        string surname;
        unsigned id;

    public: 
        Promise promise;
        Employee(const string& _name, const string& _surname, unsigned _id, float _salary): 
        name(_name), surname(_surname), id(_id), promise(id, _salary){
            cout << "Employee created:\n" << name << " " << surname << ".\n";
        };
        virtual ~Employee() = default;
    };
    class Director: public Employee{
    public:
        using Employee::Employee;
        bool check_promises(const Company& company);
        Director();
    };
    class Company{
        string title;
        float profit;
        friend class Director;
    public:
        Director* director {nullptr};
        vector<Employee*> employees;
        void set_profit(float revenue){
            profit += revenue;
        };
        void create_employee(const string& name, const string& surname, unsigned id, float salary){
            Employee* employee = new Employee(name, surname, id, salary);
            employees.push_back(employee);
        };
        void create_director(const string& name, const string& surname, unsigned id, float salary){
            if (director == nullptr){
                Director* _director = new Director(name, surname, id, salary);
                employees.push_back(_director);
                director = _director;
                cout << "Director created:\n" << name << " " << surname << ".\n";
            } else {
                cout << "Director already exists\n";
            };
        };
        bool fulfill_promise(){
            unsigned total_salary = 0.0f;
            for(auto employee : employees){
                total_salary += employee->promise.salary;
            };
            if (profit >= total_salary){
                profit -= total_salary;
                return true;
            } else return false;
        };

        //Конструктор
        explicit Company(const float _profit): profit(_profit){};

        // Деструктор
        ~Company(){
            for (auto * employee : employees) delete employee;
        }
    };
    
    bool Director::check_promises(const Company& company){
        float total_salary = 0.0f;
        for (const auto* employee : company.employees){
            total_salary += employee->promise.salary;
        }
        return company.profit >= total_salary;
    }
}

using namespace math;
using namespace classes;
using namespace company_classes;

namespace problems {
    // Задача 1
    unsigned problem_1(){

        cout << "Задача 1.\nДано пятизначное число. "
        "Найдите произведение его цифр.\n\nВвод: ";

        unsigned number;
        unsigned num_mul;
        num_mul = 1;

        cin >> number;

        for (int i = to_string(number).length(); i > 0; i--){
            num_mul *= number%10;
            number /= 10;
        }

        return num_mul;
    }

    // Задача 2
    string problem_2(){

        cout << "Задача 2.\nДано шестизначное число. \n"
        "Найдите суммы его четных и нечетных элементов. \n"
        "Образуйте из них этих сумм одно число и выведите его на экран\n\n"
        "Ввод: ";
        
        unsigned number;
        unsigned num_sum_1 {0}, num_sum_2 {0};

        cin >> number;

        for (int i = to_string(number).length(); i > 0; i--){
            if(i%2 != 0){
                num_sum_1 += number%10;
            } else {
                num_sum_2 += number%10;
            }
            number /= 10;
        }
        string result {to_string(num_sum_1) + to_string(num_sum_2)};
        return result;
    }

    // Задача 3
    double problem_3(){

        cout << "Задача 3\nВводится натуральное число N, а затем N чисел. "
        "Найти среднее арифметическое всех чисел кратных 3. "
        "Если таких чисел нет, то вывести −1\n\n"
        "Ввод: ";
        
        unsigned num_amount;
        unsigned num_sum {0};
        unsigned num;
        unsigned counter {0};

        cin >> num_amount;

        for (int i = 0; i < num_amount; i++){
            
            cout << "Число " << i+1 << ": ";
            cin >> num;
            if (num % 3 == 0){
                num_sum += num;
                counter++;
            }
        }

        int result = (counter == 0) ? -1 : (num_sum / counter);
        return result;

    }

    // Задача 4
    int problem_4(){

        cout << "Задача 4.\nДано натуральное число A>1.\n "
        "Определите, каким по счету числом Фибоначчи оно является,\n "
        "то есть выведите такое число n, что φ_n=A.\n "
        "Если А не является числом Фибоначчи, выведите число −1.\n\n"
        "Ввод: ";

        unsigned num;
        cin >> num;
        int result {-1};


        //Захардкодил количество чисел в ряде:
        auto fib = fibonacci(10);

        //for (unsigned i : fib) result = (num == fib[i]) ? i : -1;
        for (unsigned i = 0; i < fib.size(); i++){
            if (fib[i] == num){
                return i+1;
            }
        }

        return result;

    }

    // Задача 5
    string problem_5(){
        cout << "Задача 5.\nПо данному числу N распечатайте все целые значения степени двойки, \n"
        "не превосходящие N, в порядке возрастания. \n\n"
        "Ввод: ";

        int num;
        cin >> num;

        cout << "Степени двойки: ";

        for (unsigned i = 0; true; i++){
            if (exp(2, i) <= num){
                cout << exp(2, i) << " ";
            } else {
                return {"Success"};
            }
        }
        return {"Success"};


        // unsigned num_amount;
        // unsigned min_counter;
        // min_counter = 0;

        // cout << "\nКол-во чисел: ";
        // cin >> num_amount;

        // std::vector<unsigned> numbers(num_amount);

        // for (int i = 0; i < num_amount; i++){
        //     cout << "Ввод " << i+1 << ": ";
        //     unsigned number;
        //     cin >> number;

        //     numbers[i] = number;
        // }
        // unsigned min_num;
        // min_num = numbers[0];
        // for (int i = 0; i < num_amount; i++){
        //     if (numbers[i] < min_num){
        //         min_num = numbers[i];
        //         min_counter = 1;
        //     } else if (numbers[i] == min_num){
        //         min_counter++;
        //     }
        // }
        // return min_counter;
    }

    // Задача 6
    unsigned problem_6(){
        cout << "Задача 6. \n"
                "Сначала на вход поступает длина последовательности N.\n"
                "Затем элементы последовательности – целые числа.\n"
                "Напишите программу, которая подсчитывает количество положительных чисел"
                "среди элементов последовательности.\n\n"
                "Ввод: ";
        unsigned num_amount;
        unsigned counter {0};
        cin >> num_amount;

        for (int i = 0; i < num_amount; i++){
            int num;
            cout << "Число " << i+1 << ": ";
            cin >> num;

            if (num >= 0){
                counter++;
            }
        }
        return counter;
    }

    // Задача 7
    unsigned problem_7(){
        cout << "Задача 7. \n"
                "Последовательность состоит из натуральных чисел"
                "и завершается числом 0.\n"
                "Определите количество элементов этой последовательности, "
                "которые равны её наибольшему элементу.\n\n";

        unsigned max_num {0};
        unsigned counter {0};
        for (int i = 0; true; i++){
            cout << "Ввод " << i+1 << ": ";
            unsigned num;
            cin >> num;
            if (num == 0){
                break;
            }
            if (num > max_num){
                max_num = num;
                counter = 1;
            } else if (num == max_num) {
                counter ++;
            }
        }
        return counter;
    }

    // Задача 8
    void problem_8(){
        Laptop my_laptop("Dell", "XPS 15", 80000.0);

        cout << "Бренд: " << my_laptop.get_brand() << std::endl;
        std::cout << "Модель: " << my_laptop.get_model() << std::endl;
        std::cout << "Цена: " << my_laptop.get_price() << std::endl;
        std::cout << "Название: " << my_laptop.get_laptop_name() << std::endl;
    }

    void problem_9(){
        auto vk = company_classes::Company(50);
        vk.create_director(
        "Владимир", "Кириенко", 1, 15);

        vk.create_employee(
        "Елена", "Иванова", 2, 8);

        vk.create_employee(
        "Виктор", "Кузнецов", 3, 6);

        vk.set_profit(145.12);
        vk.fulfill_promise();

        auto& director = vk.director;
        vk.director->check_promises(vk); // true

        vk.set_profit(-200);
        vk.fulfill_promise();

        vk.director->check_promises(vk); // false
    }
}


using namespace problems;

int main() {
    auto run_problem = [](this auto&& self) -> void {
        cout << "\nВведите номер задачи (1-9) или 0 для выхода: ";
        unsigned id_problem;
        
        if (!(cin >> id_problem)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Попробуйте снова.\n";
            self();
            return;
        }

        switch (id_problem) {
            case 0:
                cout << "Выход из программы.\n";
                break;
            case 1:
                cout << "\nРезультат: " << problem_1() << "\n";
                break;
            case 2:
                cout << "\nРезультат: " << problem_2() << "\n";
                break;
            case 3:
                cout << "\nРезультат: " << problem_3() << "\n";
                break;
            case 4:
                cout << "\nРезультат: " << problem_4() << "\n";
                break;
            case 5:
                cout << "\nРезультат: " << problem_5() << "\n";
                break;
            case 6:
                cout << "\nРезультат: " << problem_6() << "\n";
                break;
            case 7:
                cout << "\nРезультат: " << problem_7() << "\n";
                break;
            case 8:
                problem_8();
                break;
            case 9:
                problem_9();
                break;
            default:
                cout << "Задачи с таким номером нет. Попробуйте еще раз.\n";
                self();
                break;
        }
    };

    run_problem();

    return 0;
}
