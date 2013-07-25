//
//  BST.h
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#ifndef HW4_BST_h
#define HW4_BST_h
#include <iostream>
#include "Item.h"
using namespace std;

class BST
{
    
private:
    Item nullItem;
    struct node
    { Item item; node *l,*r;
        node (Item x)
        {item =x; l=0; r=0;}
    };
    typedef node *link;
    link head;
    int N=0;

    Item searchR(link h,Key v)
    {
    if (h == 0) return nullItem;
    if (h->item.key() == v) return h->item;
    if (h->item.key() < v) return searchR(h->r,v);
    if (h->item.key() > v) return searchR(h->l,v);
    }
    
    
    void insertR(link &h,Item x)
    {
        /*
        if (h==0){h = new node(x);N++;
            return;
        }
    Key temp = h->item.key();
    if (temp > x.key())
        insertR(h->l,x);
    else if (temp < x.key())
        insertR(h->r,x);
    else if (temp == x.key())
        h->item.setInfo(x.INFO());
    return;         
        */
      //  cout<<x.key()<<endl;
        while (h!=0) {
            Key temp = h->item.key();
            if (temp > x.key()) 
                h=h->l;
            if (temp < x.key())
                h=h->r;
            if (temp == x.key())
            {h->item.setInfo(x.INFO());return;}
        }
        h = new node (x);
        N++;  
        return; 
}

public:
    BST()
    {head = 0;}
    int count()
    { return N;}
    Item search(Key v)
    { return searchR(head,v);}
    
    void insert(Item x)
    {insertR(head,x);}
    
};



#endif
