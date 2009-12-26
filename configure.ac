AC_PREREQ([2.64])
AC_INIT([worg], [0.1], [maciek.borzecki@gmail.com])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
PKG_CHECK_MODULES([GTKMM], [gtkmm-2.4])
AC_SUBST([GTKMM_CFLAGS])
AC_SUBST([GTKMM_LIBS])

PKG_CHECK_MODULES([SQLITE3], [sqlite3])
AC_SUBST([SQLITE3_CFLAGS])
AC_SUBST([SQLITE3_LIBS])
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
