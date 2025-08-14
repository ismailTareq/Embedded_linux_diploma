all: main.cpp

	${CXX} ${LDFLAGS} ${CXXFLAGS} -o dht11-reader main.cpp -lgpiod

clean:
	rm -f dht11-reader

install:
	install -d ${DISTDIR}
	install -m 0755 dht11-reader ${DISTDIR}
