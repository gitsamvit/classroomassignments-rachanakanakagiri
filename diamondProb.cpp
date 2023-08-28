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
    
    class C : virtual public A{
        public:
        C() : A ::A(20){
            //A::A();
            std::cout << "C.C()" << endl;
        }
    };
    class D : public B , public C{
        public:
        //D(){} can't be called due to diamond problem
        D():A::A(100){
            
        }
        
    };
    
    int main(){
       // B obj;
        //B obj("hello" , 10);
        // A* ptr = new B("hello" , 10);
        // ptr->print();
        // delete ptr;
        D obj;
    }
        

    OP
	A.A()100
A.A()10
B.B()
C.C()
B deleted
A deleted
A deleted