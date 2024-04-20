noinst_PROGRAMS =	table-passwd

table_passwd_SOURCES =	table_passwd.c dict.c log.c table_stdio.c util.c

AM_CFLAGS =
LDADD =			$(LIBOBJS)

smtpdir =		${prefix}/libexec/smtpd

install-exec-local: $(noinst_PROGRAMS)
	$(MKDIR_P) $(DESTDIR)$(smtpdir)
	$(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $(noinst_PROGRAMS) $(DESTDIR)$(smtpdir)
