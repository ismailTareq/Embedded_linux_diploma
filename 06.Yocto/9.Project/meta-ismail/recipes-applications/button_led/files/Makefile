all: main.cpp

	${CXX} ${LDFLAGS} ${CXXFLAGS} -o gpio-toggle main.cpp -lgpiod

clean:
	rm -f gpio-toggle

install:
	install -d ${DISTDIR}
	install -m 0755 gpio-toggle ${DISTDIR}
