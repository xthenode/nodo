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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 5/24/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/base/main.hpp"

#include "xos/network/socket/os/interface.hpp"

#include "xos/network/socket/ip/v4/endpoint.hpp"
#include "xos/network/socket/ip/v4/tcp/transport.hpp"
#include "xos/network/socket/ip/v4/udp/transport.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd }]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE "Host name or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class main_optt
template 
<class TExtends = network::base::maint<>, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0), sockets_run_(0), 
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...sockets_run
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((sockets_run_)) {
            err = (this->*sockets_run_)(argc, argv, env);
        } else {
            err = all_sockets_base_run(argc, argv, env);
        }
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_run;
        return err;
    }
    virtual int before_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_run(argc, argv, env);
            if ((err2 = after_set_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...sockets_base_run
    virtual int sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_base_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_base_run(argc, argv, env);
            if ((err2 = after_sockets_base_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_sockets_base_run;
        }
        return err;
    }
    virtual int before_set_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_base_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_base_run(argc, argv, env);
            if ((err2 = after_set_sockets_base_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...sockets_client_run
    virtual int sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_client_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_client_run(argc, argv, env);
            if ((err2 = after_sockets_client_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_sockets_client_run;
        }
        return err;
    }
    virtual int before_set_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_client_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_client_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_client_run(argc, argv, env);
            if ((err2 = after_set_sockets_client_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...sockets_server_run
    virtual int sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_server_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_server_run(argc, argv, env);
            if ((err2 = after_sockets_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_set_sockets_run(argc, argv, env))) {
            sockets_run_ = &derives::all_sockets_server_run;
        }
        return err;
    }
    virtual int before_set_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_server_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_server_run(argc, argv, env);
            if ((err2 = after_set_sockets_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...host_run
    virtual int host_run(int argc, char_t** argv, char_t** env) {
        const string_t& host = this->host();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_host_run(argc, argv, env))) {
            int err2 = 0;
            err = host_run(argc, argv, env);
            if ((err2 = after_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_host_run;
        return err;
    }
    virtual int before_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_host_run(argc, argv, env))) {
            int err2 = 0;
            err = set_host_run(argc, argv, env);
            if ((err2 = after_set_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...port_run
    virtual int port_run(int argc, char_t** argv, char_t** env) {
        const short& port = this->get_port();
        int err = 0;
        if (0 < (port)) {
            this->outln(unsigned_to_string(port).chars());
        }
        return err;
    }
    virtual int before_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_port_run(argc, argv, env))) {
            int err2 = 0;
            err = port_run(argc, argv, env);
            if ((err2 = after_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_port_run;
        return err;
    }
    virtual int before_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_port_run(argc, argv, env))) {
            int err2 = 0;
            err = set_port_run(argc, argv, env);
            if ((err2 = after_set_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...host / ...port
    virtual string_t& set_host(const char_t* chars) {
        const string_t to(chars);
        return set_host(to);
    }
    virtual string_t& set_host(const string_t& to) {
        string_t& host = this->host();
        const char_t* chars = to.has_chars();
        if ((chars)) host.assign(to);
        else host.clear();
        return host;
    }
    virtual string_t& host() const {
        string_t& host = this->connect_host();
        return host;
    }
    virtual short& set_port(const char_t* chars) {
        const string_t to(chars);
        return set_port(to.to_unsigned());
    }
    virtual short& set_port(short to) {
        short& port = this->port();
        port = to;
        return port;
    }
    virtual const short& get_port() const {
        const short& port = this->port();
        return port;
    }
    virtual short& port() const {
        short& port = this->connect_port();
        return port;
    }

    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        string_t& accept_host = this->accept_host();
        const char_t* chars = to.has_chars();
        if ((chars)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(short to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual const short& get_accept_port() const {
        const short& accept_port = this->accept_port();
        return accept_port;
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }

    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        string_t& connect_host = this->connect_host();
        const char_t* chars = to.has_chars();
        if ((chars)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(short to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual const short& get_connect_port() const {
        const short& connect_port = this->connect_port();
        return connect_port;
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }

    /// ...addr /  ...addrlen
    virtual xos::network::socket::sockaddr_t& accept_addr() const {
        return (xos::network::socket::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::socket::socklen_t& accept_addrlen() const {
        return (xos::network::socket::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::socket::sockaddr_t& connect_addr() const {
        return (xos::network::socket::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::socket::socklen_t& connect_addrlen() const {
        return (xos::network::socket::socklen_t&)connect_addrlen_;
    }

    /// ...iface
    virtual xos::network::socket::interface& accept_iface() const {
        return (xos::network::socket::interface&)accept_iface_;
    }
    virtual xos::network::socket::interface& connect_iface() const {
        return (xos::network::socket::interface&)connect_iface_;
    }

    /// ...ep
    xos::network::socket::endpoint& (derives::*ep_)() const;
    virtual xos::network::socket::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::socket::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::socket::endpoint& ip_v4_ep() const {
        return (xos::network::socket::endpoint&)ip_v4_ep_;
    }

    /// ...tp
    xos::network::socket::transport& (derives::*tp_)() const;
    virtual xos::network::socket::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::socket::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::socket::transport& ip_v4_tcp_tp() const {
        return (xos::network::socket::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::socket::transport& ip_v4_udp_tp() const {
        return (xos::network::socket::transport&)ip_v4_udp_tp_;
    }

    /// ...option...
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_host(optarg);
        } else {
            err = all_set_host_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG;
        return chars;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_port(optarg);
        } else {
            err = all_set_port_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = port_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
    string_t accept_host_, connect_host_;
    short accept_port_, connect_port_;
    
    xos::network::socket::sockaddr_t accept_addr_, connect_addr_;
    xos::network::socket::socklen_t accept_addrlen_, connect_addrlen_;
    
    xos::network::socket::os::interface accept_iface_, connect_iface_;

    xos::network::socket::ip::v4::endpoint ip_v4_ep_;
    xos::network::socket::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::socket::ip::v4::udp::transport ip_v4_udp_tp_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
