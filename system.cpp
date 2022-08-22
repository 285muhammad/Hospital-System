#include <iostream>

using namespace std;

const int MAX_QUEUE (5);
const int MAX_SPEC (20);

struct hospital_queue
{
    string names[MAX_QUEUE];
    bool status[MAX_QUEUE];
    int spec ;
    int len ;

    hospital_queue(){
        len =0;
        spec =0;
    }

    hospital_queue(int _spec){
        len=0;
        spec=_spec;
    }

    void add_end(string name, bool statu){
        if(len==MAX_QUEUE){
            cout<<"There is no places Sorry"<<endl;
            return;
        }
        names[len]=name;
        status[len]=statu;
        len++;
    }

    void add_front(string name,bool statu){
        if(len==MAX_QUEUE){
            cout<<"There is on places Sorry"<<endl;
            return;
        }
        for(int i=len;i<0;i++){
            names[len]=names[len-1];
            status[len]=status[len-1];
        }
        names[0]=name;
        status[0]=statu;
        len++;
    }


    
};


int main(){
    return 0;
}