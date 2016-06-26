/*
* @file		: TCallBack.h
* @brief	: 基于ID的回调模板类
* @author	: brentyang
* @version	: 1.0
* @history	: 2016-06-26
* @note		: 内部数据结构基于std::map构建，若考虑性能，可以考虑使用hash_map或者unorder_map
*			  当回调函数不需要参数时，可以在实例化模板类对象时使用任意参数，并在回调时将其传入，并不使用
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