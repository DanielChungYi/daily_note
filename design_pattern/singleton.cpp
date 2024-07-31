#include <iostream>
#include <map>

using namespace std;

class ShoppingCartManager {
public:
    static ShoppingCartManager& getInstance() {
        static ShoppingCartManager instance;
        return instance;
    }

    void addToCart(const string& itemName, int quantity) {
        cart[itemName] += 1;
    }

    void viewCart() {
        for(const auto& item : cart) {
            cout << item.first << " : " << item.second << endl;
        }
    }

private:
    ShoppingCartManager() {};
    map<string, int> cart;
};


int main() {
   string itemName;
   int quantity;
   
    while(cin >> itemName >> quantity) {
       ShoppingCartManager& cart = ShoppingCartManager::getInstance();  
       cart.addToCart(itemName, quantity);
   }
    ShoppingCartManager& cart = ShoppingCartManager::getInstance();  
    cart.viewCart();
    return 0;
}
