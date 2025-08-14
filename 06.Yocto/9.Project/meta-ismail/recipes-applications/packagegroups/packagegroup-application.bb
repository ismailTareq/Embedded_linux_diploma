SUMMARY = "Application package group"

inherit packagegroup

RDEPENDS:${PN} = "hello-cmake \
                  helloismail \
                  hello-git-local \
                  hello-tar-local \
                  gpio-led  \
                  ismail-dht11 \
                  simple-webserver \
                  button-led \
"