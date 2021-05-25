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
#   File: libnodo.pro
#
# Author: $author$
#   Date: 5/22/2021
#
# QtCreator .pro file for nodo library libnodo
########################################################################
include(../../../../../../build/QtCreator/nodo.pri)
include(../../../../../build/QtCreator/nodo.pri)
include(../../../../QtCreator/nodo.pri)
include(../../nodo.pri)
include(../../../../QtCreator/lib/libnodo/libnodo.pri)

TARGET = $${libnodo_TARGET}
TEMPLATE = $${libnodo_TEMPLATE}
CONFIG += $${libnodo_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libnodo_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libnodo_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libnodo_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libnodo_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libnodo_HEADERS} \
$${libnodo_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libnodo_SOURCES} \

########################################################################


