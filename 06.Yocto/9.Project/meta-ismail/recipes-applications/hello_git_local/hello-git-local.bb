LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
S = "${WORKDIR}/git"
SRC_URI = "git:///home/ismail/my_flash/poky/meta-ismail/recipes-applications/hello_git_local/files;protocol=file"

SRCREV = "a50496f988e8b2ebe67f90fc8dfe8d76e303e239"
do_fetch[network] = "0"
inherit cmake


