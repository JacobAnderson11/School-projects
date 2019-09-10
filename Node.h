#include<cstddef>

template <typename item_type>
struct Node {

	item_type data;
	Node* next;

		Node(const item_type& data_item, Node* next_ptr = NULL) :
		data(data_item), next(next_ptr) {}
};

