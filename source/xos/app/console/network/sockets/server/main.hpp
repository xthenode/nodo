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
///   Date: 5/25/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP

#include "xos/app/console/network/sockets/server/main_opt.hpp"

#define XOS_NETWORK_SOCKETS_SERVER_DEFAULT_ACCEPT_RESPONSE "HTTP/1.0 200 OK\r\n\r\nOK\r\n"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace server {

/// class maint
template 
<class TExtends = network::sockets::server::main_optt<>, 
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
    maint(): accept_response_(default_accept_response()) {
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

    /// ...sockets_stream_accept_run
    virtual int sockets_stream_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::socket::sockstring_t& host = this->accept_host();
        const xos::network::socket::sockport_t& port = this->accept_port();
        xos::network::socket::endpoint& ep = this->accept_ep();
        xos::network::socket::transport& tp = this->accept_tp();
        xos::network::socket::interface &ac = this->accept_iface(), 
                                         &cn = this->connect_iface();
        xos::network::socket::sockaddr_t& ad = this->connect_addr();
        xos::network::socket::socklen_t& al = this->connect_addrlen();

        if ((ep.attach(host, port))) {

            if ((ac.open(tp))) {
                
                if ((ac.listen(ep))) {
                    
                    this->set_accept_done(false);
                    do {
                        if ((ac.accept(cn, &ad, al))) {
                            
                            if ((err = all_socket_stream_accept(cn, argc, argv, env))) {
                                this->set_accept_done();
                            }
                            cn.close();
                        }
                    } while (!(this->accept_one() || this->accept_done() 
                               || this->server_restart() || this->server_stop()));
                }
                ac.close();
            }
            ep.detach();
        }
        return err;
    }

    /// ...socket_stream_accept
    virtual int socket_stream_accept(xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_socket_recv_request(cn, argc, argv, env))) {
            if (!(err = this->all_socket_process_request(cn, argc, argv, env))) {
                if (!(err = this->all_socket_send_response(cn, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int before_socket_stream_accept(xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_stream_accept(xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_stream_accept(xos::network::socket::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_stream_accept(cn, argc, argv, env))) {
            int err2 = 0;
            err = socket_stream_accept(cn, argc, argv, env);
            if ((err2 = after_socket_stream_accept(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...socket_recv_request
    virtual int socket_recv_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& accept_request = this->accept_request();
        err = this->all_socket_recv_request(accept_request, cn, argc, argv, env);
        return err;
    }
    /// ...socket_process_request
    virtual int socket_process_request(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& accept_request = this->accept_request();
        err = this->all_socket_process_request(accept_request, cn, argc, argv, env);
        return err;
    }
    /// ...socket_send_response
    virtual int socket_send_response(xos::network::socket::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& accept_response = this->accept_response();
        err = this->all_socket_send_response(cn, accept_response, argc, argv, env);
        return err;
    }

    /// ...socket_dgram_accept
    virtual int socket_dgram_accept
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_socket_recv_request_from(ep, ac, argc, argv, env))) {
            if (!(err = this->all_socket_process_request_from(ep, ac, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int before_socket_dgram_accept
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_socket_dgram_accept
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_socket_dgram_accept
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_socket_dgram_accept(ep, ac, argc, argv, env))) {
            int err2 = 0;
            err = socket_dgram_accept(ep, ac, argc, argv, env);
            if ((err2 = after_socket_dgram_accept(ep, ac, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...sockets_dgram_accept_run
    virtual int sockets_dgram_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::socket::sockstring_t& host = this->accept_host();
        const xos::network::socket::sockport_t& port = this->accept_port();
        xos::network::socket::endpoint& ep = this->accept_ep();
        xos::network::socket::transport& tp = this->accept_tp();
        xos::network::socket::interface &ac = this->accept_iface();

        if ((ep.attach(host, port))) {

            if ((ac.open(tp))) {

                if ((ac.bind(ep))) {
                                       
                    this->set_accept_done(false);
                    do {
                        if ((err = all_socket_dgram_accept(ep, ac, argc, argv, env))) {
                            this->set_accept_done();
                        }
                    } while (!(this->accept_one() || this->accept_done() 
                               || this->server_restart() || this->server_stop()));
                }
                ac.close();
            }
            ep.detach();
        }
        return err;
    }

    /// ...socket_recv_request_from
    virtual int socket_recv_request_from
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t count = 0;
        size_t sizeof_accept_chars = 0;
        char_t& accept_chars = this->accept_chars(sizeof_accept_chars);
        string_t& accept_request = this->accept_request();

        if (0 < (count = ac.recvfrom(&accept_chars, sizeof_accept_chars-1, ep))) {
            (&accept_chars)[count] = 0;
            accept_request.assign(&accept_chars, count);
        }
        return err;
    }
    /// ...socket_process_request_from
    virtual int socket_process_request_from
    (xos::network::socket::endpoint& ep, xos::network::socket::interface& ac, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& accept_request = this->accept_request();
        err = this->all_socket_process_request_from(accept_request, ep, ac, argc, argv, env);
        return err;
    }

    /// accept chars / request / response
    virtual char_t& accept_chars(size_t& size_of) const {
        size_of = sizeof(accept_chars_);
        return (char_t&)accept_chars_[0];
    }
    virtual string_t& accept_request() const {
        return (string_t&)accept_request_;
    }
    virtual string_t& accept_response() const {
        return (string_t&)accept_response_;
    }
    static const string_t& default_accept_response() {
        static const string_t accept_response(XOS_NETWORK_SOCKETS_SERVER_DEFAULT_ACCEPT_RESPONSE); 
        return accept_response;
    }

protected:
    string_t accept_response_, accept_request_;
    char_t accept_chars_[4096];
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP
