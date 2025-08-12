#include <bits/stdc++.h>
using namespace std;

struct nguoi {
    string ten, nsinh, cmnd, dchi;
};

class dat {
protected:
    string cn;
    nguoi sohuu;
    int sothua, soto;
    string diachi;
    int dtich;
    string ngaycap;
    int thue;
public:
    virtual ~dat() {}
    void setthue(int m) {
        this->thue = m * (this->dtich);
    }
    friend istream& operator>>(istream&, dat&);
    friend ostream& operator<<(ostream&, const dat&);
    virtual int getthue() { return this->thue; }
    virtual void evaluate() = 0;
    virtual void setnam(int) = 0;
};

class nn : public dat {
private:
    int namhh;
public:
    void setnam(int temp) override {
        this->namhh = temp;
    }
    void evaluate() override {
        if (this->namhh > 2025) cout << "con han" << endl;
        else cout << "het han" << endl;
    }
};

class dato : public dat {
public:
    void setnam(int) override {}
    void evaluate() override {}
};

istream& operator>>(istream& in, dat& x) {
    in >> x.cn;
    in.ignore();
    getline(in, x.sohuu.ten);
    in >> x.sohuu.nsinh >> x.sohuu.cmnd >> x.sohuu.dchi;
    in >> x.sothua >> x.soto >> x.diachi >> x.dtich >> x.ngaycap;
    return in;
}

ostream& operator<<(ostream& out, const dat& x) {
    out << x.sohuu.ten << " - Thue: " << x.thue;
    return out;
}

int main() {
    int slnn, slo;
    cin >> slnn >> slo;
    int size = slnn + slo;
    vector<dat*> a(size);

    for (int i = 0; i < size; i++) {
        if (i < slnn) {
            int m, temp;
            a[i] = new nn;
            cin >> *a[i] >> m >> temp;
            a[i]->setthue(m);
            a[i]->setnam(temp);
        } else {
            a[i] = new dato;
            int m; // gi? s? v?n nh?p m d? tính thu?
            cin >> *a[i] >> m;
            a[i]->setthue(m);
        }
    }

    for (int i = 0; i < slnn; i++)
        a[i]->evaluate();

    for (int i = 0; i < size; i++) {
        cout << *a[i] << endl;
        delete a[i];
    }
}
