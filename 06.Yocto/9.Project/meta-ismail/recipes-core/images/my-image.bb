include recipes-core/images/core-image-minimal.bb
IMAGE_INSTALL:append = " net-tools openssl"
IMAGE_INSTALL:append = " python3 git dhcpcd "
IMAGE_INSTALL:append = " libgpiod libgpiod-dev"
IMAGE_INSTALL:append = " lighttpd simple-webserver"
IMAGE_INSTALL:append = " u-boot evtest kernel-modules"
IMAGE_INSTALL:append = " packagegroup-application"