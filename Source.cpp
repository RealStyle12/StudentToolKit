template <class T>
class Queue {
	struct Nod {
		T info;
		Nod* next;
	};
	Nod *first, *last;
public:
	Queue() {
		first = last = NULL;
	}
	Queue(const Queue&q) {
		first = last = NULL;
		Nod*p = q.first;
		while (p != NULL) {
			push(p->info);
			p = p->next;
		}
	}
	Queue& operator=(const Queue&q) {
		if (&q != this) {
			while (!isEmpty()) {
				(void)pull();
			}
			Nod*p = q.first;
			while (p) {
				this->push(p->info);
				p = p->next;
			}
		}
		return *this;
	}
	bool isEmpty(void) {
		return (NULL == first);
	}
	bool hasFirst(void*p) {
		p = (void*)first;
		return !!p;
	}
	T pull(void) {
		if (first != NULL ) {
			Nod*p = first;
			first = p->next;
			if (first == NULL)
				last = NULL;
			T rez = p->info;
			delete p;
			return rez;
		}
	}
	T front(void) {
		assert(first);
		if (first != NULL) {
			return first->info;
		}
	}
	void push(T val)
	{
		Nod*p = new Nod;
		p->info = val;
		p->next = NULL;
		if (isEmpty())
			first = p;
		else
			last->next = p;
		last = p;
	}
	~Queue() {
		while (!isEmpty())
			(void)pull(); 
	}
};

template <class T>
class Stack {
	struct Nod {
		T info;
		Nod* next;
	};
	Nod *first, *last;
public:
	Stack() {
		first = last = NULL;
	}
	Stack(const Stack&q) {
		first = last = NULL;
		Nod*p = q.first;
		while (p != NULL) {
			push(p->info);
			p = p->next;
		}
	}
	Stack& operator=(const Stack&q) {
		Stack<T> aux;
		if (&q != this) {
			while (!isEmpty()) {
				(void)pull();
			}
			Nod*p = q.first;
			while (p) {
				aux.push(p->info);
				p = p->next;
			}
			p = aux.first;
			while (p) {
				this->push(p->info);
				p = p->next;
			}
		}
		return *this;
	}
	bool isEmpty(void) {
		return (first == NULL);
	}
	bool hasFirst(void*p) {
		p = (void*)first;
		return !!p;
	}
	T pull(void) {
		if (first != NULL) {
			Nod*p = first;
			first = p->next;
			if (first == NULL)
				last = NULL;
			T rez = p->info;
			delete p;
			return rez;
		}
	}
	T front(void) {
		if (first != NULL) {
			return first->info;
		}
	}
	void push(T val)
	{
		Nod*p = new Nod;
		p->info = val;
		p->next = NULL;
		if (isEmpty()) {
			first = last = p;
		}
		else {
			p->next = first;
			first = p;
		}
	}
	~Stack() {
		while (!isEmpty())
			(void)pull();
	}
};

//Returns an array.
template<class T> void QuickSort(T a[], const int& leftElement, const int& rightElement){ 
	if (leftElement < rightElement) {

		T pivotValue = a[leftElement];
		int left = leftElement - 1;
		int right = rightElement + 1;

		while(true) {

			while (a[--right] > pivotValue);
			while (a[++left] < pivotValue);

			if (left >= right) break;

			T aux = a[right];
			a[right] = a[left];
			a[left] = aux;
		}

		int pivot = right;
		QuickSort(a, leftElement, pivot);
		QuickSort(a, pivot + 1, rightElement);
	}
}

template<typename T>
class BinaryTreeNode {
private:
	T info;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

public:
	BinaryTreeNode(const T& val) : info(val), left(NULL), right(NULL) {

	}

	const T& getVal() const {
		return(info); 
	}
	void setVal(const T& val) { 
		info = val; 
	}

	void addChild(BinaryTreeNode<T>* p) {
		const T& other = p->getVal();
		if (other > info)
			if (right)
				right->addChild(p);
			else
				right = p;
		else
			if (left)
				left->addChild(p);
			else
				left = p;
	}
	const BinaryTreeNode<T>* getLeft() { 
		return(left); 
	}
	const BinaryTreeNode<T>* getRight() { 
		return(right); 
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};