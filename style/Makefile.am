## Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libostyle.la

libostyle_la_LDFLAGS = -version-info 1:0:0

libostyle_la_SOURCES = Collector.cxx Collector.h DssslApp.cxx \
	DssslApp.h DssslAppMessages.h DssslSpecEventHandler.cxx \
	DssslSpecEventHandler.h ELObj.cxx ELObj.h ELObjMessageArg.cxx \
	ELObjMessageArg.h ELObjPropVal.h EvalContext.h Expression.cxx \
	Expression.h FOTBuilder.cxx FOTBuilder.h FlowObj.cxx \
	GroveManager.cxx GroveManager.h InheritedC.cxx Insn.cxx Insn.h \
	Insn2.h Interpreter.cxx Interpreter.h InterpreterMessages.cxx \
	InterpreterMessages.h LangObj.cxx LangObj.h MacroFlowObj.cxx \
	MacroFlowObj.h NumberCache.cxx NumberCache.h Pattern.cxx Pattern.h \
	ProcessContext.cxx ProcessContext.h ProcessingMode.cxx \
	ProcessingMode.h SchemeParser.cxx SchemeParser.h SosofoObj.h \
	Style.cxx Style.h StyleEngine.cxx StyleEngine.h VM.h charNames.h \
	charProps.h dsssl_ns.h primitive.cxx primitive.h \
	sdata.h style_inst.cxx style_pch.h stylelib.cxx \
	stylelib.h TransformationMode.h TransformationMode.cxx \
	DocumentGenerator.h DocumentGenerator.cxx MessageModule.cxx

# We install the headers needed to create a new application based on
# the DssslApp class.
pkginclude_HEADERS = FOTBuilder.h dsssl_ns.h DssslApp.h GroveManager.h

AM_CPPFLAGS = -I$(top_srcdir)/grove -I$(top_srcdir)/spgrove

EXTRA_DIST = FlowObj_inst.cxx primitive_inst.cxx \
	style_inst.m4 FlowObj_inst.m4 primitive_inst.m4 \
	InterpreterMessages.msg InterpreterMessages.rc \
	DssslAppMessages.msg DssslAppMessages.rc \
	style.dsp 

BUILT_SOURCES = style_inst.cxx FlowObj_inst.cxx primitive_inst.cxx \
	InterpreterMessages.h InterpreterMessages.cxx \
	InterpreterMessages.rc DssslAppMessages.h DssslAppMessages.rc 

MAINTAINERCLEANFILES = Makefile.in

MSGGENFLAGS = -l jstyleModule 

SUFFIXES = .m4 .msg .rc

.m4.cxx:
	$(PERL) $(top_srcdir)/instmac.pl $< >$@

%.h %.cxx %.rc: %.msg
	[ ! -f $(top_srcdir)/msggen.pl ] || $(PERL) -w $(top_srcdir)/msggen.pl $(MSGGENFLAGS) $<

