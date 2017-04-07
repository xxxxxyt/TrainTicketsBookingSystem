template<typename T>
class list {
public:
	/**
	 * TODO
	 * a type for actions of the elements of a list, and you should write
	 *   a class named const_iterator with same interfaces.
	 */
	/**
	 * you can see RandomAccessIterator at CppReference for help.
	 */
	class iterator {
	private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		iterator operator+(const int &n) const {
			//TODO
		}
		iterator operator-(const int &n) const {
			//TODO
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			//TODO
		}
		iterator operator+=(const int &n) {
			//TODO
		}
		iterator operator-=(const int &n) {
			//TODO
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {}
		/**
		 * TODO *it
		 */
		T& operator*() const{}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {}
	};
	/**
	 * TODO Constructs
	 * Atleast three: default constructor, copy constructor and a constructor for std::list
	 */
	list() {}
	list(const fstream &f) {
		/**
		 * import data from this fstream f
		 * export data to f when you destruct this list
		 */
	}
	/**
	 * TODO Destructor
	 */
	~list() {}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 * !!! Pay attentions
	 *   In STL this operator does not check the boundary but I want you to do.
	 */
	T & operator[](const size_t &pos) {}
	/**
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T & front() const {}
	/**
	 * access the last element.
	 * throw container_is_empty if size == 0
	 */
	const T & back() const {}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {}
	iterator end() {}
	/**
	 * checks whether the container is empty
	 */
	bool empty() const {}
	/**
	 * returns the number of elements
	 */
	size_t size() const {}
	/**
	 * clears the contents
	 */
	void clear() {}
	/**
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value.
	 */
	iterator insert(iterator pos, const T &value) {}
	/**
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value is true
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value) {}
	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {}
	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind) {}
	/**
	 * adds an element to the end/begin.
	 */
	void push_back(const T &value) {}
	void push_front(const T &value) {}
	/**
	 * remove the last element from the end/begin.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back() {}
	void pop_front() {}
};