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
///   File: transport.cpp
///
/// Author: $author$
///   Date: 6/11/2021
///////////////////////////////////////////////////////////////////////
#include "xos/network/socket/local/transport.hpp"

#if !defined(XOS_NETWORK_SOCKET_LOCAL_TRANSPORT_INSTANCE)
///#define XOS_NETWORK_SOCKET_LOCAL_TRANSPORT_INSTANCE
#endif /// !defined(XOS_NETWORK_SOCKET_LOCAL_TRANSPORT_INSTANCE)

namespace xos {
namespace network {
namespace socket {
namespace local {

///  Class: transportt
#if defined(XOS_NETWORK_SOCKET_LOCAL_TRANSPORT_INSTANCE)
static transport the_transport;
#endif /// defined(XOS_NETWORK_SOCKET_LOCAL_TRANSPORT_INSTANCE)


} /// namespace local
} /// namespace socket
} /// namespace network
} /// namespace xos
