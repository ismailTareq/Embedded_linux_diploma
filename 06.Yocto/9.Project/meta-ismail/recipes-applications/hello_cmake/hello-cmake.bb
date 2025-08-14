LICENSE = "CLOSED"
S = "${WORKDIR}"

SRC_URI = "file://main.c \
           file://CMakeLists.txt \
           file://hello-startup.service"

EXTRA_OECMAKE = "-DVALUE=42"

inherit cmake
inherit systemd

SYSTEMD_SERVICE:${PN} = "hello-startup.service"
do_install:append() {
    # Install the systemd service file
    install -d ${D}${systemd_system_unitdir}
    install -m 0744 ${WORKDIR}/hello-startup.service ${D}${systemd_system_unitdir}
}
