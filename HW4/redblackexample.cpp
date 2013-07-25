//
//  redblackexample.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/5/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#include "redblack.h"
#include <iostream>
#include "Item.h"
#include <ctime>
#include <cstdlib>
const int N = 1000000;
using namespace std;
double statred();

int main(){
    double result = statred();
    cout<<"N = "<<N<<". The average percentage of red nod is "<<result<<"%. ";
}

double statred(){
    srand((unsigned)time(NULL));
    double result=0;
    for (int i =0; i<100; i++) {
    redblack ST;
    for (int i=0; i<N; i++) {
        Item item;
        item.rand();
        //cout<<item.key()<<" "<<item.INFO()<<endl;
        ST.insert(item);
    }
    int k = ST.countred();
    cout<<"Total Node:"<<ST.count()<<" Red Node: "<<k<<" Ratio:"<<(double) k/ST.count()<<endl;
    /*
    cout<<"The BST contains "<<ST.count()<<" elements"<<endl;
    cout<<"There are "<<k<<" red nodes"<<endl;
     */
    /*
    Key v = 2755;
    Item result = ST.search(v);
    if (result.null())
        cout<<"can not find the key: "<<v<<endl;
    else
        cout<<"Key: "<<v<<" Value: "<<result.INFO();
     */
    result += (double) k/ST.count();
    }
    
    //  cout<<"Round "<<i<<"Finished!"<<endl;
    return  result;
}
