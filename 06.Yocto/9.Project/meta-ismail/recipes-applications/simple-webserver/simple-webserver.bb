SUMMARY = "Simple web server setup"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "file://testing.txt \
           file://hello.html  \
           file://status.txt \  
"
S = "${WORKDIR}" 

RDEPENDS:${PN} = "lighttpd"

do_install() {
    # Create web directory and install the text file
    install -d ${D}/www/pages/
    install -m 644 ${WORKDIR}/testing.txt ${D}/www/pages/
    install -m 644 ${WORKDIR}/hello.html ${D}/www/pages/
    install -m 644 ${WORKDIR}/status.txt ${D}/www/pages/
}

pkg_postinst:${PN} () {
    #!/bin/sh
    if [ -z "$D" ]; then
        # Create directory with proper permissions
        mkdir -p /www/pages/
        chown -R lighttpd:lighttpd /www 2>/dev/null || chown -R www-data:www-data /www 2>/dev/null || chown -R root:root /www
        chmod -R 755 /www
        # Start lighttpd
        if command -v systemctl >/dev/null 2>&1; then
            systemctl enable lighttpd
            systemctl start lighttpd
        fi
    fi
}
FILES:${PN} = "/www/ /www/pages/ /www/pages/* "
