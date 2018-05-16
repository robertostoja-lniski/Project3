#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PulseTest
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <exception>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../src/Reader.cpp"
#include "../include/Reader.h"
#include "../include/Operator.h"
#include "../src/Operator.cpp"
#include "../include/Client.h"
#include "../src/Client.cpp"
#include "../include/SeniorOperator.h"
#include "../include/contractDate.h"
#include "../include/contractDateBase.h"

using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(VariantsSuite)
struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer ) 
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};

BOOST_AUTO_TEST_CASE(simplePass){}

 
BOOST_AUTO_TEST_CASE(budgetSetupIllegalmsg )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);
    teleOperator.setBudget(-1000);
    
    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "budget cannot be lower that zero - changed to zero\n" ) );
}

BOOST_AUTO_TEST_CASE(setAllBillsIllegalmsg )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);
    teleOperator.setAllBills(-532);
    
    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "all bills cannot be lower that zero - changed to zero\n" ) );
}
BOOST_AUTO_TEST_CASE(printBudgetTest )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Operator teleOperator(0);
    teleOperator.setBudget(500);
    teleOperator.printBudget();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "\nOperator has a budget of 500\n" ) );
}
BOOST_AUTO_TEST_CASE(printAllBillsTest )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Operator teleOperator(0);
    teleOperator.setAllBills(532);
    teleOperator.printAllBills();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "All Bills equals 532\n" ) );
}
BOOST_AUTO_TEST_CASE(printNegativeBalance )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Operator teleOperator(0);
    teleOperator.printBalanceMessage(-100);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Operator balance is negative\n" ) );
} 
BOOST_AUTO_TEST_CASE(printNullBalance)
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Operator teleOperator(0);
    teleOperator.printBalanceMessage(0);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Operator balance is zero!\n" ) );
}
BOOST_AUTO_TEST_CASE(printPositiveBalance )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.printBalanceMessage(1500);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Operator balance is positive\n" ) );
}

BOOST_AUTO_TEST_CASE(printClientListHeadersEmptyVec )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.printClientListHeaders();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Clients undefined. \n" ) );
}
BOOST_AUTO_TEST_CASE(sumAllBliisEmptyVec )
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.sumAllBills();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Customer vec is empty\n" ) );
}
BOOST_AUTO_TEST_CASE(printClientList)
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.printClientList();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Clients undefined. \n" ) );
}
BOOST_AUTO_TEST_CASE(getClientFromEmptyVector)
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.getClientAt(10000);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Vector is empty!\n" ) );
}
BOOST_AUTO_TEST_CASE(getClientAtNegativeIndex)
{
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    Operator teleOperator(0);

    teleOperator.getClientAt(-30232);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Index cannot be lower than zero!\n" ) ); 
}
BOOST_AUTO_TEST_CASE(budgetSetup){

    Operator teleOperator(0);
    teleOperator.setBudget(5);
    
    BOOST_CHECK(5 == teleOperator.getBudget());
      
}
BOOST_AUTO_TEST_CASE(bugetSetupToZero){

    Operator teleOperator(0);
    teleOperator.setBudget(0);
    
    BOOST_CHECK(0 == teleOperator.getBudget());
      
}
BOOST_AUTO_TEST_CASE(budgetSetupIllegal){

    Operator teleOperator(0);
    teleOperator.setBudget(-1000);
    
    BOOST_CHECK(0 == teleOperator.getBudget());
      
}

BOOST_AUTO_TEST_CASE(secondConstructor){

    Operator teleOperator(150);
    
    BOOST_CHECK(150 == teleOperator.getAllBills());
      
}
BOOST_AUTO_TEST_CASE(setAllBillsTest){

    Operator teleOperator(0);
    teleOperator.setAllBills(1238);
    
    BOOST_CHECK(1238 == teleOperator.getAllBills());
      
}
BOOST_AUTO_TEST_CASE(setMethodsComparison){

    Operator teleOperator(0);
    teleOperator.setBudget(5531);
    teleOperator.setAllBills(99);
    
    BOOST_CHECK(teleOperator.getAllBills() != teleOperator.getBudget());
      
}
BOOST_AUTO_TEST_CASE(setAllBillsWithIllegalArgument){

    Operator teleOperator(0);
    teleOperator.setAllBills(-1000);
    
    BOOST_CHECK(0 == teleOperator.getAllBills());
      
}
BOOST_AUTO_TEST_CASE(setMethodsIllegalArgComparison){

    Operator teleOperator(10);
    teleOperator.setBudget(-3939);
    teleOperator.setAllBills(-3030303);

    BOOST_CHECK(teleOperator.getAllBills() == teleOperator.getBudget());
      
}

BOOST_AUTO_TEST_CASE(checkFailure1){

    Operator teleOperator(0);
    teleOperator.setBudget(5);
    
    BOOST_CHECK(5 == teleOperator.getBudget());
      
}
BOOST_AUTO_TEST_CASE(checkFailure2){

    Operator teleOperator(0);
    teleOperator.setBudget(5);
    
    BOOST_CHECK(5 == teleOperator.getBudget());
      
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(ClientVectorInitialised)
struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer ) 
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};

BOOST_AUTO_TEST_CASE(allBillsCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff);
    teleOperator.sumAllBills();
    double bills = teleOperator.getAllBills();
    BOOST_CHECK( bills == 133);
}
BOOST_AUTO_TEST_CASE(SurnameCheck) {

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);

    std::string surname = teleOperator.getClientAt(0).getSurname(); 
    BOOST_CHECK( surname == "Smith");
}
BOOST_AUTO_TEST_CASE(clientIdCheck) {

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);

    int number = teleOperator.getClientAt(3).getNumber(); 
    BOOST_CHECK( number == 4);
}
BOOST_AUTO_TEST_CASE(nSmsCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);

    int nSms = teleOperator.getClientAt(1).getSentMessages();
    BOOST_CHECK( nSms == 6);
}
BOOST_AUTO_TEST_CASE(nMinutesCheck) {

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);
 
    int nMinutes = teleOperator.getClientAt(1).getCalledMinutes();
    BOOST_CHECK( nMinutes == 15);
} 
BOOST_AUTO_TEST_CASE(dateStringCheck) {
   
    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);

    std::cout << *teleOperator.getClientAt(3).getDatePtr();
    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "17 \tSep \t2016" ) );
}
BOOST_AUTO_TEST_CASE(dateIntCheck) {

    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    reader.readDataToClass(teleOperator, &economicTariff);

    std::cout << *teleOperator.getClientAt(2).getDatePtr();
    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "28 \t5 \t2017" ) );
} 
BOOST_AUTO_TEST_CASE(addCustomerCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff);

    Client client("","",0,0,0,0,NULL,NULL,NULL);
    int prevSize = teleOperator.getVecSize();
    teleOperator.addClient(client);
    int nextSize = teleOperator.getVecSize();
    BOOST_CHECK( nextSize = prevSize+1);
}
BOOST_AUTO_TEST_CASE(removeCustomerCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff);

    int prevSize = teleOperator.getVecSize();
    teleOperator.removeClient(0);
    int nextSize = teleOperator.getVecSize();
    BOOST_CHECK( nextSize = prevSize-1);
}
BOOST_AUTO_TEST_CASE(removeCustomerFromEmptyCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff); 
    teleOperator.removeAllClients();
    int prevSize = teleOperator.getVecSize();
    teleOperator.removeClient(0);
    int nextSize = teleOperator.getVecSize();
    BOOST_CHECK( nextSize == 0);
}

BOOST_AUTO_TEST_CASE(removeCustomerFromEmptyCheckMesage) {

    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );
    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff); 
    teleOperator.removeAllClients();
    teleOperator.removeClient(0);

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "Tried to remove client from an empty vector\n" ) );
}

BOOST_AUTO_TEST_CASE(removeAllCheck) {

    
    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(100);
    reader.readDataToClass(teleOperator, &economicTariff);

    teleOperator.removeAllClients();
    int nextSize = teleOperator.getVecSize();
    BOOST_CHECK(nextSize == 0);
}
BOOST_AUTO_TEST_CASE(positiveCheck) {

    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(135);

    reader.readDataToClass(teleOperator, &economicTariff);

    teleOperator.sumAllBills();
    teleOperator.printBalance();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "\nOperator has a budget of 135\nAll Bills equals 133\nOperator balance is positive\n" ) );
} 
BOOST_AUTO_TEST_CASE(zeroCheck) {

    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(133);

    reader.readDataToClass(teleOperator, &economicTariff);

    teleOperator.sumAllBills();
    teleOperator.printBalance();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "\nOperator has a budget of 133\nAll Bills equals 133\nOperator balance is zero!\n" ) );
}
BOOST_AUTO_TEST_CASE(negativeCheck) {

    output_test_stream output;
    cout_redirect guard( output.rdbuf( ) );

    Reader reader;
    TelecommunicationTariff<int> economicTariff(1, 5, 0.1, 0.4, 20);

    Operator teleOperator(0);
    teleOperator.setBudget(132);

    reader.readDataToClass(teleOperator, &economicTariff);

    teleOperator.sumAllBills();
    teleOperator.printBalance();

    BOOST_CHECK( !output.is_empty( false ) );
    BOOST_CHECK( output.is_equal( "\nOperator has a budget of 132\nAll Bills equals 133\nOperator balance is negative\n" ) );
} 

BOOST_AUTO_TEST_SUITE_END()    

