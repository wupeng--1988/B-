#include "BPTree.h"


template<typename KeyType>
void* BPTree::Find(KeyType key_value)
{
	if (root_==NULL)
	{
		return NULL;
	}
	return root_->Find(key_value);
}

template<typename KeyType>
bool BPTree::Insert(void* record_pointer,KeyType key_value)
{
	Node<KeyType>* new_node=root_->Insert(record_pointer,key_value);
	if (new_node==nullptr)//根节点无分裂
	{
		return true;
	}
	else//根节点分裂
	{
		Node<KeyType>* new_root=new Node<KeyType>();
		new_root->size_=1;
		new_root->pointer_[0]=root_;
		new_root->pointer_[1]=new_node;
		root_=new_root;
		new_node=NULL;
		InnerNode*(root_)->Update(1);
		return true;
	}
}
