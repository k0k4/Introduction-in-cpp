#include "gods.h"

template<class T>
Link<T>* Link<T>::insert(Link<T>* n)
{
	
	
	if (n == 0) return this;
	if (this == 0) return n;
	n->succ = this;
	if (prev) prev->succ = n;
	n->prev = prev;
	prev = n;
	
	return n;
	
}

