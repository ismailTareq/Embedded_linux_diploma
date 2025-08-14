SUMMARY = "Ismail Example Recipe"
DESCRIPTION = "This is an example recipe for Ismail."
LICENSE = "CLOSED"
SRC_URI = "file://main.c"
S = "${WORKDIR}"

do_compile(){
    bbwarn "Compiling Ismail example recipe"
    ${CC} ${LDFLAGS} ${WORKDIR}/main.c -o ${WORKDIR}/ismail 
}

do_install(){
    bbwarn "Installing Ismail example recipe"
    mkdir -p ${D}/usr/bin
    cp ${WORKDIR}/ismail ${D}/usr/bin
}
