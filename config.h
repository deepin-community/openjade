/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */
// Copyright (C) 1999 Matthias Clasen, Peter Nilsson
// See the file COPYING for copying permissions.


#include <OpenSP/config.h>


/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
#define HAVE_ALLOCA_H 1

/* Define if you have a working `mmap' system call.  */
#define HAVE_MMAP 1

/* Define if your struct stat has st_blksize.  */
#define HAVE_ST_BLKSIZE 1

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

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

/* these are needed for GNU gettext */
#define ENABLE_NLS 1
/* #undef HAVE_CATGETS */
#define HAVE_GETTEXT 1
#define HAVE_LC_MESSAGES 1
#define HAVE_STPCPY 1

 
/* define this appropriately if the type sig_atomic_t is not available */
/* #undef sig_atomic_t */

/* define this if the new handler takes size_t and returns int. */
/* #undef SP_FANCY_NEW_HANDLER */

/* The number of bytes in a bool.  */
#define SIZEOF_BOOL 1

/* The number of bytes in a size_t.  */
#define SIZEOF_SIZE_T 4

/* The number of bytes in a unsigned int.  */
#define SIZEOF_UNSIGNED_INT 4

/* The number of bytes in a unsigned short.  */
#define SIZEOF_UNSIGNED_SHORT 2

/* Define if you have the __argz_count function.  */
#define HAVE___ARGZ_COUNT 1

/* Define if you have the __argz_next function.  */
#define HAVE___ARGZ_NEXT 1

/* Define if you have the __argz_stringify function.  */
#define HAVE___ARGZ_STRINGIFY 1

/* Define if you have the dcgettext function.  */
#define HAVE_DCGETTEXT 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Define if you have the memcmp function.  */
#define HAVE_MEMCMP 1

/* Define if you have the munmap function.  */
#define HAVE_MUNMAP 1

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the setenv function.  */
#define HAVE_SETENV 1

/* Define if you have the setlocale function.  */
#define HAVE_SETLOCALE 1

/* Define if you have the stpcpy function.  */
#define HAVE_STPCPY 1

/* Define if you have the strcasecmp function.  */
#define HAVE_STRCASECMP 1

/* Define if you have the strchr function.  */
#define HAVE_STRCHR 1

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the <argz.h> header file.  */
#define HAVE_ARGZ_H 1

/* Define if you have the <cassert> header file.  */
#define HAVE_CASSERT 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <malloc.h> header file.  */
#define HAVE_MALLOC_H 1

/* Define if you have the <new> header file.  */
#define HAVE_NEW 1

/* Define if you have the <nl_types.h> header file.  */
#define HAVE_NL_TYPES_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <sys/param.h> header file.  */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the i library (-li).  */
/* #undef HAVE_LIBI */

/* Define if you have the pthread library (-lpthread).  */
#define HAVE_LIBPTHREAD 1

/* Package name */
#define OPENJADE_PACKAGE "OpenJade"

/* Package version */
#define OPENJADE_VERSION "1.4devel"

/* location of message catalogs */
#define OPENJADE_LOCALE_DIR "/free/opt/share/locale"

/* message domain */
#define OPENJADE_MESSAGE_DOMAIN "jade"

/* define if bool is a built-in type */
#define HAVE_BOOL 

/* define if the compiler supports the mutable keyword */
#define HAVE_MUTABLE 

/* define if the compiler recognizes typename */
#define HAVE_TYPENAME 

/* define if the compiler accepts the new for scoping rules */
#define HAVE_NEW_FOR_SCOPING 

/* define if the compiler supports placement operator delete */
/* #undef HAVE_PLACEMENT_OPERATOR_DELETE */

/* define if the compiler supports dynamic_cast<> */
#define HAVE_DYNAMIC_CAST 

/* define if the compiler implements namespaces */
#define HAVE_NAMESPACES 

/* define if the compiler supports explicit instantiations */
#define HAVE_INSTANTIATIONS 

/* define if placement operator new is declared */
#define HAVE_PLACEMENT_OPERATOR_NEW 1

/* define if the C++ compiler supports the std namespace */
#define HAVE_NAMESPACE_STD 1

/* define this to include template definitions in the headers */
#define SP_DEFINE_TEMPLATES 1

/* define this to compile explicit template instantiations */
/* #undef SP_MANUAL_INST */

/* define this if your system misses new.h */
/* #undef SP_NEW_H_MISSING */

/* define this if  set_new_handler() has to be declared extern C */
/* #undef SP_SET_NEW_HANDLER_EXTERN_C */

/* define this if the new handler takes size_t and returns int */
/* #undef SP_FANCY_NEW_HANDLER */

/* set this to the location of builtins.dsl */
#define DEFAULT_SCHEME_BUILTINS "/free/opt/share/OpenJade/builtins.dsl"

/* define this to build a multi-byte version */
#define SP_MULTI_BYTE 1

/* define this to build the grove in a separate thread, if possible */
/* #undef USE_THREADS */

/* define this to build the mif backend */
#define JADE_MIF 1

/* define this to build the mif backend */
#define JADE_MIF 1

/* define this to build the html backend */
#define JADE_HTML 1

/* define this to build the html backend */
#define JADE_HTML 1


#ifdef HAVE_BOOL 
#define SP_HAVE_BOOL
#endif /* HAVE_BOOL */

#if (SIZEOF_BOOL == 1)
#define SP_SIZEOF_BOOL_1
#endif

#if (SIZEOF_WCHAR_T == SIZEOF_UNSIGNED_SHORT)
#define SP_WCHAR_T_USHORT
#endif

#ifdef SP_HAVE_SETMODE
#ifndef SP_LINE_TERM1
#define SP_LINE_TERM1 '\r'
#define SP_LINE_TERM2 '\n'
#endif
#endif /* not SP_HAVE_SETMODE */

#ifndef SP_LINE_TERM1
#define SP_LINE_TERM1 '\n'
#endif

#ifndef HAVE_NEW_FOR_SCOPING
// This simulates the new ANSI "for" scope rules
#define for if (0); else for
#endif /* HAVE_NEW_FOR_SCOPING */

#ifndef SP_HAVE_TYPENAME
#define typename /* as nothing */
#endif

#ifndef SP_DLLEXPORT
#define SP_DLLEXPORT /* as nothing */
#endif

#ifndef SP_DLLIMPORT
#define SP_DLLIMPORT /* as nothing */
#endif

#ifdef SP_USE_DLL

#ifdef BUILD_LIBSP
#define SP_API SP_DLLEXPORT
#else
#define SP_API SP_DLLIMPORT
#endif

#else /* not SP_USE_DLL */

#define SP_API /* as nothing */

#endif /* not SP_USE_DLL */

#ifdef SP_WIDE_SYSTEM
#ifndef SP_MULTI_BYTE
#define SP_MULTI_BYTE
#endif
#endif

#ifdef HAVE_NAMESPACES
#define SP_NAMESPACE OpenSP
#define DSSSL_NAMESPACE OpenJade_DSSSL
#define GROVE_NAMESPACE OpenJade_Grove
#endif /* HAVE_NAMESPACES */

#ifdef SP_NAMESPACE
#define SP_NAMESPACE_SCOPE SP_NAMESPACE::
#else
#define SP_NAMESPACE_SCOPE
#endif /* SP_NAMESPACE */

#ifdef HAVE_DYNAMIC_CAST
#define SP_HAVE_RTTI
#endif /* HAVE_DYNAMIC_CAST */

#ifdef HAVE_TYPENAME
#define SP_HAVE_TYPENAME
#endif /* HAVE_TYPENAME */

#ifdef HAVE_PATHNAME_STYLE_DOS
#define SP_MSDOS_FILENAMES 
#else 
#define SP_POSIX_FILENAMES  
#endif /* HAVE_PATHNAME_STYLE_DOS */

#ifdef HAVE_INSTANTIATIONS
#define SP_ANSI_CLASS_INST
#endif /* HAVE_INSTANTIATIONS */ 

#ifdef HAVE_SETLOCALE
#define SP_HAVE_LOCALE
#endif /* HAVE_SETLOCALE */

#ifdef HAVE_GETTEXT
#define SP_HAVE_GETTEXT 
#endif /* HAVE_GETTEXT */

#ifdef WORDS_BIGENDIAN
#define SP_BIG_ENDIAN
#endif /* WORDS_BIGENDIAN */

#ifdef HAVE_LIBTHREADS
#define SP_MUTEX_MACH
#endif /* HAVE_LIBTHREADS */

#ifdef HAVE_LIBPTHREAD
#define SP_MUTEX_PTHREADS
#endif /* HAVE_LIBPTHREAD */

#ifdef HAVE_PLACEMENT_OPERATOR_DELETE
#define SP_HAVE_PLACEMENT_OPERATOR_DELETE
#endif /* HAVE_PLACEMENT_OPERATOR_DELETE */

#ifndef HAVE_PLACEMENT_OPERATOR_NEW
#define SP_DECLARE_PLACEMENT_OPERATOR_NEW
#endif /* HAVE_PLACEMENT_OPERATOR_NEW */

#ifndef HAVE_NAMESPACE_STD
#define SP_NO_STD_NAMESPACE
#endif /* HAVE_NAMESPACE_STD */
