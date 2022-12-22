// This file was automatically generated from InterpreterMessages.msg by msggen.pl.

#ifdef __GNUG__
#pragma implementation
#endif

#include "stylelib.h"
#include "InterpreterMessages.h"

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

const MessageType0 InterpreterMessages::unexpectedEof(
MessageType::error,
MessageFragment::xModule,
0
#ifndef SP_NO_MESSAGE_TEXT
,"unexpected end of file"
#endif
);
const MessageType0 InterpreterMessages::invalidChar(
MessageType::error,
MessageFragment::xModule,
1
#ifndef SP_NO_MESSAGE_TEXT
,"invalid character"
#endif
);
const MessageType0 InterpreterMessages::unknownHash(
MessageType::error,
MessageFragment::xModule,
2
#ifndef SP_NO_MESSAGE_TEXT
,"invalid character after '#'"
,"ISO/IEC 10179:1996 8.5.1 8.5.6 8.5.7.4 8.5.8 12.5.5 [70] [76] [79] [80] [81] [82] [94] [187]"
#endif
);
const MessageType1 InterpreterMessages::unknownNamedConstant(
MessageType::error,
MessageFragment::xModule,
3
#ifndef SP_NO_MESSAGE_TEXT
,"unknown #! named constant %1"
,"ISO/IEC 10179:1996 8.5.6 [76]"
#endif
);
const MessageType1 InterpreterMessages::unexpectedToken(
MessageType::error,
MessageFragment::xModule,
4
#ifndef SP_NO_MESSAGE_TEXT
,"unexpected token %1"
#endif
);
const MessageType0 InterpreterMessages::unterminatedString(
MessageType::error,
MessageFragment::xModule,
5
#ifndef SP_NO_MESSAGE_TEXT
,"string with no closing quote"
,"ISO/IEC 10179:1996 8.5.9 [118]"
#endif
);
const MessageType0 InterpreterMessages::missingCloseParen(
MessageType::error,
MessageFragment::xModule,
6
#ifndef SP_NO_MESSAGE_TEXT
,"missing closing parenthesis"
#endif
);
const MessageType1 InterpreterMessages::invalidNumber(
MessageType::error,
MessageFragment::xModule,
7
#ifndef SP_NO_MESSAGE_TEXT
,"invalid number %1"
,"ISO/IEC 10179:1996 8.5.7.4"
#endif
);
const MessageType1 InterpreterMessages::invalidAfiiGlyphId(
MessageType::error,
MessageFragment::xModule,
8
#ifndef SP_NO_MESSAGE_TEXT
,"invalid AFII glyph identifier %1"
,"ISO/IEC 10179:1996 12.5.5"
#endif
);
const MessageType1 InterpreterMessages::callNonFunction(
MessageType::error,
MessageFragment::xModule,
9
#ifndef SP_NO_MESSAGE_TEXT
,"call of non-function object %1"
,"ISO/IEC 10179:1996 8.3.1.3"
#endif
);
const MessageType0 InterpreterMessages::tooManyArgs(
MessageType::error,
MessageFragment::xModule,
10
#ifndef SP_NO_MESSAGE_TEXT
,"too many arguments for function"
,"ISO/IEC 10179:1996 8.3.1.4"
#endif
);
const MessageType0 InterpreterMessages::oddKeyArgs(
MessageType::error,
MessageFragment::xModule,
11
#ifndef SP_NO_MESSAGE_TEXT
,"odd number of keyword/value arguments"
,"ISO/IEC 10179:1996 8.3.1.4"
#endif
);
const MessageType0 InterpreterMessages::missingArg(
MessageType::error,
MessageFragment::xModule,
12
#ifndef SP_NO_MESSAGE_TEXT
,"missing argument for function call"
,"ISO/IEC 10179:1996 8.3.1.4"
#endif
);
const MessageType1 InterpreterMessages::syntacticKeywordAsVariable(
MessageType::error,
MessageFragment::xModule,
13
#ifndef SP_NO_MESSAGE_TEXT
,"syntactic keyword %1 used as variable"
,"ISO/IEC 10179:1996 8.2.1p1"
#endif
);
const MessageType1 InterpreterMessages::undefinedVariableReference(
MessageType::error,
MessageFragment::xModule,
14
#ifndef SP_NO_MESSAGE_TEXT
,"reference to undefined variable %1"
,"ISO/IEC 10179:1996 8.3.1.1"
#endif
);
const MessageType1 InterpreterMessages::badCharName(
MessageType::error,
MessageFragment::xModule,
15
#ifndef SP_NO_MESSAGE_TEXT
,"no character with name %1"
,"ISO/IEC 10179:1996 8.5.8"
#endif
);
const MessageType1 InterpreterMessages::unknownTopLevelForm(
MessageType::error,
MessageFragment::xModule,
18
#ifndef SP_NO_MESSAGE_TEXT
,"unknown top level form %1"
,"ISO/IEC 10179:1996 12 [159]"
#endif
);
const MessageType1 InterpreterMessages::badModeForm(
MessageType::error,
MessageFragment::xModule,
19
#ifndef SP_NO_MESSAGE_TEXT
,"bad form %1 in mode group"
,"ISO/IEC 10179:1996 12.4.1 [162]"
#endif
);
const MessageType1L InterpreterMessages::duplicateDefinition(
MessageType::error,
MessageFragment::xModule,
20
#ifndef SP_NO_MESSAGE_TEXT
,"identifier %1 already defined in same part"
,"ISO/IEC 10179:1996 8.4"
,"first definition was here"
#endif
);
const MessageType1 InterpreterMessages::identifierLoop(
MessageType::error,
MessageFragment::xModule,
22
#ifndef SP_NO_MESSAGE_TEXT
,"loop in specification of value of %1"
,"ISO/IEC 10179:1996 8.4"
#endif
);
const MessageType0 InterpreterMessages::outOfRange(
MessageType::error,
MessageFragment::xModule,
23
#ifndef SP_NO_MESSAGE_TEXT
,"argument out of range"
,"ISO/IEC 10179:1996 8.5.3.12 8.5.3.13 8.5.7.17 8.5.7.19 8.5.7.20 8.5.9.4 8.5.9.7"
#endif
);
const MessageType1 InterpreterMessages::unitLoop(
MessageType::error,
MessageFragment::xModule,
24
#ifndef SP_NO_MESSAGE_TEXT
,"loop in specification of value of unit %1"
,"ISO/IEC 10179:1996 8.4"
#endif
);
const MessageType1 InterpreterMessages::badUnitDefinition(
MessageType::error,
MessageFragment::xModule,
25
#ifndef SP_NO_MESSAGE_TEXT
,"bad value specified for unit %1"
,"ISO/IEC 10179:1996 8.5.7.1"
#endif
);
const MessageType1L InterpreterMessages::duplicateUnitDefinition(
MessageType::error,
MessageFragment::xModule,
26
#ifndef SP_NO_MESSAGE_TEXT
,"unit %1 already defined in same part"
,"ISO/IEC 10179:1996 8.4"
,"first definition was here"
#endif
);
const MessageType1 InterpreterMessages::undefinedQuantity(
MessageType::error,
MessageFragment::xModule,
28
#ifndef SP_NO_MESSAGE_TEXT
,"quantity %1 undefined"
#endif
);
const MessageType0 InterpreterMessages::incompatibleDimensions(
MessageType::error,
MessageFragment::xModule,
29
#ifndef SP_NO_MESSAGE_TEXT
,"incompatible dimensions"
,"ISO/IEC 10179:1996 8.5.7.7 8.5.7.9 8.5.7.10 8.5.7.12 8.5.7.19"
#endif
);
const MessageType3 InterpreterMessages::notABoolean(
MessageType::error,
MessageFragment::xModule,
30
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a boolean"
#endif
);
const MessageType3 InterpreterMessages::notAPair(
MessageType::error,
MessageFragment::xModule,
31
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a pair"
#endif
);
const MessageType3 InterpreterMessages::notAList(
MessageType::error,
MessageFragment::xModule,
32
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a list"
#endif
);
const MessageType3 InterpreterMessages::notASymbol(
MessageType::error,
MessageFragment::xModule,
33
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a symbol"
#endif
);
const MessageType3 InterpreterMessages::notAString(
MessageType::error,
MessageFragment::xModule,
34
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a string"
#endif
);
const MessageType3 InterpreterMessages::notAStringOrSymbol(
MessageType::error,
MessageFragment::xModule,
35
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a string or symbol"
#endif
);
const MessageType3 InterpreterMessages::notAChar(
MessageType::error,
MessageFragment::xModule,
36
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a char"
#endif
);
const MessageType3 InterpreterMessages::notAStyle(
MessageType::error,
MessageFragment::xModule,
37
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a style"
#endif
);
const MessageType3 InterpreterMessages::notAnExactInteger(
MessageType::error,
MessageFragment::xModule,
38
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an exact integer"
#endif
);
const MessageType3 InterpreterMessages::notAQuantity(
MessageType::error,
MessageFragment::xModule,
39
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a quantity"
#endif
);
const MessageType3 InterpreterMessages::notAColorSpace(
MessageType::error,
MessageFragment::xModule,
40
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a color-space"
#endif
);
const MessageType3 InterpreterMessages::notANumber(
MessageType::error,
MessageFragment::xModule,
41
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a number"
#endif
);
const MessageType3 InterpreterMessages::notASosofo(
MessageType::error,
MessageFragment::xModule,
42
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a sosofo"
#endif
);
const MessageType3 InterpreterMessages::notAnOptSingletonNode(
MessageType::error,
MessageFragment::xModule,
43
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an optional singleton node list"
#endif
);
const MessageType3 InterpreterMessages::notASingletonNode(
MessageType::error,
MessageFragment::xModule,
44
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a singleton node list"
#endif
);
const MessageType3 InterpreterMessages::notANodeList(
MessageType::error,
MessageFragment::xModule,
45
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a node list"
#endif
);
const MessageType3 InterpreterMessages::notANamedNodeList(
MessageType::error,
MessageFragment::xModule,
46
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a named node list"
#endif
);
const MessageType3 InterpreterMessages::notALengthSpec(
MessageType::error,
MessageFragment::xModule,
47
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a length or length-spec"
#endif
);
const MessageType3 InterpreterMessages::notAQuantityOrLengthSpec(
MessageType::error,
MessageFragment::xModule,
48
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a quantity or length-spec"
#endif
);
const MessageType3 InterpreterMessages::notAPriority(
MessageType::error,
MessageFragment::xModule,
49
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an integer or the symbol \"force\""
,"ISO/IEC 10179:1996 12.5.4.1"
#endif
);
const MessageType3 InterpreterMessages::notAnAddress(
MessageType::error,
MessageFragment::xModule,
51
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an address"
,"ISO/IEC 10179:1996 12.5.8"
#endif
);
const MessageType3 InterpreterMessages::notAGlyphId(
MessageType::error,
MessageFragment::xModule,
52
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a glyph-id"
,"ISO/IEC 10179:1996 12.5.5"
#endif
);
const MessageType3 InterpreterMessages::notAGlyphSubstTable(
MessageType::error,
MessageFragment::xModule,
53
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a glyph-subst-table"
,"ISO/IEC 10179:1996 12.5.6"
#endif
);
const MessageType3 InterpreterMessages::notAGlyphIdPairList(
MessageType::error,
MessageFragment::xModule,
54
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a list of pairs of glyph-ids"
,"ISO/IEC 10179:1996 12.5.6"
#endif
);
const MessageType3 InterpreterMessages::notAProcedure(
MessageType::error,
MessageFragment::xModule,
55
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a procedure"
#endif
);
const MessageType3 InterpreterMessages::notAVector(
MessageType::error,
MessageFragment::xModule,
56
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a vector"
#endif
);
const MessageType0L InterpreterMessages::duplicateRootRule(
MessageType::error,
MessageFragment::xModule,
57
#ifndef SP_NO_MESSAGE_TEXT
,"root rule already defined in same part with same importance"
,"ISO/IEC 10179:1996 12.4.1"
,"first definition was here"
#endif
);
const MessageType1L InterpreterMessages::duplicateInitialValue(
MessageType::error,
MessageFragment::xModule,
59
#ifndef SP_NO_MESSAGE_TEXT
,"initial value already declared for characteristic %1 in same part"
,"ISO/IEC 10179:1996 12.4.6"
,"first declaration was here"
#endif
);
const MessageType1 InterpreterMessages::invalidStyleKeyword(
MessageType::error,
MessageFragment::xModule,
61
#ifndef SP_NO_MESSAGE_TEXT
,"%1 is not a valid keyword in a style expression"
,"ISO/IEC 10179:1996 12.4.5"
#endif
);
const MessageType2 InterpreterMessages::invalidMakeKeyword(
MessageType::error,
MessageFragment::xModule,
62
#ifndef SP_NO_MESSAGE_TEXT
,"%1 is not a valid keyword in a make expression for flow object class %2"
,"ISO/IEC 10179:1996 12.4.3"
#endif
);
const MessageType1 InterpreterMessages::unknownFlowObjectClass(
MessageType::error,
MessageFragment::xModule,
63
#ifndef SP_NO_MESSAGE_TEXT
,"%1 is not the name of any flow object class"
#endif
);
const MessageType1 InterpreterMessages::atomicContent(
MessageType::error,
MessageFragment::xModule,
64
#ifndef SP_NO_MESSAGE_TEXT
,"content expression cannot be specified in make expression for atomic flow object class %1"
,"ISO/IEC 10179:1996 12.4.3"
#endif
);
const MessageType0 InterpreterMessages::labelNotASymbol(
MessageType::error,
MessageFragment::xModule,
65
#ifndef SP_NO_MESSAGE_TEXT
,"value for \"label:\" not a symbol"
,"ISO/IEC 10179:1996 12.4.3"
#endif
);
const MessageType1 InterpreterMessages::badConnection(
MessageType::error,
MessageFragment::xModule,
66
#ifndef SP_NO_MESSAGE_TEXT
,"no port for label %1"
#endif
);
const MessageType0 InterpreterMessages::badContentMap(
MessageType::error,
MessageFragment::xModule,
67
#ifndef SP_NO_MESSAGE_TEXT
,"invalid content map"
,"ISO/IEC 10179:1996 12.4.3"
#endif
);
const MessageType1 InterpreterMessages::contentMapBadPort(
MessageType::error,
MessageFragment::xModule,
68
#ifndef SP_NO_MESSAGE_TEXT
,"content map references non-existent port %1"
,"ISO/IEC 10179:1996 12.4.3"
#endif
);
const MessageType1 InterpreterMessages::invalidCharacteristicValue(
MessageType::error,
MessageFragment::xModule,
69
#ifndef SP_NO_MESSAGE_TEXT
,"invalid value for %1 characteristic"
#endif
);
const MessageType0 InterpreterMessages::condFail(
MessageType::error,
MessageFragment::xModule,
70
#ifndef SP_NO_MESSAGE_TEXT
,"no clause in cond expression matched"
,"ISO/IEC 10179:1996 8.3.2.1"
#endif
);
const MessageType1 InterpreterMessages::caseFail(
MessageType::error,
MessageFragment::xModule,
71
#ifndef SP_NO_MESSAGE_TEXT
,"no clause in case expression matched %1"
,"ISO/IEC 10179:1996 8.3.2.2"
#endif
);
const MessageType1 InterpreterMessages::caseElse(
MessageType::error,
MessageFragment::xModule,
72
#ifndef SP_NO_MESSAGE_TEXT
,"expected \"else\" not %1"
,"ISO/IEC 10179:1996 8.3.2.2 [45]"
#endif
);
const MessageType0 InterpreterMessages::caseUnresolvedQuantities(
MessageType::error,
MessageFragment::xModule,
73
#ifndef SP_NO_MESSAGE_TEXT
,"sorry, cannot handle unresolvable quantities in datums in case expression"
#endif
);
const MessageType1 InterpreterMessages::errorProc(
MessageType::error,
MessageFragment::xModule,
74
#ifndef SP_NO_MESSAGE_TEXT
,"%1"
,"ISO/IEC 10179:1996 8.5.12"
#endif
);
const MessageType0 InterpreterMessages::divideBy0(
MessageType::error,
MessageFragment::xModule,
75
#ifndef SP_NO_MESSAGE_TEXT
,"division by zero"
,"ISO/IEC 10179:1996 8.5.7.13"
#endif
);
const MessageType1 InterpreterMessages::invalidKeyArg(
MessageType::error,
MessageFragment::xModule,
76
#ifndef SP_NO_MESSAGE_TEXT
,"procedure does not have %1 keyword argument"
,"ISO/IEC 10179:1996 8.3.1.4"
#endif
);
const MessageType0 InterpreterMessages::keyArgsNotKey(
MessageType::error,
MessageFragment::xModule,
77
#ifndef SP_NO_MESSAGE_TEXT
,"argument not a keyword"
,"ISO/IEC 10179:1996 8.3.1.4"
#endif
);
const MessageType0 InterpreterMessages::specNotArc(
MessageType::error,
MessageFragment::xModule,
79
#ifndef SP_NO_MESSAGE_TEXT
,"specification document does not have the DSSSL architecture as a base architecture"
,"ISO/IEC 10179:1996 7p1"
#endif
);
const MessageType0 InterpreterMessages::noStyleSpec(
MessageType::error,
MessageFragment::xModule,
80
#ifndef SP_NO_MESSAGE_TEXT
,"specification document did not contain a style-specification-body element"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType1 InterpreterMessages::unknownCharName(
MessageType::error,
MessageFragment::xModule,
81
#ifndef SP_NO_MESSAGE_TEXT
,"unknown character name %1"
,"ISO/IEC 10179:1996 8.5.8"
#endif
);
const MessageType0 InterpreterMessages::noCurrentNode(
MessageType::error,
MessageFragment::xModule,
82
#ifndef SP_NO_MESSAGE_TEXT
,"attempt to use current node when there is none"
,"ISO/IEC 10179:1996 10.1.1 12.4.1"
#endif
);
const MessageType0 InterpreterMessages::noCurrentProcessingMode(
MessageType::error,
MessageFragment::xModule,
83
#ifndef SP_NO_MESSAGE_TEXT
,"attempt to process node in illegal context"
,"ISO/IEC 10179:1996 12.4.1"
#endif
);
const MessageType0 InterpreterMessages::invalidRadix(
MessageType::error,
MessageFragment::xModule,
84
#ifndef SP_NO_MESSAGE_TEXT
,"radix must be 2, 8, 10 or 16"
#endif
);
const MessageType0 InterpreterMessages::sosofoContext(
MessageType::error,
MessageFragment::xModule,
85
#ifndef SP_NO_MESSAGE_TEXT
,"this context requires a sosofo"
#endif
);
const MessageType0 InterpreterMessages::styleContext(
MessageType::error,
MessageFragment::xModule,
86
#ifndef SP_NO_MESSAGE_TEXT
,"this context requires a style object"
#endif
);
const MessageType0 InterpreterMessages::notInCharacteristicValue(
MessageType::error,
MessageFragment::xModule,
87
#ifndef SP_NO_MESSAGE_TEXT
,"procedure can only be used in evaluation of characteristic value"
,"ISO/IEC 10179:1996 12.4.6"
#endif
);
const MessageType1 InterpreterMessages::colorArgCount(
MessageType::error,
MessageFragment::xModule,
89
#ifndef SP_NO_MESSAGE_TEXT
,"%1 color requires three arguments"
#endif
);
const MessageType1 InterpreterMessages::colorArgType(
MessageType::error,
MessageFragment::xModule,
90
#ifndef SP_NO_MESSAGE_TEXT
,"arguments for %1 color must be numbers"
#endif
);
const MessageType1 InterpreterMessages::colorArgRange(
MessageType::error,
MessageFragment::xModule,
91
#ifndef SP_NO_MESSAGE_TEXT
,"arguments for %1 color must be in the range 0 to 1"
#endif
);
const MessageType1 InterpreterMessages::colorProcResType(
MessageType::error,
MessageFragment::xModule,
92
#ifndef SP_NO_MESSAGE_TEXT
,"result of procedure in %1 color must be a number"
#endif
);
const MessageType1 InterpreterMessages::unknownColorSpaceFamily(
MessageType::error,
MessageFragment::xModule,
93
#ifndef SP_NO_MESSAGE_TEXT
,"unknown color-space family %1"
,"ISO/IEC 10179:1996 12.5.9"
#endif
);
const MessageType1 InterpreterMessages::colorSpaceNoArgs(
MessageType::error,
MessageFragment::xModule,
94
#ifndef SP_NO_MESSAGE_TEXT
,"%1 color-space family does not take any arguments"
#endif
);
const MessageType1 InterpreterMessages::colorSpaceArgError(
MessageType::error,
MessageFragment::xModule,
95
#ifndef SP_NO_MESSAGE_TEXT
,"invalid parameters for %1 color-space family"
#endif
);
const MessageType1 InterpreterMessages::notABuiltinInheritedC(
MessageType::error,
MessageFragment::xModule,
96
#ifndef SP_NO_MESSAGE_TEXT
,"%1 is not a pre-defined inherited characteristic"
#endif
);
const MessageType1 InterpreterMessages::invalidNumberFormat(
MessageType::error,
MessageFragment::xModule,
97
#ifndef SP_NO_MESSAGE_TEXT
,"invalid number format %1"
,"ISO/IEC 10179:1996 8.5.7.24"
#endif
);
const MessageType1 InterpreterMessages::invalidPublicIdChar(
MessageType::error,
MessageFragment::xModule,
98
#ifndef SP_NO_MESSAGE_TEXT
,"invalid character %1 in public identifier"
#endif
);
const MessageType1 InterpreterMessages::debug(
MessageType::info,
MessageFragment::xModule,
99
#ifndef SP_NO_MESSAGE_TEXT
,"debug %1"
#endif
);
const MessageType0 InterpreterMessages::useLoop(
MessageType::error,
MessageFragment::xModule,
100
#ifndef SP_NO_MESSAGE_TEXT
,"circular use of specification parts"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType1 InterpreterMessages::missingPart(
MessageType::error,
MessageFragment::xModule,
101
#ifndef SP_NO_MESSAGE_TEXT
,"no style-specification or external-specification with ID %1"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType0 InterpreterMessages::noParts(
MessageType::error,
MessageFragment::xModule,
102
#ifndef SP_NO_MESSAGE_TEXT
,"document did not contain any style-specifications or external-specifications"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType0 InterpreterMessages::tableCellOutsideTable(
MessageType::error,
MessageFragment::xModule,
103
#ifndef SP_NO_MESSAGE_TEXT
,"table-cell flow object not inside a table"
#endif
);
const MessageType0 InterpreterMessages::tableRowOutsideTable(
MessageType::error,
MessageFragment::xModule,
104
#ifndef SP_NO_MESSAGE_TEXT
,"table-row flow object not inside a table"
#endif
);
const MessageType1 InterpreterMessages::noNodePropertyValue(
MessageType::error,
MessageFragment::xModule,
105
#ifndef SP_NO_MESSAGE_TEXT
,"no value for node property %1"
,"ISO/IEC 10179:1996 10.1.6"
#endif
);
const MessageType0 InterpreterMessages::returnNotNodeList(
MessageType::error,
MessageFragment::xModule,
106
#ifndef SP_NO_MESSAGE_TEXT
,"value returned by procedure was not a node-list"
#endif
);
const MessageType0 InterpreterMessages::stackTrace(
MessageType::info,
MessageFragment::xModule,
107
#ifndef SP_NO_MESSAGE_TEXT
,"called from here"
#endif
);
const MessageType1 InterpreterMessages::stackTraceEllipsis(
MessageType::info,
MessageFragment::xModule,
108
#ifndef SP_NO_MESSAGE_TEXT
,"called from here...(%1 calls omitted)"
#endif
);
const MessageType0 InterpreterMessages::processNodeLoop(
MessageType::error,
MessageFragment::xModule,
109
#ifndef SP_NO_MESSAGE_TEXT
,"node processing loop detected"
#endif
);
const MessageType0 InterpreterMessages::spliceNotList(
MessageType::error,
MessageFragment::xModule,
110
#ifndef SP_NO_MESSAGE_TEXT
,"unquote-splicing expression does not evaluate to a list"
,"ISO/IEC 10179:1996 8.3.2.7"
#endif
);
const MessageType0 InterpreterMessages::readOnly(
MessageType::error,
MessageFragment::xModule,
111
#ifndef SP_NO_MESSAGE_TEXT
,"object is read-only"
#endif
);
const MessageType1 InterpreterMessages::topLevelAssignment(
MessageType::error,
MessageFragment::xModule,
112
#ifndef SP_NO_MESSAGE_TEXT
,"assignment to top-level variable %1"
#endif
);
const MessageType0 InterpreterMessages::continuationDead(
MessageType::error,
MessageFragment::xModule,
113
#ifndef SP_NO_MESSAGE_TEXT
,"invalid call to continuation"
#endif
);
const MessageType0 InterpreterMessages::patternEmptyGi(
MessageType::error,
MessageFragment::xModule,
114
#ifndef SP_NO_MESSAGE_TEXT
,"empty generic identifier in pattern"
#endif
);
const MessageType0 InterpreterMessages::patternNotList(
MessageType::error,
MessageFragment::xModule,
115
#ifndef SP_NO_MESSAGE_TEXT
,"pattern is not a list"
#endif
);
const MessageType1 InterpreterMessages::patternBadGi(
MessageType::error,
MessageFragment::xModule,
116
#ifndef SP_NO_MESSAGE_TEXT
,"%1 cannot be used as a generic identifier in a pattern"
#endif
);
const MessageType1 InterpreterMessages::patternBadMember(
MessageType::error,
MessageFragment::xModule,
117
#ifndef SP_NO_MESSAGE_TEXT
,"%1 cannot occur in a pattern"
#endif
);
const MessageType0 InterpreterMessages::patternMissingQualifierValue(
MessageType::error,
MessageFragment::xModule,
118
#ifndef SP_NO_MESSAGE_TEXT
,"value missing for qualifier in pattern"
#endif
);
const MessageType1 InterpreterMessages::patternUnknownQualifier(
MessageType::error,
MessageFragment::xModule,
119
#ifndef SP_NO_MESSAGE_TEXT
,"unknown pattern qualifier %1"
#endif
);
const MessageType2 InterpreterMessages::patternBadQualifierValue(
MessageType::error,
MessageFragment::xModule,
120
#ifndef SP_NO_MESSAGE_TEXT
,"bad value %1 for %2 qualifier in pattern"
#endif
);
const MessageType0 InterpreterMessages::patternChildRepeat(
MessageType::error,
MessageFragment::xModule,
121
#ifndef SP_NO_MESSAGE_TEXT
,"repeat qualifier not allowed inside children qualifier"
#endif
);
const MessageType0 InterpreterMessages::patternBadAttributeQualifier(
MessageType::error,
MessageFragment::xModule,
122
#ifndef SP_NO_MESSAGE_TEXT
,"bad value for attributes qualifier in pattern"
#endif
);
const MessageType1L InterpreterMessages::ambiguousStyle(
MessageType::error,
MessageFragment::xModule,
123
#ifndef SP_NO_MESSAGE_TEXT
,"characteristic %1 applied in style rule with same specificity"
,0
,"other style rule is here"
#endif
);
const MessageType0 InterpreterMessages::ambiguousMatch(
MessageType::error,
MessageFragment::xModule,
125
#ifndef SP_NO_MESSAGE_TEXT
,"node matches more than one pattern with the same specificity"
,"ISO/IEC 10179:1996 12.4.1"
#endif
);
const MessageType1 InterpreterMessages::uninitializedVariableReference(
MessageType::error,
MessageFragment::xModule,
126
#ifndef SP_NO_MESSAGE_TEXT
,"reference to uninitialized variable %1"
#endif
);
const MessageType1 InterpreterMessages::actualLoop(
MessageType::error,
MessageFragment::xModule,
127
#ifndef SP_NO_MESSAGE_TEXT
,"circular use of actual value of characteristic %1"
,"ISO/IEC 10179:1996 12.4.6"
#endif
);
const MessageType1L InterpreterMessages::duplicateCharacteristic(
MessageType::error,
MessageFragment::xModule,
128
#ifndef SP_NO_MESSAGE_TEXT
,"characteristic %1 already defined in same part"
,"ISO/IEC 10179:1996 12.4.6"
,"first definition was here"
#endif
);
const MessageType1L InterpreterMessages::duplicateFlowObjectClass(
MessageType::error,
MessageFragment::xModule,
130
#ifndef SP_NO_MESSAGE_TEXT
,"flow object class %1 already defined in same part"
,"ISO/IEC 10179:1996 12.4.3 [178]"
,"first definition was here"
#endif
);
const MessageType1 InterpreterMessages::undefinedMode(
MessageType::error,
MessageFragment::xModule,
132
#ifndef SP_NO_MESSAGE_TEXT
,"mode %1 not defined"
,"ISO/IEC 10179:1996 12.4.3 [180]"
#endif
);
const MessageType1 InterpreterMessages::duplicateCharName(
MessageType::error,
MessageFragment::xModule,
133
#ifndef SP_NO_MESSAGE_TEXT
,"duplicate character name %1"
,"ISO/IEC 10179:1996 7.1.4"
#endif
);
const MessageType1 InterpreterMessages::duplicateSdataEntityName(
MessageType::error,
MessageFragment::xModule,
134
#ifndef SP_NO_MESSAGE_TEXT
,"duplicate SDATA entity name %1"
,"ISO/IEC 10179:1996 7.1.8"
#endif
);
const MessageType1 InterpreterMessages::duplicateSdataEntityText(
MessageType::error,
MessageFragment::xModule,
135
#ifndef SP_NO_MESSAGE_TEXT
,"duplicate SDATA entity text %1"
,"ISO/IEC 10179:1996 7.1.8"
#endif
);
const MessageType0 InterpreterMessages::unsupportedDeclaration(
MessageType::warning,
MessageFragment::xModule,
136
#ifndef SP_NO_MESSAGE_TEXT
,"unsupported declaration will be ignored"
#endif
);
const MessageType1 InterpreterMessages::unsupportedCharRepertoire(
MessageType::warning,
MessageFragment::xModule,
137
#ifndef SP_NO_MESSAGE_TEXT
,"unsupported character repertoire %1 will be ignored"
#endif
);
const MessageType0 InterpreterMessages::badDeclaration(
MessageType::error,
MessageFragment::xModule,
138
#ifndef SP_NO_MESSAGE_TEXT
,"error in declaration element"
#endif
);
const MessageType1 InterpreterMessages::invalidIdentifier(
MessageType::error,
MessageFragment::xModule,
140
#ifndef SP_NO_MESSAGE_TEXT
,"%1 is not a valid identifier"
,"ISO/IEC 10179:1996 7.3.2 [1]"
#endif
);
const MessageType0 InterpreterMessages::badLanguageDefinition(
MessageType::error,
MessageFragment::xModule,
141
#ifndef SP_NO_MESSAGE_TEXT
,"error in language definition"
,"ISO/IEC 10179:1996 8.5.8.2.1 [100]"
#endif
);
const MessageType0 InterpreterMessages::noCurrentLanguage(
MessageType::error,
MessageFragment::xModule,
142
#ifndef SP_NO_MESSAGE_TEXT
,"no current language"
,"ISO/IEC 10179:1996 8.5.8.4 8.5.8.5 8.5.8.6 8.5.9.5 8.5.9.6"
#endif
);
const MessageType3 InterpreterMessages::notALanguage(
MessageType::error,
MessageFragment::xModule,
143
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a language"
,"ISO/IEC 10179:1996 8.5.8.2"
#endif
);
const MessageType3 InterpreterMessages::notAPositiveInteger(
MessageType::error,
MessageFragment::xModule,
144
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a positive integer"
#endif
);
const MessageType3 InterpreterMessages::notAnInteger(
MessageType::error,
MessageFragment::xModule,
145
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an integer"
#endif
);
const MessageType3 InterpreterMessages::notAKeyword(
MessageType::error,
MessageFragment::xModule,
146
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a keyword"
#endif
);
const MessageType3 InterpreterMessages::notAnAlist(
MessageType::error,
MessageFragment::xModule,
147
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not an alist"
#endif
);
const MessageType3 InterpreterMessages::notACharList(
MessageType::error,
MessageFragment::xModule,
148
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a list of characters"
#endif
);
const MessageType3 InterpreterMessages::lengthError(
MessageType::error,
MessageFragment::xModule,
149
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 has wrong length"
#endif
);
const MessageType1 InterpreterMessages::noExactRepresentation(
MessageType::warning,
MessageFragment::xModule,
150
#ifndef SP_NO_MESSAGE_TEXT
,"quantity %1 can't be represented exactly"
,"ISO/IEC 10179:1996 8.5.7.2"
#endif
);
const MessageType0L InterpreterMessages::duplicateDefLangDecl(
MessageType::error,
MessageFragment::xModule,
151
#ifndef SP_NO_MESSAGE_TEXT
,"default language already declared in this part"
,"ISO/IEC 10179:1996 8.5.8.2 [99]"
,"first declaration was here"
#endif
);
const MessageType1 InterpreterMessages::defLangDeclRequiresLanguage(
MessageType::error,
MessageFragment::xModule,
153
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not a language as required in a default-language-declaration"
,"ISO/IEC 10179:1996 8.5.8.2"
#endif
);
const MessageType1 InterpreterMessages::invalidUnitName(
MessageType::error,
MessageFragment::xModule,
154
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not a valid unit name"
,"ISO/IEC 10179:1996 8.5.7.4 [87]"
#endif
);
const MessageType1 InterpreterMessages::invalidCharName(
MessageType::error,
MessageFragment::xModule,
155
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not a valid character name"
,"ISO/IEC 10179:1996 8.5.8 [95]"
#endif
);
const MessageType1 InterpreterMessages::invalidCharNumber(
MessageType::error,
MessageFragment::xModule,
156
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not a valid character number"
,"ISO/IEC 10179:1996 7.1.4p2 7.1.6p2"
#endif
);
const MessageType1 InterpreterMessages::unknownCharProperty(
MessageType::error,
MessageFragment::xModule,
157
#ifndef SP_NO_MESSAGE_TEXT
,"unknown character property %1"
,"ISO/IEC 10179:1996 8.5.8.1"
#endif
);
const MessageType0 InterpreterMessages::badAddCharProperty(
MessageType::error,
MessageFragment::xModule,
158
#ifndef SP_NO_MESSAGE_TEXT
,"error in character property declaration"
,"ISO/IEC 10179:1996 8.5.8.1"
#endif
);
const MessageType1L InterpreterMessages::duplicateCharPropertyDecl(
MessageType::error,
MessageFragment::xModule,
159
#ifndef SP_NO_MESSAGE_TEXT
,"character property %1 already declared in same part"
,"ISO/IEC 10179:1996 8.5.8.1"
,"first declaration was here"
#endif
);
const MessageType1L InterpreterMessages::duplicateAddCharProperty(
MessageType::error,
MessageFragment::xModule,
161
#ifndef SP_NO_MESSAGE_TEXT
,"added value for character property %1 already declared in same part"
,"ISO/IEC 10179:1996 8.5.8.1"
,"previous declaration was here"
#endif
);
const MessageType0 InterpreterMessages::returnNotSosofo(
MessageType::error,
MessageFragment::xModule,
163
#ifndef SP_NO_MESSAGE_TEXT
,"value returned by procedure was not a sosofo"
#endif
);
const MessageType1 InterpreterMessages::charPropertyLoop(
MessageType::error,
MessageFragment::xModule,
164
#ifndef SP_NO_MESSAGE_TEXT
,"loop in specification of value of character property %1"
#endif
);
const MessageType2 InterpreterMessages::charPropertyNotInteger(
MessageType::error,
MessageFragment::xModule,
165
#ifndef SP_NO_MESSAGE_TEXT
,"value for character property %1 of wrong type: %2 not an integer"
#endif
);
const MessageType2 InterpreterMessages::charPropertyNotIntegerOrFalse(
MessageType::error,
MessageFragment::xModule,
166
#ifndef SP_NO_MESSAGE_TEXT
,"value for character property %1 of wrong type: %2 not an integer or the value \"#f\""
#endif
);
const MessageType1 InterpreterMessages::unknownFeature(
MessageType::error,
MessageFragment::xModule,
167
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not a style or transformation language feature"
,"ISO/IEC 10179:1996 11.1 12.1"
#endif
);
const MessageType1 InterpreterMessages::missingFeature(
MessageType::error,
MessageFragment::xModule,
168
#ifndef SP_NO_MESSAGE_TEXT
,"undeclared use of feature %1"
,"ISO/IEC 10179:1996 7.1.1"
#endif
);
const MessageType1 InterpreterMessages::unsupportedFeature(
MessageType::warning,
MessageFragment::xModule,
169
#ifndef SP_NO_MESSAGE_TEXT
,"feature %1 not supported"
#endif
);
const MessageType1 InterpreterMessages::partiallySupportedFeature(
MessageType::warning,
MessageFragment::xModule,
170
#ifndef SP_NO_MESSAGE_TEXT
,"feature %1 only partially supported"
#endif
);
const MessageType0 InterpreterMessages::styleLanguage(
MessageType::error,
MessageFragment::xModule,
171
#ifndef SP_NO_MESSAGE_TEXT
,"only allowed in style language"
#endif
);
const MessageType0 InterpreterMessages::transformationLanguage(
MessageType::error,
MessageFragment::xModule,
172
#ifndef SP_NO_MESSAGE_TEXT
,"only allowed in transformation language"
#endif
);
const MessageType0 InterpreterMessages::mixedLanguages(
MessageType::error,
MessageFragment::xModule,
173
#ifndef SP_NO_MESSAGE_TEXT
,"style and transformation language parts mixed"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType0 InterpreterMessages::partialSpec(
MessageType::warning,
MessageFragment::xModule,
174
#ifndef SP_NO_MESSAGE_TEXT
,"specification is marked as partial"
,"ISO/IEC 10179:1996 7.1"
#endif
);
const MessageType1 InterpreterMessages::cantOmitModule(
MessageType::warning,
MessageFragment::xModule,
175
#ifndef SP_NO_MESSAGE_TEXT
,"grove plan excluding module %1 not supported"
#endif
);
const MessageType1 InterpreterMessages::cantAddModule(
MessageType::warning,
MessageFragment::xModule,
176
#ifndef SP_NO_MESSAGE_TEXT
,"grove plan including module %1 not supported"
#endif
);
const MessageType1 InterpreterMessages::unknownModule(
MessageType::error,
MessageFragment::xModule,
177
#ifndef SP_NO_MESSAGE_TEXT
,"%1 not an SGML property set module"
#endif
);
const MessageType2 InterpreterMessages::notACharInCharMap(
MessageType::error,
MessageFragment::xModule,
178
#ifndef SP_NO_MESSAGE_TEXT
,"Function for char-map characteristic returned non-char object %2 for character %1"
,"ISO/IEC 10179:1996 12.6.11"
#endif
);
const MessageType2 InterpreterMessages::charPropertyNotPublicId(
MessageType::error,
MessageFragment::xModule,
179
#ifndef SP_NO_MESSAGE_TEXT
,"value for character property %1 of wrong type: %2 not a public identifier or the value \"#f\""
#endif
);
const MessageType1 InterpreterMessages::duplicateVariableBinding(
MessageType::error,
MessageFragment::xModule,
180
#ifndef SP_NO_MESSAGE_TEXT
,"variable %1 occurs more than once in bindings"
,"ISO/IEC 10179:1996 8.3.2.5"
#endif
);
const MessageType0 InterpreterMessages::subgroveArgs(
MessageType::error,
MessageFragment::xModule,
181
#ifndef SP_NO_MESSAGE_TEXT
,"exactly one of node:, subgrove: and class: needed"
,"ISO/IEC 10179:1996 11.3.1"
#endif
);
const MessageType0 InterpreterMessages::subgroveSubgroveArgs(
MessageType::warning,
MessageFragment::xModule,
182
#ifndef SP_NO_MESSAGE_TEXT
,"add:, null:, remove:, children:, sub: make no sense with subgrove:"
,"ISO/IEC 10179:1996 11.3.1"
#endif
);
const MessageType0 InterpreterMessages::subgroveClassArgs(
MessageType::warning,
MessageFragment::xModule,
183
#ifndef SP_NO_MESSAGE_TEXT
,"remove: makes no sense with class:"
,"ISO/IEC 10179:1996 11.3.1"
#endif
);
const MessageType3 InterpreterMessages::notASubgroveSpec(
MessageType::error,
MessageFragment::xModule,
184
#ifndef SP_NO_MESSAGE_TEXT
,"%2 argument for primitive %1 of wrong type: %3 not a subgrove-spec"
#endif
);
const MessageType1 InterpreterMessages::notACspecList(
MessageType::error,
MessageFragment::xModule,
185
#ifndef SP_NO_MESSAGE_TEXT
,"wrong type: %1 not a list of create-specs"
#endif
);
const MessageType1 InterpreterMessages::notACspecOrCspecList(
MessageType::error,
MessageFragment::xModule,
186
#ifndef SP_NO_MESSAGE_TEXT
,"wrong type: %1 not a create-spec or list of create-specs"
#endif
);
const MessageType1 InterpreterMessages::queryNotANodeList(
MessageType::error,
MessageFragment::xModule,
187
#ifndef SP_NO_MESSAGE_TEXT
,"query expression: %1 not a node list"
,"ISO/IEC 10179:1996 11.2 12.4.1 [152] [164]"
#endif
);
const MessageType1 InterpreterMessages::priorityNotAnExactInteger(
MessageType::error,
MessageFragment::xModule,
188
#ifndef SP_NO_MESSAGE_TEXT
,"priority expression: %1 not an exact integer"
,"ISO/IEC 10179:1996 11.2 12.4.1 [152] [164]"
#endif
);
const MessageType0 InterpreterMessages::badTopLevelFlowObj(
MessageType::error,
MessageFragment::xModule,
189
#ifndef SP_NO_MESSAGE_TEXT
,"flow objects at the root must be all of class scroll or all of class page-sequence or simple-page-sequence"
,"ISO/IEC 10179:1996 12.4.1"
#endif
);
const MessageType0 InterpreterMessages::noPrincipalPort(
MessageType::error,
MessageFragment::xModule,
190
#ifndef SP_NO_MESSAGE_TEXT
,"current flow parent has no principal port"
#endif
);
const MessageType0 InterpreterMessages::noParagraphAncestor(
MessageType::error,
MessageFragment::xModule,
191
#ifndef SP_NO_MESSAGE_TEXT
,"this flow object requires a paragraph as an ancestor flow object"
#endif
);
const MessageType0 InterpreterMessages::notInlineFlowObj(
MessageType::error,
MessageFragment::xModule,
192
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only inline flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::notDisplayFlowObj(
MessageType::error,
MessageFragment::xModule,
193
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only display flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::notInlineOrDisplayFlowObj(
MessageType::error,
MessageFragment::xModule,
194
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only display or inline flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::notValidInParagraph(
MessageType::error,
MessageFragment::xModule,
195
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted in a paragraph; only inline, display or paragraph-break flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::notSideBySideItem(
MessageType::error,
MessageFragment::xModule,
196
#ifndef SP_NO_MESSAGE_TEXT
,"a side-by-side flow object only accepts side-by-side-item flow objects as children"
#endif
);
const MessageType0 InterpreterMessages::notMathSequence(
MessageType::error,
MessageFragment::xModule,
197
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only math-sequence, unmath, subscript, superscript, script, mark, fence, fraction, radical, math-operator, grid, character and alignment-point flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::notGridCell(
MessageType::error,
MessageFragment::xModule,
198
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; must be grid-cell"
#endif
);
const MessageType0 InterpreterMessages::notSingleChar(
MessageType::error,
MessageFragment::xModule,
199
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only a single character flow object accepted"
#endif
);
const MessageType0 InterpreterMessages::badTableContent(
MessageType::error,
MessageFragment::xModule,
200
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; in a table, only either table-part flow objects or table-column flow objects followed by table-row or table-cell flow objects are allowed"
#endif
);
const MessageType0 InterpreterMessages::badTablePartHF(
MessageType::error,
MessageFragment::xModule,
201
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only table-row or table-cell flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::badTablePartBody(
MessageType::error,
MessageFragment::xModule,
202
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only table-column flow objects followed by table-row or table-cell flow objects allowd"
#endif
);
const MessageType0 InterpreterMessages::badTableRow(
MessageType::error,
MessageFragment::xModule,
203
#ifndef SP_NO_MESSAGE_TEXT
,"flow object not accepted by port; only table-cell flow objects accepted"
#endif
);
const MessageType0 InterpreterMessages::priorityNotNumber(
MessageType::error,
MessageFragment::xModule,
204
#ifndef SP_NO_MESSAGE_TEXT
,"priority-expression must be a number"
#endif
);
const MessageType0 InterpreterMessages::queryNotNodelist(
MessageType::error,
MessageFragment::xModule,
205
#ifndef SP_NO_MESSAGE_TEXT
,"query-expression must be a node-list"
#endif
);
const MessageType0 InterpreterMessages::sorryPriority(
MessageType::error,
MessageFragment::xModule,
206
#ifndef SP_NO_MESSAGE_TEXT
,"Sorry, non-integral priorities not implemented"
#endif
);
#ifdef SP_NAMESPACE
}
#endif
