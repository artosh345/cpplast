#include <iostream>
#include <thread>
#include <string>
#include <fstream>
using namespace std;
void base(){
    ifstream obj;
    obj.open("C:\\Users\\ACER\\CLionProjects\\cpplast\\Task_2.txt");
    if(obj.is_open()!=1){
        cout<<"errrrooor";
        exit(0);
    }
    string buff;
    double s=0;
    double avg;
    for(int a=0;a<100;a++){
        obj>>buff;
        s=s+stod(buff);
        buff.clear();

    }
    avg=s/100;
    cout<<endl<<avg<<endl;
    obj.close();
}
void upper(){
    double arr[100];
    ifstream obj;
    obj.open("C:\\Users\\ACER\\CLionProjects\\cpplast\\Task_2.txt");
    string buff;
    int t=0;
    for(int a=0;a<100;a++){
         obj>>buff;
         if(stod(buff)>=0.478){
             arr[t]= stod(buff);
             t++;
         }
    }
    obj.close();
    ofstream obj2;
    obj2.open("C:\\Users\\ACER\\CLionProjects\\cpplast\\Thread_1.txt");
    for(int a=0;a<t;a++){
        obj2<<arr[a]<<endl;
    }
}

void lower(){
    double arr[100];
    ifstream obj;
    obj.open("C:\\Users\\ACER\\CLionProjects\\cpplast\\Task_2.txt");
    string buff;
    int t=0;
    for(int a=0;a<100;a++){
        obj>>buff;
        if(stod(buff)<0.478){
            arr[t]= stod(buff);
            t++;
        }
    }
    obj.close();
    ofstream obj2;
    obj2.open("C:\\Users\\ACER\\CLionProjects\\cpplast\\Thread_2.txt");
    for(int a=0;a<t;a++){
        obj2<<arr[a]<<endl;
    }
}


int main() {
    std::thread thread_1(base);
    thread_1.join();
    thread thread_2(upper);
    thread_2.join();
    thread thread_3(lower);
    thread_3.join();
    cout<<"finfish";
    return 0;
}
