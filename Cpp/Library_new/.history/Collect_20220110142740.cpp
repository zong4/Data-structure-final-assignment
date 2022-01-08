#include "Collect.h"
#include "Shop.h"

int CollecttoShop(int id,Shop&s,Collect&c){
     if(!s.judgeId(id))return 0;
     c.Delete(id,1);
     s.insert(id);
     return 1;
}
int ShoptoCollect(int id,Shop&s,Collect&c){
     if(!c.judgeId(id))return 0;
     s.Delete(id,1);
     c.insert(id);
     return 1;
}