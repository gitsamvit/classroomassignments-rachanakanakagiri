// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class Target{

    public:
    Target(){
        cout<<"Target acquired resources" <<endl;
    }
    ~Target(){
        cout<<"Target deleted successfully! resources released" <<endl;

    }
    void operation(){
         cout<<"operation on Target successfully" <<endl;
    }
};

class SmartPointers{
    private:
    Target* ptrToTarget;
    public:SmartPointers(){
        this->ptrToTarget = new Target();
    }
    ~SmartPointers(){
        delete this->ptrToTarget;
    }
    //overload operator
    Target* operator->(){
        return ptrToTarget;
    }
    
};


void init(){
    SmartPointers smartObj;
    smartObj->operation();
}

int main(){
init();
}