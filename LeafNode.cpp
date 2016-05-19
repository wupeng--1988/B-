#include "LeafNode.h"


template<typename KeyType>
void* LeafNode<KeyType>::Find(KeyType key_value)
{
	int index=Search(key_value);
	assert(index>=0);
	return pointer_[index];
}
template<typename KeyType>
int LeafNode<KeyType>::Search(KeyType key_value)
{
	int low_index=0;
	int up_index=size_;
	while (low_index<up_index)
	{
		int mid_index=(low_index+up_index)/2;
		if (key_[mid_index]==key_value)
		{
			return mid_index;
		}
		if (key_[mid_index]<key_value)
		{
			low_index=mid_index;
			continue;
		}
		if (key_[mid_index]>key_value)
		{
			up_index=mid_index;
			continue;
		}
	}
return -1;
}
template<typename KeyType>
bool LeafNode<KeyType>::IsFull()
{
	return (size_<capacity_-1);
}
template<typename KeyType>
bool LeafNode<KeyType>::isHalfFull()
{
	return (size_>(capacity_-1)/2);
}

template<typename KeyType>
bool LeafNode<KeyType>::isLeaf()
{
	return true;
}
template<typename KeyType>
Node<KeyType>* LeafNode<KeyType>::Insert(void* ptr ,KeyType key_value)
{
	int index =SearchInertPos(key_value);
	if (IsFull())//如果满了
	{
		LeafNode<KeyType>* new_node= Split();
		if (index>(capacity_-1)/2)//插入值位于后半截
		{
			new_node->InsertKey(ptr, key_value);
		}
		else
		{
			InsertKey(ptr,key_value);
		}
	}

}
