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

#include <System.hpp>
#pragma hdrstop

#include "calculator.h"



namespace NS_calculator {

_di_CalculatorSoap GetCalculatorSoap(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://www.dneonline.com/calculator.asmx?wsdl";
  static const char* defURL = "http://www.dneonline.com/calculator.asmx";
  static const char* defSvc = "Calculator";
  static const char* defPrt = "CalculatorSoap";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  Soaphttpclient::THTTPRIO* rio = HTTPRIO ? HTTPRIO : new Soaphttpclient::THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_CalculatorSoap service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* CalculatorSoap */
  InvRegistry()->RegisterInterface(__delphirtti(CalculatorSoap), L"http://tempuri.org/", L"utf-8");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(CalculatorSoap), L"http://tempuri.org/%operationName%");
  InvRegistry()->RegisterInvokeOptions(__delphirtti(CalculatorSoap), ioDocument);
  /* CalculatorSoap.Add */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CalculatorSoap), "Add", "",
                                    "[ReturnName='AddResult']" );
  /* CalculatorSoap.Subtract */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CalculatorSoap), "Subtract", "",
                                    "[ReturnName='SubtractResult']" );
  /* CalculatorSoap.Multiply */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CalculatorSoap), "Multiply", "",
                                    "[ReturnName='MultiplyResult']" );
  /* CalculatorSoap.Divide */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CalculatorSoap), "Divide", "",
                                    "[ReturnName='DivideResult']" );
}
#pragma startup RegTypes 32

};     // NS_calculator

