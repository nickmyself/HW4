//
//  Test2.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/6/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//


#include <iostream>
#include "Item.h"
#include "BST.h"
#include "LinkedlistST.h"
#include <ctime>
#include <cstdlib>
using namespace std;
//const int N = 100000;
const int repeat =100;
int binarysearch3( Key key,int low, int high,int key_[]);
double bssttest(int );
double bsttest(int);
int stats(int);

int maintest2(){
    
    stats(10000);
   // stats(180000);

        
}


int stats(int N){
    double result1 = 0;
    double result2 = 0;
    for (int i=0; i<repeat; i++) {
        result1 += bssttest(N);
        result2 += bsttest(N);
    }
    cout<<"BSST: The "<<N<<" inserts take "<<result1/repeat<<" ms"<<endl;
    cout<<"BST:  The "<<N<<" inserts take "<<result2/repeat<<" ms"<<endl;
    cout<<result1/result2<<endl<<endl;
    return 0;
    
}

double bssttest(int N)
{
    srand((unsigned)time(NULL));
   
    
    /*
     Binary search st
     */
    
    int *key_ = new int[N];
    float *val_ = new float[N];
    for (int i=0; i<N ; i++) {
        key_[i] = 0;
        val_[i] = 0;
    }
    ST bsst;
    int k =0;
    clock_t begin,end;
    begin = clock();
    for (int i=0; i<N; i++) {
        Item item;
        item.rand();
        //insert items
        if (binarysearch3(item.key(),0, k,key_) == -1) {
            int j = k;
            while(item.key()<key_[j-1]) {
                if(j==0)
                    break;
                key_[j]=key_[j-1];
                val_[j]=val_[j-1];
                j--;
            }
            key_[j]=item.key();
            val_[j]=item.INFO();
            k++;
        }
        else {
            val_[binarysearch3(item.key(),0, bsst.count(),key_)] = item.INFO();
        }
        

       // bsst.insert(item);
    }
    end = clock();
   //  double result=double (end-begin)/CLOCKS_PER_SEC * 1000;
   // cout<<"BSST: The "<<N<<" inserts take "<<result<<" ms"<<endl;
    delete key_;
    delete val_;
    return double (end-begin)/CLOCKS_PER_SEC * 1000;
}


double bsttest(int N){
    
    clock_t begin,end;
    BST bst;
    begin = clock();
    for (int i=0; i<N; i++) {
        Item item;
        item.rand();
    //    cout<<item.key()<<endl;
    bst.insert(item);
    }
    end = clock();
//    result=double (end-begin)/CLOCKS_PER_SEC * 1000;
//    cout<<"BST: The "<<N<<" inserts take "<<result<<" ms";
    return double (end-begin)/CLOCKS_PER_SEC * 1000;
    
}


int binarysearch3( Key key,int low, int high,int key_[]){
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