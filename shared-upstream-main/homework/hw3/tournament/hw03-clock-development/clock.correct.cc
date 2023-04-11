/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "clock.h"

Clock::Clock(void) {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  hh_ = now->tm_hour;
  mm_ = now->tm_min;
  ss_ = now->tm_sec;
}

Clock::Clock(int hours, int minutes, int seconds) {
  ss_ = ((seconds%60)+60)%60;
  minutes += (int)std::floor((double)seconds/60.0);
  mm_ = ((minutes%60)+60)%60;
  hours += (int)std::floor((double)minutes/60.0);
  hh_ = ((hours%24)+24)%24;
}

/**
* Constructor
* param [in] seconds: The number of seconds that have elapsed since 00:00:00, modulo 24 hours
*
* Converts time given to this Clock format and stored.
**/
Clock::Clock(int seconds) {
  // 86400 seconds in a day
  seconds = ((seconds % 86400) + 86400) % 86400; // forces modulo to be positive
  // 3600 seconds in an hour
  hh_ = seconds/3600;
  seconds %= 3600;
  // 60 seconds in a minute
  mm_ = seconds/60;
  seconds %= 60;
  ss_ = seconds;
}

/**
* Adding seconds to the time.
* param [in] rhs: right hand side of this+rhs
* param [out] New Clock object representing the time which is "seconds" number of seconds after the time currently stored, loops back around after 23:59:59
**/
Clock Clock::operator+(int seconds) const {
  int old_time = ConvertToSeconds(hh_, mm_, ss_);
  //std::cout << "Debugging ConvertToTime: " << old_time << std::endl;
  int* new_time = ConvertFromSeconds(old_time + seconds);
  //std::cout << "Debugging ConvertFromTime: " << std::endl;
  //std::cout << old_time << " + " << time << " = ";
  Clock ret = Clock(new_time[0], new_time[1], new_time[2]);
  delete[] new_time;
  return ret;
}

/**
* Subtracting seconds from the time.
* param [in] rhs: right hand side of this+rhs
* param [out] New Clock object representing the time which is "seconds" number of seconds before the time currently stored, loops back around before 00:00:00
**/
Clock Clock::operator-(int seconds) const{
  int old_time = ConvertToSeconds(hh_, mm_, ss_);
  int * new_time = ConvertFromSeconds(old_time - seconds);
  Clock ret = Clock(new_time[0], new_time[1], new_time[2]);
  delete[] new_time;
  return ret;
}

/**
* Number of seconds between this time and the time provided
* param [in] rhs: left hand side of this-rhs
* param [out] number of secodns between the two times
**/
int Clock::SecondsBetween(const Clock& time) const {
  int this_seconds = ConvertToSeconds(hh_, mm_, ss_);
  //std::cout << "Debugging ConvertToSeconds: (LHS): " << this_seconds << std::endl;
  int that_seconds = ConvertToSeconds(time.hh_, time.mm_, time.ss_);
  //std::cout << "Debugging ConvertToSeconds: (RHS)" << that_seconds << std::endl;
  return std::abs(this_seconds - that_seconds);
}

/**
* Accessor: Get the time as a string in hh:mm:ss, 24-hour format
* param [out] Clock formatted as a hh:mm:ss string
**/
std::string Clock::GetTime() const {
  char numstr[3]; //large enough for hours, minutes, seconds
  std::string time = "";
  if (hh_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", hh_);
  time = time + numstr + ":";
  if (mm_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", mm_);
  time = time + numstr + ":";
  if (ss_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", ss_);
  time = time + numstr;
  return time;
}

/**
* Accessor: Get the time as a string in hh:mm:ss, 12-hour format
* param [out] Clock formatted as a hh:mm:ss string
**/
std::string Clock::GetUsTime() const {
  char numstr[3]; //large enough for hours, minutes, seconds
  int hhh_ = (hh_%12 == 0 ? 12 : hh_%12); // 12-hour time

  std::string time = "";
  if (hhh_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", hhh_);
  time = time + numstr + ":";
  if (mm_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", mm_);
  time = time + numstr + ":";
  if (ss_ < 10)
    time = time + "0";
  sprintf(numstr, "%d", ss_);
  time = time + numstr;
  time = time + (hh_ >= 12 ? " PM" : " AM");
  return time;
}

/**
* Print the time in hh:mm:ss, 24-hour format
* param [in] boolean flag, true: print newline, false: don't
**/
void Clock::PrintTime(bool newline) const {
  std::cout << std::setw(2) << std::setfill('0') << hh_ << ":" << std::setw(2) << std::setfill('0') << mm_ << ":" << std::setw(2) << std::setfill('0') << ss_;
  if (newline)
    std::cout << std::endl;
}

/**
* Print the time in hh:mm:ss, 12-hour format
* param [in] boolean flag, true: print newline, false: don't
**/
void Clock::PrintUsTime(bool newline) const {
  std::cout << std::setw(2) << std::setfill('0') << (hh_%12 == 0 ? 12 : hh_%12) << ":" << std::setw(2) << std::setfill('0') << mm_ << ":" << std::setw(2) << std::setfill('0') << ss_ << std::setw(3) << (hh_ >= 12 ? " PM" : " AM");
  if (newline)
    std::cout << std::endl;
}


/*******************************************************************************
 * Private methods
 ******************************************************************************/
   
int Clock::ConvertToSeconds(int hh, int mm, int ss) const{
  return 3600*hh + 60*mm + ss;
}

int* Clock::ConvertFromSeconds(int seconds) const{
  int* time_back = new int[3];
  seconds = ((seconds % 86400) + 86400) % 86400; // forces modulo to be positive
  time_back[0] = seconds/3600;
  seconds %= 3600;
  time_back[1] = seconds/60;
  seconds %= 60;
  time_back[2] = seconds;
  return time_back;
}
