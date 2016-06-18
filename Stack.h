/*
* 实现栈的基本操作，接口包含：
*	Stack<T>()
*	unsigned Size()
*	bool IsEmpty()
*	void Push(T s)
*	void Pop()
*	T &Top()
* 实现方法分别基于数组和链表	
* 使用数组时：
*   默认数组初始长度为4
*	Size()大于数组长度时，数组长度增加一倍
*	Size()小于数组长度的1/4时，缩小数组长度的一半
* 
* 备注：
*	考虑程序简单，这里不对new失败做处理，业务需要则可以在Push和Pop的操作中catch异常
*/

#ifndef STACK_H__
#define STACK_H__

namespace YL
{

	/*
	* 基于数组的stack
	*/
	template<typename T>
	class AStack
	{
	public:

		//数组最小长度
		#define MINI_ARRAY_SIZE 4

	public:

		AStack()
		{
			m_uSize = 0;
			m_uArraySize = 0;
			m_pData = NULL;
		}

		~AStack()
		{
			if(NULL != m_pData)
			{
				delete[] m_pData;
			}
		}

		unsigned Size()
		{
			return m_uSize;
		}

		bool IsEmpty()
		{
			return (0 == m_uSize);
		}

		void Push(T &v)
		{
			if(m_uArraySize == m_uSize)
			{
				_Resize(m_uSize * 2);
			}

			m_pData[m_uSize] = v;
			++m_uSize;
		}

		void Pop()
		{
			--m_uSize;
			if(m_uSize == m_uArraySize/4)
			{
				_Resize(m_uArraySize/2);
			}
		}

		T &Top()
		{
			if(IsEmpty())
			{
				//抛出段错误
				return *(T *)NULL;
			}
			return m_pData[m_uSize - 1];
		}

	private:

		//重置数组长度，由函数外保证数据不丢失
		void _Resize(unsigned uResize)
		{
			if(uResize < MINI_ARRAY_SIZE)
			{
				uResize = MINI_ARRAY_SIZE;
			}

			T *pNew = new T[uResize];
			for(unsigned i=0; i<m_uSize; ++i)
			{
				pNew[i] = m_pData[i];
			}

			delete[] m_pData;
			m_pData = pNew;
			m_uArraySize = uResize;
		}

	private:

		//栈大小
		unsigned m_uSize;

		//指向栈元素数组起始地址
		T *m_pData;

		//数组大小
		unsigned m_uArraySize;
	};

	/*
	* 基于链表的stack
	*/
	template<typename T>
	class LStack
	{
	public:	
		struct Node
		{
			T data;
			Node *pNext;
		};

	public:

		LStack()
		{
			m_uSize = 0;
			m_pTop = NULL;
		}

		~LStack()
		{
			Node *p = m_pTop;
			Node *temp = m_pTop;
			while(NULL != p)
			{
				temp = p->pNext;
				free(p);
				p = temp;
			}
		}

		unsigned Size()
		{
			return m_uSize;
		}

		bool IsEmpty()
		{
			return (0 == m_uSize);
		}

		void Push(T &v)
		{
			Node *p = new Node;
			p->data = v;
			p->pNext = m_pTop;
			m_pTop = p;
			++m_uSize;
		}

		void Pop()
		{
			if(NULL != m_pTop)
			{
				Node *p = m_pTop;
				m_pTop = p->pNext;
				free(p);
				--m_uSize;
			}
		}

		T& Top()
		{
			if(NULL == m_pTop)
			{
				return *(T *)NULL;
			}

			return m_pTop->data;
		}

	private:

		//链表长
		unsigned m_uSize;

		//指向栈顶
		Node *m_pTop;
	};
}


#endif

