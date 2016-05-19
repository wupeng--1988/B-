#pragma once
#include "node.h"
template<typename KeyType>
class InnerNode :
	public Node<KeyType>
{
public:
	InnerNode(void);
	~InnerNode(void);
	void Update(int index);
	bool Isleaf() override;
	bool IsHalfFull() override;
	bool IsFull() override;
	Node<KeyType>* Split() override;
	Node<KeyType>* Insert(void* ptr, KeyType key_value)override;
	int Search(KeyType key_value) override;
	void* Find(KeyType key_value)override;

};

