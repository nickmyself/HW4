//
//  main.cpp
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#include <iostream>
#include "Item.h"
#include "LinkedlistST.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main13123131(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    int N;
    N = 100000;
    clock_t begin,end;
    ST st;
    for (int i=0;i<N;i++)
    {
        Item it;
        it.rand();
  //      cout<<it.key()<<" "<<it.INFO()<<endl;
        st.insert(it);
    }
    Key v = 0;
    double result = 0;
    for (int i = 0; i < 10000; i++) {
        v=1 + (int) (element * (::rand() / (RAND_MAX + 1.0)));
        begin = clock();
        st.search(v);
        end = clock();
        double t = double (end-begin)/CLOCKS_PER_SEC * 1000;
        result += t;
    }
    result=result/10000*1000;
    
    cout<<"ST contains: "<<st.count()<<" elements"<<endl;
  //  if (result.null())
  //  cout<<"Can not find the Key:"<<v;
  //  else
  //  cout<<"Key: "<<result.key()<<" Value:"<<result.INFO();
   // double timeConsumed_ = double (end-begin)/CLOCKS_PER_SEC * 1000;
    cout<<endl<<result<<" ms";
    
    return 0;
    
}

