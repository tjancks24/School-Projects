//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Array-based implementation.
 @file Bag.h */


#ifndef _BAG
#define _BAG

#include "BagInterface.h"

template<class ItemType>
class Bag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_BAG_SIZE = 6;  
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
   int itemCount;                    // current count of bag items 
   int maxItems;                     // max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	Bag();
	int getCurrentSize() const;
	bool isEmpty() const;
	virtual bool add(const ItemType& newEntry);
	virtual bool remove(const ItemType& anEntry);
	virtual void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const; 
};  // end Bag

#include "Bag.cpp"

#endif
