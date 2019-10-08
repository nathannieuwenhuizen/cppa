template <class T>
class buffer {
public:
	buffer(int size, T type)
	{
		items = new T[size];
	}
	T* items;

};