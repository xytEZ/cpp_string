#ifndef STRING_HH_
# define STRING_HH_

class String
{
public :
  class Iterator
  {
  private :
    char *_s;

  public :
    Iterator();
    Iterator(const Iterator&);
    Iterator(char *);
    ~Iterator();
    Iterator& operator=(const Iterator&);
    Iterator operator++(int);
    Iterator& operator++();
    char& operator*();
    bool operator!=(const Iterator&);
  };

private :
  char *_s;
  std::size_t _size;

public :
  String();
  String(const char *);
  String(const String&);
  ~String();
  String& operator=(const String&);
  String& operator=(const char *);
  String operator+(const String&);
  String operator+(const char *);
  String& operator+=(const String&);
  String& operator+=(const char *);
  const char& operator[](int) const;
  char& operator[](int);
  const char& at(int) const;
  char& at(int);
  std::size_t size() const;
  const char *c_str() const;
  operator char() const;
  Iterator begin();
  Iterator end();
};

std::ostream& operator<<(std::ostream&, const String&);

#endif /* !STRING_HH_ */
