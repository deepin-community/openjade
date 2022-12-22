# 1 "GroveBuilder.cxx"
# 1 "/home/neil/debian/openjade1.4/1.4devel1/openjade-1.4devel1/spgrove//"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "GroveBuilder.cxx"





# 1 "../config.h" 1






# 1 "/usr/include/OpenSP/config.h" 1 3 4
# 8 "../config.h" 2
# 7 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Boolean.h" 1 3 4







namespace OpenSP {




typedef bool Boolean;

typedef bool PackedBoolean;
# 28 "/usr/include/OpenSP/Boolean.h" 3 4
}
# 8 "GroveBuilder.cxx" 2
# 1 "../grove/Node.h" 1






#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 152 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 11 "../grove/Node.h" 2
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 1 3 4
# 11 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 1 3 4
# 122 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 26 "/usr/include/limits.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 295 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 296 "/usr/include/features.h" 2 3 4
# 318 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 319 "/usr/include/features.h" 2 3 4
# 27 "/usr/include/limits.h" 2 3 4
# 144 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 130 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 36 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 37 "/usr/include/bits/local_lim.h" 2 3 4
# 131 "/usr/include/bits/posix1_lim.h" 2 3 4
# 145 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 149 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/xopen_lim.h" 1 3 4
# 34 "/usr/include/bits/xopen_lim.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 35 "/usr/include/bits/xopen_lim.h" 2 3 4
# 153 "/usr/include/limits.h" 2 3 4
# 123 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 2 3 4
# 8 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/syslimits.h" 2 3 4
# 12 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 2 3 4
# 12 "../grove/Node.h" 2
# 1 "/usr/include/OpenSP/IList.h" 1 3 4






# 1 "/usr/include/OpenSP/IListBase.h" 1 3 4






# 1 "/usr/include/OpenSP/Link.h" 1 3 4







namespace OpenSP {


class Link {
public:
  Link();
  Link(Link *);
  virtual ~Link();
private:
  Link *next_;

friend class IListBase;
friend class IListIterBase;
friend class IQueueBase;
};

inline
Link::Link() : next_(0)
{
}

inline
Link::Link(Link *next) : next_(next)
{
}


}
# 8 "/usr/include/OpenSP/IListBase.h" 2 3 4
# 1 "/usr/include/OpenSP/Boolean.h" 1 3 4
# 9 "/usr/include/OpenSP/IListBase.h" 2 3 4


namespace OpenSP {


class IListBase {
public:
  IListBase();
  IListBase(Link *);
  void append(Link *);
  void insert(Link *);
  Link *head() const;
  Boolean empty() const;
  Link *get();
  void remove(Link *);
  void swap(IListBase &);
  void clear();
private:
  Link *head_;
friend class IListIterBase;
};

inline
IListBase::IListBase() : head_(0)
{
}

inline
IListBase::IListBase(Link *head) : head_(head)
{
}

inline
void IListBase::insert(Link *p)
{
  p->next_ = head_;
  head_ = p;
}

inline
Link *IListBase::head() const
{
  return head_;
}

inline
Boolean IListBase::empty() const
{
  return head_ == 0;
}

inline
Link *IListBase::get()
{
  Link *tem = head_;
  head_ = head_->next_;
  return tem;
}

inline
void IListBase::swap(IListBase &list)
{
  Link *tem = head_;
  head_ = list.head_;
  list.head_ = tem;
}


}
# 8 "/usr/include/OpenSP/IList.h" 2 3 4


namespace OpenSP {


template<class T> class IListIter;



template<class T>
class IList : private IListBase {
public:
  IList() { }
  IList(T *p) : IListBase(p) { }
  ~IList() { clear(); }
  void append(T *p) { IListBase::append(p); }
  void insert(T *p) { IListBase::insert(p); }
  void remove(T *p) { IListBase::remove(p); }
  void swap(IList<T> &list) { IListBase::swap(list); }
  T *head() const { return (T *)IListBase::head(); }
  T *get() { return (T *)IListBase::get(); }
  IListBase::clear;
  IListBase::empty;
friend class IListIter<T>;
private:
  IList(const IList<T> &);
  IList<T> &operator=(const IList<T> &);
};


}
# 13 "../grove/Node.h" 2
# 35 "../grove/Node.h"
namespace OpenJade_Grove {




typedef unsigned int GroveChar;
# 49 "../grove/Node.h"
class NodePtr;
class NodeListPtr;
class NamedNodeListPtr;
class GroveString;
class NodeVisitor;
class SdataMapper;
class GroveStringList;
class GroveStringListPtr;

enum AccessResult {
  accessOK,
  accessNull,
  accessTimeout,
  accessNotInClass
};

struct ComponentName {
  enum Id {
    noId = -1,
    idAllPropertyNames,
    idAnd,
    idAny,
    idApplicationInfo,
    idAttributeAssignment,
    idAttributeDef,
    idAttributeDefs,
    idAttributes,
    idAttributeValueToken,
    idCapacity,
    idCdata,
    idChar,
    idCharset,
    idChildrenPropertyName,
    idClassName,
    idConnector,
    idConref,
    idContent,
    idContentTokens,
    idContentType,
    idCurrent,
    idCurrentAttributeIndex,
    idCurrentGroup,
    idDataChar,
    idDataPropertyName,
    idDataSepPropertyName,
    idDeclValueType,
    idDefaulted,
    idDefaultedEntities,
    idDefaultEntity,
    idDefaultValue,
    idDefaultValueType,
    idDoctypesAndLinktypes,
    idDocument,
    idDocumentElement,
    idDocumentType,
    idDtd,
    idElement,
    idElements,
    idElementToken,
    idElementType,
    idElementTypes,
    idEmpty,
    idEntities,
    idEntity,
    idEntityName,
    idEntityType,
    idEpilog,
    idExclusions,
    idExternalData,
    idExternalId,
    idFixed,
    idFormalPublicId,
    idGeneralEntities,
    idGeneratedSystemId,
    idGi,
    idGoverning,
    idGoverningDoctype,
    idGroveRoot,
    idId,
    idIdref,
    idIdrefs,
    idImplied,
    idIncluded,
    idInclusions,
    idIso,
    idLpd,
    idModelGroup,
    idMustOmitEndTag,
    idName,
    idNames,
    idNdata,
    idNmtkgrp,
    idNmtoken,
    idNmtokens,
    idNonsgml,
    idNotation,
    idNotationName,
    idNotations,
    idNumber,
    idNumbers,
    idNutoken,
    idNutokens,
    idOccurenceIndicator,
    idOmitEndTag,
    idOmitStartTag,
    idOpt,
    idOr,
    idOrigin,
    idOriginToSubnodeRelPropertyName,
    idOwnerId,
    idOwnerType,
    idParameterEntities,
    idParent,
    idPcdataToken,
    idPi,
    idPlus,
    idProlog,
    idPublicId,
    idRankGroup,
    idRankStem,
    idRankSuffix,
    idRcdata,
    idReferent,
    idRegistered,
    idRep,
    idRequired,
    idSdata,
    idSeq,
    idSgmlConstants,
    idSgmlDocument,
    idShortref,
    idStem,
    idSubdoc,
    idSubdocument,
    idSubnodePropertyNames,
    idSyntax,
    idSystemData,
    idSystemId,
    idText,
    idTextClass,
    idTextDescription,
    idTextDesignatingSequence,
    idTextDisplayVersion,
    idTextLanguage,
    idToken,
    idTokens,
    idTokenSep,
    idTreeRoot,
    idUnavailable,
    idUnregistered,
    idValue
  };
  enum { nIds = idValue + 1 };
  static const char *rcsName(Id);
  static const char *sdqlName(Id);
};

struct ClassDef {
  ComponentName::Id className;
  const ComponentName::Id *allPropertyNames;
  const ComponentName::Id *subnodePropertyNames;
  ComponentName::Id childrenPropertyName;
  ComponentName::Id dataPropertyName;
  ComponentName::Id dataSepPropertyName;

  static const ClassDef sgmlDocument;
  static const ClassDef sgmlConstants;
  static const ClassDef dataChar;
  static const ClassDef element;
  static const ClassDef attributeAssignment;
  static const ClassDef attributeDef;
  static const ClassDef attributeValueToken;
  static const ClassDef pi;
  static const ClassDef sdata;
  static const ClassDef documentType;
  static const ClassDef entity;
  static const ClassDef notation;
  static const ClassDef externalId;
  static const ClassDef externalData;
  static const ClassDef subdocument;
  static const ClassDef nonSgml;
  static const ClassDef message;
  static const ClassDef elementType;
  static const ClassDef modelGroup;
  static const ClassDef elementToken;
  static const ClassDef pcdataToken;
  static const ClassDef defaultEntity;
  static const ClassDef rankStem;
  static const ClassDef formalPublicId;
};

class PropertyValue;

class Node {
public:




  virtual AccessResult getOrigin(NodePtr &) const;
  virtual AccessResult getParent(NodePtr &) const;
  virtual AccessResult getGroveRoot(NodePtr &) const;
  virtual AccessResult getTreeRoot(NodePtr &) const;
  virtual AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &) const = 0;
  AccessResult getClassName(ComponentName::Id &) const;
  AccessResult getChildrenPropertyName(ComponentName::Id &) const;
  AccessResult getDataPropertyName(ComponentName::Id &) const;
  AccessResult getDataSepPropertyName(ComponentName::Id &) const;
  AccessResult getSubnodePropertyNames(const ComponentName::Id *&) const;
  AccessResult getAllPropertyNames(const ComponentName::Id *&) const;



  virtual void accept(NodeVisitor &) = 0;
  virtual const ClassDef &classDef() const = 0;

  virtual AccessResult children(NodeListPtr &) const = 0;
  virtual AccessResult follow(NodeListPtr &) const = 0;


  virtual AccessResult nextSibling(NodePtr &) const;


  virtual AccessResult nextChunkSibling(NodePtr &) const;

  virtual AccessResult nextChunkAfter(NodePtr &) const;
  virtual AccessResult charChunk(const SdataMapper &, GroveString &) const;


  virtual AccessResult firstChild(NodePtr &) const;


  virtual AccessResult firstSibling(NodePtr &) const;

  virtual AccessResult siblingsIndex(unsigned long &) const;

  virtual AccessResult attributeRef(unsigned long, NodePtr &) const;



  virtual AccessResult followSiblingRef(unsigned long, NodePtr &) const;


  virtual AccessResult tokens(GroveString &) const;




  virtual AccessResult elementIndex(unsigned long &) const;



  virtual unsigned long hash() const;

  virtual bool operator==(const Node &node) const = 0;
  bool operator!=(const Node &node) const { return !(*this == node); }

  virtual bool chunkContains(const Node &nd) const;
  bool sameGrove(const Node &node) const;
  typedef const char *IID;
  virtual bool queryInterface(IID, const void *&) const;

  virtual AccessResult getMessages(NodeListPtr &) const;

  enum Severity { info, warning, error };
  virtual AccessResult getSeverity(Severity &) const;
  AccessResult property(ComponentName::Id, const SdataMapper &, PropertyValue &) const;
  virtual unsigned groveIndex() const = 0;
public:
  virtual void addRef() = 0;


  virtual void release() = 0;
protected:


  virtual

    ~Node() { }
public:


  AccessResult getChar(const SdataMapper &, GroveChar &) const;


  virtual AccessResult getAttributes(NamedNodeListPtr &) const;
  virtual AccessResult getName(GroveString &) const;
  virtual AccessResult getSystemData(GroveString &) const;
  virtual AccessResult getEntity(NodePtr &) const;
  virtual AccessResult getEntityName(GroveString &) const;
  virtual AccessResult getExternalId(NodePtr &) const;
  virtual AccessResult getNotation(NodePtr &) const;
  virtual AccessResult getGi(GroveString &) const;
  struct OccurIndicator {
    enum Enum { opt, plus, rep };
  };
  virtual AccessResult getOccurIndicator(OccurIndicator::Enum &) const;
  virtual AccessResult getAttributeDefs(NamedNodeListPtr &) const;
  virtual AccessResult getText(GroveString &) const;
  virtual AccessResult getNotationName(GroveString &) const;
  struct EntityType {
    enum Enum { text, cdata, sdata, ndata, subdocument, pi };
  };
  virtual AccessResult getEntityType(EntityType::Enum &) const;

  virtual AccessResult getDefaulted(bool &) const;

  virtual AccessResult getPublicId(GroveString &) const;
  virtual AccessResult getSystemId(GroveString &) const;
  virtual AccessResult getGeneratedSystemId(GroveString &) const;
  virtual AccessResult getFormalPublicId(NodePtr &) const;

  virtual AccessResult getValue(NodeListPtr &) const;
  virtual AccessResult getTokenSep(GroveChar &) const;
  virtual AccessResult getImplied(bool &) const;
  virtual AccessResult getAttributeDef(NodePtr &) const;

  virtual AccessResult getCurrentAttributeIndex(long &) const;
  virtual AccessResult getCurrentGroup(NodeListPtr &) const;
  struct DeclValueType {
    enum Enum { cdata, entity, entities, id, idref, idrefs, name, names, nmtoken,
                nmtokens, number, numbers, nutoken, nutokens, notation, nmtkgrp };
  };
  virtual AccessResult getDeclValueType(DeclValueType::Enum &) const;
  struct DefaultValueType {
    enum Enum { value, fixed, required, current, conref, implied };
  };
  virtual AccessResult getDefaultValueType(DefaultValueType::Enum &) const;
  virtual AccessResult getDefaultValue(NodeListPtr &) const;
  virtual AccessResult getTokens(GroveStringListPtr &) const;

  virtual bool hasGi(GroveString) const;
  virtual AccessResult getId(GroveString &) const;
  virtual AccessResult getContent(NodeListPtr &) const;
  virtual AccessResult getIncluded(bool &) const;
  virtual AccessResult getMustOmitEndTag(bool &) const;
  virtual AccessResult getElementType(NodePtr &) const;

  struct ContentType {
    enum Enum { cdata, rcdata, empty, any, modelgrp };
  };
  virtual AccessResult getContentType(ContentType::Enum &) const;
  virtual AccessResult getExclusions(GroveStringListPtr &) const;
  virtual AccessResult getInclusions(GroveStringListPtr &) const;
  virtual AccessResult getModelGroup(NodePtr &) const;
  virtual AccessResult getOmitEndTag(bool &) const;
  virtual AccessResult getOmitStartTag(bool &) const;
  virtual AccessResult getRankGroup(GroveStringListPtr &) const;
  virtual AccessResult getRankStem(GroveString &) const;
  virtual AccessResult getRankSuffix(GroveString &) const;

  virtual AccessResult getElementTypes(NodeListPtr &) const;
  virtual AccessResult getStem(GroveString &) const;

  struct Connector {
    enum Enum { and_, or_, seq };
  };
  virtual AccessResult getConnector(Connector::Enum &) const;
  virtual AccessResult getContentTokens(NodeListPtr &) const;

  virtual AccessResult getToken(GroveString &) const;
  virtual AccessResult getReferent(NodePtr &) const;

  virtual AccessResult getGoverning(bool &) const;
  virtual AccessResult getGeneralEntities(NamedNodeListPtr &) const;
  virtual AccessResult getNotations(NamedNodeListPtr &) const;
  virtual AccessResult getElementTypes(NamedNodeListPtr &) const;
  virtual AccessResult getDefaultEntity(NodePtr &) const;
  virtual AccessResult getParameterEntities(NamedNodeListPtr &) const;

  virtual AccessResult getSgmlConstants(NodePtr &) const;
  virtual AccessResult getApplicationInfo(GroveString &) const;
  virtual AccessResult getProlog(NodeListPtr &) const;
  virtual AccessResult getEpilog(NodeListPtr &) const;
  virtual AccessResult getDocumentElement(NodePtr &) const;
  virtual AccessResult getElements(NamedNodeListPtr &) const;
  virtual AccessResult getEntities(NamedNodeListPtr &) const;
  virtual AccessResult getDefaultedEntities(NamedNodeListPtr &) const;
  virtual AccessResult getGoverningDoctype(NodePtr &) const;
  virtual AccessResult getDoctypesAndLinktypes(NamedNodeListPtr &) const;



  virtual AccessResult getNonSgml(unsigned long &) const;

  struct OwnerType {
    enum Enum { iso, registered, unregistered };
  };
  virtual AccessResult getOwnerType(OwnerType::Enum &) const;
  virtual AccessResult getOwnerId(GroveString &) const;
  struct TextClass {
    enum Enum {
      capacity,
      charset,
      document,
      dtd,
      elements,
      entities,
      lpd,
      nonsgml,
      notation,
      shortref,
      subdoc,
      syntax,
      text,
    };
  };
  virtual AccessResult getTextClass(TextClass::Enum &) const;
  virtual AccessResult getUnavailable(bool &) const;
  virtual AccessResult getTextDescription(GroveString &) const;
  virtual AccessResult getTextLanguage(GroveString &) const;
  virtual AccessResult getTextDesignatingSequence(GroveString &) const;
  virtual AccessResult getTextDisplayVersion(GroveString &) const;
};

class NodeList {
public:
  virtual AccessResult first(NodePtr &) const = 0;
  virtual AccessResult rest(NodeListPtr &) const = 0;
  virtual AccessResult chunkRest(NodeListPtr &) const = 0;


  virtual AccessResult ref(unsigned long i, NodePtr &) const;
  virtual void release() = 0;
  virtual void addRef() = 0;
protected:

  virtual

    ~NodeList() { }
};

class NamedNodeList {
public:

  virtual AccessResult namedNode(GroveString, NodePtr &) const = 0;



  virtual size_t normalize(GroveChar *, size_t) const = 0;


  virtual NodeListPtr nodeList() const = 0;


  virtual NodeListPtr nodeListNoOrder() const;
  enum Type {
    elements,
    attributes,
    entities,
    notations,
    doctypesAndLinktypes,
    elementTypes,
    attributeDefs
  };
  virtual Type type() const = 0;





  AccessResult nodeName(const NodePtr &, GroveString &) const;
  virtual void release() = 0;
  virtual void addRef() = 0;
protected:

  virtual

    ~NamedNodeList() { }
};

class NodePtr {
public:
  NodePtr() : node_(0) { }
  NodePtr(Node *node) : node_(node) { addRef(); }
  ~NodePtr() { release(); }
  NodePtr(const NodePtr &ptr) : node_(ptr.node_) { addRef(); }
  NodePtr &operator=(const NodePtr &ptr) {
    ptr.addRef();
    release();
    node_ = ptr.node_;
    return *this;
  }
  Node *operator->() const { return node_; }
  Node &operator*() const { return *node_; }
  AccessResult assignOrigin() { return node_->getOrigin(*this); }
  AccessResult assignFirstChild() { return node_->firstChild(*this); }
  AccessResult assignNextSibling() { return node_->nextSibling(*this); }
  AccessResult assignNextChunkSibling() {
    return node_->nextChunkSibling(*this);
  }
  AccessResult assignNextChunkAfter() {
    return node_->nextChunkAfter(*this);
  }
  AccessResult assignFirstSibling() { return node_->firstSibling(*this); }
  void assign(Node *node) {
    if (node)
      node->addRef();
    release();
    node_ = node;
  }
  void clear() { release(); node_ = 0; }
  operator bool() const { return node_ != 0; }
private:
  void addRef() const { if (node_) node_->addRef(); }
  void release() const { if (node_) node_->release(); }
  Node *node_;
};

class NodeListPtr {
public:
  NodeListPtr() : list_(0) { }
  NodeListPtr(NodeList *list) : list_(list) { addRef(); }
  ~NodeListPtr() { release(); }
  NodeListPtr(const NodeListPtr &ptr) : list_(ptr.list_) { addRef(); }
  NodeListPtr &operator=(const NodeListPtr &ptr) {
    ptr.addRef();
    release();
    list_ = ptr.list_;
    return *this;
  }
  AccessResult assignRest() { return list_->rest(*this); }
  AccessResult assignChunkRest() { return list_->chunkRest(*this); }
  NodeList *operator->() const { return list_; }
  NodeList &operator*() const { return *list_; }
  void assign(NodeList *list) {
    if (list)
      list->addRef();
    release();
    list_ = list;
  }
  void clear() { release(); list_ = 0; }
  operator bool() const { return list_ != 0; }
private:
  void addRef() const { if (list_) list_->addRef(); }
  void release() const { if (list_) list_->release(); }
  NodeList *list_;
};

class NamedNodeListPtr {
public:
  NamedNodeListPtr() : list_(0) { }
  NamedNodeListPtr(NamedNodeList *list) : list_(list) { addRef(); }
  ~NamedNodeListPtr() { release(); }
  NamedNodeListPtr(const NamedNodeListPtr &ptr) : list_(ptr.list_) { addRef(); }
  NamedNodeListPtr &operator=(const NamedNodeListPtr &ptr) {
    ptr.addRef();
    release();
    list_ = ptr.list_;
    return *this;
  }
  NamedNodeList *operator->() const { return list_; }
  NamedNodeList &operator*() const { return *list_; }
  void assign(NamedNodeList *list) {
    if (list)
      list->addRef();
    release();
    list_ = list;
  }
  void clear() { release(); list_ = 0; }
  operator bool() const { return list_ != 0; }
private:
  void addRef() const { if (list_) list_->addRef(); }
  void release() const { if (list_) list_->release(); }
  NamedNodeList *list_;
};

class GroveString {
public:
  typedef const GroveChar *const_iterator;
  GroveString() : data_(0), size_(0) { }
  GroveString(const GroveChar *data, size_t size)
    : data_(data), size_(size) { }
  size_t size() const { return size_; }
  const GroveChar *data() const { return data_; }
  void assign(const GroveChar *data, size_t size) {
    data_ = data;
    size_ = size;
  }
  bool operator==(const GroveString &str) const;
  bool operator!=(const GroveString &str) const { return !(*this == str); }
  GroveChar operator[](size_t i) const { return data_[i]; }
  const_iterator begin() const { return data_; }
  const_iterator end() const { return data_ + size_; }
private:
  const GroveChar *data_;
  size_t size_;
};

class GroveStringLink {
public:
  GroveStringLink( const GroveString &gs )
   : data_(gs), next_(0) { }
  friend class GroveStringList;
  friend class ConstGroveStringListIter;
private:
  GroveString data_;
  GroveStringLink *next_;
};

class GroveStringList;

class ConstGroveStringListIter {
public:
  friend class GroveStringList;
  ConstGroveStringListIter() : link_(0) { }
  ConstGroveStringListIter(const GroveStringList &list);
  int done() const { return link_ == 0; }
  const GroveString &cur() const { return link_->data_; }
  void next() { link_ = link_->next_; }
protected:
  void attach(const GroveStringLink *link) { link_ = link; }
  const GroveStringLink *link_;
};

class GroveStringList {
public:
  friend class ConstGroveStringListIter;
  GroveStringList() : head_(0), refCount_(0) { }
  ~GroveStringList();
  void append(const GroveString &gs);
  void release();
  void addRef();
  bool canReuse(GroveStringListPtr &ptr) const;
  AccessResult first(GroveString &) const;
  AccessResult rest(GroveStringListPtr &) const;
  const ConstGroveStringListIter &iter() { return iter_; }
private:
  unsigned refCount_;
  GroveStringLink *head_;
  ConstGroveStringListIter iter_;
};

class GroveStringListPtr {
public:
  GroveStringListPtr() : list_(0) { }
  GroveStringListPtr(GroveStringList *list) : list_(list) { addRef(); }
  ~GroveStringListPtr() { release(); }
  GroveStringListPtr(const GroveStringListPtr &ptr) : list_(ptr.list_) { addRef(); }
  GroveStringListPtr &operator=(const GroveStringListPtr &ptr) {
    ptr.addRef();
    release();
    list_ = ptr.list_;
    return *this;
  }
  GroveStringList *operator->() const { return list_; }
  GroveStringList &operator*() const { return *list_; }
  void assign(GroveStringList *list) {
    if (list)
      list->addRef();
    release();
    list_ = list;
  }
  void clear() { release(); list_ = 0; }
  operator bool() const { return list_ != 0; }
private:
  void addRef() const { if (list_) list_->addRef(); }
  void release() const { if (list_) list_->release(); }
  GroveStringList *list_;
};

class SdataMapper {
public:
  virtual ~SdataMapper();

  virtual bool sdataMap(GroveString name, GroveString text, GroveChar &) const;
};



class NodeVisitor {
public:
  virtual void sgmlDocument(Node &);
  virtual void sgmlConstants(Node &);
  virtual void dataChar(Node &);
  virtual void element(Node &);
  virtual void attributeAssignment(Node &);
  virtual void attributeDef(Node &);
  virtual void attributeValueToken(Node &);
  virtual void pi(Node &);
  virtual void sdata(Node &);
  virtual void documentType(Node &);
  virtual void entity(Node &);
  virtual void notation(Node &);
  virtual void externalId(Node &);
  virtual void externalData(Node &);
  virtual void subdocument(Node &);
  virtual void nonSgml(Node &);
  virtual void message(Node &);
  virtual void elementType(Node &);
  virtual void rankStem(Node &);
  virtual void modelGroup(Node &);
  virtual void elementToken(Node &);
  virtual void pcdataToken(Node &);
  virtual void defaultEntity(Node &);
  virtual void formalPublicId(Node &);
};

class PropertyValue {
public:
  virtual ~PropertyValue() { }
  virtual void set(const NodePtr &) = 0;
  virtual void set(const NodeListPtr &) = 0;
  virtual void set(const NamedNodeListPtr &) = 0;
  virtual void set(bool) = 0;
  virtual void set(GroveChar) = 0;
  virtual void set(GroveString) = 0;
  virtual void set(ComponentName::Id) = 0;
  virtual void set(const GroveStringListPtr &) = 0;
  virtual void set(const ComponentName::Id *) = 0;
  virtual void set(long) = 0;
};

inline
AccessResult Node::getChar(const SdataMapper &mapper, GroveChar &c) const
{
  GroveString str;
  AccessResult ret = charChunk(mapper, str);
  if (ret == accessOK)
    c = str[0];
  return ret;
}

inline
bool Node::sameGrove(const Node &node) const
{
  return groveIndex() == node.groveIndex();
}

inline
AccessResult Node::getClassName(ComponentName::Id &name) const
{
  name = classDef().className;
  return accessOK;
}

inline
AccessResult Node::getChildrenPropertyName(ComponentName::Id &name) const
{
  const ClassDef &def = classDef();
  if (def.childrenPropertyName == ComponentName::noId)
    return accessNull;
  name = def.childrenPropertyName;
  return accessOK;
}

inline
AccessResult Node::getDataPropertyName(ComponentName::Id &name) const
{
  const ClassDef &def = classDef();
  if (def.dataPropertyName == ComponentName::noId)
    return accessNull;
  name = def.dataPropertyName;
  return accessOK;
}

inline
AccessResult Node::getDataSepPropertyName(ComponentName::Id &name) const
{
  const ClassDef &def = classDef();
  if (def.dataSepPropertyName == ComponentName::noId)
    return accessNull;
  name = def.dataSepPropertyName;
  return accessOK;
}

inline
AccessResult Node::getSubnodePropertyNames(const ComponentName::Id *&names) const
{
  names = classDef().subnodePropertyNames;
  return accessOK;
}

inline
AccessResult Node::getAllPropertyNames(const ComponentName::Id *&names) const
{
   names = classDef().allPropertyNames;
   return accessOK;
}


}
# 9 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Resource.h" 1 3 4







namespace OpenSP {


class Resource {
public:
  Resource();
  Resource(const Resource &);
  int unref();
  void ref();
  int count() const;
private:
  int count_;
};

inline
Resource::Resource()
: count_(0)
{
}

inline
Resource::Resource(const Resource &)
: count_(0)
{
}

inline
int Resource::count() const
{
  return count_;
}

inline
int Resource::unref()
{
  return --count_ <= 0;
}

inline
void Resource::ref()
{
  ++count_;
}


}
# 10 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 13 "/usr/include/OpenSP/Ptr.h" 3 4
namespace OpenSP {


template<class T>
class Ptr {
public:
  Ptr() : ptr_(0) { }
  Ptr(T *ptr);
  ~Ptr();
  Ptr(const Ptr<T> &);
  Ptr<T> &operator=(const Ptr<T> &);
  Ptr<T> &operator=(T *);
  T *pointer() const { return ptr_; }
  T *operator->() const { return ptr_; }
  T &operator*() const { return *ptr_; }
  void swap(Ptr<T> &p) {
    T *tem = p.ptr_;
    p.ptr_ = ptr_;
    ptr_ = tem;
  }
  Boolean isNull() const { return ptr_ == 0; }

  void clear();
  Boolean operator==(const Ptr<T> &p) const {
    return ptr_ == p.ptr_;
  }
  Boolean operator!=(const Ptr<T> &p) const {
    return ptr_ != p.ptr_;
  }
  Boolean operator==(const T *p) const {
    return ptr_ == p;
  }
  Boolean operator!=(const T *p) const {
    return ptr_ != p;
  }
private:
  T *ptr_;
};

template<class T>
class ConstPtr : private Ptr<T> {
public:
  ConstPtr() { }
  ConstPtr(T *ptr) : Ptr<T>(ptr) { }
  ConstPtr(const Ptr<T> &p) : Ptr<T>(p) { }
  ConstPtr(const ConstPtr<T> &p) : Ptr<T>(p) { }
  ConstPtr<T> &operator=(const Ptr<T> &p) {
    Ptr<T>::operator=(p); return *this;
  }
  ConstPtr<T> &operator=(const ConstPtr<T> &p) {
    Ptr<T>::operator=(p); return *this;
  }
  ConstPtr<T> &operator=(T *p) {
    Ptr<T>::operator=(p); return *this;
  }
  const T *pointer() const { return Ptr<T>::pointer(); }
  const T *operator->() const { return Ptr<T>::pointer(); }
  const T &operator*() const { return *Ptr<T>::pointer(); }
  void swap(ConstPtr<T> &p) { Ptr<T>::swap(p); }
  Ptr<T>::isNull;
  Ptr<T>::clear;
  Boolean operator==(const Ptr<T> &p) const { return Ptr<T>::operator==(p); }
  Boolean operator!=(const Ptr<T> &p) const { return Ptr<T>::operator!=(p); }
  Boolean operator==(const ConstPtr<T> &p) const {
    return Ptr<T>::operator==(p);
  }
  Boolean operator!=(const ConstPtr<T> &p) const {
    return Ptr<T>::operator!=(p);
  }
};


}





# 1 "/usr/include/OpenSP/Ptr.cxx" 1 3 4







namespace OpenSP {


template<class T>
Ptr<T>::Ptr(T *ptr) : ptr_(ptr)
{
  if (ptr_)
    ptr_->ref();
}

template<class T>
Ptr<T>::~Ptr()
{
  if (ptr_) {
    if (ptr_->unref())
      delete ptr_;
    ptr_ = 0;
  }
}

template<class T>
Ptr<T>::Ptr(const Ptr<T> &p)
: ptr_(p.ptr_)
{
  if (p.ptr_)
    p.ptr_->ref();
}

template<class T>
Ptr<T> &Ptr<T>::operator=(const Ptr<T> &p)
{
  if (p.ptr_)
    p.ptr_->ref();
  if (ptr_ && ptr_->unref())
    delete ptr_;
  ptr_ = p.ptr_;
  return *this;
}

template<class T>
Ptr<T> &Ptr<T>::operator=(T *p)
{
  if (p)
    p->ref();
  if (ptr_ && ptr_->unref())
    delete ptr_;
  ptr_ = p;
  return *this;
}

template<class T>
void Ptr<T>::clear()
{
  if (ptr_) {
    if (ptr_->unref())
      delete ptr_;
    ptr_ = 0;
  }
}


}
# 92 "/usr/include/OpenSP/Ptr.h" 2 3 4
# 11 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/xnew.h" 1 3 4
# 20 "/usr/include/OpenSP/xnew.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/new" 1 3 4
# 41 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/new" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cstddef" 1 3 4
# 46 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cstddef" 3 4
       
# 47 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cstddef" 3

# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 49 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cstddef" 2 3

namespace std
{
  using ::ptrdiff_t;
  using ::size_t;
}
# 42 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/new" 2 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/exception" 1 3 4
# 40 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/exception" 3 4
#pragma GCC visibility push(default)

extern "C++" {

namespace std
{
# 54 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/exception" 3 4
  class exception
  {
  public:
    exception() throw() { }
    virtual ~exception() throw();


    virtual const char* what() const throw();
  };



  class bad_exception : public exception
  {
  public:
    bad_exception() throw() { }


    virtual ~bad_exception() throw();
  };


  typedef void (*terminate_handler) ();

  typedef void (*unexpected_handler) ();


  terminate_handler set_terminate(terminate_handler) throw();


  void terminate() __attribute__ ((__noreturn__));


  unexpected_handler set_unexpected(unexpected_handler) throw();


  void unexpected() __attribute__ ((__noreturn__));
# 102 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/exception" 3 4
  bool uncaught_exception() throw();
}

namespace __gnu_cxx
{
# 117 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/exception" 3 4
  void __verbose_terminate_handler ();
}

}

#pragma GCC visibility pop
# 43 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/new" 2 3 4

#pragma GCC visibility push(default)

extern "C++" {

namespace std
{





  class bad_alloc : public exception
  {
  public:
    bad_alloc() throw() { }


    virtual ~bad_alloc() throw();
  };

  struct nothrow_t { };
  extern const nothrow_t nothrow;


  typedef void (*new_handler)();

  new_handler set_new_handler(new_handler) throw();
}
# 84 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/new" 3 4
void* operator new(std::size_t) throw (std::bad_alloc);
void* operator new[](std::size_t) throw (std::bad_alloc);
void operator delete(void*) throw();
void operator delete[](void*) throw();
void* operator new(std::size_t, const std::nothrow_t&) throw();
void* operator new[](std::size_t, const std::nothrow_t&) throw();
void operator delete(void*, const std::nothrow_t&) throw();
void operator delete[](void*, const std::nothrow_t&) throw();


inline void* operator new(std::size_t, void* __p) throw() { return __p; }
inline void* operator new[](std::size_t, void* __p) throw() { return __p; }


inline void operator delete (void*, void*) throw() { }
inline void operator delete[](void*, void*) throw() { }

}

#pragma GCC visibility pop
# 21 "/usr/include/OpenSP/xnew.h" 2 3 4
# 12 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Event.h" 1 3 4






#pragma interface



# 1 "/usr/include/OpenSP/Allocator.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/Allocator.h" 2 3 4


namespace OpenSP {


class Allocator {
public:
  Allocator(size_t maxSize, unsigned blocksPerSegment);
  ~Allocator();
  void *alloc(size_t);
  static void *allocSimple(size_t);
  static void free(void *);


  union ForceAlign {
    unsigned long n;
    struct {
      char c;
    } s;
    char *cp;
    long *lp;
  };
  struct SegmentHeader;
  union BlockHeader;
  friend union BlockHeader;
  union BlockHeader {
    SegmentHeader *seg;
    ForceAlign align;
  };
  struct Block;
  friend struct Block;
  struct Block {
    BlockHeader header;
    Block *next;
  };
  friend struct SegmentHeader;
  struct SegmentHeader {
    union {
      Block **freeList;
      ForceAlign align;
    };
    unsigned liveCount;
    SegmentHeader *next;
  };
private:
  Allocator(const Allocator &);
  Allocator &operator=(const Allocator &);
  Block *freeList_;
  size_t objectSize_;
  unsigned blocksPerSegment_;
  SegmentHeader *segments_;
  void *alloc1();
  void tooBig(size_t);
};


}
# 12 "/usr/include/OpenSP/Event.h" 2 3 4
# 1 "/usr/include/OpenSP/Location.h" 1 3 4






#pragma interface


# 1 "/usr/include/OpenSP/types.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 1 3 4
# 8 "/usr/include/OpenSP/types.h" 2 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 9 "/usr/include/OpenSP/types.h" 2 3 4


namespace OpenSP {



typedef unsigned int Unsigned32;
typedef int Signed32;






typedef Unsigned32 Number;
typedef Unsigned32 Offset;
typedef Unsigned32 Index;



typedef Unsigned32 Char;
typedef Signed32 Xchar;
# 40 "/usr/include/OpenSP/types.h" 3 4
typedef Unsigned32 UnivChar;
typedef Unsigned32 WideChar;




typedef Unsigned32 SyntaxChar;

typedef unsigned short CharClassIndex;

typedef unsigned Token;


typedef unsigned short EquivCode;





}
# 11 "/usr/include/OpenSP/Location.h" 2 3 4

# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 13 "/usr/include/OpenSP/Location.h" 2 3 4
# 1 "/usr/include/OpenSP/Resource.h" 1 3 4
# 14 "/usr/include/OpenSP/Location.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/Vector.h" 2 3 4
# 1 "/usr/include/OpenSP/xnew.h" 1 3 4
# 9 "/usr/include/OpenSP/Vector.h" 2 3 4






namespace OpenSP {


template<class T>
class Vector {
public:
  typedef size_t size_type;
  typedef T *iterator;
  typedef const T *const_iterator;
  Vector() : ptr_(0), size_(0), alloc_(0) { }
  Vector(size_t n) : ptr_(0), size_(0), alloc_(0) { append(n); }
  virtual ~Vector();
  void resize(size_t n) {
    if (n < size_)
      erase(ptr_ + n, ptr_ + size_);
    else if (n > size_)
      append(n - size_);
  }

  Vector(size_t, const T &);
  Vector(const Vector<T> &);
  Vector<T> &operator=(const Vector<T> &);
  void assign(size_t, const T &);
  void push_back(const T &t) {
    reserve(size_ + 1);
    (void)new (ptr_ + size_) T(t);
    size_++;
  }
  void insert(const_iterator p, size_t n, const T &t);
  void insert(const_iterator p, const_iterator q1, const_iterator q2);

  void swap(Vector<T> &);
  void clear() { erase(ptr_, ptr_ + size_); }
  size_t size() const { return size_; }
  T &operator[](size_t i) { return ptr_[i]; }
  const T &operator[](size_t i) const { return ptr_[i]; }
  iterator begin() { return ptr_; }
  const_iterator begin() const { return ptr_; }
  T &back() { return ptr_[size_ - 1]; }
  const T &back() const { return ptr_[size_ - 1]; }
  void reserve(size_t n) { if (n > alloc_) reserve1(n); }
  iterator erase(const_iterator, const_iterator);
private:




  void append(size_t);
  void reserve1(size_t);

  size_t size_;
  T *ptr_;
  size_t alloc_;
};


}





# 1 "/usr/include/OpenSP/Vector.cxx" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/Vector.cxx" 2 3 4
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4
extern "C" {




# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4




extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n) throw ();


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     throw ();






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     throw ();





extern void *memset (void *__s, int __c, size_t __n) throw ();


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern void *memchr (__const void *__s, int __c, size_t __n)
      throw () __attribute__ ((__pure__));





extern void *rawmemchr (__const void *__s, int __c) throw () __attribute__ ((__pure__));


extern void *memrchr (__const void *__s, int __c, size_t __n)
      throw () __attribute__ ((__pure__));





extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();

extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n) throw ();


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     throw ();

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) throw ();


extern int strcmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern int strcoll (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));

extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n) throw ();






# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;
# 115 "/usr/include/string.h" 2 3 4


extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     throw () __attribute__ ((__pure__));

extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) throw ();




extern char *strdup (__const char *__s) throw () __attribute__ ((__malloc__));






extern char *strndup (__const char *__string, size_t __n)
     throw () __attribute__ ((__malloc__));
# 160 "/usr/include/string.h" 3 4


extern char *strchr (__const char *__s, int __c) throw () __attribute__ ((__pure__));

extern char *strrchr (__const char *__s, int __c) throw () __attribute__ ((__pure__));





extern char *strchrnul (__const char *__s, int __c) throw () __attribute__ ((__pure__));





extern size_t strcspn (__const char *__s, __const char *__reject)
     throw () __attribute__ ((__pure__));


extern size_t strspn (__const char *__s, __const char *__accept)
     throw () __attribute__ ((__pure__));

extern char *strpbrk (__const char *__s, __const char *__accept)
     throw () __attribute__ ((__pure__));

extern char *strstr (__const char *__haystack, __const char *__needle)
     throw () __attribute__ ((__pure__));



extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     throw ();




extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr) throw ();

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr) throw ();




extern char *strcasestr (__const char *__haystack, __const char *__needle)
     throw () __attribute__ ((__pure__));






extern void *memmem (__const void *__haystack, size_t __haystacklen,
       __const void *__needle, size_t __needlelen)
     throw () __attribute__ ((__pure__));



extern void *__mempcpy (void *__restrict __dest,
   __const void *__restrict __src, size_t __n) throw ();
extern void *mempcpy (void *__restrict __dest,
        __const void *__restrict __src, size_t __n) throw ();





extern size_t strlen (__const char *__s) throw () __attribute__ ((__pure__));





extern size_t strnlen (__const char *__string, size_t __maxlen)
     throw () __attribute__ ((__pure__));





extern char *strerror (int __errnum) throw ();




extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) throw ();




extern void __bzero (void *__s, size_t __n) throw ();



extern void bcopy (__const void *__src, void *__dest, size_t __n) throw ();


extern void bzero (void *__s, size_t __n) throw ();


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern char *index (__const char *__s, int __c) throw () __attribute__ ((__pure__));


extern char *rindex (__const char *__s, int __c) throw () __attribute__ ((__pure__));



extern int ffs (int __i) throw () __attribute__ ((__const__));




extern int ffsl (long int __l) throw () __attribute__ ((__const__));

__extension__ extern int ffsll (long long int __ll)
     throw () __attribute__ ((__const__));




extern int strcasecmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__));





extern int strcasecmp_l (__const char *__s1, __const char *__s2,
    __locale_t __loc) throw () __attribute__ ((__pure__));

extern int strncasecmp_l (__const char *__s1, __const char *__s2,
     size_t __n, __locale_t __loc)
     throw () __attribute__ ((__pure__));





extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim) throw ();




extern int strverscmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));


extern char *strsignal (int __sig) throw ();


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();



extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n) throw ();
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n) throw ();


extern char *strfry (char *__string) throw ();


extern void *memfrob (void *__s, size_t __n) throw ();






extern char *basename (__const char *__filename) throw ();
# 379 "/usr/include/string.h" 3 4
}
# 9 "/usr/include/OpenSP/Vector.cxx" 2 3 4


namespace OpenSP {


template<class T>
Vector<T>::~Vector()
{
  if (ptr_) {
    erase(ptr_, ptr_ + size_);
    ::operator delete((void *)ptr_);
  }
}



template<class T>
Vector<T>::Vector(const Vector<T> &v)
: ptr_(0), size_(0), alloc_(0)
{
  insert(ptr_ + size_, v.ptr_, v.ptr_ + v.size_);
}

template<class T>
Vector<T>::Vector(size_t n, const T &t)
: ptr_(0), size_(0), alloc_(0)
{
  insert(ptr_ + size_, n, t);
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
  if (&v != this) {
    size_t n = v.size_;
    if (n > size_) {
      n = size_;
      insert(ptr_ + size_, v.ptr_ + size_, v.ptr_ + v.size_);
    }
    else if (n < size_)
      erase(ptr_ + n, ptr_ + size_);
    while (n-- > 0)
      ptr_[n] = v.ptr_[n];
  }
  return *this;
}

template<class T>
void Vector<T>::assign(size_t n, const T &t)
{
  size_t sz = n;
  if (n > size_) {
    sz = size_;
    insert(ptr_ + size_, n - size_, t);
  }
  else if (n < size_)
    erase(ptr_ + n, ptr_ + size_);
  while (sz-- > 0)
    ptr_[sz] = t;
}

template<class T>
void Vector<T>::insert(const T *p, size_t n, const T &t)
{
  size_t i = p - ptr_;
  reserve(size_ + n);
  if (i != size_)
    memmove(ptr_ + i + n, ptr_ + i, (size_ - i)*sizeof(T));
  for (T *pp = ptr_ + i; n-- > 0; pp++) {
    (void)new (pp) T(t);
    size_++;
  }
}

template<class T>
void Vector<T>::insert(const T *p, const T *q1, const T *q2)
{
  size_t i = p - ptr_;
  size_t n = q2 - q1;
  reserve(size_ + n);
  if (i != size_)
    memmove(ptr_ + i + n, ptr_ + i, (size_ - i)*sizeof(T));
  for (T *pp = ptr_ + i; q1 != q2; q1++, pp++) {
    (void)new (pp) T(*q1);
    size_++;
  }
}



template<class T>
void Vector<T>::swap(Vector<T> &v)
{
  {
    T *tem = ptr_;
    ptr_ = v.ptr_;
    v.ptr_ = tem;
  }
  {
    size_t tem = size_;
    size_ = v.size_;
    v.size_ = tem;
  }
  {
    size_t tem = alloc_;
    alloc_ = v.alloc_;
    v.alloc_ = tem;
  }
}

template<class T>
void Vector<T>::append(size_t n)
{
  reserve(size_ + n);
  while (n-- > 0)
    (void)new (ptr_ + size_++) T;
}

template<class T>
T *Vector<T>::erase(const T *p1, const T *p2)
{
  typedef T X;
  for (const T *p = p1; p != p2; p++)
    ((X *)p)->~X();
  if (p2 != ptr_ + size_)
    memmove((T *)p1, p2, ((const T *)(ptr_ + size_) - p2)*sizeof(T));
  size_ -= p2 - p1;
  return (T *)p1;
}

template<class T>
void Vector<T>::reserve1(size_t size)
{


  size_t newAlloc = alloc_*2;
  if (size > newAlloc)
    newAlloc += size;
  void *p = ::operator new(newAlloc * sizeof(T));
  alloc_ = newAlloc;
  if (ptr_) {
    memcpy(p, ptr_, size_*sizeof(T));
    ::operator delete((void *)ptr_);
  }
  ptr_ = (T *)p;
}


}
# 78 "/usr/include/OpenSP/Vector.h" 2 3 4
# 16 "/usr/include/OpenSP/Location.h" 2 3 4
# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 12 "/usr/include/OpenSP/Owner.h" 3 4
namespace OpenSP {


template<class T>
class Owner {
public:
  Owner() : p_(0) { }
  Owner(T *p) : p_(p) { }
  virtual ~Owner();
  void operator=(T *p) {
    if (p_) del();
    p_ = p;
  }
  operator int() const { return p_ != 0; }
  T *pointer() const { return p_; }
  T *operator->() const { return p_; }
  T &operator*() const { return *p_; }
  void swap(Owner<T> &x) {
    T *tem = p_;
    p_ = x.p_;
    x.p_ = tem;
  }
  T *extract() {
    T *tem = p_;
    p_ = 0;
    return tem;
  }
  void clear() {
    if (p_) {
      del();
      p_ = 0;
    }
  }
private:
  Owner(const Owner<T> &);
  void operator=(const Owner<T> &o);
  void del();
  T *p_;
};


}





# 1 "/usr/include/OpenSP/Owner.cxx" 1 3 4







namespace OpenSP {


template<class T>
Owner<T>::~Owner()
{
  if (p_)
    delete p_;
}

template<class T>
void Owner<T>::del()
{
  delete p_;
}


}
# 60 "/usr/include/OpenSP/Owner.h" 2 3 4
# 17 "/usr/include/OpenSP/Location.h" 2 3 4
# 1 "/usr/include/OpenSP/StringC.h" 1 3 4







# 1 "/usr/include/OpenSP/StringOf.h" 1 3 4
# 14 "/usr/include/OpenSP/StringOf.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 15 "/usr/include/OpenSP/StringOf.h" 2 3 4




namespace OpenSP {


template<class T>
class String {
public:
  typedef size_t size_type;
  typedef T *iterator;
  typedef const T *const_iterator;
  String();
  ~String() { if (ptr_) delete [] ptr_; }
  String(const T *, size_t);
  String(const String<T> &);
  String<T> &operator=(const String<T> &);
  size_t size() const { return length_; }
  String<T> &assign(const T *, size_t);
  String<T> &insert(size_t i, const String<T> &s);
  void swap(String<T> &str);
  T operator[](size_t i) const { return ptr_[i]; }
  T &operator[](size_t i) { return ptr_[i]; }
  iterator begin() { return ptr_; }
  const_iterator begin() const { return ptr_; }
  const T *data() const { return ptr_; }
  String<T> &operator+=(T c) {
    if (length_ >= alloc_)
      grow(1);
    ptr_[length_++] = c;
    return *this;
  }
  String<T> &operator+=(const String<T> &s) {
    append(s.ptr_, s.length_);
    return *this;
  }
  String<T> &append(const T *, size_t);
  Boolean operator==(const String<T> &s) const {
    return (length_ == s.length_
     && (length_ == 0
  || (*ptr_ == *s.ptr_
      && (memcmp(ptr_ + 1, s.ptr_ + 1, (length_ - 1)*sizeof(T))
   == 0))));
  }
  Boolean operator!=(const String<T> &str) const {
    return !(*this == str);
  }
  void resize(size_t n);
private:
  void grow(size_t);
  T *ptr_;
  size_t length_;
  size_t alloc_;
};


}





# 1 "/usr/include/OpenSP/StringOf.cxx" 1 3 4







# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 9 "/usr/include/OpenSP/StringOf.cxx" 2 3 4


namespace OpenSP {


template<class T>
String<T>::String(const T *ptr, size_t length)
: length_(length), alloc_(length)
{
  if (length) {
    ptr_ = new T[length];
    memcpy(ptr_, ptr, length*sizeof(T));
  }
  else
    ptr_ = 0;
}

template<class T>
String<T>::String()
: ptr_(0), length_(0), alloc_(0)
{
}

template<class T>
String<T>::String(const String<T> &s)
: length_(s.length_), alloc_(s.length_)
{
  if (length_) {
    ptr_ = new T[length_];
    memcpy(ptr_, s.ptr_, length_*sizeof(T));
  }
  else
    ptr_ = 0;
}

template<class T>
String<T> &String<T>::operator=(const String<T> &s)
{
  if (&s != this) {
    if (s.length_ > alloc_) {
      T *oldPtr = ptr_;
      ptr_ = new T[alloc_ = s.length_];
      if (oldPtr)
 delete [] oldPtr;
    }
    memcpy(ptr_, s.ptr_, s.length_*sizeof(T));
    length_ = s.length_;
  }
  return *this;
}

template<class T>
String<T> &String<T>::insert(size_t i, const String<T> &s)
{
  if (length_ + s.length_ > alloc_)
    grow(s.length_);
  for (size_t n = length_ - i; n > 0; n--)
    ptr_[i + n - 1 + s.length_] = ptr_[i + n - 1];
  length_ += s.length_;
  memcpy(ptr_ + i, s.ptr_, s.length_*sizeof(T));
  return *this;
}

template<class T>
String<T> &String<T>::append(const T *p, size_t length)
{
  if (length_ + length > alloc_)
    grow(length);
  memcpy(ptr_ + length_, p, length*sizeof(T));
  length_ += length;
  return *this;
}

template<class T>
void String<T>::grow(size_t n)
{
  size_t newAlloc = alloc_;
  if (alloc_ < n)
    newAlloc += n + 16;
  else
    newAlloc += alloc_;
  T *s = new T[newAlloc];
  memcpy(s, ptr_, length_*sizeof(T));
  delete [] ptr_;
  ptr_ = s;
  alloc_ = newAlloc;
}

template<class T>
void String<T>::swap(String<T> &to)
{
  {
    T *tem = to.ptr_;
    to.ptr_ = ptr_;
    ptr_ = tem;
  }
  {
    size_t tem = to.length_;
    to.length_ = length_;
    length_ = tem;
  }
  {
    size_t tem = to.alloc_;
    to.alloc_ = alloc_;
    alloc_ = tem;
  }
}

template<class T>
String<T> &String<T>::assign(const T *p, size_t n)
{
  if (alloc_ < n) {
    T *oldPtr = ptr_;
    ptr_ = new T[n];
    alloc_ = n;
    if (oldPtr)
      delete [] oldPtr;
  }
  length_ = n;
  for(T *to = ptr_; n > 0; n--, to++, p++)
    *to = *p;
  return *this;
}

template<class T>
void String<T>::resize(size_t n)
{
  if (alloc_ < n) {
    T *oldPtr = ptr_;
    ptr_ = new T[n];
    alloc_ = n;
    if (length_ > 0) {
      memcpy(ptr_, oldPtr, length_*sizeof(T));
      delete [] oldPtr;
    }
  }
  length_ = n;
}


}
# 79 "/usr/include/OpenSP/StringOf.h" 2 3 4
# 9 "/usr/include/OpenSP/StringC.h" 2 3 4


namespace OpenSP {


typedef String<Char> StringC;


}
# 18 "/usr/include/OpenSP/Location.h" 2 3 4
# 1 "/usr/include/OpenSP/rtti.h" 1 3 4
# 19 "/usr/include/OpenSP/Location.h" 2 3 4


namespace OpenSP {


class ExternalInfo;
class EntityOrigin;
class InputSourceOrigin;
class Entity;
class EntityDecl;
class Location;
class Markup;
class Text;
class NamedCharRef;

class Origin : public Resource {
public:
  virtual ~Origin();
  virtual const EntityOrigin *asEntityOrigin() const;
  virtual const InputSourceOrigin *asInputSourceOrigin() const;
  virtual const Location &parent() const = 0;
  virtual Index refLength() const;
  virtual Boolean origChars(const Char *&) const;
  virtual Boolean inBracketedTextOpenDelim() const;
  virtual Boolean inBracketedTextCloseDelim() const;
  virtual Boolean isNumericCharRef(const Markup *&markup) const;
  virtual Boolean isNamedCharRef(Index ind, NamedCharRef &ref) const;
  virtual const EntityDecl *entityDecl() const;
  virtual Boolean defLocation(Offset off, const Origin *&, Index &) const;
  virtual const Markup *markup() const;
  virtual const Entity *entity() const;
  virtual const ExternalInfo *externalInfo() const;
  virtual Offset startOffset(Index ind) const;
  const StringC *entityName() const;
};

class ProxyOrigin : public Origin {
public:
  ProxyOrigin(const Origin *origin);
  const EntityOrigin *asEntityOrigin() const;
  const InputSourceOrigin *asInputSourceOrigin() const;
  const Location &parent() const;
  Index refLength() const;
  Boolean origChars(const Char *&) const;
  Boolean inBracketedTextOpenDelim() const;
  Boolean inBracketedTextCloseDelim() const;
  Boolean isNumericCharRef(const Markup *&markup) const;
  Boolean isNamedCharRef(Index ind, NamedCharRef &ref) const;
  const EntityDecl *entityDecl() const;
  Boolean defLocation(Offset off, const Origin *&, Index &) const;
  const Markup *markup() const;
  const Entity *entity() const;
  const ExternalInfo *externalInfo() const;
  Offset startOffset(Index ind) const;
private:
  const Origin *origin_;
};

class Location {
public:
  Location();
  Location(Origin *, Index);
  Location(ConstPtr<Origin>, Index);
  void operator+=(Index i) { index_ += i; }
  void operator-=(Index i) { index_ -= i; }
  Index index() const { return index_; }
  const ConstPtr<Origin> &origin() const { return origin_; }
  void clear() { origin_.clear(); }
  void swap(Location &to) {
    origin_.swap(to.origin_);
    Index tem = to.index_;
    to.index_ = index_;
    index_ = tem;
  }
private:
  ConstPtr<Origin> origin_;
  Index index_;
};

class ExternalInfo {
 
public:
  virtual ~ExternalInfo();
};

class NamedCharRef {
public:
  enum RefEndType {
    endOmitted,
    endRE,
    endRefc
    };
  NamedCharRef();
  NamedCharRef(Index, RefEndType, const StringC &);
  Index refStartIndex() const;
  RefEndType refEndType() const;
  const StringC &origName() const;
  void set(Index, RefEndType, const Char *, size_t);
private:
  Index refStartIndex_;
  RefEndType refEndType_;
  StringC origName_;
};

struct InputSourceOriginNamedCharRef {
  Index replacementIndex;
  size_t origNameOffset;
  Index refStartIndex;
  NamedCharRef::RefEndType refEndType;
};

class InputSourceOrigin : public Origin {
public:
  virtual void noteCharRef(Index replacementIndex, const NamedCharRef &) = 0;
  virtual void setExternalInfo(ExternalInfo *) = 0;
  virtual InputSourceOrigin *copy() const = 0;
  static InputSourceOrigin *make();
  static InputSourceOrigin *make(const Location &refLocation);
};



class BracketOrigin : public Origin {
public:
  enum Position { open, close };
  BracketOrigin(const Location &, Position);
  const Location &parent() const;
  Boolean inBracketedTextOpenDelim() const;
  Boolean inBracketedTextCloseDelim() const;
private:
  Position pos_;
  Location loc_;
};

class ReplacementOrigin : public Origin {
public:
  ReplacementOrigin(const Location &, Char origChar);
  const Location &parent() const;
  Boolean origChars(const Char *&) const;
private:
  Location loc_;
  Char origChar_;
};

class MultiReplacementOrigin : public Origin {
public:
  MultiReplacementOrigin(const Location &, StringC &origChars);
  const Location &parent() const;
  Boolean origChars(const Char *&) const;
private:
  Location loc_;
  StringC origChars_;
};

inline
Index NamedCharRef::refStartIndex() const
{
  return refStartIndex_;
}

inline
NamedCharRef::RefEndType NamedCharRef::refEndType() const
{
  return refEndType_;
}

inline
const StringC &NamedCharRef::origName() const
{
  return origName_;
}


}
# 13 "/usr/include/OpenSP/Event.h" 2 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 14 "/usr/include/OpenSP/Event.h" 2 3 4
# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 15 "/usr/include/OpenSP/Event.h" 2 3 4


# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 18 "/usr/include/OpenSP/Event.h" 2 3 4

# 1 "/usr/include/OpenSP/Notation.h" 1 3 4






#pragma interface


# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 11 "/usr/include/OpenSP/Notation.h" 2 3 4

# 1 "/usr/include/OpenSP/NamedResource.h" 1 3 4






# 1 "/usr/include/OpenSP/Named.h" 1 3 4
# 10 "/usr/include/OpenSP/Named.h" 3 4
namespace OpenSP {


class Named {
public:
  Named(const StringC &name) : name_(name) { }
  virtual ~Named() { }
  const StringC &name() const { return name_; }
  const StringC *namePointer() const { return &name_; }
  void setName(const StringC &name) { name_ = name; }
  void swap(Named &to) { name_.swap(to.name_); }
private:
  StringC name_;
};


}
# 8 "/usr/include/OpenSP/NamedResource.h" 2 3 4



namespace OpenSP {


class NamedResource : public Named, public Resource {
public:
  NamedResource(const StringC &str) : Named(str) { }
};


}
# 13 "/usr/include/OpenSP/Notation.h" 2 3 4

# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 15 "/usr/include/OpenSP/Notation.h" 2 3 4
# 1 "/usr/include/OpenSP/ExternalId.h" 1 3 4






#pragma interface




# 1 "/usr/include/OpenSP/Text.h" 1 3 4






#pragma interface




# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 13 "/usr/include/OpenSP/Text.h" 2 3 4

# 1 "/usr/include/OpenSP/SubstTable.h" 1 3 4
# 9 "/usr/include/OpenSP/SubstTable.h" 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 10 "/usr/include/OpenSP/SubstTable.h" 2 3 4


namespace OpenSP {


class SubstTable {
public:
  SubstTable();
  void addSubst(Char from, Char to);
  void subst(Char &) const;
  void subst(StringC &) const;
  Char operator[](Char from) const;
  void sort() const;
  Char at(Char from) const;
  StringC inverse(Char to) const;
  void inverseTable(SubstTable &) const;
  struct Pair {
    Pair() {}
    Pair(Char f, Char t) : from(f), to(t) {}
    Char from;
    Char to;
  };
private:
  Char lo_[256];
  mutable Vector<Pair> map_;
  mutable bool isSorted_;
};

inline
void SubstTable::subst(StringC &str) const
{
  for (size_t i = 0; i < str.size(); i++)
    subst(str[i]);
}

inline
Char SubstTable::operator[](Char t) const
{
  if (t < 256)
    return lo_[t];
  else
    return at(t);
}

inline
void SubstTable::subst(Char &c) const
{
  c = operator[](c);
}


}
# 15 "/usr/include/OpenSP/Text.h" 2 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 16 "/usr/include/OpenSP/Text.h" 2 3 4


namespace OpenSP {


struct TextItem {
  TextItem();
  enum Type {
    data,
    cdata,
    sdata,
    nonSgml,
    entityStart,
    entityEnd,
    startDelim,
    endDelim,
    endDelimA,
    ignore
    };
  Type type;

  Char c;







  Location loc;

  size_t index;
};



class Text {
public:
  Text();

  ~Text();
  void clear();
  void swap(Text &to);
  void addChar(Char c, const Location &);
  void addChars(const StringC &, const Location &);
  void addChars(const Char *, size_t, const Location &);
  void insertChars(const StringC &, const Location &);
  void ignoreChar(Char, const Location &);
  void ignoreLastChar();
  void addNonSgmlChar(Char c, const Location &);
  void addEntityStart(const Location &);
  void addEntityEnd(const Location &);
  void addCdata(const StringC &, const ConstPtr<Origin> &);
  void addSdata(const StringC &, const ConstPtr<Origin> &);
  void addStartDelim(const Location &loc);
  void addEndDelim(const Location &loc, Boolean lita);
  void subst(const SubstTable &, Char space);
  void addCharsTokenize(const Char *, size_t, const Location &loc, Char space);
  void addCharsTokenize(const StringC &, const Location &loc, Char space);
  void tokenize(Char space, Text &text) const;
  Location charLocation(size_t i) const;
  Boolean charLocation(size_t, const Origin *&, Index &) const;
  Boolean charLocation(size_t i, const ConstPtr<Origin> *&, Index &) const;
  size_t size() const;
  Char lastChar() const;
  const StringC &string() const;
  size_t normalizedLength(size_t normsep) const;
  Boolean fixedEqual(const Text &) const;

  Boolean startDelimLocation(Location &) const;

  Boolean endDelimLocation(Location &) const;

  Boolean delimType(Boolean &lita) const;
private:
  void addSimple(TextItem::Type, const Location &);
  StringC chars_;
  Vector<TextItem> items_;
  friend class TextIter;
};

class TextIter {
public:
  TextIter(const Text &);
  void rewind();
  Boolean next(TextItem::Type &, const Char *&, size_t &,
        const Location *&);

  Boolean valid() const;
  void advance();
  TextItem::Type type() const;
  const Location &location() const;
  const Char *chars(size_t &length) const;
private:
  const TextItem *ptr_;
  const Text *text_;
};

inline
size_t Text::size() const
{
  return chars_.size();
}

inline
Char Text::lastChar() const
{
  return chars_[chars_.size() - 1];
}

inline
const StringC &Text::string() const
{
  return chars_;
}

inline
void Text::addEntityStart(const Location &loc)
{
  addSimple(TextItem::entityStart, loc);
}

inline
void Text::addEntityEnd(const Location &loc)
{
  addSimple(TextItem::entityEnd, loc);
}

inline
void Text::addChars(const StringC &s, const Location &loc)
{
  addChars(s.data(), s.size(), loc);
}

inline
void Text::addStartDelim(const Location &loc)
{
  addSimple(TextItem::startDelim, loc);
}

inline
void Text::addEndDelim(const Location &loc, Boolean lita)
{
  addSimple(lita ? TextItem::endDelimA : TextItem::endDelim,
     loc);
}

inline
void Text::addCharsTokenize(const StringC &str, const Location &loc,
       Char space)
{
  addCharsTokenize(str.data(), str.size(), loc, space);
}

inline
Location Text::charLocation(size_t i) const
{
  const ConstPtr<Origin> *originP;
  Index index;
  if (charLocation(i, originP, index))
    return Location(*originP, index);
  else
    return Location();
}

inline
Boolean Text::charLocation(size_t i, const Origin *&origin, Index &index) const
{
  const ConstPtr<Origin> *originP;
  if (charLocation(i, originP, index)) {
    origin = originP->pointer();
    return 1;
  }
  else
    return 0;
}

inline
void TextIter::rewind()
{
  ptr_ = text_->items_.begin();
}

inline
void TextIter::advance()
{
  ptr_++;
}

inline
Boolean TextIter::valid() const
{
  return ptr_ != (text_->items_.begin() + text_->items_.size());
}

inline
const Location &TextIter::location() const
{
  return ptr_->loc;
}

inline
TextItem::Type TextIter::type() const
{
  return ptr_->type;
}


}
# 13 "/usr/include/OpenSP/ExternalId.h" 2 3 4

# 1 "/usr/include/OpenSP/Message.h" 1 3 4







#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 12 "/usr/include/OpenSP/Message.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 14 "/usr/include/OpenSP/Message.h" 2 3 4
# 1 "/usr/include/OpenSP/CopyOwner.h" 1 3 4






# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 8 "/usr/include/OpenSP/CopyOwner.h" 2 3 4


namespace OpenSP {


template<class T>
class CopyOwner : public Owner<T> {
public:
  CopyOwner() { }
  CopyOwner(T *p) : Owner<T>(p) { }
  CopyOwner(const CopyOwner<T> &);
  void operator=(const CopyOwner<T> &o);
  void operator=(T *p) { Owner<T>::operator=(p); }
};


}





# 1 "/usr/include/OpenSP/CopyOwner.cxx" 1 3 4







namespace OpenSP {


template<class T>
CopyOwner<T>::CopyOwner(const CopyOwner<T> &o)
: Owner<T>(o.pointer() ? o.pointer()->copy() : 0)
{
}

template<class T>
void CopyOwner<T>::operator=(const CopyOwner<T> &o)
{
  Owner<T>::operator=(o.pointer() ? o.pointer()->copy() : 0);
}


}
# 31 "/usr/include/OpenSP/CopyOwner.h" 2 3 4
# 15 "/usr/include/OpenSP/Message.h" 2 3 4


# 1 "/usr/include/OpenSP/MessageArg.h" 1 3 4






#pragma interface



# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 12 "/usr/include/OpenSP/MessageArg.h" 2 3 4



namespace OpenSP {


class MessageBuilder;

class MessageArg {
public:
  MessageArg();
  virtual ~MessageArg();
  virtual MessageArg *copy() const = 0;
  virtual void append(MessageBuilder &) const = 0;
};

class StringMessageArg : public MessageArg {
public:
  StringMessageArg(const StringC &);
  MessageArg *copy() const;
  void append(MessageBuilder &) const;
private:
  StringC s_;
};

class NumberMessageArg : public MessageArg {
public:
  NumberMessageArg(unsigned long);
  MessageArg *copy() const;
  void append(MessageBuilder &) const;
private:
  unsigned long n_;
};

class OrdinalMessageArg : public MessageArg {
public:
  OrdinalMessageArg(unsigned long);
  MessageArg *copy() const;
  void append(MessageBuilder &) const;
private:
  unsigned long n_;
};

class OtherMessageArg : public MessageArg {
 
public:
  OtherMessageArg();
  void append(MessageBuilder &) const;
};

class StringVectorMessageArg : public MessageArg {
public:
  StringVectorMessageArg(const Vector<StringC> &);
  MessageArg *copy() const;
  void append(MessageBuilder &) const;
private:
  Vector<StringC> v_;
};



}
# 18 "/usr/include/OpenSP/Message.h" 2 3 4


namespace OpenSP {


class MessageModule;
extern MessageModule libModule;
extern MessageModule appModule;

class MessageFragment {
public:
  MessageFragment(const MessageModule *module, unsigned number, const char *text = 0);
  const MessageModule *module() const;
  unsigned number() const;
  const char *text() const;
private:
  unsigned short number_;
  const MessageModule * module_;
protected:
  unsigned char spare_;
private:

  const char *text_;

};

class MessageType : public MessageFragment {
public:
  enum Severity {
    info,
    warning,
    quantityError,
    idrefError,
    error
    };
  MessageType(Severity = info, const MessageModule *module = &libModule,
       unsigned number = unsigned(-1),
       const char *text = 0, const char *clauses = 0,
              const char *auxText = 0);
  Severity severity() const;
  MessageFragment auxFragment() const;
  Boolean isError() const;
  const char *clauses() const;
private:

  const char *clauses_;
  const char *auxText_;

};


class MessageType0 : public MessageType {
public:
  MessageType0(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType1 : public MessageType {
public:
  MessageType1(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType2 : public MessageType {
public:
  MessageType2(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType3 : public MessageType {
public:
  MessageType3(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType4 : public MessageType {
public:
  MessageType4(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType5 : public MessageType {
public:
  MessageType5(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType6 : public MessageType {
public:
  MessageType6(Severity = info, const MessageModule *module = &libModule,
        unsigned number = unsigned(-1), const char *text = 0,
               const char *clauses = 0);
};

class MessageType0L : public MessageType {
public:
  MessageType0L(Severity = info, const MessageModule *module = &libModule,
  unsigned number = unsigned(-1), const char *text = 0,
  const char *clauses = 0, const char *auxText = 0);
};

class MessageType1L : public MessageType {
public:
  MessageType1L(Severity = info, const MessageModule *module = &libModule,
  unsigned number = unsigned(-1), const char *text = 0,
  const char *clauses = 0, const char *auxText = 0);
};

class OpenElementInfo {
public:
  OpenElementInfo();
  PackedBoolean included;
  StringC gi;
  StringC matchType;
  unsigned matchIndex;
};

class Message {
public:
  Message();
  Message(int nArgs);
  const MessageType *type;
  Location loc;
  Location auxLoc;
  Vector<CopyOwner<MessageArg> > args;
  Vector<OpenElementInfo> openElementInfo;
  void swap(Message &);
  Boolean isError() const;
};

class Messenger {
public:
  Messenger();
  virtual ~Messenger();
  void message(const MessageType0 &);
  void message(const MessageType1 &, const MessageArg &);
  void message(const MessageType2 &,
        const MessageArg &,
        const MessageArg &);
  void message(const MessageType3 &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &);
  void message(const MessageType4 &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &);
  void message(const MessageType5 &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &);
  void message(const MessageType6 &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &,
        const MessageArg &);
  void message(const MessageType0L &, const Location &);
  void message(const MessageType1L &, const MessageArg &, const Location &);
  void setNextLocation(const Location &);
  virtual void initMessage(Message &);
  virtual void dispatchMessage(const Message &) = 0;
  virtual void dispatchMessage(Message &);
private:
  void doInitMessage(Message &);
  Boolean haveNextLocation_;
  Location nextLocation_;
};

class ForwardingMessenger : public Messenger {
public:
  ForwardingMessenger(Messenger &);
  void dispatchMessage(const Message &);
  void dispatchMessage(Message &);
  void initMessage(Message &);
private:
  Messenger *to_;
};

class ParentLocationMessenger : public ForwardingMessenger {
public:
  ParentLocationMessenger(Messenger &);
  void initMessage(Message &);
};

class NullMessenger : public Messenger {
public:
  NullMessenger();
  void dispatchMessage(const Message &);
};

inline
const MessageModule *MessageFragment::module() const
{
  return module_;
}

inline
unsigned MessageFragment::number() const
{
  return number_;
}

inline
const char *MessageFragment::text() const
{



  return text_;

}

inline
MessageType::Severity MessageType::severity() const
{
  return Severity(spare_);
}

inline
MessageFragment MessageType::auxFragment() const
{
  return MessageFragment(module(),
    number() + 1,



    auxText_

    );
}

inline
Boolean MessageType::isError() const
{
  return severity() != info && severity() != warning;
}

inline
const char *MessageType::clauses() const
{



  return clauses_;

}

inline
Boolean Message::isError() const
{
  return type->isError();
}


}
# 15 "/usr/include/OpenSP/ExternalId.h" 2 3 4


namespace OpenSP {


class CharsetInfo;

class PublicId {
public:
  enum Type {
    informal,
    fpi,
    urn
  };
  enum TextClass {
    CAPACITY,
    CHARSET,
    DOCUMENT,
    DTD,
    ELEMENTS,
    ENTITIES,
    LPD,
    NONSGML,
    NOTATION,
    SD,
    SHORTREF,
    SUBDOC,
    SYNTAX,
    TEXT
  };
  enum OwnerType {
    ISO,
    registered,
    unregistered
    };
  PublicId();

  Boolean getOwnerType(OwnerType &) const;
  Boolean getOwner(StringC &) const;
  Boolean getTextClass(TextClass &) const;
  Boolean getUnavailable(Boolean &) const;
  Boolean getDescription(StringC &) const;
  Boolean getLanguage(StringC &) const;
  Boolean getDesignatingSequence(StringC &) const;
  Boolean getDisplayVersion(StringC &) const;

  Boolean getNamespaceIdentifier(StringC &) const;
  Boolean getNamespaceSpecificString(StringC &) const;



  Type init(Text &, const CharsetInfo &, Char space,
        const MessageType1 *&fpierror,
               const MessageType1 *&urnerror);
  const StringC &string() const;
  const Text &text() const;
  const Type type() const { return type_; }
private:
  Boolean initFpi(const StringC &, const CharsetInfo &, Char,
               const MessageType1 *&);
  Boolean initUrn(const StringC &, const CharsetInfo &, Char,
               const MessageType1 *&);
  static Boolean nextField(Char solidus,
      const Char *&next,
      const Char *lim,
      const Char *&fieldStart,
      size_t &fieldLength,
                           Boolean dup = 1);
  static Boolean lookupTextClass(const StringC &, const CharsetInfo &,
     TextClass &);
  static const char *const textClasses[];

  Type type_;
  OwnerType ownerType_;
  StringC owner_;
  TextClass textClass_;
  PackedBoolean unavailable_;
  StringC description_;
  StringC languageOrDesignatingSequence_;
  PackedBoolean haveDisplayVersion_;
  StringC displayVersion_;
  Text text_;
  StringC nid_;
  StringC nss_;
};

class ExternalId {
public:
  ExternalId();
  const StringC *systemIdString() const;
  const StringC *publicIdString() const;
  const StringC &effectiveSystemId() const;
  const Text *systemIdText() const;
  const Text *publicIdText() const;
  const PublicId *publicId() const;
  void setSystem(Text &);
  void setEffectiveSystem(StringC &);



  PublicId::Type setPublic(Text &, const CharsetInfo &, Char space,
      const MessageType1 *&fpierror,
      const MessageType1 *&urnerror);
  void setLocation(const Location &);

  const Location &location() const;
private:
  PackedBoolean haveSystem_;
  PackedBoolean havePublic_;
  Text system_;
  PublicId public_;
  Location loc_;
  StringC effectiveSystem_;
};

inline
const StringC &PublicId::string() const
{
  return text_.string();
}

inline
const Text &PublicId::text() const
{
  return text_;
}

inline
const StringC *ExternalId::systemIdString() const
{
  return haveSystem_ ? &system_.string() : 0;
}

inline
const StringC *ExternalId::publicIdString() const
{
  return havePublic_ ? &public_.string() : 0;
}

inline
const Text *ExternalId::systemIdText() const
{
  return haveSystem_ ? &system_ : 0;
}

inline
const Text *ExternalId::publicIdText() const
{
  return havePublic_ ? &public_.text() : 0;
}

inline
const PublicId *ExternalId::publicId() const
{
  return havePublic_ ? &public_ : 0;
}

inline
const Location &ExternalId::location() const
{
  return loc_;
}

inline
const StringC &ExternalId::effectiveSystemId() const
{
  return effectiveSystem_;
}

inline
void ExternalId::setEffectiveSystem(StringC &str)
{
  str.swap(effectiveSystem_);
}


}
# 16 "/usr/include/OpenSP/Notation.h" 2 3 4

# 1 "/usr/include/OpenSP/Attributed.h" 1 3 4






# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 8 "/usr/include/OpenSP/Attributed.h" 2 3 4
# 1 "/usr/include/OpenSP/Attribute.h" 1 3 4






#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 11 "/usr/include/OpenSP/Attribute.h" 2 3 4

# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 13 "/usr/include/OpenSP/Attribute.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 15 "/usr/include/OpenSP/Attribute.h" 2 3 4
# 1 "/usr/include/OpenSP/CopyOwner.h" 1 3 4
# 16 "/usr/include/OpenSP/Attribute.h" 2 3 4


# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 19 "/usr/include/OpenSP/Attribute.h" 2 3 4



namespace OpenSP {


class Entity;
class Notation;
class DeclaredValue;
class AttributeValue;
class TokenizedAttributeValue;
class AttributeSemantics;
class AttributeContext;
class Syntax;

 class AttributeValue : public Resource {
 public:
   enum Type {
     implied,
     cdata,
     tokenized
   };
   AttributeValue();
   virtual ~AttributeValue();
   virtual AttributeSemantics *makeSemantics(const DeclaredValue *,
                                             AttributeContext &,
                                             const StringC &,
                                             unsigned &,
                                             unsigned &) const;
   virtual Type info(const Text *&, const StringC *&) const = 0;
   virtual const Text *text() const;
   virtual Boolean recoverUnquoted(const StringC &, const Location &,
                                   AttributeContext &, const StringC &);
   static Boolean handleAsUnterminated(const Text &, AttributeContext &);
 };

class AttributeDefinitionDesc {
public:
  AttributeDefinitionDesc() { }
  enum DeclaredValue {
    cdata,
    name,
    number,
    nmtoken,
    nutoken,
    entity,
    idref,
    names,
    numbers,
    nmtokens,
    nutokens,
    entities,
    idrefs,
    id,
    notation,
    nameTokenGroup
  };
  DeclaredValue declaredValue;
  enum DefaultValueType {
    required,
    current,
    implied,
    conref,
    defaulted,
    fixed
  };
  DefaultValueType defaultValueType;
  ConstPtr<AttributeValue> defaultValue;
  Vector<StringC> allowedValues;
  Vector<StringC> origAllowedValues;


  size_t currentIndex;
private:
  AttributeDefinitionDesc(const AttributeDefinitionDesc &);
  void operator=(const AttributeDefinitionDesc &);
};

class DeclaredValue {
public:
  DeclaredValue();
  virtual ~DeclaredValue();

  virtual AttributeValue *makeValue(Text &, AttributeContext &,
        const StringC &name,
        unsigned &specLength) const = 0;


  virtual AttributeValue *makeValueFromToken(Text &,
          AttributeContext &,
          const StringC &name,
          unsigned &specLength) const;

  virtual AttributeSemantics *makeSemantics(const TokenizedAttributeValue &,
         AttributeContext &,
         const StringC &,
         unsigned &nIdrefs,
         unsigned &nEntityNames) const;
  virtual Boolean containsToken(const StringC &) const;
  virtual Boolean tokenized() const = 0;
  virtual Boolean isNotation() const;
  virtual Boolean isEntity() const;
  virtual Boolean isId() const;
  virtual Boolean isIdref() const;
  virtual const Vector<StringC> *getTokens() const;
  virtual const Vector<StringC> *getOrigTokens() const;
  virtual void buildDesc(AttributeDefinitionDesc &) const = 0;
  virtual DeclaredValue *copy() const = 0;
};

class CdataDeclaredValue : public DeclaredValue {
public:
  CdataDeclaredValue();
  Boolean tokenized() const;
  AttributeValue *makeValue(Text &, AttributeContext &, const StringC &,
       unsigned &) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
protected:
  void checkNormalizedLength(Text &, AttributeContext &, unsigned &) const;
};


class TokenizedDeclaredValue : public DeclaredValue {
public:

  enum TokenType {
    name,
    number,
    nameToken,
    numberToken,
    entityName
  };
  TokenizedDeclaredValue(TokenType type, Boolean isList);
  AttributeValue *makeValue(Text &, AttributeContext &, const StringC &,
       unsigned &) const;
  TokenizedAttributeValue *makeTokenizedValue(Text &, AttributeContext &,
           const StringC &, unsigned &) const;
  Boolean tokenized() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
private:
  TokenType type_;
  Boolean isList_;
  unsigned initialCategories_;
  unsigned subsequentCategories_;
};

class GroupDeclaredValue : public TokenizedDeclaredValue {
public:
  GroupDeclaredValue(TokenType, Vector<StringC> &);
  Boolean containsToken(const StringC &) const;
  AttributeValue *makeValue(Text &, AttributeContext &, const StringC &,
       unsigned &) const;
  AttributeValue *makeValueFromToken(Text &,
         AttributeContext &,
         const StringC &name,
         unsigned &) const;
  const Vector<StringC> *getTokens() const;
  const Vector<StringC> *getOrigTokens() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
  void setOrigAllowedValues(Vector<StringC> &origAllowedValues);

private:
  Vector<StringC> allowedValues_;
  Vector<StringC> origAllowedValues_;
};

class NameTokenGroupDeclaredValue : public GroupDeclaredValue {
public:
  NameTokenGroupDeclaredValue(Vector<StringC> &);
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
};

class NotationDeclaredValue : public GroupDeclaredValue {
public:
  NotationDeclaredValue(Vector<StringC> &);
  AttributeSemantics *makeSemantics(const TokenizedAttributeValue &,
        AttributeContext &,
        const StringC &,
        unsigned &nIdrefs,
        unsigned &nEntityNames) const;
  Boolean isNotation() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
};

class EntityDeclaredValue : public TokenizedDeclaredValue {
public:
  EntityDeclaredValue(Boolean isList);
  AttributeSemantics *makeSemantics(const TokenizedAttributeValue &,
        AttributeContext &,
        const StringC &,
        unsigned &nIdrefs,
        unsigned &nEntityNames) const;
  Boolean isEntity() const;
  DeclaredValue *copy() const;
};

class IdDeclaredValue : public TokenizedDeclaredValue {
public:
  IdDeclaredValue();
  AttributeSemantics *makeSemantics(const TokenizedAttributeValue &,
        AttributeContext &,
        const StringC &,
        unsigned &nIdrefs,
        unsigned &nEntityNames) const;
  Boolean isId() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
};

class IdrefDeclaredValue : public TokenizedDeclaredValue {
public:
  IdrefDeclaredValue(Boolean isList);
  AttributeSemantics *makeSemantics(const TokenizedAttributeValue &,
        AttributeContext &,
        const StringC &,
        unsigned &nIdrefs,
        unsigned &nEntityNames) const;
  Boolean isIdref() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  DeclaredValue *copy() const;
};

class AttributeDefinition {
public:
  AttributeDefinition(const StringC &, DeclaredValue *);
  virtual ~AttributeDefinition();
  virtual ConstPtr<AttributeValue>
    makeMissingValue(AttributeContext &) const = 0;
  virtual Boolean missingValueWouldMatch(const Text &,
      const AttributeContext &) const;
  virtual const AttributeValue *
    defaultValue(const AttributeValue *impliedValue) const;
  AttributeValue *makeValue(Text &, AttributeContext &, unsigned &) const;
  AttributeValue *makeValueFromToken(Text &,
         AttributeContext &,
         unsigned &) const;

  virtual Boolean isConref() const;
  virtual Boolean isCurrent() const;
  virtual Boolean isFixed() const;
  AttributeSemantics *makeSemantics(const AttributeValue *,
        AttributeContext &,
        unsigned &nIdrefs,
        unsigned &nEntityNames) const;
  Boolean tokenized() const;
  const StringC &name() const;
  const StringC &origName() const;
  Boolean containsToken(const StringC &) const;
  Boolean isNotation() const;
  Boolean isEntity() const;
  Boolean isId() const;
  Boolean isIdref() const;
  void getDesc(AttributeDefinitionDesc &) const;
  const Vector<StringC> *getTokens() const;
  const Vector<StringC> *getOrigTokens() const;
  virtual AttributeDefinition *copy() const = 0;
  void setDeclaredValue(DeclaredValue *);
  void setSpecified(Boolean implicit);
  Boolean isSpecified(Boolean &implicit);
  void setOrigName(StringC &origName);
private:
  virtual void buildDesc(AttributeDefinitionDesc &) const = 0;
  virtual AttributeValue *checkValue(AttributeValue *, AttributeContext &) const;
  PackedBoolean implicit_;
  PackedBoolean all_;
  StringC name_;
  StringC origName_;
  CopyOwner<DeclaredValue> declaredValue_;
};

class RequiredAttributeDefinition : public AttributeDefinition {
public:
  RequiredAttributeDefinition(const StringC &, DeclaredValue *);
  ConstPtr<AttributeValue> makeMissingValue(AttributeContext &) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  AttributeDefinition *copy() const;
};

class CurrentAttributeDefinition : public AttributeDefinition {
public:
  CurrentAttributeDefinition(const StringC &, DeclaredValue *, size_t index);
  ConstPtr<AttributeValue> makeMissingValue(AttributeContext &) const;
  Boolean missingValueWouldMatch(const Text &, const AttributeContext &) const;
  AttributeValue *checkValue(AttributeValue *, AttributeContext &) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  Boolean isCurrent() const;
  AttributeDefinition *copy() const;
private:
  size_t currentIndex_;
};

class ImpliedAttributeDefinition : public AttributeDefinition {
public:
  ImpliedAttributeDefinition(const StringC &, DeclaredValue *);
  ConstPtr<AttributeValue> makeMissingValue(AttributeContext &) const;
  const AttributeValue *defaultValue(const AttributeValue *) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  AttributeDefinition *copy() const;
};

class ConrefAttributeDefinition : public ImpliedAttributeDefinition {
public:
  ConrefAttributeDefinition(const StringC &, DeclaredValue *);
  Boolean isConref() const;
  void buildDesc(AttributeDefinitionDesc &) const;
  AttributeDefinition *copy() const;
};

class DefaultAttributeDefinition : public AttributeDefinition {
public:
  DefaultAttributeDefinition(const StringC &, DeclaredValue *,
        AttributeValue *);
  ConstPtr<AttributeValue> makeMissingValue(AttributeContext &) const;
  Boolean missingValueWouldMatch(const Text &, const AttributeContext &) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  AttributeDefinition *copy() const;
  const AttributeValue *defaultValue(const AttributeValue *) const;
private:
  ConstPtr<AttributeValue> value_;
};

class FixedAttributeDefinition : public DefaultAttributeDefinition {
public:
  FixedAttributeDefinition(const StringC &, DeclaredValue *,
      AttributeValue *);

  AttributeValue *checkValue(AttributeValue *, AttributeContext &) const;
  void buildDesc(AttributeDefinitionDesc &) const;
  Boolean isFixed() const;
  AttributeDefinition *copy() const;
};

class AttributeDefinitionList : public Resource {
public:
  AttributeDefinitionList(Vector<CopyOwner<AttributeDefinition> > &,
     size_t listIndex,
     Boolean anyCurrent = 0,
     size_t idIndex = size_t(-1),
     size_t notationIndex = size_t(-1));
  AttributeDefinitionList(const ConstPtr<AttributeDefinitionList> &);
  size_t size() const;
  AttributeDefinition *def(size_t);
  const AttributeDefinition *def(size_t) const;
  Boolean tokenIndex(const StringC &, unsigned &) const;
  Boolean tokenIndexUnique(const StringC &, unsigned) const;
  Boolean attributeIndex(const StringC &, unsigned &) const;
  size_t index() const;
  size_t idIndex() const;
  size_t notationIndex() const;
  Boolean anyCurrent() const;
  void setIndex(size_t);
  void append(AttributeDefinition *);
private:
  Vector<CopyOwner<AttributeDefinition> > defs_;
  size_t index_;
  size_t idIndex_;
  size_t notationIndex_;
  Boolean anyCurrent_;
  ConstPtr<AttributeDefinitionList> prev_;
};

class AttributeSemantics {
public:
  AttributeSemantics();
  virtual ~AttributeSemantics();
  virtual size_t nEntities() const;
  virtual ConstPtr<Entity> entity(size_t) const;
  virtual ConstPtr<Notation> notation() const;
  virtual AttributeSemantics *copy() const = 0;
};

class EntityAttributeSemantics : public AttributeSemantics {
public:
  EntityAttributeSemantics(Vector<ConstPtr<Entity> > &);
  size_t nEntities() const;
  ConstPtr<Entity> entity(size_t) const;
  AttributeSemantics *copy() const;
private:
  Vector<ConstPtr<Entity> > entity_;
};

class NotationAttributeSemantics : public AttributeSemantics {
public:
  NotationAttributeSemantics(const ConstPtr<Notation> &);
  ConstPtr<Notation> notation() const;
  AttributeSemantics *copy() const;
private:
  ConstPtr<Notation> notation_;
};

class ImpliedAttributeValue : public AttributeValue {
public:
  ImpliedAttributeValue();
  Type info(const Text *&, const StringC *&) const;
};

class CdataAttributeValue : public AttributeValue {
public:
  CdataAttributeValue(Text &);
  Type info(const Text *&, const StringC *&) const;
  const Text *text() const;
  Boolean recoverUnquoted(const StringC &, const Location &,
     AttributeContext &, const StringC &);
  virtual const Notation *notation() const;
private:
  Text text_;
};


class TokenizedAttributeValue : public AttributeValue {
public:
  TokenizedAttributeValue(Text &, const Vector<size_t> &);
  size_t nTokens() const;
  AttributeSemantics *makeSemantics(const DeclaredValue *,
        AttributeContext &,
        const StringC &,
        unsigned &,
        unsigned &) const;
  Type info(const Text *&, const StringC *&) const;
  const Text *text() const;
  const StringC &string() const;
  StringC token(size_t) const;
  void token(size_t, const Char *&, size_t &) const;
  Location tokenLocation(size_t) const;
  Boolean tokenLocation(size_t, const ConstPtr<Origin> *&, Index &) const;
  Boolean recoverUnquoted(const StringC &, const Location &,
     AttributeContext &, const StringC &);
private:
  TokenizedAttributeValue(const TokenizedAttributeValue &);
  void operator=(const TokenizedAttributeValue &);
  Text text_;


  Vector<size_t> spaceIndex_;
};

class Attribute {
public:
  Attribute();
  Boolean specified() const;
  size_t specIndex() const;
  const AttributeValue *value() const;
  const ConstPtr<AttributeValue> &valuePointer() const;
  const AttributeSemantics *semantics() const;
  void setSpec(size_t);
  void setValue(const ConstPtr<AttributeValue> &);
  void setSemantics(AttributeSemantics *);
  void clear();
private:
  size_t specIndexPlus_;
  ConstPtr<AttributeValue> value_;
  CopyOwner<AttributeSemantics> semantics_;
};

class AttributeList {
public:
  AttributeList();
  AttributeList(const ConstPtr<AttributeDefinitionList> &);
  void init(const ConstPtr<AttributeDefinitionList> &);

  Boolean conref() const;
  size_t size() const;
  const StringC &name(unsigned) const;
  const AttributeValue *value(unsigned) const;
  size_t specIndex(size_t) const;
  const ConstPtr<AttributeValue> &valuePointer(unsigned) const;
  const AttributeSemantics *semantics(unsigned) const;
  Boolean tokenized(unsigned index) const;
  Boolean tokenIndex(const StringC &, unsigned &) const;
  Boolean tokenIndexUnique(const StringC &, unsigned) const;
  Boolean attributeIndex(const StringC &, unsigned &) const;
  void finish(AttributeContext &);
  Boolean setValue(unsigned index, Text &, AttributeContext &,
     unsigned &specLength);
  void setValueToken(unsigned index, Text &, AttributeContext &,
       unsigned &specLength);
  void setSpec(unsigned index, AttributeContext &);
  Boolean recoverUnquoted(const StringC &, const Location &,
     AttributeContext &);
  Boolean handleAsUnterminated(AttributeContext &context);
  void swap(AttributeList &);
  size_t nSpec() const;
  size_t defIndex() const;

  Boolean current(unsigned) const;
  Boolean anyCurrent() const;
  Boolean specified(unsigned) const;
  Boolean id(unsigned) const;
  Boolean idref(unsigned) const;
  const Vector<StringC> *getAllowedTokens(unsigned) const;
  const StringC *getId() const;
  Boolean idIndex(unsigned &) const;
  void noteInvalidSpec();
  void changeDef(const ConstPtr<AttributeDefinitionList> &);
  const ConstPtr<AttributeDefinitionList> &def() const;
private:
  const AttributeDefinition *def(size_t) const;
  PackedBoolean conref_;
  unsigned nIdrefs_;
  unsigned nEntityNames_;
  size_t nSpec_;
  Vector<Attribute> vec_;
  ConstPtr<AttributeDefinitionList> def_;
};

class DataDeclaredValue : public CdataDeclaredValue {
public:
  DataDeclaredValue(const ConstPtr<Notation> &, AttributeList &);
  AttributeValue *makeValue(Text &, AttributeContext &, const StringC &,
                            unsigned &) const;
  DeclaredValue *copy() const;
private:
  ConstPtr<Notation> notation_;
  AttributeList attributes_;
};

class DataAttributeValue : public CdataAttributeValue {
public:
  DataAttributeValue(Text &, const ConstPtr<Notation> &, const AttributeList &);
  const AttributeList &attributes() const;
  const Notation *notation() const;
private:
  const ConstPtr<Notation> notation_;
  const AttributeList *attributes_;
};

class AttributeContext : public Messenger {
public:
  AttributeContext();
  virtual ~AttributeContext();
  virtual Boolean defineId(const StringC &, const Location &, Location &);
  virtual void noteIdref(const StringC &, const Location &);
  virtual void noteCurrentAttribute(size_t, AttributeValue *);
  virtual ConstPtr<AttributeValue> getCurrentAttribute(size_t) const;
  virtual ConstPtr<Entity> getAttributeEntity(const StringC &,
           const Location &);
  virtual ConstPtr<Notation> getAttributeNotation(const StringC &,
        const Location &);
  virtual const Syntax &attributeSyntax() const = 0;

  ConstPtr<AttributeValue> makeImpliedAttributeValue();
  Boolean mayDefaultAttribute() const;
  Boolean validate() const;
protected:
  Boolean mayDefaultAttribute_;
  Boolean validate_;
private:
  ConstPtr<AttributeValue> impliedAttributeValue_;
};

inline
Boolean AttributeDefinition::tokenized() const
{
  return declaredValue_->tokenized();
}

inline
Boolean AttributeDefinition::isNotation() const
{
  return declaredValue_->isNotation();
}

inline
Boolean AttributeDefinition::isEntity() const
{
  return declaredValue_->isEntity();
}

inline
Boolean AttributeDefinition::isId() const
{
  return declaredValue_->isId();
}

inline
Boolean AttributeDefinition::isIdref() const
{
  return declaredValue_->isIdref();
}

inline
const Vector<StringC> *AttributeDefinition::getTokens() const
{
  return declaredValue_->getTokens();
}

inline
const Vector<StringC> *AttributeDefinition::getOrigTokens() const
{
  return declaredValue_->getOrigTokens();
}

inline
AttributeSemantics *
AttributeDefinition::makeSemantics(const AttributeValue *value,
       AttributeContext &context,
       unsigned &nIdrefs,
       unsigned &nEntityNames) const
{
  return value->makeSemantics(declaredValue_.pointer(), context, name_,
         nIdrefs, nEntityNames);
}

inline
AttributeValue *AttributeDefinition::makeValue(Text &text,
            AttributeContext &context,
            unsigned &specLength) const
{
  return checkValue(declaredValue_->makeValue(text, context, name_,
           specLength),
      context);
}

inline
AttributeValue *
AttributeDefinition::makeValueFromToken(Text &text,
     AttributeContext &context,
     unsigned &specLength) const
{
  return checkValue(declaredValue_->makeValueFromToken(text, context,
             name_, specLength),
      context);
}

inline
Boolean AttributeDefinition::containsToken(const StringC &token) const
{
  return declaredValue_->containsToken(token);
}

inline
const StringC &AttributeDefinition::name() const
{
  return name_;
}

inline
const StringC &AttributeDefinition::origName() const
{
  return origName_;
}

inline
void AttributeDefinition::setDeclaredValue(DeclaredValue *declaredValue)
{
  declaredValue_ = declaredValue;
}

inline
size_t AttributeDefinitionList::size() const
{
  return defs_.size();
}

inline
size_t AttributeDefinitionList::index() const
{
  return index_;
}

inline
void AttributeDefinitionList::setIndex(size_t index)
{
  index_ = index;
}

inline
size_t AttributeDefinitionList::idIndex() const
{
  return idIndex_;
}

inline
size_t AttributeDefinitionList::notationIndex() const
{
  return notationIndex_;
}

inline
Boolean AttributeDefinitionList::anyCurrent() const
{
  return anyCurrent_;
}

inline
AttributeDefinition *AttributeDefinitionList::def(size_t i)
{
  return defs_[i].pointer();
}

inline
const AttributeDefinition *AttributeDefinitionList::def(size_t i) const
{
  return defs_[i].pointer();
}

inline
size_t TokenizedAttributeValue::nTokens() const
{
  return spaceIndex_.size() + 1;
}

inline
const StringC &TokenizedAttributeValue::string() const
{
  return text_.string();
}

inline
void TokenizedAttributeValue::token(size_t i,
        const Char *&ptr, size_t &len) const
{
  size_t startIndex = i == 0 ? 0 : spaceIndex_[i - 1] + 1;
  ptr = text_.string().data() + startIndex;
  len = (i == spaceIndex_.size() ? text_.size() : spaceIndex_[i]) - startIndex;
}

inline
StringC TokenizedAttributeValue::token(size_t i) const
{
  const Char *ptr;
  size_t len;
  token(i, ptr, len);
  return StringC(ptr, len);
}


inline
Location TokenizedAttributeValue::tokenLocation(size_t i) const
{
  return text_.charLocation(i == 0 ? 0 : spaceIndex_[i - 1] + 1);
}

inline
Boolean TokenizedAttributeValue::tokenLocation(size_t i,
            const ConstPtr<Origin> *&origin,
            Index &index) const
{
  return text_.charLocation(i == 0 ? 0 : spaceIndex_[i - 1] + 1, origin, index);
}

inline
size_t Attribute::specIndex() const
{
  return specIndexPlus_ - 1;
}

inline
Boolean Attribute::specified() const
{
  return specIndexPlus_ != 0;
}

inline
const AttributeValue *Attribute::value() const
{
  return value_.pointer();
}

inline
const ConstPtr<AttributeValue> &Attribute::valuePointer() const
{
  return value_;
}

inline
const AttributeSemantics *Attribute::semantics() const
{
  return semantics_.pointer();
}

inline
void Attribute::setSpec(size_t index)
{
  specIndexPlus_ = index + 1;
}

inline
void Attribute::setValue(const ConstPtr<AttributeValue> &value)
{
  value_ = value;
}

inline
void Attribute::setSemantics(AttributeSemantics *semantics)
{
  semantics_ = semantics;
}

inline
size_t AttributeList::size() const
{
  return vec_.size();
}

inline
const AttributeDefinition *AttributeList::def(size_t i) const
{
  return def_->def(i);
}

inline
const ConstPtr<AttributeDefinitionList> &AttributeList::def() const
{
  return def_;
}

inline
Boolean AttributeList::tokenized(unsigned i) const
{
  return def(i)->tokenized();
}

inline
Boolean AttributeList::tokenIndex(const StringC &name, unsigned &index) const
{
  return !def_.isNull() && def_->tokenIndex(name, index);
}

inline
Boolean AttributeList::tokenIndexUnique(const StringC &name, unsigned index) const
{
  return def_->tokenIndexUnique(name, index);
}

inline
Boolean AttributeList::attributeIndex(const StringC &name, unsigned &index) const
{
  return !def_.isNull() && def_->attributeIndex(name, index);
}

inline
const StringC &AttributeList::name(unsigned i) const
{
  return def(i)->name();
}

inline
const Vector<StringC> *AttributeList::getAllowedTokens(unsigned i) const
{
  return def(i)->getTokens();
}

inline
const AttributeValue *AttributeList::value(unsigned i) const
{
  return vec_[i].value();
}

inline
const ConstPtr<AttributeValue> &AttributeList::valuePointer(unsigned i)
     const
{
  return vec_[i].valuePointer();
}

inline
const AttributeSemantics *AttributeList::semantics(unsigned i) const
{
  return vec_[i].semantics();
}

inline
size_t AttributeList::specIndex(size_t i) const
{
  return vec_[i].specIndex();
}

inline
size_t AttributeList::nSpec() const
{
  return nSpec_;
}

inline
Boolean AttributeList::conref() const
{
  return conref_;
}

inline
size_t AttributeList::defIndex() const
{
  return def_.isNull() ? size_t(-1) : def_->index();
}

inline
Boolean AttributeList::current(unsigned i) const
{
  return def(i)->isCurrent();
}

inline
Boolean AttributeList::anyCurrent() const
{
  return !def_.isNull() && def_->anyCurrent();
}

inline
const AttributeValue *
DefaultAttributeDefinition::defaultValue(const AttributeValue *)
     const
{
  return value_.pointer();
}

inline
Boolean AttributeList::idIndex(unsigned &ind) const
{
  if (def_.isNull() || def_->idIndex() == size_t(-1))
    return 0;
  else {
    ind = def_->idIndex();
    return 1;
  }
}

inline
Boolean AttributeList::id(unsigned i) const
{
  return def(i)->isId();
}

inline
Boolean AttributeList::idref(unsigned i) const
{
  return def(i)->isIdref();
}

inline
Boolean AttributeList::specified(unsigned i) const
{
  return vec_[i].specified();
}

inline
Boolean AttributeContext::mayDefaultAttribute() const
{
  return mayDefaultAttribute_;
}

inline
Boolean AttributeContext::validate() const
{
  return validate_;
}


}
# 9 "/usr/include/OpenSP/Attributed.h" 2 3 4





namespace OpenSP {


class Attributed {
public:
  Attributed() { }
  ConstPtr<AttributeDefinitionList> attributeDef() const;
  const AttributeDefinitionList *attributeDefTemp() const;
  Ptr<AttributeDefinitionList> attributeDef();
  void setAttributeDef(const Ptr<AttributeDefinitionList> &);
private:
  Ptr<AttributeDefinitionList> attributeDef_;

};

inline
ConstPtr<AttributeDefinitionList> Attributed::attributeDef() const
{
  return attributeDef_;
}

inline
const AttributeDefinitionList *Attributed::attributeDefTemp() const
{
  return attributeDef_.pointer();
}

inline
Ptr<AttributeDefinitionList> Attributed::attributeDef()
{
  return attributeDef_;
}

inline
void Attributed::setAttributeDef(const Ptr<AttributeDefinitionList> &def)
{
  attributeDef_ = def;
}


}
# 18 "/usr/include/OpenSP/Notation.h" 2 3 4
# 1 "/usr/include/OpenSP/StringResource.h" 1 3 4






# 1 "/usr/include/OpenSP/StringOf.h" 1 3 4
# 8 "/usr/include/OpenSP/StringResource.h" 2 3 4



namespace OpenSP {


template<class T>
class StringResource : public String<T>, public Resource {
public:
  StringResource(const String<T> &s) : String<T>(s) { }
};


}
# 19 "/usr/include/OpenSP/Notation.h" 2 3 4
# 1 "/usr/include/OpenSP/EntityDecl.h" 1 3 4







#pragma interface



# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 13 "/usr/include/OpenSP/EntityDecl.h" 2 3 4





namespace OpenSP {


class EntityDecl : public NamedResource {
public:
  enum DeclType { generalEntity, parameterEntity, doctype, linktype,
    notation, sgml };
  enum DataType { sgmlText, pi, cdata, sdata, ndata, subdoc };
  EntityDecl(const StringC &, DeclType declType, DataType dataType,
      const Location &defLocation);
  DataType dataType() const;
  DeclType declType() const;
  const Location &defLocation() const;
  Boolean declInDtdIsBase() const;
  Boolean declInActiveLpd() const;
  const StringC *declInDtdNamePointer() const;
  const StringC *declInLpdNamePointer() const;
  void setDeclIn(const ConstPtr<StringResource<Char> > &dtdName,
   Boolean dtdIsBase,
   const ConstPtr<StringResource<Char> > &lpdName,
   Boolean lpdIsActive);
  void setDeclIn(const ConstPtr<StringResource<Char> > &dtdName,
   Boolean dtdIsBase);
  void setDefLocation(const Location &);
  virtual const StringC *systemIdPointer() const;
  virtual const StringC *publicIdPointer() const;
  virtual const StringC *effectiveSystemIdPointer() const;
private:
  DeclType declType_;
  DataType dataType_;
  PackedBoolean dtdIsBase_;
  PackedBoolean lpdIsActive_;
  Location defLocation_;
  ConstPtr<StringResource<Char> > dtdName_;
  ConstPtr<StringResource<Char> > lpdName_;
};

inline
const Location &EntityDecl::defLocation() const
{
  return defLocation_;
}

inline
EntityDecl::DeclType EntityDecl::declType() const
{
  return declType_;
}

inline
EntityDecl::DataType EntityDecl::dataType() const
{
  return dataType_;
}

inline
const StringC *EntityDecl::declInDtdNamePointer() const
{
  return dtdName_.pointer();
}

inline
const StringC *EntityDecl::declInLpdNamePointer() const
{
  return lpdName_.pointer();
}

inline
Boolean EntityDecl::declInDtdIsBase() const
{
  return dtdIsBase_;
}

inline
Boolean EntityDecl::declInActiveLpd() const
{
  return lpdIsActive_;
}

inline
void EntityDecl::setDefLocation(const Location &loc)
{
  defLocation_ = loc;
}


}
# 20 "/usr/include/OpenSP/Notation.h" 2 3 4


namespace OpenSP {


class ParserState;

class Notation : public EntityDecl, public Attributed {
public:
  Notation(const StringC &,
    const ConstPtr<StringResource<Char> > &dtdName,
    Boolean dtdIsBase);
  void setExternalId(const ExternalId &, const Location &);
  const ExternalId &externalId() const;
  Boolean defined() const;
  void generateSystemId(ParserState &);
  const StringC *systemIdPointer() const;
  const StringC *publicIdPointer() const;
private:
  Notation(const Notation &);
  void operator=(const Notation &);
  PackedBoolean defined_;
  ExternalId externalId_;
};

inline
const ExternalId &Notation::externalId() const
{
  return externalId_;
}

inline
Boolean Notation::defined() const
{
  return defined_;
}


}
# 20 "/usr/include/OpenSP/Event.h" 2 3 4
# 1 "/usr/include/OpenSP/Sd.h" 1 3 4






#pragma interface





# 1 "/usr/include/OpenSP/CharsetInfo.h" 1 3 4






#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/limits.h" 1 3 4
# 11 "/usr/include/OpenSP/CharsetInfo.h" 2 3 4
# 1 "/usr/include/OpenSP/UnivCharsetDesc.h" 1 3 4






#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 11 "/usr/include/OpenSP/UnivCharsetDesc.h" 2 3 4

# 1 "/usr/include/OpenSP/CharMap.h" 1 3 4
# 11 "/usr/include/OpenSP/CharMap.h" 3 4
namespace OpenSP {




class CharMapBits {
public:

  enum { level0 = 5, level1 = 8, level2 = 4, level3 = 4 };

  enum {
    planes = (1 << CharMapBits::level0) ,
    pagesPerPlane = (1 << CharMapBits::level1),
    columnsPerPage = (1 << CharMapBits::level2),
    cellsPerColumn = (1 << CharMapBits::level3),
    planeSize = (1 << (CharMapBits::level1 + CharMapBits::level2 + CharMapBits::level3)),
    pageSize = (1 << (CharMapBits::level2 + CharMapBits::level3)),
    columnSize = (1 << CharMapBits::level3)
  };

  static size_t planeIndex(size_t c) {
    return (c >> (CharMapBits::level1 + CharMapBits::level2 + CharMapBits::level3));
  }
  static size_t pageIndex(size_t c) {
    return ((c >> (CharMapBits::level2 + CharMapBits::level3)) & (pagesPerPlane - 1));
  }
  static size_t columnIndex(size_t c) {
    return ((c >> CharMapBits::level3) & (columnsPerPage - 1));
  }
  static size_t cellIndex(size_t c) {
    return (c & (cellsPerColumn - 1));
  }
  static size_t maxInPlane(size_t c) {
    return (c | (planeSize - 1));
  }
  static size_t maxInPage(size_t c) {
    return (c | (pageSize - 1));
  }
  static size_t maxInColumn(size_t c) {
    return (c | (columnSize - 1));
  }
};
# 73 "/usr/include/OpenSP/CharMap.h" 3 4
template<class T>
class CharMapColumn {
public:
  CharMapColumn();
  CharMapColumn(const CharMapColumn<T> &);
  void operator=(const CharMapColumn<T> &);
  ~CharMapColumn();
  T *values;
  T value;
};

template<class T>
class CharMapPage {
public:
  CharMapPage();
  CharMapPage(const CharMapPage<T> &);
  void operator=(const CharMapPage<T> &);
  ~CharMapPage();
  void swap(CharMapPage<T> &);
  CharMapColumn<T> *values;
  T value;
};

template<class T>
class CharMapPlane {
public:
  CharMapPlane();
  CharMapPlane(const CharMapPlane<T> &);
  void operator=(const CharMapPlane<T> &);
  ~CharMapPlane();
  void swap(CharMapPlane<T> &);
  CharMapPage<T> *values;
  T value;
};


template<class T>
class CharMap {
public:
  CharMap();
  CharMap(T);
  T operator[](Char) const;
  T getRange(Char from, Char &to) const;
  void swap(CharMap<T> &);
  void setChar(Char, T);
  void setRange(Char from, Char to, T val);
  void setAll(T);
private:


  CharMapPlane<T> values_[CharMapBits::planes];
  T lo_[256];



};

template<class T>
class CharMapResource : public CharMap<T>, public Resource {
public:
  CharMapResource() { }
  CharMapResource(T t) : CharMap<T>(t) { }
};



template<class T>
inline
T CharMap<T>::operator[](Char c) const
{
  if (c < 256)
    return lo_[c];
  const CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(c)];
  if (pl.values) {
    const CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(c)];
    if (pg.values) {
      const CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(c)];
      if (column.values)
        return column.values[CharMapBits::cellIndex(c)];
      else
        return column.value;
    }
    else
      return pg.value;
  }
  else
    return pl.value;
}

template<class T>
inline
T CharMap<T>::getRange(Char c, Char &max) const
{
  if (c < 256) {
    max = c;
    return lo_[c];
  }
  const CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(c)];
  if (pl.values) {
    const CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(c)];
    if (pg.values) {
      const CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(c)];
      if (column.values) {
        max = c;
        return column.values[CharMapBits::cellIndex(c)];
      }
      else {
        max = CharMapBits::maxInColumn(c);
        return column.value;
      }
    }
    else {
      max = CharMapBits::maxInPage(c);
      return pg.value;
    }
  }
  else {
    max = CharMapBits::maxInPlane(c);
    return pl.value;
  }
}
# 222 "/usr/include/OpenSP/CharMap.h" 3 4
}





# 1 "/usr/include/OpenSP/CharMap.cxx" 1 3 4







namespace OpenSP {




template<class T>
CharMap<T>::CharMap()
{
}

template<class T>
CharMap<T>::CharMap(T dflt)
{
  for (size_t i = 0; i < 256; i++)
    lo_[i] = dflt;
  for (size_t i = 0; i < CharMapBits::planes; i++)
    values_[i].value = dflt;
}

template<class T>
void CharMap<T>::setAll(T val)
{
  for (size_t i = 0; i < 256; i++)
    lo_[i] = val;
  for (size_t i = 0; i < CharMapBits::planes; i++) {
    values_[i].value = val;
    delete [] values_[i].values;
    values_[i].values = 0;
  }
}

template<class T>
void CharMap<T>::swap(CharMap<T> &map)
{
  for (size_t i = 0; i < 256; i++) {
    T tem(lo_[i]);
    lo_[i] = map.lo_[i];
    map.lo_[i] = tem;
  }
  for (size_t i = 0; i < CharMapBits::planes; i++)
    values_[i].swap(map.values_[i]);
}

template<class T>
void CharMap<T>::setChar(Char c, T val)
{
  if (c < 256) {
    lo_[c] = val;
    return;
  }
  CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(c)];
  if (pl.values) {
    CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(c)];
    if (pg.values) {
      CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(c)];
      if (column.values)
        column.values[CharMapBits::cellIndex(c)] = val;
      else if (val != column.value) {
        column.values = new T[CharMapBits::columnSize];
        for (size_t i = 0; i < CharMapBits::columnSize; i++)
     column.values[i] = column.value;
        column.values[CharMapBits::cellIndex(c)] = val;
      }
    }
    else if (val != pg.value) {
      pg.values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
      for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
        pg.values[i].value = pg.value;
      CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(c)];
      column.values = new T[CharMapBits::cellsPerColumn];
      for (size_t i = 0; i < CharMapBits::cellsPerColumn; i++)
        column.values[i] = column.value;
      column.values[CharMapBits::cellIndex(c)] = val;
    }
  }
  else if (val != pl.value) {
    pl.values = new CharMapPage<T>[CharMapBits::pagesPerPlane];
    for (size_t i = 0; i < CharMapBits::pagesPerPlane; i++)
      pl.values[i].value = pl.value;
    CharMapPage<T> &page = pl.values[CharMapBits::pageIndex(c)];
    page.values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
    for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
      page.values[i].value = page.value;
    CharMapColumn<T> &column = page.values[CharMapBits::columnIndex(c)];
    column.values = new T[CharMapBits::cellsPerColumn];
    for (size_t i = 0; i < CharMapBits::cellsPerColumn; i++)
      column.values[i] = column.value;
    column.values[CharMapBits::cellIndex(c)] = val;
  }
}

template<class T>
void CharMap<T>::setRange(Char from, Char to, T val)
{
  for (; from < 256; from++) {
    lo_[from] = val;
    if (from == to)
      return;
  }
  do {
    if ((from & (CharMapBits::columnSize - 1)) == 0
        && to - from >= CharMapBits::columnSize - 1) {
      if ((from & (CharMapBits::pageSize - 1)) == 0
   && to - from >= CharMapBits::pageSize - 1) {
        if ((from & (CharMapBits::planeSize - 1)) == 0
     && to - from >= CharMapBits::planeSize - 1) {

   CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(from)];
          pl.value = val;
          delete [] pl.values;
          pl.values = 0;
   from += CharMapBits::planeSize - 1;
        }
        else {

   CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(from)];
          if (pl.values) {
     CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(from)];
     pg.value = val;
     delete [] pg.values;
     pg.values = 0;
          }
          else if (val != pl.value) {

     pl.values = new CharMapPage<T>[CharMapBits::pagesPerPlane];
            for (size_t i = 0; i < CharMapBits::pagesPerPlane; i++)
       pl.values[i].value = pl.value;
     CharMapPage<T> &page = pl.values[CharMapBits::pageIndex(from)];
            page.value = val;
   }
   from += CharMapBits::pageSize - 1;
        }
      }
      else {

 CharMapPlane<T> &pl = values_[CharMapBits::planeIndex(from)];
        if (pl.values) {
   CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(from)];
   if (pg.values) {
     CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(from)];
     column.value = val;
     delete [] column.values;
     column.values = 0;
   }
   else if (val != pg.value) {

     pg.values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
            for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
       pg.values[i].value = pg.value;
     CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(from)];
     column.value = val;
   }
        }
        else if (val != pl.value) {

   pl.values = new CharMapPage<T>[CharMapBits::pagesPerPlane];
          for (size_t i = 0; i < CharMapBits::pagesPerPlane; i++)
     pl.values[i].value = pl.value;
   CharMapPage<T> &pg = pl.values[CharMapBits::pageIndex(from)];
          pg.value = val;

   pg.values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
          for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
     pg.values[i].value = pg.value;
   CharMapColumn<T> &column = pg.values[CharMapBits::columnIndex(from)];
   column.value = val;
 }
 from += CharMapBits::columnSize - 1;
      }
    }
    else
      setChar(from, val);
  } while (from++ != to);
}

template<class T>
CharMapPlane<T>::CharMapPlane()
: values(0)
{
}

template<class T>
CharMapPlane<T>::CharMapPlane(const CharMapPlane<T> &pl)
{
  if (pl.values) {
    values = new CharMapPage<T>[CharMapBits::pagesPerPlane];
    for (size_t i = 0; i < CharMapBits::pagesPerPlane; i++)
      values[i] = pl.values[i];
  }
  else {
    value = pl.value;
    values = 0;
  }
}

template<class T>
void CharMapPlane<T>::operator=(const CharMapPlane<T> &pl)
{
  if (pl.values) {
    if (!values)
      values = new CharMapPage<T>[CharMapBits::pagesPerPlane];
    for (size_t i = 0; i < CharMapBits::pagesPerPlane; i++)
      values[i] = pl.values[i];
  }
  else {
    if (values) {
      delete [] values;
      values = 0;
    }
    value = pl.value;
  }
}

template<class T>
CharMapPlane<T>::~CharMapPlane()
{
  delete [] values;
}

template<class T>
void CharMapPlane<T>::swap(CharMapPlane<T> &pl)
{
  {
    CharMapPage<T> *tem = values;
    values = pl.values;
    pl.values = tem;
  }
  {
    T tem(value);
    value = pl.value;
    pl.value = tem;
  }
}

template<class T>
CharMapPage<T>::CharMapPage()
: values(0)
{
}

template<class T>
CharMapPage<T>::CharMapPage(const CharMapPage<T> &pg)
{
  if (pg.values) {
    values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
    for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
      values[i] = pg.values[i];
  }
  else {
    value = pg.value;
    values = 0;
  }
}

template<class T>
void CharMapPage<T>::operator=(const CharMapPage<T> &pg)
{
  if (pg.values) {
    if (!values)
      values = new CharMapColumn<T>[CharMapBits::columnsPerPage];
    for (size_t i = 0; i < CharMapBits::columnsPerPage; i++)
      values[i] = pg.values[i];
  }
  else {
    if (values) {
      delete [] values;
      values = 0;
    }
    value = pg.value;
  }
}

template<class T>
CharMapPage<T>::~CharMapPage()
{
  delete [] values;
}

template<class T>
void CharMapPage<T>::swap(CharMapPage<T> &pg)
{
  {
    CharMapColumn<T> *tem = values;
    values = pg.values;
    pg.values = tem;
  }
  {
    T tem(value);
    value = pg.value;
    pg.value = tem;
  }
}

template<class T>
CharMapColumn<T>::CharMapColumn()
: values(0)
{
}

template<class T>
CharMapColumn<T>::CharMapColumn(const CharMapColumn<T> &col)
{
  if (col.values) {
    values = new T[CharMapBits::cellsPerColumn];
    for (size_t i = 0; i < CharMapBits::cellsPerColumn; i++)
      values[i] = col.values[i];
  }
  else {
    values = 0;
    value = col.value;
  }
}

template<class T>
void CharMapColumn<T>::operator=(const CharMapColumn<T> &col)
{
  if (col.values) {
    if (!values)
      values = new T[CharMapBits::cellsPerColumn];
    for (size_t i = 0; i < CharMapBits::cellsPerColumn; i++)
      values[i] = col.values[i];
  }
  else {
    if (values) {
      delete [] values;
      values = 0;
    }
    value = col.value;
  }
}

template<class T>
CharMapColumn<T>::~CharMapColumn()
{
  delete [] values;
}
# 387 "/usr/include/OpenSP/CharMap.cxx" 3 4
}
# 229 "/usr/include/OpenSP/CharMap.h" 2 3 4
# 13 "/usr/include/OpenSP/UnivCharsetDesc.h" 2 3 4
# 1 "/usr/include/OpenSP/RangeMap.h" 1 3 4






# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 8 "/usr/include/OpenSP/RangeMap.h" 2 3 4

# 1 "/usr/include/OpenSP/ISet.h" 1 3 4







# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 9 "/usr/include/OpenSP/ISet.h" 2 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 10 "/usr/include/OpenSP/ISet.h" 2 3 4



namespace OpenSP {


template<class T> class ISetIter;

template<class T>
struct ISetRange {
  T min;
  T max;
};

template<class T>
class ISet {
public:
  ISet();
  ISet(const T *, size_t);
  ~ISet();
  Boolean contains(T) const;
  void remove(T);
  void add(T x) { addRange(x, x); }
  void addRange(T, T);



  void check();
  void operator+=(T x) { addRange(x, x); }
  void clear();
  Boolean isSingleton() const {
    return r_.size() == 1 && r_[0].min == r_[0].max;
  }
  Boolean isEmpty() const { return r_.size() == 0; }
  void swap(ISet<T> &x) { r_.swap(x.r_); }
friend class ISetIter<T>;
private:
  Vector<ISetRange<T> > r_;
};


}





# 1 "/usr/include/OpenSP/ISet.cxx" 1 3 4






# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 34 "/usr/include/stdlib.h" 2 3 4

extern "C" {






# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 43 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 63 "/usr/include/bits/waitstatus.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 64 "/usr/include/bits/waitstatus.h" 2 3 4

union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 44 "/usr/include/stdlib.h" 2 3 4
# 93 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 137 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) throw ();




extern double atof (__const char *__nptr) throw () __attribute__ ((__pure__));

extern int atoi (__const char *__nptr) throw () __attribute__ ((__pure__));

extern long int atol (__const char *__nptr) throw () __attribute__ ((__pure__));





__extension__ extern long long int atoll (__const char *__nptr)
     throw () __attribute__ ((__pure__));





extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr) throw ();





extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) throw ();

extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr) throw ();





extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base) throw ();

extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     throw ();




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base) throw ();

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     throw ();





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base) throw ();

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     throw ();

# 229 "/usr/include/stdlib.h" 3 4
extern long int strtol_l (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     __locale_t __loc) throw ();

extern unsigned long int strtoul_l (__const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, __locale_t __loc) throw ();

__extension__
extern long long int strtoll_l (__const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    __locale_t __loc) throw ();

__extension__
extern unsigned long long int strtoull_l (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, __locale_t __loc)
     throw ();

extern double strtod_l (__const char *__restrict __nptr,
   char **__restrict __endptr, __locale_t __loc)
     throw ();

extern float strtof_l (__const char *__restrict __nptr,
         char **__restrict __endptr, __locale_t __loc) throw ();

extern long double strtold_l (__const char *__restrict __nptr,
         char **__restrict __endptr,
         __locale_t __loc) throw ();






extern double __strtod_internal (__const char *__restrict __nptr,
     char **__restrict __endptr, int __group)
     throw ();
extern float __strtof_internal (__const char *__restrict __nptr,
    char **__restrict __endptr, int __group)
     throw ();
extern long double __strtold_internal (__const char *__restrict __nptr,
           char **__restrict __endptr,
           int __group) throw ();

extern long int __strtol_internal (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group) throw ();



extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group) throw ();




__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group) throw ();



__extension__
extern unsigned long long int __strtoull_internal (__const char *
         __restrict __nptr,
         char **__restrict __endptr,
         int __base, int __group)
     throw ();








extern __inline double
strtod (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtod_internal (__nptr, __endptr, 0);
}
extern __inline long int
strtol (__const char *__restrict __nptr, char **__restrict __endptr,
 int __base) throw ()
{
  return __strtol_internal (__nptr, __endptr, __base, 0);
}
extern __inline unsigned long int
strtoul (__const char *__restrict __nptr, char **__restrict __endptr,
  int __base) throw ()
{
  return __strtoul_internal (__nptr, __endptr, __base, 0);
}




extern __inline float
strtof (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtof_internal (__nptr, __endptr, 0);
}
extern __inline long double
strtold (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtold_internal (__nptr, __endptr, 0);
}




__extension__ extern __inline long long int
strtoq (__const char *__restrict __nptr, char **__restrict __endptr,
 int __base) throw ()
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtouq (__const char *__restrict __nptr, char **__restrict __endptr,
  int __base) throw ()
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}




__extension__ extern __inline long long int
strtoll (__const char *__restrict __nptr, char **__restrict __endptr,
  int __base) throw ()
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtoull (__const char * __restrict __nptr, char **__restrict __endptr,
   int __base) throw ()
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}




extern __inline double
atof (__const char *__nptr) throw ()
{
  return strtod (__nptr, (char **) __null);
}
extern __inline int
atoi (__const char *__nptr) throw ()
{
  return (int) strtol (__nptr, (char **) __null, 10);
}
extern __inline long int
atol (__const char *__nptr) throw ()
{
  return strtol (__nptr, (char **) __null, 10);
}




__extension__ extern __inline long long int
atoll (__const char *__nptr) throw ()
{
  return strtoll (__nptr, (char **) __null, 10);
}

# 408 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) throw ();


extern long int a64l (__const char *__s) throw () __attribute__ ((__pure__));




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4
extern "C" {

# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 129 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 130 "/usr/include/bits/types.h" 2 3 4






__extension__ typedef unsigned long long int __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef unsigned long long int __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef long long int __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef unsigned long long int __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef int __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef long long int __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef unsigned long long int __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef unsigned long long int __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 191 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 216 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 118 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4
# 55 "/usr/include/sys/select.h" 3 4
typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4
extern "C" {
# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 121 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);


}
# 217 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 220 "/usr/include/sys/types.h" 2 3 4




typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 258 "/usr/include/sys/types.h" 3 4
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;





# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 83 "/usr/include/bits/sched.h" 3 4
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4

typedef int __atomic_lock_t;


struct _pthread_fastlock
{
  long int __status;
  __atomic_lock_t __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;





__extension__ typedef long long __pthread_cond_align_t;




typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
   - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;




typedef struct _pthread_rwlock_t
{
  struct _pthread_fastlock __rw_lock;
  int __rw_readers;
  _pthread_descr __rw_writer;
  _pthread_descr __rw_read_waiting;
  _pthread_descr __rw_write_waiting;
  int __rw_kind;
  int __rw_pshared;
} pthread_rwlock_t;



typedef struct
{
  int __lockkind;
  int __pshared;
} pthread_rwlockattr_t;




typedef volatile int pthread_spinlock_t;


typedef struct {
  struct _pthread_fastlock __ba_lock;
  int __ba_required;
  int __ba_present;
  _pthread_descr __ba_waiting;
} pthread_barrier_t;


typedef struct {
  int __pshared;
} pthread_barrierattr_t;





typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3 4


}
# 417 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) throw ();


extern void srandom (unsigned int __seed) throw ();





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) throw ();



extern char *setstate (char *__statebuf) throw ();







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) throw ();

extern int srandom_r (unsigned int __seed, struct random_data *__buf) throw ();

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf) throw ();

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf) throw ();






extern int rand (void) throw ();

extern void srand (unsigned int __seed) throw ();




extern int rand_r (unsigned int *__seed) throw ();







extern double drand48 (void) throw ();
extern double erand48 (unsigned short int __xsubi[3]) throw ();


extern long int lrand48 (void) throw ();
extern long int nrand48 (unsigned short int __xsubi[3]) throw ();


extern long int mrand48 (void) throw ();
extern long int jrand48 (unsigned short int __xsubi[3]) throw ();


extern void srand48 (long int __seedval) throw ();
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) throw ();
extern void lcong48 (unsigned short int __param[7]) throw ();





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw ();
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw ();


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result) throw ();
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result) throw ();


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result) throw ();
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result) throw ();


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     throw ();

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) throw ();

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer) throw ();









extern void *malloc (size_t __size) throw () __attribute__ ((__malloc__));

extern void *calloc (size_t __nmemb, size_t __size)
     throw () __attribute__ ((__malloc__));







extern void *realloc (void *__ptr, size_t __size) throw () __attribute__ ((__malloc__));

extern void free (void *__ptr) throw ();




extern void cfree (void *__ptr) throw ();



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4

extern "C" {





extern void *alloca (size_t __size) throw ();





}
# 579 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) throw () __attribute__ ((__malloc__));




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     throw () __attribute__ ((__malloc__));




extern void abort (void) throw () __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) throw ();





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     throw ();






extern void exit (int __status) throw () __attribute__ ((__noreturn__));






extern void _Exit (int __status) throw () __attribute__ ((__noreturn__));






extern char *getenv (__const char *__name) throw ();




extern char *__secure_getenv (__const char *__name) throw ();





extern int putenv (char *__string) throw ();





extern int setenv (__const char *__name, __const char *__value, int __replace)
     throw ();


extern int unsetenv (__const char *__name) throw ();






extern int clearenv (void) throw ();
# 663 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) throw ();
# 674 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template);
# 683 "/usr/include/stdlib.h" 3 4
extern int mkstemp64 (char *__template);
# 693 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) throw ();








extern int system (__const char *__command);







extern char *canonicalize_file_name (__const char *__name) throw ();
# 720 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) throw ();






typedef int (*__compar_fn_t) (__const void *, __const void *);


typedef __compar_fn_t comparison_fn_t;






extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar);



extern int abs (int __x) throw () __attribute__ ((__const__));
extern long int labs (long int __x) throw () __attribute__ ((__const__));



__extension__ extern long long int llabs (long long int __x)
     throw () __attribute__ ((__const__));







extern div_t div (int __numer, int __denom)
     throw () __attribute__ ((__const__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     throw () __attribute__ ((__const__));




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     throw () __attribute__ ((__const__));

# 784 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw ();




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw ();




extern char *gcvt (double __value, int __ndigit, char *__buf) throw ();




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign) throw ();
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign) throw ();
extern char *qgcvt (long double __value, int __ndigit, char *__buf) throw ();




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw ();
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw ();

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len) throw ();
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len) throw ();







extern int mblen (__const char *__s, size_t __n) throw ();


extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) throw ();


extern int wctomb (char *__s, wchar_t __wchar) throw ();



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) throw ();

extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     throw ();








extern int rpmatch (__const char *__response) throw ();
# 866 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *__const *__restrict __tokens,
        char **__restrict __valuep) throw ();





extern void setkey (__const char *__key) throw ();







extern int posix_openpt (int __oflag);







extern int grantpt (int __fd) throw ();



extern int unlockpt (int __fd) throw ();




extern char *ptsname (int __fd) throw ();






extern int ptsname_r (int __fd, char *__buf, size_t __buflen) throw ();


extern int getpt (void);






extern int getloadavg (double __loadavg[], int __nelem) throw ();





}
# 8 "/usr/include/OpenSP/ISet.cxx" 2 3 4


namespace OpenSP {


template<class T>
ISet<T>::ISet()
{
}

template<class T>
ISet<T>::~ISet()
{
}

template<class T>
ISet<T>::ISet(const T *v, size_t n)
{
  for (size_t i = 0; i < n; i++)
    add(v[i]);
}

template<class T>
Boolean ISet<T>::contains(T x) const
{
  for (size_t i = 0; i < r_.size(); i++)
    if (r_[i].max >= x)
      return r_[i].min <= x ? 1 : 0;
  return 0;
}

template<class T>
void ISet<T>::addRange(T min, T max)
{
  size_t i;
  if (min == 0)
    i = 0;
  else {
    for (i = r_.size(); i > 0 && min - 1 <= r_[i - 1].max; i--)
      ;
  }

  if (i < r_.size() && (r_[i].min == 0 || max >= r_[i].min - 1)) {

    if (min < r_[i].min)
      r_[i].min = min;
    if (max > r_[i].max) {
      r_[i].max = max;
      size_t j;
      for (j = i + 1; j < r_.size() && r_[i].max >= r_[j].min - 1; j++)
 r_[i].max = r_[j].max;

      if (j > i + 1) {
 for (size_t k = j; k < r_.size(); k++)
   r_[k - (j - i - 1)] = r_[k];
 r_.resize(r_.size() - (j - i - 1));
      }
    }
  }
  else {


    r_.resize(r_.size() + 1);
    for (size_t j = r_.size() - 1; j > i; j--)
      r_[j] = r_[j - 1];
    r_[i].max = max;
    r_[i].min = min;
  }
}

template<class T>
void ISet<T>::remove(T c)
{
  for (size_t i = 0; i < r_.size(); i++)
    if (r_[i].max >= c) {
      if (r_[i].min <= c) {
 if (r_[i].min == r_[i].max) {
   while (++i < r_.size())
     r_[i - 1] = r_[i];
   r_.resize(r_.size() - 1);
 }
 else if (c == r_[i].min)
   r_[i].min += 1;
 else if (c == r_[i].max)
   r_[i].max -= 1;
 else {
   r_.resize(r_.size() + 1);


   for (size_t j = r_.size() - 2; j > i; j--)
     r_[j + 1] = r_[j];
   r_[i + 1].max = r_[i].max;
   r_[i + 1].min = c + 1;
   r_[i].max = c - 1;
 }
      }
      break;
    }
}

template<class T>
void ISet<T>::check()
{
  for (size_t i = 0; i < r_.size(); i++) {
    if (r_[i].min > r_[i].max)
      abort();

    if (i > 0 && r_[i].min - 1 <= r_[i - 1].max)
      abort();
  }
}

template<class T>
void ISet<T>::clear()
{
  r_.resize(0);
}


}
# 58 "/usr/include/OpenSP/ISet.h" 2 3 4
# 10 "/usr/include/OpenSP/RangeMap.h" 2 3 4

# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 12 "/usr/include/OpenSP/RangeMap.h" 2 3 4


namespace OpenSP {


template<class From, class To>
struct RangeMapRange {
  From fromMin;
  From fromMax;
  To toMin;
};

template<class From, class To> class RangeMapIter;

template<class From, class To>
class RangeMap {
public:
  RangeMap();
  Boolean map(From, To &, From &alsoMax) const;

  unsigned inverseMap(To, From &, ISet<WideChar> &, WideChar &count) const;
  void addRange(From, From, To);
private:
  Vector<RangeMapRange<From,To> > ranges_;
  friend class RangeMapIter<From,To>;
};

template<class From, class To>
class RangeMapIter {
public:
  RangeMapIter(const RangeMap<From,To> &map);
  Boolean next(From &fromMin, From &fromMax, To &toMin) {
    if (!count_)
      return 0;
    else {
      fromMin = ptr_->fromMin;
      fromMax = ptr_->fromMax;
      toMin = ptr_->toMin;
      ptr_++;
      count_--;
      return 1;
    }
  }
private:
  size_t count_;
  typename Vector<RangeMapRange<From,To> >::const_iterator ptr_;
};


}





# 1 "/usr/include/OpenSP/RangeMap.cxx" 1 3 4






# 1 "/usr/include/OpenSP/RangeMap.h" 1 3 4
# 67 "/usr/include/OpenSP/RangeMap.h" 3 4
# 1 "/usr/include/OpenSP/RangeMap.cxx" 1 3 4
# 68 "/usr/include/OpenSP/RangeMap.h" 2 3 4
# 8 "/usr/include/OpenSP/RangeMap.cxx" 2 3 4
# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 9 "/usr/include/OpenSP/RangeMap.cxx" 2 3 4

# 1 "/usr/include/OpenSP/constant.h" 1 3 4






namespace OpenSP {




const Char charMax = 0x10ffff;



const WideChar wideCharMax = WideChar(-1);
const UnivChar univCharMax = UnivChar(-1);
const SyntaxChar syntaxCharMax = SyntaxChar(-1);


}
# 11 "/usr/include/OpenSP/RangeMap.cxx" 2 3 4


namespace OpenSP {


template<class From, class To>
RangeMap<From, To>::RangeMap()
{
}

template<class From, class To>
Boolean RangeMap<From, To>::map(From from, To &to, From &alsoMax) const
{

  for (size_t i = 0; i < ranges_.size(); i++) {
    const RangeMapRange<From,To> &r = ranges_[i];
    if (r.fromMin <= from && from <= r.fromMax) {
      to = r.toMin + (from - r.fromMin);
      alsoMax = r.fromMax;
      return 1;
    }
    if (r.fromMin > from) {
      alsoMax = r.fromMin - 1;
      return 0;
    }
  }
  alsoMax = From(-1);
  return 0;
}


typedef ISet<WideChar> RangeMap_dummy;

template<class From, class To>
unsigned RangeMap<From, To>::inverseMap(To to, From &from,
     ISet<WideChar> &fromSet,
     WideChar &count) const
{

  unsigned ret = 0;
  count = wideCharMax;
  for (size_t i = 0; i < ranges_.size(); i++) {
    const RangeMapRange<From,To> &r = ranges_[i];
    if (r.toMin <= to && to <= r.toMin + (r.fromMax - r.fromMin)) {
      From n = r.fromMin + (to - r.toMin);
      WideChar thisCount = r.fromMax - n + 1;
      if (ret > 1) {
 fromSet.add(n);
 if (thisCount < count)
   count = thisCount;
      }
      else if (ret == 1) {
 fromSet.add(from);
 fromSet.add(n);
 ret = 2;
 if (thisCount < count)
   count = thisCount;
      }
      else {
 count = thisCount;
 from = n;
 ret = 1;
      }
    }
    else if (ret == 0 && r.toMin > to && (r.toMin - to < count))
      count = r.toMin - to;
  }
  return ret;
}

template<class From, class To>
RangeMapIter<From, To>::RangeMapIter(const RangeMap<From, To> &map)
: count_(map.ranges_.size()), ptr_(map.ranges_.begin())
{
}




template<class From, class To>
void RangeMap<From, To>::addRange(From fromMin, From fromMax, To toMin)
{

  size_t i;
  for (i = ranges_.size(); i > 0; i--)
    if (fromMin > ranges_[i - 1].fromMax)
      break;

  Boolean coalesced = 0;
  if (i > 0
      && ranges_[i - 1].fromMax + 1 == fromMin
      && ranges_[i - 1].toMin + (fromMin - ranges_[i - 1].fromMin) == toMin) {

    ranges_[i - 1].fromMax = fromMax;
    i--;
    coalesced = 1;
  }
  else if (i < ranges_.size() && fromMax >= ranges_[i].fromMin - 1) {

    if (fromMin <= ranges_[i].fromMin) {
      if (toMin + (ranges_[i].fromMin - fromMin) == ranges_[i].toMin) {
 ranges_[i].fromMin = fromMin;
 if (fromMax <= ranges_[i].fromMax)
   return;
 ranges_[i].fromMax = fromMax;
 coalesced = 1;
      }
    }
    else {

      if (ranges_[i].toMin + (fromMin - ranges_[i].fromMin) == toMin) {
 if (fromMax < ranges_[i].fromMax)
   return;
 ranges_[i].fromMax = fromMax;
 coalesced = 1;
      }
    }
  }
  if (!coalesced) {

    ranges_.resize(ranges_.size() + 1);
    for (size_t j = ranges_.size() - 1; j > i; j--)
      ranges_[j] = ranges_[j - 1];
    ranges_[i].fromMin = fromMin;
    ranges_[i].fromMax = fromMax;
    ranges_[i].toMin = toMin;
  }

  size_t j;
  for (j = i + 1; j < ranges_.size(); j++) {
    if (fromMax < ranges_[j].fromMax) {
      if (fromMax >= ranges_[j].fromMin)
 ranges_[j].fromMin = fromMax + 1;
      break;
    }
  }
  if (j > i + 1) {



    size_t count = ranges_.size() - j;
    for (size_t k = 0; k < count; k++)
      ranges_[i + 1 + count] = ranges_[j + count];
    ranges_.resize(ranges_.size() - (j - (i + 1)));
  }
}


}
# 68 "/usr/include/OpenSP/RangeMap.h" 2 3 4
# 14 "/usr/include/OpenSP/UnivCharsetDesc.h" 2 3 4

# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 16 "/usr/include/OpenSP/UnivCharsetDesc.h" 2 3 4



namespace OpenSP {


class UnivCharsetDesc {
public:
  struct Range {
    WideChar descMin;


    unsigned long count;
    UnivChar univMin;
  };
  enum {
    zero = 48,
    A = 65,
    a = 97,
    tab = 9,
    rs = 10,
    re = 13,
    space = 32,
    exclamation = 33,
    lessThan = 60,
    greaterThan = 62
    };
  UnivCharsetDesc();
  UnivCharsetDesc(const Range *, size_t);
  void set(const Range *, size_t);
  Boolean descToUniv(WideChar from, UnivChar &to) const;
  Boolean descToUniv(WideChar from, UnivChar &to, WideChar &alsoMax) const;

  unsigned univToDesc(UnivChar from, WideChar &to, ISet<WideChar> &toSet)
       const;
  unsigned univToDesc(UnivChar from, WideChar &to, ISet<WideChar> &toSet,
        WideChar &count)
       const;
  void addRange(WideChar descMin, WideChar descMax, UnivChar univMin);
  void addBaseRange(const UnivCharsetDesc &baseSet,
      WideChar descMin,
      WideChar descMax,
      WideChar baseMin,
      ISet<WideChar> &baseMissing);
private:
  static Boolean noDesc(Unsigned32 n) {
    return (n & (unsigned(1) << 31));
  }
  static UnivChar extractChar(Unsigned32 n, Char ch) {
    return UnivChar((n + ch) & ((unsigned(1) << 31) - 1));
  }
  static Unsigned32 wrapChar(UnivChar univ, Char ch) {
    return Unsigned32((univ - ch) & ((unsigned(1) << 31) - 1));
  }

  CharMap<Unsigned32> charMap_;

  RangeMap<WideChar,UnivChar> rangeMap_;
  friend class UnivCharsetDescIter;
};

class UnivCharsetDescIter {
public:
  UnivCharsetDescIter(const UnivCharsetDesc &);
  Boolean next(WideChar &descMin, WideChar &descMax, UnivChar &univMin);
  void skipTo(WideChar);
private:
  const CharMap<Unsigned32> *charMap_;
  Char nextChar_;
  Boolean doneCharMap_;
  RangeMapIter<WideChar,UnivChar> rangeMapIter_;
};

inline
Boolean UnivCharsetDesc::descToUniv(WideChar from, UnivChar &to) const
{
  if (from > charMax) {
    WideChar tem;
    return rangeMap_.map(from, to, tem);
  }
  else {
    Unsigned32 tem = charMap_[from];
    if (noDesc(tem))
      return 0;
    else {
      to = extractChar(tem, from);
      return 1;
    }
  }
}

inline
Boolean UnivCharsetDesc::descToUniv(WideChar from, UnivChar &to,
        WideChar &alsoMax) const
{
  if (from > charMax)
    return rangeMap_.map(from, to, alsoMax);
  else {
    Char max;
    Unsigned32 tem = charMap_.getRange(from, max);
    alsoMax = max;
    if (noDesc(tem))
      return 0;
    else {
      to = extractChar(tem, from);
      return 1;
    }
  }
}

inline
unsigned UnivCharsetDesc::univToDesc(UnivChar from, WideChar &to,
         ISet<WideChar> &toSet) const
{
  WideChar tem;
  return univToDesc(from, to, toSet, tem);
}

inline
void UnivCharsetDescIter::skipTo(WideChar ch)
{
  if (ch > charMax)
    doneCharMap_ = 1;
  else
    nextChar_ = ch;
}


}
# 12 "/usr/include/OpenSP/CharsetInfo.h" 2 3 4



# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 16 "/usr/include/OpenSP/CharsetInfo.h" 2 3 4
# 1 "/usr/include/OpenSP/CharMap.h" 1 3 4
# 17 "/usr/include/OpenSP/CharsetInfo.h" 2 3 4


namespace OpenSP {


class CharsetInfo {
public:
  CharsetInfo();
  CharsetInfo(const UnivCharsetDesc &);
  void set(const UnivCharsetDesc &);



  Char execToDesc(char) const;
  StringC execToDesc(const char *s) const;
  Boolean descToUniv(WideChar from, UnivChar &to) const;
  Boolean descToUniv(WideChar from, UnivChar &to, WideChar &alsoMax) const;



  unsigned univToDesc(UnivChar from, WideChar &to, ISet<WideChar> &toSet)
       const;
  unsigned univToDesc(UnivChar from, WideChar &to, ISet<WideChar> &toSet,
        WideChar &count)
       const;
  void getDescSet(ISet<Char> &) const;
  int digitWeight(Char) const;
  int hexDigitWeight(Char) const;
  const UnivCharsetDesc &desc() const;
private:
  void init();
  UnivCharsetDesc desc_;
  CharMap<Unsigned32> inverse_;
  Char execToDesc_[(127 * 2 + 1) + 1];
};

inline
unsigned CharsetInfo::univToDesc(UnivChar from, WideChar &to,
     ISet<WideChar> &toSet)
     const
{
  if (from <= charMax) {
    Unsigned32 n = inverse_[from];
    if (n == Unsigned32(-1))
      return 0;
    if (n != Unsigned32(-2)) {
      to = ((n + from) & ((Unsigned32(1) << 31) - 1));
      return 1;
    }
  }
  return desc_.univToDesc(from, to, toSet);
}

inline
unsigned CharsetInfo::univToDesc(UnivChar from, WideChar &to,
     ISet<WideChar> &toSet, WideChar &count)
     const
{
  if (from <= charMax) {
    Char fromMax;
    Unsigned32 n = inverse_.getRange(from, fromMax);
    if (n == Unsigned32(-1)) {
      count = (fromMax - from) + 1;
      return 0;
    }
    if (n != Unsigned32(-2)) {
      to = ((n + from) & ((Unsigned32(1) << 31) - 1));
      count = (fromMax - from) + 1;
      return 1;
    }
  }
  return desc_.univToDesc(from, to, toSet, count);
}

inline
Boolean CharsetInfo::descToUniv(UnivChar from, WideChar &to) const
{
  return desc_.descToUniv(from, to);
}

inline
Char CharsetInfo::execToDesc(char c) const
{
  return execToDesc_[(unsigned char)c];
}

inline
Boolean CharsetInfo::descToUniv(WideChar from, UnivChar &to,
    WideChar &alsoMax) const
{
  return desc_.descToUniv(from, to, alsoMax);
}

inline
const UnivCharsetDesc &CharsetInfo::desc() const
{
  return desc_;
}


}
# 14 "/usr/include/OpenSP/Sd.h" 2 3 4

# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 16 "/usr/include/OpenSP/Sd.h" 2 3 4
# 1 "/usr/include/OpenSP/Syntax.h" 1 3 4






#pragma interface




# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 13 "/usr/include/OpenSP/Syntax.h" 2 3 4


# 1 "/usr/include/OpenSP/HashTable.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/HashTable.h" 2 3 4
# 1 "/usr/include/OpenSP/OwnerTable.h" 1 3 4






# 1 "/usr/include/OpenSP/PointerTable.h" 1 3 4






# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 8 "/usr/include/OpenSP/PointerTable.h" 2 3 4

# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 10 "/usr/include/OpenSP/PointerTable.h" 2 3 4


namespace OpenSP {


template<class P, class K, class HF, class KF> class PointerTableIter;

template<class P, class K, class HF, class KF>
class PointerTable {
  void constraints() {
    P p(0);
    const K &key = KF::key(*p);
    unsigned long n = HF::hash(key);
    n = 0;
  }
public:
  PointerTable();
  P insert(P, Boolean replace = 0);


  const P &lookup(const K &) const;
  P remove(const K &);
  size_t count() const { return used_; }
  void clear();
  void swap(PointerTable<P, K, HF, KF> &);
protected:
  size_t used_;
  size_t usedLimit_;
  Vector<P> vec_;
  P null_;

  size_t startIndex(const K &k) const {
    return size_t(HF::hash(k) & (vec_.size() - 1));
  }
  size_t nextIndex(size_t i) const {
    return i == 0 ? vec_.size() - 1 : i - 1;
  }
  friend class PointerTableIter<P, K, HF, KF>;
};

template<class P, class K, class HF, class KF>
class PointerTableIter {
public:
  PointerTableIter(const PointerTable<P, K, HF, KF> &);
  const P &next();
private:
  const PointerTable<P, K, HF, KF> *tablePtr_;
  size_t i_;
};


}





# 1 "/usr/include/OpenSP/PointerTable.cxx" 1 3 4
# 10 "/usr/include/OpenSP/PointerTable.cxx" 3 4
namespace OpenSP {


template<class P, class K, class HF, class KF>
PointerTable<P, K, HF, KF>::PointerTable()
: used_(0), usedLimit_(0), null_(0)
{
}

template<class P, class K, class HF, class KF>
void PointerTable<P, K, HF, KF>::clear()
{
  vec_.clear();
  used_ = 0;
  usedLimit_ = 0;
}

template<class P, class K, class HF, class KF>
P PointerTable<P, K, HF, KF>::insert(P p, Boolean replace)
{
  size_t h;
  if (vec_.size() == 0) {
    vec_.assign(8, P(0));
    usedLimit_ = 4;
    h = startIndex(KF::key(*p));
  }
  else {
    for (h = startIndex(KF::key(*p)); vec_[h] != 0 ; h = nextIndex(h))
      if (KF::key(*vec_[h]) == KF::key(*p)) {
 if (replace) {
   P tem(vec_[h]);
   vec_[h] = p;
   return tem;
 }
 else
   return vec_[h];
      }
    if (used_ >= usedLimit_) {
      if (vec_.size() > size_t(-1)/2) {
 if (usedLimit_ == vec_.size() - 1)
   abort();
 else
   usedLimit_ = vec_.size() - 1;
      }
      else {

 Vector<P> oldVec(vec_.size()*2, P(0));
 vec_.swap(oldVec);
 usedLimit_ = vec_.size() / 2;
 for (size_t i = 0; i < oldVec.size(); i++)
   if (oldVec[i] != 0) {
     size_t j;
     for (j = startIndex(KF::key(*oldVec[i]));
   vec_[j] != 0;
   j = nextIndex(j))
       ;
     vec_[j] = oldVec[i];
   }
 for (h = startIndex(KF::key(*p)); vec_[h] != 0; h = nextIndex(h))
   ;
      }
    }
  }
  used_++;
  vec_[h] = p;
  return 0;
}

template<class P, class K, class HF, class KF>
const P &PointerTable<P, K, HF, KF>::lookup(const K &k) const
{
  if (used_ > 0) {
    for (size_t i = startIndex(k); vec_[i] != 0; i = nextIndex(i))
      if (KF::key(*vec_[i]) == k)
 return vec_[i];
  }
  return null_;
}

template<class P, class K, class HF, class KF>
P PointerTable<P, K, HF, KF>::remove(const K &k)
{
  if (used_ > 0) {
    for (size_t i = startIndex(k); vec_[i] != 0; i = nextIndex(i))
      if (KF::key(*vec_[i]) == k) {
 P p = vec_[i];
 do {
   vec_[i] = P(0);
   size_t j = i;
   size_t r;
   do {
     i = nextIndex(i);
     if (vec_[i] == 0)
       break;
     r = startIndex(KF::key(*vec_[i]));
   } while ((i <= r && r < j) || (r < j && j < i) || (j < i && i <= r));
   vec_[j] = vec_[i];
 } while (vec_[i] != 0);
 --used_;
 return p;
      }
  }
  return 0;
}

template<class P, class K, class HF, class KF>
void PointerTable<P, K, HF, KF>::swap(PointerTable<P, K, HF, KF> &to)
{
  vec_.swap(to.vec_);
  size_t tem = to.used_;
  to.used_ = used_;
  used_ = tem;
  tem = to.usedLimit_;
  to.usedLimit_ = usedLimit_;
  usedLimit_ = tem;
}

template<class P, class K, class HF, class KF>
PointerTableIter<P, K, HF, KF>::PointerTableIter(const PointerTable<P, K, HF, KF> &table)
: tablePtr_(&table), i_(0)
{
}

template<class P, class K, class HF, class KF>
const P &PointerTableIter<P, K, HF, KF>::next()
{
  for (; i_ < tablePtr_->vec_.size(); i_++)
    if (tablePtr_->vec_[i_] != 0)
      return tablePtr_->vec_[i_++];
  return tablePtr_->null_;
}


}
# 68 "/usr/include/OpenSP/PointerTable.h" 2 3 4
# 8 "/usr/include/OpenSP/OwnerTable.h" 2 3 4


namespace OpenSP {


template<class T, class K, class HF, class KF>
class OwnerTable : public PointerTable<T *, K, HF, KF> {
public:
  OwnerTable() { }
  ~OwnerTable();
  void clear();
  void swap(OwnerTable<T, K, HF, KF> &x) {
    PointerTable<T *, K, HF, KF>::swap(x);
  }
private:
  OwnerTable(const OwnerTable<T, K, HF, KF> &);
  void operator=(const OwnerTable<T, K, HF, KF> &);
};

template<class T, class K, class HF, class KF>
class OwnerTableIter : public PointerTableIter<T *, K, HF, KF> {
public:
  OwnerTableIter(const OwnerTable<T, K, HF, KF> &table)
    : PointerTableIter<T *, K, HF, KF>(table) { }
};

template<class T, class K, class HF, class KF>
class CopyOwnerTable : public OwnerTable<T, K, HF, KF> {
public:
  CopyOwnerTable() { }
  CopyOwnerTable(const CopyOwnerTable<T, K, HF, KF> &tab) { *this = tab; }
  void operator=(const CopyOwnerTable<T, K, HF, KF> &tab);
};


}





# 1 "/usr/include/OpenSP/OwnerTable.cxx" 1 3 4







namespace OpenSP {




template<class T, class K, class HF, class KF>
OwnerTable<T, K, HF, KF>::~OwnerTable()
{
  for (size_t i = 0; i < this->vec_.size(); i++)
    delete this->vec_[i];
}

template<class T, class K, class HF, class KF>
void OwnerTable<T, K, HF, KF>::clear()
{
  for (size_t i = 0; i < this->vec_.size(); i++)
    delete this->vec_[i];
  PointerTable<T *, K, HF, KF>::clear();
}

template<class T, class K, class HF, class KF>
void
CopyOwnerTable<T, K, HF, KF>::operator=(const CopyOwnerTable<T, K, HF, KF> &t)
{
  this->clear();
  PointerTable<T *, K, HF, KF>::operator=(t);

  for (size_t i = 0; i < this->vec_.size(); i++)
    if (this->vec_[i])
      this->vec_[i] = this->vec_[i]->copy();
}


}
# 50 "/usr/include/OpenSP/OwnerTable.h" 2 3 4
# 9 "/usr/include/OpenSP/HashTable.h" 2 3 4
# 1 "/usr/include/OpenSP/Hash.h" 1 3 4






#pragma interface





namespace OpenSP {


class Hash {
public:
  static unsigned long hash(const StringC &);
};


}
# 10 "/usr/include/OpenSP/HashTable.h" 2 3 4

# 1 "/usr/include/OpenSP/HashTableItemBase.h" 1 3 4
# 11 "/usr/include/OpenSP/HashTableItemBase.h" 3 4
namespace OpenSP {


template<class K>
class HashTableItemBase {
public:
  HashTableItemBase(const K &k);
  virtual ~HashTableItemBase();
  virtual HashTableItemBase<K> *copy() const = 0;
  K key;
};

template<class K>
struct HashTableKeyFunction {
  static inline const K &key(const HashTableItemBase<K> &obj) {
    return obj.key;
  }
};


}





# 1 "/usr/include/OpenSP/HashTableItemBase.cxx" 1 3 4







namespace OpenSP {


template<class K>
HashTableItemBase<K>::~HashTableItemBase()
{
}

template<class K>
HashTableItemBase<K>::HashTableItemBase(const K &k) : key(k)
{
}



}
# 38 "/usr/include/OpenSP/HashTableItemBase.h" 2 3 4
# 12 "/usr/include/OpenSP/HashTable.h" 2 3 4


namespace OpenSP {


template<class K, class V>
class HashTableItem : public HashTableItemBase<K> {
public:
  HashTableItem(const K &k, const V &v);
  HashTableItemBase<K> *copy() const;
  V value;
};

template<class K, class V> class HashTableIter;

template<class K, class V>
class HashTable {
public:
  HashTable() { }
  void insert(const K &key, const V &value, Boolean replace = 1);
  const V *lookup(const K &key) const {
    HashTableItem<K, V> *tem = (HashTableItem<K, V> *)table_.lookup(key);
    return tem ? &tem->value : 0;
  }
  size_t count() const { return table_.count(); }
private:
  CopyOwnerTable<HashTableItemBase<K>, K, Hash, HashTableKeyFunction<K> > table_;
friend class HashTableIter<K,V>;
};

template<class K, class V>
class HashTableIter {
public:
  HashTableIter(const HashTable<K, V> &table) : iter_(table.table_) { }
  Boolean next(const K *&key, const V *&value) {
    HashTableItem<K, V> *p = (HashTableItem<K, V> *)iter_.next();
    if (p) {
      key = &p->key;
      value = &p->value;
      return 1;
    }
    else
      return 0;
  }
private:
  OwnerTableIter<HashTableItemBase<K>, K, Hash, HashTableKeyFunction<K> > iter_;
};


}





# 1 "/usr/include/OpenSP/HashTable.cxx" 1 3 4







namespace OpenSP {


template<class K, class V>
void HashTable<K,V>::insert(const K &key, const V &value, Boolean replace)
{
  HashTableItem<K, V> *newItem = new HashTableItem<K, V>(key, value);
  HashTableItem<K, V> *tem = (HashTableItem<K, V> *)table_.insert(newItem);
  if (tem) {
    delete newItem;
    if (replace) {
      tem->key = key;
      tem->value = value;
    }
  }
}

template<class K, class V>
HashTableItem<K,V>::HashTableItem(const K &k, const V &v)
: HashTableItemBase<K>(k), value(v)
{
}

template<class K, class V>
HashTableItemBase<K> *HashTableItem<K,V>::copy() const
{
  return new HashTableItem<K, V>(*this);
}


}
# 68 "/usr/include/OpenSP/HashTable.h" 2 3 4
# 16 "/usr/include/OpenSP/Syntax.h" 2 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 17 "/usr/include/OpenSP/Syntax.h" 2 3 4

# 1 "/usr/include/OpenSP/XcharMap.h" 1 3 4
# 9 "/usr/include/OpenSP/XcharMap.h" 3 4
# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 10 "/usr/include/OpenSP/XcharMap.h" 2 3 4

# 1 "/usr/include/OpenSP/CharMap.h" 1 3 4
# 12 "/usr/include/OpenSP/XcharMap.h" 2 3 4


namespace OpenSP {


template<class T>
class SharedXcharMap : public Resource {
public:
  SharedXcharMap();
  SharedXcharMap(T defaultValue);
  T *ptr() { return v + 1; }
private:

  T v[2 + 0xffff];



};

template<class T>
class XcharMap {
public:
  XcharMap();
  XcharMap(T defaultValue);
  T operator[](Xchar c) const;
  void setRange(Char min, Char max, T val);
  void setChar(Char c, T val);
  void setEe(T val);
  void clear();
private:
  T *ptr_;
  Ptr<SharedXcharMap<T> > sharedMap_;

  Ptr<CharMapResource<T> > hiMap_;

};


template<class T>
inline
T XcharMap<T>::operator[](Xchar c) const
{

  if (c > 0xffff)
    return hiMap_->operator[]((Char)c);

  return ptr_[c];
}

template<class T>
inline
void XcharMap<T>::setChar(Char c, T val)
{

  if (c > 0xffff) {
    hiMap_->setChar(c, val);
    return;
  }

  ptr_[c] = val;
}

template<class T>
inline
void XcharMap<T>::setEe(T val)
{
  ptr_[-1] = val;
}

template<class T>
inline
void XcharMap<T>::clear()
{
  ptr_ = 0;
  sharedMap_.clear();

  hiMap_.clear();

}


}





# 1 "/usr/include/OpenSP/XcharMap.cxx" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/XcharMap.cxx" 2 3 4


namespace OpenSP {


template<class T>
SharedXcharMap<T>::SharedXcharMap()
{
}

template<class T>
SharedXcharMap<T>::SharedXcharMap(T defaultValue)
{
  for (size_t i = 0; i < sizeof(v)/sizeof(v[0]); i++)
    v[i] = defaultValue;
}

template<class T>
XcharMap<T>::XcharMap()
: ptr_(0)
{
}

template<class T>
XcharMap<T>::XcharMap(T defaultValue)
: sharedMap_(new SharedXcharMap<T>(defaultValue))

  , hiMap_(new CharMapResource<T>(defaultValue))

{
  ptr_ = sharedMap_->ptr();
}

template<class T>
void XcharMap<T>::setRange(Char min, Char max, T val)
{
  if (min <= max) {

    if (min <= 0xffff) {
      Char m = max <= 0xffff ? max : 0xffff;



      do {
 ptr_[min] = val;
      } while (min++ != m);

    }
    if (max >= 0x10000)
      hiMap_->setRange(min < 0x10000 ? 0x10000 : min, max, val);

  }
}


}
# 100 "/usr/include/OpenSP/XcharMap.h" 2 3 4
# 19 "/usr/include/OpenSP/Syntax.h" 2 3 4
# 1 "/usr/include/OpenSP/EntityCatalog.h" 1 3 4




#pragma interface
# 14 "/usr/include/OpenSP/EntityCatalog.h" 3 4
namespace OpenSP {


class Messenger;
class CharsetInfo;
class EntityDecl;

class EntityCatalog : public Resource {
public:
  class Syntax {
  public:
    virtual Boolean namecaseGeneral() const = 0;
    virtual Boolean namecaseEntity() const = 0;
    virtual const SubstTable &upperSubstTable() const = 0;
    virtual const StringC &peroDelim() const = 0;
  };
  virtual ~EntityCatalog();
  virtual Boolean sgmlDecl(const CharsetInfo &,
      Messenger &,
      const StringC &,
      StringC &) const;
  virtual Boolean lookup(const EntityDecl &,
    const Syntax &,
    const CharsetInfo &,
    Messenger &,
    StringC &) const;
  virtual Boolean lookupPublic(const StringC &,
          const CharsetInfo &,
          Messenger &,
          StringC &) const;


  virtual Boolean lookupChar(const StringC &,
                             const CharsetInfo &,
        Messenger &,
        UnivChar &) const;
};


}
# 20 "/usr/include/OpenSP/Syntax.h" 2 3 4


namespace OpenSP {


class Sd;
class CharsetInfo;

class Syntax : public Resource, public EntityCatalog::Syntax {
public:
  enum ReservedName {
    rALL,
    rANY,
    rATTLIST,
    rCDATA,
    rCONREF,
    rCURRENT,
    rDATA,
    rDEFAULT,
    rDOCTYPE,
    rELEMENT,
    rEMPTY,
    rENDTAG,
    rENTITIES,
    rENTITY,
    rFIXED,
    rID,
    rIDLINK,
    rIDREF,
    rIDREFS,
    rIGNORE,
    rIMPLICIT,
    rIMPLIED,
    rINCLUDE,
    rINITIAL,
    rLINK,
    rLINKTYPE,
    rMD,
    rMS,
    rNAME,
    rNAMES,
    rNDATA,
    rNMTOKEN,
    rNMTOKENS,
    rNOTATION,
    rNUMBER,
    rNUMBERS,
    rNUTOKEN,
    rNUTOKENS,
    rO,
    rPCDATA,
    rPI,
    rPOSTLINK,
    rPUBLIC,
    rRCDATA,
    rRE,
    rREQUIRED,
    rRESTORE,
    rRS,
    rSDATA,
    rSHORTREF,
    rSIMPLE,
    rSPACE,
    rSTARTTAG,
    rSUBDOC,
    rSYSTEM,
    rTEMP,
    rUSELINK,
    rUSEMAP
  };
  enum { nNames = rUSEMAP + 1 };
  enum Quantity {
    qATTCNT,
    qATTSPLEN,
    qBSEQLEN,
    qDTAGLEN,
    qDTEMPLEN,
    qENTLVL,
    qGRPCNT,
    qGRPGTCNT,
    qGRPLVL,
    qLITLEN,
    qNAMELEN,
    qNORMSEP,
    qPILEN,
    qTAGLEN,
    qTAGLVL
  };
  enum { nQuantity = qTAGLVL + 1 };
  enum { unlimited = 100000000 };
  enum DelimGeneral {
    dAND,
    dCOM,
    dCRO,
    dDSC,
    dDSO,
    dDTGC,
    dDTGO,
    dERO,
    dETAGO,
    dGRPC,
    dGRPO,
    dHCRO,
    dLIT,
    dLITA,
    dMDC,
    dMDO,
    dMINUS,
    dMSC,
    dNET,
    dNESTC,
    dOPT,
    dOR,
    dPERO,
    dPIC,
    dPIO,
    dPLUS,
    dREFC,
    dREP,
    dRNI,
    dSEQ,
    dSTAGO,
    dTAGC,
    dVI
  };
  enum { nDelimGeneral = dVI + 1 };
  enum StandardFunction {
    fRE,
    fRS,
    fSPACE
  };
  enum FunctionClass {
    cFUNCHAR,
    cSEPCHAR,
    cMSOCHAR,
    cMSICHAR,
    cMSSCHAR
  };
  enum Set {
    nameStart,
    digit,
    hexDigit,
    nmchar,
    s,
    blank,
    sepchar,
    minimumData,
    significant,
    functionChar,
    sgmlChar
  };
  enum { nSet = sgmlChar + 1 };
  enum Category {
    otherCategory = 0,
    sCategory = 01,
    nameStartCategory = 02,
    digitCategory = 04,
    otherNameCategory = 010
    };

  Syntax(const Sd &);
  Boolean lookupFunctionChar(const StringC &, Char *) const;
  HashTableIter<StringC,Char> functionIter() const;
  Boolean charFunctionName(Char c, const StringC *&name) const;
  Boolean lookupReservedName(const StringC &, ReservedName *) const;
  const StringC &reservedName(ReservedName) const;
  StringC rniReservedName(ReservedName) const;
  Number quantity(Quantity) const;
  Char standardFunction(int) const;
  Boolean getStandardFunction(int, Char &) const;
  const StringC &delim() const;
  const ISet<Char> *charSet(int i) const;
  const SubstTable *generalSubstTable() const;
  const SubstTable *entitySubstTable() const;
  const SubstTable &upperSubstTable() const;
  Boolean namecaseGeneral() const;
  Boolean namecaseEntity() const;
  const StringC &peroDelim() const;
  const StringC &delimGeneral(int) const;
  const StringC &delimShortrefComplex(size_t) const;
  const ISet<Char> &delimShortrefSimple() const;
  int nDelimShortrefComplex() const;
  Boolean isValidShortref(const StringC &) const;
  Boolean hasShortrefs() const;
  Boolean isNameCharacter(Xchar) const;
  Boolean isNameStartCharacter(Xchar) const;
  Boolean isDigit(Xchar) const;
  Boolean isHexDigit(Xchar) const;
  Boolean isS(Xchar) const;
  Boolean isB(Xchar c) const;
  Category charCategory(Xchar) const;
  Boolean isSgmlChar(Xchar) const;
  size_t attcnt() const;
  size_t attsplen() const;
  size_t namelen() const;
  size_t penamelen() const;
  size_t litlen() const;
  size_t normsep() const;
  size_t dtemplen() const;
  size_t grpcnt() const;
  size_t grpgtcnt() const;
  size_t grplvl() const;
  size_t taglvl() const;
  size_t taglen() const;
  size_t entlvl() const;
  size_t pilen() const;
  Char space() const;

  void setStandardFunction(StandardFunction, Char);
  void enterStandardFunctionNames();
  void addFunctionChar(const StringC &, FunctionClass, Char);
  void setNamecaseGeneral(Boolean);
  void setNamecaseEntity(Boolean);
  void setDelimGeneral(int, const StringC &);
  void addDelimShortref(const StringC &, const CharsetInfo &);
  void addDelimShortrefs(const ISet<Char> &shortrefChars,
    const CharsetInfo &charset);
  void addNameCharacters(const ISet<Char> &);
  void addNameStartCharacters(const ISet<Char> &);
  void addSubst(Char lc, Char uc);
  void addShunchar(Char);
  void setShuncharControls();
  void setQuantity(int, Number);
  void setName(int, const StringC &);
  void setSgmlChar(const ISet<Char> &);
  void implySgmlChar(const Sd &);

  void checkSgmlChar(const Sd &,
       const ::OpenSP:: Syntax *otherSyntax,
       Boolean invalidUseDocumentCharset,
       ISet<WideChar> &invalid)
       const;
  static int referenceQuantity(Quantity);
  const XcharMap<unsigned char> &markupScanTable() const;
  Boolean multicode() const;
  void addEntity(const StringC &, Char);
  size_t nEntities() const;
  const StringC &entityName(size_t) const;
  Char entityChar(size_t) const;
private:
  void subst(Char, Char);
  void checkUnivControlChar(UnivChar univChar,
       const CharsetInfo &docCharset,
       const ::OpenSP:: Syntax *otherSyntax,
       ISet<WideChar> &invalid) const;

  ISet<Char> shunchar_;
  PackedBoolean shuncharControls_;
  ISet<Char> set_[nSet];
  Char standardFunction_[3];
  PackedBoolean standardFunctionValid_[3];
  Boolean namecaseGeneral_;
  Boolean namecaseEntity_;
  StringC delimGeneral_[nDelimGeneral];
  Vector<StringC> delimShortrefComplex_;
  ISet<Char> delimShortrefSimple_;
  StringC names_[nNames];
  Number quantity_[nQuantity];
  HashTable<StringC,int> nameTable_;
  HashTable<StringC,Char> functionTable_;
  SubstTable upperSubst_;
  SubstTable identitySubst_;
  const SubstTable *generalSubst_;
  const SubstTable *entitySubst_;
  XcharMap<unsigned char> categoryTable_;
  Boolean multicode_;
  XcharMap<unsigned char> markupScanTable_;
  Boolean hasMarkupScanTable_;
  Vector<StringC> entityNames_;
  StringC entityChars_;
  static const int referenceQuantity_[];
};

inline Number Syntax::quantity(Quantity q) const
{
  return quantity_[q];
}

inline void Syntax::setQuantity(int i, Number n)
{
  quantity_[i] = n;
}

inline const SubstTable *Syntax::generalSubstTable() const
{
  return generalSubst_;
}

inline const SubstTable *Syntax::entitySubstTable() const
{
  return entitySubst_;
}

inline int Syntax::nDelimShortrefComplex() const
{
  return int(delimShortrefComplex_.size());
}

inline const StringC &Syntax::delimGeneral(int i) const
{
  return delimGeneral_[i];
}

inline const StringC &Syntax::delimShortrefComplex(size_t i) const
{
  return delimShortrefComplex_[i];
}

inline const ISet<Char> &Syntax::delimShortrefSimple() const
{
  return delimShortrefSimple_;
}

inline Boolean Syntax::hasShortrefs() const
{
  return delimShortrefComplex_.size() > 0 || !delimShortrefSimple_.isEmpty();
}

inline Char Syntax::standardFunction(int i) const
{
  return standardFunction_[i];
}

inline Boolean Syntax::getStandardFunction(int i, Char &result) const
{
  if (standardFunctionValid_[i]) {
    result = standardFunction_[i];
    return 1;
  }
  else
    return 0;
}

inline const ISet<Char> *Syntax::charSet(int i) const
{
  return &set_[i];
}

inline Boolean Syntax::isNameCharacter(Xchar c) const
{
  return categoryTable_[c] >= nameStartCategory;
}

inline Boolean Syntax::isNameStartCharacter(Xchar c) const
{
  return categoryTable_[c] == nameStartCategory;
}

inline Boolean Syntax::isDigit(Xchar c) const
{
  return categoryTable_[c] == digitCategory;
}

inline Boolean Syntax::isS(Xchar c) const
{
  return categoryTable_[c] == sCategory;
}

inline Boolean Syntax::isB(Xchar c) const
{
  return (categoryTable_[c] == sCategory
   && !(standardFunctionValid_[fRE] && c == standardFunction_[fRE])
   && !(standardFunctionValid_[fRS] && c == standardFunction_[fRS]));
}

inline Syntax::Category Syntax::charCategory(Xchar c) const
{
  return Category(categoryTable_[c]);
}

inline Boolean Syntax::isSgmlChar(Xchar c) const
{
  return c >= 0 && set_[sgmlChar].contains(Char(c));
}

inline const StringC &Syntax::reservedName(ReservedName i) const
{
  return names_[i];
}

inline size_t Syntax::attcnt() const
{
  return quantity(Syntax::qATTCNT);
}

inline size_t Syntax::attsplen() const
{
  return quantity(Syntax::qATTSPLEN);
}

inline size_t Syntax::namelen() const
{
  return quantity(Syntax::qNAMELEN);
}

inline size_t Syntax::penamelen() const
{
  return quantity(Syntax::qNAMELEN) - delimGeneral(Syntax::dPERO).size();
}

inline size_t Syntax::litlen() const
{
  return quantity(Syntax::qLITLEN);
}

inline size_t Syntax::normsep() const
{
  return quantity(Syntax::qNORMSEP);
}

inline size_t Syntax::dtemplen() const
{
  return quantity(Syntax::qDTEMPLEN);
}

inline size_t Syntax::grpcnt() const
{
  return quantity(Syntax::qGRPCNT);
}

inline size_t Syntax::grpgtcnt() const
{
  return quantity(Syntax::qGRPGTCNT);
}

inline size_t Syntax::grplvl() const
{
  return quantity(Syntax::qGRPLVL);
}

inline size_t Syntax::taglvl() const
{
  return quantity(Syntax::qTAGLVL);
}

inline size_t Syntax::taglen() const
{
  return quantity(Syntax::qTAGLEN);
}

inline size_t Syntax::entlvl() const
{
  return quantity(Syntax::qENTLVL);
}

inline size_t Syntax::pilen() const
{
  return quantity(Syntax::qPILEN);
}

inline Char Syntax::space() const
{
  return standardFunction(Syntax::fSPACE);
}

inline void Syntax::setSgmlChar(const ISet<Char> &set)
{
  set_[sgmlChar] = set;
}

inline int Syntax::referenceQuantity(Quantity i)
{
  return referenceQuantity_[i];
}

inline void Syntax::setShuncharControls()
{
  shuncharControls_ = 1;
}

inline const XcharMap<unsigned char> &Syntax::markupScanTable() const
{
  return markupScanTable_;
}

inline Boolean Syntax::multicode() const
{
  return multicode_;
}

inline Boolean Syntax::namecaseGeneral() const
{
  return namecaseGeneral_;
}

inline Boolean Syntax::namecaseEntity() const
{
  return namecaseEntity_;
}

inline size_t Syntax::nEntities() const
{
  return entityNames_.size();
}

inline const StringC &Syntax::entityName(size_t i) const
{
  return entityNames_[i];
}

inline Char Syntax::entityChar(size_t i) const
{
  return entityChars_[i];
}


}
# 17 "/usr/include/OpenSP/Sd.h" 2 3 4
# 1 "/usr/include/OpenSP/CharsetDecl.h" 1 3 4






#pragma interface



# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 12 "/usr/include/OpenSP/CharsetDecl.h" 2 3 4

# 1 "/usr/include/OpenSP/ISet.h" 1 3 4
# 14 "/usr/include/OpenSP/CharsetDecl.h" 2 3 4



namespace OpenSP {


class CharsetDeclRange {
public:
  enum Type {
    number,
    string,
    unused
    };
  CharsetDeclRange();
  CharsetDeclRange(WideChar, Number, WideChar);
  CharsetDeclRange(WideChar, Number);
  CharsetDeclRange(WideChar, Number, const StringC &);
  void rangeDeclared(WideChar min, Number count,
       ISet<WideChar> &declared) const;
  void usedSet(ISet<Char> &) const;
  Boolean getCharInfo(WideChar fromChar,
        CharsetDeclRange::Type &type,
        Number &n,
        StringC &str,
        Number &count) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(Number n, ISet<WideChar> &to, Number &count) const;
private:
  WideChar descMin_;
  Number count_;
  WideChar baseMin_;
  Type type_;
  StringC str_;
};

class CharsetDeclSection {
public:
  CharsetDeclSection();
  void setPublicId(const PublicId &);
  void addRange(const CharsetDeclRange &);
  void rangeDeclared(WideChar min, Number count,
       ISet<WideChar> &declared) const;
  void usedSet(ISet<Char> &) const;
  Boolean getCharInfo(WideChar fromChar,
        const PublicId *&id,
        CharsetDeclRange::Type &type,
        Number &n,
        StringC &str,
        Number &cout) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(const PublicId *id, Number n,
      ISet<WideChar> &to, Number &count) const;
private:
  PublicId baseset_;
  Vector<CharsetDeclRange> ranges_;
};

class CharsetDecl {
public:
  CharsetDecl();
  void addSection(const PublicId &);
  void swap(CharsetDecl &);
  void clear();
  void usedSet(ISet<Char> &) const;
  void declaredSet(ISet<WideChar> &set) const;
  Boolean charDeclared(WideChar) const;
  void rangeDeclared(WideChar min, Number count,
       ISet<WideChar> &declared) const;
  void addRange(WideChar, Number, WideChar);
  void addRange(WideChar, Number);
  void addRange(WideChar, Number, const StringC &);
  Boolean getCharInfo(WideChar fromChar,
        const PublicId *&id,
        CharsetDeclRange::Type &type,
        Number &n,
        StringC &str) const;
  Boolean getCharInfo(WideChar fromChar,
        const PublicId *&id,
        CharsetDeclRange::Type &type,
        Number &n,
        StringC &str,
        Number &count) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(const PublicId *id, Number n,
      ISet<WideChar> &to, Number &count) const;
  void numberToChar(const PublicId *id, Number n, ISet<WideChar> &to) const;
private:
  Vector<CharsetDeclSection> sections_;
  ISet<WideChar> declaredSet_;
};

inline
Boolean CharsetDecl::getCharInfo(WideChar fromChar,
     const PublicId *&id,
     CharsetDeclRange::Type &type,
     Number &n,
     StringC &str) const
{
  Number tem;
  return getCharInfo(fromChar, id, type, n, str, tem);
}

inline
void CharsetDecl::numberToChar(const PublicId *id, Number n,
          ISet<WideChar> &to) const
{
  Number tem;
  numberToChar(id, n, to, tem);
}

inline
void CharsetDecl::declaredSet(ISet<WideChar> &set) const
{
  set = declaredSet_;
}

inline
Boolean CharsetDecl::charDeclared(WideChar c) const
{
  return declaredSet_.contains(c);
}


}
# 18 "/usr/include/OpenSP/Sd.h" 2 3 4
# 1 "/usr/include/OpenSP/HashTable.h" 1 3 4
# 19 "/usr/include/OpenSP/Sd.h" 2 3 4
# 1 "/usr/include/OpenSP/EntityManager.h" 1 3 4







#pragma interface






# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 16 "/usr/include/OpenSP/EntityManager.h" 2 3 4



namespace OpenSP {


class Messenger;
class InputSourceOrigin;
class CharsetInfo;
class InputSource;

class EntityManager : public Resource {
public:
  enum { mayRewind = 01, maySetDocCharset = 02 };
  virtual ~EntityManager();
  virtual Boolean internalCharsetIsDocCharset() const = 0;
  virtual const CharsetInfo &charset() const = 0;
  virtual InputSource *open(const StringC &sysid,
       const CharsetInfo &docCharset,
       InputSourceOrigin *,
       unsigned flags,
       Messenger &) = 0;



  virtual ConstPtr<EntityCatalog>
    makeCatalog(StringC &systemId, const CharsetInfo &, Messenger &) = 0;
};


}
# 20 "/usr/include/OpenSP/Sd.h" 2 3 4
# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 21 "/usr/include/OpenSP/Sd.h" 2 3 4




namespace OpenSP {


class Sd : public Resource {
public:

  enum BooleanFeature {
    fDATATAG,
    fOMITTAG,
    fRANK,
    fSTARTTAGEMPTY,
    fSTARTTAGUNCLOSED,
    fENDTAGEMPTY,
    fENDTAGUNCLOSED,
    fATTRIBDEFAULT,
    fATTRIBOMITNAME,
    fATTRIBVALUE,
    fEMPTYNRM,
    fIMPLYDEFATTLIST,
    fIMPLYDEFDOCTYPE,
    fIMPLYDEFENTITY,
    fIMPLYDEFNOTATION,
    fIMPLICIT,
    fFORMAL,
    fURN,
    fKEEPRSRE
    };
  enum {
    nBooleanFeature = fKEEPRSRE + 1,
    fSHORTTAG_FIRST = fSTARTTAGEMPTY,
    fSHORTTAG_LAST = fATTRIBVALUE
  };

  enum NumberFeature {
    fSIMPLE,
    fEXPLICIT,
    fCONCUR,
    fSUBDOC
  };
  enum { nNumberFeature = fSUBDOC + 1 };
  enum NetEnable {
    netEnableNo,
    netEnableImmednet,
    netEnableAll
  };
  enum EntityRef {
    entityRefAny,
    entityRefInternal,
    entityRefNone
  };
  enum ImplydefElement {
    implydefElementNo,
    implydefElementYes,
    implydefElementAnyother
  };

  enum ReservedName {
    rALL,
    rANY,
    rANYOTHER,
    rAPPINFO,
    rATTLIST,
    rATTRIB,
    rBASESET,
    rCAPACITY,
    rCHARSET,
    rCONCUR,
    rCONTROLS,
    rDATATAG,
    rDEFAULT,
    rDELIM,
    rDESCSET,
    rDOCTYPE,
    rDOCUMENT,
    rELEMENT,
    rEMPTY,
    rEMPTYNRM,
    rENDTAG,
    rENTITIES,
    rENTITY,
    rEXPLICIT,
    rFEATURES,
    rFORMAL,
    rFUNCHAR,
    rFUNCTION,
    rGENERAL,
    rIMMEDNET,
    rIMPLICIT,
    rIMPLYDEF,
    rINSTANCE,
    rINTEGRAL,
    rINTERNAL,
    rKEEPRSRE,
    rLCNMCHAR,
    rLCNMSTRT,
    rLINK,
    rMINIMIZE,
    rMSICHAR,
    rMSOCHAR,
    rMSSCHAR,
    rNAMECASE,
    rNAMECHAR,
    rNAMES,
    rNAMESTRT,
    rNAMING,
    rNETENABL,
    rNO,
    rNOASSERT,
    rNONE,
    rNOTATION,
    rOMITNAME,
    rOMITTAG,
    rOTHER,
    rPUBLIC,
    rQUANTITY,
    rRANK,
    rRE,
    rREF,
    rRS,
    rSCOPE,
    rSEEALSO,
    rSEPCHAR,
    rSGML,
    rSGMLREF,
    rSHORTREF,
    rSHORTTAG,
    rSHUNCHAR,
    rSIMPLE,
    rSPACE,
    rSTARTTAG,
    rSUBDOC,
    rSWITCHES,
    rSYNTAX,
    rSYSTEM,
    rTYPE,
    rUCNMCHAR,
    rUCNMSTRT,
    rUNCLOSED,
    rUNUSED,
    rURN,
    rVALIDITY,
    rVALUE,
    rYES
  };
  enum Capacity {
    TOTALCAP,
    ENTCAP,
    ENTCHCAP,
    ELEMCAP,
    GRPCAP,
    EXGRPCAP,
    EXNMCAP,
    ATTCAP,
    ATTCHCAP,
    AVGRPCAP,
    NOTCAP,
    NOTCHCAP,
    IDCAP,
    IDREFCAP,
    MAPCAP,
    LKSETCAP,
    LKNMCAP
  };
  enum { nCapacity = LKNMCAP + 1 };
  Sd(const Ptr<EntityManager> &);
  void setDocCharsetDesc(const UnivCharsetDesc &);
  Boolean matchesReservedName(const StringC &, ReservedName) const;
  int digitWeight(Char) const;
  int hexDigitWeight(Char) const;
  Boolean link() const;
  Number simpleLink() const;
  Boolean implicitLink() const;
  Number explicitLink() const;
  Boolean startTagEmpty() const;
  Boolean startTagUnclosed() const;
  NetEnable startTagNetEnable() const;
  void setStartTagNetEnable(NetEnable);
  Boolean endTagEmpty() const;
  Boolean endTagUnclosed() const;
  Boolean attributeDefault() const;
  Boolean attributeValueNotLiteral() const;
  Boolean attributeOmitName() const;
  Boolean emptyElementNormal() const;
  Boolean implydefAttlist() const;
  Boolean implydefDoctype() const;
  ImplydefElement implydefElement() const;
  void setImplydefElement(ImplydefElement);
  Boolean implydefEntity() const;
  Boolean implydefNotation() const;
  Number concur() const;
  Boolean omittag() const;
  Boolean rank() const;
  Boolean datatag() const;
  Boolean formal() const;
  Boolean urn() const;
  Boolean keeprsre() const;
  Number subdoc() const;
  StringC reservedName(int) const;
  Boolean lookupQuantityName(const StringC &, Syntax::Quantity &) const;
  Boolean lookupGeneralDelimiterName(const StringC &, Syntax::DelimGeneral &)
       const;
  Boolean lookupCapacityName(const StringC &, Sd::Capacity &) const;
  StringC quantityName(Syntax::Quantity) const;
  Boolean internalCharsetIsDocCharset() const;
  const CharsetInfo &internalCharset() const;
  const CharsetInfo &docCharset() const;
  Char execToInternal(char) const;
  StringC execToInternal(const char *) const;
  Number capacity(int) const;
  void setCapacity(int, Number);
  StringC capacityName(int) const;
  Boolean scopeInstance() const;
  void setScopeInstance();
  void setDocCharsetDecl(CharsetDecl &);
  const CharsetDecl &docCharsetDecl() const;
  void setBooleanFeature(BooleanFeature, Boolean);
  void setShorttag(Boolean);
  void setNumberFeature(NumberFeature, Number);
  StringC generalDelimiterName(Syntax::DelimGeneral) const;
  UnivChar nameToUniv(const StringC &);
  Boolean www() const;
  void setWww(Boolean);
  EntityRef entityRef() const;
  void setEntityRef(EntityRef);
  Boolean typeValid() const;
  void setTypeValid(Boolean);
  Boolean integrallyStored() const;
  void setIntegrallyStored(Boolean);
private:
  PackedBoolean booleanFeature_[nBooleanFeature];
  Number numberFeature_[nNumberFeature];
  Number capacity_[nCapacity];
  PackedBoolean internalCharsetIsDocCharset_;

  const CharsetInfo *internalCharsetPtr_;
  CharsetInfo docCharset_;
  CharsetDecl docCharsetDecl_;
  Boolean scopeInstance_;
  Boolean www_;
  NetEnable netEnable_;
  EntityRef entityRef_;
  ImplydefElement implydefElement_;
  Boolean typeValid_;
  Boolean integrallyStored_;
  HashTable<StringC,int> namedCharTable_;
  Ptr<EntityManager> entityManager_;
  static const char *const reservedName_[];
  static const char *const generalDelimiterName_[];
  static const char *const capacityName_[];
  static const char *const quantityName_[];
};

inline
Boolean Sd::link() const
{
  return (numberFeature_[fSIMPLE]
   || booleanFeature_[fIMPLICIT]
   || numberFeature_[fEXPLICIT]);
}

inline
Number Sd::explicitLink() const
{
  return numberFeature_[fEXPLICIT];
}

inline
Boolean Sd::implicitLink() const
{
  return booleanFeature_[fIMPLICIT];
}

inline
Number Sd::simpleLink() const
{
  return numberFeature_[fSIMPLE];
}

inline
Boolean Sd::startTagEmpty() const
{
  return booleanFeature_[fSTARTTAGEMPTY];
}

inline
Boolean Sd::startTagUnclosed() const
{
  return booleanFeature_[fSTARTTAGUNCLOSED];
}

inline
Sd::NetEnable Sd::startTagNetEnable() const
{
  return netEnable_;
}

inline
void Sd::setStartTagNetEnable(NetEnable e)
{
  netEnable_ = e;
}

inline
Boolean Sd::endTagEmpty() const
{
  return booleanFeature_[fENDTAGEMPTY];
}

inline
Boolean Sd::endTagUnclosed() const
{
  return booleanFeature_[fENDTAGUNCLOSED];
}

inline
Boolean Sd::attributeDefault() const
{
  return booleanFeature_[fATTRIBDEFAULT];
}

inline
Boolean Sd::attributeValueNotLiteral() const
{
  return booleanFeature_[fATTRIBVALUE];
}

inline
Boolean Sd::attributeOmitName() const
{
  return booleanFeature_[fATTRIBOMITNAME];
}

inline
Boolean Sd::emptyElementNormal() const
{
  return booleanFeature_[fEMPTYNRM];
}

inline
Boolean Sd::implydefAttlist() const
{
  return booleanFeature_[fIMPLYDEFATTLIST];
}

inline
Boolean Sd::implydefDoctype() const
{
  return booleanFeature_[fIMPLYDEFDOCTYPE];
}

inline
Sd::ImplydefElement Sd::implydefElement() const
{
  return implydefElement_;
}

inline
void Sd::setImplydefElement(ImplydefElement i)
{
  implydefElement_ = i;
}

inline
Boolean Sd::implydefEntity() const
{
  return booleanFeature_[fIMPLYDEFENTITY];
}

inline
Boolean Sd::implydefNotation() const
{
  return booleanFeature_[fIMPLYDEFNOTATION];
}

inline
Number Sd::concur() const
{
  return numberFeature_[fCONCUR];
}

inline
Number Sd::subdoc() const
{
  return numberFeature_[fSUBDOC];
}


inline
Boolean Sd::omittag() const
{
  return booleanFeature_[fOMITTAG];
}

inline
Boolean Sd::rank() const
{
  return booleanFeature_[fRANK];
}

inline
Boolean Sd::datatag() const
{
  return booleanFeature_[fDATATAG];
}

inline
Boolean Sd::formal() const
{
  return booleanFeature_[fFORMAL];
}

inline
Boolean Sd::urn() const
{
  return booleanFeature_[fURN];
}

inline
Boolean Sd::keeprsre() const
{
  return booleanFeature_[fKEEPRSRE];
}

inline
const CharsetInfo &Sd::internalCharset() const
{
  return internalCharsetPtr_ ? *internalCharsetPtr_ : docCharset_;
}

inline
Char Sd::execToInternal(char c) const
{
  return internalCharset().execToDesc(c);
}

inline
StringC Sd::execToInternal(const char *s) const
{
  return internalCharset().execToDesc(s);
}

inline
StringC Sd::reservedName(int i) const
{
  return execToInternal(reservedName_[i]);
}

inline
Boolean Sd::internalCharsetIsDocCharset() const
{
  return internalCharsetIsDocCharset_;
}

inline
const CharsetInfo &Sd::docCharset() const
{
  return docCharset_;
}

inline
int Sd::digitWeight(Char c) const
{
  return internalCharset().digitWeight(c);
}

inline
int Sd::hexDigitWeight(Char c) const
{
  return internalCharset().hexDigitWeight(c);
}

inline
Number Sd::capacity(int i) const
{
  return capacity_[i];
}

inline
void Sd::setCapacity(int i, Number n)
{
  capacity_[i] = n;
}

inline
StringC Sd::capacityName(int i) const
{
  return execToInternal(capacityName_[i]);
}

inline
Boolean Sd::scopeInstance() const
{
  return scopeInstance_;
}

inline
void Sd::setScopeInstance()
{
  scopeInstance_ = 1;
}

inline
void Sd::setDocCharsetDecl(CharsetDecl &decl)
{
  decl.swap(docCharsetDecl_);
}

inline
const CharsetDecl &Sd::docCharsetDecl() const
{
  return docCharsetDecl_;
}

inline
void Sd::setBooleanFeature(BooleanFeature i, Boolean b)
{
  booleanFeature_[i] = b;
}

inline
void Sd::setNumberFeature(NumberFeature i, Number n)
{
  numberFeature_[i] = n;
}

inline
Boolean Sd::www() const
{
  return www_;
}

inline
void Sd::setWww(Boolean b)
{
  www_ = b;
}

inline
Sd::EntityRef Sd::entityRef() const
{
  return entityRef_;
}

inline
void Sd::setEntityRef(EntityRef r)
{
  entityRef_ = r;
}

inline
Boolean Sd::typeValid() const
{
  return typeValid_;
}

inline
void Sd::setTypeValid(Boolean b)
{
  typeValid_ = b;
}

inline
Boolean Sd::integrallyStored() const
{
  return integrallyStored_;
}

inline
void Sd::setIntegrallyStored(Boolean b)
{
  integrallyStored_ = b;
}


}
# 21 "/usr/include/OpenSP/Event.h" 2 3 4

# 1 "/usr/include/OpenSP/Dtd.h" 1 3 4






#pragma interface


# 1 "/usr/include/OpenSP/NamedTable.h" 1 3 4
# 10 "/usr/include/OpenSP/NamedTable.h" 3 4
# 1 "/usr/include/OpenSP/OwnerTable.h" 1 3 4
# 11 "/usr/include/OpenSP/NamedTable.h" 2 3 4


namespace OpenSP {


class NamedTableKeyFunction {
public:
  static inline const StringC &key(const Named &obj) { return obj.name(); }
};

template<class T> class NamedTableIter;
template<class T> class ConstNamedTableIter;

template<class T>
class NamedTable {
public:
  NamedTable() { }
  T *insert(T *p) { return (T *)table_.insert(p); }
  T *lookup(const StringC &str) const { return (T *)table_.lookup(str); }
  T *remove(const StringC &str) { return (T *)table_.remove(str); }
  size_t count() const { return table_.count(); }
  void clear() { table_.clear(); }
  void swap(NamedTable<T> &to) { table_.swap(to.table_); }
private:
  NamedTable(const NamedTable<T> &);
  void operator=(const NamedTable<T> &);
  OwnerTable<Named, StringC, Hash, NamedTableKeyFunction>
    table_;
  friend class NamedTableIter<T>;
  friend class ConstNamedTableIter<T>;
};

template<class T>
class NamedTableIter {
public:
  NamedTableIter(const NamedTable<T> &table) : iter_(table.table_) { }
  T *next() { return (T *)iter_.next(); }
private:
  OwnerTableIter<Named, StringC, Hash, NamedTableKeyFunction> iter_;
};

template<class T>
class ConstNamedTableIter {
public:
  ConstNamedTableIter(const NamedTable<T> &table) : iter_(table.table_) { }
  const T *next() { return (T *)iter_.next(); }
private:
  OwnerTableIter<Named, StringC, Hash, NamedTableKeyFunction> iter_;
};


}
# 11 "/usr/include/OpenSP/Dtd.h" 2 3 4
# 1 "/usr/include/OpenSP/NamedResourceTable.h" 1 3 4







# 1 "/usr/include/OpenSP/PointerTable.h" 1 3 4
# 9 "/usr/include/OpenSP/NamedResourceTable.h" 2 3 4


# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 12 "/usr/include/OpenSP/NamedResourceTable.h" 2 3 4


namespace OpenSP {


struct NamedResourceKeyFunction {
  static inline
    const StringC &key(const NamedResource &p) {
      return p.name();
    }
};

template<class T> class NamedResourceTableIter;
template<class T> class ConstNamedResourceTableIter;

template<class T>
class NamedResourceTable {





public:
  NamedResourceTable() { }
  Ptr<T> insert(const Ptr<T> &p, Boolean replace = 0) {
    return (T *)table_.insert((NamedResource *)p.pointer(), replace).pointer();
  }
  Ptr<T> lookup(const StringC &str) const {
    return (T *)table_.lookup(str).pointer();
  }
  ConstPtr<T> lookupConst(const StringC &str) const {
    return (T *)table_.lookup(str).pointer();
  }
  const T *lookupTemp(const StringC &str) const {
    return (const T *)table_.lookup(str).pointer();
  }
  Ptr<T> remove(const StringC &str) {
    return (T *)table_.remove(str).pointer();
  }
  size_t count() const { return table_.count(); }
  void clear() { table_.clear(); }
  void swap(NamedResourceTable<T> &to) { table_.swap(to.table_); }
private:
  PointerTable<Ptr<NamedResource>, StringC, Hash,
        NamedResourceKeyFunction> table_;
  friend class NamedResourceTableIter<T>;
  friend class ConstNamedResourceTableIter<T>;
};

template<class T>
class NamedResourceTableIter {
public:
  NamedResourceTableIter(const NamedResourceTable<T> &table)
  : iter_(table.table_) { }
  Ptr<T> next() {
    return (T *)iter_.next().pointer();
  }
private:
  PointerTableIter<Ptr<NamedResource>, StringC, Hash,
                   NamedResourceKeyFunction> iter_;
};

template<class T>
class ConstNamedResourceTableIter {
public:
  ConstNamedResourceTableIter(const NamedResourceTable<T> &table)
  : iter_(table.table_) { }
  ConstPtr<T> next() {
    return (T *)iter_.next().pointer();
  }
  const T *nextTemp() {
    return (const T *)iter_.next().pointer();
  }
private:
  PointerTableIter<Ptr<NamedResource>, StringC, Hash,
                   NamedResourceKeyFunction> iter_;
};


}
# 12 "/usr/include/OpenSP/Dtd.h" 2 3 4
# 1 "/usr/include/OpenSP/ElementType.h" 1 3 4






#pragma interface


# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 11 "/usr/include/OpenSP/ElementType.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 13 "/usr/include/OpenSP/ElementType.h" 2 3 4
# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 14 "/usr/include/OpenSP/ElementType.h" 2 3 4

# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 16 "/usr/include/OpenSP/ElementType.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 18 "/usr/include/OpenSP/ElementType.h" 2 3 4

# 1 "/usr/include/OpenSP/Mode.h" 1 3 4







namespace OpenSP {


enum Mode {
  grpMode,
  alitMode,
  alitaMode,
  aliteMode,
  talitMode,
  talitaMode,
  taliteMode,
  mdMode,
  mdMinusMode,
  mdPeroMode,
  sdMode,
  comMode,
  sdcomMode,
  piMode,
  refMode,
  imsMode,
  cmsMode,
  rcmsMode,

  proMode,
  dsMode,

  dsiMode,

  plitMode,
  plitaMode,
  pliteMode,
  sdplitMode,

  sdplitaMode,

  grpsufMode,
  mlitMode,
  mlitaMode,
  asMode,
  piPasMode,
  slitMode,
  slitaMode,
  sdslitMode,

  sdslitaMode,


  cconMode,
  rcconMode,
  cconnetMode,
  rcconnetMode,
  rcconeMode,
  tagMode,
  econMode,
  mconMode,
  econnetMode,
  mconnetMode
  };

const int nModes = mconnetMode + 1;

const int minShortrefMode = econMode;


}
# 20 "/usr/include/OpenSP/ElementType.h" 2 3 4
# 1 "/usr/include/OpenSP/ContentToken.h" 1 3 4






#pragma interface


# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 11 "/usr/include/OpenSP/ContentToken.h" 2 3 4

# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 13 "/usr/include/OpenSP/ContentToken.h" 2 3 4
# 1 "/usr/include/OpenSP/NCVector.h" 1 3 4
# 12 "/usr/include/OpenSP/NCVector.h" 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/Vector.h" 2 3 4







namespace OpenSP {


template<class T>
class NCVector {
public:
  typedef size_t size_type;
  typedef T *iterator;
  typedef const T *const_iterator;
  NCVector() : ptr_(0), size_(0), alloc_(0) { }
  NCVector(size_t n) : ptr_(0), size_(0), alloc_(0) { append(n); }
  virtual ~NCVector();
  void resize(size_t n) {
    if (n < size_)
      erase(ptr_ + n, ptr_ + size_);
    else if (n > size_)
      append(n - size_);
  }
# 46 "/usr/include/OpenSP/Vector.h" 3 4
  void swap(NCVector<T> &);
  void clear() { erase(ptr_, ptr_ + size_); }
  size_t size() const { return size_; }
  T &operator[](size_t i) { return ptr_[i]; }
  const T &operator[](size_t i) const { return ptr_[i]; }
  iterator begin() { return ptr_; }
  const_iterator begin() const { return ptr_; }
  T &back() { return ptr_[size_ - 1]; }
  const T &back() const { return ptr_[size_ - 1]; }
  void reserve(size_t n) { if (n > alloc_) reserve1(n); }
  iterator erase(const_iterator, const_iterator);
private:

  NCVector(const NCVector<T> &);
  void operator=(const NCVector<T> &);

  void append(size_t);
  void reserve1(size_t);

  size_t size_;
  T *ptr_;
  size_t alloc_;
};


}
# 13 "/usr/include/OpenSP/NCVector.h" 2 3 4
# 48 "/usr/include/OpenSP/NCVector.h" 3 4
# 1 "/usr/include/OpenSP/Vector.cxx" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/Vector.cxx" 2 3 4



namespace OpenSP {


template<class T>
NCVector<T>::~NCVector()
{
  if (ptr_) {
    erase(ptr_, ptr_ + size_);
    ::operator delete((void *)ptr_);
  }
}
# 99 "/usr/include/OpenSP/Vector.cxx" 3 4
template<class T>
void NCVector<T>::swap(NCVector<T> &v)
{
  {
    T *tem = ptr_;
    ptr_ = v.ptr_;
    v.ptr_ = tem;
  }
  {
    size_t tem = size_;
    size_ = v.size_;
    v.size_ = tem;
  }
  {
    size_t tem = alloc_;
    alloc_ = v.alloc_;
    v.alloc_ = tem;
  }
}

template<class T>
void NCVector<T>::append(size_t n)
{
  reserve(size_ + n);
  while (n-- > 0)
    (void)new (ptr_ + size_++) T;
}

template<class T>
T *NCVector<T>::erase(const T *p1, const T *p2)
{
  typedef T X;
  for (const T *p = p1; p != p2; p++)
    ((X *)p)->~X();
  if (p2 != ptr_ + size_)
    memmove((T *)p1, p2, ((const T *)(ptr_ + size_) - p2)*sizeof(T));
  size_ -= p2 - p1;
  return (T *)p1;
}

template<class T>
void NCVector<T>::reserve1(size_t size)
{


  size_t newAlloc = alloc_*2;
  if (size > newAlloc)
    newAlloc += size;
  void *p = ::operator new(newAlloc * sizeof(T));
  alloc_ = newAlloc;
  if (ptr_) {
    memcpy(p, ptr_, size_*sizeof(T));
    ::operator delete((void *)ptr_);
  }
  ptr_ = (T *)p;
}


}
# 49 "/usr/include/OpenSP/NCVector.h" 2 3 4
# 14 "/usr/include/OpenSP/ContentToken.h" 2 3 4



namespace OpenSP {


class LeafContentToken;

struct Transition {
  enum { invalidIndex = -1 };

  unsigned clearAndStateStartIndex;



  unsigned andDepth;




  PackedBoolean isolated;


  unsigned requireClear;

  unsigned toSet;
};

class FirstSet {
public:
  FirstSet();
  void init(LeafContentToken *);
  void append(const FirstSet &);
  size_t size() const;
  LeafContentToken *token(size_t i) const;
  size_t requiredIndex() const;
  void setNotRequired();
private:
  Vector<LeafContentToken *> v_;

  size_t requiredIndex_;
};

class LastSet : public Vector<LeafContentToken *> {
public:
  LastSet() { }
  LastSet(size_t n) : Vector<LeafContentToken *>(n) { }
  void append(const LastSet &);
};

class ElementType;
class AndModelGroup;
struct GroupInfo;

struct ContentModelAmbiguity {
  const LeafContentToken *from;
  const LeafContentToken *to1;
  const LeafContentToken *to2;
  unsigned andDepth;
};

class ModelGroup;

class ContentToken {
public:
  enum OccurrenceIndicator { none = 0, opt = 01, plus = 02, rep = 03 };
  ContentToken(OccurrenceIndicator);
  virtual ~ContentToken();
  OccurrenceIndicator occurrenceIndicator() const;
  Boolean inherentlyOptional() const;
  static unsigned andDepth(const AndModelGroup *);
  static unsigned andIndex(const AndModelGroup *);
  void analyze(GroupInfo &, const AndModelGroup *, unsigned,
        FirstSet &, LastSet &);
  static void addTransitions(const LastSet &from,
        const FirstSet &to,
        Boolean maybeRequired,
        unsigned andClearIndex,
        unsigned andDepth,
        Boolean isolated = 0,
        unsigned requireClear
          = (unsigned)Transition::invalidIndex,
        unsigned toSet
          = (unsigned)Transition::invalidIndex);
  virtual void finish(Vector<unsigned> &minAndDepth,
        Vector<size_t> &elementTransition,
        Vector<ContentModelAmbiguity> &,
        Boolean &pcdataUnreachable) = 0;
  virtual unsigned long grpgtcnt() const;
  virtual void setOrGroupMember();
  unsigned andGroupIndex() const;
  virtual const ModelGroup *asModelGroup() const;
  virtual const LeafContentToken *asLeafContentToken() const;
protected:
  PackedBoolean inherentlyOptional_;
private:
  ContentToken(const ContentToken &);
  void operator=(const ContentToken &);
  virtual void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
   FirstSet &, LastSet &) = 0;
  OccurrenceIndicator occurrenceIndicator_;
};

class ModelGroup : public ContentToken {
public:
  enum Connector { andConnector, orConnector, seqConnector };
  ModelGroup(NCVector<Owner<ContentToken> > &, OccurrenceIndicator);
  virtual Connector connector() const = 0;
  unsigned nMembers() const;
  void finish(Vector<unsigned> &minAndDepth,
       Vector<size_t> &elementTransition,
       Vector<ContentModelAmbiguity> &,
       Boolean &pcdataUnreachable);
  ContentToken &member(unsigned i);
  const ContentToken &member(unsigned i) const;
  unsigned long grpgtcnt() const;
  const ModelGroup *asModelGroup() const;
protected:
  void setOrGroup();
private:
  ModelGroup(const ModelGroup &);
  void operator=(const ModelGroup &);
  NCVector<Owner<ContentToken> > members_;
};

class AndModelGroup : public ModelGroup {
public:
  AndModelGroup(NCVector<Owner<ContentToken> > &, OccurrenceIndicator);
  Connector connector() const;
  unsigned andDepth() const;
  unsigned andIndex() const;
  unsigned andGroupIndex() const;
  const AndModelGroup *andAncestor() const;
private:
  AndModelGroup(const AndModelGroup &);
  void operator=(const AndModelGroup &);
  unsigned andDepth_;
  unsigned andIndex_;
  unsigned andGroupIndex_;
  const AndModelGroup *andAncestor_;
  void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
  FirstSet &, LastSet &);
};

class OrModelGroup : public ModelGroup {
public:
  OrModelGroup(NCVector<Owner<ContentToken> > &, OccurrenceIndicator);
  Connector connector() const;
private:
  OrModelGroup(const OrModelGroup &);
  void operator=(const OrModelGroup &);
  void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
  FirstSet &, LastSet &);
};

class SeqModelGroup : public ModelGroup {
public:
  SeqModelGroup(NCVector<Owner<ContentToken> > &, OccurrenceIndicator);
  Connector connector() const;
private:
  SeqModelGroup(const SeqModelGroup &);
  void operator=(const SeqModelGroup &);
  void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
  FirstSet &, LastSet &);
};

class AndState;

class AndInfo {
public:
  AndInfo() { }
  const AndModelGroup *andAncestor;
  unsigned andGroupIndex;
  Vector<Transition> follow;
private:
  AndInfo(const AndInfo &);
  void operator=(const AndInfo &);
};




class LeafContentToken : public ContentToken {
public:
  LeafContentToken(const ElementType *, OccurrenceIndicator);
  unsigned index() const;
  unsigned typeIndex() const;
  const ElementType *elementType() const;
  virtual Boolean isInitial() const;
  void addTransitions(const FirstSet &to,
        Boolean maybeRequired,
        unsigned andClearIndex,
        unsigned andDepth,
        Boolean isolated,
        unsigned requireClear,
        unsigned toSet);
  void setFinal();
  void finish(Vector<unsigned> &minAndDepth,
       Vector<size_t> &elementTransition,
       Vector<ContentModelAmbiguity> &,
       Boolean &pcdataUnreachable);
  Boolean isFinal() const;
  Boolean tryTransition(const ElementType *, AndState &,
   unsigned &minAndDepth,
   const LeafContentToken *&newpos) const;
  Boolean tryTransitionPcdata(AndState &, unsigned &minAndDepth,
         const LeafContentToken *&newpos) const;
  void possibleTransitions(const AndState &, unsigned minAndDepth, Vector<const ElementType *> &) const;
  const LeafContentToken *impliedStartTag(const AndState &andpos,
       unsigned minAndDepth) const;
  const LeafContentToken *transitionToken(const ElementType *to,
       const AndState &andState,
       unsigned minAndDepth) const;
  void doRequiredTransition(AndState &andState,
       unsigned &minAndDepth,
       const LeafContentToken *&newpos) const;
  unsigned computeMinAndDepth(const AndState&) const;
  Boolean orGroupMember() const;
  void setOrGroupMember();
  const AndModelGroup *andAncestor() const;
  unsigned andDepth() const;
  const LeafContentToken *asLeafContentToken() const;
protected:
  void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
  FirstSet &, LastSet &);
  const ElementType *element_;
private:
  LeafContentToken(const LeafContentToken &);
  void operator=(const LeafContentToken &);
  void andFinish(Vector<unsigned> &minAndDepth,
   Vector<size_t> &elementTransition,
   Vector<ContentModelAmbiguity> &,
   Boolean &pcdataUnreachable);
  unsigned computeMinAndDepth1(const AndState&) const;
  unsigned leafIndex_;
  unsigned typeIndex_;
  Vector<LeafContentToken *> follow_;
  PackedBoolean isFinal_;
  PackedBoolean orGroupMember_;

  char pcdataTransitionType_;
  const LeafContentToken *simplePcdataTransition_;
  size_t requiredIndex_;
  Owner<AndInfo> andInfo_;
};

class PcdataToken : public LeafContentToken {
public:
  PcdataToken();
  void analyze1(GroupInfo &, const AndModelGroup *, unsigned,
  FirstSet &, LastSet &);
private:
  PcdataToken(const PcdataToken &);
  void operator=(const PcdataToken &);
};

class InitialPseudoToken : public LeafContentToken {
public:
  InitialPseudoToken();
  Boolean isInitial() const;
private:
  InitialPseudoToken(const InitialPseudoToken &);
  void operator=(const InitialPseudoToken &);
};

class ElementToken : public LeafContentToken {
public:
  ElementToken(const ElementType *, OccurrenceIndicator);
private:
  ElementToken(const ElementToken &);
  void operator=(const ElementToken &);
};

class DataTagGroup : public SeqModelGroup {
public:

  DataTagGroup(NCVector<Owner<ContentToken> > &, OccurrenceIndicator);
private:
  DataTagGroup(const DataTagGroup &);
  void operator=(const DataTagGroup &);
};

class DataTagElementToken : public ElementToken {
public:
  DataTagElementToken(const ElementType *, Vector<Text> &templates);
  DataTagElementToken(const ElementType *, Vector<Text> &templates,
        Text &paddingTemplate);
private:
  DataTagElementToken(const DataTagElementToken &);
  void operator=(const DataTagElementToken &);
  Vector<Text> templates_;
  Boolean havePaddingTemplate_;
  Text paddingTemplate_;
};

class CompiledModelGroup {
public:
  CompiledModelGroup(Owner<ModelGroup> &);
  void compile(size_t nElementTypeIndex,
        Vector<ContentModelAmbiguity> &,
        Boolean &pcdataUnreachable);
  CompiledModelGroup *copy() const;
  const LeafContentToken *initial() const;
  unsigned andStateSize() const;
  Boolean containsPcdata() const;
  const ModelGroup *modelGroup() const;
private:
  CompiledModelGroup(const CompiledModelGroup &);
  void operator=(const CompiledModelGroup &);
  Owner<ModelGroup> modelGroup_;
  Owner<LeafContentToken> initial_;
  unsigned andStateSize_;
  Boolean containsPcdata_;
};

class AndState {
public:
  AndState(unsigned);
  Boolean isClear(unsigned) const;
  void clearFrom(unsigned);
  void set(unsigned);
  Boolean operator==(const AndState &) const;
  Boolean operator!=(const AndState &) const;
private:
  void clearFrom1(unsigned);
  unsigned clearFrom_;
  Vector<PackedBoolean> v_;
};

class MatchState {
public:
  MatchState();
  MatchState(const CompiledModelGroup *);
  Boolean tryTransition(const ElementType *);
  Boolean tryTransitionPcdata();
  void possibleTransitions(Vector<const ElementType *> &) const;
  Boolean isFinished() const;
  const LeafContentToken *impliedStartTag() const;
  const LeafContentToken *invalidExclusion(const ElementType *) const;
  void doRequiredTransition();
  const LeafContentToken *currentPosition() const;
  Boolean operator==(const MatchState &) const;
  Boolean operator!=(const MatchState &) const;
private:
  const LeafContentToken *pos_;
  AndState andState_;
  unsigned minAndDepth_;
};

inline
ContentToken::OccurrenceIndicator ContentToken::occurrenceIndicator() const
{
  return occurrenceIndicator_;
}

inline
unsigned LeafContentToken::index() const
{
  return leafIndex_;
}

inline
unsigned LeafContentToken::typeIndex() const
{
  return typeIndex_;
}

inline
Boolean ContentToken::inherentlyOptional() const
{
  return inherentlyOptional_;
}

inline
const ElementType *LeafContentToken::elementType() const
{
  return element_;
}

inline
unsigned AndModelGroup::andDepth() const
{
  return andDepth_;
}

inline
unsigned AndModelGroup::andIndex() const
{
  return andIndex_;
}

inline
unsigned ModelGroup::nMembers() const
{
  return members_.size();
}

inline
unsigned ContentToken::andDepth(const AndModelGroup *andAncestor)
{
  return andAncestor ? andAncestor->andDepth() + 1 : 0;
}

inline
unsigned ContentToken::andIndex(const AndModelGroup *andAncestor)
{
  return (andAncestor
   ? andAncestor->andIndex() + andAncestor->nMembers()
   : 0);
}

inline
ContentToken &ModelGroup::member(unsigned i)
{
  return *members_[i];
}

inline
const ContentToken &ModelGroup::member(unsigned i) const
{
  return *members_[i];
}

inline
void LeafContentToken::setFinal()
{
  isFinal_ = 1;
}

inline
Boolean LeafContentToken::isFinal() const
{
  return isFinal_;
}

inline
Boolean LeafContentToken::orGroupMember() const
{
  return orGroupMember_;
}

inline
unsigned CompiledModelGroup::andStateSize() const
{
  return andStateSize_;
}

inline
Boolean CompiledModelGroup::containsPcdata() const
{
  return containsPcdata_;
}

inline
const AndModelGroup *AndModelGroup::andAncestor() const
{
  return andAncestor_;
}

inline
unsigned AndModelGroup::andGroupIndex() const
{
  return andGroupIndex_;
}

inline
const LeafContentToken *CompiledModelGroup::initial() const
{
  return initial_.pointer();
}

inline
const ModelGroup *CompiledModelGroup::modelGroup() const
{
  return modelGroup_.pointer();
}

inline
const AndModelGroup *LeafContentToken::andAncestor() const
{
  return andInfo_ ? andInfo_->andAncestor : 0;
}

inline
unsigned LeafContentToken::andDepth() const
{
  return andInfo_ ? ContentToken::andDepth(andInfo_->andAncestor) : 0;
}

inline
unsigned LeafContentToken::computeMinAndDepth(const AndState &andState) const
{
  return andInfo_ ? computeMinAndDepth1(andState) : 0;
}

inline
Boolean LeafContentToken::tryTransitionPcdata(AndState &andState,
           unsigned &minAndDepth,
           const LeafContentToken *&newpos)
     const
{
  if (pcdataTransitionType_ == 1) {
    newpos = simplePcdataTransition_;
    return 1;
  }
  else if (pcdataTransitionType_ == 0)
    return 0;
  else
    return tryTransition(0, andState, minAndDepth, newpos);
}

inline
Boolean MatchState::tryTransition(const ElementType *to)
{
  return pos_->tryTransition(to, andState_, minAndDepth_, pos_);
}

inline
Boolean MatchState::tryTransitionPcdata()
{
  return pos_->tryTransitionPcdata(andState_, minAndDepth_, pos_);
}

inline
void MatchState::possibleTransitions(Vector<const ElementType *> &v) const
{
  pos_->possibleTransitions(andState_, minAndDepth_, v);
}

inline
Boolean MatchState::isFinished() const
{
  return pos_->isFinal() && minAndDepth_ == 0;
}

inline
const LeafContentToken *
MatchState::impliedStartTag() const
{
  return pos_->impliedStartTag(andState_, minAndDepth_);
}

inline
void MatchState::doRequiredTransition()
{
  pos_->doRequiredTransition(andState_, minAndDepth_, pos_);
}

inline
const LeafContentToken *MatchState::currentPosition() const
{
  return pos_;
}

inline
Boolean MatchState::operator!=(const MatchState &state) const
{
  return !(*this == state);
}

inline
Boolean AndState::isClear(unsigned i) const
{
  return v_[i] == 0;
}

inline
void AndState::set(unsigned i)
{
  v_[i] = 1;
  if (i >= clearFrom_)
    clearFrom_ = i + 1;
}

inline
void AndState::clearFrom(unsigned i)
{
  if (i < clearFrom_)
    clearFrom1(i);
}

inline
Boolean AndState::operator!=(const AndState &state) const
{
  return !(*this == state);
}


inline
size_t FirstSet::size() const
{
  return v_.size();
}

inline
LeafContentToken *FirstSet::token(size_t i) const
{
  return v_[i];
}

inline
size_t FirstSet::requiredIndex() const
{
  return requiredIndex_;
}

inline
void FirstSet::setNotRequired()
{
  requiredIndex_ = size_t(-1);
}


}
# 21 "/usr/include/OpenSP/ElementType.h" 2 3 4


namespace OpenSP {


class ElementType;
class ShortReferenceMap;
class RankStem;

class ElementDefinition : public Resource {
public:
  enum DeclaredContent { modelGroup, any, cdata, rcdata, empty };
  enum OmitFlags { omitStart = 01, omitEnd = 02, omitSpec = 04 };
  enum { undefinedIndex = -1 };
  ElementDefinition(const Location &location,
      size_t index,
      unsigned char omitFlags,
      DeclaredContent declaredContent,
      Boolean allowImmediateRecursion = 1);
  ElementDefinition(const Location &location,
      size_t index,
      unsigned char omitFlags,
      DeclaredContent declaredContent,
      Owner<CompiledModelGroup> &modelGroup);
  const CompiledModelGroup *compiledModelGroup() const;
  DeclaredContent declaredContent() const;

  Boolean omittedTagSpec() const;
  Boolean canOmitStartTag() const;
  Boolean canOmitEndTag() const;
  size_t nRankStems() const;
  const RankStem *rankStem(size_t i) const;
  const StringC &rankSuffix() const;
  size_t nInclusions() const;
  const ElementType *inclusion(size_t) const;
  size_t nExclusions() const;
  const ElementType *exclusion(size_t) const;
  Boolean undefined() const;
  Boolean allowImmediateRecursion() const;
  void setInclusions(Vector<const ElementType *> &inclusions);
  void setExclusions(Vector<const ElementType *> &exclusions);
  void setRank(StringC &suffix, Vector<const RankStem *> &rankStems);
  Mode mode(Boolean netEnabled) const;
  const Location &location() const;
private:
  ElementDefinition(const ElementDefinition &);
  void operator=(const ElementDefinition &);
  void computeMode();

  Location location_;
  size_t index_;
  unsigned char omitFlags_;
  DeclaredContent declaredContent_;
  Boolean allowImmediateRecursion_;
  Owner<CompiledModelGroup> modelGroup_;
  Vector<const ElementType *> inclusions_;
  Vector<const ElementType *> exclusions_;


  Vector<const RankStem *> rankStems_;
  StringC rankSuffix_;
  Mode mode_;
  Mode netMode_;
};

class RankStem : public Named {
public:
  RankStem(const StringC &, size_t);
  size_t index() const;
  void addDefinition(const ConstPtr<ElementDefinition> &);
  size_t nDefinitions() const;
  const ElementDefinition *definition(size_t) const;
private:
  RankStem(const RankStem &);
  void operator=(const RankStem &);
  size_t index_;
  Vector<ConstPtr<ElementDefinition> > def_;
};

class ElementType : public Named, public Attributed {
public:
  ElementType(const StringC &, size_t);
  void setElementDefinition(const ConstPtr<ElementDefinition> &,
       size_t defIndex);
  void setMap(const ShortReferenceMap *);
  void setRankStem(RankStem *);
  Boolean undefined() const;
  void setOrigName(StringC &origName);
  const ElementDefinition *definition() const;
  Boolean isRankedElement() const;
  const RankStem *rankedElementRankStem() const;
  size_t index() const;
  const ShortReferenceMap *map() const;
  void swap(ElementType &);
  const StringC &origName() const;
private:
  StringC origName_;
  ElementType(const ElementType &);
  void operator=(const ElementType &);
  size_t index_;
  size_t defIndex_;
  ConstPtr<ElementDefinition> def_;
  const ShortReferenceMap *map_;
};

inline
const CompiledModelGroup *ElementDefinition::compiledModelGroup() const
{
  return modelGroup_.pointer();
}

inline
ElementDefinition::DeclaredContent ElementDefinition::declaredContent() const
{
  return declaredContent_;
}

inline
Boolean ElementDefinition::canOmitStartTag() const
{
  return (omitFlags_ & omitStart) != 0;
}

inline
Boolean ElementDefinition::canOmitEndTag() const
{
  return (omitFlags_ & omitEnd) != 0;
}

inline
Boolean ElementDefinition::omittedTagSpec() const
{
  return (omitFlags_ & omitSpec) != 0;
}

inline
size_t ElementDefinition::nRankStems() const
{
  return rankStems_.size();
}

inline
const StringC &ElementDefinition::rankSuffix() const
{
  return rankSuffix_;
}

inline
const RankStem *ElementDefinition::rankStem(size_t i) const
{
  return rankStems_[i];
}

inline
const ElementType *ElementDefinition::inclusion(size_t i) const
{
  return inclusions_[i];
}

inline
size_t ElementDefinition::nInclusions() const
{
  return inclusions_.size();
}

inline
const ElementType *ElementDefinition::exclusion(size_t i) const
{
  return exclusions_[i];
}

inline
size_t ElementDefinition::nExclusions() const
{
  return exclusions_.size();
}

inline
Boolean ElementDefinition::undefined() const
{
  return index_ == size_t(undefinedIndex);
}

inline
Boolean ElementDefinition::allowImmediateRecursion() const
{
  return allowImmediateRecursion_;
}

inline
const Location &ElementDefinition::location() const
{
  return location_;
}

inline
void ElementDefinition::setInclusions(Vector<const ElementType *> &inclusions)
{
  inclusions.swap(inclusions_);
}

inline
void ElementDefinition::setExclusions(Vector<const ElementType *> &exclusions)
{
  exclusions.swap(exclusions_);
}

inline
void ElementDefinition::setRank(StringC &rankSuffix,
    Vector<const RankStem *> &rankStems)
{
  rankStems.swap(rankStems_);
  rankSuffix.swap(rankSuffix_);
}

inline
void ElementType::setOrigName(StringC &origName)
{
  origName.swap(origName_);
}

inline
Boolean ElementType::undefined() const
{
  return def_->undefined();
}

inline
Boolean ElementType::isRankedElement() const
{
  return def_->nRankStems() > 0;
}

inline
const ElementDefinition *ElementType::definition() const
{
  return def_.pointer();
}

inline
void ElementType::setElementDefinition(const ConstPtr<ElementDefinition> &def,
           size_t defIndex)
{
  def_ = def;
  defIndex_ = defIndex;
}

inline
size_t ElementType::index() const
{
  return index_;
}

inline
const RankStem *ElementType::rankedElementRankStem() const
{
  return def_->rankStem(defIndex_);
}

inline
void ElementType::setMap(const ShortReferenceMap *map)
{
  map_ = map;
}

inline
const StringC &ElementType::origName() const
{
  return origName_;
}

inline
const ShortReferenceMap *ElementType::map() const
{
  return map_;
}

inline
size_t RankStem::index() const
{
  return index_;
}

inline
size_t RankStem::nDefinitions() const
{
  return def_.size();
}

inline
const ElementDefinition *RankStem::definition(size_t i) const
{
  return def_[i].pointer();
}

inline
Mode ElementDefinition::mode(Boolean netEnabled) const
{
  return netEnabled ? netMode_ : mode_;
}


}
# 13 "/usr/include/OpenSP/Dtd.h" 2 3 4

# 1 "/usr/include/OpenSP/Entity.h" 1 3 4






#pragma interface






# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 15 "/usr/include/OpenSP/Entity.h" 2 3 4







# 1 "/usr/include/OpenSP/Markup.h" 1 3 4







#pragma interface





# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 15 "/usr/include/OpenSP/Markup.h" 2 3 4

# 1 "/usr/include/OpenSP/SdText.h" 1 3 4







#pragma interface



# 1 "/usr/include/OpenSP/StringOf.h" 1 3 4
# 13 "/usr/include/OpenSP/SdText.h" 2 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 14 "/usr/include/OpenSP/SdText.h" 2 3 4

# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 16 "/usr/include/OpenSP/SdText.h" 2 3 4


namespace OpenSP {


struct SdTextItem {
  SdTextItem();
  Location loc;
  size_t index;
};

class SdText {
public:
  SdText();
  SdText(const Location &loc, Boolean lita);
  void swap(SdText &);
  void addChar(SyntaxChar, const Location &);
  const String<SyntaxChar> &string() const;
  Boolean lita() const;
  Location endDelimLocation() const;
private:
  Boolean lita_;
  String<SyntaxChar> chars_;
  Vector<SdTextItem> items_;
  friend class SdTextIter;
};

class SdTextIter {
public:
  SdTextIter(const SdText &);
  Boolean next(const SyntaxChar *&, size_t &, Location &);
private:
  const SdText *ptr_;
  size_t itemIndex_;
};

inline
Boolean SdText::lita() const
{
  return lita_;
}

inline
const String<SyntaxChar> &SdText::string() const
{
  return chars_;
}


}
# 17 "/usr/include/OpenSP/Markup.h" 2 3 4


namespace OpenSP {


class EntityOrigin;

struct MarkupItem {
  MarkupItem();
  MarkupItem(const MarkupItem &);
  ~MarkupItem();
  void operator=(const MarkupItem &);
  unsigned char type;
  unsigned char index;
  union {
    size_t nChars;
    ConstPtr<Origin> *origin;
    Text *text;
    SdText *sdText;
  };
};

class InputSource;

class Markup {
public:
  enum Type {
    reservedName,
    sdReservedName,
    name,
    nameToken,
    attributeValue,
    number,
    comment,
    s,
    shortref,
    delimiter,
    refEndRe,
    entityStart,
    entityEnd,
    literal,
    sdLiteral
  };
  Markup();
  size_t size() const;
  void clear();
  void resize(size_t);
  void addDelim(Syntax::DelimGeneral);
  void addReservedName(Syntax::ReservedName, const InputSource *);
  void addReservedName(Syntax::ReservedName, const StringC &);
  void addSdReservedName(Sd::ReservedName, const InputSource *);
  void addSdReservedName(Sd::ReservedName, const Char *, size_t);
  void addS(Char);
  void addS(const InputSource *);
  void addRefEndRe();
  void addShortref(const InputSource *);
  void addCommentStart();
  void addCommentChar(Char);
  void addName(const InputSource *);
  void addName(const Char *, size_t);
  void addNameToken(const InputSource *);
  void addNumber(const InputSource *);
  void addAttributeValue(const InputSource *);
  void addEntityStart(const Ptr<EntityOrigin> &);
  void addEntityEnd();
  void addLiteral(const Text &);
  void addSdLiteral(const SdText &);
  void changeToAttributeValue(size_t index);
  void changeToSdReservedName(size_t index, Sd::ReservedName);
  void swap(Markup &);
private:
  StringC chars_;
  Vector<MarkupItem> items_;
  friend class MarkupIter;
};

class Location;

class MarkupIter {
public:
  MarkupIter(const Markup &);
  Markup::Type type() const;
  Boolean valid() const;
  void advance();

  void advance(Location &, const ConstPtr<Syntax> &);
  size_t index() const;
  const Char *charsPointer() const;
  size_t charsLength() const;
  const Text &text() const;
  const EntityOrigin *entityOrigin() const;
  const SdText &sdText() const;
  Syntax::DelimGeneral delimGeneral() const;
  Syntax::ReservedName reservedName() const;
  Sd::ReservedName sdReservedName() const;
private:
  const Char *chars_;
  Vector<MarkupItem>::const_iterator items_;
  size_t nItems_;
  size_t index_;
  size_t charIndex_;
};

inline
void Markup::clear()
{
  chars_.resize(0);
  items_.resize(0);
}

inline
size_t Markup::size() const
{
  return items_.size();
}

inline
Boolean MarkupIter::valid() const
{
  return index_ < nItems_;
}

inline
size_t MarkupIter::index() const
{
  return index_;
}

inline
Markup::Type MarkupIter::type() const
{
  return Markup::Type(items_[index_].type);
}

inline
const EntityOrigin *MarkupIter::entityOrigin() const
{
  return (*items_[index_].origin)->asEntityOrigin();
}

inline
const Char *MarkupIter::charsPointer() const
{
  return chars_ + charIndex_;
}

inline
size_t MarkupIter::charsLength() const
{
  return items_[index_].nChars;
}

inline
const Text &MarkupIter::text() const
{
  return *items_[index_].text;
}

inline
const SdText &MarkupIter::sdText() const
{
  return *items_[index_].sdText;
}

inline
Syntax::DelimGeneral MarkupIter::delimGeneral() const
{
  return Syntax::DelimGeneral(items_[index_].index);
}

inline
Syntax::ReservedName MarkupIter::reservedName() const
{
  return Syntax::ReservedName(items_[index_].index);
}

inline
Sd::ReservedName MarkupIter::sdReservedName() const
{
  return Sd::ReservedName(items_[index_].index);
}


}
# 23 "/usr/include/OpenSP/Entity.h" 2 3 4


namespace OpenSP {


class Messenger;
class InputSource;
class EntityOrigin;
class ParserState;
class ExternalEntity;
class ExternalDataEntity;
class SubdocEntity;
class InternalEntity;
class Notation;

class Entity : public EntityDecl {
public:
  Entity(const StringC &name, DeclType declType, DataType dataType,
  const Location &defLocation);

  virtual void litReference(Text &, ParserState &,
       const Ptr<EntityOrigin> &,
       Boolean squeezeSpaces)
    const;

  virtual void declReference(ParserState &,
        const Ptr<EntityOrigin> &)
    const;

  virtual void dsReference(ParserState &,
      const Ptr<EntityOrigin> &)
    const;

  virtual void contentReference(ParserState &,
    const Ptr<EntityOrigin> &)
    const;

  virtual void rcdataReference(ParserState &,
          const Ptr<EntityOrigin> &)
    const;

  virtual Boolean isDataOrSubdoc() const;

  virtual Boolean isCharacterData() const;
  virtual const ExternalDataEntity *asExternalDataEntity() const;
  virtual const SubdocEntity *asSubdocEntity() const;
  virtual const InternalEntity *asInternalEntity() const;
  virtual const ExternalEntity *asExternalEntity() const;

  virtual Entity *copy() const = 0;
  virtual void generateSystemId(ParserState &);
  void setUsed();
  Boolean used() const;
  void setDefaulted();
  Boolean defaulted() const;
protected:
  virtual void checkRef(ParserState &) const;
  static void checkEntlvl(ParserState &);
  Boolean checkNotOpen(ParserState &) const;
private:
  virtual void normalReference(ParserState &,
          const Ptr<EntityOrigin> &,
          Boolean generateEvent) const = 0;
  PackedBoolean used_;
  PackedBoolean defaulted_;
};

class InternalEntity : public Entity {
public:
  InternalEntity(const StringC &, DeclType declType, DataType dataType,
   const Location &, Text &);
  const StringC &string() const;
  const Text &text() const;
  const InternalEntity *asInternalEntity() const;
protected:
  void checkRef(ParserState &) const;
  Text text_;
};

class PiEntity : public InternalEntity {
public:
  PiEntity(const StringC &, DeclType, const Location &, Text &);
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void declReference(ParserState &,
       const Ptr<EntityOrigin> &) const;
  void rcdataReference(ParserState &,
         const Ptr<EntityOrigin> &) const;
  Entity *copy() const;
};

class InternalDataEntity : public InternalEntity {
public:
  InternalDataEntity(const StringC &, DataType, const Location &, Text &);
  void declReference(ParserState &,
       const Ptr<EntityOrigin> &) const;
  Boolean isDataOrSubdoc() const;
};

class InternalCdataEntity : public InternalDataEntity {
public:
  InternalCdataEntity(const StringC &, const Location &, Text &);
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
  Entity *copy() const;
  Boolean isCharacterData() const;
};

class PredefinedEntity : public InternalCdataEntity {
public:
  PredefinedEntity(const StringC &s, const Location &l, Text &t)
   : InternalCdataEntity(s,l,t) { }
protected:
  void checkRef(ParserState &) const;
};

class InternalSdataEntity : public InternalDataEntity {
public:
  InternalSdataEntity(const StringC &, const Location &, Text &);
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
  Entity *copy() const;
  Boolean isCharacterData() const;
};

class InternalTextEntity : public InternalEntity {
public:
  enum Bracketed {
    none,
    starttag,
    endtag,
    ms,
    md
    };
  InternalTextEntity(const StringC &, DeclType, const Location &, Text &,
       Bracketed);
  Entity *copy() const;
private:
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
  Bracketed bracketed_;
};

class ExternalEntity : public Entity {
public:
  ExternalEntity(const StringC &, DeclType, DataType, const Location &,
   const ExternalId &);
  const ExternalId &externalId() const;
  const ExternalEntity *asExternalEntity() const;
  void generateSystemId(ParserState &);
  const StringC *systemIdPointer() const;
  const StringC *effectiveSystemIdPointer() const;
  const StringC *publicIdPointer() const;
protected:
  void checkRef(ParserState &) const;
private:
  ExternalId externalId_;
};

class ExternalTextEntity : public ExternalEntity {
public:
  ExternalTextEntity(const StringC &, DeclType, const Location &,
       const ExternalId &);
  Entity *copy() const;
private:
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
};

class ExternalNonTextEntity : public ExternalEntity {
public:
  ExternalNonTextEntity(const StringC &, DeclType, DataType,
   const Location &, const ExternalId &);
  Boolean isDataOrSubdoc() const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean) const;
  void rcdataReference(ParserState &,
         const Ptr<EntityOrigin> &) const;
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean) const;
  void dsReference(ParserState &,
     const Ptr<EntityOrigin> &) const;
  Boolean isCharacterData() const;
};

class ExternalDataEntity : public ExternalNonTextEntity {
public:
  ExternalDataEntity(const StringC &, DataType, const Location &,
       const ExternalId &, const ConstPtr<Notation> &,
       AttributeList &, DeclType = generalEntity);
  const AttributeList &attributes() const;
  const Notation *notation() const;
  const ExternalDataEntity *asExternalDataEntity() const;
  Entity *copy() const;
  void contentReference(ParserState &,
   const Ptr<EntityOrigin> &) const;
  void setNotation(const ConstPtr<Notation> &, AttributeList &);
private:
  ConstPtr<Notation> notation_;
  AttributeList attributes_;
};

class SubdocEntity : public ExternalNonTextEntity {
public:
  SubdocEntity(const StringC &, const Location &, const ExternalId &);
  const SubdocEntity *asSubdocEntity() const;
  Entity *copy() const;
  void contentReference(ParserState &,
   const Ptr<EntityOrigin> &) const;
private:
};

class IgnoredEntity : public Entity {
public:
  IgnoredEntity(const StringC &, DeclType declType);
  Entity *copy() const;
  void litReference(Text &, ParserState &,
      const Ptr<EntityOrigin> &,
      Boolean squeezeSpaces) const;
  void declReference(ParserState &,
       const Ptr<EntityOrigin> &) const;
private:
  void normalReference(ParserState &,
         const Ptr<EntityOrigin> &,
         Boolean generateEvent) const;
};

class EntityOrigin : public InputSourceOrigin {
public:
  static EntityOrigin *make(Allocator &, const ConstPtr<Entity> &);
  static EntityOrigin *make(Allocator &,
       const ConstPtr<Entity> &,
       const Location &refLocation);
  static EntityOrigin *make(Allocator &,
       const ConstPtr<Entity> &,
       const Location &refLocation,
       Index refLength,
       Owner<Markup> &markup);
  static EntityOrigin *make(const ConstPtr<Entity> &,
       const Location &refLocation,
       Index refLength,
       Owner<Markup> &markup);
  static EntityOrigin *make(const ConstPtr<Entity> &,
       const Location &refLocation);
  static const size_t allocSize;
};

inline
Boolean Entity::used() const
{
  return used_;
}

inline
void Entity::setUsed()
{
  used_ = 1;
}

inline
Boolean Entity::defaulted() const
{
  return defaulted_;
}

inline
void Entity::setDefaulted()
{
  defaulted_ = 1;
}

inline
const StringC &InternalEntity::string() const
{
  return text_.string();
}

inline
const Text &InternalEntity::text() const
{
  return text_;
}

inline
const ExternalId &ExternalEntity::externalId() const
{
  return externalId_;
}

inline
const AttributeList &ExternalDataEntity::attributes() const
{
  return attributes_;
}

inline
const Notation *ExternalDataEntity::notation() const
{
  return notation_.pointer();
}



}
# 15 "/usr/include/OpenSP/Dtd.h" 2 3 4
# 1 "/usr/include/OpenSP/ShortReferenceMap.h" 1 3 4






#pragma interface


# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 11 "/usr/include/OpenSP/ShortReferenceMap.h" 2 3 4
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 12 "/usr/include/OpenSP/ShortReferenceMap.h" 2 3 4




# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 17 "/usr/include/OpenSP/ShortReferenceMap.h" 2 3 4


namespace OpenSP {


class ShortReferenceMap : public Named {
public:
  ShortReferenceMap();
  ShortReferenceMap(const StringC &);
  Boolean defined() const;
  void setNameMap(Vector<StringC> &map);
  void setEntityMap(Vector<ConstPtr<Entity> > &map);
  Boolean lookup(int i, const StringC *&) const;
  const StringC *entityName(size_t i) const;
  const ConstPtr<Entity> &entity(size_t i) const;
  Boolean used() const;
  void setUsed();
  const Location &defLocation() const;
  void setDefLocation(const Location &);
private:
  ShortReferenceMap(const ShortReferenceMap &);
  void operator=(const ShortReferenceMap &);
  Vector<StringC> nameMap_;
  Vector<ConstPtr<Entity> > entityMap_;
  ConstPtr<Entity> nullEntity_;
  Boolean used_;
  Location defLocation_;
};

inline
Boolean ShortReferenceMap::defined() const
{
  return nameMap_.size() > 0;
}

inline
const StringC *ShortReferenceMap::entityName(size_t i) const
{
  if (i < nameMap_.size() && nameMap_[i].size() != 0)
    return &nameMap_[i];
  else
    return 0;
}

inline
const ConstPtr<Entity> &ShortReferenceMap::entity(size_t i) const
{
  if (i < entityMap_.size())
    return entityMap_[i];
  else
    return nullEntity_;
}

inline
void ShortReferenceMap::setEntityMap(Vector<ConstPtr<Entity> > &map)
{
  map.swap(entityMap_);
}

inline
Boolean ShortReferenceMap::used() const
{
  return used_;
}

inline
void ShortReferenceMap::setUsed()
{
  used_ = 1;
}

inline
void ShortReferenceMap::setDefLocation(const Location &loc)
{
  defLocation_ = loc;
}

inline
const Location &ShortReferenceMap::defLocation() const
{
  return defLocation_;
}


}
# 16 "/usr/include/OpenSP/Dtd.h" 2 3 4




# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 21 "/usr/include/OpenSP/Dtd.h" 2 3 4
# 1 "/usr/include/OpenSP/HashTable.h" 1 3 4
# 22 "/usr/include/OpenSP/Dtd.h" 2 3 4


namespace OpenSP {


class Syntax;
class ParserState;

class Dtd : public Resource {
public:
  typedef NamedTableIter<ElementType> ElementTypeIter;
  typedef ConstNamedTableIter<ElementType> ConstElementTypeIter;
  typedef NamedTableIter<RankStem> RankStemIter;
  typedef ConstNamedTableIter<RankStem> ConstRankStemIter;
  typedef NamedTableIter<ShortReferenceMap> ShortReferenceMapIter;
  typedef ConstNamedResourceTableIter<Notation> ConstNotationIter;
  typedef NamedResourceTableIter<Notation> NotationIter;
  typedef ConstNamedResourceTableIter<Entity> ConstEntityIter;
  typedef NamedResourceTableIter<Entity> EntityIter;
  Dtd(const StringC &name, Boolean isBase);
  ConstPtr<Entity> lookupEntity(Boolean isParameter, const StringC &) const;
  const Entity *lookupEntityTemp(Boolean isParameter, const StringC &) const;
  Ptr<Entity> lookupEntity(Boolean isParameter, const StringC &);
  Ptr<Entity> insertEntity(const Ptr<Entity> &, Boolean replace = 0);
  Ptr<Entity> removeEntity(Boolean isParameter, const StringC &);
  ConstEntityIter generalEntityIter() const;
  EntityIter generalEntityIter();
  ConstEntityIter parameterEntityIter() const;
  EntityIter parameterEntityIter();

  ConstPtr<Entity> defaultEntity() const;
  const Entity *defaultEntityTemp() const;
  void setDefaultEntity(const Ptr<Entity> &, ParserState &);
  const ConstPtr<StringResource<Char> > &namePointer() const;
  const StringC &name() const;

  const ElementType *lookupElementType(const StringC &) const;
  ElementType *lookupElementType(const StringC &);
  ElementType *removeElementType(const StringC &);
  ElementType *insertElementType(ElementType *);
  size_t nElementTypeIndex() const;
  size_t allocElementTypeIndex();
  ConstElementTypeIter elementTypeIter() const;
  ElementTypeIter elementTypeIter();

  const RankStem *lookupRankStem(const StringC &) const;
  RankStem *lookupRankStem(const StringC &);
  RankStem *insertRankStem(RankStem *);
  size_t nRankStem() const;
  ConstRankStemIter rankStemIter() const;
  RankStemIter rankStemIter();

  const ShortReferenceMap *lookupShortReferenceMap(const StringC &) const;
  ShortReferenceMap *lookupShortReferenceMap(const StringC &);
  ShortReferenceMap *insertShortReferenceMap(ShortReferenceMap *);
  ShortReferenceMapIter shortReferenceMapIter();

  Boolean shortrefIndex(const StringC &, const Syntax &, size_t &index);
  size_t nShortref() const;
  const StringC &shortref(size_t i) const;
  void addNeededShortref(const StringC &);

  ConstPtr<Notation> lookupNotation(const StringC &) const;
  const Notation *lookupNotationTemp(const StringC &) const;
  Ptr<Notation> lookupNotation(const StringC &);
  Ptr<Notation> insertNotation(const Ptr<Notation> &);
  Ptr<Notation> removeNotation(const StringC &);
  ConstNotationIter notationIter() const;
  NotationIter notationIter();

  size_t allocCurrentAttributeIndex();
  size_t nCurrentAttribute() const;
  size_t allocElementDefinitionIndex();
  size_t nElementDefinition() const;
  size_t allocAttributeDefinitionListIndex();
  size_t nAttributeDefinitionList() const;
  const ElementType *documentElementType() const;
  Boolean isBase() const;
  Boolean isInstantiated() const;
  void instantiate();

  Ptr<AttributeDefinitionList> &implicitElementAttributeDef();
  void setImplicitElementAttributeDef(const Ptr<AttributeDefinitionList> &);
  Ptr<AttributeDefinitionList> &implicitNotationAttributeDef();
  void setImplicitNotationAttributeDef(const Ptr<AttributeDefinitionList> &);
private:
  Dtd(const Dtd &);
  void operator=(const Dtd &);
  NamedResourceTable<Entity> generalEntityTable_;
  NamedResourceTable<Entity> parameterEntityTable_;
  ConstPtr<Entity> defaultEntity_;
  ConstPtr<StringResource<Char> > name_;
  NamedTable<ElementType> elementTypeTable_;
  NamedTable<RankStem> rankStemTable_;
  NamedTable<ShortReferenceMap> shortReferenceMapTable_;
  NamedResourceTable<Notation> notationTable_;
  size_t nCurrentAttribute_;
  size_t nElementDefinition_;
  size_t nAttributeDefinitionList_;
  size_t nElementType_;
  ElementType *documentElementType_;
  Vector<StringC> shortrefs_;
  HashTable<StringC,int> shortrefTable_;
  Boolean isBase_;
  Boolean isInstantitated_;
  Ptr<AttributeDefinitionList> implicitElementAttributeDef_;
  Ptr<AttributeDefinitionList> implicitNotationAttributeDef_;
};

inline
ConstPtr<Entity> Dtd::lookupEntity(Boolean isParameter, const StringC &name)
  const
{
  return (isParameter
   ? &parameterEntityTable_
   : &generalEntityTable_)->lookupConst(name);
}

inline
const Entity *Dtd::lookupEntityTemp(Boolean isParameter, const StringC &name)
  const
{
  return (isParameter
   ? &parameterEntityTable_
   : &generalEntityTable_)->lookupTemp(name);
}

inline
Ptr<Entity> Dtd::lookupEntity(Boolean isParameter, const StringC &name)
{
  return (isParameter
   ? &parameterEntityTable_
   : &generalEntityTable_)->lookup(name);
}

inline
Ptr<Entity>
Dtd::insertEntity(const Ptr<Entity> &entity, Boolean replace)
{
  return ((entity->declType() == Entity::parameterEntity
    || entity->declType() == Entity::doctype)
   ? &parameterEntityTable_
   : &generalEntityTable_)->insert(entity, replace);
}

inline
Ptr<Entity> Dtd::removeEntity(Boolean isParameter, const StringC &name)
{
  return (isParameter
   ? &parameterEntityTable_
   : &generalEntityTable_)->remove(name);
}

inline
Dtd::ConstEntityIter Dtd::generalEntityIter() const
{

  return ConstNamedResourceTableIter<Entity>(generalEntityTable_);
}

inline
Dtd::EntityIter Dtd::generalEntityIter()
{

  return NamedResourceTableIter<Entity>(generalEntityTable_);
}

inline
Dtd::ConstEntityIter Dtd::parameterEntityIter() const
{

  return ConstNamedResourceTableIter<Entity>(parameterEntityTable_);
}

inline
Dtd::EntityIter Dtd::parameterEntityIter()
{

  return NamedResourceTableIter<Entity>(parameterEntityTable_);
}

inline
ConstPtr<Entity> Dtd::defaultEntity() const
{
  return defaultEntity_;
}

inline
const Entity *Dtd::defaultEntityTemp() const
{
  return defaultEntity_.pointer();
}

inline
const ConstPtr<StringResource<Char> > &Dtd::namePointer() const
{
  return name_;
}

inline
const StringC &Dtd::name() const
{
  return *name_;
}

inline
size_t Dtd::allocCurrentAttributeIndex()
{
  return nCurrentAttribute_++;
}

inline
size_t Dtd::nCurrentAttribute() const
{
  return nCurrentAttribute_;
}

inline
size_t Dtd::allocElementDefinitionIndex()
{
  return nElementDefinition_++;
}

inline
size_t Dtd::nElementDefinition() const
{
  return nElementDefinition_;
}

inline
size_t Dtd::allocAttributeDefinitionListIndex()
{
  return nAttributeDefinitionList_++;
}

inline
size_t Dtd::nAttributeDefinitionList() const
{
  return nAttributeDefinitionList_;
}

inline
const ElementType *Dtd::lookupElementType(const StringC &name) const
{
  return elementTypeTable_.lookup(name);
}

inline
ElementType *Dtd::lookupElementType(const StringC &name)
{
  return elementTypeTable_.lookup(name);
}

inline
ElementType *Dtd::insertElementType(ElementType *e)
{
  return elementTypeTable_.insert(e);
}

inline
Dtd::ElementTypeIter Dtd::elementTypeIter()
{

  return NamedTableIter<ElementType>(elementTypeTable_);
}

inline
Dtd::ConstElementTypeIter Dtd::elementTypeIter() const
{

  return ConstNamedTableIter<ElementType>(elementTypeTable_);
}

inline
Dtd::RankStemIter Dtd::rankStemIter()
{

  return NamedTableIter<RankStem>(rankStemTable_);
}

inline
Dtd::ConstRankStemIter Dtd::rankStemIter() const
{

  return ConstNamedTableIter<RankStem>(rankStemTable_);
}

inline
ElementType *Dtd::removeElementType(const StringC &name)
{
  return elementTypeTable_.remove(name);
}

inline
size_t Dtd::nElementTypeIndex() const
{

  return 1 + nElementType_;
}

inline
size_t Dtd::allocElementTypeIndex()
{
  return 1 + nElementType_++;
}

inline
const RankStem *Dtd::lookupRankStem(const StringC &name) const
{
  return rankStemTable_.lookup(name);
}

inline
RankStem *Dtd::lookupRankStem(const StringC &name)
{
  return rankStemTable_.lookup(name);
}

inline
RankStem *Dtd::insertRankStem(RankStem *e)
{
  return rankStemTable_.insert(e);
}

inline
size_t Dtd::nRankStem() const
{
  return rankStemTable_.count();
}

inline
ConstPtr<Notation> Dtd::lookupNotation(const StringC &name) const
{
  return notationTable_.lookupConst(name);
}

inline
const Notation *Dtd::lookupNotationTemp(const StringC &name) const
{
  return notationTable_.lookupTemp(name);
}

inline
Ptr<Notation> Dtd::lookupNotation(const StringC &name)
{
  return notationTable_.lookup(name);
}

inline
Ptr<Notation> Dtd::insertNotation(const Ptr<Notation> &nt)
{
  return notationTable_.insert(nt);
}

inline
Dtd::ConstNotationIter Dtd::notationIter() const
{

  return ConstNamedResourceTableIter<Notation>(notationTable_);
}

inline
Dtd::NotationIter Dtd::notationIter()
{

  return NamedResourceTableIter<Notation>(notationTable_);
}

inline
Ptr<Notation> Dtd::removeNotation(const StringC &name)
{
  return notationTable_.remove(name);
}

inline
const ElementType *Dtd::documentElementType() const
{
  return documentElementType_;
}

inline
const ShortReferenceMap *Dtd::lookupShortReferenceMap(const StringC &name) const
{
  return shortReferenceMapTable_.lookup(name);
}

inline
ShortReferenceMap *Dtd::lookupShortReferenceMap(const StringC &name)
{
  return shortReferenceMapTable_.lookup(name);
}

inline
ShortReferenceMap *Dtd::insertShortReferenceMap(ShortReferenceMap *map)
{
  return shortReferenceMapTable_.insert(map);
}

inline
Dtd::ShortReferenceMapIter Dtd::shortReferenceMapIter()
{

  return NamedTableIter<ShortReferenceMap>(shortReferenceMapTable_);
}

inline
Boolean Dtd::isBase() const
{
  return isBase_;
}

inline
size_t Dtd::nShortref() const
{
  return shortrefs_.size();
}

inline
const StringC &Dtd::shortref(size_t i) const
{
  return shortrefs_[i];
}

inline
Ptr<AttributeDefinitionList> &Dtd::implicitElementAttributeDef()
{
  return implicitElementAttributeDef_;
}

inline
void Dtd::setImplicitElementAttributeDef(const Ptr<AttributeDefinitionList> &def)
{
  implicitElementAttributeDef_ = def;
}

inline
Ptr<AttributeDefinitionList> &Dtd::implicitNotationAttributeDef()
{
  return implicitNotationAttributeDef_;
}

inline
void Dtd::setImplicitNotationAttributeDef(const Ptr<AttributeDefinitionList> &def)
{
  implicitNotationAttributeDef_ = def;
}

inline
Boolean Dtd::isInstantiated() const
{
  return isInstantitated_;
}

inline
void Dtd::instantiate()
{
  isInstantitated_ = 1;
}


}
# 23 "/usr/include/OpenSP/Event.h" 2 3 4


# 1 "/usr/include/OpenSP/Lpd.h" 1 3 4






#pragma interface




# 1 "/usr/include/OpenSP/Ptr.h" 1 3 4
# 13 "/usr/include/OpenSP/Lpd.h" 2 3 4
# 22 "/usr/include/OpenSP/Lpd.h" 3 4
namespace OpenSP {


class ElementType;

struct ResultElementSpec {
  ResultElementSpec();
  const ElementType *elementType;
  AttributeList attributeList;
  void swap(ResultElementSpec &);
};

class Lpd : public Resource {
public:
  enum Type { simpleLink, implicitLink, explicitLink };
  Lpd(const StringC &, Type, const Location &,
      const Ptr<Dtd> &sourceDtd);
  virtual ~Lpd();
  Type type() const;
  const Location &location() const;
  const Ptr<Dtd> &sourceDtd();
  ConstPtr<Dtd> sourceDtd() const;
  Boolean active() const;
  void activate();
  const ConstPtr<StringResource<Char> > &namePointer() const;
  const StringC &name() const;
private:
  Lpd(const Lpd &);
  void operator=(const Lpd &);
  Type type_;
  Location location_;
  Boolean active_;
  Ptr<Dtd> sourceDtd_;
  ConstPtr<StringResource<Char> > name_;
};

class SimpleLpd : public Lpd, public Attributed {
public:
  SimpleLpd(const StringC &, const Location &,
     const Ptr<Dtd> &sourceDtd);
private:
  SimpleLpd(const SimpleLpd &);
  void operator=(const SimpleLpd &);
};

class LinkSet;



class SourceLinkRule {
public:
  SourceLinkRule();
  void setLinkAttributes(AttributeList &);
  void setResult(const ElementType *, AttributeList &);
  void setUselink(const LinkSet *);
  void setPostlink(const LinkSet *);
  void setPostlinkRestore();
  void swap(SourceLinkRule &);
  const AttributeList &attributes() const;
  const ResultElementSpec &resultElementSpec() const;
  const LinkSet *uselink() const;
  const LinkSet *postlink() const;
  Boolean postlinkRestore() const;
private:
  const LinkSet *uselink_;
  const LinkSet *postlink_;
  Boolean postlinkRestore_;
  AttributeList linkAttributes_;
  ResultElementSpec resultElementSpec_;
};

class SourceLinkRuleResource : public Resource, public SourceLinkRule {
public:
  SourceLinkRuleResource();
};

class LinkSet : public Named {
public:
  LinkSet(const StringC &, const Dtd *);
  void setDefined();
  Boolean defined() const;
  void addImplied(const ElementType *, AttributeList &);
  size_t nLinkRules(const ElementType *) const;
  const SourceLinkRule &linkRule(const ElementType *, size_t) const;
  void addLinkRule(const ElementType *,
     const ConstPtr<SourceLinkRuleResource> &);
  size_t nImpliedLinkRules() const;
  const ResultElementSpec &impliedLinkRule(size_t) const;
  Boolean impliedResultAttributes(const ElementType *,
      const AttributeList *&);
private:
  LinkSet(const LinkSet &);
  void operator=(const LinkSet &);
  Boolean defined_;

  Vector<Vector<ConstPtr<SourceLinkRuleResource> > >
    linkRules_;
  Vector<ResultElementSpec> impliedSourceLinkRules_;
};

class IdLinkRule : public SourceLinkRule {
public:
  IdLinkRule();
  Boolean isAssociatedWith(const ElementType *) const;
  void setAssocElementTypes(Vector<const ElementType *> &);
  void swap(IdLinkRule &);
private:
  Vector<const ElementType *> assocElementTypes_;
};




class IdLinkRuleGroup : public Named {
public:
  IdLinkRuleGroup(const StringC &);
  size_t nLinkRules() const;
  const IdLinkRule &linkRule(size_t) const;
  void addLinkRule(IdLinkRule &);
private:
  IdLinkRuleGroup(const IdLinkRuleGroup &);
  void operator=(const IdLinkRuleGroup &);
  Vector<IdLinkRule> linkRules_;
};



class ComplexLpd : public Lpd {
public:
  typedef ConstNamedTableIter<LinkSet> ConstLinkSetIter;
  ComplexLpd(const StringC &, Type,
      const Location &,
      const Syntax &syntax,
      const Ptr<Dtd> &sourceDtd,
      const Ptr<Dtd> &resultDtd);
  size_t allocAttributeDefinitionListIndex();
  size_t nAttributeDefinitionList() const;
  LinkSet *initialLinkSet();
  const LinkSet *initialLinkSet() const;
  const LinkSet *emptyLinkSet() const;
  const LinkSet *lookupLinkSet(const StringC &) const;
  const IdLinkRuleGroup *lookupIdLink(const StringC &) const;
  IdLinkRuleGroup *lookupCreateIdLink(const StringC &);
  void insertIdLink(IdLinkRuleGroup *);
  ConstLinkSetIter linkSetIter() const;
  Boolean hadIdLinkSet() const;
  void setHadIdLinkSet();

  LinkSet *lookupLinkSet(const StringC &);
  LinkSet *insertLinkSet(LinkSet *);
  const Ptr<Dtd> &resultDtd();
  ConstPtr<Dtd> resultDtd() const;
  const ConstPtr<AttributeDefinitionList> &
    attributeDef(const ElementType *) const;
  void setAttributeDef(const ElementType *,
         const ConstPtr<AttributeDefinitionList> &);
private:
  ComplexLpd(const ComplexLpd &);
  void operator=(const ComplexLpd &);
  Ptr<Dtd> resultDtd_;
  Vector<ConstPtr<AttributeDefinitionList> > linkAttributeDefs_;
  NamedTable<LinkSet> linkSetTable_;
  LinkSet initialLinkSet_;
  LinkSet emptyLinkSet_;
  Boolean hadIdLinkSet_;
  NamedTable<IdLinkRuleGroup> idLinkTable_;
  size_t nAttributeDefinitionList_;
};

inline
Lpd::Type Lpd::type() const
{
  return type_;
}

inline
const Location &Lpd::location() const
{
  return location_;
}

inline
Boolean Lpd::active() const
{
  return active_;
}

inline
void Lpd::activate()
{
  active_ = 1;
}

inline
ConstPtr<Dtd> Lpd::sourceDtd() const
{
  return sourceDtd_;
}

inline
const Ptr<Dtd> &Lpd::sourceDtd()
{
  return sourceDtd_;
}

inline
const ConstPtr<StringResource<Char> > &Lpd::namePointer() const
{
  return name_;
}

inline
const StringC &Lpd::name() const
{
  return *name_;
}

inline
void SourceLinkRule::setLinkAttributes(AttributeList &attributes)
{
  attributes.swap(linkAttributes_);
}

inline
const AttributeList &SourceLinkRule::attributes() const
{
  return linkAttributes_;
}

inline
void SourceLinkRule::setResult(const ElementType *element,
          AttributeList &attributes)
{
  resultElementSpec_.elementType = element;
  attributes.swap(resultElementSpec_.attributeList);
}

inline
const ResultElementSpec &SourceLinkRule::resultElementSpec() const
{
  return resultElementSpec_;
}

inline
void SourceLinkRule::setUselink(const LinkSet *linkSet)
{
  uselink_ = linkSet;
}

inline
void SourceLinkRule::setPostlink(const LinkSet *linkSet)
{
  postlink_ = linkSet;
}

inline
void SourceLinkRule::setPostlinkRestore()
{
  postlinkRestore_ = 1;
}

inline
const LinkSet *SourceLinkRule::uselink() const
{
  return uselink_;
}

inline
const LinkSet *SourceLinkRule::postlink() const
{
  return postlink_;
}

inline
Boolean SourceLinkRule::postlinkRestore() const
{
  return postlinkRestore_;
}

inline
Boolean LinkSet::defined() const
{
  return defined_;
}

inline
void LinkSet::setDefined()
{
  defined_ = 1;
}

inline
const SourceLinkRule &LinkSet::linkRule(const ElementType *e, size_t i) const
{
  return *linkRules_[e->index()][i];
}

inline
size_t LinkSet::nImpliedLinkRules() const
{
  return impliedSourceLinkRules_.size();
}

inline
const ResultElementSpec &LinkSet::impliedLinkRule(size_t i) const
{
  return impliedSourceLinkRules_[i];
}

inline
const Ptr<Dtd> &ComplexLpd::resultDtd()
{
  return resultDtd_;
}

inline
ConstPtr<Dtd> ComplexLpd::resultDtd() const
{
  return resultDtd_;
}

inline
LinkSet *ComplexLpd::initialLinkSet()
{
  return &initialLinkSet_;
}

inline
const LinkSet *ComplexLpd::initialLinkSet() const
{
  return &initialLinkSet_;
}

inline
const LinkSet *ComplexLpd::emptyLinkSet() const
{
  return &emptyLinkSet_;
}

inline
const LinkSet *ComplexLpd::lookupLinkSet(const StringC &name) const
{
  return linkSetTable_.lookup(name);
}

inline
LinkSet *ComplexLpd::lookupLinkSet(const StringC &name)
{
  return linkSetTable_.lookup(name);
}

inline
LinkSet *ComplexLpd::insertLinkSet(LinkSet *e)
{
  return linkSetTable_.insert(e);
}

inline
size_t ComplexLpd::nAttributeDefinitionList() const
{
  return nAttributeDefinitionList_;
}

inline
size_t ComplexLpd::allocAttributeDefinitionListIndex()
{
  return nAttributeDefinitionList_++;
}

inline
ComplexLpd::ConstLinkSetIter ComplexLpd::linkSetIter() const
{

  return ConstNamedTableIter<LinkSet>(linkSetTable_);
}

inline
const ConstPtr<AttributeDefinitionList> &
ComplexLpd::attributeDef(const ElementType *e) const
{
  return linkAttributeDefs_[e->index()];
}

inline
void ComplexLpd::setAttributeDef(const ElementType *e,
     const ConstPtr<AttributeDefinitionList> &attdef)
{
  linkAttributeDefs_[e->index()] = attdef;
}

inline
Boolean ComplexLpd::hadIdLinkSet() const
{
  return hadIdLinkSet_;
}

inline
void ComplexLpd::setHadIdLinkSet()
{
  hadIdLinkSet_ = 1;
}

inline
const IdLinkRuleGroup *ComplexLpd::lookupIdLink(const StringC &id) const
{
  return idLinkTable_.lookup(id);
}

inline
size_t IdLinkRuleGroup::nLinkRules() const
{
  return linkRules_.size();
}

inline
const IdLinkRule &IdLinkRuleGroup::linkRule(size_t i) const
{
  return linkRules_[i];
}


}
# 26 "/usr/include/OpenSP/Event.h" 2 3 4





namespace OpenSP {


class EventHandler;

class Event : public Link {
public:
  enum Type {
    message,
    characterData,
    startElement,
    endElement,
    pi,
    sdataEntity,
    externalDataEntity,
    subdocEntity,
    nonSgmlChar,
    appinfo,
    startDtd,
    endDtd,
    startLpd,
    endLpd,
    endProlog,
    sgmlDecl,
    uselink,
    usemap,
    commentDecl,
    sSep,
    ignoredRs,
    ignoredRe,
    reOrigin,
    ignoredChars,
    markedSectionStart,
    markedSectionEnd,
    entityStart,
    entityEnd,
    notationDecl,
    entityDecl,
    elementDecl,
    attlistDecl,
    attlistNotationDecl,
    linkAttlistDecl,
    linkDecl,
    idLinkDecl,
    shortrefDecl,
    ignoredMarkup,
    entityDefaulted,
    sgmlDeclEntity
    };
  Event(Type);
  virtual void handle(EventHandler &) = 0;
  virtual void copyData();
  void *operator new(size_t sz, Allocator &alloc) { return alloc.alloc(sz); }
  void *operator new(size_t sz) { return Allocator::allocSimple(sz); }
  void operator delete(void *p) { Allocator::free(p); }



  Type type() const;
private:
  Event(const Event &);
  void operator=(const Event &);
  Type type_;
};

class LocatedEvent : public Event {
public:
  LocatedEvent(Type type, const Location &);
  const Location &location() const;
private:
  LocatedEvent(const LocatedEvent &);
  void operator=(const LocatedEvent &);
  Location location_;
};

class MarkupEvent : public LocatedEvent {
public:
  MarkupEvent(Type type);
  MarkupEvent(Type type, const Location &, Markup *);
  const Markup &markup() const;
private:
  MarkupEvent(const MarkupEvent &);
  void operator=(const MarkupEvent &);
  Markup markup_;
};

class MessageEvent : public Event {
public:
  MessageEvent(Message &);
  MessageEvent(const Message &);
  const Message &message() const;
  void handle(EventHandler &);
private:
  MessageEvent(const MessageEvent &);
  void operator=(const MessageEvent &);
  Message message_;
};

class AttributeList;

class StartElementEvent : public LocatedEvent {
public:
  StartElementEvent(const ElementType *,
      const ConstPtr<Dtd> &,
      AttributeList *,
      const Location &,
      Markup *);
  ~StartElementEvent();
  void handle(EventHandler &);
  Boolean mustOmitEnd() const;
  void setIncluded();
  Boolean included() const;
  const StringC &name() const;
  const ElementType *elementType() const;
  const Markup *markupPtr() const;
  const AttributeList &attributes() const;
  void copyData();
private:
  StartElementEvent(const StartElementEvent &);
  void operator=(const StartElementEvent &);
  const ElementType *elementType_;
  ConstPtr<Dtd> dtd_;
  PackedBoolean included_;
  PackedBoolean copied_;
  Markup *markup_;
  AttributeList *attributes_;
};

class EndElementEvent : public LocatedEvent {
public:
  EndElementEvent(const ElementType *,
    const ConstPtr<Dtd> &,
    const Location &,
    Markup *);
  ~EndElementEvent();
  void handle(EventHandler &);
  void setIncluded();
  Boolean included() const;
  const StringC &name() const;
  const ElementType *elementType() const;
  const Markup *markupPtr() const;
  void copyData();
private:
  EndElementEvent(const EndElementEvent &);
  void operator=(const EndElementEvent &);
  const ElementType *elementType_;
  ConstPtr<Dtd> dtd_;
  PackedBoolean included_;
  PackedBoolean copied_;
  Markup *markup_;
};

class DataEvent : public LocatedEvent {
public:
  DataEvent(Type, const Char *, size_t, const Location &);
  void handle(EventHandler &);
  const Char *data() const;
  size_t dataLength() const;
  virtual Boolean isRe(unsigned long &serial) const;
  virtual const Entity *entity() const;
protected:
  const Char *p_;
  size_t length_;
private:
  DataEvent(const DataEvent &);
  void operator=(const DataEvent &);
};

class ImmediateDataEvent : public DataEvent {
public:
  ImmediateDataEvent(Type type, const Char *, size_t, const Location &,
       Boolean copy);
  ~ImmediateDataEvent();
  void copyData();
private:
  ImmediateDataEvent(const ImmediateDataEvent &);
  void operator=(const ImmediateDataEvent &);
  Char *alloc_;
};

class InternalDataEntity;

class DataEntityEvent : public DataEvent {
public:
  DataEntityEvent(Type type, const InternalEntity *,
    const ConstPtr<Origin> &);
  const Entity *entity() const;
private:
  DataEntityEvent(const DataEntityEvent &);
  void operator=(const DataEntityEvent &);
};

class InternalCdataEntity;

class CdataEntityEvent : public DataEntityEvent {
public:
  CdataEntityEvent(const InternalEntity *,
     const ConstPtr<Origin> &);
private:
  CdataEntityEvent(const CdataEntityEvent &);
  void operator=(const CdataEntityEvent &);
};

class InternalSdataEntity;

class SdataEntityEvent : public DataEntityEvent {
public:
  SdataEntityEvent(const InternalEntity *,
     const ConstPtr<Origin> &);
  void handle(EventHandler &);
private:
  SdataEntityEvent(const SdataEntityEvent &);
  void operator=(const SdataEntityEvent &);
};

class PiEntity;

class PiEvent : public LocatedEvent {
public:
  PiEvent(const Char *, size_t, const Location &);
  const Char *data() const;
  size_t dataLength() const;
  virtual const Entity *entity() const;
  void handle(EventHandler &);
private:
  PiEvent(const PiEvent &);
  void operator=(const PiEvent &);
  const Char *data_;
  size_t dataLength_;
};

class ImmediatePiEvent : public PiEvent {
public:
  ImmediatePiEvent(StringC &, const Location &);
private:
  ImmediatePiEvent(const ImmediatePiEvent &);
  void operator=(const ImmediatePiEvent &);
  StringC string_;
};

class PiEntityEvent : public PiEvent {
public:
  PiEntityEvent(const PiEntity *entity,
  const ConstPtr<Origin> &origin);
  const Entity *entity() const;
private:
  PiEntityEvent(const PiEntityEvent &);
  void operator=(const PiEntityEvent &);
};

class ExternalNonTextEntity;
class ExternalDataEntity;
class SubdocEntity;

class ExternalEntityEvent : public Event {
public:
  ExternalEntityEvent(Type type,
        const ConstPtr<EntityOrigin> &);
  const ConstPtr<EntityOrigin> &entityOrigin() const;
  const Location &location() const;
private:
  ExternalEntityEvent(const ExternalEntityEvent &);
  void operator=(const ExternalEntityEvent &);
  ConstPtr<EntityOrigin> origin_;
};

class ExternalDataEntityEvent : public ExternalEntityEvent {
public:
  ExternalDataEntityEvent(const ExternalDataEntity *,
     const ConstPtr<EntityOrigin> &);
  void handle(EventHandler &);
  const ExternalDataEntity *entity() const;
private:
  ExternalDataEntityEvent(const ExternalDataEntityEvent &);
  void operator=(const ExternalDataEntityEvent &);
  const ExternalDataEntity *dataEntity_;
};

class SubdocEntityEvent : public ExternalEntityEvent {
public:
  SubdocEntityEvent(const SubdocEntity *,
      const ConstPtr<EntityOrigin> &);
  void handle(EventHandler &);
  const SubdocEntity *entity() const;
private:
  SubdocEntityEvent(const SubdocEntityEvent &);
  void operator=(const SubdocEntityEvent &);
  const SubdocEntity *subdocEntity_;
};

class NonSgmlCharEvent : public LocatedEvent {
public:
  NonSgmlCharEvent(Char c, const Location &);
  Char character() const;
  void handle(EventHandler &);
private:
  NonSgmlCharEvent(const NonSgmlCharEvent &);
  void operator=(const NonSgmlCharEvent &);
  Char c_;
};

class AppinfoEvent : public LocatedEvent {
public:
  AppinfoEvent(const Location &);
  AppinfoEvent(const Text &, const Location &);
  void handle(EventHandler &);
  Boolean literal(const StringC *&) const;
private:
  AppinfoEvent(const AppinfoEvent &);
  void operator=(const AppinfoEvent &);
  Boolean appinfoNone_;
  Text appinfo_;
};

class UselinkEvent : public MarkupEvent {
public:
  UselinkEvent(const ConstPtr<Lpd> &,
        const LinkSet *,
        Boolean restore,
        const Location &,
        Markup *);
  void handle(EventHandler &);
  const ConstPtr<Lpd> &lpd() const;
  const LinkSet *linkSet() const;
  Boolean restore() const;
private:
  UselinkEvent(const UselinkEvent &);
  void operator=(const UselinkEvent &);
  ConstPtr<Lpd> lpd_;
  const LinkSet *linkSet_;
  Boolean restore_;
};

class UsemapEvent : public MarkupEvent {
public:
  UsemapEvent(const ShortReferenceMap *,
       Vector<const ElementType *> &,
       const ConstPtr<Dtd> &,
       const Location &,
       Markup *);
  void handle(EventHandler &);
  const ShortReferenceMap *map() const;
  const Vector<const ElementType *> &elements() const;
private:
  UsemapEvent(const UsemapEvent &);
  void operator=(const UsemapEvent &);
  ConstPtr<Dtd> dtd_;
  Vector<const ElementType *> elements_;
  const ShortReferenceMap *map_;
};

class StartSubsetEvent : public MarkupEvent {
public:
  StartSubsetEvent(Type,
     const StringC &,
     const ConstPtr<Entity> &entity,
     Boolean hasInternalSubset,
     const Location &,
     Markup *);
  const StringC &name() const;
  const ConstPtr<Entity> &entity() const;
  Boolean hasInternalSubset() const;
private:
  StartSubsetEvent(const StartSubsetEvent &);
  void operator=(const StartSubsetEvent &);
  StringC name_;
  ConstPtr<Entity> entity_;
  Boolean hasInternalSubset_;
};

class StartDtdEvent : public StartSubsetEvent {
public:
  StartDtdEvent(const StringC &,
  const ConstPtr<Entity> &entity,
  Boolean hasInternalSubset,
  const Location &,
  Markup *);
  void handle(EventHandler &);
private:
  StartDtdEvent(const StartDtdEvent &);
  void operator=(const StartDtdEvent &);
};

class StartLpdEvent : public StartSubsetEvent {
public:
  StartLpdEvent(Boolean active,
  const StringC &,
  const ConstPtr<Entity> &entity,
  Boolean hasInternalSubset,
  const Location &,
  Markup *);
  void handle(EventHandler &);
  Boolean active() const;
private:
  StartLpdEvent(const StartLpdEvent &);
  void operator=(const StartLpdEvent &);
  Boolean active_;
};

class EndDtdEvent : public MarkupEvent {
public:
  EndDtdEvent(const ConstPtr<Dtd> &, const Location &,
       Markup *);
  void handle(EventHandler &);
  const Dtd &dtd() const;
  const ConstPtr<Dtd> &dtdPointer() const;
private:
  EndDtdEvent(const EndDtdEvent &);
  void operator=(const EndDtdEvent &);
  ConstPtr<Dtd> dtd_;
};

class EndLpdEvent : public MarkupEvent {
public:
  EndLpdEvent(const ConstPtr<Lpd> &, const Location &,
       Markup *);
  void handle(EventHandler &);
  const Lpd &lpd() const;
  const ConstPtr<Lpd> &lpdPointer() const;
private:
  EndLpdEvent(const EndLpdEvent &);
  void operator=(const EndLpdEvent &);
  ConstPtr<Lpd> lpd_;
};

class EndPrologEvent : public LocatedEvent {
public:
  EndPrologEvent(const ConstPtr<Dtd> &dtd,
   const ConstPtr<ComplexLpd> &lpd,
   Vector<StringC> &simpleLinkNames,
   Vector<AttributeList> &simpleLinkAttributes,
   const Location &);
  EndPrologEvent(const ConstPtr<Dtd> &dtd,
   const Location &);
  void handle(EventHandler &);
  const Dtd &dtd() const;
  const ConstPtr<Dtd> &dtdPointer() const;
  const ConstPtr<ComplexLpd> &lpdPointer() const;
  const Vector<StringC> &simpleLinkNames() const;
  const Vector<AttributeList> &simpleLinkAttributes() const;
private:
  EndPrologEvent(const EndPrologEvent &);
  void operator=(const EndPrologEvent &);
  ConstPtr<Dtd> dtd_;
  ConstPtr<ComplexLpd> lpd_;
  Vector<StringC> simpleLinkNames_;
  Vector<AttributeList> simpleLinkAttributes_;
};

class SgmlDeclEvent : public MarkupEvent {
public:

  SgmlDeclEvent(const ConstPtr<Sd> &,
  const ConstPtr<Syntax> &syntax);

  SgmlDeclEvent(const ConstPtr<Sd> &,
  const ConstPtr<Syntax> &syntax,
  const ConstPtr<Syntax> &instanceSyntax,
  const ConstPtr<Sd> &refSd,
  const ConstPtr<Syntax> &refSyntax,
  Index nextIndex,
  const StringC &implySystemId,
  const Location &,
  Markup *);
  void handle(EventHandler &);
  const Sd &sd() const;
  const ConstPtr<Sd> &sdPointer() const;
  const Syntax &prologSyntax() const;
  const ConstPtr<Syntax> &prologSyntaxPointer() const;
  const Syntax &instanceSyntax() const;
  const ConstPtr<Syntax> &instanceSyntaxPointer() const;
  const ConstPtr<Sd> &refSdPointer() const;
  const ConstPtr<Syntax> &refSyntaxPointer() const;
  const StringC &implySystemId() const;
private:
  SgmlDeclEvent(const SgmlDeclEvent &);
  void operator=(const SgmlDeclEvent &);
  ConstPtr<Sd> sd_;
  ConstPtr<Syntax> prologSyntax_;
  ConstPtr<Syntax> instanceSyntax_;
  ConstPtr<Sd> refSd_;
  ConstPtr<Syntax> refSyntax_;
  Index nextIndex_;
  StringC implySystemId_;
};

class CommentDeclEvent : public MarkupEvent {
public:
  CommentDeclEvent(const Location &, Markup *);
  void handle(EventHandler &);
private:
  CommentDeclEvent(const CommentDeclEvent &);
  void operator=(const CommentDeclEvent &);
};

class SSepEvent : public ImmediateDataEvent {
public:
  SSepEvent(const Char *, size_t, const Location &, Boolean copy);
  void handle(EventHandler &);
private:
  SSepEvent(const SSepEvent &);
  void operator=(const SSepEvent &);
};

class IgnoredRsEvent : public LocatedEvent {
public:
  IgnoredRsEvent(Char c, const Location &);
  void handle(EventHandler &);
  Char rs() const;
private:
  IgnoredRsEvent(const IgnoredRsEvent &);
  void operator=(const IgnoredRsEvent &);
  Char c_;
};

class IgnoredReEvent : public LocatedEvent {
public:
  IgnoredReEvent(Char c, const Location &, unsigned long serial);
  void handle(EventHandler &);
  Char re() const;
  unsigned long serial() const;
private:
  IgnoredReEvent(const IgnoredReEvent &);
  void operator=(const IgnoredReEvent &);
  unsigned long serial_;
  Char c_;
};

class ReEvent : public ImmediateDataEvent {
public:
  ReEvent(const Char *, const Location &, unsigned long serial);
  Boolean isRe(unsigned long &serial) const;
private:
  ReEvent(const ReEvent &);
  void operator=(const ReEvent &);
  unsigned long serial_;
};

class ReOriginEvent : public LocatedEvent {
public:
  ReOriginEvent(Char c, const Location &, unsigned long serial);
  void handle(EventHandler &);
  Char re() const;
  unsigned long serial() const;
private:
  ReOriginEvent(const ReOriginEvent &);
  void operator=(const ReOriginEvent &);
  unsigned long serial_;
  Char c_;
};

class IgnoredCharsEvent : public ImmediateDataEvent {
public:
  IgnoredCharsEvent(const Char *, size_t, const Location &, Boolean copy);
  void handle(EventHandler &);
private:
  IgnoredCharsEvent(const IgnoredCharsEvent &);
  void operator=(const IgnoredCharsEvent &);
};

class MarkedSectionEvent : public MarkupEvent {
public:
  enum Status { include, rcdata, cdata, ignore };
  MarkedSectionEvent(Type, Status, const Location &, Markup *);
  Status status() const;
private:
  MarkedSectionEvent(const MarkedSectionEvent &);
  void operator=(const MarkedSectionEvent &);
  Status status_;
};

class MarkedSectionStartEvent : public MarkedSectionEvent {
public:
  MarkedSectionStartEvent(Status, const Location &, Markup *);
  void handle(EventHandler &);
private:
  MarkedSectionStartEvent(const MarkedSectionStartEvent &);
  void operator=(const MarkedSectionStartEvent &);
};

class MarkedSectionEndEvent : public MarkedSectionEvent {
public:
  MarkedSectionEndEvent(Status, const Location &, Markup *);
  void handle(EventHandler &);
private:
  MarkedSectionEndEvent(const MarkedSectionEndEvent &);
  void operator=(const MarkedSectionEndEvent &);
};

class EntityStartEvent : public Event {
public:
  EntityStartEvent(const ConstPtr<EntityOrigin> &origin);
  void handle(EventHandler &);
  const Entity *entity() const;
  const ConstPtr<EntityOrigin> &entityOrigin() const;
private:
  EntityStartEvent(const EntityStartEvent &);
  void operator=(const EntityStartEvent &);

  ConstPtr<EntityOrigin> origin_;
};

class EntityEndEvent : public LocatedEvent {
public:
  EntityEndEvent(const Location &);
  void handle(EventHandler &);
private:
  EntityEndEvent(const EntityEndEvent &);
  void operator=(const EntityEndEvent &);
};

class EntityDeclEvent : public MarkupEvent {
public:
  EntityDeclEvent(const ConstPtr<Entity> &,
    Boolean ignored,
    const Location &,
    Markup *);
  void handle(EventHandler &);
  const Entity &entity() const;
  const ConstPtr<Entity> &entityPointer() const;
  Boolean ignored() const;

private:
  Boolean ignored_;

  ConstPtr<Entity> entity_;
};

class NotationDeclEvent : public MarkupEvent {
public:
  NotationDeclEvent(const ConstPtr<Notation> &,
      const Location &,
      Markup *);
  void handle(EventHandler &);
  const Notation &notation() const;
  const ConstPtr<Notation> &notationPointer() const;
private:
  NotationDeclEvent(const NotationDeclEvent &);
  void operator=(const NotationDeclEvent &);
  ConstPtr<Notation> notation_;
};

class ElementDeclEvent : public MarkupEvent {
public:
  ElementDeclEvent(Vector<const ElementType *> &elements,
     const ConstPtr<Dtd> &,
     const Location &,
     Markup *);
  void handle(EventHandler &);
  const Vector<const ElementType *> &elements() const;
private:
  ElementDeclEvent(const ElementDeclEvent &);
  void operator=(const ElementDeclEvent &);
  Vector<const ElementType *> elements_;
  ConstPtr<Dtd> dtd_;
};

class AttlistDeclEvent : public MarkupEvent {
public:
  AttlistDeclEvent(Vector<const ElementType *> &elements,
     const ConstPtr<Dtd> &,
     const Location &,
     Markup *);
  void handle(EventHandler &);
  const Vector<const ElementType *> &elements() const;
private:
  AttlistDeclEvent(const AttlistDeclEvent &);
  void operator=(const AttlistDeclEvent &);
  Vector<const ElementType *> elements_;
  ConstPtr<Dtd> dtd_;
};

class AttlistNotationDeclEvent : public MarkupEvent {
public:
  AttlistNotationDeclEvent(Vector<ConstPtr<Notation> > &notations,
      const Location &,
      Markup *);
  void handle(EventHandler &);
  const Vector<ConstPtr<Notation> > &notations() const;
private:
  AttlistNotationDeclEvent(const AttlistNotationDeclEvent &);
  void operator=(const AttlistDeclEvent &);
  Vector<ConstPtr<Notation> > notations_;
};

class LinkAttlistDeclEvent : public MarkupEvent {
public:
  LinkAttlistDeclEvent(Vector<const ElementType *> &elements,
         const ConstPtr<Lpd> &,
         const Location &,
         Markup *);
  void handle(EventHandler &);
  const Vector<const ElementType *> &elements() const;
  const Lpd &lpd() const;
private:
  LinkAttlistDeclEvent(const LinkAttlistDeclEvent &);
  void operator=(const LinkAttlistDeclEvent &);
  Vector<const ElementType *> elements_;
  ConstPtr<Lpd> lpd_;
};

class LinkDeclEvent : public MarkupEvent {
public:
  LinkDeclEvent(const LinkSet *linkSet,
  const ConstPtr<ComplexLpd> &,
  const Location &,
  Markup *);
  void handle(EventHandler &);
  const LinkSet *linkSet() const;
  const ComplexLpd &lpd() const;
private:
  LinkDeclEvent(const LinkDeclEvent &);
  void operator=(const LinkDeclEvent &);
  const LinkSet *linkSet_;
  ConstPtr<ComplexLpd> lpd_;
};

class IdLinkDeclEvent : public MarkupEvent {
public:
  IdLinkDeclEvent(const ConstPtr<ComplexLpd> &,
    const Location &,
    Markup *);
  void handle(EventHandler &);
  const ComplexLpd &lpd() const;
private:
  IdLinkDeclEvent(const IdLinkDeclEvent &);
  void operator=(const IdLinkDeclEvent &);
  ConstPtr<ComplexLpd> lpd_;
};

class ShortrefDeclEvent : public MarkupEvent {
public:
  ShortrefDeclEvent(const ShortReferenceMap *,
      const ConstPtr<Dtd> &,
      const Location &,
      Markup *);
  void handle(EventHandler &);
  const ShortReferenceMap *map() const;
private:
  ShortrefDeclEvent(const ShortrefDeclEvent &);
  void operator=(const ShortrefDeclEvent &);
  const ShortReferenceMap *map_;
  ConstPtr<Dtd> dtd_;
};

class IgnoredMarkupEvent : public MarkupEvent {
public:
  IgnoredMarkupEvent(const Location &, Markup *);
  void handle(EventHandler &);
private:
  IgnoredMarkupEvent(const IgnoredMarkupEvent &);
  void operator=(const IgnoredMarkupEvent &);
};






class EntityDefaultedEvent : public LocatedEvent {
public:
  EntityDefaultedEvent(const ConstPtr<Entity> &,
         const Location &);
  void handle(EventHandler &);
  const Entity &entity() const;
  const ConstPtr<Entity> &entityPointer() const;
private:
  EntityDefaultedEvent(const EntityDefaultedEvent &);
  void operator=(const EntityDefaultedEvent &);
  ConstPtr<Entity> entity_;
};

class SgmlDeclEntityEvent : public LocatedEvent {
public:
  SgmlDeclEntityEvent(const PublicId &publicId,
        PublicId::TextClass entityType,
        const StringC &effectiveSystemId,
        const Location &);
  void handle(EventHandler &);
  const PublicId &publicId() const;
  PublicId::TextClass entityType() const;
  const StringC &effectiveSystemId() const;
private:
  SgmlDeclEntityEvent(const SgmlDeclEntityEvent &);
  void operator=(const SgmlDeclEntityEvent &);
  PublicId publicId_;
  PublicId::TextClass entityType_;
  StringC effectiveSystemId_;
};

class EventHandler {
public:
  virtual ~EventHandler();
  virtual void message(MessageEvent *) = 0;
  virtual void data(DataEvent *);
  virtual void startElement(StartElementEvent *);
  virtual void endElement(EndElementEvent *);
  virtual void pi(PiEvent *);
  virtual void sdataEntity(SdataEntityEvent *);
  virtual void externalDataEntity(ExternalDataEntityEvent *);
  virtual void subdocEntity(SubdocEntityEvent *);
  virtual void nonSgmlChar(NonSgmlCharEvent *);
  virtual void appinfo(AppinfoEvent *);
  virtual void uselink(UselinkEvent *);
  virtual void usemap(UsemapEvent *);
  virtual void startDtd(StartDtdEvent *);
  virtual void endDtd(EndDtdEvent *);
  virtual void startLpd(StartLpdEvent *);
  virtual void endLpd(EndLpdEvent *);
  virtual void endProlog(EndPrologEvent *);
  virtual void sgmlDecl(SgmlDeclEvent *);
  virtual void commentDecl(CommentDeclEvent *);
  virtual void sSep(SSepEvent *);
  virtual void ignoredRs(IgnoredRsEvent *);
  virtual void ignoredRe(IgnoredReEvent *);
  virtual void reOrigin(ReOriginEvent *);
  virtual void ignoredChars(IgnoredCharsEvent *);
  virtual void markedSectionStart(MarkedSectionStartEvent *);
  virtual void markedSectionEnd(MarkedSectionEndEvent *);
  virtual void entityStart(EntityStartEvent *);
  virtual void entityEnd(EntityEndEvent *);
  virtual void notationDecl(NotationDeclEvent *);
  virtual void entityDecl(EntityDeclEvent *);
  virtual void elementDecl(ElementDeclEvent *);
  virtual void attlistDecl(AttlistDeclEvent *);
  virtual void linkAttlistDecl(LinkAttlistDeclEvent *);
  virtual void attlistNotationDecl(AttlistNotationDeclEvent *);
  virtual void linkDecl(LinkDeclEvent *);
  virtual void idLinkDecl(IdLinkDeclEvent *);
  virtual void shortrefDecl(ShortrefDeclEvent *);
  virtual void ignoredMarkup(IgnoredMarkupEvent *);
  virtual void entityDefaulted(EntityDefaultedEvent *);
  virtual void inputClosed(InputSource *in);
  virtual void inputOpened(InputSource *in);
  virtual void sgmlDeclEntity(SgmlDeclEntityEvent *);
};

inline
Event::Event(Type type)
: type_(type)
{
}

inline
Event::Type Event::type() const
{
  return type_;
}

inline
const Location &LocatedEvent::location() const
{
  return location_;
}

inline
const Markup &MarkupEvent::markup() const
{
  return markup_;
}

inline
const Message &MessageEvent::message() const
{
  return message_;
}

inline
const ElementType *StartElementEvent::elementType() const
{
  return elementType_;
}

inline
const StringC &StartElementEvent::name() const
{
  return elementType_->name();
}

inline
void StartElementEvent::setIncluded()
{
  included_ = 1;
}

inline
Boolean StartElementEvent::included() const
{
  return included_;
}

inline
const Markup *StartElementEvent::markupPtr() const
{
  return markup_;
}

inline
const AttributeList &StartElementEvent::attributes() const
{
  return *attributes_;
}

inline
Boolean StartElementEvent::mustOmitEnd() const
{
  return ((elementType()->definition()->declaredContent()
    == ElementDefinition::empty)
   || attributes_->conref());
}

inline
const ElementType *EndElementEvent::elementType() const
{
  return elementType_;
}

inline
const StringC &EndElementEvent::name() const
{
  return elementType_->name();
}

inline
void EndElementEvent::setIncluded()
{
  included_ = 1;
}

inline
Boolean EndElementEvent::included() const
{
  return included_;
}

inline
const Markup *EndElementEvent::markupPtr() const
{
  return markup_;
}

inline
const Char *DataEvent::data() const
{
  return p_;
}

inline
size_t DataEvent::dataLength() const
{
  return length_;
}

inline
const Char *PiEvent::data() const
{
  return data_;
}

inline
size_t PiEvent::dataLength() const
{
  return dataLength_;
}

inline
const ConstPtr<EntityOrigin> &
ExternalEntityEvent::entityOrigin() const
{
  return origin_;
}

inline
const Location &ExternalEntityEvent::location() const
{
  return origin_->parent();
}

inline
const ExternalDataEntity *ExternalDataEntityEvent::entity() const
{
  return dataEntity_;
}

inline
const SubdocEntity *SubdocEntityEvent::entity() const
{
  return subdocEntity_;
}

inline
Char NonSgmlCharEvent::character() const
{
  return c_;
}

inline
Boolean AppinfoEvent::literal(const StringC *&p) const
{
  if (appinfoNone_)
    return 0;
  p = &appinfo_.string();
  return 1;
}

inline
const ConstPtr<Lpd> &UselinkEvent::lpd() const
{
  return lpd_;
}

inline
const LinkSet *UselinkEvent::linkSet() const
{
  return linkSet_;
}

inline
Boolean UselinkEvent::restore() const
{
  return restore_;
}

inline
const ShortReferenceMap *UsemapEvent::map() const
{
  return map_;
}

inline
const StringC &StartSubsetEvent::name() const
{
  return name_;
}

inline
const ConstPtr<Entity> &StartSubsetEvent::entity() const
{
  return entity_;
}

inline
Boolean StartSubsetEvent::hasInternalSubset() const
{
  return hasInternalSubset_;
}

inline
Boolean StartLpdEvent::active() const
{
  return active_;
}

inline
const Dtd &EndDtdEvent::dtd() const
{
  return *dtd_;
}

inline
const ConstPtr<Dtd> &EndDtdEvent::dtdPointer() const
{
  return dtd_;
}

inline
const Lpd &EndLpdEvent::lpd() const
{
  return *lpd_;
}

inline
const ConstPtr<Lpd> &EndLpdEvent::lpdPointer() const
{
  return lpd_;
}

inline
const Dtd &EndPrologEvent::dtd() const
{
  return *dtd_;
}

inline
const ConstPtr<Dtd> &EndPrologEvent::dtdPointer() const
{
  return dtd_;
}

inline
const ConstPtr<ComplexLpd> &EndPrologEvent::lpdPointer() const
{
  return lpd_;
}

inline
const Vector<StringC> &EndPrologEvent::simpleLinkNames() const
{
  return simpleLinkNames_;
}

inline
const Vector<AttributeList> &EndPrologEvent::simpleLinkAttributes() const
{
  return simpleLinkAttributes_;
}

inline
const Sd &SgmlDeclEvent::sd() const
{
  return *sd_;
}

inline
const ConstPtr<Sd> &SgmlDeclEvent::sdPointer() const
{
  return sd_;
}

inline
const ConstPtr<Sd> &SgmlDeclEvent::refSdPointer() const
{
  return refSd_;
}

inline
const Syntax &SgmlDeclEvent::prologSyntax() const
{
  return *prologSyntax_;
}

inline
const ConstPtr<Syntax> &SgmlDeclEvent::prologSyntaxPointer() const
{
  return prologSyntax_;
}

inline
const Syntax &SgmlDeclEvent::instanceSyntax() const
{
  return *instanceSyntax_;
}

inline
const ConstPtr<Syntax> &SgmlDeclEvent::instanceSyntaxPointer() const
{
  return instanceSyntax_;
}

inline
const ConstPtr<Syntax> &SgmlDeclEvent::refSyntaxPointer() const
{
  return refSyntax_;
}

inline
const StringC &SgmlDeclEvent::implySystemId() const
{
  return implySystemId_;
}

inline
Char IgnoredRsEvent::rs() const
{
  return c_;
}

inline
Char IgnoredReEvent::re() const
{
  return c_;
}

inline
unsigned long IgnoredReEvent::serial() const
{
  return serial_;
}

inline
Char ReOriginEvent::re() const
{
  return c_;
}

inline
unsigned long ReOriginEvent::serial() const
{
  return serial_;
}

inline
MarkedSectionEvent::Status MarkedSectionEvent::status() const
{
  return status_;
}

inline
const Entity *EntityStartEvent::entity() const
{
  return origin_->entity();
}

inline
const ConstPtr<EntityOrigin> &
EntityStartEvent::entityOrigin() const
{
  return origin_;
}

inline
const ConstPtr<Entity> &EntityDeclEvent::entityPointer() const
{
  return entity_;
}

inline
const Entity &EntityDeclEvent::entity() const
{
  return *entity_;
}

inline
Boolean EntityDeclEvent::ignored() const
{
  return ignored_;
}

inline
const Notation &NotationDeclEvent::notation() const
{
  return *notation_;
}

inline
const ConstPtr<Notation> &NotationDeclEvent::notationPointer() const
{
  return notation_;
}

inline
const Vector<const ElementType *> &ElementDeclEvent::elements() const
{
  return elements_;
}

inline
const Vector<const ElementType *> &AttlistDeclEvent::elements() const
{
  return elements_;
}

inline
const Vector<const ElementType *> &LinkAttlistDeclEvent::elements() const
{
  return elements_;
}

inline
const Lpd &LinkAttlistDeclEvent::lpd() const
{
  return *lpd_;
}

inline
const LinkSet *LinkDeclEvent::linkSet() const
{
  return linkSet_;
}

inline
const ComplexLpd &LinkDeclEvent::lpd() const
{
  return *lpd_;
}

inline
const ComplexLpd &IdLinkDeclEvent::lpd() const
{
  return *lpd_;
}

inline
const Vector<ConstPtr<Notation> > &
AttlistNotationDeclEvent::notations() const
{
  return notations_;
}

inline
const ShortReferenceMap *ShortrefDeclEvent::map() const
{
  return map_;
}

inline
const Entity &EntityDefaultedEvent::entity() const
{
  return *entity_;
}

inline
const ConstPtr<Entity> &EntityDefaultedEvent::entityPointer()
     const
{
  return entity_;
}

inline
const PublicId &SgmlDeclEntityEvent::publicId() const
{
  return publicId_;
}

inline
PublicId::TextClass SgmlDeclEntityEvent::entityType() const
{
  return entityType_;
}

inline
const StringC &SgmlDeclEntityEvent::effectiveSystemId() const
{
  return effectiveSystemId_;
}


}
# 13 "GroveBuilder.cxx" 2
# 1 "GroveBuilder.h" 1
# 21 "GroveBuilder.h"
namespace OpenSP {


class Messenger;
class ErrorCountEventHandler;
class MessageFormatter;

class GroveBuilder {
public:
  static bool setBlocking(bool);
  static ErrorCountEventHandler *make(unsigned index,
          Messenger *,
          MessageFormatter *,
          bool validateOnly,
          OpenJade_Grove:: NodePtr &root);
  static ErrorCountEventHandler *make(unsigned index,
          Messenger *,
          MessageFormatter *,
          bool validateOnly,
          const ConstPtr<Sd> &sd,
          const ConstPtr<Syntax> &prologSyntax,
          const ConstPtr<Syntax> &instanceSyntax,
          OpenJade_Grove:: NodePtr &root);
private:
  GroveBuilder();
};


}
# 14 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/ErrorCountEventHandler.h" 1 3 4







#pragma interface


# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4
extern "C" {

# 1 "/usr/include/bits/sigset.h" 1 3 4
# 103 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 117 "/usr/include/bits/sigset.h" 3 4
extern __inline int __sigismember (__const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }
# 34 "/usr/include/signal.h" 2 3 4







typedef __sig_atomic_t sig_atomic_t;

# 58 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/signum.h" 1 3 4
# 59 "/usr/include/signal.h" 2 3 4
# 73 "/usr/include/signal.h" 3 4
typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     throw ();

extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     throw ();







extern __sighandler_t signal (int __sig, __sighandler_t __handler) throw ();
# 102 "/usr/include/signal.h" 3 4





extern __sighandler_t bsd_signal (int __sig, __sighandler_t __handler) throw ();






extern int kill (__pid_t __pid, int __sig) throw ();






extern int killpg (__pid_t __pgrp, int __sig) throw ();




extern int raise (int __sig) throw ();




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler) throw ();
extern int gsignal (int __sig) throw ();




extern void psignal (int __sig, __const char *__s);
# 149 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);




extern int sigpause (int __mask) throw ();
# 177 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) throw ();


extern int sigsetmask (int __mask) throw ();


extern int siggetmask (void) throw ();
# 192 "/usr/include/signal.h" 3 4
typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;







# 1 "/usr/include/time.h" 1 3 4
# 206 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3 4
typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
 int _pad[((128 / sizeof (int)) - 3)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
      } _sifields;
  } siginfo_t;
# 129 "/usr/include/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 273 "/usr/include/bits/siginfo.h" 3 4
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 3)];



 __pid_t _tid;

 struct
   {
     void (*_function) (sigval_t);
     void *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};
# 209 "/usr/include/signal.h" 2 3 4



extern int sigemptyset (sigset_t *__set) throw ();


extern int sigfillset (sigset_t *__set) throw ();


extern int sigaddset (sigset_t *__set, int __signo) throw ();


extern int sigdelset (sigset_t *__set, int __signo) throw ();


extern int sigismember (__const sigset_t *__set, int __signo) throw ();



extern int sigisemptyset (__const sigset_t *__set) throw ();


extern int sigandset (sigset_t *__set, __const sigset_t *__left,
        __const sigset_t *__right) throw ();


extern int sigorset (sigset_t *__set, __const sigset_t *__left,
       __const sigset_t *__right) throw ();




# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 25 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 242 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) throw ();






extern int sigsuspend (__const sigset_t *__set);


extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) throw ();


extern int sigpending (sigset_t *__set) throw ();






extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig);






extern int sigwaitinfo (__const sigset_t *__restrict __set,
   siginfo_t *__restrict __info);






extern int sigtimedwait (__const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    __const struct timespec *__restrict __timeout);



extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     throw ();
# 297 "/usr/include/signal.h" 3 4
extern __const char *__const _sys_siglist[65];
extern __const char *__const sys_siglist[65];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };
# 321 "/usr/include/signal.h" 3 4
extern int sigvec (int __sig, __const struct sigvec *__vec,
     struct sigvec *__ovec) throw ();



# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 28 "/usr/include/bits/sigcontext.h" 3 4
# 1 "/usr/include/asm/sigcontext.h" 1 3 4



# 1 "/usr/include/linux/compiler.h" 1 3 4
# 5 "/usr/include/asm/sigcontext.h" 2 3 4
# 20 "/usr/include/asm/sigcontext.h" 3 4
struct _fpreg {
 unsigned short significand[4];
 unsigned short exponent;
};

struct _fpxreg {
 unsigned short significand[4];
 unsigned short exponent;
 unsigned short padding[3];
};

struct _xmmreg {
 unsigned long element[4];
};

struct _fpstate {

 unsigned long cw;
 unsigned long sw;
 unsigned long tag;
 unsigned long ipoff;
 unsigned long cssel;
 unsigned long dataoff;
 unsigned long datasel;
 struct _fpreg _st[8];
 unsigned short status;
 unsigned short magic;


 unsigned long _fxsr_env[6];
 unsigned long mxcsr;
 unsigned long reserved;
 struct _fpxreg _fxsr_st[8];
 struct _xmmreg _xmm[8];
 unsigned long padding[56];
};



struct sigcontext {
 unsigned short gs, __gsh;
 unsigned short fs, __fsh;
 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned long edi;
 unsigned long esi;
 unsigned long ebp;
 unsigned long esp;
 unsigned long ebx;
 unsigned long edx;
 unsigned long ecx;
 unsigned long eax;
 unsigned long trapno;
 unsigned long err;
 unsigned long eip;
 unsigned short cs, __csh;
 unsigned long eflags;
 unsigned long esp_at_signal;
 unsigned short ss, __ssh;
 struct _fpstate * fpstate;
 unsigned long oldmask;
 unsigned long cr2;
};
# 29 "/usr/include/bits/sigcontext.h" 2 3 4
# 327 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp) throw ();
# 339 "/usr/include/signal.h" 3 4
extern int siginterrupt (int __sig, int __interrupt) throw ();

# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 26 "/usr/include/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 50 "/usr/include/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 342 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/sys/ucontext.h" 1 3 4
# 23 "/usr/include/sys/ucontext.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 24 "/usr/include/sys/ucontext.h" 2 3 4



# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 28 "/usr/include/sys/ucontext.h" 2 3 4



typedef int greg_t;





typedef greg_t gregset_t[19];



enum
{
  REG_GS = 0,

  REG_FS,

  REG_ES,

  REG_DS,

  REG_EDI,

  REG_ESI,

  REG_EBP,

  REG_ESP,

  REG_EBX,

  REG_EDX,

  REG_ECX,

  REG_EAX,

  REG_TRAPNO,

  REG_ERR,

  REG_EIP,

  REG_CS,

  REG_EFL,

  REG_UESP,

  REG_SS

};



struct _libc_fpreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
};

struct _libc_fpstate
{
  unsigned long int cw;
  unsigned long int sw;
  unsigned long int tag;
  unsigned long int ipoff;
  unsigned long int cssel;
  unsigned long int dataoff;
  unsigned long int datasel;
  struct _libc_fpreg _st[8];
  unsigned long int status;
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;


    fpregset_t fpregs;
    unsigned long int oldmask;
    unsigned long int cr2;
  } mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
# 345 "/usr/include/signal.h" 2 3 4





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss) throw ();



extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) throw ();







extern int sighold (int __sig) throw ();


extern int sigrelse (int __sig) throw ();


extern int sigignore (int __sig) throw ();


extern __sighandler_t sigset (int __sig, __sighandler_t __disp) throw ();





# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 379 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       __const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)throw ();


extern int pthread_kill (pthread_t __threadid, int __signo) throw ();
# 380 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) throw ();

extern int __libc_current_sigrtmax (void) throw ();



}
# 12 "/usr/include/OpenSP/ErrorCountEventHandler.h" 2 3 4
# 1 "/usr/include/OpenSP/Event.h" 1 3 4
# 13 "/usr/include/OpenSP/ErrorCountEventHandler.h" 2 3 4


namespace OpenSP {


class ErrorCountEventHandler : public EventHandler {
public:
  ErrorCountEventHandler(unsigned errorLimit = 0);
  void setErrorLimit(unsigned maxErrors);
  const sig_atomic_t *cancelPtr() const;
  void cancel();
  Boolean cancelled() const;
  unsigned errorCount() const;
  void message(MessageEvent *);
  void noteMessage(const Message &);
private:
  unsigned maxErrors_;
  unsigned errorCount_;
  sig_atomic_t cancel_;
};

inline
unsigned ErrorCountEventHandler::errorCount() const
{
  return errorCount_;
}

inline
const sig_atomic_t *ErrorCountEventHandler::cancelPtr() const
{
  return &cancel_;
}

inline
void ErrorCountEventHandler::cancel()
{
  cancel_ = 1;
}

inline
void ErrorCountEventHandler::setErrorLimit(unsigned maxErrors)
{
  maxErrors_ = maxErrors;
}

inline
Boolean ErrorCountEventHandler::cancelled() const
{
  return cancel_ != 0;
}


}
# 15 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/OutputCharStream.h" 1 3 4







# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 9 "/usr/include/OpenSP/OutputCharStream.h" 2 3 4


# 1 "/usr/include/OpenSP/Owner.h" 1 3 4
# 12 "/usr/include/OpenSP/OutputCharStream.h" 2 3 4
# 1 "/usr/include/OpenSP/CodingSystem.h" 1 3 4







#pragma interface





# 1 "/usr/include/OpenSP/OutputByteStream.h" 1 3 4







# 1 "/usr/include/OpenSP/StringOf.h" 1 3 4
# 9 "/usr/include/OpenSP/OutputByteStream.h" 2 3 4



namespace OpenSP {


class OutputByteStream : public Link {
public:
  OutputByteStream();
  virtual ~OutputByteStream();
  virtual void flush() = 0;
  void sputc(char c);
  void sputn(const char *, size_t);
  OutputByteStream &operator<<(char);
  OutputByteStream &operator<<(unsigned char);
  OutputByteStream &operator<<(const char *);
  OutputByteStream &operator<<(int);
  OutputByteStream &operator<<(unsigned);
  OutputByteStream &operator<<(long);
  OutputByteStream &operator<<(unsigned long);
  OutputByteStream &operator<<(const String<char> &);
  char *getBufferPtr() const;
  size_t getBufferSize() const;
  void usedBuffer(size_t);
  virtual void flushBuf(char) = 0;
protected:
  char *ptr_;
  char *end_;
};

inline
char *OutputByteStream::getBufferPtr() const
{
  return ptr_;
}

inline
size_t OutputByteStream::getBufferSize() const
{
  return end_ - ptr_;
}

inline
void OutputByteStream::usedBuffer(size_t n)
{
  ptr_ += n;
}

inline
void OutputByteStream::sputc(char c)
{
  if (ptr_ < end_)
    *ptr_++ = c;
  else
    flushBuf(c);
}

inline
OutputByteStream &OutputByteStream::operator<<(char c)
{
  sputc(c);
  return *this;
}

inline
OutputByteStream &OutputByteStream::operator<<(unsigned char c)
{
  sputc(char(c));
  return *this;
}

inline
OutputByteStream &OutputByteStream::operator<<(int n)
{
  return *this << long(n);
}

inline
OutputByteStream &OutputByteStream::operator<<(unsigned n)
{
  return *this << (unsigned long)n;
}

inline
OutputByteStream &OutputByteStream::operator<<(const String<char> &s)
{
  sputn(s.data(), s.size());
  return *this;
}

class StrOutputByteStream : public OutputByteStream {
public:
  StrOutputByteStream();
  virtual ~StrOutputByteStream() { };
  void extractString(String<char> &);
protected:
  StrOutputByteStream(const StrOutputByteStream &);
  void operator=(const StrOutputByteStream &);
  void flush();
  void flushBuf(char);
  String<char> buf_;
};

class FileOutputByteStream : public OutputByteStream {
public:
  FileOutputByteStream();
  FileOutputByteStream(int fd, Boolean closeFd = 1);
  virtual ~FileOutputByteStream();



  Boolean open(const char *);

  Boolean attach(int fd, Boolean closeFd = 1);
  Boolean close();
private:
  FileOutputByteStream(const FileOutputByteStream &);
  void operator=(const FileOutputByteStream &);
  void flush();
  void flushBuf(char);
  String<char> buf_;
  int fd_;
  Boolean closeFd_;
};


}
# 15 "/usr/include/OpenSP/CodingSystem.h" 2 3 4

# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 17 "/usr/include/OpenSP/CodingSystem.h" 2 3 4



namespace OpenSP {


class Decoder {
public:
  Decoder(unsigned minBytesPerChar = 1);
  virtual ~Decoder();
  virtual size_t decode(Char *, const char *, size_t, const char **) = 0;
  virtual Boolean convertOffset(unsigned long &offset) const;


  unsigned minBytesPerChar() const;
protected:
  unsigned minBytesPerChar_;
};


class Encoder {
public:
  class Handler {
  public:
    virtual void handleUnencodable(Char, OutputByteStream *) = 0;
  };
  Encoder();
  virtual ~Encoder();
  virtual void output(const Char *, size_t, OutputByteStream *) = 0;

  virtual void startFile(OutputByteStream *);
  virtual void output(Char *, size_t, OutputByteStream *);
  virtual void setUnencodableHandler(Handler *);
  virtual void handleUnencodable(Char, OutputByteStream *);
};

class RecoveringEncoder : public Encoder {
public:
  RecoveringEncoder();
  void setUnencodableHandler(Handler *);
  void handleUnencodable(Char, OutputByteStream *);
private:
  Handler *unencodableHandler_;
};

class InputCodingSystem {
public:
  virtual ~InputCodingSystem();

  virtual Decoder *makeDecoder() const { return makeDecoder(1); }
  virtual Decoder *makeDecoder(Boolean lsbFirst) const { return makeDecoder(lsbFirst,1); }
  virtual Decoder *makeDecoder(Boolean lsbFirst, Boolean lswFirst) const { return makeDecoder(); }
  StringC convertIn(const char *) const;
  virtual Boolean isIdentity() const;
};

class OutputCodingSystem {
public:
  virtual ~OutputCodingSystem();
  virtual Encoder *makeEncoder() const = 0;
  virtual unsigned fixedBytesPerChar() const;
  String<char> convertOut(const StringC &) const;
};

class CodingSystem : public InputCodingSystem, public OutputCodingSystem {
};

inline
unsigned Decoder::minBytesPerChar() const
{
  return minBytesPerChar_;
}


}
# 13 "/usr/include/OpenSP/OutputCharStream.h" 2 3 4



namespace OpenSP {


class OutputCharStream : public Link {
public:
  enum Newline { newline };
  typedef void (*Escaper)(OutputCharStream &, Char);
  OutputCharStream();
  virtual ~OutputCharStream();
  OutputCharStream &put(Char);
  OutputCharStream &write(const Char *, size_t);
  virtual void flush() = 0;
  virtual void setEscaper(Escaper);

  OutputCharStream &operator<<(char);
  OutputCharStream &operator<<(const char *);
  OutputCharStream &operator<<(const StringC &);
  OutputCharStream &operator<<(unsigned long);
  OutputCharStream &operator<<(int);
  OutputCharStream &operator<<(Newline);
private:
  OutputCharStream(const OutputCharStream &);
  void operator=(const OutputCharStream &);

  virtual void flushBuf(Char) = 0;
protected:
  Char *ptr_;
  Char *end_;
};

class EncodeOutputCharStream : public OutputCharStream,
                            private Encoder::Handler {
public:
  EncodeOutputCharStream();

  EncodeOutputCharStream(OutputByteStream *, const OutputCodingSystem *);
  ~EncodeOutputCharStream();
  void open(OutputByteStream *, const OutputCodingSystem *);
  void flush();
  void setEscaper(Escaper);
private:
  EncodeOutputCharStream(const EncodeOutputCharStream &);
  void operator=(const EncodeOutputCharStream &);
  EncodeOutputCharStream(OutputByteStream *, Encoder *);
  void allocBuf(int bytesPerChar);
  void flushBuf(Char);
  void handleUnencodable(Char c, OutputByteStream *);
  Char *buf_;
  OutputByteStream *byteStream_;
  Encoder *encoder_;
  Owner<Encoder> ownedEncoder_;
  Escaper escaper_;
};

class StrOutputCharStream : public OutputCharStream {
public:
  StrOutputCharStream();
  ~StrOutputCharStream();
  void extractString(StringC &);
  void flush();
private:
  void flushBuf(Char);
  void sync(size_t);
  StrOutputCharStream(const StrOutputCharStream &);
  void operator=(const StrOutputCharStream &);
  Char *buf_;
  size_t bufSize_;
};

class RecordOutputCharStream : public OutputCharStream {
public:
  RecordOutputCharStream(OutputCharStream *);
  ~RecordOutputCharStream();
  void flush();
  void setEscaper(Escaper);
private:
  RecordOutputCharStream(const RecordOutputCharStream &);
  void operator=(const RecordOutputCharStream &);
  void flushBuf(Char);
  void outputBuf();

  OutputCharStream *os_;
  enum { bufSize_ = 1024 };
  Char buf_[bufSize_];
};

inline
OutputCharStream &OutputCharStream::put(Char c)
{
  if (ptr_ < end_)
    *ptr_++ = c;
  else
    flushBuf(c);
  return *this;
}

inline
OutputCharStream &OutputCharStream::operator<<(char c)
{
  return put(Char(c));
}

inline
OutputCharStream &OutputCharStream::operator<<(Newline)
{
  put(Char('\n'));



  return *this;
}

inline
OutputCharStream &OutputCharStream::operator<<(const StringC &str)
{
  return write(str.data(), str.size());
}


}
# 16 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/MessageFormatter.h" 1 3 4







#pragma interface



# 1 "/usr/include/OpenSP/MessageBuilder.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 8 "/usr/include/OpenSP/MessageBuilder.h" 2 3 4



namespace OpenSP {


class OtherMessageArg;
class MessageFragment;

class MessageBuilder {
public:
  virtual void appendNumber(unsigned long) = 0;
  virtual void appendOrdinal(unsigned long) = 0;
  virtual void appendChars(const Char *, size_t) = 0;
  virtual void appendOther(const OtherMessageArg *) = 0;
  virtual void appendFragment(const MessageFragment &) = 0;
};


}
# 13 "/usr/include/OpenSP/MessageFormatter.h" 2 3 4




# 1 "/usr/include/OpenSP/OutputCharStream.h" 1 3 4
# 18 "/usr/include/OpenSP/MessageFormatter.h" 2 3 4


namespace OpenSP {


class MessageFormatter {
public:
  MessageFormatter();
  virtual void formatMessage(const MessageFragment &,
       const Vector<CopyOwner<MessageArg> > &args,
       OutputCharStream &, bool noquote = 0);
  virtual void formatOpenElements(const Vector<OpenElementInfo> &openElementInfo,
     OutputCharStream &os);
  virtual Boolean getMessageText(const MessageFragment &, StringC &) = 0;
  virtual Boolean formatFragment(const MessageFragment &, OutputCharStream &);
private:
  MessageFormatter(const MessageFormatter &);
  void operator=(const MessageFormatter &);
protected:
  class Builder : public MessageBuilder {
  public:
    Builder(MessageFormatter *formatter, OutputCharStream &os, bool b)
      : formatter_(formatter), os_(&os), argIsCompleteMessage_(b) { }
    void appendNumber(unsigned long);
    void appendOrdinal(unsigned long);
    void appendChars(const Char *, size_t);
    void appendOther(const OtherMessageArg *);
    void appendFragment(const MessageFragment &);
  private:
    OutputCharStream &os() { return *os_; }
    OutputCharStream *os_;
    MessageFormatter *formatter_;
    bool argIsCompleteMessage_;
  };
};


}
# 17 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Dtd.h" 1 3 4
# 18 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Syntax.h" 1 3 4
# 19 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Attribute.h" 1 3 4
# 20 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/Vector.h" 1 3 4
# 21 "GroveBuilder.cxx" 2
# 1 "../grove/LocNode.h" 1







# 1 "../grove/Node.h" 1
# 9 "../grove/LocNode.h" 2


namespace OpenSP {


class Location;







class LocNode {
public:
  virtual OpenJade_Grove:: AccessResult getLocation(Location &) const = 0;
  static const OpenJade_Grove:: Node::IID iid;
  static const LocNode *convert(const OpenJade_Grove:: NodePtr &nd) {
    const void *p;
    if (nd && nd->queryInterface(iid, p))
      return (const LocNode *)p;
    else
      return 0;
  }
};




}
# 22 "GroveBuilder.cxx" 2
# 1 "SdNode.h" 1
# 9 "SdNode.h"
# 1 "/usr/include/OpenSP/Sd.h" 1 3 4
# 10 "SdNode.h" 2




namespace OpenSP {
# 23 "SdNode.h"
class SdNode {
public:
  virtual OpenJade_Grove:: AccessResult
    getSd(ConstPtr<Sd> &sd,
          ConstPtr<Syntax> &prologSyntax,
  ConstPtr<Syntax> &instanceSyntax) const = 0;
  static const OpenJade_Grove:: Node::IID iid;
  static const SdNode *convert(const OpenJade_Grove:: NodePtr &nd) {
    const void *p;
    if (nd && nd->queryInterface(iid, p))
      return (const SdNode *)p;
    else
      return 0;
  }
};




}
# 23 "GroveBuilder.cxx" 2
# 1 "threads.h" 1
# 472 "threads.h"
class Thread {
public:
  Thread(int (*func)(void *), void *args) : ret_((*func)(args)) { }
  int wait() { return ret_; }
private:
  int ret_;
};

class RefCount {
public:
  RefCount() : count_(0) { }
  void operator++() { ++count_; }
  bool operator--() { return --count_ != 0; }
  operator unsigned long() const { return count_; }
private:
  unsigned long count_;
};

class Mutex {
public:
  class Lock {
  public:
    Lock(Mutex *) { }
  };
  Mutex() { }
};





class Condition {
public:
  Condition() { }
  void pulse() { }
  void set() { }
  bool wait() const { return 0; }
};
# 24 "GroveBuilder.cxx" 2
# 1 "/usr/include/OpenSP/macros.h" 1 3 4
# 35 "/usr/include/OpenSP/macros.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cassert" 1 3 4
# 46 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cassert" 3 4
       
# 47 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cassert" 3

# 1 "/usr/include/assert.h" 1 3 4
# 67 "/usr/include/assert.h" 3 4
extern "C" {


extern void __assert_fail (__const char *__assertion, __const char *__file,
      unsigned int __line, __const char *__function)
     throw () __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, __const char *__file,
      unsigned int __line,
      __const char *__function)
     throw () __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     throw () __attribute__ ((__noreturn__));


}
# 48 "/usr/lib/gcc/i486-linux-gnu/4.0.1/../../../../include/c++/4.0.1/cassert" 2 3
# 36 "/usr/include/OpenSP/macros.h" 2 3 4
# 25 "GroveBuilder.cxx" 2





# 1 "/usr/lib/gcc/i486-linux-gnu/4.0.1/include/stddef.h" 1 3 4
# 31 "GroveBuilder.cxx" 2



namespace OpenSP {



using namespace OpenJade_Grove;


static bool blockingAccess = 1;

size_t initialBlockSize = 8192;
unsigned maxBlocksPerSize = 20;

struct Chunk;
struct ParentChunk;
class ElementChunk;
struct SgmlDocumentChunk;
class DataChunk;
class GroveImpl;
class BaseNode;
class ChunkNode;
class ElementNode;
class DataNode;
class CdataAttributeValueNode;
class AttributeValueTokenNode;
class AttributeAsgnNode;
class AttributeDefNode;
class EntityNode;
class NotationNode;
class ExternalIdNode;
class FormalPublicIdNode;
class DocumentTypeNode;
class SgmlConstantsNode;
class MessageNode;
class ElementTypeNode;
class RankStemNode;
class ModelGroupNode;
class ElementTokenNode;
class PcdataTokenNode;
class DefaultEntityNode;

struct Chunk {


  virtual AccessResult setNodePtrFirst(NodePtr &ptr,
           const BaseNode *) const = 0;
  virtual AccessResult setNodePtrFirst(NodePtr &ptr,
           const ElementNode *node) const;
  virtual AccessResult setNodePtrFirst(NodePtr &ptr,
           const DataNode *node) const;
  virtual const Chunk *after() const = 0;
  virtual AccessResult getFollowing(const GroveImpl *,
                                    const Chunk *&, unsigned long &nNodes)
    const;
  virtual AccessResult getFirstSibling(const GroveImpl *, const Chunk *&) const;
  virtual const StringC *id() const;
  virtual Boolean getLocOrigin(const Origin *&) const;
  ParentChunk *origin;
};

struct LocChunk : public Chunk {
  Index locIndex;
};

struct ParentChunk : public LocChunk {
  ParentChunk() : nextSibling(0) { }
  Chunk *nextSibling;
};

class ElementChunk : public ParentChunk {
public:
  virtual const AttributeValue *
    attributeValue(size_t attIndex, const GroveImpl &grove) const;
  virtual Boolean mustOmitEndTag() const;
  virtual Boolean included() const;
  const AttributeDefinitionList *attDefList() const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const DataNode *node) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const;
  static const StringC &key(const ElementChunk &chunk) { return *chunk.id(); }
  const Chunk *after() const;
  AccessResult getFollowing(const GroveImpl *, const Chunk *&, unsigned long &nNodes)
    const;
  const ElementType *elementType() const { return type; }
private:
  friend class ElementNode;
  const ElementType *type;
public:
  unsigned long elementIndex;
};

inline
const AttributeDefinitionList *ElementChunk::attDefList() const
{
  return type->attributeDefTemp();
}

class LocOriginChunk : public Chunk {
public:
  LocOriginChunk(const Origin *lo) : locOrigin(lo) { }
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const DataNode *node) const;
  const Chunk *after() const;
  AccessResult getFollowing(const GroveImpl *,
                            const Chunk *&, unsigned long &nNodes)
    const;
  Boolean getLocOrigin(const Origin *&) const;
private:
  const Origin *locOrigin;
};

class MessageItem {
public:
  MessageItem(Node::Severity severity, const StringC &text, const Location &loc)
    : severity_(severity), text_(text), loc_(loc), next_(0) { }
  Node::Severity severity() const { return severity_; }
  const Location &loc() const { return loc_; }
  const StringC &text() const { return text_; }
  const MessageItem *next() const { return next_; }
  MessageItem **nextP() { return &next_; }
private:
  Node::Severity severity_;
  StringC text_;
  Location loc_;
  MessageItem *next_;
};



class GroveImpl {
public:
  GroveImpl(unsigned groveIndex);


  void addRef() const { ++(((GroveImpl *)this)->refCount_); }
  void release() const {
    if (!--(((GroveImpl *)this)->refCount_))
      delete (GroveImpl *)this;
  }
  unsigned groveIndex() const { return groveIndex_; }
  const SgmlDocumentChunk *root() const { return root_; }
  const AttributeValue *impliedAttributeValue() const {
    return impliedAttributeValue_.pointer();
  }

  Boolean getAppinfo(const StringC *&) const;
  const SubstTable *generalSubstTable() const {
    return instanceSyntax_.isNull() ? 0 : instanceSyntax_->generalSubstTable();
  }
  const SubstTable *entitySubstTable() const {
    return instanceSyntax_.isNull() ? 0 : instanceSyntax_->entitySubstTable();
  }

  const Dtd *governingDtd() const { return dtd_.pointer(); }
  const Dtd *lookupDtd(const StringC &) const;
  const Dtd *lookupDtd(const ElementType &) const;
  const Dtd *lookupDtd(const RankStem &) const;
  const Dtd *firstDtd() const { return allDtds_.size() == 0 ? 0 : allDtds_.begin()->pointer(); }
  const Dtd *nextDtd(const Dtd *) const;

  Dtd::ConstEntityIter defaultedEntityIter() const;
  const Entity *lookupDefaultedEntity(const StringC &) const;
  const ElementChunk *lookupElement(const StringC &) const;
  typedef PointerTableIter<ElementChunk *,StringC,Hash,ElementChunk> ElementIter;

  ElementIter elementIter() const;
  Boolean complete() const { return complete_; }
  const void *completeLimit() const { return completeLimit_; }
  const void *completeLimitWithLocChunkAfter() const {
    return completeLimitWithLocChunkAfter_;
  }
  const Origin *currentLocOrigin() const { return currentLocOrigin_; }
  Boolean hasDefaultEntity() const { return hasDefaultEntity_; }
  Boolean maybeMoreSiblings(const ParentChunk *chunk) const;

  Boolean waitForMoreNodes() const;
  AccessResult proxifyLocation(const Location &, Location &) const;
  const MessageItem *messageList() const { return messageList_; }

  void getSd(ConstPtr<Sd> &, ConstPtr<Syntax> &, ConstPtr<Syntax> &) const;

  void *allocChunk(size_t);
  void appendSibling(Chunk *);
  void appendSibling(DataChunk *);
  Boolean tryExtend(size_t n) {
    if (n <= nFree_) {
      nFree_ -= n;
      freePtr_ += n;
      return 1;
    }
    else
      return 0;
  }
  DataChunk *pendingData() { return pendingData_; }
  void push(ElementChunk *, Boolean hasId);
  void pop();
  void setAppinfo(const StringC &);
  void setGoverningDtd(const ConstPtr<Dtd> &dtd);
  void addDtd(const ConstPtr<Dtd> &dtd);
  void setSd(const ConstPtr<Sd> &, const ConstPtr<Syntax> &, const ConstPtr<Syntax> &);
  void storeAttributeValue(const ConstPtr<AttributeValue> &value) {
    values_.push_back(value);
  }
  void addDefaultedEntity(const ConstPtr<Entity> &);
  void setComplete();
  Boolean haveRootOrigin();
  void setLocOrigin(const ConstPtr<Origin> &);
  void appendMessage(MessageItem *);
private:
  GroveImpl(const GroveImpl &);
  void operator=(const GroveImpl &);
  ~GroveImpl();

  Boolean maybeMoreSiblings1(const ParentChunk *) const;
  void *allocFinish(size_t);
  void pulse();
  void maybePulse();
  void finishDocumentElement();
  void finishProlog();
  void addBarrier();
  void storeLocOrigin(const ConstPtr<Origin> &);

  struct BlockHeader {
    BlockHeader() : next(0) { }
    BlockHeader *next;
  };
  unsigned groveIndex_;
  SgmlDocumentChunk *root_;
  ParentChunk *origin_;
  DataChunk *pendingData_;
  Chunk **tailPtr_;
  ConstPtr<Dtd> dtd_;
  Vector<ConstPtr<Dtd> > allDtds_;
  ConstPtr<Sd> sd_;
  ConstPtr<Syntax> prologSyntax_;
  ConstPtr<Syntax> instanceSyntax_;
  ConstPtr<AttributeValue> impliedAttributeValue_;
  Vector<ConstPtr<AttributeValue> > values_;
  Vector<ConstPtr<Origin> > origins_;
  NamedResourceTable<Entity> defaultedEntityTable_;
  PointerTable<ElementChunk *,StringC,Hash,ElementChunk> idTable_;
  Boolean hasDefaultEntity_;
  Boolean haveAppinfo_;
  StringC appinfo_;
  const Origin *currentLocOrigin_;

  Boolean complete_;
  const void *completeLimit_;
  const void *completeLimitWithLocChunkAfter_;

  char *freePtr_;


  size_t nFree_;

  BlockHeader *blocks_;

  BlockHeader **blockTailPtr_;

  size_t blockAllocSize_;

  size_t nBlocksThisSizeAlloced_;
  RefCount refCount_;
  Condition moreNodesCondition_;
  Mutex mutex_;
  Mutex *mutexPtr_;
  unsigned pulseStep_;
  unsigned long nEvents_;
  unsigned long nElements_;
  enum { maxChunksWithoutLocOrigin = 100 };
  unsigned nChunksSinceLocOrigin_;
  MessageItem *messageList_;
  MessageItem **messageListTailP_;
};

class GroveImplPtr {
public:
  GroveImplPtr(const GroveImpl *grove) : grove_(grove) { grove_->addRef(); }
  ~GroveImplPtr() { grove_->release(); }
  const GroveImpl *operator->() const { return grove_; }
  operator const GroveImpl *() const { return grove_; }
private:
  GroveImplPtr(const GroveImplPtr &);
  void operator=(const GroveImplPtr &);
  const GroveImpl *grove_;
};

class GroveImplProxyOrigin : public ProxyOrigin {
public:
  GroveImplProxyOrigin(const GroveImpl *grove, const Origin *origin)
    : grove_(grove), ProxyOrigin(origin) { }
private:
  GroveImplPtr grove_;
};

class GroveBuilderMessageEventHandler : public ErrorCountEventHandler {
public:
  GroveBuilderMessageEventHandler(unsigned groveIndex, Messenger *mgr, MessageFormatter *msgFmt_);
  ~GroveBuilderMessageEventHandler();
  void message(MessageEvent *);
  void sgmlDecl(SgmlDeclEvent *);
  void makeInitialRoot(NodePtr &);
  void setSd(const ConstPtr<Sd> &, const ConstPtr<Syntax> &, const ConstPtr<Syntax> &);
protected:
  GroveImpl *grove_;
private:
  Messenger *mgr_;
  MessageFormatter *msgFmt_;
};

class GroveBuilderEventHandler : public GroveBuilderMessageEventHandler {
public:
  GroveBuilderEventHandler(unsigned groveIndex, Messenger *mgr, MessageFormatter *msgFmt_);
  void appinfo(AppinfoEvent *);
  void startElement(StartElementEvent *);
  void endElement(EndElementEvent *);
  void data(DataEvent *);
  void sdataEntity(SdataEntityEvent *);
  void nonSgmlChar(NonSgmlCharEvent *);
  void externalDataEntity(ExternalDataEntityEvent *);
  void subdocEntity(SubdocEntityEvent *);
  void pi(PiEvent *);
  void endProlog(EndPrologEvent *);
  void endDtd(EndDtdEvent *);
  void entityDefaulted(EntityDefaultedEvent *);
};

inline
void setString(GroveString &to, const StringC &from)
{
  to.assign(from.data(), from.size());
}

inline
bool operator==(const StringC &str1, const GroveString &str2)
{
  return (str1.size() == str2.size()
          && memcmp(str1.data(), str2.data(), str1.size()*sizeof(Char)) == 0);
}

inline
bool operator!=(const StringC &str1, const GroveString &str2)
{
  return !(str1 == str2);
}

inline
size_t roundUp(size_t n)
{
  return (n + (sizeof(void *) - 1)) & ~(sizeof(void *) - 1);
}



class BaseNode : public Node, public LocNode {
public:
  BaseNode(const GroveImpl *grove);
  virtual ~BaseNode();
  void addRef();
  void release();
  bool canReuse(NodePtr &ptr) const;
  unsigned groveIndex() const;
  bool operator==(const Node &node) const;

  virtual bool same(const BaseNode &) const = 0;

  virtual bool same2(const ChunkNode *) const;
  virtual bool same2(const DataNode *) const;
  virtual bool same2(const AttributeAsgnNode *) const;
  virtual bool same2(const AttributeValueTokenNode *) const;
  virtual bool same2(const CdataAttributeValueNode *) const;
  virtual bool same2(const EntityNode *) const;
  virtual bool same2(const NotationNode *) const;
  virtual bool same2(const ExternalIdNode *) const;
  virtual bool same2(const FormalPublicIdNode *) const;
  virtual bool same2(const DocumentTypeNode *) const;
  virtual bool same2(const SgmlConstantsNode *) const;
  virtual bool same2(const MessageNode *) const;
  virtual bool same2(const ElementTypeNode *) const;
  virtual bool same2(const RankStemNode *) const;
  virtual bool same2(const ModelGroupNode *) const;
  virtual bool same2(const ElementTokenNode *) const;
  virtual bool same2(const PcdataTokenNode *) const;
  virtual bool same2(const AttributeDefNode *) const;
  virtual bool same2(const DefaultEntityNode *) const;
  const GroveImpl *grove() const { return grove_; }
  AccessResult nextSibling(NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult follow(NodeListPtr &ptr) const;
  AccessResult children(NodeListPtr &) const;
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getGroveRoot(NodePtr &ptr) const;
  AccessResult getLocation(Location &) const;
  bool queryInterface(IID, const void *&) const;
  bool chunkContains(const Node &) const;
  bool inChunk(const DataNode *node) const;
  bool inChunk(const CdataAttributeValueNode *) const;
protected:
  static unsigned long secondHash(unsigned long n) {
    return n * 1001;
  }
private:
  unsigned refCount_;
  GroveImplPtr grove_;
};

inline
BaseNode::BaseNode(const GroveImpl *grove)
: grove_(grove), refCount_(0)
{
}

inline
bool BaseNode::canReuse(NodePtr &ptr) const
{
  const Node *tem = &*ptr;
  return tem == this && refCount_ == 1;
}

struct ForwardingChunk : Chunk {
  ForwardingChunk(const Chunk *to, ParentChunk *p)
    : forwardTo(to) { origin = p; }
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
  AccessResult getFollowing(const GroveImpl *,
                            const Chunk *&, unsigned long &nNodes)
    const;
  const Chunk *after() const { return forwardTo; }
  const Chunk *forwardTo;
};

class ChunkNode : public BaseNode {
public:
  ChunkNode(const GroveImpl *grove, const LocChunk *chunk);
  const LocChunk *chunk() const { return chunk_; }
  bool same(const BaseNode &node) const;
  bool same2(const ChunkNode *node) const;
  unsigned long hash() const;
  AccessResult getParent(NodePtr &ptr) const;
  AccessResult getTreeRoot(NodePtr &ptr) const;
  AccessResult getOrigin(NodePtr &) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &) const;
  AccessResult nextChunkSibling(NodePtr &) const;
  AccessResult nextChunkAfter(NodePtr &) const;
  AccessResult firstSibling(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  AccessResult followSiblingRef(unsigned long, NodePtr &) const;
  AccessResult getLocation(Location &) const;
protected:
  const LocChunk *chunk_;
};

inline
ChunkNode::ChunkNode(const GroveImpl *grove, const LocChunk *chunk)
: BaseNode(grove), chunk_(chunk)
{
}

class SgmlDocumentNode;

struct SgmlDocumentChunk : public ParentChunk {
  SgmlDocumentChunk() : prolog(0), documentElement(0), epilog(0) { }
  Chunk *prolog;
  Chunk *documentElement;
  Chunk *epilog;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
  const Chunk *after() const { return this + 1; }
};

class SgmlDocumentNode : public ChunkNode, public SdNode {
public:
  SgmlDocumentNode(const GroveImpl *grove,
     const SgmlDocumentChunk *chunk);
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const { return ClassDef::sgmlDocument; }
  AccessResult getDocumentElement(NodePtr &ptr) const;
  AccessResult getElements(NamedNodeListPtr &ptr) const;
  AccessResult getEntities(NamedNodeListPtr &ptr) const;
  AccessResult getDefaultedEntities(NamedNodeListPtr &ptr) const;
  AccessResult getGoverningDoctype(NodePtr &ptr) const;
  AccessResult getDoctypesAndLinktypes(NamedNodeListPtr &ptr) const;
  AccessResult getProlog(NodeListPtr &ptr) const;
  AccessResult getEpilog(NodeListPtr &ptr) const;
  AccessResult getSgmlConstants(NodePtr &) const;
  AccessResult getApplicationInfo(GroveString &str) const;
  AccessResult getMessages(NodeListPtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &) const { return accessNotInClass; }
  AccessResult firstSibling(NodePtr &) const { return accessNotInClass; }
  AccessResult siblingsIndex(unsigned long &) const { return accessNotInClass; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &) const { return accessNull; }
  AccessResult getSd(ConstPtr<Sd> &sd,
       ConstPtr<Syntax> &prologSyntax,
       ConstPtr<Syntax> &instanceSyntax) const;
private:
  const SgmlDocumentChunk *chunk() const {
    return (const SgmlDocumentChunk *)ChunkNode::chunk();
  }
};

inline
SgmlDocumentNode::SgmlDocumentNode(const GroveImpl *grove,
       const SgmlDocumentChunk *chunk)
: ChunkNode(grove, chunk)
{
}



class AttElementChunk : private ElementChunk {
protected:
  AttElementChunk(size_t n) : nAtts(n) { }
  friend class ElementNode;
private:
  const AttributeValue *
    attributeValue(size_t attIndex, const GroveImpl &) const;
  Boolean mustOmitEndTag() const;
  const Chunk *after() const;
  const StringC *id() const;
  size_t nAtts;
};

class IncludedElementChunk : public ElementChunk {
  friend class ElementNode;
  Boolean included() const;
};

class IncludedAttElementChunk : public AttElementChunk {
  IncludedAttElementChunk(size_t n) : AttElementChunk(n) { }
  friend class ElementNode;
  Boolean included() const;
};

class ElementNode : public ChunkNode {
public:
  friend class ElementChunk;
  ElementNode(const GroveImpl *grove, const ElementChunk *chunk)
    : ChunkNode(grove, chunk) { }
  AccessResult attributeRef(unsigned long i, NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult nextChunkAfter(NodePtr &) const;
  AccessResult firstChild(NodePtr &ptr) const;
  AccessResult getAttributes(NamedNodeListPtr &ptr) const;
  AccessResult getGi(GroveString &str) const;
  bool hasGi(GroveString) const;
  AccessResult getId(GroveString &str) const;
  AccessResult getContent(NodeListPtr &ptr) const;
  AccessResult getMustOmitEndTag(bool &) const;
  AccessResult getIncluded(bool &) const;
  AccessResult elementIndex(unsigned long &) const;
  AccessResult getElementType(NodePtr &) const;
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const { return ClassDef::element; }
  static void add(GroveImpl &grove, const StartElementEvent &event);
private:
  static
    ElementChunk *makeAttElementChunk(GroveImpl &grove,
          const StartElementEvent &,
          Boolean &hasId);
  const ElementChunk *chunk() const {
    return (const ElementChunk *)ChunkNode::chunk();
  }
  void reuseFor(const ElementChunk *chunk) { chunk_ = chunk; }
};

class CharsChunk : public LocChunk {
public:
  const Chunk *after() const {
    return (const Chunk *)((char *)this + allocSize(size));
  }
  const Char *data() const { return (const Char *)(this + 1); }
  size_t size;
  static size_t allocSize(size_t nChars) {
    return roundUp(sizeof(CharsChunk) + nChars*sizeof(Char));
  }
};


class DataChunk : public CharsChunk {
private:
  friend class DataNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const;
  AccessResult setNodePtrFirst(NodePtr &ptr, const DataNode *node) const;
  AccessResult getFollowing(const GroveImpl *, const Chunk *&, unsigned long &) const;
};

class DataNode : public ChunkNode {
public:
  friend class DataChunk;
  DataNode(const GroveImpl *, const DataChunk *chunk, size_t index);
  bool same(const BaseNode &node) const;
  bool same2(const DataNode *node) const;
  AccessResult nextSibling(NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult nextChunkAfter(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  AccessResult followSiblingRef(unsigned long, NodePtr &) const;
  AccessResult charChunk(const SdataMapper &, GroveString &) const;
  bool chunkContains(const Node &) const;
  bool inChunk(const DataNode *node) const;
  AccessResult getNonSgml(unsigned long &) const;
  AccessResult getLocation(Location &) const;
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const { return ClassDef::dataChar; }
  unsigned long hash() const;
  static void add(GroveImpl &grove, const DataEvent &event);
private:
  const DataChunk *chunk() const {
    return (const DataChunk *)ChunkNode::chunk();
  }
  void reuseFor(const DataChunk *chunk, size_t index);
  size_t index_;
};

inline
DataNode::DataNode(const GroveImpl *grove,
     const DataChunk *chunk, size_t index)
: ChunkNode(grove, chunk), index_(index)
{
}

class PiChunk : private CharsChunk {
  friend class PiNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
};

class PrologPiChunk : public PiChunk {
  AccessResult getFirstSibling(const GroveImpl *, const struct Chunk *&) const;
};

class EpilogPiChunk : public PiChunk {
  AccessResult getFirstSibling(const GroveImpl *, const struct Chunk *&) const;
};

class PiNode : public ChunkNode {
public:
  PiNode(const GroveImpl *grove, const PiChunk *chunk)
    : ChunkNode(grove, chunk) {}
  AccessResult getSystemData(GroveString &) const;
  AccessResult getEntityName(GroveString &) const{ return accessNull; }
  AccessResult getEntity(NodePtr &) const { return accessNull; }
  void accept(NodeVisitor &visitor) { visitor.pi(*this); }
  const ClassDef &classDef() const { return ClassDef::pi; }
  static void add(GroveImpl &grove, const PiEvent &);
private:
  const PiChunk *chunk() const {
    return (const PiChunk *)ChunkNode::chunk();
  }
};

class EntityRefChunk : public LocChunk {
public:
  const Entity *entity;
  const Chunk *after() const { return this + 1; }
};

class EntityRefNode : public ChunkNode {
public:
  EntityRefNode(const GroveImpl *grove, const EntityRefChunk *chunk)
    : ChunkNode(grove, chunk) { }
  AccessResult getEntity(NodePtr &) const;
  AccessResult getEntityName(GroveString &) const;
protected:
  const EntityRefChunk *chunk() const {
    return (const EntityRefChunk *)ChunkNode::chunk();
  }
};

class SdataNode;

class SdataChunk : private EntityRefChunk {
  friend class SdataNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
};

class SdataNode : public EntityRefNode {
public:
  SdataNode(const GroveImpl *grove, const SdataChunk *chunk)
    : EntityRefNode(grove, chunk) { }
  AccessResult charChunk(const SdataMapper &, GroveString &) const;
  AccessResult getSystemData(GroveString &str) const;
  void accept(NodeVisitor &visitor) { visitor.sdata(*this); }
  const ClassDef &classDef() const { return ClassDef::sdata; }
  static void add(GroveImpl &grove, const SdataEntityEvent &event);
private:
  Char c_;
};

class NonSgmlNode;

class NonSgmlChunk : public LocChunk {
public:
  Char c;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
  const Chunk *after() const { return this + 1; }
};

class NonSgmlNode : public ChunkNode {
public:
  NonSgmlNode(const GroveImpl *grove, const NonSgmlChunk *chunk)
    : ChunkNode(grove, chunk) { }
  AccessResult charChunk(const SdataMapper &, GroveString &) const;
  AccessResult getNonSgml(unsigned long &) const;
  void accept(NodeVisitor &visitor) { visitor.nonSgml(*this); }
  const ClassDef &classDef() const { return ClassDef::nonSgml; }
  static void add(GroveImpl &grove, const NonSgmlCharEvent &event);
protected:
  const NonSgmlChunk *chunk() const {
    return (const NonSgmlChunk *)ChunkNode::chunk();
  }
};

class ExternalDataNode;

class ExternalDataChunk : private EntityRefChunk {
  friend class ExternalDataNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
};

class ExternalDataNode : public EntityRefNode {
public:
  ExternalDataNode(const GroveImpl *grove, const ExternalDataChunk *chunk)
    : EntityRefNode(grove, chunk) { }
  void accept(NodeVisitor &visitor) { visitor.externalData(*this); }
  const ClassDef &classDef() const { return ClassDef::externalData; }
  static void add(GroveImpl &grove, const ExternalDataEntityEvent &event);
};

class SubdocChunk : private EntityRefChunk {
  friend class SubdocNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
};

class SubdocNode : public EntityRefNode {
public:
  SubdocNode(const GroveImpl *grove, const SubdocChunk *chunk)
    : EntityRefNode(grove, chunk) { }
  void accept(NodeVisitor &visitor) { visitor.subdocument(*this); }
  const ClassDef &classDef() const { return ClassDef::subdocument; }
  static void add(GroveImpl &grove, const SubdocEntityEvent &event);
};

class PiEntityChunk : private EntityRefChunk {
  friend class PiEntityNode;
  AccessResult setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const;
};

class PiEntityNode : public EntityRefNode {
public:
  PiEntityNode(const GroveImpl *grove, const PiEntityChunk *chunk)
    : EntityRefNode(grove, chunk) { }
  AccessResult getSystemData(GroveString &) const;
  void accept(NodeVisitor &visitor) { visitor.pi(*this); }
  const ClassDef &classDef() const { return ClassDef::pi; }
  static void add(GroveImpl &grove, const Entity *, const Location &);
};

struct AttributeDefOrigin {
  AttributeDefOrigin(size_t attIndex = 0) : attIndex_(attIndex) { }
  virtual const AttributeDefinitionList *attDefList() const = 0;
  virtual Node *makeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex = 0) const = 0;
  virtual Node *makeAttributeValueTokenNode(const GroveImpl *grove,
         const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex) const = 0;
  virtual Node *makeOriginNode(const GroveImpl *grove, size_t attIndex) const = 0;
  virtual AccessResult makeAttributeValueNode(const GroveImpl *grove,
                                              NodePtr &ptr,
                                              const AttributeValue *value) const;
  virtual AccessResult makeAttributeValueNodeList(const GroveImpl *grove,
                                                  NodeListPtr &ptr,
                                                  const AttributeValue *value) const;
  virtual AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                            NodePtr &ptr,
                                            size_t attributeDefIdx) const = 0;
  virtual AccessResult makeAttributeDefList(const GroveImpl *,
                                            NodeListPtr &,
                                            size_t) const {
    return accessNull;
  }
  AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                    NodePtr &ptr,
                                    const StringC &name) const;
  virtual const void *attributeOriginId() const = 0;
  const size_t attIndex() const { return attIndex_; }
protected:
  size_t attIndex_;
};

struct AttributeOrigin : public virtual AttributeDefOrigin {
  virtual const AttributeValue *
    attributeValue(size_t attIndex, const GroveImpl &grove) const = 0;
  virtual AccessResult
    setNodePtrAttributeOrigin(NodePtr &, const BaseNode *) const = 0;
  virtual Node *makeAttributeAsgnNode(const GroveImpl *grove,
          size_t attIndex) const = 0;
};

class ElementAttributeOrigin : public virtual AttributeOrigin {
public:
  ElementAttributeOrigin(const ElementChunk *);
  const AttributeDefinitionList *attDefList() const;
  const AttributeValue *
    attributeValue(size_t attIndex, const GroveImpl &grove) const;
  AccessResult setNodePtrAttributeOrigin(NodePtr &, const BaseNode *) const;
  Node *makeCdataAttributeValueNode(const GroveImpl *grove,
        const AttributeValue *value,
        size_t attIndex,
        const TextIter &iter,
        size_t charIndex) const;
  Node *makeAttributeValueTokenNode(const GroveImpl *grove,
        const TokenizedAttributeValue *value,
        size_t attIndex,
        size_t tokenIndex) const;
  Node *makeAttributeAsgnNode(const GroveImpl *grove,
         size_t attIndex) const;
  virtual Node *makeOriginNode(const GroveImpl *grove, size_t attIndex) const;
  virtual AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                            NodePtr &ptr,
                                            size_t attributeDefIdx) const;
  const void *attributeOriginId() const;
private:
  const ElementChunk *chunk_;
};

class EntityAttributeOrigin : public virtual AttributeOrigin {
public:
  EntityAttributeOrigin(const ExternalDataEntity *);
  const AttributeDefinitionList *attDefList() const;
  const AttributeValue *
    attributeValue(size_t attIndex, const GroveImpl &grove) const;
  AccessResult setNodePtrAttributeOrigin(NodePtr &, const BaseNode *) const;
  Node *makeCdataAttributeValueNode(const GroveImpl *grove,
        const AttributeValue *value,
        size_t attIndex,
        const TextIter &iter,
        size_t charIndex) const;
  Node *makeAttributeValueTokenNode(const GroveImpl *grove,
        const TokenizedAttributeValue *value,
        size_t attIndex,
        size_t tokenIndex) const;
  Node *makeAttributeAsgnNode(const GroveImpl *grove,
         size_t attIndex) const;
  virtual AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                            NodePtr &ptr,
                                            size_t attributeDefIdx) const;
  virtual Node *makeOriginNode(const GroveImpl *grove, size_t attIndex) const;
  const void *attributeOriginId() const;
private:
  const ExternalDataEntity *entity_;
};


class ElementTypeAttributeDefOrigin : public virtual AttributeDefOrigin {
public:
  ElementTypeAttributeDefOrigin(const ElementType *);
  const AttributeDefinitionList *attDefList() const;
  Node *makeCdataAttributeValueNode(const GroveImpl *grove,
        const AttributeValue *value,
        size_t attIndex,
        const TextIter &iter,
        size_t charIndex) const;
  Node *makeAttributeValueTokenNode(const GroveImpl *grove,
        const TokenizedAttributeValue *value,
        size_t attIndex,
        size_t tokenIndex) const;
  virtual AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                            NodePtr &ptr,
                                            size_t attributeDefIdx) const;
  virtual AccessResult makeAttributeDefList(const GroveImpl *grove,
                                            NodeListPtr &ptr,
                                            size_t firstAttDefIdx) const;
  virtual Node *makeOriginNode(const GroveImpl *grove, size_t attIndex) const;
  virtual const void *attributeOriginId() const;
protected:
  const ElementType *elementType_;
};


class NotationAttributeDefOrigin : public virtual AttributeDefOrigin {
public:
  NotationAttributeDefOrigin(const Notation *);
  virtual const AttributeDefinitionList *attDefList() const;
  Node *makeCdataAttributeValueNode(const GroveImpl *grove,
        const AttributeValue *value,
        size_t attIndex,
        const TextIter &iter,
        size_t charIndex) const;
  Node *makeAttributeValueTokenNode(const GroveImpl *grove,
        const TokenizedAttributeValue *value,
        size_t attIndex,
        size_t tokenIndex) const;
  virtual AccessResult makeAttributeDefNode(const GroveImpl *grove,
                                            NodePtr &ptr,
                                            size_t attributeDefIdx) const;
  virtual AccessResult makeAttributeDefList(const GroveImpl *grove,
                                            NodeListPtr &ptr,
                                            size_t firstAttDefIdx) const;
  virtual Node *makeOriginNode(const GroveImpl *grove, size_t attIndex) const;
  virtual const void *attributeOriginId() const;
protected:
  const Notation *notation_;
};

class AttributeAsgnNode : public BaseNode, public virtual AttributeOrigin {
public:
  AttributeAsgnNode(const GroveImpl *grove, size_t attIndex);
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getName(GroveString &str) const;
  AccessResult getImplied(bool &implied) const;
  AccessResult getValue(NodeListPtr &ptr) const;
  AccessResult children(NodeListPtr &ptr) const;
  AccessResult firstChild(NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult followSiblingRef(unsigned long, NodePtr &) const;
  AccessResult firstSibling(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  AccessResult getTokenSep(Char &) const;
  AccessResult tokens(GroveString &) const;
  AccessResult getAttributeDef(NodePtr &) const;
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const { return ClassDef::attributeAssignment; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idAttributes;
    return accessOK;
  }
  bool same(const BaseNode &node) const;
  bool same2(const AttributeAsgnNode *node) const;
  unsigned long hash() const;
};

class ElementAttributeAsgnNode
: public AttributeAsgnNode, public ElementAttributeOrigin {
public:
  ElementAttributeAsgnNode(const GroveImpl *grove, size_t attIndex,
      const ElementChunk *);
};

class EntityAttributeAsgnNode
: public AttributeAsgnNode, public EntityAttributeOrigin {
public:
  EntityAttributeAsgnNode(const GroveImpl *grove, size_t attIndex,
      const ExternalDataEntity *);
};

class AttributeValueTokenNode
: public BaseNode, public virtual AttributeDefOrigin {
public:
  AttributeValueTokenNode(const GroveImpl *grove,
     const TokenizedAttributeValue *value,
                          size_t attIndex,
     size_t tokenIndex);
  AccessResult getParent(NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult followSiblingRef(unsigned long, NodePtr &ptr) const;
  AccessResult firstSibling(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  AccessResult getToken(GroveString &str) const;
  AccessResult getEntity(NodePtr &ptr) const;
  AccessResult getNotation(NodePtr &ptr) const;
  AccessResult getReferent(NodePtr &ptr) const;
  AccessResult getLocation(Location &) const;
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const { return ClassDef::attributeValueToken; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idValue;
    return accessOK;
  }
  bool same(const BaseNode &node) const;
  bool same2(const AttributeValueTokenNode *node) const;
  unsigned long hash() const;
private:
  const TokenizedAttributeValue *value_;
  size_t tokenIndex_;
};

class ElementAttributeValueTokenNode
: public AttributeValueTokenNode, public ElementAttributeOrigin {
public:
  ElementAttributeValueTokenNode(const GroveImpl *grove,
     const TokenizedAttributeValue *value,
     size_t attIndex,
     size_t tokenIndex,
     const ElementChunk *);
};

class EntityAttributeValueTokenNode
: public AttributeValueTokenNode, public EntityAttributeOrigin {
public:
  EntityAttributeValueTokenNode(const GroveImpl *grove,
    const TokenizedAttributeValue *value,
    size_t attIndex,
    size_t tokenIndex,
    const ExternalDataEntity *);
};

class ElementTypeAttributeValueTokenNode
: public AttributeValueTokenNode, public ElementTypeAttributeDefOrigin {
public:
  ElementTypeAttributeValueTokenNode(const GroveImpl *grove,
               const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex,
         const ElementType *);
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idDefaultValue;
    return accessOK;
  }
};

class NotationAttributeValueTokenNode
: public AttributeValueTokenNode, public NotationAttributeDefOrigin {
public:
  NotationAttributeValueTokenNode(const GroveImpl *grove,
           const TokenizedAttributeValue *value,
      size_t attIndex,
      size_t tokenIndex,
      const Notation *);
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idDefaultValue;
    return accessOK;
  }
};

class CdataAttributeValueNode
: public BaseNode, public virtual AttributeDefOrigin {
public:
  static bool skipBoring(TextIter &iter);
  CdataAttributeValueNode(const GroveImpl *grove,
     const AttributeValue *value,
     size_t attIndex,
     const TextIter &iter,
     size_t charIndex);
  AccessResult getParent(NodePtr &ptr) const;
  AccessResult charChunk(const SdataMapper &, GroveString &) const;
  bool chunkContains(const Node &) const;
  bool inChunk(const CdataAttributeValueNode *) const;
  AccessResult getEntity(NodePtr &) const;
  AccessResult getEntityName(GroveString &) const;
  AccessResult getSystemData(GroveString &str) const;
  AccessResult nextSibling(NodePtr &ptr) const;
  AccessResult nextChunkSibling(NodePtr &ptr) const;
  AccessResult firstSibling(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  AccessResult getLocation(Location &) const;
  void accept(NodeVisitor &visitor);
  const ClassDef &classDef() const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idValue;
    return accessOK;
  }
  bool same(const BaseNode &node) const;
  bool same2(const CdataAttributeValueNode *node) const;
  unsigned long hash() const;
private:
  const AttributeValue *value_;
  TextIter iter_;
  size_t charIndex_;
  Char c_;
};

class ElementCdataAttributeValueNode
: public CdataAttributeValueNode, public ElementAttributeOrigin {
public:
  ElementCdataAttributeValueNode(const GroveImpl *grove,
     const AttributeValue *value,
     size_t attIndex,
     const TextIter &iter,
     size_t charIndex,
     const ElementChunk *);
};

class EntityCdataAttributeValueNode
: public CdataAttributeValueNode, public EntityAttributeOrigin {
public:
  EntityCdataAttributeValueNode(const GroveImpl *grove,
    const AttributeValue *value,
    size_t attIndex,
    const TextIter &iter,
    size_t charIndex,
    const ExternalDataEntity *);
};

class ElementTypeCdataAttributeValueNode
: public CdataAttributeValueNode, public ElementTypeAttributeDefOrigin {
public:
  ElementTypeCdataAttributeValueNode(const GroveImpl *grove,
                       const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex,
         const ElementType *);
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idDefaultValue;
    return accessOK;
  }
};

class NotationCdataAttributeValueNode
: public CdataAttributeValueNode, public NotationAttributeDefOrigin {
public:
  NotationCdataAttributeValueNode(const GroveImpl *grove,
        const AttributeValue *value,
      size_t attIndex,
      const TextIter &iter,
      size_t charIndex,
      const Notation *);
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idDefaultValue;
    return accessOK;
  }
};

class EntityNodeBase : public BaseNode {
public:
  EntityNodeBase(const GroveImpl *grove, const Entity *entity)
   : BaseNode(grove), entity_(entity) {}
  AccessResult getName(GroveString &str) const;
  AccessResult getExternalId(NodePtr &ptr) const;
  AccessResult getNotation(NodePtr &) const;
  AccessResult getNotationName(GroveString &) const;
  AccessResult getText(GroveString &) const;
  AccessResult getEntityType(Node::EntityType::Enum &) const;
  AccessResult getAttributes(NamedNodeListPtr &) const;
  AccessResult attributeRef(unsigned long i, NodePtr &ptr) const;
  AccessResult getLocation(Location &) const;
  unsigned long hash() const;
protected:
  const Entity *entity_;
};

class EntityNode : public EntityNodeBase {
public:
  EntityNode(const GroveImpl *grove, const Entity *entity);
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &) const;
  AccessResult getDefaulted(bool &) const;
  bool same(const BaseNode &) const;
  bool same2(const EntityNode *) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::entity; }
};

class DefaultEntityNode : public EntityNodeBase {
public:
  DefaultEntityNode(const GroveImpl *grove, const Entity *entity);
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &) const;
  bool same(const BaseNode &) const;
  bool same2(const DefaultEntityNode *) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::defaultEntity; }
};

class NotationNode : public BaseNode {
public:
  NotationNode(const GroveImpl *grove, const Notation *notation);
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idNotations;
    return accessOK;
  }
  AccessResult getName(GroveString &str) const;
  AccessResult getExternalId(NodePtr &ptr) const;
  AccessResult getAttributeDefs(NamedNodeListPtr &) const;
  bool same(const BaseNode &) const;
  bool same2(const NotationNode *) const;
  AccessResult getLocation(Location &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::notation; }
  unsigned long hash() const;
private:
  const Notation *notation_;
};

class FormalPublicIdNode : public BaseNode {
public:
  FormalPublicIdNode(const GroveImpl *, const PublicId *);
  AccessResult getOwnerType(OwnerType::Enum &) const;
  AccessResult getOwnerId(GroveString &) const;
  AccessResult getTextClass(TextClass::Enum &) const;
  AccessResult getUnavailable(bool &) const;
  AccessResult getTextDescription(GroveString &) const;
  AccessResult getTextLanguage(GroveString &) const;
  AccessResult getTextDesignatingSequence(GroveString &) const;
  AccessResult getTextDisplayVersion(GroveString &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::formalPublicId; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idFormalPublicId;
    return accessOK;
  }
  bool same(const BaseNode &) const;
  bool same2(const FormalPublicIdNode *) const;
private:
  const PublicId *pubid_;
  mutable StringC owner_;
  mutable StringC desc_;
  mutable StringC lang_;
  mutable StringC dseq_;
  mutable StringC dver_;
};

class ExternalIdNode : public BaseNode {
public:
  ExternalIdNode(const GroveImpl *grove);
  virtual const ExternalId &externalId() const = 0;
  AccessResult getPublicId(GroveString &) const;
  AccessResult getFormalPublicId(NodePtr &) const;
  AccessResult getSystemId(GroveString &) const;
  AccessResult getGeneratedSystemId(GroveString &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::externalId; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idExternalId;
    return accessOK;
  }
  bool same(const BaseNode &) const;
  bool same2(const ExternalIdNode *) const;
};

class EntityExternalIdNode : public ExternalIdNode {
public:
  EntityExternalIdNode(const GroveImpl *grove,
         const ExternalEntity *entity);
  const ExternalId &externalId() const;
  AccessResult getOrigin(NodePtr &ptr) const;
  unsigned long hash() const;
private:
  const ExternalEntity *entity_;
};

class NotationExternalIdNode : public ExternalIdNode {
public:
  NotationExternalIdNode(const GroveImpl *grove,
    const Notation *notation);
  const ExternalId &externalId() const;
  AccessResult getOrigin(NodePtr &ptr) const;
  unsigned long hash() const;
private:
  const Notation *notation_;
};

class DocumentTypeNode : public BaseNode {
public:
  DocumentTypeNode(const GroveImpl *grove, const Dtd *);
  AccessResult getName(GroveString &) const;
  AccessResult getGoverning(bool &) const;
  AccessResult getGeneralEntities(NamedNodeListPtr &) const;
  AccessResult getNotations(NamedNodeListPtr &) const;
  AccessResult getElementTypes(NamedNodeListPtr &) const;
  AccessResult getDefaultEntity(NodePtr &) const;
  AccessResult getParameterEntities(NamedNodeListPtr &) const;
  AccessResult getOrigin(NodePtr &) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idDoctypesAndLinktypes;
    return accessOK;
  }
  AccessResult nextChunkSibling(NodePtr &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::documentType; }
  bool same(const BaseNode &) const;
  bool same2(const DocumentTypeNode *) const;
private:
  const Dtd *dtd_;
};

class SgmlConstantsNode : public BaseNode {
public:
  SgmlConstantsNode(const GroveImpl *);
  AccessResult getOrigin(NodePtr &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::sgmlConstants; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idSgmlConstants;
    return accessOK;
  }
  bool same(const BaseNode &) const;
  bool same2(const SgmlConstantsNode *) const;
};

class MessageNode : public BaseNode {
public:
  MessageNode(const GroveImpl *, const MessageItem *);
  AccessResult getOrigin(NodePtr &) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::noId;
    return accessOK;
  }
  AccessResult nextChunkSibling(NodePtr &) const;
  AccessResult firstSibling(NodePtr &) const;
  AccessResult siblingsIndex(unsigned long &) const;
  void accept(NodeVisitor &);
  const ClassDef &classDef() const { return ClassDef::message; }
  bool same(const BaseNode &) const;
  bool same2(const MessageNode *) const;
  AccessResult getLocation(Location &) const;
  AccessResult getText(GroveString &) const;
  AccessResult getSeverity(Severity &) const;
private:
  const MessageItem *item_;
};


class RankStemNode : public BaseNode {
public:
  RankStemNode(const GroveImpl *grove, const RankStem &rankStem, const Dtd::ConstElementTypeIter &iter)
   : BaseNode(grove), rankStem_(rankStem), iter_(iter) {};
  AccessResult getOrigin(NodePtr &) const;
  const ClassDef &classDef() const { return ClassDef::rankStem; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idElementTypes;
    return accessOK;
}
  AccessResult getStem(GroveString &) const;
  AccessResult getElementTypes(NodeListPtr &) const;
  bool same(const BaseNode &) const;
  bool same2(const RankStemNode *) const;
  void accept(NodeVisitor &);
  unsigned long hash() const;
  const RankStem &rankStem() const { return rankStem_; }
protected:
  const RankStem &rankStem_;
  Dtd::ConstElementTypeIter iter_;
};


class ElementTypeNode : public BaseNode {
public:
  ElementTypeNode(const GroveImpl *grove, const ElementType &elementType)
    : BaseNode(grove), elementType_(elementType) {};
  AccessResult getOrigin(NodePtr &) const;
  const ClassDef &classDef() const { return ClassDef::elementType; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idElementTypes;
    return accessOK;
  }
  AccessResult getGi(GroveString &str) const;
  AccessResult getAttributeDefs(NamedNodeListPtr &) const;
  AccessResult getContentType(Node::ContentType::Enum &) const;
  AccessResult getExclusions(GroveStringListPtr &) const;
  AccessResult getInclusions(GroveStringListPtr &) const;
  AccessResult getModelGroup(NodePtr &) const;
  AccessResult getOmitEndTag(bool &) const;
  AccessResult getOmitStartTag(bool &) const;
  AccessResult getRankGroup(GroveStringListPtr &) const;
  AccessResult getRankStem(GroveString &) const;
  AccessResult getRankSuffix(GroveString &) const;
  AccessResult getLocation(Location &) const;
  bool same(const BaseNode &) const;
  bool same2(const ElementTypeNode *) const;
  void accept(NodeVisitor &);
  unsigned long hash() const;
  const ElementType &elementType() const { return elementType_; }
protected:
  const ElementType &elementType_;
};


class ModelGroupNode;
class ContentTokenNodeBase : public BaseNode {
public:
  ContentTokenNodeBase(const GroveImpl *grove,
                       const ElementType &elementType,
                       ModelGroupNode *parentModelGroupNode = 0);
  ~ContentTokenNodeBase();
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idContentTokens;
    return accessOK;
  }
  AccessResult getOrigin(NodePtr &) const;
  AccessResult getLocation(Location &) const;
  const ElementType &elementType() const { return elementType_; }
protected:
  ModelGroupNode *parentModelGroupNode_;
  const ElementType &elementType_;
};


class ElementTokenNode : public ContentTokenNodeBase {
public:
  ElementTokenNode(const GroveImpl *grove,
                   const ElementType &elementType,
                   const ElementToken &elementToken,
                   ModelGroupNode *parentModelGroupNode)
   : ContentTokenNodeBase(grove, elementType, parentModelGroupNode),
     elementToken_(elementToken) {}
  const ClassDef &classDef() const { return ClassDef::elementToken; }
  AccessResult getGi(GroveString &str) const;
  AccessResult getOccurIndicator(Node::OccurIndicator::Enum &) const;
  bool same(const BaseNode &) const;
  bool same2(const ElementTokenNode *) const;
  void accept(NodeVisitor &);
  unsigned long hash() const;
  const ElementToken &elementToken() const { return elementToken_; }
protected:
  const ElementToken &elementToken_;
};


class PcdataTokenNode : public ContentTokenNodeBase {
public:
  PcdataTokenNode(const GroveImpl *grove,
                  const ElementType &elementType,
                  const PcdataToken &pcdataToken,
                  ModelGroupNode *parentModelGroupNode)
   : ContentTokenNodeBase(grove, elementType, parentModelGroupNode),
     pcdataToken_(pcdataToken) {}
  const ClassDef &classDef() const { return ClassDef::pcdataToken; }
  bool same(const BaseNode &) const;
  bool same2(const PcdataTokenNode *) const;
  void accept(NodeVisitor &);
  unsigned long hash() const;
  const PcdataToken &pcdataToken() const { return pcdataToken_; }
protected:
  const PcdataToken &pcdataToken_;
};


class ModelGroupNode : public ContentTokenNodeBase {
public:
  ModelGroupNode(const GroveImpl *grove,
                 const ElementType &elementType,
                 const ModelGroup &modelGroup,
                 ModelGroupNode *parentModelGroupNode = 0)
   : ContentTokenNodeBase(grove, elementType, parentModelGroupNode),
     modelGroup_(modelGroup) {}
  const ClassDef &classDef() const { return ClassDef::modelGroup; }
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const;
  AccessResult getConnector(Node::Connector::Enum &con) const;
  AccessResult getOccurIndicator(Node::OccurIndicator::Enum &occur) const;
  AccessResult getContentTokens(NodeListPtr &) const;
  bool same(const BaseNode &) const;
  bool same2(const ModelGroupNode *) const;
  void accept(NodeVisitor &);
  unsigned long hash() const;
  void makeNode(NodePtr &ptr, unsigned contentTokenIdx);
  const ModelGroup &modelGroup() const { return modelGroup_; }
private:
  const ModelGroup &modelGroup_;
};


class AttributeDefNode : public BaseNode, public virtual AttributeDefOrigin {
public:
  AttributeDefNode(const GroveImpl *grove, size_t attIndex)
   : BaseNode(grove), AttributeDefOrigin(attIndex) {}
  const ClassDef &classDef() const { return ClassDef::attributeDef; }
  AccessResult getName(GroveString &) const;
  AccessResult getDeclValueType(Node::DeclValueType::Enum &) const;
  AccessResult getDefaultValueType(Node::DefaultValueType::Enum &) const;
  AccessResult getTokens(GroveStringListPtr &) const;
  AccessResult getCurrentAttributeIndex(long &) const;
  void accept(NodeVisitor &visitor);
  bool same(const BaseNode &node) const;
  bool same2(const AttributeDefNode *node) const;
  unsigned long hash() const;
protected:
};


class ElementTypeAttributeDefNode
: public AttributeDefNode, public ElementTypeAttributeDefOrigin {
public:
  ElementTypeAttributeDefNode(const GroveImpl *grove,
                              const ElementType &elementType,
                              size_t attributeDefIdx)
   : AttributeDefNode(grove, attributeDefIdx),
     ElementTypeAttributeDefOrigin(&elementType),
     AttributeDefOrigin(attributeDefIdx) {}
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idAttributeDefs;
    return accessOK;
  }
  AccessResult getCurrentGroup(NodeListPtr &) const;
  AccessResult getLocation(Location &) const;
  AccessResult getDefaultValue(NodeListPtr &) const;
};


class NotationAttributeDefNode
: public AttributeDefNode, public NotationAttributeDefOrigin {
public:
  NotationAttributeDefNode(const GroveImpl *grove,
                           const Notation &notation,
                           size_t attributeDefIdx)
   : AttributeDefNode(grove, attributeDefIdx),
     NotationAttributeDefOrigin(&notation),
     AttributeDefOrigin(attributeDefIdx) {};
  AccessResult getOrigin(NodePtr &ptr) const;
  AccessResult getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const {
    name = ComponentName::idAttributeDefs;
    return accessOK;
  }
  AccessResult getCurrentGroup(NodeListPtr &) const;
  AccessResult getLocation(Location &) const;
  AccessResult getDefaultValue(NodeListPtr &) const;
};

class BaseNodeList : public NodeList {
public:
  BaseNodeList() : refCount_(0) { }
  virtual ~BaseNodeList() { }
  void addRef() { ++refCount_; }
  bool canReuse(NodeListPtr &ptr) const {
    const NodeList *tem = &*ptr;
    return tem == this && refCount_ == 1;
  }
  void release() {
    (static_cast<void> (__builtin_expect (!!(refCount_ != 0), 1) ? 0 : (__assert_fail ("refCount_ != 0", "GroveBuilder.cxx", 1547, __PRETTY_FUNCTION__), 0)));
    if (--refCount_ == 0) delete this;
  }
  AccessResult first(NodePtr &) const { return accessNull; }
  AccessResult rest(NodeListPtr &ptr) const { return chunkRest(ptr); }
  AccessResult chunkRest(NodeListPtr &) const { return accessNull; }
private:
  unsigned refCount_;
};

class SiblingNodeList : public BaseNodeList {
public:
  SiblingNodeList(const NodePtr &first) : first_(first) { }
  AccessResult first(NodePtr &ptr) const {
    ptr = first_;
    return accessOK;
  }
  AccessResult rest(NodeListPtr &ptr) const {
    AccessResult ret;
    if (canReuse(ptr)) {
      ret = ((SiblingNodeList *)this)->first_.assignNextSibling();
      if (ret == accessOK)
 return ret;
    }
    else {
      NodePtr next;
      ret = first_->nextSibling(next);
      if (ret == accessOK) {
 ptr.assign(new SiblingNodeList(next));
 return ret;
      }
    }
    if (ret == accessNull) {
      ptr.assign(new BaseNodeList);
      return accessOK;
    }
    return ret;
  }
  AccessResult chunkRest(NodeListPtr &ptr) const {
    AccessResult ret;
    if (canReuse(ptr)) {
      ret = ((SiblingNodeList *)this)->first_.assignNextChunkSibling();
      if (ret == accessOK)
 return ret;
    }
    else {
      NodePtr next;
      ret = first_->nextChunkSibling(next);
      if (ret == accessOK) {
 ptr.assign(new SiblingNodeList(next));
 return ret;
      }
    }
    if (ret == accessNull) {
      ptr.assign(new BaseNodeList);
      return accessOK;
    }
    return ret;
  }
  AccessResult ref(unsigned long i, NodePtr &ptr) const {
    if (i == 0) {
      ptr = first_;
      return accessOK;
    }
    return first_->followSiblingRef(i - 1, ptr);
  }
private:
  NodePtr first_;
};

class BaseNamedNodeList : public NamedNodeList {
public:
  BaseNamedNodeList(const GroveImpl *grove,
      const SubstTable *substTable)
  : grove_(grove), substTable_(substTable), refCount_(0) { }
  virtual ~BaseNamedNodeList() { }
  void addRef() { ++refCount_; }
  bool canReuse(NamedNodeListPtr &ptr) const {
    const NamedNodeList *tem = &*ptr;
    return tem == this && refCount_ == 1;
  }
  void release() {
    (static_cast<void> (__builtin_expect (!!(refCount_ != 0), 1) ? 0 : (__assert_fail ("refCount_ != 0", "GroveBuilder.cxx", 1629, __PRETTY_FUNCTION__), 0)));
    if (--refCount_ == 0) delete this;
  }
  size_t normalize(GroveChar *s, size_t n) const {
    if (substTable_) {
      for (size_t i = 0; i < n; i++)
 substTable_->subst(s[i]);
    }
    return n;
  }
  const GroveImpl *grove() const { return grove_; }
  AccessResult namedNode(GroveString str, NodePtr &node) const {
    StringC tem(str.data(), str.size());
    normalize(&tem[0], tem.size());
    return namedNodeU(tem, node);
  }
  virtual AccessResult namedNodeU(const StringC &, NodePtr &) const = 0;
private:
  GroveImplPtr grove_;
  const SubstTable *substTable_;
  unsigned refCount_;
};

class AttributesNamedNodeList
: public BaseNamedNodeList, public virtual AttributeOrigin {
public:
  AttributesNamedNodeList(const GroveImpl *grove)
   : BaseNamedNodeList(grove, grove->generalSubstTable()) { }
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return attributes; }
};

class ElementAttributesNamedNodeList
: public AttributesNamedNodeList, public ElementAttributeOrigin {
public:
  ElementAttributesNamedNodeList(const GroveImpl *grove,
     const ElementChunk *chunk)
   : AttributesNamedNodeList(grove), ElementAttributeOrigin(chunk) { }
};

class EntityAttributesNamedNodeList
: public AttributesNamedNodeList, public EntityAttributeOrigin {
public:
  EntityAttributesNamedNodeList(const GroveImpl *grove,
    const ExternalDataEntity *entity)
   : AttributesNamedNodeList(grove), EntityAttributeOrigin(entity) { }
};

class ElementsNamedNodeList : public BaseNamedNodeList {
public:
  ElementsNamedNodeList(const GroveImpl *grove)
    : BaseNamedNodeList(grove, grove->generalSubstTable()) { }
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return elements; }
};

class DocEntitiesNamedNodeList : public BaseNamedNodeList {
public:
  DocEntitiesNamedNodeList(const GroveImpl *grove)
   : BaseNamedNodeList(grove, grove->entitySubstTable()) { }
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return entities; }
};

class DefaultedEntitiesNamedNodeList : public BaseNamedNodeList {
public:
  DefaultedEntitiesNamedNodeList(const GroveImpl *grove)
   : BaseNamedNodeList(grove, grove->entitySubstTable()) { }
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return entities; }
};

class GeneralEntitiesNamedNodeList : public BaseNamedNodeList {
public:
  GeneralEntitiesNamedNodeList(const GroveImpl *, const Dtd *);
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return entities; }
private:
  const Dtd *dtd_;
};

class ParameterEntitiesNamedNodeList : public BaseNamedNodeList {
public:
  ParameterEntitiesNamedNodeList(const GroveImpl *, const Dtd *);
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return entities; }
private:
  const Dtd *dtd_;
};

class NotationsNamedNodeList : public BaseNamedNodeList {
public:
  NotationsNamedNodeList(const GroveImpl *, const Dtd *);
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return notations; }
private:
  const Dtd *dtd_;
};

class DoctypesAndLinktypesNamedNodeList : public BaseNamedNodeList {
public:
  DoctypesAndLinktypesNamedNodeList(const GroveImpl *);
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return doctypesAndLinktypes; }
};

class ElementsNodeList : public BaseNodeList {
public:
  ElementsNodeList(const GroveImpl *grove,
                   const Chunk *head);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
public:
  GroveImplPtr grove_;
  const Chunk *first_;
};

class EntitiesNodeList : public BaseNodeList {
public:
  EntitiesNodeList(const GroveImpl *grove,
     const Dtd::ConstEntityIter &iter);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
protected:
  const GroveImpl *grove() const { return grove_; }
public:
  GroveImplPtr grove_;
  Dtd::ConstEntityIter iter_;
};

class DocEntitiesNodeList : public EntitiesNodeList {
public:
  DocEntitiesNodeList(const GroveImpl *grove);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
};

class NotationsNodeList : public BaseNodeList {
public:
  NotationsNodeList(const GroveImpl *grove,
                    const Dtd::ConstNotationIter &iter);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
public:
  GroveImplPtr grove_;
  Dtd::ConstNotationIter iter_;
};


class RankStemElementTypesNodeList : public BaseNodeList {
public:
  RankStemElementTypesNodeList(const GroveImpl *,
                               const RankStem &,
                               const Dtd::ConstElementTypeIter &);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
protected:
  GroveImplPtr grove_;
  const RankStem &rankStem_;
  Dtd::ConstElementTypeIter iter_;
};


class ElementTypesNodeList : public BaseNodeList {
public:
  ElementTypesNodeList( const GroveImpl *,
                        const Dtd *,
                        const Dtd::ConstElementTypeIter &,
                        const Dtd::ConstRankStemIter &);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
protected:
  GroveImplPtr grove_;
  const Dtd *dtd_;
  Dtd::ConstElementTypeIter elementTypeIter_;
  Dtd::ConstRankStemIter rankStemIter_;
};


class ElementTypesNamedNodeList : public BaseNamedNodeList {
public:
  ElementTypesNamedNodeList(const GroveImpl *, const Dtd *);
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return elementTypes; }
protected:
  const Dtd *dtd_;
};


class ContentTokenNodeList : public BaseNodeList {
public:
  ContentTokenNodeList(const GroveImpl *grove,
                       ModelGroupNode &modelGroupNode,
                       unsigned firstTokenIdx = 0);
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
  unsigned firstTokenIdx() const { return firstTokenIdx_; }
  AccessResult next();
protected:
  GroveImplPtr grove_;
  ModelGroupNode &modelGroupNode_;
  unsigned firstTokenIdx_;
};


class AttributeDefsNodeList
 : public BaseNodeList, public virtual AttributeDefOrigin {
public:
  AttributeDefsNodeList(const GroveImpl *grove,
                        size_t firstAttIndex)
   : grove_(grove), AttributeDefOrigin(firstAttIndex) {}
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
  bool inList(size_t attIndex) const;
protected:
  GroveImplPtr grove_;
};


class ElementTypeAttributeDefsNodeList
 : public AttributeDefsNodeList, public ElementTypeAttributeDefOrigin {
public:
  ElementTypeAttributeDefsNodeList(const GroveImpl *grove,
                                   const ElementType &elementType,
                                   size_t firstAttIndex)
   : AttributeDefsNodeList(grove, firstAttIndex),
     ElementTypeAttributeDefOrigin(&elementType),
     AttributeDefOrigin(firstAttIndex) {}
};


class NotationAttributeDefsNodeList
 : public AttributeDefsNodeList, public NotationAttributeDefOrigin {
public:
  NotationAttributeDefsNodeList(const GroveImpl *grove,
                                const Notation &notation,
                                size_t firstAttIndex)
   : AttributeDefsNodeList(grove, firstAttIndex),
     NotationAttributeDefOrigin(&notation),
     AttributeDefOrigin(firstAttIndex) {}
};


class AttributeDefsNamedNodeList
 : public BaseNamedNodeList, public virtual AttributeDefOrigin {
public:
  AttributeDefsNamedNodeList(const GroveImpl *grove)
   : BaseNamedNodeList(grove, grove->generalSubstTable()) { }
  NodeListPtr nodeList() const;
  AccessResult namedNodeU(const StringC &, NodePtr &) const;
  Type type() const { return attributeDefs; }
};


class ElementTypeAttributeDefsNamedNodeList
 : public AttributeDefsNamedNodeList, public ElementTypeAttributeDefOrigin {
public:
  ElementTypeAttributeDefsNamedNodeList(const GroveImpl *grove,
                  const ElementType &elementType)
   : AttributeDefsNamedNodeList(grove), ElementTypeAttributeDefOrigin(&elementType) { }
};


class NotationAttributeDefsNamedNodeList
 : public AttributeDefsNamedNodeList, public NotationAttributeDefOrigin {
public:
  NotationAttributeDefsNamedNodeList(const GroveImpl *grove,
            const Notation &notation)
   : AttributeDefsNamedNodeList(grove), NotationAttributeDefOrigin(&notation) { }
};



class ElementTypeCurrentGroupAttributeDefsNodeList
: public BaseNodeList {
public:
  ElementTypeCurrentGroupAttributeDefsNodeList(const GroveImpl *grove,
                                               const Dtd::ConstElementTypeIter &iter,
                                               size_t currentGroupIndex);
  ElementTypeCurrentGroupAttributeDefsNodeList(const GroveImpl *grove,
                                               const Dtd::ConstElementTypeIter &iter,
                                               const ElementType *elementType,
                                               size_t firstAttIndex,
                                               size_t currentGroupIndex)
   : grove_(grove), iter_(iter), elementType_(elementType), attIndex_(firstAttIndex),
     currentGroupIndex_(currentGroupIndex) {}
  AccessResult first(NodePtr &) const;
  AccessResult chunkRest(NodeListPtr &) const;
  bool next(Dtd::ConstElementTypeIter &iter,
            const ElementType *&elementType,
            size_t &attIndex,
            bool incrementFirst = true) const;
  bool next(bool incrementFirst = true) {
    return next(iter_, elementType_, attIndex_, incrementFirst); }
protected:
  GroveImplPtr grove_;
  Dtd::ConstElementTypeIter iter_;
  const ElementType *elementType_;
  size_t currentGroupIndex_;
  size_t attIndex_;
};

inline
Boolean GroveImpl::waitForMoreNodes() const
{
  if (blockingAccess)
    return moreNodesCondition_.wait();
  else
    return 0;
}

inline
void GroveImpl::pulse()
{
  moreNodesCondition_.pulse();
}

inline
void GroveImpl::maybePulse()
{



  if ((++nEvents_ & ~(~unsigned(0) << pulseStep_)) == 0) {
    pulse();
    if (pulseStep_ < 8 && nEvents_ > (1 << (pulseStep_ + 10)))
      pulseStep_++;
  }
}

inline
void GroveImpl::appendSibling(Chunk *chunk)
{
  if (pendingData_) {
    if (tailPtr_) {

      completeLimit_ = pendingData_->after();
      *tailPtr_ = pendingData_;
      tailPtr_ = 0;
    }
    pendingData_ = 0;
  }

  chunk->origin = origin_;

  completeLimit_ = freePtr_;
  if (tailPtr_) {
    *tailPtr_ = chunk;
    tailPtr_ = 0;
  }
  pendingData_ = 0;
  maybePulse();
}

inline
void GroveImpl::appendSibling(DataChunk *chunk)
{



  if (pendingData_) {

    completeLimit_ = pendingData_->after();
    if (tailPtr_) {
      *tailPtr_ = pendingData_;
      tailPtr_ = 0;
    }
  }
  chunk->origin = origin_;
  pendingData_ = chunk;
  maybePulse();
}

inline
void GroveImpl::push(ElementChunk *chunk, Boolean hasId)
{
  if (pendingData_) {
    if (tailPtr_) {

      completeLimit_ = pendingData_->after();
      *tailPtr_ = pendingData_;
      tailPtr_ = 0;
    }
    pendingData_ = 0;
  }
  chunk->elementIndex = nElements_++;
  chunk->origin = origin_;





  origin_ = chunk;
  completeLimit_ = freePtr_;


  if ((const Chunk *)chunk->origin == root_ && root_->documentElement == 0)
    root_->documentElement = chunk;
  else if (tailPtr_) {
    *tailPtr_ = chunk;
    tailPtr_ = 0;
  }
  if (hasId) {
    Mutex::Lock lock(mutexPtr_);
    idTable_.insert(chunk);
  }
  maybePulse();
}

inline
void GroveImpl::pop()
{
  if (pendingData_) {

    completeLimit_ = pendingData_->after();
    if (tailPtr_) {
      *tailPtr_ = pendingData_;
      tailPtr_ = 0;
    }
    pendingData_ = 0;
  }
  tailPtr_ = &origin_->nextSibling;
  origin_ = origin_->origin;
  if ((const Chunk *)origin_ == root_)
    finishDocumentElement();
  maybePulse();
}

inline
Boolean GroveImpl::haveRootOrigin()
{
  return (const Chunk *)origin_ == root_;
}

inline
void GroveImpl::setGoverningDtd(const ConstPtr<Dtd> &dtd)
{
  dtd_ = dtd;
  hasDefaultEntity_ = !dtd_->defaultEntity().isNull();
  finishProlog();
  pulse();
}

inline
void GroveImpl::addDtd(const ConstPtr<Dtd> &dtd)
{
  allDtds_.push_back(dtd);
}

const Dtd *GroveImpl::lookupDtd(const StringC &name) const
{
  for (size_t i = 0; i < allDtds_.size(); i++)
    if (allDtds_[i]->name() == name)
      return allDtds_[i].pointer();
  return 0;
}

const Dtd *GroveImpl::lookupDtd(const ElementType &et) const
{
  for (size_t i = 0; i < allDtds_.size(); i++)
    if (allDtds_[i]->lookupElementType(et.name()) == &et)
      return allDtds_[i].pointer();
  return 0;
}

const Dtd *GroveImpl::lookupDtd(const RankStem &rs) const
{
  for (size_t i = 0; i < allDtds_.size(); i++)
    if (allDtds_[i]->lookupRankStem(rs.name()) == &rs)
      return allDtds_[i].pointer();
  return 0;
}

const Dtd *GroveImpl::nextDtd(const Dtd *dtd) const
{
  for (size_t i = 0; i < allDtds_.size() - 1; i++)
    if (allDtds_[i].pointer() == dtd)
      return allDtds_[i+1].pointer();
  return 0;
}

inline
const ElementChunk *GroveImpl::lookupElement(const StringC &id) const
{
  Mutex::Lock lock(mutexPtr_);
  return idTable_.lookup(id);
}

inline
GroveImpl::ElementIter GroveImpl::elementIter() const
{
  (static_cast<void> (__builtin_expect (!!(complete()), 1) ? 0 : (__assert_fail ("complete()", "GroveBuilder.cxx", 2129, __PRETTY_FUNCTION__), 0)));
  return ElementIter(idTable_);
}

inline
Boolean GroveImpl::maybeMoreSiblings(const ParentChunk *chunk) const
{
  return (complete_
          ? chunk->nextSibling != 0
   : (origin_ == chunk
       || &chunk->nextSibling == tailPtr_
       || maybeMoreSiblings1(chunk)));
}

inline
void *GroveImpl::allocChunk(size_t n)
{
  nChunksSinceLocOrigin_++;
  if (n <= nFree_) {
    void *p = freePtr_;
    freePtr_ += n;
    nFree_ -= n;
    return p;
  }
  else
    return allocFinish(n);
}

inline
void GroveImpl::setLocOrigin(const ConstPtr<Origin> &locOrigin)
{
  if (locOrigin.pointer() != currentLocOrigin_
      || nChunksSinceLocOrigin_ >= maxChunksWithoutLocOrigin)
    storeLocOrigin(locOrigin);
}

inline
void GroveImpl::appendMessage(MessageItem *item)
{
  *messageListTailP_ = item;
  messageListTailP_ = item->nextP();
  pulse();
}

inline
void ElementNode::add(GroveImpl &grove, const StartElementEvent &event)
{
  grove.setLocOrigin(event.location().origin());
  ElementChunk *chunk;
  const AttributeList &atts = event.attributes();
  Boolean hasId;
  if (atts.nSpec() == 0 && !atts.anyCurrent()) {
    void *mem = grove.allocChunk(sizeof(ElementChunk));
    if (event.included())
      chunk = new (mem) IncludedElementChunk;
    else
      chunk = new (mem) ElementChunk;
    hasId = 0;
  }
  else
    chunk = makeAttElementChunk(grove, event, hasId);
  chunk->type = event.elementType();
  chunk->locIndex = event.location().index();
  grove.push(chunk, hasId);
}



inline
AccessResult DataNode::nextChunkSibling(NodePtr &ptr) const
{


  const Chunk *p = chunk_->after();
  while (p == grove()->completeLimit())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  if (p->origin != chunk_->origin)
    return accessNull;
  return p->setNodePtrFirst(ptr, this);
}

inline
void DataNode::reuseFor(const DataChunk *chunk, size_t index)
{
  chunk_ = chunk;
  index_ = index;
}

inline
void DataNode::add(GroveImpl &grove, const DataEvent &event)
{
  size_t dataLen = event.dataLength();
  if (dataLen) {
   DataChunk *chunk = grove.pendingData();
   if (chunk
       && event.location().origin().pointer() == grove.currentLocOrigin()
       && event.location().index() == chunk->locIndex + chunk->size
       && grove.tryExtend(CharsChunk::allocSize(chunk->size + dataLen)
                          - CharsChunk::allocSize(chunk->size))) {
     memcpy((Char *)(chunk + 1) + chunk->size,
     event.data(),
     dataLen * sizeof(Char));
     chunk->size += dataLen;
   }
   else {
     grove.setLocOrigin(event.location().origin());
     chunk = new (grove.allocChunk(CharsChunk::allocSize(dataLen))) DataChunk;
     chunk->size = dataLen;
     chunk->locIndex = event.location().index();
     memcpy(chunk + 1, event.data(), dataLen * sizeof(Char));
     grove.appendSibling(chunk);
   }
 }
}

GroveBuilderMessageEventHandler::GroveBuilderMessageEventHandler(unsigned groveIndex,
         Messenger *mgr,
         MessageFormatter *msgFmt)
: mgr_(mgr), grove_(new GroveImpl(groveIndex)), msgFmt_(msgFmt)
{
  grove_->addRef();
}

GroveBuilderMessageEventHandler::~GroveBuilderMessageEventHandler()
{
  grove_->setComplete();
  grove_->release();
}

void GroveBuilderMessageEventHandler::makeInitialRoot(NodePtr &root)
{
  root.assign(new SgmlDocumentNode(grove_, grove_->root()));
}

void GroveBuilderMessageEventHandler::message(MessageEvent *event)
{
  mgr_->dispatchMessage(event->message());
  const Message &msg = event->message();
  StrOutputCharStream os;
  msgFmt_->formatMessage(*msg.type, msg.args, os);
  StringC tem;
  os.extractString(tem);
  Node::Severity severity;
  switch (msg.type->severity()) {
  case MessageType::info:
    severity = Node::info;
    break;
  case MessageType::warning:
    severity = Node::warning;
    break;
  default:
    severity = Node::error;
    break;
  }
  grove_->appendMessage(new MessageItem(severity, tem, msg.loc));
  if (!msg.auxLoc.origin().isNull()) {
    msgFmt_->formatMessage(msg.type->auxFragment(), msg.args, os);
    os.extractString(tem);
    grove_->appendMessage(new MessageItem(Node::info, tem, msg.auxLoc));
  }
  ErrorCountEventHandler::message(event);
}

void GroveBuilderMessageEventHandler::sgmlDecl(SgmlDeclEvent *event)
{
  grove_->setSd(event->sdPointer(), event->prologSyntaxPointer(), event->instanceSyntaxPointer());
  delete event;
}

void GroveBuilderMessageEventHandler::setSd(const ConstPtr<Sd> &sd, const ConstPtr<Syntax> &prologSyntax, const ConstPtr<Syntax> &instanceSyntax)
{
  grove_->setSd(sd, prologSyntax, instanceSyntax);
}

GroveBuilderEventHandler::GroveBuilderEventHandler(unsigned groveIndex,
         Messenger *mgr,
         MessageFormatter *msgFmt)
: GroveBuilderMessageEventHandler(groveIndex, mgr, msgFmt)
{
}

void GroveBuilderEventHandler::appinfo(AppinfoEvent *event)
{
  const StringC *appinfo;
  if (event->literal(appinfo))
    grove_->setAppinfo(*appinfo);
  delete event;
}

void GroveBuilderEventHandler::endProlog(EndPrologEvent *event)
{
  grove_->setGoverningDtd(event->dtdPointer());
  delete event;
}

void GroveBuilderEventHandler::endDtd(EndDtdEvent *event)
{
  grove_->addDtd(event->dtdPointer());
  delete event;
}

void GroveBuilderEventHandler::startElement(StartElementEvent *event)
{
  ElementNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::endElement(EndElementEvent *event)
{
  grove_->pop();
  delete event;
}

void GroveBuilderEventHandler::data(DataEvent *event)
{
  DataNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::sdataEntity(SdataEntityEvent *event)
{
  SdataNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::nonSgmlChar(NonSgmlCharEvent *event)
{
  NonSgmlNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::externalDataEntity(ExternalDataEntityEvent *event)
{
  ExternalDataNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::subdocEntity(SubdocEntityEvent *event)
{
  SubdocNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::pi(PiEvent *event)
{
  PiNode::add(*grove_, *event);
  delete event;
}

void GroveBuilderEventHandler::entityDefaulted(EntityDefaultedEvent *event)
{
  grove_->addDefaultedEntity(event->entityPointer());
  delete event;
}

ErrorCountEventHandler *GroveBuilder::make(unsigned index,
        Messenger *mgr,
        MessageFormatter *msgFmt,
        bool validateOnly,
        NodePtr &root)
{
  GroveBuilderMessageEventHandler *eh;
  if (validateOnly)
    eh = new GroveBuilderMessageEventHandler(index, mgr, msgFmt);
  else
    eh = new GroveBuilderEventHandler(index, mgr, msgFmt);
  eh->makeInitialRoot(root);
  return eh;
}

ErrorCountEventHandler *GroveBuilder::make(unsigned index,
        Messenger *mgr,
        MessageFormatter *msgFmt,
        bool validateOnly,
        const ConstPtr<Sd> &sd,
        const ConstPtr<Syntax> &prologSyntax,
        const ConstPtr<Syntax> &instanceSyntax,
        NodePtr &root)
{
  GroveBuilderMessageEventHandler *eh;
  if (validateOnly)
    eh = new GroveBuilderMessageEventHandler(index, mgr, msgFmt);
  else
    eh = new GroveBuilderEventHandler(index, mgr, msgFmt);
  eh->makeInitialRoot(root);
  eh->setSd(sd, prologSyntax, instanceSyntax);
  return eh;
}

bool GroveBuilder::setBlocking(bool b)
{
  bool prev = blockingAccess;
  blockingAccess = b;
  return prev;
}

GroveImpl::GroveImpl(unsigned groveIndex)
: groveIndex_(groveIndex),
  root_(0),
  impliedAttributeValue_(new ImpliedAttributeValue),
  tailPtr_(0),
  freePtr_(0),
  nFree_(0),
  blocks_(0),
  blockTailPtr_(&blocks_),
  blockAllocSize_(initialBlockSize),
  nBlocksThisSizeAlloced_(0),
  complete_(0),
  mutexPtr_(&mutex_),
  pulseStep_(0),
  nEvents_(0),
  haveAppinfo_(0),
  pendingData_(0),
  nElements_(0),
  currentLocOrigin_(0),
  completeLimitWithLocChunkAfter_(0),
  nChunksSinceLocOrigin_(0),
  messageList_(0),
  messageListTailP_(&messageList_)
{
  root_ = new (allocChunk(sizeof(SgmlDocumentChunk))) SgmlDocumentChunk;
  root_->origin = 0;
  root_->locIndex = 0;
  completeLimit_ = freePtr_;
  origin_ = root_;
  tailPtr_ = &root_->prolog;
}

GroveImpl::~GroveImpl()
{
  while (blocks_) {
    BlockHeader *tem = blocks_;
    blocks_ = blocks_->next;
    ::operator delete(tem);
  }
  while (messageList_) {
    MessageItem *tem = messageList_;
    messageList_ = *messageList_->nextP();
    delete tem;
  }
}

void GroveImpl::setAppinfo(const StringC &appinfo)
{
  appinfo_ = appinfo;
  haveAppinfo_ = 1;
}

Boolean GroveImpl::getAppinfo(const StringC *&appinfo) const
{
  if (!haveAppinfo_) {
    if (!complete_ && sd_.isNull())
      return 0;
    appinfo = 0;
  }
  else
    appinfo = &appinfo_;
  return 1;
}

void GroveImpl::setSd(const ConstPtr<Sd> &sd, const ConstPtr<Syntax> &prologSyntax, const ConstPtr<Syntax> &instanceSyntax)
{
  instanceSyntax_ = instanceSyntax;
  prologSyntax_ = prologSyntax;
  sd_ = sd;
}

void GroveImpl::getSd(ConstPtr<Sd> &sd, ConstPtr<Syntax> &prologSyntax, ConstPtr<Syntax> &instanceSyntax) const
{
  instanceSyntax = instanceSyntax_;
  prologSyntax = prologSyntax_;
  sd = sd_;
}

void GroveImpl::finishProlog()
{
  if (root_->prolog)
    addBarrier();
  tailPtr_ = 0;
}

void GroveImpl::finishDocumentElement()
{

  if (root_->epilog == 0) {
    addBarrier();
    tailPtr_ = &root_->epilog;
  }
}

void GroveImpl::addBarrier()
{
  if (freePtr_) {
    (void) new (freePtr_) ForwardingChunk(0, 0);
    if (nFree_ <= sizeof(ForwardingChunk)) {
      nFree_ = 0;
      freePtr_ = 0;
    }
    else {
      nFree_ -= sizeof(ForwardingChunk);
      freePtr_ += sizeof(ForwardingChunk);
    }
  }
}

void GroveImpl::setComplete()
{
  addBarrier();
  mutexPtr_ = 0;
  completeLimit_ = 0;
  completeLimitWithLocChunkAfter_ = 0;
  if (pendingData_ && tailPtr_)
    *tailPtr_ = pendingData_;
  tailPtr_ = 0;
  pendingData_ = 0;
  complete_ = 1;
  moreNodesCondition_.set();
}

void GroveImpl::addDefaultedEntity(const ConstPtr<Entity> &entity)
{
  Mutex::Lock lock(mutexPtr_);

  defaultedEntityTable_.insert((Entity *)entity.pointer());
}

const Entity *GroveImpl::lookupDefaultedEntity(const StringC &name) const
{
  Mutex::Lock lock(mutexPtr_);
  return defaultedEntityTable_.lookupTemp(name);
}

Dtd::ConstEntityIter GroveImpl::defaultedEntityIter() const
{
  (static_cast<void> (__builtin_expect (!!(complete()), 1) ? 0 : (__assert_fail ("complete()", "GroveBuilder.cxx", 2564, __PRETTY_FUNCTION__), 0)));
  return Dtd::ConstEntityIter(defaultedEntityTable_);
}

Boolean GroveImpl::maybeMoreSiblings1(const ParentChunk *chunk) const
{
  for (const ParentChunk *open = origin_; open; open = open->origin)
    if (open == chunk)
      return 1;

  return tailPtr_ == &chunk->nextSibling || chunk->nextSibling != 0;
}

void *GroveImpl::allocFinish(size_t n)
{
  if (++nBlocksThisSizeAlloced_ >= maxBlocksPerSize) {
     blockAllocSize_ *= 2;
     nBlocksThisSizeAlloced_ = 0;
  }
  size_t allocSize = n + (sizeof(ForwardingChunk) + sizeof(BlockHeader));
  if (allocSize < blockAllocSize_) {
    nFree_ = blockAllocSize_ - allocSize;
    allocSize = blockAllocSize_;
  }
  else
    nFree_ = 0;
  *blockTailPtr_ = new (::operator new(allocSize)) BlockHeader;
  char *chunkStart = (char *)(*blockTailPtr_ + 1);
  blockTailPtr_ = &(*blockTailPtr_)->next;
  if (freePtr_)
    (void)new (freePtr_) ForwardingChunk((const Chunk *)chunkStart, origin_);
  freePtr_ = chunkStart + n;
  return chunkStart;
}

AccessResult ChunkNode::getLocation(Location &loc) const
{
  const Origin *origin = grove()->currentLocOrigin();
  for (const Chunk *p = chunk_->after(); p; p = p->after()) {
    if (p == grove()->completeLimitWithLocChunkAfter()) {
      while (!p->getLocOrigin(origin)) {
 p = p->after();
 (static_cast<void> (__builtin_expect (!!(p != 0), 1) ? 0 : (__assert_fail ("p != 0", "GroveBuilder.cxx", 2606, __PRETTY_FUNCTION__), 0)));
      }
      break;
    }
    if (p == grove()->completeLimit() || p->getLocOrigin(origin))
      break;
  }
  if (!origin)
    return accessNull;
  loc = Location(new GroveImplProxyOrigin(grove(), origin), chunk_->locIndex);
  return accessOK;
}

void GroveImpl::storeLocOrigin(const ConstPtr<Origin> &locOrigin)
{
  LocOriginChunk *chunk
    = new (allocChunk(sizeof(LocOriginChunk)))
   LocOriginChunk(currentLocOrigin_);
  chunk->origin = origin_;
  completeLimitWithLocChunkAfter_ = completeLimit_;
  nChunksSinceLocOrigin_ = 0;
  if (locOrigin.pointer() == currentLocOrigin_)
    return;
  if (currentLocOrigin_
      && locOrigin == currentLocOrigin_->parent().origin()) {

    currentLocOrigin_ = locOrigin.pointer();
    return;
  }
  currentLocOrigin_ = locOrigin.pointer();
  if (locOrigin.isNull())
    return;
  origins_.push_back(locOrigin);
}

AccessResult GroveImpl::proxifyLocation(const Location &loc, Location &ret) const
{
  if (loc.origin().isNull())
    return accessNull;
  ret = Location(new GroveImplProxyOrigin(this, loc.origin().pointer()),
   loc.index());
  return accessOK;
}

NodeListPtr AttributesNamedNodeList::nodeList() const
{
  const AttributeDefinitionList *defList = attDefList();
  if (!defList || defList->size() == 0)
    return new BaseNodeList;
  else
    return new SiblingNodeList(makeAttributeAsgnNode(grove(), 0));
}

AccessResult
AttributesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const AttributeDefinitionList *defList = attDefList();
  if (defList) {
    for (size_t i = 0; i < defList->size(); i++)
      if (defList->def(i)->name() == str) {
        ptr.assign(makeAttributeAsgnNode(grove(), i));
 return accessOK;
      }
  }
  return accessNull;
}

void SgmlDocumentNode::accept(NodeVisitor &visitor)
{
  visitor.sgmlDocument(*this);
}

AccessResult SgmlDocumentNode::getSgmlConstants(NodePtr &ptr) const
{
  ptr.assign(new SgmlConstantsNode(grove()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getApplicationInfo(GroveString &str) const
{
  const StringC *appinfo;
  while (!grove()->getAppinfo(appinfo))
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  if (!appinfo)
    return accessNull;
  setString(str, *appinfo);
  return accessOK;
}

AccessResult SgmlDocumentNode::getDocumentElement(NodePtr &ptr) const
{
  while (chunk()->documentElement == 0) {
    if (grove()->complete()) {

      if (chunk()->documentElement)
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  return chunk()->documentElement->setNodePtrFirst(ptr, this);
}

AccessResult SgmlDocumentNode::getProlog(NodeListPtr &ptr) const
{
  while (chunk()->prolog == 0) {
    if (chunk()->documentElement || grove()->complete())
      break;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  if (chunk()->prolog == 0)
    ptr.assign(new BaseNodeList);
  else {
    NodePtr tem;
    chunk()->prolog->setNodePtrFirst(tem, this);
    ptr.assign(new SiblingNodeList(tem));
  }
  return accessOK;
}

AccessResult SgmlDocumentNode::getEpilog(NodeListPtr &ptr) const
{
  while (chunk()->epilog == 0) {
    if (grove()->complete())
      break;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  if (chunk()->epilog == 0)
    ptr.assign(new BaseNodeList);
  else {
    NodePtr tem;
    chunk()->epilog->setNodePtrFirst(tem, this);
    ptr.assign(new SiblingNodeList(tem));
  }
  return accessOK;
}

AccessResult SgmlDocumentNode::getElements(NamedNodeListPtr &ptr) const
{
  while (!grove()->root()->documentElement) {
    if (grove()->complete()) {
      if (grove()->root()->documentElement)
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  if (!grove()->generalSubstTable())
    return accessNull;
  ptr.assign(new ElementsNamedNodeList(grove()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getEntities(NamedNodeListPtr &ptr) const
{
  while (!grove()->governingDtd()) {
    if (grove()->complete()) {
      if (grove()->governingDtd())
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  ptr.assign(new DocEntitiesNamedNodeList(grove()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getDefaultedEntities(NamedNodeListPtr &ptr) const
{
  while (!grove()->complete())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  ptr.assign(new DefaultedEntitiesNamedNodeList(grove()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getGoverningDoctype(NodePtr &ptr) const
{
  while (!grove()->governingDtd()) {
    if (grove()->complete()) {
      if (grove()->governingDtd())
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  ptr.assign(new DocumentTypeNode(grove(), grove()->governingDtd()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getDoctypesAndLinktypes(NamedNodeListPtr &ptr) const
{
  while (!grove()->governingDtd()) {
    if (grove()->complete()) {
      if (grove()->governingDtd())
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  ptr.assign(new DoctypesAndLinktypesNamedNodeList(grove()));
  return accessOK;
}

AccessResult SgmlDocumentNode::getMessages(NodeListPtr &ptr) const
{
  while (grove()->messageList() == 0) {
    if (grove()->complete())
      break;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  if (grove()->messageList()) {
    NodePtr tem(new MessageNode(grove(), grove()->messageList()));
    ptr.assign(new SiblingNodeList(tem));
  }
  else
    ptr.assign(new BaseNodeList);
  return accessOK;
}

AccessResult SgmlDocumentNode::getSd(ConstPtr<Sd> &sd,
         ConstPtr<Syntax> &prologSyntax,
         ConstPtr<Syntax> &instanceSyntax) const
{
  while (!grove()->complete()) {
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  grove()->getSd(sd, prologSyntax, instanceSyntax);
  if (!sd.isNull() && !prologSyntax.isNull() && !instanceSyntax.isNull())
    return accessOK;
  return accessNull;
}

AccessResult
SgmlDocumentChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const
{
  ptr.assign(new SgmlDocumentNode(node->grove(), this));
  return accessOK;
}

DocumentTypeNode::DocumentTypeNode(const GroveImpl *grove, const Dtd *dtd)
: BaseNode(grove), dtd_(dtd)
{
}

AccessResult DocumentTypeNode::nextChunkSibling(NodePtr &ptr) const
{
  const Dtd *next = grove()->nextDtd(dtd_);
  if (!next)
    return accessNull;
  ptr.assign(new DocumentTypeNode(grove(), next));
  return accessOK;
}

AccessResult DocumentTypeNode::getName(GroveString &str) const
{
  setString(str, dtd_->name());
  return accessOK;
}

AccessResult DocumentTypeNode::getGoverning(bool &governing) const
{
  governing = dtd_->isBase();
  return accessOK;
}

AccessResult DocumentTypeNode::getGeneralEntities(NamedNodeListPtr &ptr) const
{
  ptr.assign(new GeneralEntitiesNamedNodeList(grove(), dtd_));
  return accessOK;
}

AccessResult DocumentTypeNode::getParameterEntities(NamedNodeListPtr &ptr) const
{
  ptr.assign(new ParameterEntitiesNamedNodeList(grove(), dtd_));
  return accessOK;
}

AccessResult DocumentTypeNode::getNotations(NamedNodeListPtr &ptr) const
{
  ptr.assign(new NotationsNamedNodeList(grove(), dtd_));
  return accessOK;
}

AccessResult DocumentTypeNode::getElementTypes(NamedNodeListPtr &ptr) const
{
  ptr.assign(new ElementTypesNamedNodeList(grove(), dtd_));
  return accessOK;
}

AccessResult DocumentTypeNode::getDefaultEntity(NodePtr &ptr) const
{
  const Entity *entity = dtd_->defaultEntityTemp();
  if (entity == 0)
    return accessNull;
  ptr.assign(new DefaultEntityNode(grove(), entity));
  return accessOK;
}

AccessResult DocumentTypeNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new SgmlDocumentNode(grove(), grove()->root()));
  return accessOK;
}

void DocumentTypeNode::accept(NodeVisitor &visitor)
{
  visitor.documentType(*this);
}

bool DocumentTypeNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool DocumentTypeNode::same2(const DocumentTypeNode *node) const
{
  return dtd_ == node->dtd_;
}

SgmlConstantsNode::SgmlConstantsNode(const GroveImpl *grove)
: BaseNode(grove)
{
}

AccessResult SgmlConstantsNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new SgmlDocumentNode(grove(), grove()->root()));
  return accessOK;
}

void SgmlConstantsNode::accept(NodeVisitor &visitor)
{
  visitor.sgmlConstants(*this);
}

bool SgmlConstantsNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool SgmlConstantsNode::same2(const SgmlConstantsNode *) const
{
  return 1;
}

MessageNode::MessageNode(const GroveImpl *grove, const MessageItem *item)
: BaseNode(grove), item_(item)
{
}

AccessResult MessageNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new SgmlDocumentNode(grove(), grove()->root()));
  return accessOK;
}

AccessResult MessageNode::nextChunkSibling(NodePtr &ptr) const
{
  while (!item_->next()) {
    if (grove()->complete()) {
      if (item_->next())
 break;
      return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  const MessageItem *p = item_->next();
  if (!p)
    return accessNull;
  ptr.assign(new MessageNode(grove(), p));
  return accessOK;
}

AccessResult MessageNode::firstSibling(NodePtr &ptr) const
{
  ptr.assign(new MessageNode(grove(), grove()->messageList()));
  return accessOK;
}

AccessResult MessageNode::siblingsIndex(unsigned long &n) const
{
  n = 0;
  for (const MessageItem *p = grove()->messageList(); p != item_; p = p->next())
    n++;
  return accessOK;
}

void MessageNode::accept(NodeVisitor &visitor)
{
  visitor.message(*this);
}

bool MessageNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool MessageNode::same2(const MessageNode *node) const
{
  return item_ == node->item_;
}

AccessResult MessageNode::getLocation(Location &loc) const
{
  return grove()->proxifyLocation(item_->loc(), loc);
}

AccessResult MessageNode::getText(GroveString &str) const
{
  setString(str, item_->text());
  return accessOK;
}

AccessResult MessageNode::getSeverity(Severity &severity) const
{
  severity = item_->severity();
  return accessOK;
}

AccessResult ElementNode::nextChunkSibling(NodePtr &ptr) const
{
  while (!chunk()->nextSibling) {
    if (!grove()->maybeMoreSiblings(chunk())) {

      if ((const Chunk *)chunk() == grove()->root()->documentElement)
 return accessNotInClass;
      else
        return accessNull;
    }
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  return chunk()->nextSibling->setNodePtrFirst(ptr, this);
}




AccessResult ElementNode::nextChunkAfter(NodePtr &nd) const
{
  const Chunk *p = chunk_->after();
  while (p == grove()->completeLimit())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  return p->setNodePtrFirst(nd, this);
}

AccessResult ElementChunk::getFollowing(const GroveImpl *grove,
     const Chunk *&f,
     unsigned long &n) const
{
  while (!nextSibling) {
    if (!grove->maybeMoreSiblings(this)) {
      if ((const Chunk *)origin == grove->root())
 return accessNotInClass;
      else
        return accessNull;
    }
    if (!grove->waitForMoreNodes())
      return accessTimeout;
  }
  f = nextSibling;
  n = 1;
  return accessOK;
}

AccessResult ElementNode::firstChild(NodePtr &ptr) const
{
  const Chunk *p = chunk()->after();
  while (p == grove()->completeLimit()) {
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  if ((const Chunk *)(p->origin) == chunk())
    return p->setNodePtrFirst(ptr, this);
  return accessNull;
}

AccessResult ElementNode::attributeRef(unsigned long n, NodePtr &ptr) const
{
  const AttributeDefinitionList *defList = chunk()->attDefList();
  if (!defList || n >= defList->size())
    return accessNull;
  ptr.assign(new ElementAttributeAsgnNode(grove(), size_t(n), chunk()));
  return accessOK;
}

AccessResult ElementNode::getAttributes(NamedNodeListPtr &ptr) const
{
  ptr.assign(new ElementAttributesNamedNodeList(grove(), chunk()));
  return accessOK;
}

AccessResult ElementNode::getGi(GroveString &str) const
{
  setString(str, chunk()->type->name());
  return accessOK;
}

bool ElementNode::hasGi(GroveString str) const
{
  const StringC &gi = chunk()->type->name();
  size_t len = gi.size();
  if (len != str.size())
    return 0;
  const SubstTable *subst = grove()->generalSubstTable();
  if (!subst)
    return 0;
  for (size_t i = 0; i < len; i++)
    if ((*subst)[str[i]] != gi[i])
      return 0;
  return 1;
}

AccessResult ElementNode::getId(GroveString &str) const
{
  const StringC *id = chunk()->id();
  if (!id)
    return accessNull;
  setString(str, *id);
  return accessOK;
}

AccessResult ElementNode::elementIndex(unsigned long &i) const
{
  i = chunk()->elementIndex;
  return accessOK;
}

AccessResult ElementNode::getElementType(NodePtr &ptr) const
{
  if (chunk()->elementType() == 0)
    return accessNull;
  ptr.assign(new ElementTypeNode(grove(), *(chunk()->elementType())));
  return accessOK;
}

AccessResult ElementNode::getContent(NodeListPtr &ptr) const
{
  return children(ptr);
}

AccessResult ElementNode::getMustOmitEndTag(bool &b) const
{
  b = chunk()->mustOmitEndTag();
  return accessOK;
}

AccessResult ElementNode::getIncluded(bool &b) const
{
  b = chunk()->included();
  return accessOK;
}

void ElementNode::accept(NodeVisitor &visitor)
{
  visitor.element(*this);
}

ElementChunk *
ElementNode::makeAttElementChunk(GroveImpl &grove,
     const StartElementEvent &event,
     Boolean &hasId)
{
  const AttributeList &atts = event.attributes();
  size_t nAtts = atts.size();
  while (nAtts > 0 && !atts.specified(nAtts - 1) && !atts.current(nAtts - 1))
    nAtts--;
  ElementChunk *chunk;
  void *mem
    = grove.allocChunk(sizeof(AttElementChunk) + nAtts * sizeof(AttributeValue *));
  if (event.included()) {

    AttElementChunk *tem = new (mem) IncludedAttElementChunk(nAtts);
    chunk = tem;
  }
  else
    chunk = new (mem) AttElementChunk(nAtts);
  const AttributeValue **values
    = (const AttributeValue **)(((AttElementChunk *)chunk) + 1);
  const AttributeDefinitionList *defList
    = event.elementType()->attributeDef().pointer();
  unsigned idIndex;
  if (atts.idIndex(idIndex) && atts.specified(idIndex) && atts.value(idIndex))
    hasId = 1;
  else
    hasId = 0;
  for (size_t i = 0; i < nAtts; i++) {
    if (atts.specified(i) || atts.current(i)) {
      grove.storeAttributeValue(atts.valuePointer(i));
      values[i] = atts.value(i);
    }
    else {




      values[i] = defList->def(i)->defaultValue(grove.impliedAttributeValue());
    }
  }
  return chunk;
}

const Chunk *AttElementChunk::after() const
{
  return (const Chunk *)((char *)(this + 1)
    + (sizeof(const AttributeValue *) * nAtts));
}

const AttributeValue *
AttElementChunk::attributeValue(size_t attIndex, const GroveImpl &grove) const
{
  if (attIndex < nAtts)
    return ((const AttributeValue **)(this + 1))[attIndex];
  else
    return ElementChunk::attributeValue(attIndex, grove);
}

const StringC *AttElementChunk::id() const
{
  size_t i = ElementChunk::attDefList()->idIndex();
  if (i == size_t(-1) || i >= nAtts)
    return 0;
  const AttributeValue *av = ((const AttributeValue **)(this + 1))[i];
  if (!av)
    return 0;
  const Text *t = av->text();
  if (!t)
    return 0;
  return &t->string();
}

Boolean AttElementChunk::mustOmitEndTag() const
{
  if (ElementChunk::mustOmitEndTag())
    return 1;
  const AttributeDefinitionList *adl = ElementChunk::attDefList();
  size_t nAtts = adl->size();
  const AttributeValue **atts = (const AttributeValue **)(this + 1);
  for (size_t i = 0; i < nAtts; i++)
    if (adl->def(i)->isConref() && atts[i] && atts[i]->text())
      return 1;
  return 0;
}

const Chunk *ElementChunk::after() const
{
  return this + 1;
}

const AttributeValue *
ElementChunk::attributeValue(size_t attIndex, const GroveImpl &grove) const
{
  return attDefList()->def(attIndex)->defaultValue(grove.impliedAttributeValue());
}

Boolean ElementChunk::mustOmitEndTag() const
{
  return type->definition()->declaredContent() == ElementDefinition::empty;
}

Boolean IncludedElementChunk::included() const
{
  return 1;
}

Boolean IncludedAttElementChunk::included() const
{
  return 1;
}

Boolean ElementChunk::included() const
{
  return 0;
}

AccessResult
ElementChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const
{
  ptr.assign(new ElementNode(node->grove(), this));
  return accessOK;
}

AccessResult
ElementChunk::setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const
{
  if (node->canReuse(ptr))
    ((ElementNode *)node)->reuseFor(this);
  else
    ptr.assign(new ElementNode(node->grove(), this));
  return accessOK;
}

AccessResult
ElementChunk::setNodePtrFirst(NodePtr &ptr, const DataNode *node) const
{
  ptr.assign(new ElementNode(node->grove(), this));
  return accessOK;
}

ElementAttributeOrigin::ElementAttributeOrigin(const ElementChunk *chunk)
: chunk_(chunk)
{
}

const AttributeDefinitionList *ElementAttributeOrigin::attDefList() const
{
  return chunk_->attDefList();
}


const AttributeValue *
ElementAttributeOrigin::attributeValue(size_t attIndex, const GroveImpl &grove) const
{
  return chunk_->attributeValue(attIndex, grove);
}


AccessResult
ElementAttributeOrigin::setNodePtrAttributeOrigin(NodePtr &ptr,
        const BaseNode *node) const
{
  return chunk_->setNodePtrFirst(ptr, node);
}


Node *ElementAttributeOrigin
::makeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex) const
{
  return new ElementCdataAttributeValueNode(grove, value, attIndex, iter,
         charIndex, chunk_);
}


Node *ElementAttributeOrigin
::makeAttributeValueTokenNode(const GroveImpl *grove,
         const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex) const
{
  return new ElementAttributeValueTokenNode(grove, value, attIndex,
         tokenIndex, chunk_);
}

Node *ElementAttributeOrigin
::makeAttributeAsgnNode(const GroveImpl *grove,
   size_t attIndex) const
{
  return new ElementAttributeAsgnNode(grove, attIndex, chunk_);
}

AccessResult ElementAttributeOrigin
::makeAttributeDefNode(const GroveImpl *grove,
                       NodePtr &ptr,
                       size_t attributeDefIdx) const
{
  if (chunk_->elementType() == 0)
    return accessNull;
  ptr.assign(new ElementTypeAttributeDefNode(grove,
                                             *(chunk_->elementType()),
                                             attributeDefIdx));
  return accessOK;
}

Node *ElementAttributeOrigin::makeOriginNode(const GroveImpl *grove, size_t attIndex) const
{
  return makeAttributeAsgnNode(grove, attIndex);
}

const void *ElementAttributeOrigin::attributeOriginId() const
{
  return chunk_;
}

bool DataNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool DataNode::same2(const DataNode *node) const
{
  return chunk_ == node->chunk_ && index_ == node->index_;
}

bool DataNode::chunkContains(const Node &node) const
{
  if (!sameGrove(node))
    return 0;
  return ((const BaseNode &)node).inChunk(this);
}

bool DataNode::inChunk(const DataNode *node) const
{
  return chunk_ == node->chunk_ && index_ >= node->index_;
}

AccessResult DataNode::charChunk(const SdataMapper &, GroveString &str) const
{
  str.assign(chunk()->data() + index_, chunk()->size - index_);
  return accessOK;
}

void DataNode::accept(NodeVisitor &visitor)
{
  visitor.dataChar(*this);
}

unsigned long DataNode::hash() const
{
  return secondHash(ChunkNode::hash() + index_);
}

AccessResult DataNode::getNonSgml(unsigned long &) const
{
  return accessNull;
}

AccessResult DataNode::nextSibling(NodePtr &ptr) const
{
  if (index_ + 1 < chunk()->size) {
    if (canReuse(ptr))
      ((DataNode *)this)->index_ += 1;
    else
      ptr.assign(new DataNode(grove(), chunk(), index_ + 1));
    return accessOK;
  }
  return DataNode::nextChunkSibling(ptr);
}

AccessResult DataNode::nextChunkAfter(NodePtr &nd) const
{
  const Chunk *p = chunk_->after();
  while (p == grove()->completeLimit())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  return p->setNodePtrFirst(nd, this);
}

AccessResult DataNode::followSiblingRef(unsigned long i, NodePtr &ptr) const
{
  if (i < chunk()->size - index_ - 1) {
    if (canReuse(ptr))
      ((DataNode *)this)->index_ += 1 + size_t(i);
    else
      ptr.assign(new DataNode(grove(), chunk(), index_ + size_t(i) + 1));
    return accessOK;
  }
  return ChunkNode::followSiblingRef(i - (chunk()->size - index_ - 1), ptr);
}

AccessResult DataNode::siblingsIndex(unsigned long &i) const
{
  AccessResult ret = ChunkNode::siblingsIndex(i);
  if (ret == accessOK)
    i += index_;
  return ret;
}

AccessResult DataNode::getLocation(Location &loc) const
{
  AccessResult ret = ChunkNode::getLocation(loc);
  if (ret == accessOK)
    loc += index_;
  return ret;
}

AccessResult DataChunk::getFollowing(const GroveImpl *grove,
         const Chunk *&f,
         unsigned long &i) const
{



  const Chunk *p = CharsChunk::after();
  while (p == grove->completeLimit())
    if (!grove->waitForMoreNodes())
      return accessTimeout;
  if (p->origin != origin)
    return accessNull;
  i = size;
  f = p;
  return accessOK;
}

AccessResult DataChunk::setNodePtrFirst(NodePtr &ptr,
     const BaseNode *node) const
{
  ptr.assign(new DataNode(node->grove(), this, 0));
  return accessOK;
}


AccessResult DataChunk::setNodePtrFirst(NodePtr &ptr,
     const ElementNode *node) const
{
  ptr.assign(new DataNode(node->grove(), this, 0));
  return accessOK;
}

AccessResult DataChunk::setNodePtrFirst(NodePtr &ptr, const DataNode *node)
     const
{
  if (node->canReuse(ptr))
    ((DataNode *)node)->reuseFor(this, 0);
  else
    ptr.assign(new DataNode(node->grove(), this, 0));
  return accessOK;
}

AccessResult PiNode::getSystemData(GroveString &str) const
{
  str.assign(chunk()->data(), chunk()->size);
  return accessOK;
}

void PiNode::add(GroveImpl &grove, const PiEvent &event)
{
  const Entity *entity = event.entity();
  if (entity)
    PiEntityNode::add(grove, entity, event.location());
  else {
    grove.setLocOrigin(event.location().origin());
    size_t dataLen = event.dataLength();
    void *mem = grove.allocChunk(CharsChunk::allocSize(dataLen));
    PiChunk *chunk;
    if (grove.haveRootOrigin()) {
      if (grove.root()->documentElement)
 chunk = new (mem) EpilogPiChunk;
      else
 chunk = new (mem) PrologPiChunk;
    }
    else
      chunk = new (mem) PiChunk;
    chunk->size = dataLen;
    chunk->locIndex = event.location().index();
    memcpy(chunk + 1, event.data(), dataLen * sizeof(Char));
    grove.appendSibling(chunk);
  }
}

AccessResult PiChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const
{
  ptr.assign(new PiNode(node->grove(), this));
  return accessOK;
}

AccessResult PrologPiChunk::getFirstSibling(const GroveImpl *grove, const struct Chunk *&p) const
{
  p = grove->root()->prolog;
  return accessOK;
}

AccessResult EpilogPiChunk::getFirstSibling(const GroveImpl *grove, const struct Chunk *&p) const
{
  p = grove->root()->epilog;
  return accessOK;
}

AccessResult SdataNode::charChunk(const SdataMapper &mapper, GroveString &str) const
{
  const StringC &name = chunk()->entity->name();
  const StringC &text = chunk()->entity->asInternalEntity()->string();
  Char *cp = (Char *)&c_;
  if (mapper.sdataMap(GroveString(name.data(), name.size()), GroveString(text.data(), text.size()), *cp)) {
    str.assign(&c_, 1);
    return accessOK;
  }
  else
    return accessNull;
}

AccessResult SdataNode::getSystemData(GroveString &str) const
{
  setString(str, chunk()->entity->asInternalEntity()->string());
  return accessOK;
}

void SdataNode::add(GroveImpl &grove, const SdataEntityEvent &event)
{
  const Location &loc = event.location().origin()->parent();
  grove.setLocOrigin(loc.origin());
  SdataChunk *chunk = new (grove.allocChunk(sizeof(SdataChunk))) SdataChunk;
  chunk->entity = event.entity();
  chunk->locIndex = loc.index();
  grove.appendSibling(chunk);
}

AccessResult SdataChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node)
     const
{
  ptr.assign(new SdataNode(node->grove(), this));
  return accessOK;
}

AccessResult NonSgmlChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node)
     const
{
  ptr.assign(new NonSgmlNode(node->grove(), this));
  return accessOK;
}

AccessResult NonSgmlNode::getNonSgml(unsigned long &n) const
{
  n = chunk()->c;
  return accessOK;
}

AccessResult NonSgmlNode::charChunk(const SdataMapper &, GroveString &) const
{
  return accessNull;
}

void NonSgmlNode::add(GroveImpl &grove, const NonSgmlCharEvent &event)
{
  grove.setLocOrigin(event.location().origin());
  NonSgmlChunk *chunk = new (grove.allocChunk(sizeof(NonSgmlChunk))) NonSgmlChunk;
  chunk->c = event.character();
  chunk->locIndex = event.location().index();
  grove.appendSibling(chunk);
}

void ExternalDataNode::add(GroveImpl &grove, const ExternalDataEntityEvent &event)
{
  grove.setLocOrigin(event.location().origin());
  ExternalDataChunk *chunk = new (grove.allocChunk(sizeof(ExternalDataChunk))) ExternalDataChunk;
  chunk->entity = event.entity();
  chunk->locIndex = event.location().index();
  grove.appendSibling(chunk);
}

AccessResult ExternalDataChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node)
     const
{
  ptr.assign(new ExternalDataNode(node->grove(), this));
  return accessOK;
}

void SubdocNode::add(GroveImpl &grove, const SubdocEntityEvent &event)
{
  grove.setLocOrigin(event.location().origin());
  SubdocChunk *chunk = new (grove.allocChunk(sizeof(SubdocChunk))) SubdocChunk;
  chunk->entity = event.entity();
  chunk->locIndex = event.location().index();
  grove.appendSibling(chunk);
}

AccessResult SubdocChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node)
     const
{
  ptr.assign(new SubdocNode(node->grove(), this));
  return accessOK;
}

AccessResult PiEntityNode::getSystemData(GroveString &str) const
{
  setString(str, chunk()->entity->asInternalEntity()->string());
  return accessOK;
}

void PiEntityNode::add(GroveImpl &grove, const Entity *entity,
         const Location &loc)
{

  grove.setLocOrigin(loc.origin());
  PiEntityChunk *chunk = new (grove.allocChunk(sizeof(PiEntityChunk))) PiEntityChunk;
  chunk->entity = entity;
  chunk->locIndex = loc.index();
  grove.appendSibling(chunk);
}

AccessResult PiEntityChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node)
 const
{
  ptr.assign(new PiEntityNode(node->grove(), this));
  return accessOK;
}

AccessResult EntityRefNode::getEntity(NodePtr &ptr) const
{
  ptr.assign(new EntityNode(grove(), chunk()->entity));
  return accessOK;
}

AccessResult EntityRefNode::getEntityName(GroveString &str) const
{
  setString(str, chunk()->entity->name());
  return accessOK;
}

AttributeAsgnNode::AttributeAsgnNode(const GroveImpl *grove,
         size_t attIndex)
: BaseNode(grove), AttributeDefOrigin(attIndex)
{
}

AccessResult ChunkNode::nextChunkSibling(NodePtr &ptr) const
{


  const Chunk *p = chunk_->after();
  while (p == grove()->completeLimit())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  if (p->origin != chunk_->origin)
    return accessNull;
  return p->setNodePtrFirst(ptr, this);
}

AccessResult ChunkNode::nextChunkAfter(NodePtr &nd) const
{
  const Chunk *p = chunk_->after();
  while (p == grove()->completeLimit())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  return p->setNodePtrFirst(nd, this);
}

AccessResult ChunkNode::firstSibling(NodePtr &ptr) const
{
  const Chunk *first;
  AccessResult ret = chunk_->getFirstSibling(grove(), first);
  if (ret != accessOK)
    return ret;
  return first->setNodePtrFirst(ptr, this);
}

AccessResult ChunkNode::siblingsIndex(unsigned long &i) const
{
  const Chunk *p;
  AccessResult ret = chunk_->getFirstSibling(grove(), p);
  if (ret != accessOK)
    return ret;
  i = 0;
  while (p != chunk_) {
    unsigned long tem;
    if (p->getFollowing(grove(), p, tem) != accessOK)
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 3758, __PRETTY_FUNCTION__), 0)));
    i += tem;
  }
  return accessOK;
}

AccessResult ChunkNode::followSiblingRef(unsigned long i, NodePtr &ptr) const
{
  const Chunk *p;
  unsigned long count;
  AccessResult ret = chunk()->getFollowing(grove(), p, count);
  if (ret != accessOK)
    return ret;
  while (i > 0) {
    const Chunk *lastP = p;
    ret = p->getFollowing(grove(), p, count);
    if (ret == accessOK && count <= i)
      i -= count;
    else if (ret == accessOK || ret == accessNull) {
      lastP->setNodePtrFirst(ptr, this);
      return ptr->followSiblingRef(i - 1, ptr);
    }
    else
      return ret;
  }
  return p->setNodePtrFirst(ptr, this);
}

AccessResult AttributeAsgnNode::getOrigin(NodePtr &ptr) const
{
  return setNodePtrAttributeOrigin(ptr, this);
}

AccessResult AttributeAsgnNode::getName(GroveString &str) const
{
  setString(str, attDefList()->def(attIndex_)->name());
  return accessOK;
}

AccessResult AttributeAsgnNode::getImplied(bool &implied) const
{
  const AttributeValue *value = attributeValue(attIndex_, *grove());
  implied = (value != 0 && value->text() == 0);
  return accessOK;
}

AccessResult AttributeAsgnNode::getValue(NodeListPtr &ptr) const
{
  return children(ptr);
}

AccessResult AttributeAsgnNode::nextChunkSibling(NodePtr &ptr) const
{
  return followSiblingRef(0, ptr);
}

AccessResult AttributeAsgnNode::followSiblingRef(unsigned long i, NodePtr &ptr) const
{

  if (i >= attDefList()->size() - attIndex_ - 1)
    return accessNull;
  if (canReuse(ptr))
    ((AttributeAsgnNode *)this)->attIndex_ += size_t(i) + 1;
  else
    ptr.assign(makeAttributeAsgnNode(grove(), attIndex_ + 1 + size_t(i)));
  return accessOK;
}

AccessResult AttributeAsgnNode::firstSibling(NodePtr &ptr) const
{
  if (canReuse(ptr))
    ((AttributeAsgnNode *)this)->attIndex_ = 0;
  else
    ptr.assign(makeAttributeAsgnNode(grove(), 0));
  return accessOK;
}

AccessResult AttributeAsgnNode::siblingsIndex(unsigned long &i) const
{
  i = attIndex_;
  return accessOK;
}

void AttributeAsgnNode::accept(NodeVisitor &visitor)
{
  visitor.attributeAssignment(*this);
}

AccessResult AttributeAsgnNode::firstChild(NodePtr &ptr) const
{
  const AttributeValue *value = attributeValue(attIndex_, *grove());
  return makeAttributeValueNode(grove(), ptr, value);
}

AccessResult AttributeAsgnNode::children(NodeListPtr &ptr) const
{
  const AttributeValue *value = attributeValue(attIndex_, *grove());
  return makeAttributeValueNodeList(grove(), ptr, value);
}

AccessResult AttributeAsgnNode::getTokenSep(Char &ch) const
{
  const AttributeValue *value = attributeValue(attIndex_, *grove());
  if (!value)
    return accessNull;
  const Text *text;
  const StringC *str;
  if (value->info(text, str) != AttributeValue::tokenized)
    return accessNull;
  const TokenizedAttributeValue *tValue =
    (const TokenizedAttributeValue *)value;
  if (tValue->nTokens() <= 1)
    return accessNull;
  const Char *ptr;
  size_t len;
  tValue->token(0, ptr, len);

  ch = ptr[len];
  return accessOK;
}

AccessResult AttributeAsgnNode::tokens(GroveString &s) const
{
  const AttributeValue *value = attributeValue(attIndex_, *grove());
  if (!value)
    return accessNull;
  const Text *text;
  const StringC *str;
  if (value->info(text, str) != AttributeValue::tokenized)
    return accessNull;
  setString(s, *str);
  return accessOK;
}

AccessResult AttributeAsgnNode::getAttributeDef(NodePtr &ptr) const
{
  return makeAttributeDefNode(grove(), ptr, attIndex_);
}

bool AttributeAsgnNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool AttributeAsgnNode::same2(const AttributeAsgnNode *node)
 const
{
  return (attributeOriginId() == node->attributeOriginId()
   && attIndex_ == node->attIndex_);
}

unsigned long AttributeAsgnNode::hash() const
{
  unsigned long n = (unsigned long)attributeOriginId();
  return secondHash(n + attIndex_);
}

ElementAttributeAsgnNode
::ElementAttributeAsgnNode(const GroveImpl *grove, size_t attIndex,
      const ElementChunk *chunk)
: AttributeAsgnNode(grove, attIndex),
  ElementAttributeOrigin(chunk),
  AttributeDefOrigin(attIndex)
{
}

EntityAttributeAsgnNode
::EntityAttributeAsgnNode(const GroveImpl *grove, size_t attIndex,
     const ExternalDataEntity *entity)
: AttributeAsgnNode(grove, attIndex),
  EntityAttributeOrigin(entity),
  AttributeDefOrigin(attIndex)
{
}

CdataAttributeValueNode
::CdataAttributeValueNode(const GroveImpl *grove,
     const AttributeValue *value,
     size_t attIndex,
     const TextIter &iter,
     size_t charIndex)
: BaseNode(grove),
  AttributeDefOrigin(attIndex),
  value_(value),
  iter_(iter),
  charIndex_(charIndex)
{
}

bool CdataAttributeValueNode::skipBoring(TextIter &iter)
{
  while (iter.valid()) {
    switch (iter.type()) {
    case TextItem::data:
    case TextItem::cdata:
    case TextItem::sdata:
      {
 size_t length;
 iter.chars(length);
 if (length > 0)
   return 1;
      }

    default:
      iter.advance();
      break;
    }
  }
  return 0;
}

AccessResult CdataAttributeValueNode::getParent(NodePtr &ptr) const
{
  ptr.assign(makeOriginNode(grove(), attIndex_));
  return accessOK;
}

AccessResult CdataAttributeValueNode::charChunk(const SdataMapper &mapper, GroveString &str) const
{
  if (iter_.type() == TextItem::sdata) {
    const Entity *entity = iter_.location().origin()->asEntityOrigin()->entity();
    const StringC &name = entity->name();
    const StringC &text = entity->asInternalEntity()->string();
    Char *cp = (Char *)&c_;
    if (mapper.sdataMap(GroveString(name.data(), name.size()), GroveString(text.data(), text.size()), *cp)) {
      str.assign(&c_, 1);
      return accessOK;
    }
    else
      return accessNull;
  }
  size_t len;
  const Char *s = iter_.chars(len);
  str.assign(s + charIndex_, len - charIndex_);
  return accessOK;
}

AccessResult CdataAttributeValueNode::siblingsIndex(unsigned long &n) const
{
  TextIter copy(iter_);
  size_t tem;
  const Char *iterChars = iter_.chars(tem);
  copy.rewind();
  skipBoring(copy);
  n = 0;
  while (copy.chars(tem) != iterChars) {
    if (copy.type() == TextItem::sdata)
      n += 1;
    else
      n += tem;
    copy.advance();
    skipBoring(copy);
  }
  n += charIndex_;
  return accessOK;
}

AccessResult CdataAttributeValueNode::getEntity(NodePtr &ptr) const
{
  if (iter_.type() != TextItem::sdata)
    return accessNotInClass;
  const Entity *entity
    = iter_.location().origin()->asEntityOrigin()->entity();
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

AccessResult CdataAttributeValueNode::getEntityName(GroveString &str) const
{
  if (iter_.type() != TextItem::sdata)
    return accessNotInClass;
  const Entity *entity
    = iter_.location().origin()->asEntityOrigin()->entity();
  setString(str, entity->name());
  return accessOK;
}

AccessResult CdataAttributeValueNode::getSystemData(GroveString &str) const
{
  if (iter_.type() != TextItem::sdata)
    return accessNotInClass;
  size_t len;
  const Char *ptr = iter_.chars(len);
  str.assign(ptr, len);
  return accessOK;
}

AccessResult CdataAttributeValueNode::firstSibling(NodePtr &ptr) const
{
  TextIter copy(iter_);
  copy.rewind();
  skipBoring(copy);
  if (canReuse(ptr)) {
    CdataAttributeValueNode *node = (CdataAttributeValueNode *)this;
    node->iter_ = copy;
    node->charIndex_ = 0;
  }
  else
    ptr.assign(makeCdataAttributeValueNode(grove(), value_, attIndex_, copy));
  return accessOK;
}

AccessResult CdataAttributeValueNode::nextChunkSibling(NodePtr &ptr) const
{
  TextIter copy(iter_);
  copy.advance();
  if (!skipBoring(copy))
    return accessNull;
  if (canReuse(ptr)) {
    CdataAttributeValueNode *node = (CdataAttributeValueNode *)this;
    node->iter_ = copy;
    node->charIndex_ = 0;
  }
  else
    ptr.assign(makeCdataAttributeValueNode(grove(), value_, attIndex_, copy));
  return accessOK;
}

AccessResult CdataAttributeValueNode::nextSibling(NodePtr &ptr) const
{
  if (iter_.type() != TextItem::sdata) {
    size_t length;
    iter_.chars(length);
    if (charIndex_ + 1 < length) {
      if (canReuse(ptr))
 ((CdataAttributeValueNode *)this)->charIndex_ += 1;
      else
 ptr.assign(makeCdataAttributeValueNode(grove(), value_,
            attIndex_, iter_,
            charIndex_ + 1));
      return accessOK;
    }
  }
  return CdataAttributeValueNode::nextChunkSibling(ptr);
}

AccessResult CdataAttributeValueNode::getLocation(Location &loc) const
{
  if (iter_.type() == TextItem::sdata)
    return grove()->proxifyLocation(iter_.location().origin()->parent(), loc);
  else
    return grove()->proxifyLocation(iter_.location(), loc);
}

void CdataAttributeValueNode::accept(NodeVisitor &visitor)
{
  if (iter_.type() == TextItem::sdata)
    visitor.sdata(*this);
  else
    visitor.dataChar(*this);
}

unsigned long CdataAttributeValueNode::hash() const
{
  unsigned long n;
  CdataAttributeValueNode::siblingsIndex(n);
  return secondHash(secondHash((unsigned long)attributeOriginId() + attIndex_) + n);
}

const ClassDef &CdataAttributeValueNode::classDef() const
{
  if (iter_.type() == TextItem::sdata)
    return ClassDef::sdata;
  else
    return ClassDef::dataChar;
}

bool CdataAttributeValueNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool CdataAttributeValueNode::same2(const CdataAttributeValueNode *node)
     const
{
  size_t tem;
  return (attributeOriginId() == node->attributeOriginId()
   && attIndex_ == node->attIndex_
   && charIndex_ == node->charIndex_
   && iter_.chars(tem) == node->iter_.chars(tem));
}

bool CdataAttributeValueNode::chunkContains(const Node &node) const
{
  if (!sameGrove(node))
    return 0;
  return ((const BaseNode &)node).inChunk(this);
}

bool CdataAttributeValueNode::inChunk(const CdataAttributeValueNode *node) const
{
  size_t tem;
  return (attributeOriginId() == node->attributeOriginId()
          && attIndex_ == node->attIndex_
   && iter_.chars(tem) == node->iter_.chars(tem)
   && charIndex_ >= node->charIndex_);
}

ElementCdataAttributeValueNode
::ElementCdataAttributeValueNode(const GroveImpl *grove,
     const AttributeValue *value,
     size_t attIndex,
     const TextIter &iter,
     size_t charIndex,
     const ElementChunk *chunk)
: CdataAttributeValueNode(grove, value, attIndex, iter, charIndex),
  ElementAttributeOrigin(chunk), AttributeDefOrigin(attIndex)
{
}

EntityCdataAttributeValueNode
::EntityCdataAttributeValueNode(const GroveImpl *grove,
    const AttributeValue *value,
    size_t attIndex,
    const TextIter &iter,
    size_t charIndex,
    const ExternalDataEntity *entity)
: CdataAttributeValueNode(grove, value, attIndex, iter, charIndex),
  EntityAttributeOrigin(entity), AttributeDefOrigin(attIndex)
{
}

ElementTypeCdataAttributeValueNode
::ElementTypeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex,
         const ElementType *elementType)
: CdataAttributeValueNode(grove, value, attIndex, iter, charIndex),
  ElementTypeAttributeDefOrigin(elementType), AttributeDefOrigin(attIndex)
{
}

NotationCdataAttributeValueNode
::NotationCdataAttributeValueNode(const GroveImpl *grove,
      const AttributeValue *value,
      size_t attIndex,
      const TextIter &iter,
      size_t charIndex,
      const Notation *notation)
: CdataAttributeValueNode(grove, value, attIndex, iter, charIndex),
  NotationAttributeDefOrigin(notation), AttributeDefOrigin(attIndex)
{
}

AttributeValueTokenNode
::AttributeValueTokenNode(const GroveImpl *grove,
     const TokenizedAttributeValue *value,
     size_t attIndex, size_t tokenIndex)
: BaseNode(grove),
  AttributeDefOrigin(attIndex),
  value_(value),
  tokenIndex_(tokenIndex)
{
}

AccessResult AttributeValueTokenNode::getParent(NodePtr &ptr) const
{
  ptr.assign(makeOriginNode(grove(), attIndex_));
  return accessOK;
}

AccessResult AttributeValueTokenNode::nextChunkSibling(NodePtr &ptr) const
{
  return followSiblingRef(0, ptr);
}

AccessResult AttributeValueTokenNode::followSiblingRef(unsigned long i, NodePtr &ptr) const
{

  if (i >= value_->nTokens() - tokenIndex_ - 1)
    return accessNull;
  if (canReuse(ptr)) {
    AttributeValueTokenNode *node = (AttributeValueTokenNode *)this;
    node->tokenIndex_ += size_t(i) + 1;
  }
  else
    ptr.assign(makeAttributeValueTokenNode(grove(), value_, attIndex_,
        tokenIndex_ + size_t(i) + 1));
  return accessOK;
}

AccessResult AttributeValueTokenNode::firstSibling(NodePtr &ptr) const
{
  if (canReuse(ptr))
    ((AttributeValueTokenNode *)this)->tokenIndex_ = 0;
  else
    ptr.assign(makeAttributeValueTokenNode(grove(), value_, attIndex_, 0));
  return accessOK;
}

AccessResult AttributeValueTokenNode::siblingsIndex(unsigned long &i) const
{
  i = tokenIndex_;
  return accessOK;
}

AccessResult AttributeValueTokenNode::getToken(GroveString &str) const
{
  const Char *ptr;
  size_t len;
  value_->token(tokenIndex_, ptr, len);
  str.assign(ptr, len);
  return accessOK;
}

AccessResult AttributeValueTokenNode::getEntity(NodePtr &ptr) const
{
   if (!attDefList()->def(attIndex_)->isEntity())
    return accessNull;
  StringC token(value_->token(tokenIndex_));
  const Entity *entity = grove()->governingDtd()->lookupEntityTemp(0, token);
  if (!entity) {
    entity = grove()->lookupDefaultedEntity(token);
    if (!entity)
      return accessNull;
  }
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

AccessResult AttributeValueTokenNode::getNotation(NodePtr &ptr) const
{
  if (!attDefList()->def(attIndex_)->isNotation())
    return accessNull;
  StringC token(value_->token(tokenIndex_));
  const Notation *notation = grove()->governingDtd()->lookupNotationTemp(token);
  if (!notation)
    return accessNull;
  ptr.assign(new NotationNode(grove(), notation));
  return accessOK;
}

AccessResult AttributeValueTokenNode::getReferent(NodePtr &ptr) const
{
  if (!attDefList()->def(attIndex_)->isIdref())
    return accessNull;
  StringC token(value_->token(tokenIndex_));
  for (;;) {
    Boolean complete = grove()->complete();
    const ElementChunk *element = grove()->lookupElement(token);
    if (element) {
      ptr.assign(new ElementNode(grove(), element));
      break;
    }
    if (complete)
      return accessNull;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  return accessOK;
}

void AttributeValueTokenNode::accept(NodeVisitor &visitor)
{
  visitor.attributeValueToken(*this);
}

unsigned long AttributeValueTokenNode::hash() const
{
  return secondHash(secondHash((unsigned long)attributeOriginId() + attIndex_) + tokenIndex_);
}

bool AttributeValueTokenNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool AttributeValueTokenNode::same2(const AttributeValueTokenNode *node) const
{
  return (attributeOriginId() == node->attributeOriginId()
   && attIndex_ == node->attIndex_
   && tokenIndex_ == node->tokenIndex_);
}

AccessResult AttributeValueTokenNode::getLocation(Location &loc) const
{
  const ConstPtr<Origin> *originP;
  Index index;
  if (!value_->tokenLocation(tokenIndex_, originP, index)
      && originP->pointer()) {
    loc = Location(new GroveImplProxyOrigin(grove(), originP->pointer()), index);
    return accessOK;
  }
  return accessNull;
}

ElementAttributeValueTokenNode
::ElementAttributeValueTokenNode(const GroveImpl *grove,
     const TokenizedAttributeValue *value,
     size_t attIndex,
     size_t tokenIndex,
     const ElementChunk *chunk)
: AttributeValueTokenNode(grove, value, attIndex, tokenIndex),
  ElementAttributeOrigin(chunk), AttributeDefOrigin(attIndex)
{
}

EntityAttributeValueTokenNode
::EntityAttributeValueTokenNode(const GroveImpl *grove,
    const TokenizedAttributeValue *value,
    size_t attIndex,
    size_t tokenIndex,
    const ExternalDataEntity *entity)
: AttributeValueTokenNode(grove, value, attIndex, tokenIndex),
  EntityAttributeOrigin(entity), AttributeDefOrigin(attIndex)
{
}

ElementTypeAttributeValueTokenNode
::ElementTypeAttributeValueTokenNode(const GroveImpl *grove,
               const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex,
         const ElementType *elementType)
: AttributeValueTokenNode(grove, value, attIndex, tokenIndex),
  ElementTypeAttributeDefOrigin(elementType), AttributeDefOrigin(attIndex)
{
}

NotationAttributeValueTokenNode
::NotationAttributeValueTokenNode(const GroveImpl *grove,
        const TokenizedAttributeValue *value,
      size_t attIndex,
      size_t tokenIndex,
      const Notation *notation)
: AttributeValueTokenNode(grove, value, attIndex, tokenIndex),
  NotationAttributeDefOrigin(notation), AttributeDefOrigin(attIndex)
{
}

EntityNode::EntityNode(const GroveImpl *grove, const Entity *entity)
: EntityNodeBase(grove, entity)
{
}

DefaultEntityNode::DefaultEntityNode(const GroveImpl *grove, const Entity *entity)
: EntityNodeBase(grove, entity)
{
}

AccessResult EntityNode::getOrigin(NodePtr &ptr) const
{
  if (entity_->defaulted() && grove()->lookupDefaultedEntity(entity_->name()))
    ptr.assign(new SgmlDocumentNode(grove(), grove()->root()));
  else
    ptr.assign(new DocumentTypeNode(grove(),
       grove()->lookupDtd(*(entity_->declInDtdNamePointer()))));
  return accessOK;
}

AccessResult DefaultEntityNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new DocumentTypeNode(grove(),
            grove()->lookupDtd(*(entity_->declInDtdNamePointer()))));
  return accessOK;
}

AccessResult EntityNode::getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const
{
  if (entity_->defaulted() && grove()->lookupDefaultedEntity(entity_->name()))
    name = ComponentName::idDefaultedEntities;
  else if (entity_->declType() == EntityDecl::parameterEntity)
    name = ComponentName::idParameterEntities;
  else
    name = ComponentName::idGeneralEntities;
  return accessOK;
}

AccessResult DefaultEntityNode::getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const
{
  name = ComponentName::idDefaultEntity;
  return accessOK;
}

AccessResult EntityNodeBase::getName(GroveString &str) const
{
  setString(str, entity_->name());
  return accessOK;
}

AccessResult EntityNodeBase::getExternalId(NodePtr &ptr) const
{
  const ExternalEntity *x = entity_->asExternalEntity();
  if (!x)
    return accessNull;
  ptr.assign(new EntityExternalIdNode(grove(), x));
  return accessOK;
}

AccessResult EntityNodeBase::getNotation(NodePtr &ptr) const
{
  const ExternalDataEntity *x = entity_->asExternalDataEntity();
  if (!x || !x->notation())
    return accessNull;
  ptr.assign(new NotationNode(grove(), x->notation()));
  return accessOK;
}

AccessResult EntityNodeBase::getNotationName(GroveString &str) const
{
  const ExternalDataEntity *x = entity_->asExternalDataEntity();
  if (!x || !x->notation())
    return accessNull;
  setString(str, x->notation()->name());
  return accessOK;
}

AccessResult EntityNodeBase::getText(GroveString &str) const
{
  const InternalEntity *i = entity_->asInternalEntity();
  if (!i)
    return accessNull;
  setString(str, i->string());
  return accessOK;
}

AccessResult EntityNodeBase::getEntityType(Node::EntityType::Enum &entityType) const
{
  switch (entity_->dataType()) {
  case EntityDecl::sgmlText:
    entityType = EntityType::text;
    break;
  case EntityDecl::pi:
    entityType = EntityType::pi;
    break;
  case EntityDecl::cdata:
    entityType = EntityType::cdata;
    break;
  case EntityDecl::sdata:
    entityType = EntityType::sdata;
    break;
  case EntityDecl::ndata:
    entityType = EntityType::ndata;
    break;
  case EntityDecl::subdoc:
    entityType = EntityType::subdocument;
    break;
  default:
    (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 4498, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult EntityNode::getDefaulted(bool &dflted) const
{
  dflted = entity_->defaulted();
  return accessOK;
}

AccessResult EntityNodeBase::getAttributes(NamedNodeListPtr &ptr) const
{
  const ExternalDataEntity *x = entity_->asExternalDataEntity();
  if (!x)
    return accessNull;
  ptr.assign(new EntityAttributesNamedNodeList(grove(), x));
  return accessOK;
}

AccessResult EntityNodeBase::attributeRef(unsigned long i, NodePtr &ptr) const
{
  const ExternalDataEntity *x = entity_->asExternalDataEntity();
  if (!x || i >= x->attributes().size())
    return accessNull;
  ptr.assign(new EntityAttributeAsgnNode(grove(), size_t(i), x));
  return accessOK;
}

AccessResult EntityNodeBase::getLocation(Location &loc) const
{
  return grove()->proxifyLocation(entity_->defLocation(), loc);
}

bool EntityNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool DefaultEntityNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool EntityNode::same2(const EntityNode *node) const
{
  return entity_ == node->entity_;
}

bool DefaultEntityNode::same2(const DefaultEntityNode *node) const
{
  return entity_ == node->entity_;
}

void EntityNode::accept(NodeVisitor &visitor)
{
  visitor.entity(*this);
}

void DefaultEntityNode::accept(NodeVisitor &visitor)
{
  visitor.defaultEntity(*this);
}

unsigned long EntityNodeBase::hash() const
{
  return (unsigned long)entity_;
}

EntityAttributeOrigin
::EntityAttributeOrigin(const ExternalDataEntity *entity)
: entity_(entity)
{
}

const AttributeDefinitionList *
EntityAttributeOrigin::attDefList() const
{
  return entity_->notation()->attributeDefTemp();
}


const AttributeValue *
EntityAttributeOrigin::attributeValue(size_t attIndex, const GroveImpl &) const
{
  return entity_->attributes().value(attIndex);
}

AccessResult
EntityAttributeOrigin::setNodePtrAttributeOrigin(NodePtr &ptr,
       const BaseNode *node) const
{
  ptr.assign(new EntityNode(node->grove(), entity_));
  return accessOK;
}

Node *EntityAttributeOrigin
::makeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex) const
{
  return new EntityCdataAttributeValueNode(grove, value, attIndex, iter,
        charIndex, entity_);
}


Node *EntityAttributeOrigin
::makeAttributeValueTokenNode(const GroveImpl *grove,
         const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex) const
{
  return new EntityAttributeValueTokenNode(grove, value, attIndex,
        tokenIndex, entity_);
}

Node *EntityAttributeOrigin
::makeAttributeAsgnNode(const GroveImpl *grove,
   size_t attIndex) const
{
  return new EntityAttributeAsgnNode(grove, attIndex, entity_);
}

AccessResult EntityAttributeOrigin
::makeAttributeDefNode(const GroveImpl *grove,
                       NodePtr &ptr,
                       size_t attributeDefIdx) const
{
  if (entity_->notation() == 0)
    return accessNull;
  ptr.assign(new NotationAttributeDefNode(grove,
                                          *(entity_->notation()),
                                          attributeDefIdx));
  return accessOK;
}

Node *EntityAttributeOrigin::makeOriginNode(const GroveImpl *grove, size_t attIndex) const
{
  return makeAttributeAsgnNode(grove, attIndex);
}

const void *EntityAttributeOrigin::attributeOriginId() const
{
  return entity_;
}

DoctypesAndLinktypesNamedNodeList
::DoctypesAndLinktypesNamedNodeList(const GroveImpl *grove)
: BaseNamedNodeList(grove, grove->generalSubstTable())
{
}

NodeListPtr DoctypesAndLinktypesNamedNodeList::nodeList() const
{
  NodePtr tem(new DocumentTypeNode(grove(), grove()->firstDtd()));
  return new SiblingNodeList(tem);
}

AccessResult
DoctypesAndLinktypesNamedNodeList
::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Dtd *dtd = grove()->lookupDtd(str);
  if (!dtd)
    return accessNull;
  ptr.assign(new DocumentTypeNode(grove(), dtd));
  return accessOK;
}

GeneralEntitiesNamedNodeList
::GeneralEntitiesNamedNodeList(const GroveImpl *grove, const Dtd *dtd)
: BaseNamedNodeList(grove, grove->entitySubstTable()), dtd_(dtd)
{
}

NodeListPtr GeneralEntitiesNamedNodeList::nodeList() const
{
  return new EntitiesNodeList(grove(),
         dtd_->generalEntityIter());
}

AccessResult
GeneralEntitiesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Entity *entity
   = dtd_->lookupEntityTemp(0, str);
  if (!entity)
    return accessNull;
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

ParameterEntitiesNamedNodeList
::ParameterEntitiesNamedNodeList(const GroveImpl *grove, const Dtd *dtd)
: BaseNamedNodeList(grove, grove->entitySubstTable()), dtd_(dtd)
{
}

NodeListPtr ParameterEntitiesNamedNodeList::nodeList() const
{
  return new EntitiesNodeList(grove(),
         dtd_->parameterEntityIter());
}

AccessResult
ParameterEntitiesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Entity *entity
   = dtd_->lookupEntityTemp(1, str);
  if (!entity)
    return accessNull;
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

AccessResult
DefaultedEntitiesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Entity *entity
   = grove()->lookupDefaultedEntity(str);
  if (!entity)
    return accessNull;
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

NodeListPtr
DefaultedEntitiesNamedNodeList::nodeList() const
{
  return new EntitiesNodeList(grove(), grove()->defaultedEntityIter());
}

NodeListPtr DocEntitiesNamedNodeList::nodeList() const
{
  return new DocEntitiesNodeList(grove());
}

AccessResult
DocEntitiesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Entity *entity
   = grove()->governingDtd()->lookupEntityTemp(0, str);

  while (!entity) {
    if (!grove()->hasDefaultEntity())
      return accessNull;



    Boolean complete = grove()->complete();
    entity = grove()->lookupDefaultedEntity(str);
    if (entity)
      break;
    if (complete)
      return accessNull;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

AccessResult
ElementsNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  for (;;) {
    Boolean complete = grove()->complete();
    const ElementChunk *element = grove()->lookupElement(str);
    if (element) {
      ptr.assign(new ElementNode(grove(), element));
      break;
    }
    if (complete)
      return accessNull;
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  }
  return accessOK;
}

NodeListPtr ElementsNamedNodeList::nodeList() const
{
  return new ElementsNodeList(grove(), grove()->root()->documentElement);
}

ElementsNodeList::ElementsNodeList(const GroveImpl *grove,
       const Chunk *first)
: grove_(grove), first_(first)
{
}

AccessResult ElementsNodeList::first(NodePtr &ptr) const
{
  const Chunk *p = first_;
  while (p) {
    while (p == grove_->completeLimit()) {
      if (!grove_->waitForMoreNodes())
 return accessTimeout;
    }
    if (p->id()) {
      ((ElementsNodeList *)this)->first_ = p;
      ptr.assign(new ElementNode(grove_, (const ElementChunk *)p));
      return accessOK;
    }
    p = p->after();
  }
  return accessNull;
}

AccessResult ElementsNodeList::chunkRest(NodeListPtr &ptr) const
{
  const Chunk *p = first_;
  while (p) {
    while (p == grove_->completeLimit()) {
      if (!grove_->waitForMoreNodes())
 return accessTimeout;
    }
    if (p->id()) {
      if (canReuse(ptr))
 ((ElementsNodeList *)this)->first_ = p->after();
      else
 ptr.assign(new ElementsNodeList(grove_, p->after()));
      return accessOK;
    }
    p = p->after();
 }
 return accessNull;
}



EntitiesNodeList::EntitiesNodeList(const GroveImpl *grove,
       const Dtd::ConstEntityIter &iter)
: grove_(grove), iter_(iter)
{
}

AccessResult EntitiesNodeList::first(NodePtr &ptr) const
{
  Dtd::ConstEntityIter tem(iter_);
  const Entity *entity = tem.nextTemp();
  if (!entity)
    return accessNull;
  ptr.assign(new EntityNode(grove_, entity));
  return accessOK;
}

AccessResult EntitiesNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (canReuse(ptr)) {
    EntitiesNodeList *list = (EntitiesNodeList *)this;
    if (list->iter_.nextTemp() == 0)
      return accessNull;
    return accessOK;
  }
  Dtd::ConstEntityIter tem(iter_);
  if (tem.nextTemp() == 0)
    return accessNull;
  ptr.assign(new EntitiesNodeList(grove_, tem));
  return accessOK;
}

DocEntitiesNodeList::DocEntitiesNodeList(const GroveImpl *grove)
: EntitiesNodeList(grove, grove->governingDtd()->generalEntityIter())
{
}

AccessResult DocEntitiesNodeList::first(NodePtr &ptr) const
{
  AccessResult ret = EntitiesNodeList::first(ptr);
  if (ret != accessNull || !grove()->hasDefaultEntity())
    return ret;
  while (!grove()->complete())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  Dtd::ConstEntityIter tem(grove()->defaultedEntityIter());
  const Entity *entity = tem.nextTemp();
  if (!entity)
    return accessNull;
  ptr.assign(new EntityNode(grove(), entity));
  return accessOK;
}

AccessResult DocEntitiesNodeList::chunkRest(NodeListPtr &ptr) const
{
  AccessResult ret = EntitiesNodeList::chunkRest(ptr);
  if (ret != accessNull || !grove()->hasDefaultEntity())
    return ret;
  while (!grove()->complete())
    if (!grove()->waitForMoreNodes())
      return accessTimeout;
  Dtd::ConstEntityIter tem(grove()->defaultedEntityIter());
  const Entity *entity = tem.nextTemp();
  if (!entity)
    return accessNull;
  ptr.assign(new EntitiesNodeList(grove(), tem));
  return accessOK;
}

NotationsNamedNodeList
::NotationsNamedNodeList(const GroveImpl *grove, const Dtd *dtd)
: BaseNamedNodeList(grove, grove->generalSubstTable()), dtd_(dtd)
{
}

NodeListPtr NotationsNamedNodeList::nodeList() const
{
  return new NotationsNodeList(grove(),
          dtd_->notationIter());
}

AccessResult
NotationsNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const Notation *notation
   = dtd_->lookupNotationTemp(str);
  if (!notation)
    return accessNull;
  ptr.assign(new NotationNode(grove(), notation));
  return accessOK;
}




NotationsNodeList::NotationsNodeList(const GroveImpl *grove,
         const Dtd::ConstNotationIter &iter)
: grove_(grove), iter_(iter)
{
}

AccessResult NotationsNodeList::first(NodePtr &ptr) const
{
  Dtd::ConstNotationIter tem(iter_);
  const Notation *notation = tem.nextTemp();
  if (!notation)
    return accessNull;
  ptr.assign(new NotationNode(grove_, notation));
  return accessOK;
}

AccessResult NotationsNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (canReuse(ptr)) {
    NotationsNodeList *list = (NotationsNodeList *)this;
    if (list->iter_.next().isNull())
      return accessNull;
    return accessOK;
  }
  Dtd::ConstNotationIter tem(iter_);
  if (tem.nextTemp() == 0)
    return accessNull;
  ptr.assign(new NotationsNodeList(grove_, tem));
  return accessOK;
}

NotationNode::NotationNode(const GroveImpl *grove,
      const Notation *notation)
: BaseNode(grove), notation_(notation)
{
}

AccessResult NotationNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new DocumentTypeNode(grove(),
                   grove()->lookupDtd(*(notation_->declInDtdNamePointer()))));
  return accessOK;
}

AccessResult NotationNode::getName(GroveString &str) const
{
  setString(str, notation_->name());
  return accessOK;
}

AccessResult NotationNode::getExternalId(NodePtr &ptr) const
{
  ptr.assign(new NotationExternalIdNode(grove(), notation_));
  return accessOK;
}

AccessResult NotationNode::getAttributeDefs(NamedNodeListPtr &ptr) const
{
  ptr.assign(new NotationAttributeDefsNamedNodeList(grove(), *notation_));
  return accessOK;
}

AccessResult NotationNode::getLocation(Location &loc) const
{
  return grove()->proxifyLocation(notation_->defLocation(), loc);
}

bool NotationNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool NotationNode::same2(const NotationNode *node) const
{
  return notation_ == node->notation_;
}

void NotationNode::accept(NodeVisitor &visitor)
{
  visitor.notation(*this);
}

unsigned long NotationNode::hash() const
{
  return (unsigned long)notation_;
}

FormalPublicIdNode::FormalPublicIdNode(const GroveImpl *grove, const PublicId *pubid)
: BaseNode(grove), pubid_(pubid)
{
}

AccessResult FormalPublicIdNode::getOwnerType(OwnerType::Enum &type) const
{
  PublicId::OwnerType otp;
  if (!pubid_->getOwnerType(otp))
    return accessNull;
  switch (otp) {
  case PublicId::ISO:
    type = OwnerType::iso;
    break;
  case PublicId::registered:
    type = OwnerType::registered;
    break;
  case PublicId::unregistered:
    type = OwnerType::unregistered;
    break;
  }
  return accessOK;
}

AccessResult FormalPublicIdNode::getOwnerId(GroveString &str) const
{
  if (!pubid_->getOwner(



     owner_))
    return accessNull;
  setString(str, owner_);
  return accessOK;
}

AccessResult FormalPublicIdNode::getTextClass(TextClass::Enum &tc) const
{
  PublicId::TextClass text;
  if (!pubid_->getTextClass(text))
    return accessNull;
  switch (text) {
  case PublicId::CAPACITY:
    tc = TextClass::capacity;
    break;
  case PublicId::CHARSET:
    tc = TextClass::charset;
    break;
  case PublicId::DOCUMENT:
    tc = TextClass::document;
    break;
  case PublicId::DTD:
    tc = TextClass::dtd;
    break;
  case PublicId::ELEMENTS:
    tc = TextClass::elements;
    break;
  case PublicId::ENTITIES:
    tc = TextClass::entities;
    break;
  case PublicId::LPD:
    tc = TextClass::lpd;
    break;
  case PublicId::NONSGML:
    tc = TextClass::nonsgml;
    break;
  case PublicId::NOTATION:
    tc = TextClass::notation;
    break;
  case PublicId::SHORTREF:
    tc = TextClass::shortref;
    break;
  case PublicId::SUBDOC:
    tc = TextClass::subdoc;
    break;
  case PublicId::SYNTAX:
    tc = TextClass::syntax;
    break;
  case PublicId::TEXT:
    tc = TextClass::text;
    break;
  default:
    return accessNull;
  }
  return accessOK;
}

AccessResult FormalPublicIdNode::getUnavailable(bool &u) const
{
  if (!pubid_->getUnavailable(u))
    return accessNull;
  return accessOK;
}

AccessResult FormalPublicIdNode::getTextDescription(GroveString &str) const
{
  if (!pubid_->getDescription(



       desc_))
    return accessNull;
  setString(str, desc_);
  return accessOK;
}

AccessResult FormalPublicIdNode::getTextLanguage(GroveString &str) const
{
  if (!pubid_->getLanguage(



      lang_))
    return accessNull;
  setString(str, lang_);
  return accessOK;
}

AccessResult FormalPublicIdNode::getTextDesignatingSequence(GroveString &str) const
{
  if (!pubid_->getDesignatingSequence(



       dseq_))
    return accessNull;
  setString(str, dseq_);
  return accessOK;
}

AccessResult FormalPublicIdNode::getTextDisplayVersion(GroveString &str) const
{
  if (!pubid_->getDisplayVersion(



      dver_))
    return accessNull;
  setString(str, dver_);
  return accessOK;
}

void FormalPublicIdNode::accept(NodeVisitor &visitor)
{
  visitor.formalPublicId(*this);
}

bool FormalPublicIdNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool FormalPublicIdNode::same2(const FormalPublicIdNode *node) const
{
  return pubid_ == node->pubid_;
}

ExternalIdNode::ExternalIdNode(const GroveImpl *grove)
: BaseNode(grove)
{
}

AccessResult ExternalIdNode::getPublicId(GroveString &str) const
{
  const StringC *s = externalId().publicIdString();
  if (!s)
    return accessNull;
  setString(str, *s);
  return accessOK;
}

AccessResult ExternalIdNode::getFormalPublicId(NodePtr &ptr) const
{
  const PublicId *pubid = externalId().publicId();
  if (!pubid || pubid->type() != PublicId::fpi)
    return accessNull;
  ptr.assign(new FormalPublicIdNode(grove(), pubid));
  return accessOK;
}

AccessResult ExternalIdNode::getSystemId(GroveString &str) const
{
  const StringC *s = externalId().systemIdString();
  if (!s)
    return accessNull;
  setString(str, *s);
  return accessOK;
}

AccessResult ExternalIdNode::getGeneratedSystemId(GroveString &str) const
{
  const StringC &s = externalId().effectiveSystemId();
  if (!s.size())
    return accessNull;
  setString(str, s);
  return accessOK;
}

void ExternalIdNode::accept(NodeVisitor &visitor)
{
  visitor.externalId(*this);
}

bool ExternalIdNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool ExternalIdNode::same2(const ExternalIdNode *node) const
{
  return &externalId() == &node->externalId();
}

EntityExternalIdNode::EntityExternalIdNode(const GroveImpl *grove,
        const ExternalEntity *entity)
: ExternalIdNode(grove), entity_(entity)
{
}

const ExternalId &EntityExternalIdNode::externalId() const
{
  return entity_->externalId();
}

AccessResult EntityExternalIdNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new EntityNode(grove(), entity_));
  return accessOK;
}

unsigned long EntityExternalIdNode::hash() const
{
  return secondHash((unsigned long)entity_);
}

NotationExternalIdNode::NotationExternalIdNode(const GroveImpl *grove,
            const Notation *notation)
: ExternalIdNode(grove), notation_(notation)
{
}

const ExternalId &NotationExternalIdNode::externalId() const
{
  return notation_->externalId();
}

AccessResult NotationExternalIdNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new NotationNode(grove(), notation_));
  return accessOK;
}

unsigned long NotationExternalIdNode::hash() const
{
  return secondHash((unsigned long)notation_);
}

AccessResult ChunkNode::getParent(NodePtr &ptr) const
{
  if (!chunk_->origin)
    return accessNull;



  if ((const Chunk *)chunk()->origin == grove()->root())
    return accessNull;
  chunk_->origin->setNodePtrFirst(ptr, this);
  return accessOK;
}

AccessResult ChunkNode::getTreeRoot(NodePtr &ptr) const
{
  if (chunk()->origin
      && (const Chunk *)chunk()->origin != grove()->root()

      && !grove()->root()->epilog
      && grove()->root()->documentElement)
    return grove()->root()->documentElement->setNodePtrFirst(ptr, this);
  return Node::getTreeRoot(ptr);
}

AccessResult ChunkNode::getOrigin(NodePtr &ptr) const
{
  if (!chunk_->origin)
    return accessNull;
  chunk_->origin->setNodePtrFirst(ptr, this);
  return accessOK;
}

AccessResult ChunkNode::getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const
{
  if ((const Chunk *)chunk()->origin != grove()->root())
    name = ComponentName::idContent;
  else if ((const Chunk *)chunk() == grove()->root()->documentElement)
    name = ComponentName::idDocumentElement;
  else {
    const Chunk *tem;
    if (chunk()->getFirstSibling(grove(), tem) == accessOK && tem == grove()->root()->prolog)
      name = ComponentName::idProlog;
    else
      name = ComponentName::idEpilog;
  }
  return accessOK;
}

unsigned long ChunkNode::hash() const
{
  return (unsigned long)chunk_;
}

bool ChunkNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool ChunkNode::same2(const ChunkNode *node) const
{
  return chunk_ == node->chunk_;
}

BaseNode::~BaseNode()
{
}

void BaseNode::addRef()
{
  ++refCount_;
}

void BaseNode::release()
{
  (static_cast<void> (__builtin_expect (!!(refCount_ != 0), 1) ? 0 : (__assert_fail ("refCount_ != 0", "GroveBuilder.cxx", 5343, __PRETTY_FUNCTION__), 0)));
  if (--refCount_ == 0)
    delete this;
}

unsigned BaseNode::groveIndex() const
{
  return grove_->groveIndex();
}

bool BaseNode::operator==(const Node &node) const
{
  if (!sameGrove(node))
    return 0;
  return same((const BaseNode &)node);
}

bool BaseNode::chunkContains(const Node &node) const
{
  if (!sameGrove(node))
    return 0;
  return same((const BaseNode &)node);
}

bool BaseNode::inChunk(const DataNode *) const
{
  return 0;
}

bool BaseNode::inChunk(const CdataAttributeValueNode *) const
{
  return 0;
}

bool BaseNode::same2(const ChunkNode *) const
{
  return 0;
}

bool BaseNode::same2(const DataNode *) const
{
  return 0;
}

bool BaseNode::same2(const AttributeAsgnNode *) const
{
  return 0;
}

bool BaseNode::same2(const AttributeValueTokenNode *) const
{
  return 0;
}

bool BaseNode::same2(const CdataAttributeValueNode *) const
{
  return 0;
}

bool BaseNode::same2(const EntityNode *) const
{
  return 0;
}

bool BaseNode::same2(const NotationNode *) const
{
  return 0;
}

bool BaseNode::same2(const ExternalIdNode *) const
{
  return 0;
}

bool BaseNode::same2(const FormalPublicIdNode *) const
{
  return 0;
}

bool BaseNode::same2(const DocumentTypeNode *) const
{
  return 0;
}

bool BaseNode::same2(const SgmlConstantsNode *) const
{
  return 0;
}

bool BaseNode::same2(const MessageNode *) const
{
  return 0;
}

bool BaseNode::same2(const ElementTypeNode *) const
{
  return 0;
}

bool BaseNode::same2(const RankStemNode *) const
{
  return 0;
}

bool BaseNode::same2(const ModelGroupNode *) const
{
  return 0;
}

bool BaseNode::same2(const ElementTokenNode *) const
{
  return 0;
}

bool BaseNode::same2(const PcdataTokenNode *) const
{
  return 0;
}

bool BaseNode::same2(const AttributeDefNode *) const
{
  return 0;
}

bool BaseNode::same2(const DefaultEntityNode *) const
{
  return 0;
}

AccessResult BaseNode::nextSibling(NodePtr &ptr) const
{
  return nextChunkSibling(ptr);
}

class NodalPropertyValue : public PropertyValue {
public:
NodePtr nd;
NodeListPtr nl;
NamedNodeListPtr nnl;
void set(const NodePtr &x) { nd = x; }
void set(const NodeListPtr &x) { nl = x; }
void set(const NamedNodeListPtr &x) { nnl = x; }
void set(bool) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5485, __PRETTY_FUNCTION__), 0))); }
void set(GroveChar) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5486, __PRETTY_FUNCTION__), 0))); }
void set(GroveString) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5487, __PRETTY_FUNCTION__), 0))); }
void set(ComponentName::Id) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5488, __PRETTY_FUNCTION__), 0))); }
void set(const GroveStringListPtr &) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5489, __PRETTY_FUNCTION__), 0))); }
void set(const ComponentName::Id *) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5490, __PRETTY_FUNCTION__), 0))); }
void set(long) { (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5491, __PRETTY_FUNCTION__), 0))); }
};

AccessResult BaseNode::nextChunkSibling(NodePtr &ptr) const
{
  NodePtr origin;
  ComponentName::Id id;
  NodalPropertyValue pv;
  SdataMapper sm;
  NodeListPtr nl;
  if (getOrigin(origin) != accessOK
      || getOriginToSubnodeRelPropertyName(id) != accessOK
      || origin->property(id, sm, pv) != accessOK)
    return accessNull;
  if (pv.nd)
    return accessNull;
  nl = pv.nl ? pv.nl : pv.nnl->nodeList();
  for (;;) {
    NodePtr nd;
    if (nl->first(nd) != accessOK
       || nl->rest(nl) != accessOK)
      return accessNull;
    if (*nd == *ptr)
      break;
  }
  if (nl->first(ptr) != accessOK)
    return accessNull;
  return accessOK;
}

AccessResult BaseNode::follow(NodeListPtr &ptr) const
{
  NodePtr nd;
  AccessResult ret = nextSibling(nd);
  switch (ret) {
  case accessOK:
    ptr.assign(new SiblingNodeList(nd));
    break;
  case accessNull:
    ptr.assign(new BaseNodeList);
    ret = accessOK;
    break;
  default:
    break;
  }
  return ret;
}

AccessResult BaseNode::children(NodeListPtr &ptr) const
{
  NodePtr head;
  AccessResult ret = firstChild(head);
  switch (ret) {
  case accessOK:
    ptr.assign(new SiblingNodeList(head));
    break;
  case accessNull:
    ptr.assign(new BaseNodeList);
    ret = accessOK;
    break;
  default:
    break;
  }
  return ret;
}

AccessResult BaseNode::getOrigin(NodePtr &ptr) const
{
  return getParent(ptr);
}

AccessResult BaseNode::getGroveRoot(NodePtr &ptr) const
{
  ptr.assign(new SgmlDocumentNode(grove(), grove()->root()));
  return accessOK;
}

AccessResult BaseNode::getLocation(Location &) const
{
  return accessNull;
}

bool BaseNode::queryInterface(IID iid, const void *&p) const
{
  if (iid == LocNode::iid) {
    const LocNode *ip = this;
    p = ip;
    return 1;
  }
  return 0;
}

AccessResult
ForwardingChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const
{
  if (forwardTo == 0)
    return accessNull;
  (static_cast<void> (__builtin_expect (!!(origin == forwardTo->origin), 1) ? 0 : (__assert_fail ("origin == forwardTo->origin", "GroveBuilder.cxx", 5588, __PRETTY_FUNCTION__), 0)));
  return forwardTo->setNodePtrFirst(ptr, node);
}

AccessResult
ForwardingChunk::getFollowing(const GroveImpl *grove,
                              const Chunk *&p, unsigned long &nNodes)
    const
{
  AccessResult ret = Chunk::getFollowing(grove, p, nNodes);
  if (ret == accessOK)
    nNodes = 0;
  return ret;
}

AccessResult
LocOriginChunk::getFollowing(const GroveImpl *grove,
                             const Chunk *&p, unsigned long &nNodes)
    const
{
  AccessResult ret = Chunk::getFollowing(grove, p, nNodes);
  if (ret == accessOK)
    nNodes = 0;
  return ret;
}

AccessResult LocOriginChunk::setNodePtrFirst(NodePtr &ptr, const BaseNode *node) const
{
  return ((const Chunk *)(this + 1))->setNodePtrFirst(ptr, node);
}

AccessResult LocOriginChunk::setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const
{
  return ((const Chunk *)(this + 1))->setNodePtrFirst(ptr, node);
}

AccessResult LocOriginChunk::setNodePtrFirst(NodePtr &ptr, const DataNode *node) const
{
  return ((const Chunk *)(this + 1))->setNodePtrFirst(ptr, node);
}

const Chunk *LocOriginChunk::after() const
{
  return this + 1;
}

Boolean LocOriginChunk::getLocOrigin(const Origin *&ret) const
{
  ret = locOrigin;
  return 1;
}

AccessResult
Chunk::setNodePtrFirst(NodePtr &ptr, const ElementNode *node) const
{
  return setNodePtrFirst(ptr, (const BaseNode *)node);
}

AccessResult
Chunk::setNodePtrFirst(NodePtr &ptr, const DataNode *node) const
{
  return setNodePtrFirst(ptr, (const BaseNode *)node);
}

const StringC *Chunk::id() const
{
  return 0;
}

AccessResult Chunk::getFollowing(const GroveImpl *grove,
            const Chunk *&f, unsigned long &n) const
{
  const Chunk *p = after();
  while (p == grove->completeLimit())
    if (!grove->waitForMoreNodes())
      return accessTimeout;
  if (p->origin != origin)
    return accessNull;
  n = 1;
  f = p;
  return accessOK;
}

AccessResult Chunk::getFirstSibling(const GroveImpl *grove,
        const Chunk *&p) const
{
  if ((const Chunk *)origin == grove->root())
    return accessNotInClass;
  p = origin->after();
  return accessOK;
}

Boolean Chunk::getLocOrigin(const Origin *&) const
{
  return 0;
}





AccessResult RankStemNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new DocumentTypeNode(grove(),
                 grove()->lookupDtd(rankStem_)));
  return accessOK;
}

AccessResult RankStemNode::getStem(GroveString &str) const
{
  setString(str, rankStem_.name());
  return accessOK;
}

AccessResult RankStemNode::getElementTypes(NodeListPtr &ptr) const
{
  ptr.assign(new RankStemElementTypesNodeList(grove(), rankStem_, iter_));
  return accessOK;
}

bool RankStemNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool RankStemNode::same2(const RankStemNode *node) const
{
  return &rankStem_ == &(node->rankStem());
}

void RankStemNode::accept(NodeVisitor &visitor)
{
  visitor.rankStem(*this);
}

unsigned long RankStemNode::hash() const
{
  return (unsigned long)&rankStem_;
}



AccessResult ElementTypeNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new DocumentTypeNode(grove(),
                 grove()->lookupDtd(elementType_)));
  return accessOK;
}

AccessResult ElementTypeNode::getLocation(Location &loc) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0)
    return accessNull;
  return grove()->proxifyLocation(def->location(), loc);
}

AccessResult ElementTypeNode::getGi(GroveString &str) const
{
  setString(str, elementType_.name());
  return accessOK;
}

AccessResult ElementTypeNode::getModelGroup(NodePtr &ptr) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || def->declaredContent() != ElementDefinition::modelGroup)
    return accessNull;
  ptr.assign(new ModelGroupNode(grove(),
                                elementType_,
                                *(def->compiledModelGroup()->modelGroup())));
  return accessOK;
}

AccessResult ElementTypeNode::getContentType(Node::ContentType::Enum &enumId) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0)
    return accessNull;
  switch (def->declaredContent() ) {
    case ElementDefinition::modelGroup:
      enumId = ContentType::modelgrp;
      break;
    case ElementDefinition::any:
      enumId = ContentType::any;
      break;
    case ElementDefinition::cdata:
      enumId = ContentType::cdata;
      break;
    case ElementDefinition::rcdata:
      enumId = ContentType::rcdata;
      break;
    case ElementDefinition::empty:
      enumId = ContentType::empty;
      break;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 5784, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult ElementTypeNode::getExclusions(GroveStringListPtr &sl) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0
      || (def->declaredContent() != ElementDefinition::modelGroup
          && def->declaredContent() != ElementDefinition::any))
    return accessNull;
  sl.assign(new GroveStringList);
  GroveString str;
  for (size_t i = 0; i < def->nExclusions(); i++ ) {
    setString(str, def->exclusion(i)->name());
    sl->append(str);
  }
  return accessOK;
}

AccessResult ElementTypeNode::getInclusions(GroveStringListPtr &sl) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0
      || (def->declaredContent() != ElementDefinition::modelGroup
          && def->declaredContent() != ElementDefinition::any))
    return accessNull;
  sl.assign(new GroveStringList);
  GroveString str;
  for (size_t i = 0; i < def->nInclusions(); i++ ) {
    setString(str, def->inclusion(i)->name());
    sl->append(str);
  }
  return accessOK;
}

AccessResult ElementTypeNode::getOmitEndTag(bool &f) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || !def->omittedTagSpec())
    return accessNull;
  f = def->canOmitEndTag();
  return accessOK;
}

AccessResult ElementTypeNode::getOmitStartTag(bool &f) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || !def->omittedTagSpec())
    return accessNull;
  f = def->canOmitStartTag();
  return accessOK;
}

AccessResult ElementTypeNode::getRankGroup(GroveStringListPtr &stems) const
{

  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || !def->nRankStems() <= 1)
    return accessNull;
  stems.assign(new GroveStringList);
  GroveString str;
  for (size_t i = 0; i < def->nRankStems(); i++)
  {
    setString(str, def->rankStem(i)->name());
    stems->append(str);
  }
  return accessOK;
}

AccessResult ElementTypeNode::getRankStem(GroveString &str) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || def->nRankStems() != 1)
    return accessNull;
  setString(str, def->rankStem(0)->name());
  return accessOK;
}

AccessResult ElementTypeNode::getRankSuffix(GroveString &str) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0 || def->rankSuffix().size() == 0)
    return accessNull;
  setString(str, def->rankSuffix());
  return accessOK;
}

AccessResult ElementTypeNode::getAttributeDefs(NamedNodeListPtr &ptr) const
{
  ptr.assign(new ElementTypeAttributeDefsNamedNodeList(grove(), elementType_));
  return accessOK;
}

bool ElementTypeNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool ElementTypeNode::same2(const ElementTypeNode *node) const
{
  return &elementType_ == &(node->elementType());
}

void ElementTypeNode::accept(NodeVisitor &visitor)
{
  visitor.elementType(*this);
}

unsigned long ElementTypeNode::hash() const
{
  return (unsigned long)&elementType_;
}



RankStemElementTypesNodeList::RankStemElementTypesNodeList(const GroveImpl *grove,
                                           const RankStem &rankStem,
                                           const Dtd::ConstElementTypeIter &iter)

 : grove_(grove), rankStem_(rankStem), iter_(iter)
{
}

AccessResult RankStemElementTypesNodeList::first(NodePtr &ptr) const
{
  RankStemElementTypesNodeList *list = (RankStemElementTypesNodeList *)this;
  for (;;) {
    Dtd::ConstElementTypeIter tem(iter_);
    const ElementType *elementType = tem.next();
    if (elementType == 0)
      return accessNull;
    if (elementType->isRankedElement()
        && elementType->rankedElementRankStem() == &rankStem_) {
      ptr.assign(new ElementTypeNode(grove_, *elementType));
      return accessOK;
    }
    list->iter_.next();
  }
}

AccessResult RankStemElementTypesNodeList::chunkRest(NodeListPtr &ptr) const
{
  NodePtr tem;
  if (first(tem) == accessNull)
    return accessNull;
  if (canReuse(ptr)) {
    ((RankStemElementTypesNodeList *)this)->iter_.next();
    return first(tem);
  }
  Dtd::ConstElementTypeIter iter(iter_);
  iter.next();
  ptr.assign(new RankStemElementTypesNodeList(grove_, rankStem_, iter));
  return ptr->first(tem);
}



ElementTypesNodeList::ElementTypesNodeList(const GroveImpl *grove,
                                           const Dtd *dtd,
                                           const Dtd::ConstElementTypeIter &elementTypeIter,
                                           const Dtd::ConstRankStemIter &rankStemIter)

 : grove_(grove), dtd_(dtd), elementTypeIter_(elementTypeIter),
rankStemIter_(rankStemIter)
{
}

AccessResult ElementTypesNodeList::first(NodePtr &ptr) const
{
  Dtd::ConstElementTypeIter elementTypeIter(elementTypeIter_);
  const ElementType *elementType = elementTypeIter.next();
  if (elementType) {
    ptr.assign(new ElementTypeNode(grove_, *elementType));
    return accessOK;
  }
  Dtd::ConstRankStemIter rankStemIter(rankStemIter_);
  const RankStem *rankStem = rankStemIter.next();
  if (rankStem) {
    ptr.assign(new RankStemNode(grove_, *rankStem, dtd_->elementTypeIter()));
    return accessOK;
  }
  return accessNull;
}

AccessResult ElementTypesNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (canReuse(ptr)) {
    ElementTypesNodeList *list = (ElementTypesNodeList *)this;
    if (list->elementTypeIter_.next() == 0)
      if (list->rankStemIter_.next() == 0)
        return accessNull;
    return accessOK;
  }
  Dtd::ConstElementTypeIter elementTypeIter(elementTypeIter_);
  Dtd::ConstRankStemIter rankStemIter(rankStemIter_);
  if (elementTypeIter.next() == 0)
    if (rankStemIter.next() == 0)
      return accessNull;
  ptr.assign(new ElementTypesNodeList(grove_, dtd_, elementTypeIter, rankStemIter));
  return accessOK;
}



ElementTypesNamedNodeList::ElementTypesNamedNodeList(const GroveImpl *grove, const Dtd *dtd)
 : BaseNamedNodeList( grove, grove->generalSubstTable() ), dtd_(dtd)
{
}

NodeListPtr ElementTypesNamedNodeList::nodeList() const
{
  return new ElementTypesNodeList(grove(), dtd_, dtd_->elementTypeIter(), dtd_->rankStemIter());
}

AccessResult ElementTypesNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  const ElementType *elementType = dtd_->lookupElementType(str);
  if (elementType) {
    ptr.assign(new ElementTypeNode(grove(), *elementType));
    return accessOK;
  }
  const RankStem *rankStem = dtd_->lookupRankStem(str);
  if (rankStem) {
    ptr.assign(new RankStemNode(grove(), *rankStem, dtd_->elementTypeIter()));
    return accessOK;
  }
  return accessNull;
}



ContentTokenNodeBase::ContentTokenNodeBase(const GroveImpl *grove,
                                           const ElementType &elementType,
                                           ModelGroupNode *parentModelGroupNode)
 : BaseNode(grove), elementType_(elementType), parentModelGroupNode_(parentModelGroupNode)
{
  if (parentModelGroupNode_ != 0)
    parentModelGroupNode_->addRef();
}

ContentTokenNodeBase::~ContentTokenNodeBase()
{
  if (parentModelGroupNode_ != 0)
    parentModelGroupNode_->release();
}

AccessResult ContentTokenNodeBase::getOrigin(NodePtr &ptr) const
{
  if (parentModelGroupNode_ != 0)
    ptr.assign(parentModelGroupNode_);
  else
    ptr.assign(new ElementTypeNode(grove(), elementType_));
  return accessOK;
}

AccessResult ContentTokenNodeBase::getLocation(Location &loc) const
{
  const ElementDefinition *def = elementType_.definition();
  if (def == 0)
    return accessNull;
  return grove()->proxifyLocation(def->location(), loc);
}



AccessResult ElementTokenNode::getGi(GroveString &str) const
{
  (static_cast<void> (__builtin_expect (!!(elementToken_.elementType() != 0), 1) ? 0 : (__assert_fail ("elementToken_.elementType() != 0", "GroveBuilder.cxx", 6053, __PRETTY_FUNCTION__), 0)));
  setString(str, elementToken_.elementType()->name());
  return accessOK;
}

AccessResult ElementTokenNode::getOccurIndicator(Node::OccurIndicator::Enum &occur) const
{
  switch (elementToken_.occurrenceIndicator())
  {
    case ContentToken::opt:
      occur = OccurIndicator::opt;
      break;
    case ContentToken::plus:
      occur = OccurIndicator::plus;
      break;
    case ContentToken::rep:
      occur = OccurIndicator::rep;
      break;
    case ContentToken::none:
      return accessNull;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6074, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

bool ElementTokenNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool ElementTokenNode::same2(const ElementTokenNode *node) const
{
  return &elementToken_ == &(node->elementToken());
}

void ElementTokenNode::accept(NodeVisitor &visitor)
{
  visitor.elementToken(*this);
}

unsigned long ElementTokenNode::hash() const
{
  return (unsigned long)&elementToken_;
}



bool PcdataTokenNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool PcdataTokenNode::same2(const PcdataTokenNode *node) const
{
  return &pcdataToken_ == &(node->pcdataToken());
}

void PcdataTokenNode::accept(NodeVisitor &visitor)
{
  visitor.pcdataToken(*this);
}

unsigned long PcdataTokenNode::hash() const
{
  return (unsigned long)&pcdataToken_;
}



AccessResult ModelGroupNode::getOriginToSubnodeRelPropertyName(ComponentName::Id &name) const
{
  name = parentModelGroupNode_ == 0
          ? ComponentName::idModelGroup
          : ComponentName::idContentTokens;
  return accessOK;
}

AccessResult ModelGroupNode::getConnector(Node::Connector::Enum &conn) const
{
  switch (modelGroup_.connector())
  {
    case ModelGroup::andConnector:
      conn = Connector::and_;
      break;
    case ModelGroup::orConnector:
      conn = Connector::or_;
      break;
    case ModelGroup::seqConnector:
      conn = Connector::seq;
      break;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6145, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult ModelGroupNode::getOccurIndicator(Node::OccurIndicator::Enum &occur) const
{
  switch (modelGroup_.occurrenceIndicator()) {
    case ContentToken::opt:
      occur = OccurIndicator::opt;
      break;
    case ContentToken::plus:
      occur = OccurIndicator::plus;
      break;
    case ContentToken::rep:
      occur = OccurIndicator::rep;
      break;
    case ContentToken::none:
      return accessNull;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6165, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult ModelGroupNode::getContentTokens(NodeListPtr &ptr) const
{
  ptr.assign(new ContentTokenNodeList(grove(), *(ModelGroupNode *)this));
  return accessOK;
}

void ModelGroupNode::makeNode(NodePtr &ptr, unsigned contentTokenIdx)
{
  (static_cast<void> (__builtin_expect (!!(contentTokenIdx < modelGroup_.nMembers()), 1) ? 0 : (__assert_fail ("contentTokenIdx < modelGroup_.nMembers()", "GroveBuilder.cxx", 6178, __PRETTY_FUNCTION__), 0)));
  const ContentToken &contentToken = modelGroup_.member(contentTokenIdx);
  const ModelGroup *asModelGroup = contentToken.asModelGroup();
  if (asModelGroup != 0)
    ptr.assign(new ModelGroupNode(grove(),
                                  elementType_,
                                  *asModelGroup,
                                  this));
  else
  {
    const LeafContentToken *asLeafContentToken = contentToken.asLeafContentToken();
    if (asLeafContentToken != 0)
      if (asLeafContentToken->elementType() != 0)
        ptr.assign(new ElementTokenNode(grove(),
                                        elementType_,
                                        *(const ElementToken*)asLeafContentToken,
                                        this));
      else if (asLeafContentToken->occurrenceIndicator() == ContentToken::rep)
        ptr.assign(new PcdataTokenNode(grove(),
                                       elementType_,
                                       *(const PcdataToken*)asLeafContentToken,
                                       this));
      else
        (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6201, __PRETTY_FUNCTION__), 0)));
  }
}

bool ModelGroupNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool ModelGroupNode::same2(const ModelGroupNode *node) const
{
  return &modelGroup_ == &(node->modelGroup());
}

void ModelGroupNode::accept(NodeVisitor &visitor)
{
  visitor.modelGroup(*this);
}

unsigned long ModelGroupNode::hash() const
{
  return (unsigned long)&modelGroup_;
}



ContentTokenNodeList::ContentTokenNodeList(const GroveImpl *grove,
               ModelGroupNode &modelGroupNode,
                                           unsigned firstTokenIdx)
 : grove_(grove), modelGroupNode_(modelGroupNode), firstTokenIdx_(firstTokenIdx)
{
}

AccessResult ContentTokenNodeList::next()
{
  if (++firstTokenIdx_ >= modelGroupNode_.modelGroup().nMembers())
    return accessNull;
  return accessOK;
}

AccessResult ContentTokenNodeList::first(NodePtr &ptr) const
{
  if (firstTokenIdx_ < modelGroupNode_.modelGroup().nMembers())
    modelGroupNode_.makeNode(ptr, firstTokenIdx_);
  else
    return accessNull;
  return accessOK;
}

AccessResult ContentTokenNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (canReuse(ptr)) {
    ContentTokenNodeList *list = (ContentTokenNodeList *)this;
    return list->next();
  }
  unsigned firstTokenIdx = firstTokenIdx_;
  if (++firstTokenIdx >= modelGroupNode_.modelGroup().nMembers())
    return accessNull;
  ptr.assign(new ContentTokenNodeList(grove_, modelGroupNode_, firstTokenIdx));
  return accessOK;
}



AccessResult
AttributeDefOrigin::makeAttributeValueNode(const GroveImpl *grove,
                                           NodePtr &ptr,
                                           const AttributeValue *value) const
{
  if (value) {
    const Text *text;
    const StringC *str;
    switch (value->info(text, str)) {
    case AttributeValue::tokenized:
        ptr.assign(makeAttributeValueTokenNode(grove,
                                               (const TokenizedAttributeValue *)value,
                                 attIndex_, 0));
      return accessOK;
    case AttributeValue::cdata:
      {
 TextIter iter(*text);
 if (!CdataAttributeValueNode::skipBoring(iter)) {
          ptr.assign(0);
     return accessNull;
        }
 else {
   ptr.assign(makeCdataAttributeValueNode(grove, value,
               attIndex_, iter));
     return accessOK;
        }
      }
    default:
      break;
    }
  }
  return accessNull;
}

AccessResult
AttributeDefOrigin::makeAttributeValueNodeList(const GroveImpl *grove,
                                               NodeListPtr &ptr,
                                               const AttributeValue *value = 0) const
{
  NodePtr nodePtr;
  AccessResult result;
  result = makeAttributeValueNode(grove, nodePtr, value);
  if (result == accessOK)
    ptr.assign(nodePtr.operator->() == 0 ? new BaseNodeList : new SiblingNodeList(nodePtr));
  return result;
}

AccessResult AttributeDefOrigin::makeAttributeDefNode(const GroveImpl *grove,
                                                      NodePtr &ptr,
                                                      const StringC &name) const
{
  if (attDefList() == 0)
    return accessNull;
  for (size_t i = 0; i < attDefList()->size(); i++)
    if (attDefList()->def(i)->name() == name)
    {
      return makeAttributeDefNode(grove, ptr, i);
      break;
    }
  return accessNull;
}



ElementTypeAttributeDefOrigin::ElementTypeAttributeDefOrigin(const ElementType *elementType)
: elementType_(elementType)
{
}

const AttributeDefinitionList *ElementTypeAttributeDefOrigin::attDefList() const
{
  return elementType_->attributeDefTemp();
}

AccessResult ElementTypeAttributeDefOrigin::makeAttributeDefNode(const GroveImpl *grove,
                                                                 NodePtr &ptr,
                                                                 size_t attributeDefIdx) const
{
  ptr.assign(new ElementTypeAttributeDefNode(grove, *elementType_, attributeDefIdx));
  return accessOK;
}

AccessResult ElementTypeAttributeDefOrigin::makeAttributeDefList(const GroveImpl *grove,
                                                                 NodeListPtr &ptr,
                                                                 size_t firstAttDefIdx) const
{
  ptr.assign(new ElementTypeAttributeDefsNodeList(grove,
                                                  *elementType_,
                                                  firstAttDefIdx));
  return accessOK;
}

Node *ElementTypeAttributeDefOrigin
::makeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex) const
{
  return new ElementTypeCdataAttributeValueNode(grove, value, attIndex, iter,
                       charIndex, elementType_);
}


Node *ElementTypeAttributeDefOrigin
::makeAttributeValueTokenNode(const GroveImpl *grove,
         const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex) const
{
  return new ElementTypeAttributeValueTokenNode(grove, value, attIndex,
                                  tokenIndex, elementType_);
}

Node *ElementTypeAttributeDefOrigin::makeOriginNode(const GroveImpl *grove, size_t) const
{
  return new ElementTypeAttributeDefNode(grove, *elementType_, attIndex_);
}

const void *ElementTypeAttributeDefOrigin::attributeOriginId() const
{
  return elementType_;
}



NotationAttributeDefOrigin::NotationAttributeDefOrigin(const Notation *notation)
: notation_(notation)
{
}

const AttributeDefinitionList *NotationAttributeDefOrigin::attDefList() const
{
  return notation_->attributeDefTemp();
}

AccessResult NotationAttributeDefOrigin::makeAttributeDefNode(const GroveImpl *grove,
                                                              NodePtr &ptr,
                                                              size_t attributeDefIdx) const
{
  ptr.assign(new NotationAttributeDefNode(grove, *notation_, attributeDefIdx));
  return accessOK;
}

AccessResult NotationAttributeDefOrigin::makeAttributeDefList(const GroveImpl *grove,
                                                              NodeListPtr &ptr,
                                                              size_t firstAttDefIdx) const
{
  ptr.assign(new NotationAttributeDefsNodeList(grove,
                                               *notation_,
                                               firstAttDefIdx));
  return accessOK;
}

Node *NotationAttributeDefOrigin
::makeCdataAttributeValueNode(const GroveImpl *grove,
         const AttributeValue *value,
         size_t attIndex,
         const TextIter &iter,
         size_t charIndex) const
{
  return new NotationCdataAttributeValueNode(grove, value, attIndex, iter,
                    charIndex, notation_);
}


Node *NotationAttributeDefOrigin
::makeAttributeValueTokenNode(const GroveImpl *grove,
         const TokenizedAttributeValue *value,
         size_t attIndex,
         size_t tokenIndex) const
{
  return new NotationAttributeValueTokenNode(grove, value, attIndex,
                               tokenIndex, notation_);
}

Node *NotationAttributeDefOrigin::makeOriginNode(const GroveImpl *grove, size_t) const
{
  return new NotationAttributeDefNode(grove, *notation_, attIndex_);
}

const void *NotationAttributeDefOrigin::attributeOriginId() const
{
  return notation_;
}



AccessResult AttributeDefNode::getName(GroveString &str) const
{
  setString(str, attDefList()->def(attIndex_)->name());
  return accessOK;
}

AccessResult AttributeDefNode::getDeclValueType(Node::DeclValueType::Enum &dvt) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  switch (desc.declaredValue)
  {
    case AttributeDefinitionDesc::cdata:
      dvt = DeclValueType::cdata;
      break;
    case AttributeDefinitionDesc::name:
      dvt = DeclValueType::name;
      break;
    case AttributeDefinitionDesc::number:
      dvt = DeclValueType::number;
      break;
    case AttributeDefinitionDesc::nmtoken:
      dvt = DeclValueType::nmtoken;
      break;
    case AttributeDefinitionDesc::nutoken:
      dvt = DeclValueType::nutoken;
      break;
    case AttributeDefinitionDesc::entity:
      dvt = DeclValueType::entity;
      break;
    case AttributeDefinitionDesc::idref:
      dvt = DeclValueType::idref;
      break;
    case AttributeDefinitionDesc::names:
      dvt = DeclValueType::names;
      break;
    case AttributeDefinitionDesc::numbers:
      dvt = DeclValueType::numbers;
      break;
    case AttributeDefinitionDesc::nmtokens:
      dvt = DeclValueType::nmtokens;
      break;
    case AttributeDefinitionDesc::nutokens:
      dvt = DeclValueType::nutokens;
      break;
    case AttributeDefinitionDesc::entities:
      dvt = DeclValueType::entities;
      break;
    case AttributeDefinitionDesc::idrefs:
      dvt = DeclValueType::idrefs;
      break;
    case AttributeDefinitionDesc::id:
      dvt = DeclValueType::id;
      break;
    case AttributeDefinitionDesc::notation:
      dvt = DeclValueType::notation;
      break;
    case AttributeDefinitionDesc::nameTokenGroup:
      dvt = DeclValueType::nmtkgrp;
      break;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6514, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult AttributeDefNode::getDefaultValueType(Node::DefaultValueType::Enum &dvt) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  switch (desc.defaultValueType)
  {
    case AttributeDefinitionDesc::required:
      dvt = DefaultValueType::required;
      break;
    case AttributeDefinitionDesc::current:
      dvt = DefaultValueType::current;
      break;
    case AttributeDefinitionDesc::implied:
      dvt = DefaultValueType::implied;
      break;
    case AttributeDefinitionDesc::conref:
      dvt = DefaultValueType::conref;
      break;
    case AttributeDefinitionDesc::defaulted:
      dvt = DefaultValueType::value;
      break;
    case AttributeDefinitionDesc::fixed:
      dvt = DefaultValueType::fixed;
      break;
    default:
      (static_cast<void> (__builtin_expect (!!(0), 1) ? 0 : (__assert_fail ("0", "GroveBuilder.cxx", 6544, __PRETTY_FUNCTION__), 0)));
  }
  return accessOK;
}

AccessResult AttributeDefNode::getTokens(GroveStringListPtr &tokens) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  if (desc.declaredValue != AttributeDefinitionDesc::notation
       && desc.declaredValue != AttributeDefinitionDesc::nameTokenGroup)
    return accessNull;
  tokens.assign(new GroveStringList);
  GroveString str;
  for (size_t i = 0; i < desc.allowedValues.size(); i++)
  {
    setString(str, desc.allowedValues[i]);
    tokens->append(str);
  }
  return accessOK;
}

AccessResult AttributeDefNode::getCurrentAttributeIndex(long &index) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  if (desc.defaultValueType != AttributeDefinitionDesc::current)
    return accessNull;
  index = desc.currentIndex;
  return accessOK;
}

void AttributeDefNode::accept(NodeVisitor &visitor)
{
  visitor.attributeDef(*this);
}

bool AttributeDefNode::same(const BaseNode &node) const
{
  return node.same2(this);
}

bool AttributeDefNode::same2(const AttributeDefNode *node) const
{
  return (attributeOriginId() == node->attributeOriginId()
          && attIndex_ == node->attIndex());
}

unsigned long AttributeDefNode::hash() const
{
  unsigned long n = (unsigned long)attributeOriginId();
  return secondHash(n + attIndex_);
}



AccessResult ElementTypeAttributeDefNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new ElementTypeNode(grove(), *elementType_));
  return accessOK;
}

AccessResult ElementTypeAttributeDefNode::getCurrentGroup(NodeListPtr &ptr) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  if (desc.defaultValueType != AttributeDefinitionDesc::current)
    return accessNull;
  ptr.assign(
   new ElementTypeCurrentGroupAttributeDefsNodeList(grove(),
                                                    grove()->governingDtd()->elementTypeIter(),
                                                    desc.currentIndex));
  return accessOK;
}

AccessResult ElementTypeAttributeDefNode::getLocation(Location &loc) const
{
  const ElementDefinition *def = elementType_->definition();
  if (def == 0)
    return accessNull;
  return grove()->proxifyLocation(def->location(), loc);
}

AccessResult ElementTypeAttributeDefNode::getDefaultValue(NodeListPtr &ptr) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  const AttributeValue *value = desc.defaultValue.pointer();
  return makeAttributeValueNodeList(grove(), ptr, value);
}



AccessResult NotationAttributeDefNode::getOrigin(NodePtr &ptr) const
{
  ptr.assign(new NotationNode(grove(), notation_));
  return accessOK;
}

AccessResult NotationAttributeDefNode::getCurrentGroup(NodeListPtr &ptr) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  if (desc.defaultValueType != AttributeDefinitionDesc::current)
    return accessNull;
  NodePtr nodePtr;
  nodePtr.assign(new NotationAttributeDefNode(grove(), *notation_, attIndex_));
  ptr.assign(new SiblingNodeList(nodePtr));
  return accessOK;
}

AccessResult NotationAttributeDefNode::getLocation(Location &loc) const
{
  return grove()->proxifyLocation(notation_->defLocation(), loc);
}

AccessResult NotationAttributeDefNode::getDefaultValue(NodeListPtr &ptr) const
{
  AttributeDefinitionDesc desc;
  attDefList()->def(attIndex_)->getDesc(desc);
  const AttributeValue *value = desc.defaultValue.pointer();
  return makeAttributeValueNodeList(grove(), ptr, value);
}



bool AttributeDefsNodeList::inList(size_t attIndex) const
{
  if (attDefList() == 0 || attIndex >= attDefList()->size())
    return false;
  return true;
}

AccessResult AttributeDefsNodeList::first(NodePtr &ptr) const
{
  return inList(attIndex_)
          ? makeAttributeDefNode(grove_, ptr, attIndex_)
          : accessNull;
}

AccessResult AttributeDefsNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (canReuse(ptr)) {
    AttributeDefsNodeList *list = (AttributeDefsNodeList *)this;
    if (list->inList(list->attIndex_)) {
      ++(list->attIndex_);
      return accessOK;
    }
    return accessNull;
  }
  return inList(attIndex_)
          ? makeAttributeDefList(grove_, ptr, attIndex_+1)
          : accessNull;
}



NodeListPtr AttributeDefsNamedNodeList::nodeList() const
{
  NodeListPtr ptr;
  makeAttributeDefList(grove(), ptr, 0);
  return ptr;
}

AccessResult AttributeDefsNamedNodeList::namedNodeU(const StringC &str, NodePtr &ptr) const
{
  return makeAttributeDefNode(grove(), ptr, str);
}



ElementTypeCurrentGroupAttributeDefsNodeList
 ::ElementTypeCurrentGroupAttributeDefsNodeList(const GroveImpl *grove,
                                                const Dtd::ConstElementTypeIter &iter,
                                                size_t currentGroupIndex)
   : grove_(grove), iter_(iter), currentGroupIndex_(currentGroupIndex), attIndex_(0)
{
  elementType_ = iter_.next();
  next(false);
}

bool ElementTypeCurrentGroupAttributeDefsNodeList::next(Dtd::ConstElementTypeIter &iter,
                                                        const ElementType *&elementType,
                                                        size_t &attIndex,
                                                        bool incrementFirst) const
{
  if (incrementFirst)
    attIndex++;
  while (elementType != 0) {
    if (attIndex >= elementType->attributeDefTemp()->size() ) {
      do {
        elementType = iter.next();
      } while(elementType != 0 && !elementType->attributeDefTemp()->anyCurrent());
      attIndex = 0;
    }
    else {
      if (elementType->attributeDefTemp()->def(attIndex)->isCurrent()) {
        AttributeDefinitionDesc desc;
        elementType->attributeDefTemp()->def(attIndex)->getDesc(desc);
        if (desc.currentIndex == currentGroupIndex_)
          break;
      }
      attIndex++;
    }
  }
  return elementType != 0 ? true : false;
}

AccessResult ElementTypeCurrentGroupAttributeDefsNodeList::first(NodePtr &ptr) const
{
  if (elementType_ == 0)
    return accessNull;
  ptr.assign(new ElementTypeAttributeDefNode(grove_,
                                             *elementType_,
                                             attIndex_));
  return accessOK;
}

AccessResult ElementTypeCurrentGroupAttributeDefsNodeList::chunkRest(NodeListPtr &ptr) const
{
  if (elementType_ == 0)
    return accessNull;
  if (canReuse(ptr)) {
    ElementTypeCurrentGroupAttributeDefsNodeList *list
     = (ElementTypeCurrentGroupAttributeDefsNodeList *)this;
    list->next();
    return accessOK;
  } else {
    Dtd::ConstElementTypeIter iter(iter_);
    const ElementType *elementType = elementType_;
    size_t attIndex = attIndex_;
    next(iter, elementType, attIndex);
    ptr.assign(new ElementTypeCurrentGroupAttributeDefsNodeList(grove_,
                                                                iter,
                                                                elementType,
                                                                attIndex,
                                                                currentGroupIndex_));
  }
  return accessOK;
}




}


# 1 "grove_inst.cxx" 1

namespace OpenSP {




}




# 1 "../config.h" 1






# 1 "/usr/include/OpenSP/config.h" 1 3 4
# 8 "../config.h" 2
# 13 "grove_inst.cxx" 2
# 6791 "GroveBuilder.cxx" 2
