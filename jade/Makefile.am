## Process this file with automake to produce Makefile.in

bin_PROGRAMS = openjade

openjade_SOURCES = jade.cxx SgmlFOTBuilder.cxx RtfFOTBuilder.cxx \
	HtmlFOTBuilder.cxx TeXFOTBuilder.cxx TransformFOTBuilder.cxx \
	MifFOTBuilder.cxx SgmlFOTBuilder.h RtfFOTBuilder.h \
	HtmlFOTBuilder.h TeXFOTBuilder.h TransformFOTBuilder.h \
	MifFOTBuilder.h \
	JadeMessages.h HtmlMessages.h RtfMessages.h TeXMessages.h \
	MifMessages.h TmpOutputByteStream.h MessageModule.cxx

openjade_LDADD = $(top_builddir)/style/libostyle.la \
	$(top_builddir)/spgrove/libospgrove.la \
	$(top_builddir)/grove/libogrove.la -losp

AM_CPPFLAGS = -I$(top_srcdir)/grove -I$(top_srcdir)/spgrove -I$(top_srcdir)/style

EXTRA_DIST = JadeMessages.msg JadeMessages.rc \
	HtmlMessages.msg HtmlMessages.rc \
	RtfMessages.msg RtfMessages.rc \
	TeXMessages.msg TeXMessages.rc \
	MifMessages.msg MifMessages.rc \
	HtmlFOTBuilder_inst.cxx RtfFOTBuilder_inst.cxx \
	TeXFOTBuilder_inst.cxx TransformFOTBuilder_inst.cxx \
	MifFOTBuilder_inst.cxx \
	HtmlFOTBuilder_inst.m4 RtfFOTBuilder_inst.m4 \
	TeXFOTBuilder_inst.m4 TransformFOTBuilder_inst.m4 \
	MifFOTBuilder_inst.m4 jade.dsp jade.rc \
	RtfOle.cxx RtfOle.h

BUILT_SOURCES = JadeMessages.h JadeMessages.rc \
	HtmlMessages.h HtmlMessages.rc \
	RtfMessages.h RtfMessages.rc \
	TeXMessages.h TeXMessages.rc \
	MifMessages.h MifMessages.rc \
	HtmlFOTBuilder_inst.cxx RtfFOTBuilder_inst.cxx \
	TeXFOTBuilder_inst.cxx TransformFOTBuilder_inst.cxx \
	MifFOTBuilder_inst.cxx

MAINTAINERCLEANFILES = Makefile.in  jade-out.fot

MSGGENFLAGS = -l jadeModule

SUFFIXES = .msg .m4 .rc

.m4.cxx:
	$(PERL) $(top_srcdir)/instmac.pl $< >$@

%.h %.cxx %.rc: %.msg
	[ ! -f $(top_srcdir)/msggen.pl ] || $(PERL) -w $(top_srcdir)/msggen.pl $(MSGGENFLAGS) $<
