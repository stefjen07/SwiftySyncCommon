#include "Functions.hpp"
#include "Request.hpp"
#include <iostream>

using namespace std;

int main() {
    //UUIDs
    for(int i=0;i<10;i++) {
        cout << create_uuid() << "\n";
    }
    //Requests
    auto dr = DataRequest("1", "2", "3");
    auto fr = FunctionRequest("1", DataUnit(vector<char>()));
    return 0;
}