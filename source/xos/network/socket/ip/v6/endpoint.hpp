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
///   File: endpoint.hpp
///
/// Author: $author$
///   Date: 5/23/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_IP_V6_ENDPOINT_HPP
#define XOS_NETWORK_SOCKET_IP_V6_ENDPOINT_HPP

#include "xos/network/socket/ip/endpoint.hpp"

namespace xos {
namespace network {
namespace socket {
namespace ip {
namespace v6 {

/// class endpointt
template <class TImplements = socket::ip::endpoint>
class exported endpointt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef endpointt derives; 
    
    /// constructors / destructor
    virtual ~endpointt() {
    }
}; /// class endpointt
typedef endpointt<> endpoint;

} /// namespace v6
} /// namespace ip
} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_IP_V6_ENDPOINT_HPP
