//
// Created by Administrator on 2/10/2021.
//

#ifndef CONVHELPER_H
#define CONVHELPER_H
#include <iostream>


template<class T>
class ConvHelper {
public:
    ConvHelper() = delete;
    ConvHelper(T data):m_data(data), m_format("array"), is_bigEndian(true)
    { }
    ConvHelper(T data, std::string format, bool ok_bigEn);

    void setStrFormat(const std::string& format);
    std::string getStrFormat() const{return m_format;}
    void setBigEndian(bool ok) {is_bigEndian = ok;}
    bool getIsBigEndian() const {return is_bigEndian;}
    std::string result() const ;

private:
    T m_data;
    std::string m_format;
    bool is_bigEndian;
};


#endif //CUSTOMTOOLS_CONVHELPER_H
