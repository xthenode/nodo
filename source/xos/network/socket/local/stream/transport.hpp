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
///   File: transport.hpp
///
/// Author: $author$
///   Date: 6/11/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_LOCAL_STREAM_TRANSPORT_HPP
#define XOS_NETWORK_SOCKET_LOCAL_STREAM_TRANSPORT_HPP

#include "xos/network/socket/local/transport.hpp"

namespace xos {
namespace network {
namespace socket {
namespace local {
namespace stream {

/// class transportt
template <class TImplements = local::transport>
class exported transportt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef transportt derives; 
    
    typedef typename implements::domain_t domain_t;
    enum { domain_unspec = implements::domain_unspec };
    
    typedef typename implements::type_t type_t;
    enum { type_unspec = implements::type_unspec };
    
    typedef typename implements::protocol_t protocol_t;
    enum { protocol_unspec = implements::protocol_unspec };

    /// constructors / destructor
    virtual ~transportt() {
    }

    /// type
    virtual type_t type() const {
        return SOCK_STREAM;
    }
}; /// class transportt
typedef transportt<> transport;

} /// namespace stream
} /// namespace local
} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_LOCAL_STREAM_TRANSPORT_HPP
