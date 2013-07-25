//
//  TEST.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/6/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#include "TEST.h"
#include <iostream>
#include "Item.h"
#include "LinkedlistST.h"
#include <ctime>
#include <cstdlib>

using namespace std;
const int N = 142;
const int repeat = 10000;
int binarysearch2( Key key,int low, int high,int key_[]);

int maintest()
{
    srand((unsigned)time(NULL));
 //   clock_t begin,end;
  /*  ST st;
    
    //INSERT ELEMENTS
    for (int i=0;i<N;i++)
    {
        Item it(i,i*0.1);
        
        //      cout<<it.key()<<" "<<it.INFO()<<endl;
        st.insert(it);
    }
    
    
    Key v = 0;
    double result = 0;
    
    for (int i = 0; i < repeat; i++) {
        v=1 + (int) (N * (::rand() / (RAND_MAX + 1.0)));
        begin = clock();
        st.search(v).INFO();
        end = clock();
        double t = double (end-begin)/CLOCKS_PER_SEC * 1000;
        result += t;
    }
    result=result/repeat;
    cout<<"ST contains: "<<st.count()<<" elements"<<endl;
    cout<<"The search cost "<<result<<" ms";
    */
    
    /*
     Binary search st
     */
    
    int key_[N];
    float val_[N];
    for (int i=0; i<N ; i++) {
        key_[i] = 0;
        val_[i] = 0;
    }
    ST bsst;
    for (int i=0; i<N; i++) {
        Item item(i,i*0.1);
        //insert items
        if (binarysearch2(item.key(),0, bsst.count(),key_) == -1) {
            int j=bsst.count();
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
            val_[binarysearch2(item.key(),0, bsst.count(),key_)] = item.INFO();
        }
        bsst.insert(item);
    }
   
    Key v = 0;
    double result = 0;
    clock_t begin,end;
    begin = clock();
    for (int i = 0; i < repeat; i++) {
        v=1 + (int) (N * (::rand() / (RAND_MAX + 1.0)));
        Item x = bsst.search(N/2);
    }
    end = clock();
    result=double (end-begin)/CLOCKS_PER_SEC * 1000;
    cout<<"ST contains: "<<bsst.count()<<" elements"<<endl;
    cout<<"The search cost "<<result<<" ms";

    

    
    result = 0;
    int max = bsst.count()-1;
    begin = clock();
    for (int i=0; i <repeat; i++) {
        v=1 + (int) (N * (::rand() / (RAND_MAX + 1.0)));
        binarysearch2(max,0, max,key_);
    }
    end = clock();
    result=double (end-begin)/CLOCKS_PER_SEC * 1000;
   // result=result/repeat;
     
    
    cout<<endl<<"BSST contains: "<<bsst.count()<<" elements"<<endl;
    cout<<"The search cost "<<result<<" ms";
    
    
    
    return 0;
    
}


int binarysearch2( Key key,int low, int high,int key_[]){
    
    while (low <high) {
        int mid = (low + high)/2;
        
        if (key < key_[mid])
        { high = mid-1; continue;}
        else if (key > key_[mid])
        { low = mid +1; continue;}
        else return mid;    
    }
    return -1;
}

