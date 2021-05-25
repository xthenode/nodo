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
///   File: os.hpp
///
/// Author: $author$
///   Date: 5/23/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKET_OS_OS_HPP
#define XOS_NETWORK_SOCKET_OS_OS_HPP

#include "xos/platform/build.hpp"

#if defined(WINDOWS)
#include "xos/network/socket/microsoft/windows/os.hpp"
#else /// defined(WINDOWS)
#include "xos/network/socket/posix/os.hpp"
#endif /// defined(WINDOWS)

namespace xos {
namespace network {
namespace socket {

namespace apple { namespace ios {} namespace osx {} namespace mach {} } /// namespace apple
namespace microsoft { namespace windows { namespace crt {} } } /// namespace microsoft
namespace oracle { namespace solaris {} } /// namespace oracle
namespace google { namespace android {} } /// namespace google
namespace ibm { namespace aix {} } /// namespace ibm
namespace hp { namespace hpux {} } /// namespace hp
namespace mach {} /// namespace mach
namespace linux {} /// namespace linux
namespace posix {} /// namespace posix
namespace bsd {} /// namespace bsd
namespace systemv {} /// namespace systemv

namespace os {

#if defined(WINDOWS)
namespace os = microsoft::windows;
#else /// defined(WINDOWS)
namespace os = posix;
#endif /// defined(WINDOWS)

} /// namespace os
} /// namespace socket
} /// namespace network
} /// namespace xos

#endif /// XOS_NETWORK_SOCKET_OS_OS_HPP
