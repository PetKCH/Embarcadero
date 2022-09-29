
// ***************************************** //
//                                         
//            XML Data Binding             
//                                         
//         Generated on: 15/06/2022 12:27:37 
//       Generated from: history.xml       
//   Settings stored in: history.xdb       
//                                         
// ***************************************** //

#ifndef   historyH
#define   historyH

#include <System.hpp>
#include <System.Variants.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLeventsType;
typedef System::DelphiInterface<IXMLeventsType> _di_IXMLeventsType;
__interface IXMLeventType;
typedef System::DelphiInterface<IXMLeventType> _di_IXMLeventType;

// IXMLeventsType 

__interface INTERFACE_UUID("{4F1DCE28-60C0-4EEB-9780-33898CCDB03E}") IXMLeventsType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLeventType __fastcall Get_event(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLeventType __fastcall Add() = 0;
  virtual _di_IXMLeventType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLeventType event[int Index] = { read=Get_event };/* default */
};

// IXMLeventType 

__interface INTERFACE_UUID("{D8BDE8A8-B8AD-4403-81F0-94D6F303AAE7}") IXMLeventType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_username() = 0;
  virtual System::UnicodeString __fastcall Get_timestamp() = 0;
  virtual void __fastcall Set_username(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_timestamp(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString username = { read=Get_username, write=Set_username };
  __property System::UnicodeString timestamp = { read=Get_timestamp, write=Set_timestamp };
};

// Forward Decls 

class TXMLeventsType;
class TXMLeventType;

// TXMLeventsType 

class TXMLeventsType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLeventsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLeventsType 
  virtual _di_IXMLeventType __fastcall Get_event(int Index);
  virtual _di_IXMLeventType __fastcall Add();
  virtual _di_IXMLeventType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLeventType 

class TXMLeventType : public Xml::Xmldoc::TXMLNode, public IXMLeventType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLeventType 
  virtual System::UnicodeString __fastcall Get_username();
  virtual System::UnicodeString __fastcall Get_timestamp();
  virtual void __fastcall Set_username(System::UnicodeString Value);
  virtual void __fastcall Set_timestamp(System::UnicodeString Value);
};

// Global Functions 

_di_IXMLeventsType __fastcall Getevents(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLeventsType __fastcall Getevents(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLeventsType __fastcall Loadevents(const System::UnicodeString& FileName);
_di_IXMLeventsType __fastcall  Newevents();

#define TargetNamespace ""

#endif