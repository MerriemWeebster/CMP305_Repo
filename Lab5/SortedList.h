#pragma once
#include "List.h"
class SortedOrderMismatchException { };

template <typename Object>
class SortedClass : public List<Object> {

public:

	List<Object>::iterator insert(const Object&  x)
	{
		typename List<Object>::iterator itr = List<Object>::begin();
       
      

	}
	List<Object>::iterator erase(const Object & x)
	{
		
	}
	
	List<Object>::iterator insert(List<Object>::iterator itr, const Object & x)
	{
       
	}


	friend SortedClass<Object>* intersection(const SortedClass<Object>& list1,
		const SortedClass<Object> & list2)
	{
		SortedClass<Object>* result = new SortedClass<Object>;
		
		SortedClass<Object> itr1 = list1.begin();
		SortedClass<Object> itr2 = list2.begin();

		while(itr1 != list1.end() && itr2 != list2.end())
		{
			if(*itr1 < *itr2)
				itr1++;
			else if(*itr1 > *itr2)
				itr2++;
			else
			{
				*result = *itr1;
				++result; ++itr1; ++itr2;
			}
		}
		
		return result;	

	}

	friend SortedClass<Object>* Union(const SortedClass<Object>& list1,
		const SortedClass<Object> & list2)
	{
		SortedClass<Object>* result = new SortedClass<Object>;
		//your code

		return result;
	}

};


