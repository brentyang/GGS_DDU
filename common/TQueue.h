#ifndef TQUEQUE_H__
#define TQUEQUE_H__

template<typename T, unsigned int CAPACITY>
class TQueue
{
#define TQUEUE_DATA_LEN (CAPACITY + 1)

public:
	
	TQueue()
	{
		m_head = 0;
		m_tail = 0;
	}

	~TQueue()
	{

	}

	bool Empty()
	{
		return (m_head == m_tail);
	}

	bool Full()
	{
		return (((m_tail + 1) % TQUEUE_DATA_LEN) == m_head);
	}

	unsigned int Size()
	{
		return ((m_tail + TQUEUE_DATA_LEN - m_head) % TQUEUE_DATA_LEN);
	}

	bool Enqueue(const T &value)
	{
		if(Full())
		{
			return false;
		}

		m_data[m_tail] = value;
		m_tail = (m_tail + 1) % TQUEUE_DATA_LEN;
		return true;
	}

	bool Dequeue(T &value)
	{
		if(Empty())
		{
			return false;
		}

		value = m_data[m_head];
		m_head = (m_head + 1) % TQUEUE_DATA_LEN;
		return true;
	}

private:

	T m_data[CAPACITY];

	unsigned int m_head;

	unsigned int m_tail;
};

#endif //TQUEQUE_H__