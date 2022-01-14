#include "Shop.h"
#include "Collect.h"

int ShoptoCollect(int id,Shop&s,Collect&c){
    if (!s.judgeId(id)) {
        cout<<"rrr"<<endl;
        return 0;
    }
     c.insert(c.book[id]);
     s.Delete(id);
     return 1;
}
int Shop::Countnum(){
    for(int i=1;i<size;i++){
        if(book[i].num!=0){
            Allnum+=book[i].num;
        }
    }
    return Allnum;
}
double Shop::Countprice(){
    for(int i=1;i<size;i++){
        if(book[i].num!=0){
            Allprice+=book[i].num*book[i].getPrice();
        }
    }
    return Allprice;
}
void Shop::show(){
    cout << "ttt:";
    DataBase::show();
}
int Shop::changeNum(int id,int num) {
    if (!judgeId(id)) {
        cout << "vvv" << endl;
        return 0;
    }
    this->book[id].setNum(num);
    return 1;
}
void Shop::showpay(int id) {
    cout << "eee:" << book[id].num*book[id].getPrice()<< endl;
}
