#include "Node.h"

template<typename KeyType>
Node<KeyType>::Node(void)
{
	size = 0;
	capacity = 0;
}

template<typename KeyType>
Node<KeyType>::~Node(void)
{
}

template<typename KeyType>
bool Node<KeyType>::IsLeaf(void)
{
	return false;
}

template<typename KeyType>
bool Node<KeyType>::IsFull(void)
{
	return false;
}

template<typename KeyType>
bool Node<KeyType>::IsHalfFull(void)
{
	return bool();
}
