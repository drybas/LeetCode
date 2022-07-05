
#include <iostream>
#include <vector>

using namespace std;

// 284. Peeking Iterator

class Iterator {
public:
	struct Data;
	Data* data;
	Iterator(const vector<int>& /*nums*/) { }
	Iterator(const Iterator& iter) { }

	// Returns the next element in the iteration.
	virtual int next() { return 0; }

	// Returns true if the iteration has more elements.
	virtual bool hasNext() const { return false; }
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		hasNext_ = Iterator::hasNext();
		if (hasNext_)
			val_ = Iterator::next();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return val_;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		auto r = val_;
		hasNext_ = Iterator::hasNext();
		if (hasNext_)
			val_ = Iterator::next();

		return r;
	}

	bool hasNext() const {
		return hasNext_;
	}

private:
	int val_;
	bool hasNext_;
};

int main()
{
	//	["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
	//	[[[1, 2, 3]], [], [], [], [], []]

	PeekingIterator pi{ { 1, 2, 3 } };
	std::cout << pi.next();
	std::cout << pi.peek();
	std::cout << pi.next();
	std::cout << pi.next();
	std::cout << pi.hasNext();
}

