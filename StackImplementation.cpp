#include <iostream>
#include <vector>
using namespace std;

//implementation of stack using vector

template <typename T> //T tells us what type of data the stack will have when it is created
class Stack{
private:
    vector<T> v;
public:
    void push(T data){
        v.push_back(data);
    }
    bool empty(){
        if(v.size()==0){ //v.size() gives the no. of elements
            return true;
        }
        return false;
    }
    void pop(){
        if(!empty()){
            v.pop_back(); //removes last element
        }
    }
    T top(){
        return v[v.size()-1]; //last element
    }
};

int main(){
    Stack<int> s; //we gave T as int
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    //Print the content of the stack by popping each element
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

return 0;
}
