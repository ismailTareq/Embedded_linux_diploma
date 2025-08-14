LICENSE = "CLOSED"
SUMMARY = "DHT11 Temperature and Humidity Sensor Reader"
LIC_FILES_CHKSUM = ""
S = "${WORKDIR}"
DEPENDS = "libgpiod"
RDEPENDS:${PN} = "libgpiod"

SRC_URI = "file://Makefile \
           file://main.cpp "


EXTRA_OEMAKE = "DISTDIR=${D}${bindir}"

do_compile() {
    bbwarn "Compiling dht11-reader"
    oe_runmake
}

do_install() {
    bbwarn "Installing dht11-reader"
    oe_runmake install
}
