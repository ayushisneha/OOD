#include<iostream>
using namespace std;

class Strategy{
public:
    virtual int doOperation(int x, int y) = 0;
};

class AdditionStrategy: public Strategy {
    int doOperation(int x, int y){
        cout<<"AdditionStrategy: ";
        return x+y;
    }
};

class SubtractionStrategy: public Strategy {
    int doOperation(int x, int y){
        cout<<"SubtractionStrategy: ";
        return x-y;
    }
};

class MultiplicationStrategy: public Strategy {
    int doOperation(int x, int y){
        cout<<"MultiplicationStrategy: ";
        return x*y;
    }
};


class ArithmeticOperation{
private:
    int a;
    int b;
    Strategy* strategy;

public:
    void setfirstNum(int x){
        this->a = x;
    }
    void setsecondNum(int x){
        this->b = x;
    }
    void setStrategy(Strategy* strat){
        this->strategy = strat;
    }
    void execute(){
        cout<<"Operation "<< strategy->doOperation(a,b)<<endl;
    }

};



int main(){
    unique_ptr<ArithmeticOperation> aop = make_unique<ArithmeticOperation>();
    aop->setfirstNum(2);
    aop->setsecondNum(3);
    aop->setStrategy(new AdditionStrategy());
    aop->execute();
    aop->setStrategy(new SubtractionStrategy());
    aop->execute();

    return 0;
}