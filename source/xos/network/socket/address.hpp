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
///   File: address.hpp
///
/// Author: $author$
///   Date: 5/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_ADDRESS_HPP
#define XOS_NETWORK_SOCKET_ADDRESS_HPP

#include "xos/network/address.hpp"
#include <sys/socket.h>

#if !defined(BSDSOCK)
#if defined(BSD) || defined(WINSOCK_2)
#define BSDSOCK
#endif /// !defined(BSD) || defined(WINSOCK_2)
#endif /// !defined(BSDSOCK)

#if !defined(NO_IP6_SOCK)
#if defined(WINSOCK_1)
#define NO_IP6_SOCK
#endif /// defined(WINSOCK_1)
#endif /// !defined(NO_IP6_SOCK)

namespace xos {
namespace network {
namespace socket {

/// enum addrindex_t
typedef int addrindex_t;
enum {
    first_addrindex = 0,
    last_addrindex = -1
}; /// enum addrindex_t

/// struct sockaddr
typedef struct sockaddr sockaddr_t;

/// socklen_t
typedef ::socklen_t socklen_t;

/// sockport_t
typedef unsigned short sockport_t;

/// sockstring_t
typedef string sockstring_t;

/// sockchar_t
typedef sockstring_t::char_t sockchar_t;

/// class addresst
template <class TImplements = network::address>
class exported addresst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef addresst derives; 
    
    typedef typename implements::family_t family_t;
    enum { family_unspec = AF_UNSPEC };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = 0 };

    /// constructors / destructor
    virtual ~addresst() {
    }

    /// family /  version
    virtual family_t family() const {
        return family_unspec;
    }
    virtual version_t version() const {
        return version_unspec;
    }
}; /// class addresst
typedef addresst<> address;

namespace extended {
/// class addresst
template 
<class TExtends = network::extended::address, class TImplements = socket::address>

class exported addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef addresst derives;

    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructor / destructor
    addresst(const addresst& copy): extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }
}; /// class addresst
typedef addresst<> address;
} /// namespace extended

} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_ADDRESS_HPP
