/**
 * @file time.h
 *
 * @copyright 208 3081 Staff, All rights reserved.
 * based off of Date class
 */

#ifndef TIME_H_
#define TIME_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>     // Used for absolute value (abs)
#include <math.h>
#include <iostream>
#include <string>
#include <cstdio>    // Used for sprintf, converting int to string
#include <iomanip>
#include <ctime>     // Used to get current time
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a time
 * It is stored as hours, minutes, and seconds. Typically displayed as hh:mm:ss.
 */
 
class Clock {
 public:
  /**
    * Constructors
  **/
  Clock(void); //Current time
  Clock(int hourse, int minutes, int seconds);

  /**
    * Constructor
    * param [in] seconds: The number of seconds that have elapsed since 00:00:00, modulo 24 hours
    *
    * Converts time given to this Clock format and stored.
    **/
  Clock(int seconds);
  
  /**
    * Adding seconds to the time.
    * param [in] rhs: right hand side of this+rhs
    * param [out] New Clock object representing the time which is "seconds" number of seconds after the time currently stored, loops back around after 23:59:59
    **/
  Clock operator+(int seconds) const;

  /**
    * Subtracting seconds from the time.
    * param [in] rhs: right hand side of this+rhs
    * param [out] New Clock object representing the time which is "seconds" number of seconds before the time currently stored, loops back around before 00:00:00
    **/
  Clock operator-(int seconds) const;
  
  /**
    * Number of seconds between this time and the time provided
    * param [in] rhs: left hand side of this-rhs
    * param [out] number of secodns between the two times
    **/
  int SecondsBetween(const Clock& time) const;
  
  /**
    * Accessor: Get the time as a string in hh:mm:ss, 24-hour format
    * param [out] Clock formatted as a hh:mm:ss string
    **/
  std::string GetTime() const;

  /**
    * Accessor: Get the time as a string in hh:mm:ss, 12-hour format
    * param [out] Clock formatted as a hh:mm:ss string
    **/
  std::string GetUsTime() const;
  
  /**
    * Print the time in hh:mm:ss, 24-hour format
    * param [in] boolean flag, true: print newline, false: don't
    **/
  void PrintTime(bool newline) const;
  
  /**
    * Print the time in hh:mm:ss, 12-hour format
    * param [in] boolean flag, true: print newline, false: don't
    **/
  void PrintUsTime(bool newline) const;

 private:
  int hh_, mm_, ss_;
  int ConvertToSeconds(int hh, int mm, int ss) const;
  int* ConvertFromSeconds(int seconds) const;
  
};

#endif /* TIME_H_ */
