
BINARY = test_library
HEADERS +=  -I.
OBJECT_FILE = test.o
LDFLAGS= -L. -ltutu

all: prep $(BINARY)

prep:
	-cp -f ../build/libtutu.a .
	-cp -f ../build/libtutu.so .
	cp ../inc/tutu1.h .

$(BINARY): $(OBJECT_FILE)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADERS)

clean:
	find . -name "*.o" -print0 | xargs -0 rm -f
	find . -name "*.wav" -print0 | xargs -0 rm -f
	rm -f $(BINARY)
	rm -f *.a
	rm -f tutu1.h
