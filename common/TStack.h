#ifndef TSTACK_H__ 
#define TSTACK_H__

template<typename T, int CAPACITY>
class TStack
{
#define INVALID_INDEX -1

public:
	TStack()
	{
		m_pop = INVALID_INDEX;
	}

	~TStack()
	{

	}

	bool Empty()
	{
		return (INVALID_INDEX == m_pop);
	}

	bool Full()
	{
		return (m_pop >= CAPACITY - 1);
	}

	unsigned int Size()
	{
		return (m_pop + 1);
	}

	bool Push(const T &value)
	{
		if(Full())
		{
			return false;
		}

		++m_pop;
		m_data[m_pop] = value;
		return true;
	}

	bool Pop(T &value)
	{
		if(Empty())
		{
			return false;
		}

		value = m_data[m_pop];
		--m_pop;
		return true;
	}

private:
	
	T m_data[CAPACITY];

	int m_pop;
};


#endif //TSTACK_H__