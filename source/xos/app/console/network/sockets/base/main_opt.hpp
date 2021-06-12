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
#include "xos/network/socket/ip/v4/raw/transport.hpp"
#include "xos/network/socket/ip/v4/tcp/transport.hpp"
#include "xos/network/socket/ip/v4/udp/transport.hpp"

#if !defined(NO_IP6_SOCK)
#include "xos/network/socket/ip/v6/endpoint.hpp"
#include "xos/network/socket/ip/v6/raw/transport.hpp"
#include "xos/network/socket/ip/v6/tcp/transport.hpp"
#include "xos/network/socket/ip/v6/udp/transport.hpp"
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

#if !defined(NO_IP6_SOCK)
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPT "endpoint"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTUSE "Endpoint"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
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

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPT "from-host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTUSE "From host name or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPT "from-port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTUSE "From port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPT "ip4"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG_RESULT 0
#if !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG "[{ ip(6) | ip(4) | ...}]"
#else /// !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG "[{ ip(4) | ...}]"
#endif /// !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTUSE "Ipv4 Address family"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_S "4::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_C '4'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_C}, \

#if !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPT "ip6"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG "[{ ip(4) | ip(6) | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTUSE "Ipv6 Address family"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_S "6::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_C '6'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_C}, 
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPT "family"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG_RESULT 0
#if !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG "[{ ip(4) | ip(6) | ...}]"
#else /// !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG "[{ ip(4) | ...}]"
#endif /// !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTUSE "Address family"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_S "f::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_C 'f'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPT "raw"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG "[{ stream (tcp) | dgram (udp) | raw | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTUSE "Raw transport"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPT "dgram"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG "[{ raw | stream (tcp) | dgram (udp) | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTUSE "Datagram transport"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPT "stream"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG "[{ raw | dgram (udp) | stream (tcp) | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTUSE "Stream transport"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_C 's'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPT "transport"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG "[{ raw | dgram (udp) | stream (tcp) | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTUSE "Transport"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_C 't'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_C}, \

#if !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_S

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTION 
#else /// !defined(NO_IP6_SOCK)
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_S

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTION 
#endif /// !defined(NO_IP6_SOCK)

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTION \

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
      ep_from_(0), ip_ep_from_(0), ep_(0), ip_ep_(0), 
      tp_(0), ip_tp_(0), ip_raw_tp_(0), ip_tcp_tp_(0), ip_udp_tp_(0),
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      from_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      from_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT) {
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

    /// ...sockets_endpoint_run
    virtual int sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_endpoint_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_endpoint_run(argc, argv, env);
            if ((err2 = after_sockets_endpoint_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_endpoint_run;
        return err;
    }
    virtual int before_set_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_sockets_endpoint_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_sockets_endpoint_run(argc, argv, env))) {
            int err2 = 0;
            err = set_sockets_endpoint_run(argc, argv, env);
            if ((err2 = after_set_sockets_endpoint_run(argc, argv, env))) {
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

    /// ...from_host_run
    virtual int from_host_run(int argc, char_t** argv, char_t** env) {
        const string_t& from_host = this->from_host();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = from_host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_from_host_run(argc, argv, env))) {
            int err2 = 0;
            err = from_host_run(argc, argv, env);
            if ((err2 = after_from_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_from_host_run;
        return err;
    }
    virtual int before_set_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_from_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_from_host_run(argc, argv, env))) {
            int err2 = 0;
            err = set_from_host_run(argc, argv, env);
            if ((err2 = after_set_from_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...from_port_run
    virtual int from_port_run(int argc, char_t** argv, char_t** env) {
        const short& from_port = this->get_from_port();
        int err = 0;
        if (0 < (from_port)) {
            this->outln(unsigned_to_string(from_port).chars());
        }
        return err;
    }
    virtual int before_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_from_port_run(argc, argv, env))) {
            int err2 = 0;
            err = from_port_run(argc, argv, env);
            if ((err2 = after_from_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_from_port_run;
        return err;
    }
    virtual int before_set_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_from_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_from_port_run(argc, argv, env))) {
            int err2 = 0;
            err = set_from_port_run(argc, argv, env);
            if ((err2 = after_set_from_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...family_run
    virtual int family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::socket::endpoint& ep = this->ep();
        
        this->outlln("ep family = ", signed_to_string(ep.family()).chars(), null);
        this->outlln("ep version = ", signed_to_string(ep.version()).chars(), null);
        return err;
    }
    virtual int before_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_family_run(argc, argv, env))) {
            int err2 = 0;
            err = family_run(argc, argv, env);
            if ((err2 = after_family_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_family_run;
        return err;
    }
    virtual int before_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_family_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_family_run(argc, argv, env))) {
            int err2 = 0;
            err = set_family_run(argc, argv, env);
            if ((err2 = after_set_family_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...transport_run
    virtual int transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::socket::transport& tp = this->tp();
        
        this->outlln("tp domain = ", signed_to_string(tp.domain()).chars(), null);
        this->outlln("tp type = ", signed_to_string(tp.type()).chars(), null);
        this->outlln("tp protocol = ", signed_to_string(tp.protocol()).chars(), null);
        return err;
    }
    virtual int before_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_transport_run(argc, argv, env))) {
            int err2 = 0;
            err = transport_run(argc, argv, env);
            if ((err2 = after_transport_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_transport_run;
        return err;
    }
    virtual int before_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_transport_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_transport_run(argc, argv, env))) {
            int err2 = 0;
            err = set_transport_run(argc, argv, env);
            if ((err2 = after_set_transport_run(argc, argv, env))) {
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
    virtual short& set_accept_port(const char_t* chars) {
        const string_t to(chars);
        return set_accept_port(to.to_unsigned());
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
    virtual short& set_connect_port(const char_t* chars) {
        const string_t to(chars);
        return set_connect_port(to.to_unsigned());
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

    /// ...from_host / ...from_port
    virtual string_t& set_from_host(const string_t& to) {
        string_t& from_host = this->from_host();
        const char_t* chars = to.has_chars();
        if ((chars)) from_host.assign(to);
        else from_host.clear();
        return from_host;
    }
    virtual string_t& from_host() const {
        return (string_t&)from_host_;
    }
    virtual short& set_from_port(const char_t* chars) {
        const string_t to(chars);
        return set_from_port(to.to_unsigned());
    }
    virtual short& set_from_port(short to) {
        short& from_port = this->from_port();
        from_port = to;
        return from_port;
    }
    virtual const short& get_from_port() const {
        const short& from_port = this->from_port();
        return from_port;
    }
    virtual short& from_port() const {
        return (short&)from_port_;
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

    /// ...ep_from
    xos::network::socket::endpoint& (derives::*ep_from_)() const;
    virtual xos::network::socket::endpoint& ep_from() const {
        if ((this->ep_from_)) {
            return (this->*ep_from_)();
        }
        return this->default_ep_from();
    }
    virtual xos::network::socket::endpoint& default_ep_from() const {
        return this->ip_ep_from();
    }
    xos::network::socket::endpoint& (derives::*ip_ep_from_)() const;
    virtual xos::network::socket::endpoint& ip_ep_from() const {
        if ((this->ip_ep_from_)) {
            return (this->*ip_ep_from_)();
        }
        return this->default_ip_ep_from();
    }
    virtual xos::network::socket::endpoint& default_ip_ep_from() const {
        return this->ip_v4_ep_from();
    }
    virtual xos::network::socket::endpoint& set_ip_v4_ep_from() {
        ip_ep_from_ = &derives::ip_v4_ep_from;
        return ip_ep_from();
    }
    virtual xos::network::socket::endpoint& ip_v4_ep_from() const {
        return (xos::network::socket::endpoint&)ip_v4_ep_from_;
    }
#if !defined(NO_IP6_SOCK)
    virtual xos::network::socket::endpoint& set_ip_v6_ep_from() {
        ip_ep_from_ = &derives::ip_v6_ep_from;
        return ip_ep_from();
    }
    virtual xos::network::socket::endpoint& ip_v6_ep_from() const {
        return (xos::network::socket::endpoint&)ip_v6_ep_from_;
    }
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

    /// ...ep
    xos::network::socket::endpoint& (derives::*ep_)() const;
    virtual xos::network::socket::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::socket::endpoint& default_ep() const {
        return this->ip_ep();
    }
    xos::network::socket::endpoint& (derives::*ip_ep_)() const;
    virtual xos::network::socket::endpoint& ip_ep() const {
        if ((this->ip_ep_)) {
            return (this->*ip_ep_)();
        }
        return this->default_ip_ep();
    }
    virtual xos::network::socket::endpoint& default_ip_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::socket::endpoint& set_ip_v4_ep() {
        ip_ep_ = &derives::ip_v4_ep;
        return ip_ep();
    }
    virtual xos::network::socket::endpoint& ip_v4_ep() const {
        return (xos::network::socket::endpoint&)ip_v4_ep_;
    }
#if !defined(NO_IP6_SOCK)
    virtual xos::network::socket::endpoint& set_ip_v6_ep() {
        ip_ep_ = &derives::ip_v6_ep;
        return ip_ep();
    }
    virtual xos::network::socket::endpoint& ip_v6_ep() const {
        return (xos::network::socket::endpoint&)ip_v6_ep_;
    }
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

    /// ...tp
    xos::network::socket::transport& (derives::*tp_)() const;
    virtual xos::network::socket::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::socket::transport& default_tp() const {
        return this->ip_tp();
    }
    xos::network::socket::transport& (derives::*ip_tp_)() const;
    virtual xos::network::socket::transport& set_ip_raw_tp() {
        ip_tp_ = &derives::ip_raw_tp;
        return ip_tp();
    }
    virtual xos::network::socket::transport& set_ip_tcp_tp() {
        ip_tp_ = &derives::ip_tcp_tp;
        return ip_tp();
    }
    virtual xos::network::socket::transport& set_ip_udp_tp() {
        ip_tp_ = &derives::ip_udp_tp;
        return ip_tp();
    }
    virtual xos::network::socket::transport& ip_tp() const {
        if ((this->ip_tp_)) {
            return (this->*ip_tp_)();
        }
        return this->default_ip_tp();
    }
    virtual xos::network::socket::transport& default_ip_tp() const {
        return this->ip_tcp_tp();
    }
    xos::network::socket::transport& (derives::*ip_raw_tp_)() const;
    virtual xos::network::socket::transport& ip_raw_tp() const {
        if ((this->ip_raw_tp_)) {
            return (this->*ip_raw_tp_)();
        }
        return this->default_ip_raw_tp();
    }
    virtual xos::network::socket::transport& default_ip_raw_tp() const {
        return this->ip_v4_raw_tp();
    }
    xos::network::socket::transport& (derives::*ip_tcp_tp_)() const;
    virtual xos::network::socket::transport& ip_tcp_tp() const {
        if ((this->ip_tcp_tp_)) {
            return (this->*ip_tcp_tp_)();
        }
        return this->default_ip_tcp_tp();
    }
    virtual xos::network::socket::transport& default_ip_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
    xos::network::socket::transport& (derives::*ip_udp_tp_)() const;
    virtual xos::network::socket::transport& ip_udp_tp() const {
        if ((this->ip_udp_tp_)) {
            return (this->*ip_udp_tp_)();
        }
        return this->default_ip_udp_tp();
    }
    virtual xos::network::socket::transport& default_ip_udp_tp() const {
        return this->ip_v4_udp_tp();
    }
    virtual xos::network::socket::transport& set_ip_v4_raw_tp() {
        ip_raw_tp_ = &derives::ip_v4_raw_tp;
        return ip_raw_tp();
    }
    virtual xos::network::socket::transport& ip_v4_raw_tp() const {
        return (xos::network::socket::transport&)ip_v4_raw_tp_;
    }
    virtual xos::network::socket::transport& set_ip_v4_tcp_tp() {
        ip_tcp_tp_ = &derives::ip_v4_tcp_tp;
        return ip_tcp_tp();
    }
    virtual xos::network::socket::transport& ip_v4_tcp_tp() const {
        return (xos::network::socket::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::socket::transport& set_ip_v4_udp_tp() {
        ip_udp_tp_ = &derives::ip_v4_udp_tp;
        return ip_udp_tp();
    }
    virtual xos::network::socket::transport& ip_v4_udp_tp() const {
        return (xos::network::socket::transport&)ip_v4_udp_tp_;
    }
#if !defined(NO_IP6_SOCK)
    virtual xos::network::socket::transport& set_ip_v6_raw_tp() {
        ip_raw_tp_ = &derives::ip_v6_raw_tp;
        return ip_raw_tp();
    }
    virtual xos::network::socket::transport& ip_v6_raw_tp() const {
        return (xos::network::socket::transport&)ip_v6_raw_tp_;
    }
    virtual xos::network::socket::transport& set_ip_v6_tcp_tp() {
        ip_tcp_tp_ = &derives::ip_v6_tcp_tp;
        return ip_tcp_tp();
    }
    virtual xos::network::socket::transport& ip_v6_tcp_tp() const {
        return (xos::network::socket::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::socket::transport& set_ip_v6_udp_tp() {
        ip_udp_tp_ = &derives::ip_v6_udp_tp;
        return ip_udp_tp();
    }
    virtual xos::network::socket::transport& ip_v6_udp_tp() const {
        return (xos::network::socket::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)

    /// ...option...
    virtual int on_endpoint_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = all_set_sockets_endpoint_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* endpoint_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTARG;
        return chars;
    }
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
    virtual int on_from_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_from_host(optarg);
        } else {
            err = all_set_from_host_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* from_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTARG;
        return chars;
    }
    virtual int on_from_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_from_port(optarg);
        } else {
            err = all_set_from_port_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* from_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTARG;
        return chars;
    }
    virtual int on_ip_v4_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            set_ip_v4_ep();
            set_ip_v4_raw_tp();
            set_ip_v4_tcp_tp();
            set_ip_v4_udp_tp();
        }
        return err;
    }
    virtual const char_t* ip_v4_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTARG;
        return chars;
    }
#if !defined(NO_IP6_SOCK)
    virtual int on_ip_v6_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            set_ip_v6_ep();
            set_ip_v6_raw_tp();
            set_ip_v6_tcp_tp();
            set_ip_v6_udp_tp();
        }
        return err;
    }
    virtual const char_t* ip_v6_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTARG;
        return chars;
    }
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)
    virtual int on_family_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = all_set_family_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* family_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTARG;
        return chars;
    }
    virtual int on_raw_option_set
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_raw_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            set_ip_raw_tp();
            err = on_raw_option_set(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* raw_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTARG;
        return chars;
    }
    virtual int on_dgram_option_set
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_dgram_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            set_ip_udp_tp();
            err = on_dgram_option_set(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* dgram_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTARG;
        return chars;
    }
    virtual int on_stream_option_set
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_stream_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            set_ip_tcp_tp();
            err = on_stream_option_set(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* stream_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTARG;
        return chars;
    }
    virtual int on_transport_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = all_set_transport_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* transport_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_C:
            err = this->on_endpoint_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_C:
            err = this->on_from_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_C:
            err = this->on_from_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_C:
            err = this->on_ip_v4_option(optval, optarg, optname, optind, argc, argv, env);
            break;
#if !defined(NO_IP6_SOCK)
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_C:
            err = this->on_ip_v6_option(optval, optarg, optname, optind, argc, argv, env);
            break;
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_C:
            err = this->on_family_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_C:
            err = this->on_raw_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_C:
            err = this->on_dgram_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_C:
            err = this->on_stream_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_C:
            err = this->on_transport_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ENDPOINT_OPTVAL_C:
            chars = endpoint_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_HOST_OPTVAL_C:
            chars = from_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FROM_PORT_OPTVAL_C:
            chars = from_port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V4_OPTVAL_C:
            chars = ip_v4_option_usage(optarg, longopt);
            break;
#if !defined(NO_IP6_SOCK)
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_IP_V6_OPTVAL_C:
            chars = ip_v6_option_usage(optarg, longopt);
            break;
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_FAMILY_OPTVAL_C:
            chars = family_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RAW_OPTVAL_C:
            chars = raw_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_DGRAM_OPTVAL_C:
            chars = dgram_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_STREAM_OPTVAL_C:
            chars = stream_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_TRANSPORT_OPTVAL_C:
            chars = transport_option_usage(optarg, longopt);
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
    string_t accept_host_, connect_host_, from_host_;
    short accept_port_, connect_port_, from_port_;
    
    xos::network::socket::sockaddr_t accept_addr_, connect_addr_;
    xos::network::socket::socklen_t accept_addrlen_, connect_addrlen_;
    
    xos::network::socket::os::interface accept_iface_, connect_iface_;

    xos::network::socket::ip::v4::endpoint ip_v4_ep_from_, ip_v4_ep_;
    xos::network::socket::ip::v4::raw::transport ip_v4_raw_tp_;
    xos::network::socket::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::socket::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(NO_IP6_SOCK)
    xos::network::socket::ip::v6::endpoint ip_v6_ep_from_, ip_v6_ep_;
    xos::network::socket::ip::v6::raw::transport ip_v6_raw_tp_;
    xos::network::socket::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::socket::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(NO_IP6_SOCK)
#endif /// !defined(NO_IP6_SOCK)
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
