//
//  redblack.h
//  HW4
//
//  Created by Junwei Zhao on 4/4/13.
//  Copyright (c) 2013 Junwei Zhao. All rights reserved.
//

#ifndef HW4_redblack_h
#define HW4_redblack_h
#include "Item.h"

class redblack 
    {
        
    private:
        int rednum_=0 ;
        enum Color{red,black};
        Item nullItem;
        struct node
        { Item item; node *l,*r;
            Color color;
            node (Item x,Color newcolor)
            {item =x;color = newcolor; l=0; r=0;}
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
            
            if (h==0){
                if (N==0)
                {Color RD = black;h = new node(x,RD);N++;return;}
                Color RD =red; h = new node(x,RD);N++;
                return;
            }
            Key temp = h->item.key();
            if (temp > x.key())
                insertR(h->l,x);
            else if (temp < x.key())
                insertR(h->r,x);
            else if (temp == x.key())
                h->item.setInfo(x.INFO());
            
            if (isRed(h->r) && !isRed(h->l)) h = rotateleft (h);
            if (isRed(h->l) && isRed(h->l->l)) h = rotateright (h);
            if (isRed(h->l) && isRed(h->r)) flipcolors(h);
        }
        
        bool isRed(link h){
            if (h==0)
                return false;
            if (h->color == red)
                return true;
            else
                return false;
        }
        
        link rotateleft(link h){
            link x = h->r;
            h->r = x->l;
            x->l = h;
            x->color = h->color;
            h->color = red;
            return x;
        }
        
        link rotateright(link h){
            link x = h->l;
            h->l = x->r;
            x->r = h;
            x->color = h->color;
            h->color =red;
            return x;
        }
        
        void flipcolors(link h){
            h->color = red;
            h->l->color = black;
            h->r->color = black;
            if(h==head)
                h->color = black;
        }
        
        
    public:
    
        redblack()
        {head = 0;}
        int count()
        { return N;}
        Item search(Key v)
        { return searchR(head,v);}
        void insert(Item x)
        { insertR(head,x); }
        void visit(link h)
        { if (h->color ==red) rednum_++;
            if (h->l != 0) visit(h->l);
            if (h->r != 0) visit(h->r);
        }
        int countred()
        { visit(head);
            return rednum_;
        }
    
    
    };





#endif
