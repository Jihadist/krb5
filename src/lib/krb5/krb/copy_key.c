/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/mit-copyright.h>.
 *
 * krb5_copy_keyblock()
 */

#if !defined(lint) && !defined(SABER)
static char copy_key_c[] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/copyright.h>
#include <krb5/krb5.h>
#include <krb5/ext-proto.h>

#include <errno.h>

/*
 * Copy a keyblock, including alloc'ed storage.
 */
krb5_error_code
krb5_copy_keyblock(from, to)
const krb5_keyblock *from;
krb5_keyblock *to;
{
    *to = *from;
    to->contents = (krb5_octet *)malloc(to->length);
    if (!to->contents)
	return ENOMEM;
    bcopy((char *)from->contents, (char *)to->contents, to->length);
    return 0;
}
