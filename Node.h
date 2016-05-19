#pragma once
template<typename KeyType>
class Node
{
public:
	Node(void);
	~Node(void);
	virtual bool IsLeaf();
	virtual bool IsFull();
	virtual bool IsHalfFull();
	virtual Node<KeyType>* Split();
	virtual Node<KeyType>* Insert(void* ptr ,KeyType key_value);
	virtual int Search(KeyType key_value);
	virtual void* Find(KeyType key_value);
private:
	int capacity_;
	int size_;
	KeyType* key_;
	void** pointer_;
};

