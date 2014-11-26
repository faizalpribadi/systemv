#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([systemv], [1.0], [faizal_pribadi@aol.com])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_SRCDIR([src/systemv.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
SYSTEMD_REQUIRED_VERSION=2.1.7
PKG_CHECK_MODULES(systemd, systemd-2.1.7 >= $SYSTEMD_REQUIRED_VERSION)

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T

# Checks for library functions.
AC_CHECK_FUNCS([memset socket strtoul])

AC_CONFIG_FILES([docs/Makefile
                 examples/Makefile
                 man/Makefile
                 scripts/Makefile
                 src/Makefile])

AC_OUTPUT
