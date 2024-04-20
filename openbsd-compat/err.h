#include "../compat.h"

#ifdef HAVE_ERR
# include_next <err.h>
#else
__dead void	 err(int, const char *, ...);
__dead void	 errx(int, const char *, ...);
void		 warn(const char *, ...);
void		 warnx(const char *, ...);
#endif
