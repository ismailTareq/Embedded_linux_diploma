LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRC_URI = "git://github.com/Moatasem-Elsayed/cpu-Tracker-notify-by-Email.git;protocol=https;branch=main"
SRCREV = "100327595565b5cade302e796c779d5be069f79d"
PV = "1.0+git${SRCPV}"
S = "${WORKDIR}/git"
inherit cmake

do_install() {
    install -d ${D}${bindir}
    install -m 0755 CPU_Tracker ${D}${bindir}/cpu-tracker
}

