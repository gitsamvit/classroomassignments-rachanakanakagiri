    // Online C++ compiler to run C++ program online
    #include <iostream>
    #include <vector>
    #include <functional>
    using namespace std;
    
    class A{
        int x;
        public:
        A(int xArg) :x {xArg} {
           std::cout << "A.A()" << xArg << endl;
           //this->print(); // Avoid
        }
        virtual void print(){
            std::cout << "print" << x << endl;
        }
        virtual ~A(){
            cout << "A deleted" << endl;
        }
        
    };
        
    class B : public A{
        string msg;
        public: 
        //invoke base class const explicitly from derived class
        
        B() : A::A(10){
            //every const of derived class will make a call to const of base class
            //A::A(); : before any line of derived class is called , base class constructor is called
             std::cout << "B.B()" << endl;
        }
        B(string msgArg, int xArg) : msg(msgArg), A::A(xArg){}
        
        void print() override{
           std::cout << "msg length" <<this->msg.length() << endl; 
        }
        virtual ~B(){
            cout << "B deleted" << endl;
        }
    };
    
    
    
    //std::cout << "obj1.x :" <<obj1.x    << "obj1.bObj.y :" << obj1.bObj->y << endl;
    
    int main(){
       // B obj;
        //B obj("hello" , 10);
        A* ptr = new B("hello" , 10);
        ptr->print();
        delete ptr;
    }