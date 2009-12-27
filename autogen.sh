#1/bin/sh
aclocal -I m4
automake --add-missing -cf
autoconf
