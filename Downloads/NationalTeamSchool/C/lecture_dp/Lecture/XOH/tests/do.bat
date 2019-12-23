@echo on
@echo *************************************************
@echo Testov primer %1%3
@echo Programata izvejda:
@%2 < %2.%1%3.in
@echo Vernia rezultat e:
@type %2.%1%3.sol
%2 <%2.%1%3.in >%2.user.sol
@echo ima li suvpadenie vuv file compare
fc %2.%1%3.sol %2.user.sol
@echo off
pause