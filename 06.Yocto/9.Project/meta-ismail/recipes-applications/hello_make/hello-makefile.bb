LICENSE = "CLOSED"
S = "${WORKDIR}"

SRC_URI = "file://Makefile \
           file://main.c"

EXTRA_OEMAKE = "DISTDIR=${D}${bindir}"

do_compile() {
    bbwarn "Compiling hello_makefile"
    oe_runmake
}

do_install() {
    bbwarn "Installing hello_makefile"
    oe_runmake install
}
