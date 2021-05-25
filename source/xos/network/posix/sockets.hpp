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
///   File: sockets.hpp
///
/// Author: $author$
///   Date: 5/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_POSIX_SOCKETS_HPP
#define XOS_NETWORK_POSIX_SOCKETS_HPP

#include "xos/network/sockets.hpp"

namespace xos {
namespace network {
namespace posix {

/// class socketst
template <class TImplements = network::sockets, class TExtends = xos::extend>
class exported socketst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef socketst derives; 
    
    /// constructors / destructor
    virtual ~socketst() {
    }

    /// initialize / finalize
    virtual bool initialize() {
        return true;
    }
    virtual bool finalize() {
        return true;
    }
}; /// class socketst
typedef socketst<> sockets;

} /// namespace posix
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_POSIX_SOCKETS_HPP
