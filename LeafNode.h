#pragma once
#include "node.h"
template<typename KeyType>
class LeafNode :
	public Node<KeyType>
{
public:
	LeafNode(void);
	~LeafNode(void);
	bool isLeaf() override;
	bool isFull() override;
	bool isHalfFull() override;
	void* Find(KeyType key_value)override;
	int Search(KeyType key_value)override;
	Node<KeyType>* Insert(void* ptr ,KeyType key_value) override;
	Node<KeyType>* Split()override;
	int SearchInertPos(KeyType key_value);
	void InsertKey(void* ptr ,KeyType key_value);//不会造成分裂的插入
};

