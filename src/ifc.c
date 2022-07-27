#include "ifc.h"

const static char *ifc_months_full[13] = {
  "January", "February", "March",
  "April", "May", "June", "Sol",
  "July", "August", "September",
  "October", "November", "December"
};

const static char ifc_months_short[13][4] = {
  "JAN", "FEB", "MAR", "APR", "MAY",
  "JUN", "SOL", "JUL", "AUG", "SEP",
  "OCT", "NOV", "DEC"
};

const static char *ifc_weekdays_full[7] = {
  "Sunday", "Monday", "Tuesday", "Wednesday",
  "Thursday", "Friday", "Saturday"
};

const static char ifc_weekdays_short[7][4] = {
  "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};

const char *ifc_month_name(IFCDate date)
{
  return ifc_months_full[ifc_month(date) - 1];
}

const char *ifc_month_name_short(IFCDate date)
{
  return ifc_months_short[ifc_month(date) - 1];
}

const char *ifc_weekday_name(IFCDate date)
{
  return ifc_weekdays_full[ifc_weekday(date) - 1];
}

const char *ifc_weekday_name_short(IFCDate date)
{
  return ifc_weekdays_short[ifc_weekday(date) - 1];
}


int ifc_day(IFCDate date)
{
  int day = date.day;
  if (day < 0 || day > 366)
    return -1;
  if (ifc_is_leap(date))
  {
    if (day == 169)
      return 29;
    if (day == 366)
      return 29;
    if (day == 365)
      return 28;
    if (day > 169) day--;
  }
  else if (day == 366)
    return -1;
  else if (day == 365)
    return 29;
  int rem;
  if ((rem = day % 28) != 0)
    return rem;
  return 28;
}

int ifc_week(IFCDate date)
{
  int day = date.day;
  if (ifc_is_leap(date))
  {
    // Year Day or Leap Day are not part of IFC week
    if (day == 169 || day == 366)
      return -1;
    if (day > 169) day--;
  }
  return day / 7;
}

int ifc_weekday(IFCDate date)
{
  int day = date.day;
  if (ifc_is_leap(date))
  {
    if (day == 169 || day == 366)
      return 0;
    if (day > 169) day--;
  }
  else if (day == 365)
    return 0;

  return day % 7;
}

int ifc_month(IFCDate date)
{
  int day = date.day;
  if (day < 0 || day > 366)
    return -1;
  if (ifc_is_leap(date))
  {
    if (day == 169)
      return 6;
    if (day > 169) day--;
  }

  if (day == 365 || day == 366)
    return 13;

  int month = day / 28, mday = day % 28;

  return (day == 0 && month != 13) ? month : month + 1;
}

int ifc_is_leap(IFCDate date)
{
  int year = date.year;
  if ((year % 4) == 0)
  {
    if ((year % 100) == 0)
    {
      return (year % 400) == 0;
    }
    return 1;
  }
  return 0;
}

IFCDate ifc_from_date(struct tm date)
{
  return (IFCDate){ date.tm_year + 1900, date.tm_yday + 1 };
}

struct tm ifc_to_date(IFCDate ifc)
{
  return (struct tm){
    .tm_sec = 0,
    .tm_min = 0,
    .tm_hour = 0,
    .tm_mday = -1,      // TODO
    .tm_mon = -1,       // TODO
    .tm_year = ifc.year - 1900,
    .tm_wday = -1,      // TODO
    .tm_yday = ifc.day - 1,
    .tm_isdst = -1,     // TODO
  };
}
