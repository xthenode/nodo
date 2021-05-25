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
///   Date: 5/24/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/base/main_opt.hpp"
#include "xos/network/os/sockets.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class maint
template 
<class TExtends = network::sockets::base::main_optt<>, 
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

    /// ...sockets_run
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::os::sockets& sockets = this->sockets();

        LOGGER_IS_LOGGED_DEBUG("sockets.initialize()...");
        if ((sockets.initialize())) {
            LOGGER_IS_LOGGED_DEBUG("...sockets.initialize()");
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.initialize()");
            err = 1;
        }
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::os::sockets& sockets = this->sockets();

        LOGGER_IS_LOGGED_DEBUG("sockets.finalize()...");
        if ((sockets.finalize())) {
            LOGGER_IS_LOGGED_DEBUG("...sockets.finalize()");
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.finalize()");
            err = 1;
        }
        return err;
    }

    /// ...socket_send_request
    virtual int socket_send_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_send_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_send_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_send_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_send_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_send_request(cn, argc, argv, env);
            if ((err2 = after_socket_send_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_recv_response
    virtual int socket_recv_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_recv_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_recv_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_recv_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_recv_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_recv_response(cn, argc, argv, env);
            if ((err2 = after_socket_recv_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_process_response
    virtual int socket_process_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_process_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_process_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_process_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_process_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_process_response(cn, argc, argv, env);
            if ((err2 = after_socket_process_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...socket_recv_request
    virtual int socket_recv_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_recv_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_recv_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_recv_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_recv_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_recv_request(cn, argc, argv, env);
            if ((err2 = after_socket_recv_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_process_request
    virtual int socket_process_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_process_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_process_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_process_request(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_process_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_process_request(cn, argc, argv, env);
            if ((err2 = after_socket_process_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_send_response
    virtual int socket_send_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_socket_send_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_send_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_send_response(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_send_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_send_response(cn, argc, argv, env);
            if ((err2 = after_socket_send_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...socket_send_request
    virtual int socket_send_request(xos::network::socket::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    virtual int before_socket_send_request(xos::network::socket::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_send_request(xos::network::socket::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_send_request(xos::network::socket::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_send_request(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = socket_send_request(cn, request, argc, argv, env);
            if ((err2 = after_socket_send_request(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_recv_response
    virtual int socket_recv_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        if (!(err = this->recv_crlf2(response, c, cn, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_socket_recv_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_recv_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_recv_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_recv_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_recv_response(response, cn, argc, argv, env);
            if ((err2 = after_socket_recv_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_process_response
    virtual int socket_process_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_socket_process_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_process_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_process_response(string_t& response, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_process_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_process_response(response, cn, argc, argv, env);
            if ((err2 = after_socket_process_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...socket_recv_request
    virtual int socket_recv_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        if (!(err = this->recv_crlf2(request, c, cn, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_socket_recv_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_recv_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_recv_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_recv_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_recv_request(request, cn, argc, argv, env);
            if ((err2 = after_socket_recv_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_process_request
    virtual int socket_process_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_socket_process_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_process_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_process_request(string_t& request, xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_process_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_process_request(request, cn, argc, argv, env);
            if ((err2 = after_socket_process_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...socket_send_response
    virtual int socket_send_response(xos::network::socket::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    virtual int before_socket_send_response(xos::network::socket::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_send_response(xos::network::socket::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_send_response(xos::network::socket::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_send_response(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = socket_send_response(cn, response, argc, argv, env);
            if ((err2 = after_socket_send_response(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    virtual xos::network::os::sockets& sockets() const {
        return (xos::network::os::sockets&)sockets_;
    }

protected:
    xos::network::os::sockets sockets_; 
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
