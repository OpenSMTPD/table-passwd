/*
 * Copyright (c) 2013 Eric Faurot <eric@openbsd.org>
 * Copyright (c) 2011 Gilles Chehade <gilles@poolp.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

enum table_service {
	K_ALIAS =	0x001,	/* returns struct expand	*/
	K_DOMAIN =	0x002,	/* returns struct destination	*/
	K_CREDENTIALS =	0x004,	/* returns struct credentials	*/
	K_NETADDR =	0x008,	/* returns struct netaddr	*/
	K_USERINFO =	0x010,	/* returns struct userinfo	*/
	K_SOURCE =	0x020,	/* returns struct source	*/
	K_MAILADDR =	0x040,	/* returns struct mailaddr	*/
	K_ADDRNAME =	0x080,	/* returns struct addrname	*/
	K_MAILADDRMAP =	0x100,	/* returns struct mailaddr	*/
	K_ANY =		0xfff,
};

void		 table_api_on_update(int(*)(void));
void		 table_api_on_check(int(*)(int, struct dict *, const char *));
void		 table_api_on_lookup(int(*)(int, struct dict *, const char *, char *, size_t));
void		 table_api_on_fetch(int(*)(int, struct dict *, char *, size_t));
int		 table_api_dispatch(void);
const char	*table_api_get_name(void);
