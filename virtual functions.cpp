#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    private:
        string name;
        int age;
        string cur_id;
    public:
        virtual void getdata(){
            cin>>this->name>>this->age;
        }
        virtual void putdata(){
            cout<<name<<" "<<age;
        }  
};

class Professor:public Person{
        private:
            int publications;
            static int cur_id_temp;
            int cur_id;
        public:
            void getdata(){
                cur_id=cur_id_temp++;
                Person::getdata();
                cin>>this->publications;
            }
            void putdata(){
                Person::putdata();
                cout<<" "<<this->publications<<" "<<cur_id<<endl;
            }     
};

class Student:public Person{
    private:
        int mark[6];
        static int cur_id_temp;
        int cur_id;
    public: 
        void getdata(){
            cur_id=cur_id_temp++;
            Person::getdata();
            for(int q=0;q<6;q++)cin>>mark[q];
        } 
        void putdata(){
            Person::putdata();
            cout<<" ";
            for(int q=0;q<6;q++)cout<<mark[q]<<" ";
            cout<<this->cur_id<<endl;
        }
};

int Professor::cur_id_temp=1;
int Student::cur_id_temp=1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
