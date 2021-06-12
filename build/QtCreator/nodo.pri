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
# Build specific QtCreator .pri file for nodo
########################################################################
contains(BUILD_OS,Uname) {
UNAME = $$system(uname)

contains(UNAME,Darwin) {
BUILD_OS = macosx
} else {
contains(UNAME,Linux) {
BUILD_OS = linux
} else {
contains(UNAME,Windows) {
BUILD_OS = windows
} else {
BUILD_OS = os
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)
} else {
contains(BUILD_OS,NODO_OS) {
} else {
BUILD_OS = os
} # contains(BUILD_OS,NODO_OS)
} # contains(BUILD_OS,Uname)

#BUILD_CPP_VERSION = 11

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir FRAMEWORKS
#
build_nadir_FRAMEWORKS += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# rete
#
# pkg-config --cflags --libs rete
#

# build rete INCLUDEPATH
#
build_rete_INCLUDEPATH += \

# build rete DEFINES
#
build_rete_DEFINES += \

# build rete FRAMEWORKS
#
build_rete_FRAMEWORKS += \

# build rete LIBS
#
build_rete_LIBS += \

########################################################################
# nodo

# build nodo INCLUDEPATH
#
build_nodo_INCLUDEPATH += \
$${build_rete_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \


# build nodo DEFINES
#
build_nodo_DEFINES += \
$${build_nadir_DEFINES} \
$${build_rete_DEFINES} \


# build nodo FRAMEWORKS
#
build_nodo_FRAMEWORKS += \
$${build_rete_FRAMEWORKS} \
$${build_nadir_FRAMEWORKS} \


# build nodo LIBS
#
build_nodo_LIBS += \
$${build_rete_LIBS} \
$${build_nadir_LIBS} \


