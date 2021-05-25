///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP

#include "xos/app/console/network/base/main_opt.hpp"
#include "xos/network/interface.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace base {

/// class maint
template 
<class TExtends = network::base::main_optt<>, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// send_cr...
    /// ...<cr>
    virtual int send_cr(xos::network::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int send_crlf(xos::network::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        cr_s.appendlf();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }

    /// send_lf...
    /// ...<lf>
    virtual int send_lf(xos::network::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t lf_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        lf_s.appendlf();
        if ((chars = lf_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }

    /// recv_lf...
    /// ...<lf>
    virtual int recv_lf(string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\n':
                return err = 0;
            }
        }
        return err;
    }

    /// recv_cr...
    /// ...<cr>
    virtual int recv_cr(string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                return err = 0;
            }
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int recv_crlf(string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case cr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int recv_crlf2(string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                case lf:
                    s = lfcr;
                    break;
                case lfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                case lf:
                    s = ch;
                    break;
                case cr:
                    s = lf;
                    break;
                case lfcr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// <d>[1..n]...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sizeof_sized_crlf2(size_t size_of, string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;

        for (size_t remain = size_of; remain; --remain) {
            if  (1 > (amount = cn.recv(&c, 1))) {
                return err;
            }
            r.append(&c, 1);
            size = (size << 8) | ((uint8_t)c);
        }
        err = recv_sized_crlf2(size, r, c, cn, argc, argv, env);
        return err;
    }
    /// ...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sized_crlf2(size_t size, string_t& r, char_t& c, xos::network::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;
        for (; size; --size) {
            if (1 > (amount = cn.recv(&c, 1))) {
                break;
            } else {
                r.append(&c, 1);
                switch (c) {
                case '\r':
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        break;
                    case lf:
                        s = lfcr;
                        break;
                    case lfcr:
                        s = cr;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                case '\n':
                    switch (s) {
                    case ch:
                        s = ch;
                        break;
                    case cr:
                        s = lf;
                        break;
                    case lf:
                        s = ch;
                        break;
                    case lfcr:
                        return err = 0;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    s = ch;
                    break;
                }
            }
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP
