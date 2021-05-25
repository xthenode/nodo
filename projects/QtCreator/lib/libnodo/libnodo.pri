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
#   File: libnodo.pri
#
# Author: $author$
#   Date: 5/22/2021
#
# QtCreator .pri file for nodo library libnodo
########################################################################

########################################################################
# libnodo

# libnodo TARGET
#
libnodo_TARGET = nodo
libnodo_TEMPLATE = lib
libnodo_CONFIG += staticlib

# libnodo INCLUDEPATH
#
libnodo_INCLUDEPATH += \
$${nodo_INCLUDEPATH} \

# libnodo DEFINES
#
libnodo_DEFINES += \
$${nodo_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# libnodo OBJECTIVE_HEADERS
#
#libnodo_OBJECTIVE_HEADERS += \
#$${NODO_SRC}/xos/app/console/nodo/main.hh \

# libnodo OBJECTIVE_SOURCES
#
#libnodo_OBJECTIVE_SOURCES += \
#$${NODO_SRC}/xos/app/console/nodo/main.mm \

########################################################################
# libnodo HEADERS
#
libnodo_HEADERS += \
$${NODO_SRC}/xos/lib/nodo/version.hpp \

# libnodo SOURCES
#
libnodo_SOURCES += \
$${NODO_SRC}/xos/lib/nodo/version.cpp \

########################################################################



