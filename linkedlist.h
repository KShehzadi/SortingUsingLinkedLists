class node
{
	public:
		int data;
		node * next;
};

class LinkedList
{
	private:
		node * head;
	public:
		LinkedList();
		~LinkedList();
		void insert(int v);
		void deletev(int v);
		void print();
		int search(int v);
		void sort();	
};
