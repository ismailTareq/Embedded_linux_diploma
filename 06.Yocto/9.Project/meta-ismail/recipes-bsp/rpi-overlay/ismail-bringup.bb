SUMMARY = "RPi-4 overlay: DHT11 + LED + button"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://ismail-bringup-overlay.dts"
S = "${WORKDIR}"

DEPENDS += "dtc-native dtc"

do_compile() {
    dtc -@ -H epapr -O dtb -o ismail-bringup-overlay.dtbo ismail-bringup-overlay.dts
}

do_install() {
    # create directory AND install file in one shot
    install -D -m 644 ismail-bringup-overlay.dtbo \
        ${D}/lib/firmware/overlays/ismail-bringup-overlay.dtbo
}

# Tell bitbake exactly where we put it
FILES:${PN} += "/lib/firmware/overlays/ismail-bringup-overlay.dtbo"

COMPATIBLE_MACHINE = "raspberrypi4-64"
