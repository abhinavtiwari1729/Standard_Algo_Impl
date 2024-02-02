#include <iostream>

using namespace std;

class MyClass {
public:
    // Default constructor
    MyClass() : myRefVar(defaultRefValue), myConstPtr(nullptr), staticVar(defaultStaticValue) {}

    // Parametrized constructor
    MyClass(int& refValue, const int* constPtr, int staticValue) 
        : myRefVar(refValue), myConstPtr(constPtr), staticVar(staticValue) {}

    // Copy constructor
    MyClass(const MyClass& other) 
        : myRefVar(other.myRefVar), myConstPtr(other.myConstPtr), staticVar(other.staticVar) {}

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {  // Avoid self-assignment
            myRefVar = other.myRefVar;
            myConstPtr = other.myConstPtr;
            staticVar = other.staticVar;
        }
        return *this;
    }

    // Member function to display values
    void displayValues() const {
        std::cout << "Reference Variable: " << myRefVar 
                  << ", Constant Pointer Variable: " << *myConstPtr 
                  << ", Static Variable: " << staticVar << std::endl;
    }

private:
    int& myRefVar;
    const int* myConstPtr;
    static int defaultRefValue;
    static int defaultStaticValue;
    int staticVar;
};

// Default values for static member variables
int MyClass::defaultRefValue = 0;
int MyClass::defaultStaticValue = 999;

int main() {
    int variable1 = 42;
    const int* variable2 = new int(99);

    // Creating an instance using the default constructor
    // MyClass obj1;
    // obj1.displayValues();

    // Creating an instance using the parametrized constructor
    MyClass obj2(variable1, variable2, 123);
    obj2.displayValues();

    // Creating an instance using the copy constructor
    MyClass obj3 = obj2;
    obj3.displayValues();

    // Creating an instance using the copy assignment operator
    MyClass obj4;
    obj4 = obj2;
    obj4.displayValues();

    // Cleanup for dynamically allocated memory
    delete variable2;
    std::cin.get();
    //sreturn 0;
}
