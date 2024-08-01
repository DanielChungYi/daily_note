#include <iostream>
#include <vector>

using namespace std;

class Block {
public:
    virtual void produce() = 0;
};

class Circle : public Block {
public:
    void produce() override{
        cout << "Circle" << endl;
    }
};

class Square : public Block {
public:
    void produce() override{
        cout << "Square" << endl;
    }
};

class BlockFactory {
public:
    virtual Block* createBlock() = 0;
};

class CircleFactory : public BlockFactory {
public:
    Block* createBlock() override {
        return new Circle();
    }
};

class SquareFactory : public BlockFactory {
public:
    Block* createBlock() override {
        return new Square();
    }
};


int main() {
    SquareFactory sF;
    CircleFactory cF;
    Block* myProduct = sF.createBlock();
    myProduct->produce();
    myProduct = cF.createBlock();
    myProduct->produce();
    return 0;
}
