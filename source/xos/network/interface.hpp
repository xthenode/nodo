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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 5/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_INTERFACE_HPP
#define XOS_NETWORK_INTERFACE_HPP

#include "xos/base/logged.hpp"
#include "xos/base/opened.hpp"
#include "xos/network/transport.hpp"

namespace xos {
namespace network {

namespace socket {
class exported interface;
} /// namespace socket

/// class interfacet
template <class TImplements = loggedt<opener> >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives; 
    
    /// constructors / destructor
    virtual ~interfacet() {
    }

    /// open / close
    virtual bool open(const transport& tp) {
        return false;
    }
    virtual bool close() {
        return false;
    }
    
    /// send... / recv...
    virtual ssize_t send(const void* buf, size_t len) {
        return 0;
    }
    virtual ssize_t recv(void* buf, size_t len) {
        return 0;
    }

    /// ...socket_interface
    virtual const socket::interface* const_socket_interface() const {
        return this->socket_interface();
    }
    virtual socket::interface* socket_interface() const {
        return 0;
    }
}; /// class interfacet
typedef interfacet<> interface;

namespace extended {
/// class interfacet
template 
<typename TAttached = pointer_t, typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = network::interface, class TExtends = openedt
 <TAttached, TUnattached, VUnattached, TImplements> >

class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    /// constructor / destructor
    interfacet(attached_t detached, bool is_open): extends(detached, is_open) {
    }
    interfacet(attached_t detached): extends(detached) {
    }
    interfacet(const interfacet& copy): extends(copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended

} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_INTERFACE_HPP
