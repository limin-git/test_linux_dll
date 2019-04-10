
GCC = g++ -w -fpermissive
AR = ar cvr

ALL : main libdll1.so libdll2.so liba.a

lib.o : lib.cpp
	$(GCC) -c -fPIC -o $@ $<

liba.a : lib.o
	$(AR) $@ $<

libdll1.so : dll.cpp liba.a
	$(GCC) -o $@ -shared dll.cpp -la -L.

libdll2.so : dll.cpp liba.a
	$(GCC) -o $@ -shared dll.cpp -la -L.

main : main.cpp liba.a
	$(GCC) -o $@ main.cpp -la -ldl -L.

.PHONY: clean
clean:
	$(RM) *.o *.a *.so
