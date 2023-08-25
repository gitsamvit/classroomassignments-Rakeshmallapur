#include <iostream>
#include <vector>
#include <functional>
using namespace std;

 class Device{
private:
string model, id;
public: Device(string idArg, string modelArg): id {idArg}, model {modelArg}{}
//get Mutators
string getId(){return this->id;}
string getModel(){return this->model;}
friend ostream& operator<<(ostream& out, const Device & item){
    out << "Device ID:"<<item.getId()<<" Model Name:"<<item.getModel();
}
 };
template<typename T>
vector<T> filter(const vector<T> &source, function<bool(T)> predicate){
    vector<T>  result;
    for( int i=0;i< source.size(); ++i){
        if(predicate(source[i])){
            result.push_back(source[i]);
        }
        }
    return result;
}

template<typename T>
void printResult(const vector<T> &source){
    for(int i = 0; i < source.size(); ++i){
        std::cout << source[i] << endl;
}
}

function<bool(int)> isNumGreaterthanAny(int searchKey){
    //predicate function
    //fn returns boolean but i/p is int : 
    // predicate(fn) obj of class function<bool(int)> which represents the function predicate returns boolean that has arg int
    function<bool(int)> predicate = [searchKey](int item){ return item > searchKey;};
    return predicate;
}

function<bool(string)> checkStringWithAny(string s ){
    function<bool(string)> predicate = [s](string item){ return item[0] == s[0];};
    return predicate;
}
 
function<bool(string)> checkIdWithAny(string s ){
    function<bool(string)> predicate = [s](string item){ return item == s;};
    return predicate;
}
int main() {
    vector<int> numbers = {1,4,3,6,7,9,12};
    printResult(filter(numbers , isNumGreaterthanAny(5)));
     std::cout << endl;
     printResult(filter(numbers , isNumGreaterthanAny(7)));
     std::cout << endl;
    printResult(filter(numbers , isNumGreaterthanAny(11)));
    std::cout << endl;

   vector<string> names = {"Bosch", "KOR" , "ADU", "GTP"};
printResult(filter(names , checkStringWithAny("Bosch")));

vector<Device> devices;
Device d1 {"D1", "M1"};
Device d2 {"D2", "M1"};
Device d3 {"D3", "M2"};
Device d4 {"D4", "M2"};
devices.push_back(d1);
devices.push_back(d2);
devices.push_back(d3);
devices.push_back(d4);
printResult(filter<devices>(devices,, [] (Device item) {return item.geModel() == "M1";}));

    return 0;
}