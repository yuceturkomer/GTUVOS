#ifndef GTUEXCEPTIONS_H
#define GTUEXCEPTIONS_H

#include <exception>
#include <iostream>

using namespace std;

class INSUFFICIENT_PARAMS_EXCEPTION : public exception{
public:
    virtual const char* what() const throw()
      {
        return "EXCEPTION -> INSUFFICIENT PARAMETER\n";
      }
};

class FILE_PATH_EXCEPTION : public exception{
public:
    virtual const char* what() const throw()
      {
        return "EXCEPTION -> FILE_PATH_EXCEPTION\n";
      }
};

class INVALID_COMMAND_EXCEPTION : public exception{
public:
    virtual const char* what() const throw()
      {
        return "Invalid Command. Please look help manual. -> help\n";
      }
};

class DIR_EXIST_EXCEPTION : public exception{
public:
    virtual const char* what() const throw()
      {
        return "Directory already exist!";
      }
};




#endif // GTUEXCEPTIONS_H
