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
///   Date: 5/22/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_ENDPOINT_HPP
#define XOS_NETWORK_SOCKET_ENDPOINT_HPP

#include "xos/network/socket/address.hpp"
#include "xos/network/endpoint.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/logger.hpp"
#include <netdb.h>

namespace xos {
namespace network {
namespace socket {

typedef sockaddr_t* sockaddr_attached_t;
typedef int sockaddr_unattached_t;
enum { sockaddr_unattached = 0 };

/// class endpointt
template <class TImplements = attachert
 <sockaddr_attached_t, sockaddr_unattached_t, sockaddr_unattached, network::endpoint> >
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

    /// ...attach...
    using implements::attach;
    virtual attached_t attach_first(const string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach_first(chars, port); }
        return this->attach(port);
    }
    virtual attached_t attach_last(const string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach_last(chars, port); }
        return this->attach(port);
    }
    virtual attached_t attach(const string& host, sockport_t port) {
        const char* chars = host.has_chars();
        if ((chars)) { return this->attach(chars, port); }
        return this->attach(port);
    }
    virtual attached_t attach_first(const char* host, sockport_t port) {
        if ((host) && (host[0]) && (('*' != host[0]) || (0 != host[1]))) {
            return this->attach(host, first_addrindex, port); }
        return this->attach(port);
    }
    virtual attached_t attach_last(const char* host, sockport_t port) {
        if ((host) && (host[0]) && (('*' != host[0]) || (0 != host[1]))) {
            return this->attach(host, last_addrindex, port); }
        return this->attach(port);
    }
    virtual attached_t attach(const char* host, sockport_t port) {
        if ((host) && (host[0]) && (('*' != host[0]) || (0 != host[1]))) {
            return this->attach(host, first_addrindex, port); }
        return this->attach(port);
    }

    /// ...attach...
    virtual attached_t attach(const char* host, addrindex_t index, sockport_t port) {
        attached_t saddr = 0;
        struct addrinfo* addrs = 0;
        int err = 0;

        LOGGER_IS_LOGGED_DEBUG("getaddrinfo(\"" << host << "\",...)...");
        if (!(err = getaddrinfo(host, 0, 0, &addrs))) {
            const address_family_t family = this->family();
            struct addrinfo* addr = 0;
            addrindex_t addr_i = 0;

            LOGGER_IS_LOGGED_DEBUG("...getaddrinfo(\"" << host << "\",...) family = " << family);
            for (addr_i = 0, addr = addrs; addr; addr = addr->ai_next) {
                const address_family_t addrfamily = addr->ai_family;

                if (family == (addrfamily)) {
                    if ((addr_i == index) || ((last_addrindex == index) && !(addr->ai_next))) {
                        LOGGER_IS_LOGGED_DEBUG("...found family " << family << " address[" << addr_i << "]");
                        saddr = this->attach(addr->ai_addr, addr->ai_addrlen, port);
                        break;
                    } else {
                        ++addr_i;
                    }
                }
            }
            freeaddrinfo(addrs);
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed " << this->last_error() << " on getaddrinfo(\"" << host << "\",...)");
        }
        return saddr;
    }
    virtual attached_t attach(const attached_t saddr, socklen_t saddrlen, sockport_t port) {
        return 0;
    }
    virtual attached_t attach(sockport_t port) {
        return 0;
    }
    virtual sockaddr_attached_t attach(const char* path) {
        return 0;
    }

    /// host_name...
    virtual const char* host_name(char* host, socklen_t hostlen) const {
        if ((host) && (1 < hostlen)) {
            attached_t saddr = 0; socklen_t saddrlen = 0;

            if ((saddr = socket_address(saddrlen)) && (0 < saddrlen)) {
                int err = 0;
                
                LOGGER_IS_LOGGED_DEBUG("getnameinfo(...)...");
                if (!(err = getnameinfo(saddr, saddrlen, host, hostlen-1, 0, 0, 0))) {
                    host[hostlen - 1] = 0;
                    LOGGER_IS_LOGGED_DEBUG("...getnameinfo(..., host = \"" << host << "\",...)");
                    return host;
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed " << this->last_error() << " on getnameinfo(...)");
                }
            }
        }
        return 0;
    }

    /// ...address_bytes...
    virtual byte_t* recv_address_bytes(size_t& length) const {
        length = 0;
        return 0;
    }
    virtual byte_t* address_bytes(size_t& length) const {
        length = 0;
        return 0;
    }

    /// ...socket_address...
    virtual attached_t recv_socket_address(socklen_t& len) const {
        len = this->socket_address_len();
        return 0;
    }
    virtual attached_t socket_address(socklen_t& len) const {
        len = this->socket_address_len();
        return this->attached_to();
    }
    virtual attached_t socket_address() const {
        return this->attached_to();
    }
    virtual socklen_t socket_address_len() const {
        return 0;
    }
    virtual operator attached_t () const {
        return this->socket_address();
    }
    virtual int last_error() const {
        return errno;
    }

    /// ...addrinfo / ...nameinfo
    virtual int getaddrinfo
    (const char *hostname, const char *servname, 
     const struct addrinfo *hints, struct addrinfo **res) const {
        int err = EINVAL;

        if ((hostname) && (hostname[0]) && (res)) {
#if !defined(WINSOCK_1)
            err = ::getaddrinfo(hostname, servname, hints, res);
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
        } else {
        }
        return err;
    }
    virtual void freeaddrinfo(struct addrinfo *ai) const {
        if ((ai)) {
#if !defined(WINSOCK_1)
            ::freeaddrinfo(ai);
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
        }
    }
    virtual int getnameinfo
    (const struct sockaddr *sa, socklen_t salen, char *host,
     socklen_t hostlen, char *serv, socklen_t servlen, int flags) const {
        int err = EINVAL;

        if ((sa) && (sizeof(struct sockaddr) <= salen) && (host) && (1 <= hostlen)) {
        } else {
        }
        return err;
    }

    /// ...hostbyname / ...hostbyaddr
    virtual struct hostent *gethostbyname(const char *hostname) const {
        struct hostent *hostent = 0;

        if ((hostname) && (hostname[0])) {
        } else {
        }
        return hostent;
    }
    virtual struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type) const {
        struct hostent *hostent = 0;
        const char *caddr = 0;
        
        if ((caddr = ((const char *)addr)) && (0 < len)) {
        } else {
        } 
        return hostent;
    }
}; /// class endpointt
typedef endpointt<> endpoint;

namespace extended {
/// class endpointt
template 
<class TEndpoint = network::extended::endpoint, class TImplements = socket::endpoint,
 class TExtends = attachedt
 <sockaddr_attached_t, sockaddr_unattached_t, sockaddr_unattached, network::endpoint, TEndpoint, TImplements> >

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
    endpointt(const string& host, sockport_t port): socket_address_port_(0), socket_address_len_(0) {
        if (!(this->attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const char* host, sockport_t port): socket_address_port_(0), socket_address_len_(0) {
        if (!(this->attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(sockport_t port): socket_address_port_(0), socket_address_len_(0) {
        if (!(this->attach(port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const endpointt& copy): extends(copy), socket_address_port_(0), socket_address_len_(0) {
    }
    endpointt(): socket_address_port_(0), socket_address_len_(0) {
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
    virtual attached_t attach(attached_t detached) {
        return extends::attach(detached);
    }

protected:
    sockport_t socket_address_port_;
    socklen_t socket_address_len_;
}; /// class endpointt
typedef endpointt<> endpoint;
} /// namespace extended

} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_ENDPOINT_HPP
