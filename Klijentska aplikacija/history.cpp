
// ***************************************** //
//                                         
//            XML Data Binding             
//                                         
//         Generated on: 15/06/2022 12:27:37 
//       Generated from: history.xml       
//   Settings stored in: history.xdb       
//                                         
// ***************************************** //

#include <System.hpp>
#pragma hdrstop

#include "history.h"


// Global Functions 

_di_IXMLeventsType __fastcall Getevents(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLeventsType) Doc->GetDocBinding("events", __classid(TXMLeventsType), TargetNamespace);
};

_di_IXMLeventsType __fastcall Getevents(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getevents(DocIntf);
};

_di_IXMLeventsType __fastcall Loadevents(const System::UnicodeString& FileName)
{
  return (_di_IXMLeventsType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("events", __classid(TXMLeventsType), TargetNamespace);
};

_di_IXMLeventsType __fastcall  Newevents()
{
  return (_di_IXMLeventsType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("events", __classid(TXMLeventsType), TargetNamespace);
};

// TXMLeventsType 

void __fastcall TXMLeventsType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("event"), __classid(TXMLeventType));
  ItemTag = "event";
  ItemInterface = __uuidof(IXMLeventType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLeventType __fastcall TXMLeventsType::Get_event(int Index)
{
  return (_di_IXMLeventType) List->Nodes[Index];
};

_di_IXMLeventType __fastcall TXMLeventsType::Add()
{
  return (_di_IXMLeventType) AddItem(-1);
};

_di_IXMLeventType __fastcall TXMLeventsType::Insert(const int Index)
{
  return (_di_IXMLeventType) AddItem(Index);
};

// TXMLeventType 

System::UnicodeString __fastcall TXMLeventType::Get_username()
{
  return GetChildNodes()->Nodes[System::UnicodeString("username")]->Text;
};

void __fastcall TXMLeventType::Set_username(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("username")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLeventType::Get_timestamp()
{
  return GetChildNodes()->Nodes[System::UnicodeString("timestamp")]->Text;
};

void __fastcall TXMLeventType::Set_timestamp(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("timestamp")]->NodeValue = Value;
};
