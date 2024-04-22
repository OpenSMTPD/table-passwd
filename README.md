TABLE\_PASSWD(5) - File Formats Manual

# NAME

**table\_passwd** - format description for smtpd passwd tables

# DESCRIPTION

This manual page documents the file format of "passwd" tables used by the
smtpd(8)
mail daemon.

The format described here applies to tables as defined in
smtpd.conf(5).

# PASSWD TABLE

A "passwd" table stores information regarding local users.
The information is encoded using the traditional
passwd(5)
format and allows the sharing of a user database across different software
supporting this format.

The table is used by
smtpd(8)
when authenticating a user or when user information such as user-id or
home directory is required for a delivery.

A "passwd" table consists of a flat file containing the user entries, each
one on a line by itself, with fields separated by a colon:

	gilles:*:1000:1000:Gilles:/home/gilles:/sbin/nologin
	eric:*:1001:1001:Eric:/home/eric:/sbin/nologin
	chl:*:1002:1002:Charles:/home/chl:/sbin/nologin

Besides the first username field and depending on the table type, fields are
optional and might be empty.
The gecos and the shell field are not used and ignored.

If the table is used for authentication, the second field should contain a
password encrypted using the
crypt(3)
function.
Such passwords can be generated using the
encrypt(1)
utility or
smtpctl(8)
encrypt command.

If the table is used for user information, user-id, group-id, and home
directory fields are required.

In favor of supporting shared authentication with the Dovecot Passwd-file
format, extra fields after the last shell field are allowed (and ignored).

# SEE ALSO

passwd(5),
smtpd.conf(5),
smtpctl(8),
smtpd(8)

# HISTORY

The first version of
**table\_passwd**
was written in 2013.
It was converted to the stdio table protocol in 2024.

# AUTHORS

**table\_passwd**
was intially written by
Gilles Chehade &lt;[gilles@poolp.org](mailto:gilles@poolp.org)&gt;
and further improved by
Joerg Jung &lt;[jung@openbsd.org](mailto:jung@openbsd.org)&gt;.
The conversion to the stdio table protocol was done by
Omar Polo &lt;[op@openbsd.org](mailto:op@openbsd.org)&gt;.

OpenBSD 7.5 - April 4, 2024
