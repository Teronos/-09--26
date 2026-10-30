#include <algorithm>
#include <iostream>
#include <ranges>
#include <functional>
#include <map>
#include <cmath>
#include <memory>

using namespace std;

namespace problem {
  unsigned problem1() {
    /*
    Дано пятизначное число. Найдите произведение его цифр.
    */
    string num;
    cin >> num;
    return ranges::fold_left(
      ranges::transform_view(num, [](auto& ch){return ch-'0';}),
      1,
      multiplies<>()
    );
  }

  string problem2(){
    /*
    Дано шестизначное число. Найдите суммы его четных и нечетных элементов. 
    Образуйте из них этих сумм одно число и выведите его на экран
    */
   string num;
   cin >> num;
   auto [sum1, sum2] = ranges::fold_left(
        num | views::transform([](auto& ch){return ch-'0';}) | views::enumerate, 
        pair{0, 0},        
        [](pair<int,int> acc, auto elem) {
            auto [ind, dgt] = elem;
            return ind%2 == 0 ? pair{acc.first + dgt, acc.second} : pair{acc.first, acc.second + dgt};
        }
    );
   return to_string(sum1) + to_string(sum2);
  }
  
  double problem3(){
    /*
    Вводится натуральное число N, а затем N чисел. 
    Найти среднее арифметическое всех чисел кратных 3. Если таких чисел нет, то вывести -1    
    */
    unsigned n;
    cin >> n;
    vector<unsigned> v(n);
    ranges::for_each(v, [](auto& el){cin >> el;});
    auto [sum, n3] = ranges::fold_left(
      v | views::filter([](auto num){return (num % 3 == 0);}),
      pair{0.0, 0.0},
      [](auto acc, auto num){return pair{acc.first+num, acc.second+1.0};}
    );
    return  n3 == 0.0 ? -1.0 : sum/n3;
  }

  int problem4(){
    /*
    Дано натуральное число A > 1. Определите, каким по счету числом Фибоначчи оно является,
    то есть выведите такое число n, что \varphi_n = A . Если А не является числом Фибоначчи, выведите число -1/
    */
    int a;
    cin >> a;
    auto fi = [a](auto&& self, auto i, auto n1, auto n2){
      if (n2 == a) return i;
      if (n2 > a) return -1;
      return self(self, i+1, n2, n2+n1);
    };
    return fi(fi, 3, 1, 2); //числа Ф.: 1, 1, n2=2
  }


  void problem5(){
    /*
    По данному числу N распечатайте все целые значения степени двойки, не превосходящие N в порядке возрастания.
    */
    unsigned n;
    cin >> n;
    auto powers = [n](auto&& self, auto cur){
      if (cur > n) return;
      cout << cur << " ";
      self(self, cur*2); 
    };
    powers(powers, 1);
  }

  unsigned problem6(){
    /*
    Сначала на вход поступает длина последовательности N. Затем элементы последовательности – целые числа.
    Напишите программу, которая подсчитывает количество положительных чисел среди элементов последовательности.
    */
    unsigned n;
    cin >> n;
    vector<int> v;
    auto input = [n, &v](auto&& self){
      if (v.size() == n) return;
      int num;
      cin >> num;
      v.push_back(num);
      self(self);
    };
    input(input);
    return ranges::fold_left(
        v | views::filter([](auto num){return (num > 0);}),
        0,
        [](auto acc, auto _){return acc+1;}
      );
  }

  unsigned problem7(){
    /*
    Последовательность состоит из натуральных чисел и завершается числом 0. 
    Определите количество элементов этой последовательности, которые равны ее наибольшему элементу.
    */
    vector<int> v;
    auto input = [&v](auto&& self){
      int num;
      cin >> num;
      if (num == 0) return;
      v.push_back(num);
      self(self);
    };
    input(input);
    int max_num = ranges::max(v);
    return ranges::fold_left(
      v | views::filter([max_num](auto num){return (num == max_num);}),
      0,
      [](auto acc, auto _){return acc+1;}
    );
  }

  /*__Задача 8__
    Создайте класс Laptop, у которого есть:
    + Конструктор, принимающий 3 аргумента: бренд, модель и цену ноутбука. 
    На основании этих аргументов нужно для экземпляра создать атрибуты brand, model, price 
    и также атрибут laptop_name — строковое значение, следующего вида: «brand model»
    + Метод laptop_name возвращающий аналогичное значение поля.
  */

  class Laptop{
  private:
    string brand_;
    string model_;
    int price_;
    string laptop_name_;
  
  public:
    Laptop(const string& brand, const string& model, int price){
      brand_ = brand;
      model_ = model;
      price_ = price; // в условных единицах
    };
    ~Laptop(){};

    void brand(string brand){brand_ = brand; laptop_name_ = brand_ + " " + model_;};
    string brand(){return brand_;};
    void model(string model){model_ = model; laptop_name_ = brand_ + " " + model_;};
    string model(){return model_;}
    void price(int price){price_ = price;};
    int price(){return price_;};
    string laptop_name(){return laptop_name_;};

    void print_info(){
      cout << "Laptop: " + laptop_name() + "\n";
      cout << "price: " + to_string(price()) + "\n";
    }
  };

  void problem8(){
    //interface for Laptop class
    string brand, model, price;
    cout << "New laptop:\nbrand: ";
    getline(cin, brand);
    cout << "model: ";
    getline(cin, model);
    cout << "price: ";
    getline(cin, price);
    
    auto lap = Laptop(brand, model, stoi(price));
    lap.print_info();

    string option = "";
    while (option != "0")
    {
      cout << "Options:\n0 - exit\n1 - change brand\n2 - change model\n3 - change price\n\n";
      getline(cin, option);
      if (option.empty()) continue;
      
      switch(stoi(option)){
        case 1: {
          cout << "model: ";
          getline(cin, model);
          lap.model(model);
          cout << "\n";
          lap.print_info();
          cout << "\n";
          break;
        }
        case 2: {
          cout << "brand: ";
          getline(cin, brand);
          lap.brand(brand);
          cout << "\n";
          lap.print_info();
          cout << "\n";
          break;
        }
        case 3: {
          cout << "price: ";
          getline(cin, price);
          lap.price(stoi(price));
          cout << "\n";
          lap.print_info();
          cout << "\n";
          break;
        }
        default: 
          cout << "please enter valid option number\n";
          break;
      }
    }
    lap.~Laptop();
  }

  /*
__Задача 9__
  Нужно создать функционал для упрошенного описания экономических отношений между работодателем, работником и компанией. 
  Нужно реализовать классы Director, Employee, Company, Promise.
  */

  class Promise {
    int id_;
    double salary_;
    bool paid_{false};

  public:
    Promise(int id, double salary) : id_(id), salary_(salary) {}
    int id() const { return id_; }
    double salary() const { return salary_; }
    bool is_paid() const { return paid_; }
    void set_paid(bool p) { paid_ = p; }
  };

  class Worker {
  protected:
    string first_name_;
    string second_name_;
    Promise promise_;

  public:
    Worker(const string& first, const string& second, int id, double salary)
        : first_name_(first), second_name_(second), promise_(id, salary) {}
    virtual ~Worker() = default;

    const string& first_name() const { return first_name_; }
    const string& second_name() const { return second_name_; }
    Promise& promise() { return promise_; }
    const Promise& promise() const { return promise_; }
  };

  class Company; 

  class Director : public Worker {
      Company* company_{nullptr};

  public:
    Director(const string& first, const string& second, int id, double salary)
      : Worker(first, second, id, salary) {}
    
    void set_company(Company* comp) { company_ = comp; }
    bool check_promises() const;
  };

  class Employee : public Worker {
  public:
    Employee(const string& first, const string& second, int id, double salary)
      : Worker(first, second, id, salary) {}
  };

  class Company {
    double balance_;
    unique_ptr<Director> director_;
    vector<unique_ptr<Employee>> employees_;

  public:
    Company(double balance) : balance_(balance) {}
    void create_director(const string& first, const string& second, int id, double salary) {
      director_ = make_unique<Director>(first, second, id, salary);
      director_->set_company(this);
    }
    void create_employee(const string& first, const string& second, int id, double salary) {
      employees_.push_back(make_unique<Employee>(first, second, id, salary));
    }
    void set_profit(double amount) {balance_ += amount;}
    double balance() const { return balance_; }

    bool fulfill_promise() {
      double total_salary = 0.0;
      if (director_) total_salary += director_->promise().salary();
      for (const auto& emp : employees_) {
        total_salary += emp->promise().salary();
      }
      if (balance_ >= total_salary) {
        balance_ -= total_salary;
        if (director_) director_->promise().set_paid(true);
        for (auto& emp : employees_) {
          emp->promise().set_paid(true);
        }
        return true;
      } else {
        if (director_) director_->promise().set_paid(false);
        for (auto& emp : employees_) {
          emp->promise().set_paid(false);
        }
        return false;
      }
    }
    Director& director() {
      return *director_;
    }
    bool all_promises_paid() const {
      if (director_ && !director_->promise().is_paid()) return false;
      for (const auto& emp : employees_) {
        if (!emp->promise().is_paid()) return false;
      }
      return true;
    }
  };

  bool Director::check_promises() const {
    if (company_) {
      return company_->all_promises_paid();
    }
    return false;
  }

  void problem9() {
    auto vk = Company(50);
    vk.create_director("Владимир", "Кириенко", 1, 15);
    vk.create_employee("Елена", "Иванова", 2, 8);
    vk.create_employee("Виктор", "Кузнецов", 3, 6);

    vk.set_profit(145.12);
    vk.fulfill_promise();

    auto& director = vk.director();
    cout << boolalpha << director.check_promises() << endl; // true

    vk.set_profit(-200);
    vk.fulfill_promise();

    cout << boolalpha << director.check_promises() << endl; // false
  }

  void problem9_demo() {
    double balance;
    cout << "Company balance: ";
    cin >> balance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Company vk(balance);

    string option = "";
    while (option != "0") {
      cout << "\nOptions:\n"
              "0 - exit\n"
              "1 - create director\n"
              "2 - create employee\n"
              "3 - set profit\n"
              "4 - fulfill promises\n"
              "5 - check promises\n"
              "6 - show balance\n\n";
      
              getline(cin, option);
      if (option.empty()) continue;

      int choice = -1;
      try { choice = stoi(option); }
      catch (...) { cout << "Invalid option\n"; continue; }

      switch (choice) {
      case 0:
          break;

      case 1: {
          string first, second, salary;
          int id;
          cout << "first name: ";
          getline(cin, first);
          cout << "second name: ";
          getline(cin, second);
          cout << "id: ";
          cin >> id;
          cin.ignore();
          cout << "salary: ";
          getline(cin, salary);

          vk.create_director(first, second, id, stod(salary));
          cout << "Director created\n";
          break;
      }

      case 2: {
        string first, second, salary;
        int id;
        cout << "first name: ";
        getline(cin, first);
        cout << "second name: ";
        getline(cin, second);
        cout << "id: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "salary: ";
        getline(cin, salary);

        vk.create_employee(first, second, id, stod(salary));
        cout << "Employee created\n";
        break;
      }

      case 3: {
        string amount;
        cout << "profit (can be negative): ";
        getline(cin, amount);
        try {
          vk.set_profit(stod(amount));
          cout << "Profit set\n";
        } catch (...) {
          cout << "Invalid number\n";
        }
        break;
      }

      case 4: {
        bool ok = vk.fulfill_promise();
        cout << "Fulfill: " << boolalpha << ok << "\n";
        break;
      }

      case 5: {
        bool ok = vk.all_promises_paid();
        cout << "All promises paid: " << boolalpha << ok << "\n";
        break;
      }

      case 6:
        cout << "Balance: " << vk.balance() << "\n";
        break;

      default:
        cout << "Unknown option: " << choice << "\n";
        break;
      }
      if (choice == 0) break;
  }
}
  
};

using namespace problem;

int main() {
  auto run_problem = [](this auto&& self) -> void
    {
        unsigned id_problem;
        cin >> id_problem;
        cin.ignore();

        switch (id_problem) {
        case 1:
          cout << problem1();
          break;

        case 2:
          cout << problem2();
          break;

        case 3:
          cout << problem3();
          break;

        case 4:
          cout << problem4();
          break;

        case 5:
          problem5();
          break;

        case 6:
          cout << problem6();
          break;
        
        case 7:
          cout << problem7();
          break;

        case 8: 
          problem8();
          break;

        case 9:{
          string option = "";
          cout << "Options:\n1 - example\n2 - interactive\n\n";
          getline(cin, option);
          if (option == "1") problem9();
          else if (option == "2") problem9_demo();
          break;
        }

        default:
          self();
        }
    };

  run_problem();
}
  
