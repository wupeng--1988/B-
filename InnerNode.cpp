#include "InnerNode.h"


template<typename KeyType>
void* InnerNode<KeyType>::Find(KeyType key_value)
{
	int index=Search(key_value);
	assert(index>=0);
	return static_cast<Node*>(pointer_[index])->Find(key_value)��
}

template<typename KeyType>
int InnerNode<KeyType>::Search(KeyType key_value)
{
	for (int i=1;i<=size_;++i)
	{
		if (key_value<key_[i])
		{
			return i-1;
		}
	}
	return size_;
}
template<typename KeyType>
void InnerNode<KeyType>::Update(int index)
{
	Node* p=pointer_[index];
	while (!p->IsLeaf())
	{
		p=p->pointer_[0];//�Ҵ�Ҷ�ڵ�
	}
	key_[index]=p->key_[0];
	p=NULL;
}
template<typename KeyType>
Node<KeyType>* InnerNode<KeyType>::Insert(void* ptr, KeyType key_value)
{
	int index=Search(key_value);
	assert(index>0);
	Node<KeyType>* select_ptr=pointer_[index];
	Node<KeyType>* new_node=static_cast<Node<KeyType>*>(select_ptr)->Insert(ptr,key_value);
	Update(index);
	if (new_node==NULL)//�޷��ѽڵ�
	{
		return NULL;
	}
	else//���ѳ��ڵ�,Ҫ���½ڵ�ӵ�index+1��
	{
		if (!IsFull())//�ڵ�û��,ֱ����λ����
		{
			++size_;
			for (int i=size_-1;i>index;--i)
			{
				pointer_[i+1]=pointer_[i];
				key_[i+1]=key_[i];
			}
			pointer_[index+1]=new_node;//�����ӽڵ�ҵ���Ӧ��λ��
			Update(index+1);
			return NULL;
		}
		else()//����ڵ����ˣ���Ҫ����
		{
			Node<KeyType>* split_node=Split();
			select_ptr=NULL;
			new_node=NULL;
			return split_node;//���µĽڵ�����ڵ�
		}
	}
}

template<typename KeyType>
bool InnerNode<KeyType>::IsFull()
{
	return (size_<capacity_-1);
}

template<typename KeyType>
bool InnerNode<KeyType>::IsHalfFull()
{
	return (size_>=(capacity_-1)/2);
}
template<typename KeyType>
bool InnerNode<KeyType>::Isleaf()
{
	return false;
}