#include <iostream>
#include <vector>

using namespace std;

class MyStack{
    private :
        vector<int> st; 
        //int start;
        int end;

    public:

     MyStack(){ // default constructor
        //start = 0;
     
        st.resize(100);
        end = -1;

     }   

        ~MyStack(){
           // delete[] res;
        }

        void push(int a){
            
            end++;
            st[end] = a;
        }
        
        void pop(){
            if(end > 0)
            end--;
        }

        int top(){
            if(end >=0)
                return st[end];
            return -1; 
        }


};


int main(){

    MyStack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    std::cout << s1.top() << std::endl;
    s1.pop();

    cout << s1.top() << endl;


}