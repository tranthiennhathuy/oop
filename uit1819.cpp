#include<bits/stdc++.h>

using namespace std;

class nguoi {
    private:
     int O,C,E,A,N;
    public:
   //  void import();
   //  void export();
     void evaluation();
     friend istream& operator >> (istream&, nguoi&);
     friend ostream& operator << (ostream&, nguoi);
};

istream& operator >> (istream& in, nguoi& x){
    in>>x.O>>x.C>>x.E>>x.A>>x.N;
    return in;
}

ostream& operator << (ostream& out, nguoi x){
    out<<"O"<<x.O<<"-"<<"C"<<x.C<<"-"<<"E"<<x.E<<"-"<<"A"<<x.A<<"-"<<"N"<<x.N<<endl;
    return out;
}

void nguoi::evaluation(){
    if(C<=30||N>=70)cout<<"luu y"<<endl;
}

int main(){
    int n;
    cin>>n;
    nguoi a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    for(int i=0;i<n;i++){
     cout<<a[i];
     a[i].evaluation();
    }
}
