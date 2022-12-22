// This file was automatically generated from InterpreterMessages.msg by msggen.pl.
#ifndef InterpreterMessages_INCLUDED
#define InterpreterMessages_INCLUDED 1

#ifdef __GNUG__
#pragma interface
#endif
#include <OpenSP/Message.h>

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

struct InterpreterMessages {
  // 0
  static const MessageType0 unexpectedEof;
  // 1
  static const MessageType0 invalidChar;
  // 2
  static const MessageType0 unknownHash;
  // 3
  static const MessageType1 unknownNamedConstant;
  // 4
  static const MessageType1 unexpectedToken;
  // 5
  static const MessageType0 unterminatedString;
  // 6
  static const MessageType0 missingCloseParen;
  // 7
  static const MessageType1 invalidNumber;
  // 8
  static const MessageType1 invalidAfiiGlyphId;
  // 9
  static const MessageType1 callNonFunction;
  // 10
  static const MessageType0 tooManyArgs;
  // 11
  static const MessageType0 oddKeyArgs;
  // 12
  static const MessageType0 missingArg;
  // 13
  static const MessageType1 syntacticKeywordAsVariable;
  // 14
  static const MessageType1 undefinedVariableReference;
  // 15
  static const MessageType1 badCharName;
  // 18
  static const MessageType1 unknownTopLevelForm;
  // 19
  static const MessageType1 badModeForm;
  // 20
  static const MessageType1L duplicateDefinition;
  // 22
  static const MessageType1 identifierLoop;
  // 23
  static const MessageType0 outOfRange;
  // 24
  static const MessageType1 unitLoop;
  // 25
  static const MessageType1 badUnitDefinition;
  // 26
  static const MessageType1L duplicateUnitDefinition;
  // 28
  static const MessageType1 undefinedQuantity;
  // 29
  static const MessageType0 incompatibleDimensions;
  // 30
  static const MessageType3 notABoolean;
  // 31
  static const MessageType3 notAPair;
  // 32
  static const MessageType3 notAList;
  // 33
  static const MessageType3 notASymbol;
  // 34
  static const MessageType3 notAString;
  // 35
  static const MessageType3 notAStringOrSymbol;
  // 36
  static const MessageType3 notAChar;
  // 37
  static const MessageType3 notAStyle;
  // 38
  static const MessageType3 notAnExactInteger;
  // 39
  static const MessageType3 notAQuantity;
  // 40
  static const MessageType3 notAColorSpace;
  // 41
  static const MessageType3 notANumber;
  // 42
  static const MessageType3 notASosofo;
  // 43
  static const MessageType3 notAnOptSingletonNode;
  // 44
  static const MessageType3 notASingletonNode;
  // 45
  static const MessageType3 notANodeList;
  // 46
  static const MessageType3 notANamedNodeList;
  // 47
  static const MessageType3 notALengthSpec;
  // 48
  static const MessageType3 notAQuantityOrLengthSpec;
  // 49
  static const MessageType3 notAPriority;
  // 51
  static const MessageType3 notAnAddress;
  // 52
  static const MessageType3 notAGlyphId;
  // 53
  static const MessageType3 notAGlyphSubstTable;
  // 54
  static const MessageType3 notAGlyphIdPairList;
  // 55
  static const MessageType3 notAProcedure;
  // 56
  static const MessageType3 notAVector;
  // 57
  static const MessageType0L duplicateRootRule;
  // 59
  static const MessageType1L duplicateInitialValue;
  // 61
  static const MessageType1 invalidStyleKeyword;
  // 62
  static const MessageType2 invalidMakeKeyword;
  // 63
  static const MessageType1 unknownFlowObjectClass;
  // 64
  static const MessageType1 atomicContent;
  // 65
  static const MessageType0 labelNotASymbol;
  // 66
  static const MessageType1 badConnection;
  // 67
  static const MessageType0 badContentMap;
  // 68
  static const MessageType1 contentMapBadPort;
  // 69
  static const MessageType1 invalidCharacteristicValue;
  // 70
  static const MessageType0 condFail;
  // 71
  static const MessageType1 caseFail;
  // 72
  static const MessageType1 caseElse;
  // 73
  static const MessageType0 caseUnresolvedQuantities;
  // 74
  static const MessageType1 errorProc;
  // 75
  static const MessageType0 divideBy0;
  // 76
  static const MessageType1 invalidKeyArg;
  // 77
  static const MessageType0 keyArgsNotKey;
  // 79
  static const MessageType0 specNotArc;
  // 80
  static const MessageType0 noStyleSpec;
  // 81
  static const MessageType1 unknownCharName;
  // 82
  static const MessageType0 noCurrentNode;
  // 83
  static const MessageType0 noCurrentProcessingMode;
  // 84
  static const MessageType0 invalidRadix;
  // 85
  static const MessageType0 sosofoContext;
  // 86
  static const MessageType0 styleContext;
  // 87
  static const MessageType0 notInCharacteristicValue;
  // 89
  static const MessageType1 colorArgCount;
  // 90
  static const MessageType1 colorArgType;
  // 91
  static const MessageType1 colorArgRange;
  // 92
  static const MessageType1 colorProcResType;
  // 93
  static const MessageType1 unknownColorSpaceFamily;
  // 94
  static const MessageType1 colorSpaceNoArgs;
  // 95
  static const MessageType1 colorSpaceArgError;
  // 96
  static const MessageType1 notABuiltinInheritedC;
  // 97
  static const MessageType1 invalidNumberFormat;
  // 98
  static const MessageType1 invalidPublicIdChar;
  // 99
  static const MessageType1 debug;
  // 100
  static const MessageType0 useLoop;
  // 101
  static const MessageType1 missingPart;
  // 102
  static const MessageType0 noParts;
  // 103
  static const MessageType0 tableCellOutsideTable;
  // 104
  static const MessageType0 tableRowOutsideTable;
  // 105
  static const MessageType1 noNodePropertyValue;
  // 106
  static const MessageType0 returnNotNodeList;
  // 107
  static const MessageType0 stackTrace;
  // 108
  static const MessageType1 stackTraceEllipsis;
  // 109
  static const MessageType0 processNodeLoop;
  // 110
  static const MessageType0 spliceNotList;
  // 111
  static const MessageType0 readOnly;
  // 112
  static const MessageType1 topLevelAssignment;
  // 113
  static const MessageType0 continuationDead;
  // 114
  static const MessageType0 patternEmptyGi;
  // 115
  static const MessageType0 patternNotList;
  // 116
  static const MessageType1 patternBadGi;
  // 117
  static const MessageType1 patternBadMember;
  // 118
  static const MessageType0 patternMissingQualifierValue;
  // 119
  static const MessageType1 patternUnknownQualifier;
  // 120
  static const MessageType2 patternBadQualifierValue;
  // 121
  static const MessageType0 patternChildRepeat;
  // 122
  static const MessageType0 patternBadAttributeQualifier;
  // 123
  static const MessageType1L ambiguousStyle;
  // 125
  static const MessageType0 ambiguousMatch;
  // 126
  static const MessageType1 uninitializedVariableReference;
  // 127
  static const MessageType1 actualLoop;
  // 128
  static const MessageType1L duplicateCharacteristic;
  // 130
  static const MessageType1L duplicateFlowObjectClass;
  // 132
  static const MessageType1 undefinedMode;
  // 133
  static const MessageType1 duplicateCharName;
  // 134
  static const MessageType1 duplicateSdataEntityName;
  // 135
  static const MessageType1 duplicateSdataEntityText;
  // 136
  static const MessageType0 unsupportedDeclaration;
  // 137
  static const MessageType1 unsupportedCharRepertoire;
  // 138
  static const MessageType0 badDeclaration;
  // 140
  static const MessageType1 invalidIdentifier;
  // 141
  static const MessageType0 badLanguageDefinition;
  // 142
  static const MessageType0 noCurrentLanguage;
  // 143
  static const MessageType3 notALanguage;
  // 144
  static const MessageType3 notAPositiveInteger;
  // 145
  static const MessageType3 notAnInteger;
  // 146
  static const MessageType3 notAKeyword;
  // 147
  static const MessageType3 notAnAlist;
  // 148
  static const MessageType3 notACharList;
  // 149
  static const MessageType3 lengthError;
  // 150
  static const MessageType1 noExactRepresentation;
  // 151
  static const MessageType0L duplicateDefLangDecl;
  // 153
  static const MessageType1 defLangDeclRequiresLanguage;
  // 154
  static const MessageType1 invalidUnitName;
  // 155
  static const MessageType1 invalidCharName;
  // 156
  static const MessageType1 invalidCharNumber;
  // 157
  static const MessageType1 unknownCharProperty;
  // 158
  static const MessageType0 badAddCharProperty;
  // 159
  static const MessageType1L duplicateCharPropertyDecl;
  // 161
  static const MessageType1L duplicateAddCharProperty;
  // 163
  static const MessageType0 returnNotSosofo;
  // 164
  static const MessageType1 charPropertyLoop;
  // 165
  static const MessageType2 charPropertyNotInteger;
  // 166
  static const MessageType2 charPropertyNotIntegerOrFalse;
  // 167
  static const MessageType1 unknownFeature;
  // 168
  static const MessageType1 missingFeature;
  // 169
  static const MessageType1 unsupportedFeature;
  // 170
  static const MessageType1 partiallySupportedFeature;
  // 171
  static const MessageType0 styleLanguage;
  // 172
  static const MessageType0 transformationLanguage;
  // 173
  static const MessageType0 mixedLanguages;
  // 174
  static const MessageType0 partialSpec;
  // 175
  static const MessageType1 cantOmitModule;
  // 176
  static const MessageType1 cantAddModule;
  // 177
  static const MessageType1 unknownModule;
  // 178
  static const MessageType2 notACharInCharMap;
  // 179
  static const MessageType2 charPropertyNotPublicId;
  // 180
  static const MessageType1 duplicateVariableBinding;
  // 181
  static const MessageType0 subgroveArgs;
  // 182
  static const MessageType0 subgroveSubgroveArgs;
  // 183
  static const MessageType0 subgroveClassArgs;
  // 184
  static const MessageType3 notASubgroveSpec;
  // 185
  static const MessageType1 notACspecList;
  // 186
  static const MessageType1 notACspecOrCspecList;
  // 187
  static const MessageType1 queryNotANodeList;
  // 188
  static const MessageType1 priorityNotAnExactInteger;
  // 189
  static const MessageType0 badTopLevelFlowObj;
  // 190
  static const MessageType0 noPrincipalPort;
  // 191
  static const MessageType0 noParagraphAncestor;
  // 192
  static const MessageType0 notInlineFlowObj;
  // 193
  static const MessageType0 notDisplayFlowObj;
  // 194
  static const MessageType0 notInlineOrDisplayFlowObj;
  // 195
  static const MessageType0 notValidInParagraph;
  // 196
  static const MessageType0 notSideBySideItem;
  // 197
  static const MessageType0 notMathSequence;
  // 198
  static const MessageType0 notGridCell;
  // 199
  static const MessageType0 notSingleChar;
  // 200
  static const MessageType0 badTableContent;
  // 201
  static const MessageType0 badTablePartHF;
  // 202
  static const MessageType0 badTablePartBody;
  // 203
  static const MessageType0 badTableRow;
  // 204
  static const MessageType0 priorityNotNumber;
  // 205
  static const MessageType0 queryNotNodelist;
  // 206
  static const MessageType0 sorryPriority;
};

#ifdef SP_NAMESPACE
}
#endif

#endif /* not InterpreterMessages_INCLUDED */
