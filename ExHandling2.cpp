// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <thread>
using namespace std;

class ErrorInfo{
    public:
    string dateTime , methodName, lineNo , desc ;
    std::thread::id threadId;
};
class DivByZeroExc : public ErrorInfo{};
class DivByNegExc : public ErrorInfo {};

int divFunc(int nume , int deno){
    if(deno ==0){
        ErrorInfo exObj;
        DivByZeroExc obj;
        exObj.dateTime = "23-08-23, 4:38";
        exObj.methodName = "divFunc";
        exObj.lineNo = "12";
        exObj.desc="divided by zero exception";
        exObj.threadId = this_thread::get_id();    
        throw exObj; // return throw error info
    }
    return nume/deno;
};


void c(){
    throw 1;
}

void b(){
    cout<< "before c call:"<<endl;
    c();
    cout<< "after c call:" <<endl;
}
void a(){
    cout<< "before b call:"<<endl;
    b();
    cout<< "after b call:" <<endl;
}

int main() {
    
    try{
        int res = divFunc(10,0);
        cout<< "statement n :" << res<<endl;
        
    }catch(ErrorInfo & exObj){
        cout<< exObj.desc <<endl;
    }catch(DivByZeroExc & exObj){
        cout<< "DivByZeroExc :" << exObj.desc<<endl;
    }catch(DivByNegExc & exObj){
        cout<< "DivByNegExc :" << exObj.desc<<endl;
    }
    cout<< "statement n+1" <<endl;
    // divFunc(10,-1);
    // divFunc(10,2);

   
}