//
//  Item.h
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//


// This is the single node of data struteure
#ifndef HW4_Item_h
#define HW4_Item_h
#include <stdlib.h>
#include <iostream>

static int maxKey = 100000;  // the max key
static int element = 100000;

typedef int Key;

class Item
{
private:
    Key keyval;
    float info;
public:
    Item()
    { keyval = maxKey;}
    Item(Key k, float value)
    { keyval = k; info = value;}
    Key key()
    { return keyval;}
    float INFO()
    { return info;}
    int null()
    { return keyval == maxKey;}
    void rand()
    {   
        keyval = 1 + (int) (element * (::rand() / (RAND_MAX + 1.0))) ;
        info = 1.0*::rand()/RAND_MAX;
    }
    void setInfo(float val)
    { info = val;
    }
    
};



#endif
