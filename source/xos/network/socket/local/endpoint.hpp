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
///   Date: 6/12/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_LOCAL_ENDPOINT_HPP
#define XOS_NETWORK_SOCKET_LOCAL_ENDPOINT_HPP

#include "xos/network/socket/local/address.hpp"
#include "xos/network/socket/endpoint.hpp"

namespace xos {
namespace network {
namespace socket {
namespace local {

/// sockaddr_t
typedef struct sockaddr_un sockaddr_t;

/// class endpointt
template <class TImplements = network::socket::endpoint>
class exported endpointt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef endpointt derives; 
    
    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    enum { unattached = implements::unattached };
    
    typedef typename implements::implements::family_t family_t;
    enum { family_unspec = implements::implements::family_unspec };
    
    typedef typename implements::implements::version_t version_t;
    enum { version_unspec = implements::implements::version_unspec };

    /// constructors / destructor
    virtual ~endpointt() {
    }

    /// family /  version
    virtual family_t family() const {
        return AF_LOCAL;
    }
    virtual version_t version() const {
        return 0;
    }
}; /// class endpointt
typedef endpointt<> endpoint;

namespace extended {
/// class endpointt
template <class TExtends = socket::extended::endpoint, class TImplements = socket::local::endpoint>
class exported endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef endpointt derives;

    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    enum { unattached = implements::unattached };
    
    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructor / destructor
    endpointt(const string& path) {
        if (!(this->attach(path))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const char* path) {
        if (!(this->attach(path))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const endpointt& copy): extends(copy) {
    }
    endpointt() {
    }
    virtual ~endpointt() {
        if ((this->attached_to())) {
            if (!(this->detach())) {
                LOGGER_IS_LOGGED_ERROR("...throw attach_exception(detach_failed)...");
                throw attach_exception(detach_failed);
            }
        }
    }

    /// attach
    using implements::attach;
    virtual attached_t attach(const attached_t saddr, socklen_t saddrlen) {
        if ((saddr) && (saddrlen == (this->socket_address_len()))) {
            if (this->family() == (saddr->sa_family)) {
            } else {
            }
        } else {
        }
        return 0;
    }
    virtual attached_t attach(const string& path) {
        const char* chars = 0;
        if ((chars = path.has_chars())) {
            attached_t attached = attach(chars);
            return attached;
        } else {
        }
        return 0;
    }
    virtual attached_t attach(const char* path) {
        if ((path) && (path[0])) {
            memset(&socket_address_, 0, this->socket_address_len_ = (this->socket_address_len()));
#if defined(BSDSOCK)
            socket_address_.sun_len = this->socket_address_len_;
#endif /// defined(BSDSOCK)
            socket_address_.sun_family = this->family();
            if (0 < (strncpy(socket_address_.sun_path, path, sizeof(socket_address_.sun_path)-1))) {
                return extends::attach((attached_t)(&socket_address_));
            }
        } else {
        }
        return 0;
    }

    /// ...address...
    virtual socklen_t socket_address_len() const {
        return ((socklen_t)sizeof(socket_address_));
    }
    virtual byte_t* address_bytes(size_t& length) const {
        byte_t* bytes = (byte_t*)&socket_address_.sun_path;
        length = address_length(bytes, sizeof(socket_address_.sun_path));
        return bytes;
    }
    virtual byte_t* recv_address_bytes(size_t& length) const {
        byte_t* bytes = (byte_t*)&recv_socket_address_.sun_path;
        length = address_length(bytes, sizeof(recv_socket_address_.sun_path));
        return bytes;
    }
    
protected:
    virtual socklen_t address_length(const byte_t* bytes, size_t size) const {
        const char* chars = 0;
        if ((chars = ((const char*)bytes)) && (chars[0])) {
            return strnlen(chars, size);
        }
        return 0;
    }

protected:
    sockaddr_t socket_address_, recv_socket_address_;
}; /// class endpointt
typedef endpointt<> endpoint;
} /// namespace extended

} /// namespace local
} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_LOCAL_ENDPOINT_HPP
