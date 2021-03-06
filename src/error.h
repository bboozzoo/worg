#ifndef __ERROR_H__
#define __ERROR_H__
#include <exception>
#include <string>
#include <sstream>
#include <stdint.h>

#define ERR_HERE (err_here(__FILE__, __LINE__))

static inline std::string err_here(const char * file, uint32_t line) 
{
    std::ostringstream os;
    os << file << ":"  << line << " ";
    return os.str();
}

class Error : public std::exception 
{
    public:
        Error(const std::string & arg, const std::string & where) 
        {
            m_what += where;
            m_what += arg;
        }
        ~Error() throw()
        {
        }
        const char * what() const throw ()
        { 
            return m_what.c_str(); 
        }

    private:
        std::string     m_what;
};

#endif /* __ERROR_H__ */
