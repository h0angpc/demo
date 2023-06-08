#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>

using namespace std;

static int tongban = 0;
static double Tmax = 0;

class Friend {
protected:
    string name;
    int age;
public:
    Friend() {
        name = '\0';
        age = 0;
    }
    virtual void Nhap() {
        tongban++;
        cin >> name >> age;
    }
    virtual void Xuat() = 0;
    virtual double Time() = 0;
};


class BestFriend : public Friend {
protected:
    string phone;
public:
    BestFriend() {
        phone = '\0';
    }
    static double TimeBFF;
    void Nhap() {
        Friend::Nhap();
        cin >> phone;
    }
    void Xuat() {
        cout << "Ten: " << name << ", tuoi: " << age << ", so dien thoai: " << phone << endl;
    }
    double Time() {
        TimeBFF += 5;
        if (Tmax < 5) {
            Tmax = 5;
        }
        return 5;
    }
};
double BestFriend::TimeBFF = 0;

class BoyFriend :public Friend {
protected:
    long long income;
public:
    BoyFriend() {
        income = 0;
    }
    static double TimeBF;
    void Nhap() {
        Friend::Nhap();
        cin >> income;
    }
    void Xuat() {
        cout << "Ten: " << name << ", tuoi: " << age << ", thu nhap: " << income << "d" << endl;
    }
    double Time() {
        TimeBF += 5 * income / 10000000.0;
        if (Tmax < 5 * income / 10000000.0) {
            Tmax = 5 * income / 10000000.0;
        }
        return 5 * income / 10000000.0;
    }
};

double BoyFriend::TimeBF = 0;

class OtherFriend :public Friend {
protected:
    double attractiveness;
public:
    OtherFriend() {
        attractiveness = 0;
    }
    static double TimeOF;
    void Nhap() {
        Friend::Nhap();
        cin >> attractiveness;
    }
    void Xuat() {
        cout << "Ten: " << name << ", tuoi: " << age << ", do thu hut: ";
        if (attractiveness < 0.4) {
            cout << "thap" << endl;
        }
        else if (attractiveness >= 0.7) {
            cout << "cao" << endl;
        }
        else
            cout << "trung binh" << endl;
    }
    double Time() {
        TimeOF += attractiveness * 20 / tongban;
        if (Tmax < attractiveness * 20 / tongban) {
            Tmax = attractiveness * 20 / tongban;
        }
        return attractiveness * 20 / tongban;
    }
};

double OtherFriend::TimeOF = 0;

int main() {
    int n;
    vector<Friend*> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Friend* p;
        int type;
        cin >> type;
        switch (type) {
        case 1:
            p = new BestFriend;
            break;
        case 2:
            p = new BoyFriend;
            break;
        case 3:
            p = new OtherFriend;
            break;
        default:
            p = NULL;
            break;
        }
        if (p != NULL) {
            p->Nhap();
            a.push_back(p);
        }
    }
    for (int i = 0; i < n; i++) {
        a[i]->Time();
    }
    cout << "Thong ke: ";
    if (BestFriend::TimeBFF > 0) {
        cout << "\n-Thoi gian cho ban than: " << BestFriend::TimeBFF << " h";
    }
    if (BoyFriend::TimeBF > 0) {
        cout << "\n-Thoi gian cho ban trai: " << BoyFriend::TimeBF << " h";
    }
    if (OtherFriend::TimeOF > 0) {
        cout << "\n-Thoi gian cho ban trai khac: " << OtherFriend::TimeOF << " h";
    }
    cout << "\nNguoi ban quan trong nhat: " << endl; 
    for (int i = 0; i < n; i++) {
        if (Tmax == a[i]->Time()) {
            a[i]->Xuat();
        }
    }
    return 0;
}
