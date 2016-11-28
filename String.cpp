#include <iostream>
#include <cstring>
#include <stdexcept>

#include "String.hh"

String::Iterator::Iterator() : _s(nullptr) { }
String::Iterator::Iterator(const Iterator& other) : _s(other._s) { }
String::Iterator::Iterator(char *s) : _s(s) { }
String::Iterator::~Iterator() { }

String::Iterator& String::Iterator::operator=(const Iterator& other)
{
  if (this != &other)
    _s = other._s;
  return *this;
}

String::Iterator String::Iterator::operator++(int) { return Iterator(++_s); }
String::Iterator& String::Iterator::operator++() { ++_s; return *this; }
char& String::Iterator::operator*() { return *_s; }

bool String::Iterator::operator!=(const Iterator& other)
{
  return _s != other._s;
}

String::String() : _s(nullptr), _size(0) { }

String::String(const char *s)
{
  _size = std::strlen(s);
  _s = new char[_size + 1];
  std::memset(_s, 0, _size + 1);
  std::memcpy(_s, s, _size);
}

String::String(const String& other)
{
  _size = other._size;
  _s = new char[_size + 1];
  std::memset(_s, 0, _size + 1);
  std::memcpy(_s, other._s, _size);
}

String::~String() { delete[] _s; }

String&	String::operator=(const String& other)
{
  if (this != &other)
    {
      if (_s)
	delete[] _s;
      _size = other._size;
      _s = new char[_size + 1];
      std::memset(_s, 0, _size + 1);
      std::memcpy(_s, other._s, _size);
    }
  return *this;
}

String&	String::operator=(const char *s)
{
  if (_s)
    delete[] _s;
  _size = std::strlen(s);
  _s = new char[_size + 1];
  std::memset(_s, 0, _size + 1);
  std::memcpy(_s, s, _size);
  return *this;
}

String String::operator+(const String& other)
{
  char *s = new char[_size + other._size + 1];
  
  std::memset(s, 0, _size + other._size + 1);
  std::strcat(s, _s);
  std::strcat(s, other._s);
  
  String string(s);
  
  delete[] s;
  return string;
}

String String::operator+(const char *s)
{
  std::size_t size = std::strlen(s);
  char *s2 = new char[_size + size + 1];
  
  std::memset(s2, 0, _size + size + 1);
  std::strcat(s2, _s);
  std::strcat(s2, s);
  
  String string(s2);

  delete[] s2;
  return string;
}

String&	String::operator+=(const String& other)
{
  char *tmp = nullptr;
  
  if (_s)
    {
      tmp = new char[_size + 1];
      std::memset(tmp, 0, _size + 1);
      std::memcpy(tmp, _s, _size);
      delete[] _s;
    }
  _size = (tmp) ? std::strlen(tmp) + other._size : other._size;
  _s = new char[_size + 1];
  std::memset(_s, 0, _size + 1);
  std::strcat(_s, tmp);
  std::strcat(_s, other._s);
  if (tmp)
    delete[] tmp;
  return *this;
}

String&	String::operator+=(const char *s)
{
  char *tmp = nullptr;
  
  if (_s)
    {
      tmp = new char[_size + 1];
      std::memset(tmp, 0, _size + 1);
      std::memcpy(tmp, _s, _size);
      delete[] _s;
    }
  _size = (tmp) ? std::strlen(tmp) + std::strlen(s) : std::strlen(s);
  _s = new char[_size + 1];
  std::memset(_s, 0, _size + 1);
  std::strcat(_s, tmp);
  std::strcat(_s, s);
  if (tmp)
    delete[] tmp;
  return *this;
}

const char& String::operator[](int pos) const
{
  if (pos < 0 || pos > _size)
    throw std::out_of_range("<String's module> \"operator[]\"");
  return _s[pos];
}

char& String::operator[](int pos)
{
  if (pos < 0 || pos > _size)
    throw std::out_of_range("<String's module> \"operator[]\"");
  return _s[pos];
}

const char& String::at(int pos) const
{
  if (pos < 0 || pos > _size)
    throw std::out_of_range("<String's module> \"at\"");
  return _s[pos];
}

char& String::at(int pos)
{
  if (pos < 0 || pos > _size)
    throw std::out_of_range("<String's module> \"at\"");
  return _s[pos];
}

size_t String::size() const { return _size; }
const char *String::c_str() const { return _s; }
String::operator char() const { return _s ? *_s : 0; }
String::Iterator String::begin() { return Iterator(_s); }
String::Iterator String::end() { return Iterator(&_s[_size]); }

std::ostream&	operator<<(std::ostream& os, const String& string)
{
  return os << string.c_str();
}
