#include "Collect.h"
#include "Shop.h"

int CollecttoShop(int id,Shop&s,Collect&c){
     if(!s.judgeId(id))return 0;
     s.insert(c.book[id]);
     c.Delete(id,1);
     return 1;
}
int ShoptoCollect(int id,Shop&s,Collect&c){
     if(!c.judgeId(id))return 0;
     c.insert(s.book[id]);
     s.Delete(id,1);
     return 1;
}