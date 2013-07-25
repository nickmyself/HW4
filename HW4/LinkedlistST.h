//
//  LinkedlistST.h
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#ifndef HW4_LinkedlistST_h
#define HW4_LinkedlistST_h

#include "Item.h"
class ST
{
private:
    Item nullItem;
    struct node
    { Item item; node* next;
        node(Item x,node* t)
        { item = x; next = t;}
    };
    typedef node *link;
    int N;
    link head;
    Item searchR( link t, Key v)
    { if (t == 0)
      return nullItem;
      if (t->item.key() == v)
      return t->item;
        return searchR(t->next,v);
    }
public:
    ST()
    { head = 0; N=0; }
    
    int count()
    { return N;}
    
    Item search(Key v)
    { return searchR(head,v); }
    
    link findnode(link t,Key v)
    { if (t ==0)
        return t;
        if (t->item.key() == v) 
            return t;
        
        return findnode(t->next,v);
    }
    
        
    
    
    void insert (Item x)
    {
        Item item = search(x.key());
        if (!item.null()) {
            findnode(head,x.key())->item.setInfo(x.INFO());
        }
        else {
            head = new node (x, head);
            N++;
        }

    }
    
};


#endif
