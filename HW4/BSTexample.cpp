//
//  BSTexample.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#include "BST.h"
#include <iostream>
#include "Item.h"
#include <ctime>
#include <cstdlib>
const int N = 1000;
using namespace std;

int main1(){
    
    BST bst;
    for (int i=0; i<N; i++) {
        Item item;
        item.rand();
    //    cout<<item.key()<<" "<<item.INFO()<<endl;
        bst.insert(item);
    }
    cout<<"The BST contains "<<bst.count()<<" elements"<<endl;
    Key v = 755;
    
    Item result = bst.search(v);
    if (result.null())
        cout<<"can not find the key: "<<v<<endl;
    else
        cout<<"Key: "<<v<<" Value: "<<result.INFO();
}