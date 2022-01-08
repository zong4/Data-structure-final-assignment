#include "Shop.h"

int CollecttoShop(int id,Shop&s,Collect&c){
     if(!s.judgeId(id))return 0;
     c.Delete(id,c.book[id].getNum());
     s.insert(s.book[id]);
     return 1;
}
int ShoptoCollect(int id,Shop&s,Collect&c){
     if(!c.judgeId(id))return 0;
     s.Delete(id,s.book[id].getNum());
     c.insert(c.book[id]);
     return 1;
}
int Shop::Countnum(){
    for(int i=1;i<size;i++){
        if(book[i].getNum()!=0){
            Allnum+=book[i].getNum();
        }
    }
    return Allnum;
}
double Shop::Countprice(){
    for(int i=1;i<size;i++){
        if(book[i].getNum()!=0){
            Allprice+=book[i].getNum()*book[i].getPrice();
        }
    }
    return Allprice;
}

