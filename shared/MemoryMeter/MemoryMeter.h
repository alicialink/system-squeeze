// MemoryMeter.h
//
// On ATMega328P, this will create a string that has the free memory.
//
// This has one function: memoryFree() it simply returns an integer of
// free RAM space.
//
// memoryFree() function from Arduino Cookbook, section 17.2.
// Except that I put in the {} in the if()...else, because the original
// version didn't.
//
// It will get a warning because the externs are not defined until
// the sketch is compiled.

int memoryFree();
