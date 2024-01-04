#ifndef ANY_EXCEPTION_H_INCLUDED
#define ANY_EXCEPTION_H_INCLUDED

#include <string>
#include <exception>

class AnyException : public std::exception {
    private:
        std::string msg;
    public:
        explicit AnyException(const char* message): msg(message) {}
        explicit AnyException(const std::string& message): msg(message) {}
        virtual ~AnyException() throw() {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };


#endif // ANY_EXCEPTION_H_INCLUDED
