# cpp_hw6

## 6-1

When allocating a new node throws an exception, unless the exception is handled by the user (who have pointers to the
root), there will be memory leak. So it is better to have unique_ptr to point to a node's children. And we can discard
its recursive destructor because RAII will do this for us.

And I think a copy constructor is not necessary since we can use raw pointer for the global root. So a shallow copy
would be easy as we can merely copy the root pointer.

Besides, search should return raw pointers instead of move unique_ptr<node> out of the function, since this could lead
the node accessible and corrupts the tree.

This modification makes the tree more robust.

## 6-3

I come up with a multi-counter for an array of functions with same type.

## 6-4

See LockFreeStack.h

## 6-5

Leant that. Interesting. This allows counting from zero to 1023 using both hands.

