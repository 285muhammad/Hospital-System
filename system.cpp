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

    void remove_front(){
        cout<<names[0]<<" please to the DR"<<endl;

        for(int i=1;i<len;i++){
            names[i-1]=names[i];
            status[i-1]=status[i];
        }

        len--;
    }

    void print(){

        for(int i=0;i<len;i++){
            cout<<names<<" ";
            
            if(status[i])
                cout<<"urgent"<<endl;
            else 
                cout<<"regular"<<endl;

        }
    }


    
};


struct hospital_system
{
    hospital_queue queues[MAX_SPEC+1];

    hospital_system(){
        for(int i=0;i<MAX_SPEC;i++)
            queues[i]=hospital_queue(i);
    }
};



int main(){
    return 0;
}