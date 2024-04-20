AC_INIT([table-passwd], [0.1], [bugs@opensmtpd.org])
AC_CONFIG_AUX_DIR(etc)
AC_CONFIG_LIBOBJ_DIR(openbsd-compat)
AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS

AC_ARG_WITH([libbsd],
	AS_HELP_STRING([--with-libbsd],
		[Build with libbsd library (default: disabled)]))

AS_IF([test "x$with_libbsd" = "xyes"], [
	PKG_CHECK_MODULES([libbsd], [libbsd-overlay libbsd-ctor], [
		CFLAGS="$libbsd_CFLAGS $CFLAGS"
		LIBS="$libbsd_LIBS $LIBS"
	])
])

AC_REPLACE_FUNCS([ \
	asprintf \
	getprogname \
	err \
	strlcat \
	strlcpy \
	strsep \
	strtonum \
])

CFLAGS="$CFLAGS -I$srcdir/openbsd-compat"

AC_CHECK_HEADER([sys/queue.h], [], [
	CFLAGS="$CFLAGS -I$srcdir/openbsd-compat/tree"
])

AC_CHECK_HEADER([sys/tree.h], [], [
	CFLAGS="$CFLAGS -I$srcdir/openbsd-compat/tree"
])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
])
AC_OUTPUT
