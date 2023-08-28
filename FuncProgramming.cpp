
    // Online C++ compiler to run C++ program online
    #include <iostream>
    #include <vector>
    #include <functional>
    using namespace std;
    
    class Device{
        public :
        string id, model;
        public: 
        Device(string idArg, string modelArg) : id{idArg} , model{modelArg}{}
        //get mutators 
        string getId() {return this->id;}
        string getModel() {return this->model;}
        friend ostream& operator<<(ostream& out, const Device &item){
            out<<item.id << " " << item.model <<endl;
            return out;
        }
    };
    
    function<bool(int)> isNumGreaterthanAny(int searchKey){
        //predicate function
        //fn returns boolean but i/p is int : 
        // predicate(fn) obj of class function<bool(int)> which represents the function predicate returns boolean that has arg int
        function<bool(int)> predicate = [searchKey](int item){ return item > searchKey;};
        return predicate;
    }
    
    function<bool(string)> checkStringWithAny(string s ){
        function<bool(string)> predicate =
        [s](string item){ return s[0] == item[0];};
        return predicate;
    }
    
    // function<bool(Device)> checkDeviceWithAny(Device d){
    //     function<bool(Device)> predicate =
    //     [d] (Device item) { return d[modelArg] == item[modelArg];};
    //     return predicate;
    // }
    
    template<typename T>
    vector<T> filter(const vector<T> &source, function<bool(T)> predicate){
        vector<T>  result;
        for( int i=0;i< source.size(); ++i)
            if(predicate(source[i])){
                result.push_back(source[i]);
            }
            return result;
            }
        
    
    
    
    template <typename T>
    void printResult(const vector<T> &source){
        for(int i = 0; i < source.size(); ++i){
            std::cout << source[i] << endl;
    }
    }
    
    
    
    //template <typename T>
    void printVector(const vector<Device> &source){
        for(int i = 0; i < source.size(); ++i){
            std::cout << source[i] << endl;
    }
    }
    int main() {
        
        //no change in filter and printResult fn : user defined datatype instead of str & int
        vector<Device> devices;
        Device d1{"D1" , "M1"};
         Device d2{"D2" , "M2"};
         Device d3{"D3" , "M1"};
         Device d4{"D4" , "M4"};
         devices.push_back(d1);
         devices.push_back(d2);
         devices.push_back(d3);
         devices.push_back(d4);
         
        printVector(
            filter<Device>(
                devices,[](Device item) {return item.getModel()=="M1";}));
        
        //source
        vector<int> numbers = {1,4,3,6,7,9,12};
        //printResult
        printResult(filter(numbers , isNumGreaterthanAny(5)));
         std::cout << endl;
         printResult(filter(numbers , isNumGreaterthanAny(7)));
         std::cout << endl;
        printResult(filter(numbers , isNumGreaterthanAny(11)));
        std::cout << endl;
       
       vector<string> names = {"Bosch", "KOR" , "ADU", "GTP"};
        printResult<string>(filter(names , checkStringWithAny("B")));
        std::cout << endl;
        printResult<string>(filter(names , checkStringWithAny("G")));
        std::cout << endl;
        return 0;
    }