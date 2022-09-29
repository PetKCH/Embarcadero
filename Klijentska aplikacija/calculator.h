// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://www.dneonline.com/calculator.asmx?wsdl
//  >Import : http://www.dneonline.com/calculator.asmx?wsdl>0
// Encoding : utf-8
// Codegen  : [wfUseSettersAndGetters+]
// Version  : 1.0
// (10.6.2022. 20:48:49 - - $Rev: 108085 $)
// ************************************************************************ //

#ifndef   calculatorH
#define   calculatorH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <Soap.SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif
#if !defined(IS_REF)
#define IS_REF 0x0080
#endif


namespace NS_calculator {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:int             - "http://www.w3.org/2001/XMLSchema"[Gbl]



// ************************************************************************ //
// Namespace : http://tempuri.org/
// soapAction: http://tempuri.org/%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : document
// use       : literal
// binding   : CalculatorSoap
// service   : Calculator
// port      : CalculatorSoap
// URL       : http://www.dneonline.com/calculator.asmx
// ************************************************************************ //
__interface INTERFACE_UUID("{42FA0556-A79E-45A1-65B8-EDB9F7C6702F}") CalculatorSoap : public IInvokable
{
public:
  virtual int             Add(const int intA, const int intB) = 0; 
  virtual int             Subtract(const int intA, const int intB) = 0; 
  virtual int             Multiply(const int intA, const int intB) = 0; 
  virtual int             Divide(const int intA, const int intB) = 0; 
};
typedef DelphiInterface<CalculatorSoap> _di_CalculatorSoap;

_di_CalculatorSoap GetCalculatorSoap(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_calculator

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_calculator;
#endif



#endif // calculatorH
