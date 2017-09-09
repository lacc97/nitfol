MAJOR = 0
MINOR = 5
DISTNAME = nitfol-$(MAJOR).$(MINOR)
CATEGORIES = games
MASTER_SITES = ftp://ftp.gmd.de/if-archive/infocom/interpreters/nitfol/
MAINTAINER = nitfol@my-deja.com
MAN6 = nitfol.6

#
#  If you're trying to make xnitfol and get link errors for xlibs and such,
#  edit xglk's Makefile to generate a more correct Make.xglk.
#

OSLIBS =

# Installation locations:

DESTDIR = /usr/local
prefix = $(DESTDIR)
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
infodir = $(prefix)/info
mandir = $(prefix)/man
man6dir = $(mandir)/man6

# This should be the directory off of which you store your glks
# For example, if you want to link with xglk which is located in
# /usr/local/src/xglk/, set PATHTOGLK = /usr/local/src
# If your different Glks are not children of the same directory,
# you'll need to modify each one in their rules below
PATHTOGLK = ..



# Define the stuff you want:
#
# DEBUGGING   Compile in the debugger.  See DEBUG for details
# SMART_TOKENISER Tries to correct typos.
# TWOS16SHORT Try to speed up some operations if 'short' is a 16 bit two's
#             complement number on your system.  Note that this might slow down
#             Pentium IIs.
# FAST_SIGNED If you're on something which does signed math much faster than
#             unsigned, define this
# FAST        Normally, nitfol does lots of tests to make sure values are in
#             range, both to alert games of unportable actions and to prevent
#             nitfol from crashing.  Defining this removes those tests, so will
#             speed up the game a bit.  Completely legal games should run
#             exactly the same with or without this flag, so if you have a
#             slow computer and you know all the games you will be running are
#             completely legal, define this.
# USE_INLINE  If your C compiler uses the keyword 'inline' to inline functions
# NO_LIBC     Cause nitfol to use its own functions rather than your libc
# NO_TICK     If you don't need glk_tick, define this (minor speed improvement)
# _GNU_SOURCE Use GNU functions (currently just canonicalize_file_name)
# _BSD_SOURCE Use BSD functions (just realpath)
# _XOPEN_SOURCE (also lets nitfol use realpath)

# I recommend you leave it with -DSMART_TOKENISER -DDEBUGGING unless these
# options annoy you or you're really pressed for speed/size.
DEFS = -DSMART_TOKENISER -DDEBUGGING -DNO_TICK
#DEFS = -DSMART_TOKENISER -DDEBUGGING -D_GNU_SOURCE
#DEFS = -DFAST


##########
# Names and locations of programs
#

# If you have cfunctions, comment in the right line.  If you don't even have
# true, use echo
CFUNCTIONS=echo
CFUNCTIONS=true
CFUNCTIONS=cfunctions


# If you use yacc instead of bison, you MUST have either debugging enabled
# or taken inform.y out of SRCS
YACC = bison -y

CC = gcc


INSTALL = /usr/bin/install

# Solaris 2.x
#INSTALL = /usr/ucb/install


UNINSTALL = $(RM)

# For GNU install-info
INSTALL_INFO = install-info --info-dir=$(infodir)

# For Debian install-info
#INSTALL_INFO = install-info --info-dir=$(infodir) --section .\*game.\* Games

UNINSTALL_INFO = install-info --info-dir=$(infodir) --remove


##############
# Compilation and linking options
#

ALLFLAGS = -g
WARNS = -pedantic -Wall -W -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wbad-function-cast -Wwrite-strings
CFLAGS = -ansi $(WARNS) $(ALLFLAGS)
LIBS = -L$(GLKLIBDIR) $(OSLIBS) $(GLKLIB) $(LINKLIBS) $(EXTRALIBS)
LDFLAGS = $(ALLFLAGS)


SRCS = automap.c solve.c infix.c copying.c debug.c inform.y quetzal.c undo.c op_call.c decode.c errmesg.c globals.c iff.c init.c main.c io.c z_io.c op_jmp.c op_math.c op_save.c op_table.c op_v6.c oplist.c stack.c zscii.c tokenise.c struct.c objects.c portfunc.c hash.c

CSRCS = $(SRCS:.y=.c)

INCL = nitfol.h binary.h $(CSRCS:.c=.h)
OBJS = $(CSRCS:.c=.o) $(GLKSPECIFIC:.c=.o)


default:
	@echo "You must specify a Glk target. This makefile assumes the"
	@echo "requested Glk library can be found in $(PATHTOGLK)/glkname/"
	@echo " Command                      Looks in"
	@echo "  make xnitfol                 $(PATHTOGLK)/xglk/"
	@echo "  make termnitfol              $(PATHTOGLK)/glkterm/"
	@echo "  make cheapnitfol             $(PATHTOGLK)/cheapglk/"
	@echo "  ...                          ..."


EXECUTABLES = xnitfol termnitfol cheapnitfol
all: $(EXECUTABLES)


# We only want to do an include if we're coming around the second time.
# Unfortunately, 'ifdef' is a GNU extension, so I shouldn't use it.  Declare
# variables that will be overridden when specified on the commandline.
GLKINCLUDEDIR = .
GLKMAKEFILE = Make.dummy

include $(GLKINCLUDEDIR)/$(GLKMAKEFILE)


# recursive uglies because 'include' can't see target-specific variables

xnitfol: $(OBJS) startunix.o graphics.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/xglk GLKLIBDIR=$(PATHTOGLK)/xglk GLKMAKEFILE=Make.xglk "GLKSPECIFIC=startunix.c graphics.c blorb.c no_snd.c" PRODUCT=$@

fencenitfol: $(OBJS) startunix.o graphics.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/xglk GLKLIBDIR=$(PATHTOGLK)/xglk GLKMAKEFILE=Make.xglk "GLKSPECIFIC=startunix.c graphics.c blorb.c no_snd.c" OSLIBS=-lefence PRODUCT=$@

termnitfol: $(OBJS) startunix.o no_graph.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/glkterm GLKLIBDIR=$(PATHTOGLK)/glkterm GLKMAKEFILE=Make.glkterm "GLKSPECIFIC=startunix.c no_graph.c blorb.c no_snd.c" PRODUCT=$@

dosnitfol: $(OBJS) startdos.o no_graph.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/glkterm GLKLIBDIR=$(PATHTOGLK)/glkterm GLKMAKEFILE=Make.glk "GLKSPECIFIC=startdos.c no_graph.c blorb.c no_snd.c" PRODUCT=nitfol.exe

cheapnitfol: $(OBJS) startunix.o no_graph.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/cheapglk GLKLIBDIR=$(PATHTOGLK)/cheapglk GLKMAKEFILE=Make.cheapglk "GLKSPECIFIC=startunix.c no_graph.c blorb.c no_snd.c" PRODUCT=$@

winnitfol: $(OBJS) startwin.o graph.o blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/winglk GLKLIBDIR=$(PATHTOGLK)/winglk GLKMAKEFILE=Make.winglk "GLKSPECIFIC=startwin.c graph.c blorb.c no_snd.c" PRODUCT=$@

mudnitfol: $(OBJS) startunix.o no_graph.o no_blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/mudglk GLKLIBDIR=$(PATHTOGLK)/mudglk GLKMAKEFILE=Make.mudglk "GLKSPECIFIC=startunix.c no_graph.c no_blorb.c no_snd.c" PRODUCT=$@

mpcmudnitfol: $(OBJS) startunix.o no_graph.o no_blorb.o no_snd.o
	$(MAKE) nitfol GLKINCLUDEDIR=$(PATHTOGLK)/mudglk GLKLIBDIR=$(PATHTOGLK)/mudglk GLKMAKEFILE=Make.mpcmudglk "GLKSPECIFIC=startunix.c no_graph.c no_blorb.c no_snd.c" PRODUCT=$@


.SUFFIXES:
.SUFFIXES: .c .o .h .y


.y.c:
	$(YACC) $<
	mv y.tab.c $@

.c.o:	$(INCL)
	$(CC) $(DEFS) $(CFLAGS) -c $<

inform.h:
	cp inform.hhh inform.h

.c.h:
	$(CFUNCTIONS) -i $<

# Prevent deletion of inform.c, so people without a yacc don't get in trouble
.SECONDARY: inform.c


startunix.c: nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -unix nitfol.opt

startdos.c: nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -dos nitfol.opt

# djgpp chokes if startdos.c is compiled with -ansi
startdos.o: startdos.c
	$(CC) $(ALLFLAGS) $(WARNS) $(DEFS) -c $<

startwin.c: nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -win nitfol.opt

startmac.c: nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -mac nitfol.opt

# Make copying.c from COPYING
copying.c: COPYING copying.awk
	awk -f copying.awk < COPYING > copying.c

options.texi: nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -info nitfol.opt

dbg_help.texi: inform.y y2help.pl
	perl y2help.pl inform.y

dbg_help.h: inform.y y2help.pl
	perl y2help.pl inform.y

nitfol.info: nitfol.texi options.texi dbg_help.texi
	makeinfo nitfol.texi

nitfol.html: nitfol.texi options.texi dbg_help.texi
	texi2html -monolithic -number nitfol.texi

nitfol.6: nitfol.texi nitfol.opt opt2glkc.pl
	perl opt2glkc.pl -man nitfol.opt

nitfol.dvi: nitfol.texi options.texi dbg_help.texi
	mkdir doc && cd doc && cp ../nitfol.texi ../options.texi ../dbg_help.texi . && texi2dvi nitfol.texi && mv nitfol.dvi .. && cd .. && rm -rf doc

TAGS: $(SRCS)
	etags $(SRCS)



nitfol: $(OBJS) $(GLKSPECIFIC)
	$(CC) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(LIBS)


install:
	$(NORMAL_INSTALL)	# Normal commands follow.
	$(INSTALL) -d -m 755 $(bindir)
	$(INSTALL) -m 755 nitfol $(bindir)
	$(INSTALL) -s -m 755 $(EXECUTABLES) $(bindir)
	$(INSTALL) -d -m 755 $(man6dir)
	$(INSTALL) -m 755 $(MAN6) $(man6dir)
	$(INSTALL) -d -m 755 $(infodir)
	$(INSTALL) -m 755 nitfol.info $(infodir)
	$(POST_INSTALL)		# Post-install commands follow.
	$(INSTALL_INFO) nitfol.info

uninstall:
	$(PRE_UNINSTALL)	# Pre-uninstall commands follow.
	$(UNINSTALL_INFO) nitfol.info
	$(NORMAL_UNINSTALL)	# Normal commands follow.
	$(UNINSTALL) $(addprefix $(bindir)/,nitfol $(EXECUTABLES))
	$(UNINSTALL) $(man6dir)/nitfol.6
	$(UNINSTALL) $(infodir)/nitfol.info

backup: clean
	tar czf /home/ftp/pub/mycode/nitfol/snapshot/nitfol-`date +%Y%m%d`.tar.gz *

.PHONY: clean backup nitfol default all install uninstall realclean distclean

clean:
	$(RM) *~ *.o core TAGS $(EXECUTABLES)

realclean: clean
	$(RM) $(CSRCS:.c=.h) start*.[ch] nitfol.info nitfol.6 nitfol.html nitfol.dvi

distclean: realclean
	$(MAKE) all CFUNCTIONS=cfunctions
	$(MAKE) startunix.c
	$(MAKE) startmac.c
	$(MAKE) startwin.c
	$(MAKE) startdos.c
	$(MAKE) nitfol.info
	$(MAKE) nitfol.6
	$(MAKE) nitfol.html
	$(MAKE) clean

package: distclean
	mkdir /tmp/$(DISTNAME)
	cp * /tmp/$(DISTNAME)
	cd /tmp/ && tar cvzf $(DISTNAME).tar.gz $(DISTNAME)
	cd /tmp/$(DISTNAME) && zip nitfol$(MAJOR)$(MINOR).zip *
	mv /tmp/$(DISTNAME)/nitfol$(MAJOR)$(MINOR).zip /tmp/

# dependencies:

$(OBJS): $(INCL) Makefile

inform.o: dbg_help.h


#.c.d:
#	$(SHELL) -ec '$(CC) -MM $(CPPFLAGS) $< | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; [ -s $@ ] || $(RM) $@'
#
# include $(CSRCS:.c=.d)
