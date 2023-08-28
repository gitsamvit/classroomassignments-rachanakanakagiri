// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1,4,3,6,7,9,12};
    vector<int> newVec;
    //find all res > 5 and print them
    int threshold =5;
    for (auto ele : numbers){
        if(ele > threshold){
            newVec.push_back(ele);
        }
    }
    for (auto ele : newVec){
         std::cout << ele << endl;
    }
    
    for(int i = 0; i < newVec.size(); ++i){
        std::cout << newVec[i] << endl;
        }
        
    for(int i = 0; i < numbers.size(); ++i){
        if(numbers[i]>5){
            newVec.push_back(numbers[i]);
        }
    }
            for(int i = 0; i < newVec.size(); ++i){
        std::cout << newVec[i] << endl;
        }

    return 0;
}