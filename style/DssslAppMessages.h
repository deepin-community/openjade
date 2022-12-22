// This file was automatically generated from DssslAppMessages.msg by msggen.pl.
#include <OpenSP/Message.h>

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

struct DssslAppMessages {
  // 2000
  static const MessageType2 versionInfo;
  // 2001
  static const MessageType0 noSpec;
  // 2002
  static const MessageType2 noSpecTitle;
  // 2003
  static const MessageType1 prefixInfo;
  // 2004
  static const MessageType1 help2;
  // 2005
  static const MessageType1 GHelp;
  // 2006
  static const MessageType1 dHelp;
  // 2007
  static const MessageType1 THelp;
  // 2008
  static const MessageType1 VHelp;
  // 2009
  static const MessageType1 sHelp;
  // 2010
  static const MessageType1 eHelp;
  // 2011
  static const MessageType1 gHelp;
  // 2012
  static const MessageType1 nHelp;
  // 2013
  static const MessageType1 xHelp;
  // 2014
  static const MessageType1 iHelp;
  // 2015
  static const MessageType1 wHelp;
  // 2016
  static const MessageFragment sysid;
  // 2017
  static const MessageFragment vardef;
  // 2018
  static const MessageFragment name;
  // 2019
  static const MessageFragment type;
};
const MessageType2 DssslAppMessages::versionInfo(
MessageType::info,
MessageFragment::xModule,
2000
#ifndef SP_NO_MESSAGE_TEXT
,"%1 version %2"
#endif
);
const MessageType0 DssslAppMessages::noSpec(
MessageType::error,
MessageFragment::xModule,
2001
#ifndef SP_NO_MESSAGE_TEXT
,"no DSSSL specification: use -d to specify"
#endif
);
const MessageType2 DssslAppMessages::noSpecTitle(
MessageType::error,
MessageFragment::xModule,
2002
#ifndef SP_NO_MESSAGE_TEXT
,"no applicable processing instruction with title %1; available titles: %2"
#endif
);
const MessageType1 DssslAppMessages::prefixInfo(
MessageType::info,
MessageFragment::xModule,
2003
#ifndef SP_NO_MESSAGE_TEXT
,"Options with a \"doc-\"/\"spec-\" prefix apply only to the document/specification."
#endif
);
const MessageType1 DssslAppMessages::help2(
MessageType::info,
MessageFragment::xModule,
2004
#ifndef SP_NO_MESSAGE_TEXT
,"Enable experimental DSSSL extensions."
#endif
);
const MessageType1 DssslAppMessages::GHelp(
MessageType::info,
MessageFragment::xModule,
2005
#ifndef SP_NO_MESSAGE_TEXT
,"Debug mode."
#endif
);
const MessageType1 DssslAppMessages::dHelp(
MessageType::info,
MessageFragment::xModule,
2006
#ifndef SP_NO_MESSAGE_TEXT
,"Use DSSSL specification %1."
#endif
);
const MessageType1 DssslAppMessages::THelp(
MessageType::info,
MessageFragment::xModule,
2007
#ifndef SP_NO_MESSAGE_TEXT
,"Use DSSSL specification with title %1."
#endif
);
const MessageType1 DssslAppMessages::VHelp(
MessageType::info,
MessageFragment::xModule,
2008
#ifndef SP_NO_MESSAGE_TEXT
,"Pretend that %1 appeared in the specification."
#endif
);
const MessageType1 DssslAppMessages::sHelp(
MessageType::info,
MessageFragment::xModule,
2009
#ifndef SP_NO_MESSAGE_TEXT
,"Strict DSSSL compliance mode."
#endif
);
const MessageType1 DssslAppMessages::eHelp(
MessageType::info,
MessageFragment::xModule,
2010
#ifndef SP_NO_MESSAGE_TEXT
,"Show open entities in error messages."
#endif
);
const MessageType1 DssslAppMessages::gHelp(
MessageType::info,
MessageFragment::xModule,
2011
#ifndef SP_NO_MESSAGE_TEXT
,"Show open elements in error messages."
#endif
);
const MessageType1 DssslAppMessages::nHelp(
MessageType::info,
MessageFragment::xModule,
2012
#ifndef SP_NO_MESSAGE_TEXT
,"Show error numbers in error messages."
#endif
);
const MessageType1 DssslAppMessages::xHelp(
MessageType::info,
MessageFragment::xModule,
2013
#ifndef SP_NO_MESSAGE_TEXT
,"Show references in error messages."
#endif
);
const MessageType1 DssslAppMessages::iHelp(
MessageType::info,
MessageFragment::xModule,
2014
#ifndef SP_NO_MESSAGE_TEXT
,"Define parameter entity %1 as \"INCLUDE\"."
#endif
);
const MessageType1 DssslAppMessages::wHelp(
MessageType::info,
MessageFragment::xModule,
2015
#ifndef SP_NO_MESSAGE_TEXT
,"Enable warning %1."
#endif
);
const MessageFragment DssslAppMessages::sysid(
MessageFragment::xModule,
2016
#ifndef SP_NO_MESSAGE_TEXT
,"SYSID"
#endif
);
const MessageFragment DssslAppMessages::vardef(
MessageFragment::xModule,
2017
#ifndef SP_NO_MESSAGE_TEXT
,"DEFINITION"
#endif
);
const MessageFragment DssslAppMessages::name(
MessageFragment::xModule,
2018
#ifndef SP_NO_MESSAGE_TEXT
,"NAME"
#endif
);
const MessageFragment DssslAppMessages::type(
MessageFragment::xModule,
2019
#ifndef SP_NO_MESSAGE_TEXT
,"TYPE"
#endif
);
#ifdef SP_NAMESPACE
}
#endif
