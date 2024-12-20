#include <string>
#include <vector>
#include <map>

using namespace std;

// Абстрактный класс User
class User {
protected:
    string id;
    string name;
    string email;
    string phone;
public:
    virtual void login() {};
    virtual void logout() {};
    virtual void updateProfile() {};
    virtual ~User() = default; // Виртуальный деструктор для полиморфизма
};

// Класс Client наследует User
class Client : public User {
private:
    string address;
    vector<Product> cart;
    vector<Order> orderHistory;
public:
    void selectProducts() {};
    void placeOrder() {};
    void makePayment() {};
    void trackOrder(string orderID) {};
    void updateAddress() {};
    void viewOrderHistory() {};
};

// Класс Assembler наследует User
class Assembler : public User {
private:
    vector<Order> currentOrders;
public:
    void assignPackage(Order order) {};
    void collectOrder(Order order) {};
    void confirmOrderReady(Order order) {};
    void reportIssue(Order order, string issue) {};
};

// Класс Courier наследует User
class Courier : public User {
private:
    string vehicleType;
    string currentLocation;
    Order currentOrder;
public:
    void startDelivery(Order order) {};
    void completeDelivery(Order order) {};
    void updateLocation(string location) {};
    void cancelDelivery(Order order) {};
};

// Абстрактный класс PaymentMethod
class PaymentMethod {
protected:
    string paymentMethod;
public:
    virtual bool validatePayment() = 0; // Чисто виртуальный метод
    virtual ~PaymentMethod() = default;
};

// Класс CardPayment наследует PaymentMethod
class CardPayment : public PaymentMethod {
private:
    string cardNum;
    string cardDate;
    string cardCVV;
    string cardHolderName;
public:
    bool validatePayment() override {
        // Реализация валидации карты
        return true;
    }
};

// Класс SBPPayment наследует PaymentMethod
class SBPPayment : public PaymentMethod {
private:
    string phone;
    string bankName;
    string transactionID;
public:
    bool validatePayment() override {
        // Реализация валидации
        return true;
    }
};

// Перечисление статусов заказа
enum STATUS { ASSEMBLY, DELIVERING, COMPLETED, CANCELLED };

// Класс Order
class Order {
private:
    string orderID;
    vector<Product> productList;
    PaymentMethod* paymentMethod; // Указатель для работы с полиморфизмом
    STATUS status;
    string createdAt;
    string deliveryTime;
public:
    double calculatePrice() {
        // Реализация подсчета цены
        return 0.0;
    }
    void updateStatus(STATUS newStatus) {
        status = newStatus;
    }
    void cancelOrder() {
        status = CANCELLED;
    }
};

// Класс Product
class Product {
private:
    string productID;
    string name;
    double price;
    string description;
    int stock;
};

// Класс Application
class Application {
public:
    vector<Product> browseProducts() {
        return {};
    }
    void manageCart(vector<Product> cart) {};
    void trackOrder(string orderID) {};
};

// Класс DarkStoreSystem
class DarkStoreSystem {
private:
    map<Product, int> inventory;
    vector<Order> activeOrders;
public:
    void assignOrderToAssembler(Order order, Assembler& assembler) {};
    void notifyCourier(Order order, Courier& courier) {};
};

// Класс Administrator наследует User
class Administrator : public User {
private:
    vector<string> permissions;
public:
    void manageUsers(User& user) {};
    string generateReports() {
        return "Report";
    }
};