#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class GroceryCounter {
private:
    int value;
    int overflows;

public:
    GroceryCounter() : value(0), overflows(0) {}

    //10.00
    void tens() {
         value += 1000;

        if(value > 9999){
            number_of_overflows();
        }
    }

    //01.00
    void ones() {
        value += 100;
        if(value > 9999){
            number_of_overflows();
        }
    }

    //00.10
    void tenths() {
        value += 10;
        if(value > 9999){
            number_of_overflows();
        }
    }

    //00.01
    void hundredths() {
        value += 1;
        if(value >= 9999){
            number_of_overflows();
        }
    }

    void minusTens(){
        value -= 1000;

        if(value < 0){
            underflows();
        }

    }

    void minusOnes(){
        value -= 100;
        if(value < 0){
            underflows();
        }
    }

    void minusTenths(){
        value -= 10;
        if(value < 0){
            underflows();
        }
    }
    void minusHundreths(){
        value -= 1;
        if(value < 0){
            underflows();
        }
    }

    string total() {
        int dollars = value / 100;
        int cents = value % 100;
        stringstream ss;
        ss << "$" << dollars << "." << setw(2) << setfill('0') << cents;
        return ss.str();
    }

    int number_of_overflows() {
        cout << "\noverflowed\n";
        value -= 9999;
        overflows++;
        return overflows;
    }
    //if value goes under zero, this resets value back to zero
    void underflows(){
        value = 0;
        cout << "\nUnderflowed\ncounter reset to zero\n";
    }


    void clear() {
        value = 0;
        overflows = 0;
    }

};

int main() {
    GroceryCounter counter;
    cout << counter.total() << endl;  // Output: $0.00

    counter.ones();
    counter.ones();
    counter.minusOnes();
    counter.minusOnes();
    counter.minusTenths();
    cout << counter.total() << endl;


    
    counter.clear();
    cout << counter.total() << endl;  
    return 0;
}