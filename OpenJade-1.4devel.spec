# Copyright (C) 2000 Matthias Clasen
# See the file COPYING for copying permissions.

Summary: OpenJade group's DSSSL engine
Name: OpenJade
Version: 1.4devel
Release: 1
BuildRoot: /tmp/OpenJade-1.4devel-buildroot
Copyright: Copyright 1997 James Clark
Group: Applications/Text
Source: http://download.sourceforge.net/openjade/OpenJade-1.4devel.tar.gz
URL: http://openjade.sourceforge.net
Vendor: The OpenJade team <jade-devel@infomansol.com>
Packager: Matthias Clasen <clasen@mathematik.uni-freiburg.de>
Requires: OpenJade-lib

%description
OpenJade is an implementation of the DSSSL style language. 

The OpenJade engine is a useful tool (in conjunction with a DSSSL style sheet)
for translating SGML documents into other formats. OpenJade can currently
generate SGML, HTML, RTF, MIF and TeX. In conjunction with the "jadetex" TeX
style, it can generate quite nice output.  
     
%package lib
Summary: Runtime libraries for OpenJade group's DSSSL engine
Group: System Environment/Libraries
Requires: OpenSP-lib

%description lib 
This is the OpenJade shared library runtime support.  These C++
libraries contain the actual DSSSL engine, an abstract C++ interface to
groves and an implementation of this interface on top of OpenSP.

%package devel
Summary: Libraries and include files for developing DSSSL applications.
Group: Development/Libraries
Requires: OpenSP-devel

%description devel 
This contains include files and libraries for OpenJade.
These C++ libraries contain the actual DSSSL engine, an abstract C++ interface
to groves and an implementation of this interface on top of OpenSP.

%prep
# check that rpm is new enough to know internal macros like %{_prefix}
rpmversion=`rpm -q --queryformat '%{RPMVERSION}' rpm | cut -d. -f1`
[ ${rpmversion} -lt 3 ] && { echo "please update rpm" exit 1 ; }
# unpack source .tar.gz package
%setup

%build
# configure build system according to rpm settings
./configure --prefix=%{_prefix} --exec-prefix=%{_exec_prefix} --bindir=%{_bindir} --sbindir=%{_sbindir} --libexecdir=%{_libexecdir} --datadir=%{_datadir} --sysconfdir=%{_sysconfdir} --sharedstatedir=%{_sharedstatedir} --localstatedir=%{_localstatedir} --libdir=%{_libdir} --includedir=%{_includedir} --oldincludedir=%{_oldincludedir} --infodir=%{_infodir} --mandir=%{_mandir}
# compile and link
make CFLAGS="${RPM_OPT_FLAGS}"

%install
# install all files
make "DESTDIR=${RPM_BUILD_ROOT}" install

%clean
test "$RPM_BUILD_ROOT" = "/" || rm -rf "$RPM_BUILD_ROOT"

%files
%defattr(-, root, root)
%{_bindir}/*
%{_datadir}/OpenJade/*
%doc /usr/doc/OpenJade/*

%files lib
%defattr(-, root, root)
%{_libdir}/*.so.*

%files devel
%defattr(-, root, root)
%{_libdir}/lib*.{so,a,la}
%{_includedir}/OpenJade/*
