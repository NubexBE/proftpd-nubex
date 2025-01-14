/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */
/* -*- C -*- */
/* @configure_input@ */

#ifndef		config_h_included
#define		config_h_included

/*************************************************************************
 * This section is automatically generated by 'configure'.  Adjust these
 * if configure didn't make a correct guess for your system.
 *************************************************************************/

/* Define to be the build options. */
#define PR_BUILD_OPTS " '--with-modules=mod_readme:mod_auth_pam:mod_tls:mod_proxy_protocol:mod_sftp:mod_ifsession:mod_ctrls_admin:mod_tls_shmcache' '--enable-openssl' '--enable-dso' '--enable-memcache' '--enable-nls' '--enable-ctrls' '--with-includes=/usr/include' '--with-libraries=/usr/lib' '--prefix=/usr'"

/* Define to be the build CFLAGS.  */
#define PR_BUILD_CFLAGS "-g2 -O2 -Wall -fno-omit-frame-pointer -fno-strict-aliasing"

/* Define to be the build LDLAGS.  */
#define PR_BUILD_LDFLAGS "-Wl,-L$(top_srcdir)/lib,-L$(top_builddir)/lib  -rdynamic -L/usr/lib"

/* Define to be the build LIBS.  */
#define PR_BUILD_LIBS " -lssl -lcrypto -lssl  -lpam  -lcrypto -lcrypt -lmemcachedutil -lmemcached  -pthread"

/* Define to be the build platform. */
#define PR_PLATFORM "LINUX"

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef ino_t */

/* Define to `int' if <sys/types.h> doesn't define. */
#define HAVE_INTPTR_T 1
#if !defined(HAVE_INTPTR_T)
# define intptr_t	int
#endif /* HAVE_INTPTR_T */

/* Define to `int' if <sys/socket.h> doesn't define. */
/* #undef socklen_t */

/* Define if you have AIX send_file() semantics. */
/* #undef HAVE_AIX_SENDFILE */

/* Define if you have BSD POSIX ACLs. */
/* #undef HAVE_BSD_POSIX_ACL */

/* Define if you have BSD sendfile() semantics. */
/* #undef HAVE_BSD_SENDFILE */

/* Define if you have Linux POSIX ACLs. */
/* #undef HAVE_LINUX_POSIX_ACL */

/* Define if you have Linux sendfile() semantics. */
#define HAVE_LINUX_SENDFILE 1

/* Define if you have MacOSX POSIX ACLs. */
/* #undef HAVE_MACOSX_POSIX_ACL */

/* Define if you have MacOSX sendfile() semantics.  */
/* #undef HAVE_MACOSX_SENDFILE */

/* Define if you have Solaris POSIX ACLs. */
/* #undef HAVE_SOLARIS_POSIX_ACL */

/* Define if you have Solaris sendfile() semantics. */
/* #undef HAVE_SOLARIS_SENDFILE */

/* Define if your <syslog.h> defines the LOG_CRON macro */
#define HAVE_LOG_CRON 1

/* Define if your <syslog.h> defines the LOG_FTP macro */
#define HAVE_LOG_FTP 1

/* Define if you want support for PAM based authentication */
#define HAVE_PAM 1

/* Define if your DIR structure has member dd_fd */
/* #undef HAVE_STRUCT_DIR_DD_FD */

/* Define if your DIR structure has member __dd_fd */
/* #undef HAVE_STRUCT_DIR___DD_FD */

/* Define if you have struct cmsgcred.  */
/* #undef HAVE_STRUCT_CMSGCRED */

/* Define if you have struct sockcred.  */
/* #undef HAVE_STRUCT_SOCKCRED */

/* Define if you have struct sockpeercred.  */
/* #undef HAVE_STRUCT_SOCKPEERCRED */

/* Define if your spwd structure has member warn */
#define HAVE_SPWD_SP_WARN 1

/* Define if your spwd structure has member inact */
#define HAVE_SPWD_SP_INACT 1

/* Define if your spwd structure has member expire */
#define HAVE_SPWD_SP_EXPIRE 1

/* Define if your system has __progname */
#define HAVE___PROGNAME 1

/* Define if your system has _pw_stayopen variable (IRIX specific?) */
/* #undef HAVE__PW_STAYOPEN */

/* Define if your system has POSIX ACL support */
/* #undef HAVE_POSIX_ACL */

/* Define if your system has the sendfile function */
#define HAVE_SENDFILE 1

/* Define this if you have the setpassent function */
/* #undef HAVE_SETPASSENT */

/* Define if your system has the setspent function.  */
#define HAVE_SETSPENT 1

/* Define if your DIR structure has member d_fd */
/* #undef HAVE_STRUCT_DIR_D_FD */

/* Define if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define if you have the tzname global variable.  */
#define HAVE_TZNAME 1

/* Define if your struct utmp has ut_host */
#define HAVE_UT_UT_HOST 1

/* Define if your struct utmp uses ut_user and not ut_name */
/* #undef HAVE_UTMAXTYPE */

#define PF_ARGV_NONE		0
#define PF_ARGV_NEW		1
#define PF_ARGV_WRITEABLE	2
#define PF_ARGV_PSTAT		3
#define PF_ARGV_PSSTRINGS	4

/* If you don't have setproctitle, PF_ARGV_TYPE needs to be set to either
 * PF_ARGV_NEW (replace argv[] arguments), PF_ARGV_WRITEABLE (overwrite
 * argv[]), PF_ARGV_PSTAT (use the pstat function), or PF_ARGV_PSSTRINGS
 * (use PS_STRINGS).
 * 
 * configure should, we hope <wink>, detect this for you.
 */
#define PF_ARGV_TYPE PF_ARGV_WRITEABLE

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define to the type of elements in the array set by `getgroups'.
   Usually this is either `int' or `gid_t'.  */
#define GETGROUPS_T gid_t

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
#define HAVE_ALLOCA_H 1

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef mode_t */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define if the listen(2) system call accepts backlog value of -1. */
#define LISTEN_NEGATIVE_BACKLOG 1

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if the `setpgrp' function takes no argument.  This is the default
 * POSIX signature, so assume that the host system uses the POSIX
 * signature.  This avoids cross-compilation errors; the Autoconf macro
 * AC_FUNC_SETPGRP causes the configure script to fail when cross-compiling.
 * Thus we always assume the POSIX signature.  If this is incorrect,
 * the generated config.h file can be updated manually.
 */
#define SETPGRP_VOID 1

/* Define if the `setgrent` function returns void.  */
#define SETGRENT_VOID 1

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
 STACK_DIRECTION > 0 => grows toward higher addresses
 STACK_DIRECTION < 0 => grows toward lower addresses
 STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if your <sys/time.h> declares struct tm.  */
/* #undef TM_IN_SYS_TIME */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in an int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 8

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in an off_t.  */
#define SIZEOF_OFF_T 8

/* The number of bytes in a size_t.  */
#define SIZEOF_SIZE_T 8

/* The number of bytes in a time_t.  */
#define SIZEOF_TIME_T 8

/* The number of bytes in a pointer to a char.  */
#define SIZEOF_CHAR_P 8

/* The number of bytes in a pointer to a void.  */
#define SIZEOF_VOID_P 8

/* The number of bytes in a uid_t.  */
#define SIZEOF_UID_T 4

/* The number of bytes in a gid_t.  */
#define SIZEOF_GID_T 4

/* Define if you have the `u_int8_t` type defined.  */
#define HAVE_U_INT8_T 1

/* Define if you have the `u_int16_t` type defined.  */
#define HAVE_U_INT16_T 1

/* Define if you have the `u_int32_t` type defined.  */
#define HAVE_U_INT32_T 1

/* Define if you have the authenticate function.  */
/* #undef HAVE_AUTHENTICATE */

/* Define if you have the backtrace function.  */
#define HAVE_BACKTRACE 1

/* Define if you have the backtrace_symbols function.  */
#define HAVE_BACKTRACE_SYMBOLS 1

/* Define if you have the bcopy function.  */
#define HAVE_BCOPY 1

/* Define if you have the crypt function.  */
#define HAVE_CRYPT 1

/* Define if you have the ctime_r function.  */
#define HAVE_CTIME_R 1

/* Define if you have the dirfd function.  */
#define HAVE_DIRFD 1

/* Define if you have the explicit_bzero function.  */
#define HAVE_EXPLICIT_BZERO 1

/* Define if you have the endprotoent function.  */
#define HAVE_ENDPROTOENT 1

/* Define if you have the extattr_delete_link function.  */
/* #undef HAVE_EXTATTR_DELETE_LINK */

/* Define if you have the extattr_delete_link function.  */
/* #undef HAVE_EXTATTR_GET_LINK */

/* Define if you have the extattr_delete_link function.  */
/* #undef HAVE_EXTATTR_LIST_LINK */

/* Define if you have the extattr_delete_link function.  */
/* #undef HAVE_EXTATTR_SET_LINK */

/* Define if you have the fconvert function.  */
/* #undef HAVE_FCONVERT */

/* Define if you have the fcvt function.  */
/* #undef HAVE_FCVT */

/* Define if you have the fdatasync function.  */
#define HAVE_FDATASYNC 1

/* Define if you have the flock function.  */
#define HAVE_FLOCK 1

/* Define if you have the fpathconf function.  */
#define HAVE_FPATHCONF 1

/* Define if you have the fgetspent function.  */
#define HAVE_FGETSPENT 1

/* Define if you have the freeaddrinfo function.  */
#define HAVE_FREEADDRINFO 1

/* Define if you have the fsync function.  */
#define HAVE_FSYNC 1

/* Define if you have the futimes function.  */
#define HAVE_FUTIMES 1

/* Define if you have the gai_strerror function.  */
#define HAVE_GAI_STRERROR 1

/* Define if you have the getaddrinfo function.  */
#define HAVE_GETADDRINFO 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the getenv function.  */
#define HAVE_GETENV 1

/* Define if you have the getgrouplist function.  */
#define HAVE_GETGROUPLIST 1

/* Define if your getgrouplist(3) function takes ints. */
/* #undef HAVE_GETGROUPLIST_TAKES_INTS */

/* Define if you have the getgroups function.  */
#define HAVE_GETGROUPS 1

/* Define if you have the getgrset function.  */
/* #undef HAVE_GETGRSET */

/* Define if you have the gethostbyname2 function.  */
#define HAVE_GETHOSTBYNAME2 1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the getifaddrs function.  */
#define HAVE_GETIFADDRS 1

/* Define if you have the getnameinfo function.  */
#define HAVE_GETNAMEINFO 1

/* Define if you have the getopt function.  */
#define HAVE_GETOPT 1

/* Define if you have the getopt_long function.  */
#define HAVE_GETOPT_LONG 1

/* Define if you have the getpeereid function.  */
/* #undef HAVE_GETPEEREID */

/* Define if you have the getpeerucred function.  */
/* #undef HAVE_GETPEERUCRED */

/* Define if you have the getpgid function.  */
#define HAVE_GETPGID 1

/* Define if you have the getpgrp function.  */
#define HAVE_GETPGRP 1

/* Define if you have the getprpwent function.  */
/* #undef HAVE_GETPRPWENT */

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the gmtime_r function.  */
#define HAVE_GMTIME_R 1

/* Define if you have the Hiredis redisInitiateSSL function.  */
/* #undef HAVE_HIREDIS_REDISINITIATESSL */

/* Define if you have the Hiredis redisReconnect function.  */
/* #undef HAVE_HIREDIS_REDISRECONNECT */

/* Define if you have the hstrerror function.  */
#define HAVE_HSTRERROR 1

/* Define if you have the iconv function.  */
#define HAVE_ICONV 1

/* Define if you have the idn2_to_ascii_8z function.  */
/* #undef HAVE_IDN2_TO_ASCII_8Z */

/* Define if you have the idna_to_ascii_8z function.  */
/* #undef HAVE_IDNA_TO_ASCII_8Z */

/* Define if you have the inet_aton function.  */
#define HAVE_INET_ATON 1

/* Define if you have the inet_ntop function.  */
#define HAVE_INET_NTOP 1

/* Define if you have the inet_pton function.  */
#define HAVE_INET_PTON 1

/* Define if you have the initgroups function.  */
#define HAVE_INITGROUPS 1

/* Define if you have the lgetxattr function.  */
#define HAVE_LGETXATTR 1

/* Define if you have the llistxattr function.  */
/* #undef HAVE_LLISTXATTR */

/* Define if you have the localtime_r function.  */
#define HAVE_LOCALTIME_R 1

/* Define if you have the loginfailed function.  */
/* #undef HAVE_LOGINFAILED */

/* Define if you have the loginrestrictions function.  */
/* #undef HAVE_LOGINRESTRICTIONS */

/* Define if you have the loginsuccess function.  */
/* #undef HAVE_LOGINSUCCESS */

/* Define if you have the lremovexattr function.  */
#define HAVE_LREMOVEXATTR 1

/* Define if you have the lsetxattr function.  */
/* #undef HAVE_LSETXATTR */

/* Define if you have the memcpy function.  */
#define HAVE_MEMCPY 1

/* Define if you have the mempcpy function.  */
#define HAVE_MEMPCPY 1

/* Define if you have the memset_s function.  */
/* #undef HAVE_MEMSET_S */

/* Define if you have the mkdir function.  */
#define HAVE_MKDIR 1

/* Define if you have the mkdtemp function.  */
#define HAVE_MKDTEMP 1

/* Define if you have the mkstemp function.  */
#define HAVE_MKSTEMP 1

/* Define if you have the mlock function.  */
#define HAVE_MLOCK 1

/* Define if you have the mlockall function.  */
#define HAVE_MLOCKALL 1

/* Define if you have the munlock function.  */
#define HAVE_MUNLOCK 1

/* Define if you have the munlockall function.  */
#define HAVE_MUNLOCKALL 1

/* Define if you have the mysql_get_option function.  */
/* #undef HAVE_MYSQL_GET_OPTION */

/* Define if you have the MySQL make_scrambled_password function.  */
/* #undef HAVE_MYSQL_MAKE_SCRAMBLED_PASSWORD */

/* Define if you have the MySQL make_scrambled_password_323 function.  */
/* #undef HAVE_MYSQL_MAKE_SCRAMBLED_PASSWORD_323 */

/* Define if you have the MySQL my_make_scrambled_password function.  */
/* #undef HAVE_MYSQL_MY_MAKE_SCRAMBLED_PASSWORD */

/* Define if you have the MySQL my_make_scrambled_password_323 function.  */
/* #undef HAVE_MYSQL_MY_MAKE_SCRAMBLED_PASSWORD_323 */

/* Define if you have the MySQL mysql_get_ssl_cipher function.  */
/* #undef HAVE_MYSQL_MYSQL_GET_SSL_CIPHER */

/* Define if you have the MySQL mysql_ssl_set function.  */
/* #undef HAVE_MYSQL_MYSQL_SSL_SET */

/* Define if you have the nl_langinfo function.  */
#define HAVE_NL_LANGINFO 1

/* Define if you have the pathconf function.  */
#define HAVE_PATHCONF 1

/* Define if you have the PCRE pcre_free_study function.  */
/* #undef HAVE_PCRE_PCRE_FREE_STUDY */

/* Define if you have the PCRE2 pcre2_jit_compile function.  */
/* #undef HAVE_PCRE2_PCRE2_JIT_COMPILE */

/* Define if you have the PCRE2 pcre2_regcomp function.  */
/* #undef HAVE_PCRE2_PCRE2_REGCOMP */

/* Define if you have the perm_copy_fd function.  */
/* #undef HAVE_PERM_COPY_FD */

/* Define if you have the posix_fadvise function.  */
#define HAVE_POSIX_FADVISE 1

/* Define if you have the Postgres PQescapeStringConn function.  */
/* #undef HAVE_POSTGRES_PQESCAPESTRINGCONN */

/* Define if you have the Postgres PQgetssl function.  */
/* #undef HAVE_POSTGRES_PQGETSSL */

/* Define if you have the Postgres PQinitOpenSSL function.  */
/* #undef HAVE_POSTGRES_PQINITOPENSSL */

/* Define if you have the pread function.  */
#define HAVE_PREAD 1

/* Define if you have the prctl function.  */
#define HAVE_PRCTL 1

/* Define if you have the pstat function.  */
/* #undef HAVE_PSTAT */

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the pwrite function.  */
#define HAVE_PWRITE 1

/* Define if you have the random function.  */
#define HAVE_RANDOM 1

/* Define if you have the regcomp function.  */
#define HAVE_REGCOMP 1

/* Define if you have the rmdir function.  */
#define HAVE_RMDIR 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the set_auth_parameters function.  */
/* #undef HAVE_SET_AUTH_PARAMETERS */

/* Define if you have the setegid function.  */
#define HAVE_SETEGID 1

/* Define if you have the setenv function.  */
#define HAVE_SETENV 1

/* Define if you have the seteuid function.  */
#define HAVE_SETEUID 1

/* Define if you have the setgroupent function.  */
/* #undef HAVE_SETGROUPENT */

/* Define if you have the setgroups function.  */
#define HAVE_SETGROUPS 1

/* Define if you have the setpgid function.  */
#define HAVE_SETPGID 1

/* Define if you have the setproctitle function.  */
/* #undef HAVE_SETPROCTITLE */

/* Define if your system has the setprotoent function.  */
#define HAVE_SETPROTOENT 1

/* Define if you have the setsid function.  */
#define HAVE_SETSID 1

/* Define if you have the siginterrupt function.  */
#define HAVE_SIGINTERRUPT 1

/* Define if you have the snprintf function.  */
#define HAVE_SNPRINTF 1

/* Define if you have the socket function.  */
#define HAVE_SOCKET 1

/* Define if you have the srandom function.  */
#define HAVE_SRANDOM 1

/* Define if you have the statfs function.  */
#define HAVE_STATFS 1

/* Define if you have the struct statfs.f_fstypename member.  */
/* #undef HAVE_STATFS_F_FSTYPENAME */

/* Define if you have the struct statfs.f_type member.  */
#define HAVE_STATFS_F_TYPE 1

/* Define if you have the strchr function.  */
#define HAVE_STRCHR 1

/* Define if you have the strcoll function.  */
#define HAVE_STRCOLL 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the strlcat function.  */
/* #undef HAVE_STRLCAT */

/* Define if you have the strlcpy function.  */
/* #undef HAVE_STRLCPY */

/* Define if you have the strsep function.  */
#define HAVE_STRSEP 1

/* Define if you have the strtod function.  */
#define HAVE_STRTOD 1

/* Define if you have the strtof function.  */
#define HAVE_STRTOF 1

/* Define if you have the strtol function.  */
#define HAVE_STRTOL 1

/* Define if you have the strtoll function.  */
#define HAVE_STRTOLL 1

/* Define if you have the strtoull function.  */
#define HAVE_STRTOULL 1

/* Define if you have the timingsafe_bcmp function.  */
/* #undef HAVE_TIMINGSAFE_BCMP */

/* Define if you have the tzset function.  */
#define HAVE_TZSET 1

/* Define if you have the uname function.  */
#define HAVE_UNAME 1

/* Define if you have the unsetenv function.  */
#define HAVE_UNSETENV 1

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1

/* Define if you have the <acl/libacl.h> header file.  */
/* #undef HAVE_ACL_LIBACL_H */

/* Define if you have the <arpa/inet.h> header file.  */
#define HAVE_ARPA_INET_H 1

/* Define if you have the <attr/xattr.h> header file.  */
/* #undef HAVE_ATTR_XATTR_H */

/* Define if you have the <bstring.h> header file.  */
/* #undef HAVE_BSTRING_H */

/* Define if you have the <check.h> header file.  */
/* #undef HAVE_CHECK_H */

/* Define if you have the <crypt.h> header file.  */
#define HAVE_CRYPT_H 1

/* Define if you have the <ctype.h> header file.  */
#define HAVE_CTYPE_H 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <dlfcn.h> header file.  */
#define HAVE_DLFCN_H 1

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H 1

/* Define if you have the <execinfo.h> header file.  */
#define HAVE_EXECINFO_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <floatingpoint.h> header file.  */
/* #undef HAVE_FLOATINGPOINT_H */

/* Define if you have the <getopt.h> header file.  */
#define HAVE_GETOPT_H 1

/* Define if you have the <hpsecurity.h> header file.  */
/* #undef HAVE_HPSECURITY_H */

/* Define if you have the <krb.h> header file.  */
/* #undef HAVE_KRB_H */

/* Define if you have the <hiredis/hiredis.h> header file.  */
/* #undef HAVE_HIREDIS_HIREDIS_H */

/* Define if you have the <hiredis/hiredis_ssl.h> header file.  */
/* #undef HAVE_HIREDIS_HIREDIS_SSL_H */

/* Define if you have the <iconv.h> header file.  */
#define HAVE_ICONV_H 1

/* Define if you have the <idn2.h> header file.  */
/* #undef HAVE_IDN2_H */

/* Define if you have the <idna.h> header file.  */
/* #undef HAVE_IDNA_H */

/* Define if you have the <ifaddrs.h> header file.  */
#define HAVE_IFADDRS_H 1

/* Define if you have the <inttypes.h> header file.  */
#define HAVE_INTTYPES_H 1

/* Define if you have the <langinfo.h> header file.  */
#define HAVE_LANGINFO_H 1

/* Define if you have the <lastlog.h> header file.  */
/* #undef HAVE_LASTLOG_H */

/* Define if you have the <libintl.h> header file.  */
#define HAVE_LIBINTL_H 1

/* Define if you have the <libutil.h> header file.  */
/* #undef HAVE_LIBUTIL_H */

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <linux/capability.h> header file.  */
#define HAVE_LINUX_CAPABILITY_H 1

/* Define if you have the <linux/prctl.h> header file.  */
#define HAVE_LINUX_PRCTL_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <login.h> header file.  */
/* #undef HAVE_LOGIN_H */

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <ncurses.h> header file.  */
#define HAVE_NCURSES_H 1

/* Define if you have the <curses.h> header file.  */
#define HAVE_CURSES_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <netdb.h> header file.  */
#define HAVE_NETDB_H 1

/* Define if you have the <net/if.h> header file.  */
#define HAVE_NET_IF_H 1

/* Define if you have the <netinet/in.h> header file.  */
#define HAVE_NETINET_IN_H 1

/* Define if you have the <netinet/in_systm.h> header file.  */
#define HAVE_NETINET_IN_SYSTM_H 1

/* Define if you have the <netinet/ip.h> header file.  */
#define HAVE_NETINET_IP_H 1

/* Define if you have the <netinet/tcp.h> header file.  */
#define HAVE_NETINET_TCP_H 1

/* Define if you have the <paths.h> header file.  */
/* #undef HAVE_PATHS_H */

/* Define if you have the <prot.h> header file.  */
/* #undef HAVE_PROT_H */

/* Define if you have the <regex.h> header file.  */
#define HAVE_REGEX_H 1

/* Define if you have the <sasl/sasl.h> header file.  */
#define HAVE_SASL_SASL_H 1

/* Define if you have the <security/pam_appl.h> header file.  */
#define HAVE_SECURITY_PAM_APPL_H 1

/* Define if you have the <security/pam_modules.h> header file.  */
#define HAVE_SECURITY_PAM_MODULES_H 1

/* Define if you have the <pam/pam_appl.h> header file.  */
/* #undef HAVE_PAM_PAM_APPL_H */

/* Define if you have the <shadow.h> header file.  */
#define HAVE_SHADOW_H 1

/* Define if you have the <sia.h> header file.  */
/* #undef HAVE_SIA_H */

/* Define if you have the <siad.h> header file.  */
/* #undef HAVE_SIAD_H */

/* Define if you have the <signal.h> header file.  */
#define HAVE_SIGNAL_H 1

/* Define if you have the <sodium.h> header file.  */
/* #undef HAVE_SODIUM_H */

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <stropts.h> header file.  */
/* #undef HAVE_STROPTS_H */

/* Define if you have the <sys/acl.h> header file.  */
/* #undef HAVE_SYS_ACL_H */

/* Define if you have the <sys/audit.h> header file.  */
/* #undef HAVE_SYS_AUDIT_H */

/* Define if you have the <sys/capability.h> header file.  */
/* #undef HAVE_SYS_CAPABILITY_H */

/* Define if you have the <sys/dir.h> header file.  */
#define HAVE_SYS_DIR_H 1

/* Define if you have the <sys/extattr.h> header file.  */
/* #undef HAVE_SYS_EXTATTR_H */

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/mman.h> header file.  */
#define HAVE_SYS_MMAN_H 1

/* Define if you have the <sys/mount.h> header file.  */
#define HAVE_SYS_MOUNT_H 1

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/param.h> header file.  */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/prctl.h> header file.  */
#define HAVE_SYS_PRCTL_H 1

/* Define if you have the <sys/pstat.h> header file.  */
/* #undef HAVE_SYS_PSTAT_H */

/* Define if you have the <sys/resource.h> header file.  */
#define HAVE_SYS_RESOURCE_H 1

/* Define if you have the <sys/security.h> header file.  */
/* #undef HAVE_SYS_SECURITY_H */

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/sendfile.h> header file.  */
#define HAVE_SYS_SENDFILE_H 1

/* Define if you have the <sys/socket.h> header file.  */
#define HAVE_SYS_SOCKET_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/statvfs.h> header file.  */
#define HAVE_SYS_STATVFS_H 1

/* Define if you have the <sys/termio.h> header file.  */
/* #undef HAVE_SYS_TERMIO_H */

/* Define if you have the <sys/termios.h> header file.  */
#define HAVE_SYS_TERMIOS_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <sys/ucred.h> header file.  */
/* #undef HAVE_SYS_UCRED_H */

/* Define if you have the <sys/uio.h> header file.  */
#define HAVE_SYS_UIO_H 1

/* Define if you have the <sys/un.h> header file.  */
#define HAVE_SYS_UN_H 1

/* Define if you have the <sys/vfs.h> header file.  */
#define HAVE_SYS_VFS_H 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have the <sys/xattr.h> header file.  */
#define HAVE_SYS_XATTR_H 1

/* Define if you have the <termios.h> header file.  */
#define HAVE_TERMIOS_H 1

/* Define if you have the <ucontext.h> header file.  */
#define HAVE_UCONTEXT_H 1

/* Define if you have the <ucred.h> header file.  */
/* #undef HAVE_UCRED_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <usersec.h> header file.  */
/* #undef HAVE_USERSEC_H */

/* Define if you have the <utime.h> header file.  */
#define HAVE_UTIME_H 1

/* Define if you have the <utmp.h> header file.  */
#define HAVE_UTMP_H 1

/* Define if you have the <utmpx.h> header file.  */
#define HAVE_UTMPX_H 1

/* Define if you have the "vmsdir.h" header file.  */
/* #undef HAVE_VMSDIR_H */

/* Define if you have the acl library (-lacl).  */
/* #undef HAVE_LIBACL */

/* Define if you have the bind library (-lbind).  */
/* #undef HAVE_LIBBIND */

/* Define if you have the cap library (-lcap).  */
/* #undef HAVE_LIBCAP */

/* Define if you have the cap (v2) library (-lcap2).  */
/* #undef HAVE_LIBCAP2 */

/* Define if you have the crypt library (-lcrypt).  */
#define HAVE_LIBCRYPT 1

/* Define if you have the check library (-lcheck).  */
/* #undef HAVE_LIBCHECK */

/* Define if you have the curses library (-lcurses).  */
#define HAVE_LIBCURSES 1

/* Define if you have the UnixWare gen library (-lgen).  */
/* #undef HAVE_LIBGEN */

/* Define if you have the iconv library (-liconv).  */
/* #undef HAVE_LIBICONV */

/* Define if you have the intl library (-lintl).  */
/* #undef HAVE_LIBINTL */

/* Define if you have the ncurses library (-lncurses).  */
/* #undef HAVE_LIBNCURSES */

/* Define if you have the ncurses library (-lncursesw).  */
#define HAVE_LIBNCURSESW 1

/* Define if you have the nsl library (-lnsl).  */
/* #undef HAVE_LIBNSL */

/* Define if you have the resolv library (-lresolv).  */
/* #undef HAVE_LIBRESOLV */

/* Define if you have the sec library (-lsec).  */
/* #undef HAVE_LIBSEC */

/* Define if you have the security library (-lsecurity).  */
/* #undef HAVE_LIBSECURITY */

/* Define if you have the libtinfo library (-ltinfo).  */
#define HAVE_LIBTINFO 1

/* Define if you have the libtinfow library (-ltinfow).  */
/* #undef HAVE_LIBTINFOW */

/* Define if you have the addrinfo struct.  */
#define HAVE_STRUCT_ADDRINFO 1

/* Define if you have the sockaddr_storage struct.  */
#define HAVE_STRUCT_SS 1

/* Define if you have the ss_family sockaddr_storage struct member.  */
#define HAVE_SS_FAMILY 1

/* Define if you have the __ss_family sockaddr_storage struct member.  */
/* #undef HAVE___SS_FAMILY */

/* Define if you have the ss_len sockaddr_storage struct member.  */
/* #undef HAVE_SS_LEN */

/* Define if you have the __ss_len sockaddr_storage struct member.  */
/* #undef HAVE___SS_LEN */

/* Define if you have the sin_len sockaddr_in struct member. */
/* #undef SIN_LEN */

/* Define if you have the socket library (-lsocket).  */
/* #undef HAVE_LIBSOCKET */
#ifndef STDIN_FILENO
#define STDIN_FILENO 	0
#endif /* STDIN_FILENO */

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 	1
#endif /* STDOUT_FILENO */

#ifndef STDERR_FILENO
#define STDERR_FILENO	2
#endif /* STDERR_FILENO */

#ifndef PR_CONFIG_DIR
#define PR_CONFIG_DIR "/etc"
#endif /* PR_CONFIG_DIR */

#ifndef PR_INCLUDE_DIR
#define PR_INCLUDE_DIR "/usr/include"
#endif /* PR_INCLUDE_DIR */

#ifndef PR_LIBEXEC_DIR
#define PR_LIBEXEC_DIR "/usr/libexec"
#endif /* PR_LIBEXEC_DIR */

#ifndef PR_LOCALE_DIR
#define PR_LOCALE_DIR "/usr/share/locale"
#endif /* PR_LOCALE_DIR */

#ifndef PR_RUN_DIR
#define PR_RUN_DIR "/var"
#endif /* PR_RUN_DIR */

#ifndef PR_CONFIG_FILE_PATH
#define PR_CONFIG_FILE_PATH "/etc/proftpd.conf"
#endif /* PR_CONFIG_FILE_PATH */

#ifndef PR_PID_FILE_PATH
#define PR_PID_FILE_PATH "/var/proftpd.pid"
#endif /* PR_PID_FILE_PATH */

#ifndef PR_LASTLOG_PATH
/* #undef PR_LASTLOG_PATH */
#endif /* PR_LASTLOG_PATH */

/* Number of bits in a file offset, on hosts where this is settable. */
#ifndef _FILE_OFFSET_BITS
/* #undef _FILE_OFFSET_BITS */
#endif /* _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define for use of hstrerror on AIX-style hosts. */
/* #undef _USE_IRS */

/* Define if auto-detection of shadow passwords is wanted.  */
/* #undef PR_USE_AUTO_SHADOW */

/* Define if controls support is desired.  */
#define PR_USE_CTRLS 1

/* Define if curses support, if available, should be used.  */
#define PR_USE_CURSES 1

/* Define if you are a developer. */
/* #undef PR_USE_DEVEL */

/* Define if DSO support is desired.  */
#define PR_USE_DSO 1

/* Define if use of POSIX ACL support is desired.  */
/* #undef PR_USE_FACL */

/* Define if use of builtin getaddrinfo() is desired.  */
/* #undef PR_USE_GETADDRINFO */

/* Define if use of builtin getnameinfo() is desired.  */
/* #undef PR_USE_GETNAMEINFO */

/* Define if IPv6 support is desired.  */
#define PR_USE_IPV6 1

/* Define if largefile support is desired.  */
#define PR_USE_LARGEFILES 1

/* Define if Memcache support is desired.. */
#define PR_USE_MEMCACHE 1

/* Define if Redis support is desired.. */
/* #undef PR_USE_REDIS */

/* Define if the %llu format should be used.  */
#define HAVE_LLU 1

/* Define if the %lu format should be used.  */
/* #undef HAVE_LU */

/* Define if lastlog support is desired.  */
/* #undef PR_USE_LASTLOG */

/* Define if NLS support, if available, should be used. */
#define PR_USE_NLS 1

/* Define if ncurses support, if available, should be used.  */
/* #undef PR_USE_NCURSES */

/* Define if ncursesw support, if available, should be used.  */
#define PR_USE_NCURSESW 1

/* Define if non-local network tests are enabled. */
/* #undef PR_USE_NETWORK_TESTS */

/* Define if using nonblocking open of log files.  */
#define PR_USE_NONBLOCKING_LOG_OPEN 1

/* Define if OpenSSL support, if available, should be used.  */
#define PR_USE_OPENSSL 1

/* Define if OpenSSL Application Layer Protocol Negotiation (ALPN) support,
 * if available, should be used.
 */
#define PR_USE_OPENSSL_ALPN 1

/* Define if using OPENSSL_API_COMPAT.  */
#define PR_USE_OPENSSL_API_COMPAT 1

/* Define if using OpenSSL has BIO_s_secmem().  */
#define PR_USE_OPENSSL_BIO_SECMEM 1

/* Define if OpenSSL Elliptic Curve Cryptography (ECC) support, if available,
 * should be used.
 */
#define PR_USE_OPENSSL_ECC 1

/* Define if OpenSSL EVP_CipherInit_ex support, if available, should be used.
 */
#define PR_USE_OPENSSL_EVP_CIPHERINIT_EX 1

/* Define if OpenSSL engine support, if available, should be used.  */
#define PR_USE_OPENSSL_ENGINE 1

/* Define if OpenSSL support (with FIPS enabled), if available, should be
 * used.
 */
#define PR_USE_OPENSSL_FIPS 1

/* Define if OpenSSL Next Protocol Negotiation (NPN) support, if available,
 * should be used.
 */
#define PR_USE_OPENSSL_NPN 1

/* Define if OpenSSL OCSP support, if available, should be used.  */
#define PR_USE_OPENSSL_OCSP 1

/* Define if OpenSSL OSSL_PROVIDER_load support, if available, should be used.  */
#define PR_USE_OPENSSL_OSSL_PROVIDER_LOAD 1

/* Define if OpenSSL SSL num ticket support, if available, should be used.  */
#define PR_USE_OPENSSL_SSL_NUM_TICKETS 1

/* Define if OpenSSL SSL read ahead support, if available, should be used.  */
#define PR_USE_OPENSSL_SSL_READ_AHEAD 1

/* Define if OpenSSL SSL session ID context set support, if available, should
   be used.  */
#define PR_USE_OPENSSL_SSL_SESSION_SET1_ID_CONTEXT 1

/* Define if OpenSSL SSL session ticket callback support, if available,
 * should be used.  */
#define PR_USE_OPENSSL_SSL_SESSION_TICKET_CALLBACK 1

/* Define if using PCRE support.  */
/* #undef PR_USE_PCRE */

/* Define if using PCRE2 support.  */
/* #undef PR_USE_PCRE2 */

/* Define if sendfile support, if available, should be used.  */
#define PR_USE_SENDFILE 1

/* Define if using /etc/shadow files.  */
#define PR_USE_SHADOW 1

/* Define if using Tru64's C2 SIA authentication.  */
/* #undef PR_USE_SIA */

/* Define if Sodiumm support, if available, should be used.  */
/* #undef PR_USE_SODIUM */

/* Define if use of system getopt is desired.  */
#define PR_USE_SYSTEM_GETOPT 1

/* Define if using testsuite support.  */
/* #undef PR_USE_TESTS */

/* Define if using trace support.  */
#define PR_USE_TRACE 1

/* Define if using xattr support.  */
#define PR_USE_XATTR 1

/* Tunable parameters */
/* #undef PR_TUNABLE_BUFFER_SIZE */
/* #undef PR_TUNABLE_NEW_POOL_SIZE */
/* #undef PR_TUNABLE_SCOREBOARD_BUFFER_SIZE */
/* #undef PR_TUNABLE_TIMEOUTIDENT */
/* #undef PR_TUNABLE_TIMEOUTIDLE */
/* #undef PR_TUNABLE_TIMEOUTLINGER */
/* #undef PR_TUNABLE_TIMEOUTLOGIN */
/* #undef PR_TUNABLE_TIMEOUTNOXFER */
/* #undef PR_TUNABLE_TIMEOUTSTALLED */
/* #undef PR_TUNABLE_XFER_SCOREBOARD_UPDATES */

#endif /* config_h_included */
