    // Online C++ compiler to run C++ program online
    #include <iostream>
    #include <vector>
    #include <functional>
    using namespace std;
    
    class B{
        public: int y;
    };
    class A{
        public:
        int x;
        //B bObj;
        B* bObj = new B();
        A(){}
        A(const A& obj){
            this->x = obj.x;
            B* tmp = new B();
            tmp-> y = obj.bObj->y;
            this->bObj = tmp;
        }
    };
    
    int main(){
        A obj{};
        obj.x=10;
        obj.bObj->y=100;
        
        A obj1(obj); //coTpy const
        obj1.x=100;
        obj1.bObj->y=1000;
        std::cout << "obj.x : " <<obj.x    << "obj.bObj.y :" << obj.bObj->y <<endl;
        std::cout << "obj1.x :" <<obj1.x    << "obj1.bObj.y :" << obj1.bObj->y << endl;
        
    }
    