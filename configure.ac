AC_INIT([table-passwd], [0.1], [bugs@opensmtpd.org])
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

AC_CHECK_HEADER([sys/tree.h], [], [
	CFLAGS="$CFLAGS -I$srcdir/openbsd-compat/tree"
])

AC_DEFUN([CC_ADD_CHECK_FLAGS], [
	AC_MSG_CHECKING([if $CC supports $1 flag])
	old_CFLAGS="$CFLAGS"
	CFLAGS="$CFLAGS $1"
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [])], [
		AC_MSG_RESULT(yes)
	], [
		AC_MSG_RESULT(no)
		CFLAGS="$old_CFLAGS"
	])
])
CC_ADD_CHECK_FLAGS([-MMD])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
])
AC_OUTPUT
