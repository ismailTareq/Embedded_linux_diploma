all: main.c
	${CC} ${LDFLAGS} ${CFLAGS} -o hello_makefile main.c

clean:
	rm -f hello_makefile

install:
	install -d ${DISTDIR}
	install -m 0755 hello_makefile ${DISTDIR}