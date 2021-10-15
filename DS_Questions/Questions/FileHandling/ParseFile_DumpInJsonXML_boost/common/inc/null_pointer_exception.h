#include "common.h"

class base {
protected:
    char* m_msg = nullptr;
private:
    void copyMsg (const char* c) {
        const char* customMessage = "NULLException";
        if ( c != nullptr ) {
            delete [] m_msg;
            m_msg = nullptr;
        }
        size_t size = strlen (c);
        m_msg = new char [size+6];
        memset (m_msg, '\0', size);

        memcpy (m_msg, customMessage, 5);
        memcpy ((char*)m_msg+5, c, size);
    }

public:
    base (const char* m) : m_msg(nullptr) {
        copyMsg (m);
        std::cout << "Logged message on Log server"
                  << std::endl;
    }
    base (const std::exception& obj) {
        copyMsg (obj.what());
    }
    base& operator = (const base& obj) {
        if (this != &obj)
            copyMsg(obj.what());
    }
    virtual ~base() {
        if ( nullptr != m_msg) {
            delete [] m_msg;
            m_msg = nullptr;
        }
    }
    virtual const char* what() const {
        return m_msg;
    }
};

class NULLException : public base {
public:
    explicit NULLException (const char *msg) : base (msg) {}
};
