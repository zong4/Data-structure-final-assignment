#include "Set.h"

int Set::deleteAll(Time &t){
    for(int i=1;i<size;i++){
        if((this->book[i].getSave()).getYear==t.getYear()&&this->book[i].getSave().getMonth==t.getMonth()&&this->book[i]->getSave().getDay==t.getDay)
        book[i].setNum=0;//将数量置0，表示删除
    }
}