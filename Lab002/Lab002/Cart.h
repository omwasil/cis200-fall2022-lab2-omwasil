#pragma once

using namespace std;

#include "Item.h"


class Cart {
private:
	int numberOfItems;
	int maxNumberOfItems;
	Item* items;

public:
	Cart(int maxNumberOfItems) {
		this->numberOfItems = 0;
		this->maxNumberOfItems = maxNumberOfItems;
		items = new Item[maxNumberOfItems];

	}

	void addItem(Item item) {

		this->items[numberOfItems] = item;

		if (numberOfItems == maxNumberOfItems) {
			throw logic_error("The cart is Full!");
		}
		this->numberOfItems++;
	}

	~Cart() {
		delete[] items;
	}
	Cart(const Cart& cart) {
		this->numberOfItems = cart.numberOfItems;
		this->maxNumberOfItems = cart.maxNumberOfItems;
		items = new Item[this->maxNumberOfItems];
		for (int i = 0; i < numberOfItems; i++) {
			this->items[i] = cart.items[i];
		}
	}
	Cart& operator=(const Cart& cart) {
		if (this != &cart) {
			delete[] items;
			this->numberOfItems = cart.numberOfItems;
			this->maxNumberOfItems = cart.maxNumberOfItems;
			items = new Item[maxNumberOfItems];
			for (int i = 0; i < numberOfItems; i++) {
				this->items[i] = cart.items[i];
			}
			return *this;
		}
	}
	void doubleInSize() {
		Item* newItems;
		newItems = new Item[maxNumberOfItems * 2];

		// copy element to new table
		for (int i = 0; i < numberOfItems; i++) {
			newItems[i] = items[i];
		}
		delete[] items;
		items = newItems;
	}

	Item getItem(int index) {
		for (index = 0; index < maxNumberOfItems; index++) {
			if (index < 0 && index >= numberOfItems) {
				throw logic_error("index can't be negitive and >= number of items!");
			}
			return items[index];
		}
	}
};

