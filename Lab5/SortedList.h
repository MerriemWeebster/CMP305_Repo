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
		
		//your code

	}

	friend SortedClass<Object>* Union(const SortedClass<Object>& list1,
		const SortedClass<Object> & list2)
	{
		SortedClass<Object>* result = new SortedClass<Object>;
		//your code

		return result;
	}

};


