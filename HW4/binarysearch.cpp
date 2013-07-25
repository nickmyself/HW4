//
//  binarysearch.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#include <iostream>
#include "LinkedlistST.h"
#include <ctime>
#include <cstdlib>
const int N=20000;
using namespace std;

int binarysearch(Key,int,int, int []);

int mainW(){
    srand((unsigned)time(NULL));
    int key_[N];
    float val_[N];
    for (int i=0; i<N ; i++) {
        key_[i] = 0;
        val_[i] = 0;
    }
    ST st;
    for (int i=0; i<N; i++) {
        Item item;
        item.rand();
        
        //insert items
        if (binarysearch(item.key(),0, st.count(),key_) == -1) {
            int j=st.count();
            while(item.key()<key_[j-1]) {
                if(j==0)
                    break;
                key_[j]=key_[j-1];
                val_[j]=val_[j-1];
                j--;
            }
            key_[j]=item.key();
            val_[j]=item.INFO();
        }
        else {
            val_[binarysearch(item.key(),0, st.count(),key_)] = item.INFO();
        }
        
        st.insert(item);
        
    }
    clock_t begin,end;
    Key v = 699;
    double result = 0;
    for (int i=0; i <10000; i++) {
        v=1 + (int) (element * (::rand() / (RAND_MAX + 1.0)));
        begin = clock();
        binarysearch(v,0, st.count(),key_);
        end = clock();
        double t = double (end-begin)/CLOCKS_PER_SEC * 1000;
        result += t;
    }
    result=result/10000*1000;
    
    cout<<"ST contains: "<<st.count()<<" elements"<<endl;
//    if (result==-1)
  //      cout<<"Can not find the Key:"<<v;
 //   else
 //       cout<<"Key: "<<key_[result]<<" Value:"<<val_[result];
  //  double timeConsumed_ = double (end-begin)/CLOCKS_PER_SEC * 1000;
    cout<<endl<<result<<" ms";
    return 0;
    
}

int binarysearch( Key key,int low, int high,int key_[]){
    if (low == high) {
        return -1;
    }
    int mid = (low+high)/2;
    
    if (key_[mid] == key) {
        return mid;
    }
    if (key_[mid]<key) {
        return binarysearch(key,mid+1,high,key_);
    }
    if (key_[mid]>key) {
        return binarysearch(key,low,mid,key_);
    }
    return -1;
}