#pragma once
#include "InnerNode.h"
#include "LeafNode.h"
template<typename KeyType>
class BPTree
{
public:
	void PrintTree();
	void Clear();
	void Build(void** data, int block_size=4096);
	bool Insert(void* record_pointer, KeyType key_value);
	void* Find(KeyType key_value);
	bool Delete(KeyType key_value);
private:
	Node<KeyType>* root_;
	int block_size;
};

