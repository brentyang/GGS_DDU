/*
* ʵ��ջ�Ļ����������ӿڰ�����
*	Stack<T>()
*	unsigned Size()
*	bool IsEmpty()
*	void Push(T s)
*	void Pop()
*	T &Top()
* ʵ�ַ����ֱ�������������	
* ʹ������ʱ��
*   Ĭ�������ʼ����Ϊ4
*	Size()�������鳤��ʱ�����鳤������һ��
*	Size()С�����鳤�ȵ�1/4ʱ����С���鳤�ȵ�һ��
* 
* ��ע��
*	���ǳ���򵥣����ﲻ��newʧ��������ҵ����Ҫ�������Push��Pop�Ĳ�����catch�쳣
*/

#ifndef STACK_H__
#define STACK_H__

namespace YL
{

	/*
	* ���������stack
	*/
	template<typename T>
	class AStack
	{
	public:

		//������С����
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
				//�׳��δ���
				return *(T *)NULL;
			}
			return m_pData[m_uSize - 1];
		}

	private:

		//�������鳤�ȣ��ɺ����Ᵽ֤���ݲ���ʧ
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

		//ջ��С
		unsigned m_uSize;

		//ָ��ջԪ��������ʼ��ַ
		T *m_pData;

		//�����С
		unsigned m_uArraySize;
	};

	/*
	* ���������stack
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

		//����
		unsigned m_uSize;

		//ָ��ջ��
		Node *m_pTop;
	};
}


#endif

