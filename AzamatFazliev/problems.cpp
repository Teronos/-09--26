// 1 задача

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int product = 1;          
    while (n > 0) {
        int digit = n % 10;   
        product *= digit;     
        n /= 10;              
    }

    cout << product;
    return 0;
}

// 2 задача

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sumA = 0;   
    int sumB = 0;   

    for (int i = 1; i <= 6; i++) {
        int digit = n % 10;
        if (i % 2 == 1) {
            sumB += digit;   
        }
        else {
            sumA += digit;   
        }
        n /= 10;
    }

    cout << sumA << sumB;    
    return 0;
}

// 3 задача

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;     
    int count = 0;   

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 3 == 0) {
            sum += x;
            count++;
        }
    }

    if (count == 0) {
        cout << -1;
    }
    else {
        cout << (double)sum / count;   
    }
    return 0;
}

// задача 4

#include <iostream>
using namespace std;

int main() {
    long long a;
    cin >> a;

    long long prev = 1;   
    long long cur = 1;    
    int n = 2;            

    while (cur < a) {     
        long long next = prev + cur;
        prev = cur;
        cur = next;
        n++;
    }

    if (cur == a) {
        cout << n;
    }
    else {
        cout << -1;      
    }
    return 0;
}

// задача 5

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long p = 1;      
    while (p <= n) {
        cout << p << " ";
        p *= 2;           
    }
    return 0;
}

// задача 6

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {      
            count++;
        }
    }

    cout << count;
    return 0;
}

// задача 7

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    int maxValue = 0;   
    int count = 0;      

    while (x != 0) {            
        if (x > maxValue) {     
            maxValue = x;
            count = 1;          
        }
        else if (x == maxValue) {
            count++;            
        }
        cin >> x;               
    }

    cout << count;
    return 0;
}

// задача 8

#include <iostream>
#include <string>
using namespace std;

class Laptop {
private:                       
    string brand;
    string model;
    double price;
    string laptop_name_;       

public:
    Laptop(string brand, string model, double price) {
        this->brand = brand;   
        this->model = model;
        this->price = price;
        laptop_name_ = brand + " " + model;   
    }

    string laptop_name() {
        return laptop_name_;
    }
};

int main() {
    Laptop l("Lenovo", "ThinkPad", 75000);
    cout << l.laptop_name();   
    return 0;
}

// задача 9

#include <iostream>
#include <string>
#include <vector>
#include <memory>      
#include <stdexcept>   
using namespace std;

// контракт о зарплате
class Promise {
private:
    int id;          
    double salary;   
    bool paid;       

public:
    Promise(int id, double salary) {
        this->id = id;
        this->salary = salary;
        paid = false;
    }

    int get_id() const { return id; }
    double get_salary() const { return salary; }
    bool is_paid() const { return paid; }

    void pay() { paid = true; }      
    void reset() { paid = false; }   
};

// работник
class Employee {
protected:   
    string first_name;
    string second_name;
    int id;
    shared_ptr<Promise> promise;   

public:
    Employee(string first_name, string second_name, int id, shared_ptr<Promise> promise) {
        this->first_name = first_name;
        this->second_name = second_name;
        this->id = id;
        this->promise = promise;
    }

    string get_first_name() const { return first_name; }
    string get_second_name() const { return second_name; }
    int get_id() const { return id; }
};

// директор 
class Director : public Employee {
private:
    vector<shared_ptr<Promise>> promises;

public:
    Director(string first_name, string second_name, int id, shared_ptr<Promise> promise)
        : Employee(first_name, second_name, id, promise) {
    }  

    void add_promise(shared_ptr<Promise> p) {
        promises.push_back(p);
    }

    bool check_promises() const {
        for (const auto& p : promises) {
            if (!p->is_paid()) {
                return false;
            }
        }
        return true;
    }
};

// компания
class Company {
private:
    double balance;
    shared_ptr<Director> director_;              
    vector<Employee> employees;                  
    vector<shared_ptr<Promise>> promises;        

public:
    explicit Company(double balance) {
        this->balance = balance;
    }

    void create_director(string first_name, string second_name, int id, double salary) {
        if (director_ != nullptr) {
            throw runtime_error("У компании уже есть директор");
        }
        auto promise = make_shared<Promise>(id, salary);
        director_ = make_shared<Director>(first_name, second_name, id, promise);
        promises.push_back(promise);
        director_->add_promise(promise);
    }

    void create_employee(string first_name, string second_name, int id, double salary) {
        if (director_ == nullptr) {
            throw runtime_error("Сначала нужно создать директора");
        }
        auto promise = make_shared<Promise>(id, salary);
        employees.push_back(Employee(first_name, second_name, id, promise));
        promises.push_back(promise);
        director_->add_promise(promise);   
    }

    void set_profit(double profit) {
        balance += profit;
    }

    bool fulfill_promise() {
        double total = 0;
        for (const auto& p : promises) {
            p->reset();                   
            total += p->get_salary();
        }

        if (balance < total) {
            return false;                 
        }

        balance -= total;
        for (const auto& p : promises) {
            p->pay();
        }
        return true;
    }

    Director& director() {
        if (director_ == nullptr) {
            throw runtime_error("У компании нет директора");
        }
        return *director_;                
    }
};

int main() {
    auto vk = Company(50);
    vk.create_director("Владимир", "Кириенко", 1, 15);
    vk.create_employee("Елена", "Иванова", 2, 8);
    vk.create_employee("Виктор", "Кузнецов", 3, 6);

    vk.set_profit(145.12);
    vk.fulfill_promise();

    auto& director = vk.director();
    cout << boolalpha << director.check_promises() << endl;   

    vk.set_profit(-200);
    vk.fulfill_promise();

    cout << director.check_promises() << endl;                
    return 0;
}
