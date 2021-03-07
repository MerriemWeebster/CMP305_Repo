#pragma once
#include "List.h"
class SortedOrderMismatchException { };

template <typename Object>
class SortedClass : public List<Object> {

public:

	List<Object>::iterator insert(const Object&  x)
	{
		typename List<Object>::iterator itr = List<Object>::begin();

		while (itr != List<Object>::end() && *itr < x) {
			++itr;
		}
		//Now we have found the node bigger than x. 
		//X needs to be inserted behind that node.
		List<Object>::insert(itr, x);

	}
	List<Object>::iterator erase(const Object & x)
	{
		typename List<Object>::iterator itr = List<Object>::begin();

		while (itr != List<Object>::end() && *itr < x) {
			++itr;
		}
		//Now we have found the node bigger than x. 
		//X needs to be inserted behind that node.
		List<Object>::erase(itr);
	}
	
	List<Object>::iterator insert(List<Object>::iterator itr, const Object & x)
	{
		if (itr == List<Object>::begin()){ //insert at first node
			if (x < ++itr) {
				List<Object>::insert(itr, x);
				return --itr;
			}
			else {
				throw SortedOrderMismatchException;
			}
		}
		else if (x > *(--itr) && x <= *(++itr)) {//insert at any other node
			List<Object>::insert(itr, x);
			return --itr;
	   }
		else {
			throw SortedOrderMismatchException;
		}
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
				result++; 
				itr1++; 
				itr2++;
			}
		}
		
		return result;	

	}

	friend SortedClass<Object>* Union(const SortedClass<Object>& list1,
		const SortedClass<Object> & list2)
	{
		SortedClass<Object>* result = new SortedClass<Object>;
		
		SortedClass<Object> itr1 = list1.begin();
		SortedClass<Object> itr2 = list2.begin();

		while(true)
		{
			if(itr1 == list1.end())
			{
				std::copy(itr2, itr2.end(), result);
				return result;
			}

			if(itr2 == list2.end())
			{
				std::copy(itr1, itr1.end(), result);
				return result;
			}

			if(*itr1 < *itr2)
			{
				*result = *itr1;
				itr1++;
			}
			else if(*itr1 > *itr2)
			{
				*result = *itr2;
				itr2++;
			}
			else
			{
				*result = *itr1;
				itr1++;
				itr2++;
			}

			result++;
		}
	}

};


