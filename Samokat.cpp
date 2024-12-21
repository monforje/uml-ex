#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Предварительные объявления
class Product;
class Order;

// Абстрактный класс User
class User {
protected:
    string id;
    string name;
    string email;
    string phone;
public:
    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    virtual void login() {
        cout << name << " logged in." << endl;
    };
    virtual void logout() {
        cout << name << " logged out." << endl;
    };
    virtual void updateProfile() {
        cout << name << " updated their profile." << endl;
    };
    virtual ~User() = default; // Виртуальный деструктор для полиморфизма
};

class Product {
public:
    string productID;
    string name;
    double price;
    string description;
    int stock;

    Product(string id, string name, double price, string desc, int stock)
        : productID(id), name(name), price(price), description(desc), stock(stock) {}
};

// Класс Client наследует User
class Client : public User {
private:
    string address;
    vector<Product> cart;
    vector<string> orderHistory;
public:
    void selectProducts(Product product) {
        cart.push_back(product);
        cout << "Product " << product.name << " added to cart." << endl;
    }

    void placeOrder() {
        if (cart.empty()) {
            cout << "Cart is empty. Add products to place an order." << endl;
            return;
        }
        string orderID = "Order_" + to_string(orderHistory.size() + 1);
        orderHistory.push_back(orderID);
        cart.clear();
        cout << "Order " << orderID << " placed successfully." << endl;
    }

    void makePayment() {
        cout << "Payment made successfully." << endl;
    }

    void trackOrder(string orderID) {
        cout << "Tracking information for " << orderID << ": In progress." << endl;
    }

    void updateAddress(string newAddress) {
        address = newAddress;
        cout << "Address updated to " << address << "." << endl;
    }

    void viewOrderHistory() {
        cout << "Order History:" << endl;
        for (const auto& order : orderHistory) {
            cout << " - " << order << endl;
        }
    }
};

// Класс Assembler наследует User
class Assembler : public User {
private:
    vector<string> currentOrders;
public:
    void assignPackage(string orderID) {
        currentOrders.push_back(orderID);
        cout << "Package assigned to assembler for order " << orderID << "." << endl;
    }

    void collectOrder(string orderID) {
        cout << "Order " << orderID << " collected for assembly." << endl;
    }

    void confirmOrderReady(string orderID) {
        cout << "Order " << orderID << " is ready for delivery." << endl;
    }

    void reportIssue(string orderID, string issue) {
        cout << "Issue reported for order " << orderID << ": " << issue << "." << endl;
    }
};

// Класс Courier наследует User
class Courier : public User {
private:
    string vehicleType;
    string currentLocation;
    string currentOrder;
public:
    void startDelivery(string orderID) {
        currentOrder = orderID;
        cout << "Courier started delivery for order " << orderID << "." << endl;
    }

    void completeDelivery(string orderID) {
        cout << "Delivery completed for order " << orderID << "." << endl;
        currentOrder = "";
    }

    void updateLocation(string location) {
        currentLocation = location;
        cout << "Courier location updated to " << location << "." << endl;
    }

    void cancelDelivery(string orderID) {
        cout << "Delivery canceled for order " << orderID << "." << endl;
    }
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
        cout << "Card payment validated." << endl;
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
        cout << "SBP payment validated." << endl;
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
    Order(string id, vector<Product> products, PaymentMethod* payment)
        : orderID(id), productList(products), paymentMethod(payment), status(ASSEMBLY) {}

    string getOrderID() const {
        return orderID;
    }

    double calculatePrice() {
        double total = 0;
        for (const auto& product : productList) {
            total += product.price;
        }
        return total;
    }

    void updateStatus(STATUS newStatus) {
        status = newStatus;
        cout << "Order " << orderID << " status updated." << endl;
    }

    void cancelOrder() {
        status = CANCELLED;
        cout << "Order " << orderID << " has been canceled." << endl;
    }
};

// Класс Application
class Application {
public:
    vector<Product> browseProducts() {
        vector<Product> products = {
            Product("1", "Milk", 1.5, "1L of milk", 100),
            Product("2", "Bread", 1.0, "500g of bread", 50),
            Product("3", "Apple", 0.5, "1 apple", 200)
        };
        return products;
    }

    void manageCart(vector<Product>& cart) {
        cout << "Managing cart with " << cart.size() << " products." << endl;
    }

    void trackOrder(string orderID) {
        cout << "Tracking order: " << orderID << "." << endl;
    }
};

// Класс DarkStoreSystem
class DarkStoreSystem {
private:
    map<string, int> inventory;
    vector<Order> activeOrders;
public:
    void assignOrderToAssembler(Order& order, Assembler& assembler) {
        assembler.assignPackage(order.getOrderID());
    }

    void notifyCourier(Order& order, Courier& courier) {
        courier.startDelivery(order.getOrderID());
    }
};

// Класс Administrator наследует User
class Administrator : public User {
private:
    vector<string> permissions;
public:
    void manageUsers(User& user) {
        cout << "Managing user " << user.getName() << "." << endl;
    }

    string generateReports() {
        cout << "Generating reports." << endl;
        return "Report generated.";
    }
};

int main() {
    Application app;
    vector<Product> products = app.browseProducts();
    Client client;
    client.setName("John Doe");

    cout << "Available products:" << endl;
    for (const auto& product : products) {
        cout << " - " << product.name << " ($" << product.price << ")" << endl;
    }

    client.selectProducts(products[0]);
    client.selectProducts(products[1]);
    client.placeOrder();

    Assembler assembler;
    assembler.setName("Alice");
    assembler.assignPackage("Order_1");

    Courier courier;
    courier.setName("Bob");
    courier.startDelivery("Order_1");
    courier.updateLocation("123 Main St");
    courier.completeDelivery("Order_1");

    Administrator admin;
    admin.setName("Admin");
    admin.generateReports();

    return 0;
}
