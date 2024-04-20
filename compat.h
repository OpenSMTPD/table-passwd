#include "config.h"

#include <stddef.h>
#include <limits.h>

#ifndef UID_MAX
#define UID_MAX UINT_MAX
#endif
#ifndef GID_MAX
#define GID_MAX UINT_MAX
#endif

#ifndef __dead
#define __dead __attribute__((noreturn))
#endif

#ifndef HAVE_ASPRINTF
int		 asprintf(char **, const char *, ...);
#endif

#ifndef HAVE_GETPROGNAME
const char	*getprogname(void);
#endif

#ifndef HAVE_STRLCAT
size_t		 strlcat(char *, const char *, size_t);
#endif

#ifndef HAVE_STRLCPY
size_t		 strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_STRSEP
char		*strsep(char **, const char *);
#endif

#ifndef HAVE_STRTONUM
long long	 strtonum(const char *, long long, long long, const char **);
#endif
