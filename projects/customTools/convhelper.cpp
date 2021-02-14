//
// Created by Administrator on 2/10/2021.
//

#include "convhelper.h"
#include <sstream>


template<class T>
ConvHelper<T>::ConvHelper(T data, std::string format, bool ok_bigEn):
m_data(data), m_format(format), is_bigEndian(ok_bigEn)
{
    if(m_format != "hex" && m_format != "array")
        throw;
}

template<class T>
inline void ConvHelper<T>::setStrFormat(const std::string &format)
{
    if(m_format != "hex" && m_format != "array")
        throw;
    m_format = format;
}

template<class T>
inline std::string ConvHelper<T>::result() const
{
    char* start = (char *)(&m_data);
    int length = sizeof(T);
    uint8_t array[length];
    for(int i = 0; i < length; i++)
        array[i] = (uint8_t)(*(start + i));

    std::stringstream stream;

    if(m_format == "hex")
    {

    }
    else if(m_format == "array")
    {
        stream << '{';
        for(int i = 0; i < length; i++)
        {
            stream << std::hex << array[i];
            if(i != length - 1)
                stream << ',';
        }
        stream << '}';
    }

    return stream.str();



}





