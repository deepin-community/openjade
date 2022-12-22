// This file was automatically generated from JadeMessages.msg by msggen.pl.
#include <OpenSP/Message.h>

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

struct JadeMessages {
  // 1000
  static const MessageType1 unknownType;
  // 1001
  static const MessageType0 emptyOutputFilename;
  // 1002
  static const MessageType2 cannotOpenOutputError;
  // 1003
  static const MessageType1 tHelp;
  // 1004
  static const MessageType1 oHelp;
  // 1005
  static const MessageFragment file;
  // 1006
  static const MessageFragment outputType;
};
const MessageType1 JadeMessages::unknownType(
MessageType::error,
MessageFragment::xModule,
1000
#ifndef SP_NO_MESSAGE_TEXT
,"unknown output type %1"
#endif
);
const MessageType0 JadeMessages::emptyOutputFilename(
MessageType::error,
MessageFragment::xModule,
1001
#ifndef SP_NO_MESSAGE_TEXT
,"empty output filename"
#endif
);
const MessageType2 JadeMessages::cannotOpenOutputError(
MessageType::error,
MessageFragment::xModule,
1002
#ifndef SP_NO_MESSAGE_TEXT
,"cannot open output file %1 (%2)"
#endif
);
const MessageType1 JadeMessages::tHelp(
MessageType::info,
MessageFragment::xModule,
1003
#ifndef SP_NO_MESSAGE_TEXT
,"Use the backend %1."
#endif
);
const MessageType1 JadeMessages::oHelp(
MessageType::info,
MessageFragment::xModule,
1004
#ifndef SP_NO_MESSAGE_TEXT
,"Send output to %1."
#endif
);
const MessageFragment JadeMessages::file(
MessageFragment::xModule,
1005
#ifndef SP_NO_MESSAGE_TEXT
,"FILE"
#endif
);
const MessageFragment JadeMessages::outputType(
MessageFragment::xModule,
1006
#ifndef SP_NO_MESSAGE_TEXT
,"TYPE"
#endif
);
#ifdef SP_NAMESPACE
}
#endif
