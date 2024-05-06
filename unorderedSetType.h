#ifndef H_unorderedSetType
#define H_unorderedSetType

#include "unorderedArrayListType.h"

template <class elemType>
class unorderedSetType : public unorderedArrayListType<elemType>
{
public:
    // Constructor 
    unorderedSetType(int size = 100);

    // Overloading operators
    unorderedSetType<elemType> operator+(const unorderedSetType<elemType>& set);
    unorderedSetType<elemType> operator-(const unorderedSetType<elemType>& set);
};

template <class elemType>
unorderedSetType<elemType>::unorderedSetType(int size) : unorderedArrayListType<elemType>(size)
{
}

// create a new set for the result
template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator+(const unorderedSetType<elemType>& set)
{
    unorderedSetType<elemType> resultSet;

    for (int i = 0; i < this->length; ++i)
    {
        resultSet.insertEnd(this->list[i]);
    }

    for (int i = 0; i < set.listSize(); ++i)
    {
        if (resultSet.seqSearch(set.list[i]) == -1)
        {
            resultSet.insertEnd(set.list[i]);
        }
    }

    return resultSet;
}

template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator-(const unorderedSetType<elemType>& set)
{
    unorderedSetType<elemType> resultSet;

    for (int i = 0; i < this->length; ++i)
    {
        if (set.seqSearch(this->list[i]) != -1)
        {
            resultSet.insertEnd(this->list[i]);
        }
    }

    return resultSet;
}

#endif

