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
    
    void run(){
        while (true)
        {
            int choice {menu()};
            if(choice==1)
                add_patient();
            else if (choice ==2 )
                get_next_patient();
            else if (choice ==3 )
                print_patients();
            else 
                break;
            
        }
        
        
    }
    int menu(){
        int choice {0};
        while(choice==0){

            cout<<"1) Add a new Patient"<<endl;
            cout<<"2) Get the next patient"<<endl;
            cout<<"3) Print All patients"<<endl;
            cout<<"4) Exit"<<endl;
            cin>>choice;

            if(!(choice>=1 && choice<=4)){
                cout<<"Invalid Choice, Try Again"<<endl;
                cin>>choice;
            }
        }

        return choice;
    }

    void add_patient(){

        string name;
        bool statu;
        int spec;

        cout<<"Enter your information Specaliazaion , name , status"<<endl;
        cin>>spec>>name>>statu;

        if(statu)
            queues[spec].add_front(name,statu);
        else 
            queues[spec].add_end(name,statu);
        


    }

    void get_next_patient(){
        int spec;
        cout<<"Enter the number of specalizaion"<<endl;
        cin>>spec;
        queues[spec].remove_front();
    }

    void print_patients(){

        cout<<"***********************************************"<<endl;
        for(int i=0;i<MAX_SPEC;i++)
            queues[i].print();

    }

    
};



int main(){
    // hospital_queue queue()=hospital_queue();
    // hospital_queue.
    return 0;
}