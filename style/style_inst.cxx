#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif


#ifdef SP_NAMESPACE
}
#endif
// Copyright (c) 1996 James Clark
// See the file copying.txt for copying permission.

#include "stylelib.h"

#ifdef SP_MANUAL_INST

#define SP_DEFINE_TEMPLATES
#include <OpenSP/Vector.h>
#include <OpenSP/NCVector.h>
#include <OpenSP/Ptr.h>
#include <OpenSP/Owner.h>
#include <OpenSP/PointerTable.h>
#include <OpenSP/OwnerTable.h>
#include <OpenSP/NamedTable.h>
#include <OpenSP/IList.h>
#include <OpenSP/IListIter.h>
#include <OpenSP/IQueue.h>
#include <OpenSP/HashTable.h>
#include <OpenSP/CharMap.h>
#ifdef SP_SIZEOF_BOOL_1
#include <OpenSP/XcharMap.h>
#endif
#undef SP_DEFINE_TEMPLATES

#include "Insn.h"
#include "Expression.h"
#include "Interpreter.h"
#include "ELObj.h"
#include "Style.h"
#include "FOTBuilder.h"
#include "ProcessingMode.h"
#include "ProcessContext.h"
#include "SosofoObj.h"
#include "DssslSpecEventHandler.h"
#include <OpenSP/Boolean.h>
#include "Node.h"
#include "DssslApp.h"
#include "Pattern.h"
#include "MacroFlowObj.h"

#ifdef DSSSL_NAMESPACE
class DSSSL_NAMESPACE::ProcessingMode;
class DSSSL_NAMESPACE::SosofoObj;
#else
class ProcessingMode;
class SosofoObj;
#endif

#if _MSC_VER >= 1100

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

#ifdef DSSSL_NAMESPACE
using namespace DSSSL_NAMESPACE;
#endif

#ifdef GROVE_NAMESPACE
using namespace GROVE_NAMESPACE;
#endif

#else

#ifdef DSSSL_NAMESPACE
namespace DSSSL_NAMESPACE {
#endif

#endif

#ifdef __DECCXX
#pragma define_template Ptr<Insn>
#else
#ifdef __xlC__
#pragma define(Ptr<Insn>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<Insn>;
#else
typedef Ptr<Insn> Dummy_0;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<Expression>
#else
#ifdef __xlC__
#pragma define(Owner<Expression>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<Expression>;
#else
typedef Owner<Expression> Dummy_1;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const Identifier *>
#else
#ifdef __xlC__
#pragma define(Vector<const Identifier *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const Identifier *>;
#else
typedef Vector<const Identifier *> Dummy_2;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<Owner<Expression> >
#else
#ifdef __xlC__
#pragma define(NCVector<Owner<Expression> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<Owner<Expression> >;
#else
typedef NCVector<Owner<Expression> > Dummy_3;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<BoundVar>
#else
#ifdef __xlC__
#pragma define(Vector<BoundVar>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<BoundVar>;
#else
typedef Vector<BoundVar> Dummy_4;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder>;
#else
typedef Owner<FOTBuilder> Dummy_5;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<SaveFOTBuilder>
#else
#ifdef __xlC__
#pragma define(Owner<SaveFOTBuilder>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<SaveFOTBuilder>;
#else
typedef Owner<SaveFOTBuilder> Dummy_6;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<InputSource>
#else
#ifdef __xlC__
#pragma define(Owner<InputSource>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<InputSource>;
#else
typedef Owner<InputSource> Dummy_7;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<SymbolObj *>
#else
#ifdef __xlC__
#pragma define(Vector<SymbolObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<SymbolObj *>;
#else
typedef Vector<SymbolObj *> Dummy_8;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<OutputCharStream>
#else
#ifdef __xlC__
#pragma define(Owner<OutputCharStream>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<OutputCharStream>;
#else
typedef Owner<OutputCharStream> Dummy_9;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<Environment::FrameVarList>
#else
#ifdef __xlC__
#pragma define(Ptr<Environment::FrameVarList>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<Environment::FrameVarList>;
#else
typedef Ptr<Environment::FrameVarList> Dummy_10;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template ConstPtr<Environment::FrameVarList>
#else
#ifdef __xlC__
#pragma define(ConstPtr<Environment::FrameVarList>)
#else
#ifdef SP_ANSI_CLASS_INST
template class ConstPtr<Environment::FrameVarList>;
#else
typedef ConstPtr<Environment::FrameVarList> Dummy_11;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template PointerTable<SymbolObj *, StringC, Hash, SymbolObj>
#else
#ifdef __xlC__
#pragma define(PointerTable<SymbolObj *, StringC, Hash, SymbolObj>)
#else
#ifdef SP_ANSI_CLASS_INST
template class PointerTable<SymbolObj *, StringC, Hash, SymbolObj>;
#else
typedef PointerTable<SymbolObj *, StringC, Hash, SymbolObj> Dummy_12;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTableIter<Identifier>
#else
#ifdef __xlC__
#pragma define(NamedTableIter<Identifier>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTableIter<Identifier>;
#else
typedef NamedTableIter<Identifier> Dummy_13;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<StyleSpec>
#else
#ifdef __xlC__
#pragma define(Ptr<StyleSpec>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<StyleSpec>;
#else
typedef Ptr<StyleSpec> Dummy_14;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<InheritedC>
#else
#ifdef __xlC__
#pragma define(Ptr<InheritedC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<InheritedC>;
#else
typedef Ptr<InheritedC> Dummy_15;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template ConstPtr<InheritedC>
#else
#ifdef __xlC__
#pragma define(ConstPtr<InheritedC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class ConstPtr<InheritedC>;
#else
typedef ConstPtr<InheritedC> Dummy_16;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ConstPtr<InheritedC> >
#else
#ifdef __xlC__
#pragma define(Vector<ConstPtr<InheritedC> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ConstPtr<InheritedC> >;
#else
typedef Vector<ConstPtr<InheritedC> > Dummy_17;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const Vector<ConstPtr<InheritedC> > *>
#else
#ifdef __xlC__
#pragma define(Vector<const Vector<ConstPtr<InheritedC> > *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const Vector<ConstPtr<InheritedC> > *>;
#else
typedef Vector<const Vector<ConstPtr<InheritedC> > *> Dummy_18;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const VarStyleObj *>
#else
#ifdef __xlC__
#pragma define(Vector<const VarStyleObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const VarStyleObj *>;
#else
typedef Vector<const VarStyleObj *> Dummy_19;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<InheritedCInfo>
#else
#ifdef __xlC__
#pragma define(Ptr<InheritedCInfo>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<InheritedCInfo>;
#else
typedef Ptr<InheritedCInfo> Dummy_20;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTable<ProcessingMode::ElementRules>
#else
#ifdef __xlC__
#pragma define(NamedTable<ProcessingMode::ElementRules>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTable<ProcessingMode::ElementRules>;
#else
typedef NamedTable<ProcessingMode::ElementRules> Dummy_21;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTableIter<ProcessingMode::ElementRules>
#else
#ifdef __xlC__
#pragma define(NamedTableIter<ProcessingMode::ElementRules>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTableIter<ProcessingMode::ElementRules>;
#else
typedef NamedTableIter<ProcessingMode::ElementRules> Dummy_22;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTableIter<ProcessingMode>
#else
#ifdef __xlC__
#pragma define(NamedTableIter<ProcessingMode>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTableIter<ProcessingMode>;
#else
typedef NamedTableIter<ProcessingMode> Dummy_23;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<ProcessingMode::GroveRules>
#else
#ifdef __xlC__
#pragma define(NCVector<ProcessingMode::GroveRules>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<ProcessingMode::GroveRules>;
#else
typedef NCVector<ProcessingMode::GroveRules> Dummy_24;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ProcessingMode::Rule>
#else
#ifdef __xlC__
#pragma define(Vector<ProcessingMode::Rule>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ProcessingMode::Rule>;
#else
typedef Vector<ProcessingMode::Rule> Dummy_25;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<ProcessingMode::Action>
#else
#ifdef __xlC__
#pragma define(Ptr<ProcessingMode::Action>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<ProcessingMode::Action>;
#else
typedef Ptr<ProcessingMode::Action> Dummy_26;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<ProcessingMode::ElementRule>
#else
#ifdef __xlC__
#pragma define(IList<ProcessingMode::ElementRule>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<ProcessingMode::ElementRule>;
#else
typedef IList<ProcessingMode::ElementRule> Dummy_27;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<ProcessingMode::ElementRule>
#else
#ifdef __xlC__
#pragma define(IListIter<ProcessingMode::ElementRule>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<ProcessingMode::ElementRule>;
#else
typedef IListIter<ProcessingMode::ElementRule> Dummy_28;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const ProcessingMode::ElementRule *>
#else
#ifdef __xlC__
#pragma define(Vector<const ProcessingMode::ElementRule *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const ProcessingMode::ElementRule *>;
#else
typedef Vector<const ProcessingMode::ElementRule *> Dummy_29;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<SaveFOTBuilder>
#else
#ifdef __xlC__
#pragma define(IList<SaveFOTBuilder>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<SaveFOTBuilder>;
#else
typedef IList<SaveFOTBuilder> Dummy_30;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const ProcessingMode *>
#else
#ifdef __xlC__
#pragma define(Vector<const ProcessingMode *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const ProcessingMode *>;
#else
typedef Vector<const ProcessingMode *> Dummy_31;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::DisplayGroupNIC>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::DisplayGroupNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::DisplayGroupNIC>;
#else
typedef Owner<FOTBuilder::DisplayGroupNIC> Dummy_32;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<SosofoObj *>
#else
#ifdef __xlC__
#pragma define(Vector<SosofoObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<SosofoObj *>;
#else
typedef Vector<SosofoObj *> Dummy_33;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<FOTBuilder *>
#else
#ifdef __xlC__
#pragma define(Vector<FOTBuilder *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<FOTBuilder *>;
#else
typedef Vector<FOTBuilder *> Dummy_34;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IQueue<NodeSaveFOTBuilder>
#else
#ifdef __xlC__
#pragma define(IQueue<NodeSaveFOTBuilder>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IQueue<NodeSaveFOTBuilder>;
#else
typedef IQueue<NodeSaveFOTBuilder> Dummy_35;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<IQueue<NodeSaveFOTBuilder> >
#else
#ifdef __xlC__
#pragma define(NCVector<IQueue<NodeSaveFOTBuilder> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<IQueue<NodeSaveFOTBuilder> >;
#else
typedef NCVector<IQueue<NodeSaveFOTBuilder> > Dummy_36;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<ProcessContext::Connection>
#else
#ifdef __xlC__
#pragma define(IList<ProcessContext::Connection>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<ProcessContext::Connection>;
#else
typedef IList<ProcessContext::Connection> Dummy_37;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<ProcessContext::Connection>
#else
#ifdef __xlC__
#pragma define(IListIter<ProcessContext::Connection>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<ProcessContext::Connection>;
#else
typedef IListIter<ProcessContext::Connection> Dummy_38;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<ProcessContext::Connectable>
#else
#ifdef __xlC__
#pragma define(IList<ProcessContext::Connectable>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<ProcessContext::Connectable>;
#else
typedef IList<ProcessContext::Connectable> Dummy_39;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<ProcessContext::Connectable>
#else
#ifdef __xlC__
#pragma define(IListIter<ProcessContext::Connectable>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<ProcessContext::Connectable>;
#else
typedef IListIter<ProcessContext::Connectable> Dummy_40;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<PopList>
#else
#ifdef __xlC__
#pragma define(Ptr<PopList>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<PopList>;
#else
typedef Ptr<PopList> Dummy_41;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<Ptr<InheritedCInfo> >
#else
#ifdef __xlC__
#pragma define(Vector<Ptr<InheritedCInfo> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<Ptr<InheritedCInfo> >;
#else
typedef Vector<Ptr<InheritedCInfo> > Dummy_42;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<ProcessContext::Port>
#else
#ifdef __xlC__
#pragma define(NCVector<ProcessContext::Port>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<ProcessContext::Port>;
#else
typedef NCVector<ProcessContext::Port> Dummy_43;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<CaseExpression::Case>
#else
#ifdef __xlC__
#pragma define(NCVector<CaseExpression::Case>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<CaseExpression::Case>;
#else
typedef NCVector<CaseExpression::Case> Dummy_44;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTable<NumberCache::Entry>
#else
#ifdef __xlC__
#pragma define(NamedTable<NumberCache::Entry>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTable<NumberCache::Entry>;
#else
typedef NamedTable<NumberCache::Entry> Dummy_45;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<NamedTable<NumberCache::Entry> >
#else
#ifdef __xlC__
#pragma define(NCVector<NamedTable<NumberCache::Entry> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<NamedTable<NumberCache::Entry> >;
#else
typedef NCVector<NamedTable<NumberCache::Entry> > Dummy_46;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NamedTable<NumberCache::ElementEntry>
#else
#ifdef __xlC__
#pragma define(NamedTable<NumberCache::ElementEntry>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NamedTable<NumberCache::ElementEntry>;
#else
typedef NamedTable<NumberCache::ElementEntry> Dummy_47;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<NamedTable<NumberCache::ElementEntry> >
#else
#ifdef __xlC__
#pragma define(NCVector<NamedTable<NumberCache::ElementEntry> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<NamedTable<NumberCache::ElementEntry> >;
#else
typedef NCVector<NamedTable<NumberCache::ElementEntry> > Dummy_48;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ELObj *>
#else
#ifdef __xlC__
#pragma define(Vector<ELObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ELObj *>;
#else
typedef Vector<ELObj *> Dummy_49;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ConstPtr<Insn> >
#else
#ifdef __xlC__
#pragma define(Vector<ConstPtr<Insn> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ConstPtr<Insn> >;
#else
typedef Vector<ConstPtr<Insn> > Dummy_50;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<StyleObj *>
#else
#ifdef __xlC__
#pragma define(Vector<StyleObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<StyleObj *>;
#else
typedef Vector<StyleObj *> Dummy_51;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<Vector<StyleObj *> >
#else
#ifdef __xlC__
#pragma define(Vector<Vector<StyleObj *> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<Vector<StyleObj *> >;
#else
typedef Vector<Vector<StyleObj *> > Dummy_52;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<ProcessContext::Table>
#else
#ifdef __xlC__
#pragma define(IList<ProcessContext::Table>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<ProcessContext::Table>;
#else
typedef IList<ProcessContext::Table> Dummy_53;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<ProcessContext::Table>
#else
#ifdef __xlC__
#pragma define(IListIter<ProcessContext::Table>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<ProcessContext::Table>;
#else
typedef IListIter<ProcessContext::Table> Dummy_54;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<String<char> >
#else
#ifdef __xlC__
#pragma define(Vector<String<char> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<String<char> >;
#else
typedef Vector<String<char> > Dummy_55;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<LengthSpec>
#else
#ifdef __xlC__
#pragma define(Owner<LengthSpec>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<LengthSpec>;
#else
typedef Owner<LengthSpec> Dummy_56;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<FOTBuilder::MultiMode>
#else
#ifdef __xlC__
#pragma define(Vector<FOTBuilder::MultiMode>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<FOTBuilder::MultiMode>;
#else
typedef Vector<FOTBuilder::MultiMode> Dummy_57;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<Vector<FOTBuilder::MultiMode> >
#else
#ifdef __xlC__
#pragma define(Vector<Vector<FOTBuilder::MultiMode> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<Vector<FOTBuilder::MultiMode> >;
#else
typedef Vector<Vector<FOTBuilder::MultiMode> > Dummy_58;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<FOTBuilder::CharacterNIC>
#else
#ifdef __xlC__
#pragma define(Vector<FOTBuilder::CharacterNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<FOTBuilder::CharacterNIC>;
#else
typedef Vector<FOTBuilder::CharacterNIC> Dummy_59;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTable<StringC,FunctionObj *>
#else
#ifdef __xlC__
#pragma define(HashTable<StringC,FunctionObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTable<StringC,FunctionObj *>;
#else
typedef HashTable<StringC,FunctionObj *> Dummy_60;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTableItem<StringC,FunctionObj *>
#else
#ifdef __xlC__
#pragma define(HashTableItem<StringC,FunctionObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTableItem<StringC,FunctionObj *>;
#else
typedef HashTableItem<StringC,FunctionObj *> Dummy_61;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<DssslSpecEventHandler::Part *>
#else
#ifdef __xlC__
#pragma define(Vector<DssslSpecEventHandler::Part *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<DssslSpecEventHandler::Part *>;
#else
typedef Vector<DssslSpecEventHandler::Part *> Dummy_62;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<DssslSpecEventHandler::PartHeader *>
#else
#ifdef __xlC__
#pragma define(Vector<DssslSpecEventHandler::PartHeader *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<DssslSpecEventHandler::PartHeader *>;
#else
typedef Vector<DssslSpecEventHandler::PartHeader *> Dummy_63;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<DssslSpecEventHandler::BodyElement>
#else
#ifdef __xlC__
#pragma define(IListIter<DssslSpecEventHandler::BodyElement>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<DssslSpecEventHandler::BodyElement>;
#else
typedef IListIter<DssslSpecEventHandler::BodyElement> Dummy_64;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<DssslSpecEventHandler::BodyElement>
#else
#ifdef __xlC__
#pragma define(IList<DssslSpecEventHandler::BodyElement>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<DssslSpecEventHandler::BodyElement>;
#else
typedef IList<DssslSpecEventHandler::BodyElement> Dummy_65;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<DssslSpecEventHandler::PartHeader>
#else
#ifdef __xlC__
#pragma define(IListIter<DssslSpecEventHandler::PartHeader>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<DssslSpecEventHandler::PartHeader>;
#else
typedef IListIter<DssslSpecEventHandler::PartHeader> Dummy_66;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<DssslSpecEventHandler::PartHeader>
#else
#ifdef __xlC__
#pragma define(IList<DssslSpecEventHandler::PartHeader>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<DssslSpecEventHandler::PartHeader>;
#else
typedef IList<DssslSpecEventHandler::PartHeader> Dummy_67;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<DssslSpecEventHandler::Doc>
#else
#ifdef __xlC__
#pragma define(IListIter<DssslSpecEventHandler::Doc>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<DssslSpecEventHandler::Doc>;
#else
typedef IListIter<DssslSpecEventHandler::Doc> Dummy_68;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<DssslSpecEventHandler::Doc>
#else
#ifdef __xlC__
#pragma define(IList<DssslSpecEventHandler::Doc>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<DssslSpecEventHandler::Doc>;
#else
typedef IList<DssslSpecEventHandler::Doc> Dummy_69;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<DssslSpecEventHandler::SpecPart>
#else
#ifdef __xlC__
#pragma define(Owner<DssslSpecEventHandler::SpecPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<DssslSpecEventHandler::SpecPart>;
#else
typedef Owner<DssslSpecEventHandler::SpecPart> Dummy_70;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<Location>
#else
#ifdef __xlC__
#pragma define(Owner<Location>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<Location>;
#else
typedef Owner<Location> Dummy_71;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::DisplaySpace>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::DisplaySpace>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::DisplaySpace>;
#else
typedef Owner<FOTBuilder::DisplaySpace> Dummy_72;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::InlineSpace>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::InlineSpace>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::InlineSpace>;
#else
typedef Owner<FOTBuilder::InlineSpace> Dummy_73;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::Address>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::Address>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::Address>;
#else
typedef Owner<FOTBuilder::Address> Dummy_74;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<String<char> *>
#else
#ifdef __xlC__
#pragma define(Vector<String<char> *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<String<char> *>;
#else
typedef Vector<String<char> *> Dummy_75;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template PointerTable<String<char> *, String<char>, Interpreter::StringSet, Interpreter::StringSet>
#else
#ifdef __xlC__
#pragma define(PointerTable<String<char> *, String<char>, Interpreter::StringSet, Interpreter::StringSet>)
#else
#ifdef SP_ANSI_CLASS_INST
template class PointerTable<String<char> *, String<char>, Interpreter::StringSet, Interpreter::StringSet>;
#else
typedef PointerTable<String<char> *, String<char>, Interpreter::StringSet, Interpreter::StringSet> Dummy_76;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OwnerTable<String<char>, String<char>, Interpreter::StringSet, Interpreter::StringSet>
#else
#ifdef __xlC__
#pragma define(OwnerTable<String<char>, String<char>, Interpreter::StringSet, Interpreter::StringSet>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OwnerTable<String<char>, String<char>, Interpreter::StringSet, Interpreter::StringSet>;
#else
typedef OwnerTable<String<char>, String<char>, Interpreter::StringSet, Interpreter::StringSet> Dummy_77;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<FOTBuilder::GlyphId>
#else
#ifdef __xlC__
#pragma define(Vector<FOTBuilder::GlyphId>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<FOTBuilder::GlyphId>;
#else
typedef Vector<FOTBuilder::GlyphId> Dummy_78;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<FOTBuilder::GlyphSubstTable>
#else
#ifdef __xlC__
#pragma define(Ptr<FOTBuilder::GlyphSubstTable>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<FOTBuilder::GlyphSubstTable>;
#else
typedef Ptr<FOTBuilder::GlyphSubstTable> Dummy_79;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template ConstPtr<FOTBuilder::GlyphSubstTable>
#else
#ifdef __xlC__
#pragma define(ConstPtr<FOTBuilder::GlyphSubstTable>)
#else
#ifdef SP_ANSI_CLASS_INST
template class ConstPtr<FOTBuilder::GlyphSubstTable>;
#else
typedef ConstPtr<FOTBuilder::GlyphSubstTable> Dummy_80;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ConstPtr<FOTBuilder::GlyphSubstTable> >
#else
#ifdef __xlC__
#pragma define(Vector<ConstPtr<FOTBuilder::GlyphSubstTable> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ConstPtr<FOTBuilder::GlyphSubstTable> >;
#else
typedef Vector<ConstPtr<FOTBuilder::GlyphSubstTable> > Dummy_81;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::ExtensionFlowObj>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::ExtensionFlowObj>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::ExtensionFlowObj>;
#else
typedef Owner<FOTBuilder::ExtensionFlowObj> Dummy_82;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<FOTBuilder::CompoundExtensionFlowObj>
#else
#ifdef __xlC__
#pragma define(Owner<FOTBuilder::CompoundExtensionFlowObj>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<FOTBuilder::CompoundExtensionFlowObj>;
#else
typedef Owner<FOTBuilder::CompoundExtensionFlowObj> Dummy_83;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTable<StringC,NodePtr>
#else
#ifdef __xlC__
#pragma define(HashTable<StringC,NodePtr>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTable<StringC,NodePtr>;
#else
typedef HashTable<StringC,NodePtr> Dummy_84;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTableItem<StringC,NodePtr>
#else
#ifdef __xlC__
#pragma define(HashTableItem<StringC,NodePtr>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTableItem<StringC,NodePtr>;
#else
typedef HashTableItem<StringC,NodePtr> Dummy_85;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ProcessContext::NodeStackEntry>
#else
#ifdef __xlC__
#pragma define(Vector<ProcessContext::NodeStackEntry>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ProcessContext::NodeStackEntry>;
#else
typedef Vector<ProcessContext::NodeStackEntry> Dummy_86;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<const Pattern::Element *>
#else
#ifdef __xlC__
#pragma define(Vector<const Pattern::Element *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<const Pattern::Element *>;
#else
typedef Vector<const Pattern::Element *> Dummy_87;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<Pattern>
#else
#ifdef __xlC__
#pragma define(NCVector<Pattern>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<Pattern>;
#else
typedef NCVector<Pattern> Dummy_88;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<Pattern::Element>
#else
#ifdef __xlC__
#pragma define(IList<Pattern::Element>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<Pattern::Element>;
#else
typedef IList<Pattern::Element> Dummy_89;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<Pattern::Element>
#else
#ifdef __xlC__
#pragma define(IListIter<Pattern::Element>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<Pattern::Element>;
#else
typedef IListIter<Pattern::Element> Dummy_90;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IList<Pattern::Qualifier>
#else
#ifdef __xlC__
#pragma define(IList<Pattern::Qualifier>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IList<Pattern::Qualifier>;
#else
typedef IList<Pattern::Qualifier> Dummy_91;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template IListIter<Pattern::Qualifier>
#else
#ifdef __xlC__
#pragma define(IListIter<Pattern::Qualifier>)
#else
#ifdef SP_ANSI_CLASS_INST
template class IListIter<Pattern::Qualifier>;
#else
typedef IListIter<Pattern::Qualifier> Dummy_92;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<MacroFlowObj::Definition>
#else
#ifdef __xlC__
#pragma define(Ptr<MacroFlowObj::Definition>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<MacroFlowObj::Definition>;
#else
typedef Ptr<MacroFlowObj::Definition> Dummy_93;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<MacroFlowObj::S>
#else
#ifdef __xlC__
#pragma define(Owner<MacroFlowObj::S>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<MacroFlowObj::S>;
#else
typedef Owner<MacroFlowObj::S> Dummy_94;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTable<StringC,CharPart>
#else
#ifdef __xlC__
#pragma define(HashTable<StringC,CharPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTable<StringC,CharPart>;
#else
typedef HashTable<StringC,CharPart> Dummy_95;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTableItem<StringC,CharPart>
#else
#ifdef __xlC__
#pragma define(HashTableItem<StringC,CharPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTableItem<StringC,CharPart>;
#else
typedef HashTableItem<StringC,CharPart> Dummy_96;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTable<StringC,StringC>
#else
#ifdef __xlC__
#pragma define(HashTable<StringC,StringC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTable<StringC,StringC>;
#else
typedef HashTable<StringC,StringC> Dummy_97;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template HashTableItem<StringC,StringC>
#else
#ifdef __xlC__
#pragma define(HashTableItem<StringC,StringC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class HashTableItem<StringC,StringC>;
#else
typedef HashTableItem<StringC,StringC> Dummy_98;
#endif
#endif
#endif
#ifdef SP_SIZEOF_BOOL_1
#ifdef __DECCXX
#pragma define_template XcharMap<char>
#else
#ifdef __xlC__
#pragma define(XcharMap<char>)
#else
#ifdef SP_ANSI_CLASS_INST
template class XcharMap<char>;
#else
typedef XcharMap<char> Dummy_99;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template SharedXcharMap<char>
#else
#ifdef __xlC__
#pragma define(SharedXcharMap<char>)
#else
#ifdef SP_ANSI_CLASS_INST
template class SharedXcharMap<char>;
#else
typedef SharedXcharMap<char> Dummy_100;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<SharedXcharMap<char> >
#else
#ifdef __xlC__
#pragma define(Ptr<SharedXcharMap<char> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<SharedXcharMap<char> >;
#else
typedef Ptr<SharedXcharMap<char> > Dummy_101;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template ConstPtr<SharedXcharMap<char> >
#else
#ifdef __xlC__
#pragma define(ConstPtr<SharedXcharMap<char> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class ConstPtr<SharedXcharMap<char> >;
#else
typedef ConstPtr<SharedXcharMap<char> > Dummy_102;
#endif
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<ELObjPart>
#else
#ifdef __xlC__
#pragma define(CharMap<ELObjPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<ELObjPart>;
#else
typedef CharMap<ELObjPart> Dummy_103;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<ELObjPart>
#else
#ifdef __xlC__
#pragma define(CharMapPage<ELObjPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<ELObjPart>;
#else
typedef CharMapPage<ELObjPart> Dummy_104;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<ELObjPart>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<ELObjPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<ELObjPart>;
#else
typedef CharMapColumn<ELObjPart> Dummy_105;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapResource<ELObjPart>
#else
#ifdef __xlC__
#pragma define(CharMapResource<ELObjPart>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapResource<ELObjPart>;
#else
typedef CharMapResource<ELObjPart> Dummy_106;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<CharMapResource<ELObjPart> >
#else
#ifdef __xlC__
#pragma define(Ptr<CharMapResource<ELObjPart> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<CharMapResource<ELObjPart> >;
#else
typedef Ptr<CharMapResource<ELObjPart> > Dummy_107;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template ConstPtr<CharMapResource<ELObjPart> >
#else
#ifdef __xlC__
#pragma define(ConstPtr<CharMapResource<ELObjPart> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class ConstPtr<CharMapResource<ELObjPart> >;
#else
typedef ConstPtr<CharMapResource<ELObjPart> > Dummy_108;
#endif
#endif
#endif
#ifndef _MSC_VER
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::Address>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::Address>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::Address>;
#else
typedef OneRefArgCall<FOTBuilder::Address> Dummy_109;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<char const *>
#else
#ifdef __xlC__
#pragma define(OneArgCall<char const *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<char const *>;
#else
typedef OneArgCall<char const *> Dummy_110;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::TableCellNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::TableCellNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::TableCellNIC>;
#else
typedef OneRefArgCall<FOTBuilder::TableCellNIC> Dummy_111;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<FOTBuilder::Symbol>
#else
#ifdef __xlC__
#pragma define(OneArgCall<FOTBuilder::Symbol>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<FOTBuilder::Symbol>;
#else
typedef OneArgCall<FOTBuilder::Symbol> Dummy_112;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<unsigned int>
#else
#ifdef __xlC__
#pragma define(OneArgCall<unsigned int>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<unsigned int>;
#else
typedef OneArgCall<unsigned int> Dummy_113;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<unsigned short>
#else
#ifdef __xlC__
#pragma define(OneArgCall<unsigned short>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<unsigned short>;
#else
typedef OneArgCall<unsigned short> Dummy_114;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::CharacterNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::CharacterNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::CharacterNIC>;
#else
typedef OneRefArgCall<FOTBuilder::CharacterNIC> Dummy_115;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<NodePtr>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<NodePtr>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<NodePtr>;
#else
typedef OneRefArgCall<NodePtr> Dummy_116;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::LeaderNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::LeaderNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::LeaderNIC>;
#else
typedef OneRefArgCall<FOTBuilder::LeaderNIC> Dummy_117;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<long>
#else
#ifdef __xlC__
#pragma define(OneArgCall<long>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<long>;
#else
typedef OneArgCall<long> Dummy_118;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::GridNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::GridNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::GridNIC>;
#else
typedef OneRefArgCall<FOTBuilder::GridNIC> Dummy_119;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::TableColumnNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::TableColumnNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::TableColumnNIC>;
#else
typedef OneRefArgCall<FOTBuilder::TableColumnNIC> Dummy_120;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::RuleNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::RuleNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::RuleNIC>;
#else
typedef OneRefArgCall<FOTBuilder::RuleNIC> Dummy_121;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::DisplayGroupNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::DisplayGroupNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::DisplayGroupNIC>;
#else
typedef OneRefArgCall<FOTBuilder::DisplayGroupNIC> Dummy_122;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<String<unsigned short> >
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<String<unsigned short> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<String<unsigned short> >;
#else
typedef OneRefArgCall<String<unsigned short> > Dummy_123;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::LengthSpec>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::LengthSpec>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::LengthSpec>;
#else
typedef OneRefArgCall<FOTBuilder::LengthSpec> Dummy_124;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::InlineNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::InlineNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::InlineNIC>;
#else
typedef OneRefArgCall<FOTBuilder::InlineNIC> Dummy_125;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::DisplayNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::DisplayNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::DisplayNIC>;
#else
typedef OneRefArgCall<FOTBuilder::DisplayNIC> Dummy_126;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::TableNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::TableNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::TableNIC>;
#else
typedef OneRefArgCall<FOTBuilder::TableNIC> Dummy_127;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<Vector<ConstPtr<FOTBuilder::GlyphSubstTable> > >
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<Vector<ConstPtr<FOTBuilder::GlyphSubstTable> > >)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<Vector<ConstPtr<FOTBuilder::GlyphSubstTable> > >;
#else
typedef OneRefArgCall<Vector<ConstPtr<FOTBuilder::GlyphSubstTable> > > Dummy_128;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::BoxNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::BoxNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::BoxNIC>;
#else
typedef OneRefArgCall<FOTBuilder::BoxNIC> Dummy_129;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::GridCellNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::GridCellNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::GridCellNIC>;
#else
typedef OneRefArgCall<FOTBuilder::GridCellNIC> Dummy_130;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::DeviceRGBColor>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::DeviceRGBColor>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::DeviceRGBColor>;
#else
typedef OneRefArgCall<FOTBuilder::DeviceRGBColor> Dummy_131;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::OptLengthSpec>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::OptLengthSpec>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::OptLengthSpec>;
#else
typedef OneRefArgCall<FOTBuilder::OptLengthSpec> Dummy_132;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneArgCall<bool>
#else
#ifdef __xlC__
#pragma define(OneArgCall<bool>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneArgCall<bool>;
#else
typedef OneArgCall<bool> Dummy_133;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::InlineSpace>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::InlineSpace>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::InlineSpace>;
#else
typedef OneRefArgCall<FOTBuilder::InlineSpace> Dummy_134;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::ExternalGraphicNIC>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::ExternalGraphicNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::ExternalGraphicNIC>;
#else
typedef OneRefArgCall<FOTBuilder::ExternalGraphicNIC> Dummy_135;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<CharMap<NCVector<CharProp::addedProp_>::size_type> >
#else
#ifdef __xlC__
#pragma define(Owner<CharMap<NCVector<CharProp::addedProp_>::size_type> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<CharMap<NCVector<CharProp::addedProp_>::size_type> >;
#else
typedef Owner<CharMap<NCVector<CharProp::addedProp_>::size_type> > Dummy_136;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<NCVector<CharProp::addedProp_>::size_type>
#else
#ifdef __xlC__
#pragma define(CharMap<NCVector<CharProp::addedProp_>::size_type>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<NCVector<CharProp::addedProp_>::size_type>;
#else
typedef CharMap<NCVector<CharProp::addedProp_>::size_type> Dummy_137;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<NCVector<CharProp::addedProp_>::size_type>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<NCVector<CharProp::addedProp_>::size_type>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<NCVector<CharProp::addedProp_>::size_type>;
#else
typedef CharMapColumn<NCVector<CharProp::addedProp_>::size_type> Dummy_138;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<NCVector<CharProp::addedProp_>::size_type>
#else
#ifdef __xlC__
#pragma define(CharMapPage<NCVector<CharProp::addedProp_>::size_type>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<NCVector<CharProp::addedProp_>::size_type>;
#else
typedef CharMapPage<NCVector<CharProp::addedProp_>::size_type> Dummy_139;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<CharProp::addedProp_>
#else
#ifdef __xlC__
#pragma define(NCVector<CharProp::addedProp_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<CharProp::addedProp_>;
#else
typedef NCVector<CharProp::addedProp_> Dummy_140;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<Ptr<ProcessContext::Validator> >
#else
#ifdef __xlC__
#pragma define(Vector<Ptr<ProcessContext::Validator> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<Ptr<ProcessContext::Validator> >;
#else
typedef Vector<Ptr<ProcessContext::Validator> > Dummy_141;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<ProcessContext::Validator>
#else
#ifdef __xlC__
#pragma define(Ptr<ProcessContext::Validator>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<ProcessContext::Validator>;
#else
typedef Ptr<ProcessContext::Validator> Dummy_142;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<FOTBuilder::OptInlineSpace>
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<FOTBuilder::OptInlineSpace>)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<FOTBuilder::OptInlineSpace>;
#else
typedef OneRefArgCall<FOTBuilder::OptInlineSpace> Dummy_143;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template NCVector<TransformationMode::Association>
#else
#ifdef __xlC__
#pragma define(NCVector<TransformationMode::Association>)
#else
#ifdef SP_ANSI_CLASS_INST
template class NCVector<TransformationMode::Association>;
#else
typedef NCVector<TransformationMode::Association> Dummy_144;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<MaybeIntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMap<MaybeIntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<MaybeIntegerCharPropValues::ValT_>;
#else
typedef CharMap<MaybeIntegerCharPropValues::ValT_> Dummy_145;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<MaybeIntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<MaybeIntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<MaybeIntegerCharPropValues::ValT_>;
#else
typedef CharMapColumn<MaybeIntegerCharPropValues::ValT_> Dummy_146;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<MaybeIntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapPage<MaybeIntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<MaybeIntegerCharPropValues::ValT_>;
#else
typedef CharMapPage<MaybeIntegerCharPropValues::ValT_> Dummy_147;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<ProcessContext::Validator *>
#else
#ifdef __xlC__
#pragma define(Vector<ProcessContext::Validator *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<ProcessContext::Validator *>;
#else
typedef Vector<ProcessContext::Validator *> Dummy_148;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<PublicIdCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMap<PublicIdCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<PublicIdCharPropValues::ValT_>;
#else
typedef CharMap<PublicIdCharPropValues::ValT_> Dummy_149;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<PublicIdCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<PublicIdCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<PublicIdCharPropValues::ValT_>;
#else
typedef CharMapColumn<PublicIdCharPropValues::ValT_> Dummy_150;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<PublicIdCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapPage<PublicIdCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<PublicIdCharPropValues::ValT_>;
#else
typedef CharMapPage<PublicIdCharPropValues::ValT_> Dummy_151;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Ptr<TransformationMode::Action>
#else
#ifdef __xlC__
#pragma define(Ptr<TransformationMode::Action>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Ptr<TransformationMode::Action>;
#else
typedef Ptr<TransformationMode::Action> Dummy_152;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<BooleanCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMap<BooleanCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<BooleanCharPropValues::ValT_>;
#else
typedef CharMap<BooleanCharPropValues::ValT_> Dummy_153;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<BooleanCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<BooleanCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<BooleanCharPropValues::ValT_>;
#else
typedef CharMapColumn<BooleanCharPropValues::ValT_> Dummy_154;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<BooleanCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapPage<BooleanCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<BooleanCharPropValues::ValT_>;
#else
typedef CharMapPage<BooleanCharPropValues::ValT_> Dummy_155;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<IntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMap<IntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<IntegerCharPropValues::ValT_>;
#else
typedef CharMap<IntegerCharPropValues::ValT_> Dummy_156;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<IntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<IntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<IntegerCharPropValues::ValT_>;
#else
typedef CharMapColumn<IntegerCharPropValues::ValT_> Dummy_157;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<IntegerCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapPage<IntegerCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<IntegerCharPropValues::ValT_>;
#else
typedef CharMapPage<IntegerCharPropValues::ValT_> Dummy_158;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<ELObj *>
#else
#ifdef __xlC__
#pragma define(CharMap<ELObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<ELObj *>;
#else
typedef CharMap<ELObj *> Dummy_159;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<ELObj *>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<ELObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<ELObj *>;
#else
typedef CharMapColumn<ELObj *> Dummy_160;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<ELObj *>
#else
#ifdef __xlC__
#pragma define(CharMapPage<ELObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<ELObj *>;
#else
typedef CharMapPage<ELObj *> Dummy_161;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMap<SymbolCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMap<SymbolCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMap<SymbolCharPropValues::ValT_>;
#else
typedef CharMap<SymbolCharPropValues::ValT_> Dummy_162;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapColumn<SymbolCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapColumn<SymbolCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapColumn<SymbolCharPropValues::ValT_>;
#else
typedef CharMapColumn<SymbolCharPropValues::ValT_> Dummy_163;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template CharMapPage<SymbolCharPropValues::ValT_>
#else
#ifdef __xlC__
#pragma define(CharMapPage<SymbolCharPropValues::ValT_>)
#else
#ifdef SP_ANSI_CLASS_INST
template class CharMapPage<SymbolCharPropValues::ValT_>;
#else
typedef CharMapPage<SymbolCharPropValues::ValT_> Dummy_164;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<CreateSpecObj *>
#else
#ifdef __xlC__
#pragma define(Vector<CreateSpecObj *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<CreateSpecObj *>;
#else
typedef Vector<CreateSpecObj *> Dummy_165;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Owner<String<unsigned short> >
#else
#ifdef __xlC__
#pragma define(Owner<String<unsigned short> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class Owner<String<unsigned short> >;
#else
typedef Owner<String<unsigned short> > Dummy_166;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template String<unsigned short>
#else
#ifdef __xlC__
#pragma define(String<unsigned short>)
#else
#ifdef SP_ANSI_CLASS_INST
template class String<unsigned short>;
#else
typedef String<unsigned short> Dummy_167;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<CharProp *>
#else
#ifdef __xlC__
#pragma define(Vector<CharProp *>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<CharProp *>;
#else
typedef Vector<CharProp *> Dummy_168;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template OneRefArgCall<Vector<FOTBuilder::CharacterNIC> >
#else
#ifdef __xlC__
#pragma define(OneRefArgCall<Vector<FOTBuilder::CharacterNIC> >)
#else
#ifdef SP_ANSI_CLASS_INST
template class OneRefArgCall<Vector<FOTBuilder::CharacterNIC> >;
#else
typedef OneRefArgCall<Vector<FOTBuilder::CharacterNIC> > Dummy_169;
#endif
#endif
#endif
#ifdef __DECCXX
#pragma define_template Vector<FOTBuilder::CharacterNIC>
#else
#ifdef __xlC__
#pragma define(Vector<FOTBuilder::CharacterNIC>)
#else
#ifdef SP_ANSI_CLASS_INST
template class Vector<FOTBuilder::CharacterNIC>;
#else
typedef Vector<FOTBuilder::CharacterNIC> Dummy_170;
#endif
#endif
#endif
#endif

#ifdef SP_NAMESPACE
}
#endif

#endif /* SP_MANUAL_INST */
