#include "Collect.h"
#include "Shop.h"

int CollecttoShop(int id, Shop& s,Collect&c) {
    if (!c.judgeId(id)) {
        cout <<"fff"<< endl;
        return 0;
    }
    s.insert(s.book[id]);
    c.Delete(id);
    return 1;
}
void Collect::show(){
    cout << "fff:";
     DataBase::show();
}
