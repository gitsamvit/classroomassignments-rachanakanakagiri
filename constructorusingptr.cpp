// Online C++ compiler to run C++ program online
#include <iostream>

const int MAX_SIZE =100;
//Read it right-to-left: “p is a pointer to an X that is constant.”
class T{
    public :
    int x;
    //method is const -> make this ptr as constant 
    void method()const {
        
    }
};

void api(T* ptr){
    
}

//ptr is a pointer to an T that is constant : obj is constant
void init(const T* ptr){
  //ptr->x =20;   //cant modify const obj using ptr
  ptr = new T();    // can create new obj using ptr
}
int main() {
    T obj;
    init(&obj);
    // newPtr is a ptr to T that is const
    const T* newPtr = new T();
    // ptr is a constant ptr to T 
    T* const ptr = new T();
    // nextptr is a constant ptr to T that is const
    const T* const nextptr = new T();
    //refObj is bydefault constant reference to an obj of type T that is const
    const T& refObj = obj;
    T obj1;
    
    T& newRef = obj1; // const T& const newRef = obj1;  : bydefault const

    
}