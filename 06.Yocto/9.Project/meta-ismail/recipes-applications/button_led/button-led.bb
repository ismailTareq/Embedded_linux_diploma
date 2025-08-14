SUMMARY = "GPIO button-to-LED toggle utility"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

DEPENDS = "libgpiod"
RDEPENDS:${PN} = "libgpiod"

SRC_URI = "file://main.cpp \
           file://Makefile \   
"
S = "${WORKDIR}"

EXTRA_OEMAKE = "DISTDIR=${D}${bindir}"

do_compile() {
    bbwarn "Installing gpio-toggle"
    oe_runmake
}

do_install() {
    bbwarn "Installing gpio-toggle"
    oe_runmake install
}

