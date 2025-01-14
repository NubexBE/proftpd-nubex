

top_builddir=..
top_srcdir=..
srcdir=.


include ../Make.rules

LIB_DEPS=libltdl
LIB_OBJS=pr_fnmatch.o sstrncpy.o strsep.o vsnprintf.o glibc-glob.o glibc-hstrerror.o glibc-mkstemp.o pr-syslog.o pwgrent.o hanson-tpl.o ccan-json.o openbsd-blowfish.o openbsd-bcrypt.o

"":

dummy:

all:
	@echo "Running make from top level directory."
	cd ../ && $(MAKE) all

Makefile: Makefile.in ../config.status
	cd ../ && ./config.status

.c.o:
	$(LIBTOOL) --mode=compile --tag=CC $(CC) $(CPPFLAGS) $(CFLAGS) -static -c $<

libltdl: dummy
	cd libltdl/ && $(MAKE)

prbase.a: $(LIB_OBJS)
	$(AR) rc prbase.a $(LIB_OBJS)
	$(RANLIB) prbase.a

lib: prbase.a $(LIB_DEPS)

install:

clean:
	$(RM) *.o *.gcda *.gcno prbase.a
	$(LIBTOOL) --mode=clean $(RM) `echo $(LIB_OBJS) | sed 's/\.o$\/.lo/g'`
	test -z $(LIB_DEPS) || (cd libltdl/ && $(MAKE) clean)

depend:
	$(MAKEDEPEND) $(CPPFLAGS) $(top_srcdir)/lib/*.c 2>/dev/null
	$(MAKEDEPEND) $(CPPFLAGS) -fMakefile.in $(top_srcdir)/lib/*.c 2>/dev/null

distclean: clean
	-$(RM) *.gcda *.gcno
	test -z $(LIB_DEPS) || (cd libltdl/ && $(MAKE) distclean)
