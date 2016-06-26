/*
* @file		: TCallBack.h
* @brief	: ����ID�Ļص�ģ����
* @author	: brentyang
* @version	: 1.0
* @history	: 2016-06-26
* @note		: �ڲ����ݽṹ����std::map���������������ܣ����Կ���ʹ��hash_map����unorder_map
*			  ���ص���������Ҫ����ʱ��������ʵ����ģ�������ʱʹ��������������ڻص�ʱ���䴫�룬����ʹ��
**/

#ifndef TCALLBACK_H__
#define TCALLBACK_H__

#include <map>

template<typename TPraram, typename TFunc>
class TCallBack
{
public:

	TCallBack()
	{

	}

	~TCallBack()
	{

	}

	void Register(int iMsgID, TFunc pFun)
	{
		m_data.insert(std::pair<int, TFunc>(iMsgID, pFun));
	}

	void CallBack(int MsgID, TPraram Prama)
	{
		std::map<int, TFunc>::iterator itor = m_data.find(MsgID);
		if(itor == m_data.end())
		{
			return;
		}

		TFunc pFun = itor->second;
		pFun(Prama);
	}

private:

	std::map<int, TFunc> m_data;
};
	
#endif	//TCALLBACK_H__