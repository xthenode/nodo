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
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP

#include "xos/app/console/network/sockets/client/main_opt.hpp"

#define XOS_NETWORK_SOCKETS_CLIENT_DEFAULT_CONNECT_REQUEST "GET / HTTP/1.0\r\n\r\n"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace client {

/// class maint
template 
<class TExtends = network::sockets::client::main_optt<>, 
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
    maint(): connect_request_(default_connect_request()) {
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

    /// ...sockets_...client_run
    virtual int sockets_stream_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::socket::sockstring_t& host = this->connect_host();
        const xos::network::socket::sockport_t& port = this->connect_port();
        xos::network::socket::endpoint& ep = this->connect_ep();
        xos::network::socket::transport& tp = this->connect_tp();
        xos::network::socket::interface &cn = this->connect_iface();

        if ((ep.attach(host, port))) {

            if ((cn.open(tp))) {
                
                if ((cn.connect(ep))) {
                    
                    err = all_socket_connect(cn, argc, argv, env);
                }
                cn.close();
            }
            ep.detach();
        }
        return err;
    }
    virtual int sockets_dgram_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::socket::sockstring_t& host = this->connect_host();
        const xos::network::socket::sockport_t& port = this->connect_port();
        xos::network::socket::endpoint& ep = this->connect_ep();
        xos::network::socket::transport& tp = this->connect_tp();
        xos::network::socket::interface &cn = this->connect_iface();

        if ((ep.attach(host, port))) {

            if ((cn.open(tp))) {
                
                err = this->all_socket_send_request_to(ep, cn, argc, argv, env);
                cn.close();
            }
            ep.detach();
        }
        return err;
    }

    /// ...socket_connect
    virtual int socket_connect(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_socket_send_request(cn, argc, argv, env))) {
            if (!(err = this->all_socket_recv_response(cn, argc, argv, env))) {
                if (!(err = this->all_socket_process_response(cn, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int before_socket_connect(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_connect(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_connect(xos::network::socket::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_socket_connect(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_connect(cn, argc, argv, env);
            if ((err2 = after_socket_connect(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...socket_send_request_to
    virtual int socket_send_request_to
    (xos::network::socket::endpoint& ep, 
     xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& connect_request = this->connect_request();
        err = this->all_socket_send_request_to(ep, cn, connect_request, argc, argv, env);
        return err;
    }
    /// ...socket_send_request
    virtual int socket_send_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& connect_request = this->connect_request();
        err = this->all_socket_send_request(cn, connect_request, argc, argv, env);
        return err;
    }
    /// ...socket_recv_response
    virtual int socket_recv_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& connect_response = this->connect_response();
        err = this->all_socket_recv_response(connect_response, cn, argc, argv, env);
        return err;
    }
    /// ...socket_process_response
    virtual int socket_process_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& connect_response = this->connect_response();
        err = this->all_socket_process_response(connect_response, cn, argc, argv, env);
        return err;
    }

    /// connect request / response
    virtual string_t& connect_request() const {
        return (string_t&)connect_request_;
    }
    virtual string_t& connect_response() const {
        return (string_t&)connect_response_;
    }
    static const string_t& default_connect_request() {
        static const string_t connect_request(XOS_NETWORK_SOCKETS_CLIENT_DEFAULT_CONNECT_REQUEST);
        return connect_request;
    }

protected:
    string_t connect_request_, connect_response_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP
