########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: nodo.pri
#
# Author: $author$
#   Date: 5/22/2021
#
# QtCreator .pri file for nodo executable nodo
########################################################################

########################################################################
# nodo

# nodo_exe TARGET
#
nodo_exe_TARGET = nodo

# nodo_exe INCLUDEPATH
#
nodo_exe_INCLUDEPATH += \
$${nodo_INCLUDEPATH} \

# nodo_exe DEFINES
#
nodo_exe_DEFINES += \
$${nodo_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_INSTANCE \

########################################################################
# nodo_exe OBJECTIVE_HEADERS
#
#nodo_exe_OBJECTIVE_HEADERS += \
#$${NODO_SRC}/xos/app/console/nodo/main.hh \

# nodo_exe OBJECTIVE_SOURCES
#
#nodo_exe_OBJECTIVE_SOURCES += \
#$${NODO_SRC}/xos/app/console/nodo/main.mm \

########################################################################
# nodo_exe HEADERS
#
nodo_exe_HEADERS += \
$${NODO_SRC}/xos/network/address.hpp \
$${NODO_SRC}/xos/network/transport.hpp \
$${NODO_SRC}/xos/network/endpoint.hpp \
$${NODO_SRC}/xos/network/interface.hpp \
$${NODO_SRC}/xos/network/os/os.hpp \
$${NODO_SRC}/xos/network/sockets.hpp \
$${NODO_SRC}/xos/network/posix/sockets.hpp \
$${NODO_SRC}/xos/network/os/sockets.hpp \
\
$${NODO_SRC}/xos/network/socket/address.hpp \
$${NODO_SRC}/xos/network/socket/endpoint.hpp \
$${NODO_SRC}/xos/network/socket/transport.hpp \
$${NODO_SRC}/xos/network/socket/interface.hpp \
\
$${NODO_SRC}/xos/network/socket/local/address.hpp \
$${NODO_SRC}/xos/network/socket/local/endpoint.hpp \
$${NODO_SRC}/xos/network/socket/local/transport.hpp \
$${NODO_SRC}/xos/network/socket/local/dgram/transport.hpp \
$${NODO_SRC}/xos/network/socket/local/stream/transport.hpp \
$${NODO_SRC}/xos/network/socket/local/transports.hpp \
\
$${NODO_SRC}/xos/network/socket/ip/address.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/address.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/address.hpp \
$${NODO_SRC}/xos/network/socket/ip/addresses.hpp \
$${NODO_SRC}/xos/network/socket/addresses.hpp \
\
$${NODO_SRC}/xos/network/socket/ip/endpoint.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/endpoint.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/endpoint.hpp \
$${NODO_SRC}/xos/network/socket/ip/endpoints.hpp \
$${NODO_SRC}/xos/network/socket/endpoints.hpp \
\
$${NODO_SRC}/xos/network/socket/ip/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/raw/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/tcp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/udp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/raw/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/tcp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/udp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v4/transports.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/raw/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/tcp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/udp/transport.hpp \
$${NODO_SRC}/xos/network/socket/ip/v6/transports.hpp \
$${NODO_SRC}/xos/network/socket/ip/transports.hpp \
$${NODO_SRC}/xos/network/socket/transports.hpp \
\
$${NODO_SRC}/xos/network/socket/os/os.hpp \
$${NODO_SRC}/xos/network/socket/posix/os.hpp \
$${NODO_SRC}/xos/network/socket/posix/interface.hpp \
$${NODO_SRC}/xos/network/socket/os/interface.hpp \
$${NODO_SRC}/xos/network/socket/os/interfaces.hpp \
$${NODO_SRC}/xos/network/socket/interfaces.hpp \
\
$${NODO_SRC}/xos/app/console/nodo/main_opt.hpp \
$${NODO_SRC}/xos/app/console/nodo/main.hpp \
\
$${NODO_SRC}/xos/app/console/network/base/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/base/main.hpp \
$${NODO_SRC}/xos/app/console/network/client/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/client/main.hpp \
$${NODO_SRC}/xos/app/console/network/server/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/server/main.hpp \
\
$${NODO_SRC}/xos/app/console/network/sockets/base/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/base/main.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/client/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/client/main.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/server/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/server/main.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/main_opt.hpp \
$${NODO_SRC}/xos/app/console/network/sockets/main.hpp \
\
$${NODO_SRC}/xos/app/console/main_main.hpp \

# nodo_exe SOURCES
#
nodo_exe_SOURCES += \
$${NODO_SRC}/xos/network/os/os.cpp \
$${NODO_SRC}/xos/network/os/sockets.cpp \
\
$${NODO_SRC}/xos/network/socket/addresses.cpp \
$${NODO_SRC}/xos/network/socket/endpoints.cpp \
$${NODO_SRC}/xos/network/socket/transports.cpp \
$${NODO_SRC}/xos/network/socket/interfaces.cpp \
\
$${NODO_SRC}/xos/app/console/network/sockets/main_opt.cpp \
$${NODO_SRC}/xos/app/console/network/sockets/main.cpp \
\
$${NODO_SRC}/xos/app/console/main_main.cpp \

########################################################################
# nodo_exe FRAMEWORKS
#
nodo_exe_FRAMEWORKS += \
$${nodo_FRAMEWORKS} \

# nodo_exe LIBS
#
nodo_exe_LIBS += \
$${nodo_LIBS} \


