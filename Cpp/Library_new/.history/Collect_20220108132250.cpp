#include "Collect.h"

int CollecttoShop(int id,Shop&s,Collect&c){
     if(!s.judgeId(id))return 0;
     c.Delete(id);
     s.insert(id);
     return 1;
}
int ShoptoCollect(int,Shop&s,Collect&c){
     if(!c.judgeId(id))return 0;
     s.Delete(id);
     c.insert(id);
     return 1;
}