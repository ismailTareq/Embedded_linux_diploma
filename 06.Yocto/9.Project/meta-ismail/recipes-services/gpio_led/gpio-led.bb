LICENSE = "CLOSED"
SRC_URI = "file://main.cpp \
           file://led-gpio.service"

S = "${WORKDIR}"

DEPENDS = "libgpiod"
inherit systemd

do_compile(){
    # Compile the C++ source code
    ${CXX} ${CXXFLAGS} ${LDFLAGS} -o led-gpio main.cpp -lgpiod -lgpiodcxx
}

do_install(){
    # Install the compiled binary
    install -d ${D}${bindir}
    install -m 0755 led-gpio ${D}${bindir}

    # Install the systemd service file
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 led-gpio.service ${D}${systemd_system_unitdir}
}
SYSTEMD_SERVICE:${PN} = "led-gpio.service"
