#include <iostream>

using namespace std;

const int MAX_QUEUE (5);
const int MAX_SPEC (20);

struct hospital_queue
{
    string names;
    int spec ;
    bool status;
    int len ;

    hospital_queue(){
        len =0;
        spec =0;
    }

    hospital_queue(int _spec){
        len=0;
        spec=_spec;
    }


    
};


int main(){
    return 0;
}