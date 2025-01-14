CC=gcc


top_builddir=..
top_srcdir=..
srcdir=.


include ../Make.rules


all:
	@echo "Running make from top level directory."
	cd ../; $(MAKE) all

Makefile: Makefile.in ../config.status
	cd ../ && ./config.status

.c.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<


src: $(OBJS) $(FTPDCTL_OBJS)

clean:
	$(RM) *.o *.gcda *.gcno

depend:
	$(MAKEDEPEND) $(CPPFLAGS) $(top_srcdir)/src/*.c 2>/dev/null
	$(MAKEDEPEND) $(CPPFLAGS) -fMakefile.in $(top_srcdir)/src/*.c 2>/dev/null

distclean: clean
	-$(RM) *.gcda *.gcno

clang-tidy:
	clang-tidy $(SRCS) -- $(CPPFLAGS) $(CFLAGS)
